/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include <sstream>
#include <stdexcept>

#include "cachelib/allocator/nvmcache/NavyConfig.h"
#include "cachelib/navy/common/Types.h"
namespace facebook {
namespace cachelib {
namespace tests {
using NavyConfig = navy::NavyConfig;
namespace {
// AP settings
const std::string admissionPolicy = "dynamic_random";
const uint64_t admissionWriteRate = 100;
const uint64_t maxWriteRate = 160;
const size_t admissionSuffixLen = 1;
const uint64_t admissionProbBaseSize = 1024;

// device settings
const uint64_t blockSize = 1024;
const std::string fileName = "test";
const std::vector<std::string> raidPaths = {"test1", "test2"};
const std::vector<std::string> raidPathsInvalid = {"test1"};
const uint64_t deviceMetadataSize = 1024 * 1024 * 1024;
const uint64_t fileSize = 10 * 1024 * 1024;
const bool truncateFile = false;
const uint32_t deviceMaxWriteSize = 4 * 1024 * 1024;

// BlockCache settings
const uint32_t blockCacheRegionSize = 16 * 1024 * 1024;
const std::vector<uint32_t> blockCacheSizeClasses = {1024, 2048, 4096};
const uint8_t blockCacheReinsertionHitsThreshold = 111;
const uint32_t blockCacheCleanRegions = 4;
const bool blockCacheDataChecksum = true;
const std::vector<unsigned int> blockCacheSegmentedFifoSegmentRatio = {111, 222,
                                                                       333};
// BigCache settings
const unsigned int bigHashSizePct = 50;
const uint32_t bigHashBucketSize = 1024;
const uint64_t bigHashBucketBfSize = 4;
const uint64_t bigHashSmallItemMaxSize = 512;

const uint32_t maxConcurrentInserts = 50000;
const uint64_t maxParcelMemoryMB = 512;

// Job scheduler settings
const unsigned int readerThreads = 40;
const unsigned int writerThreads = 40;
const uint64_t navyReqOrderingShards = 30;

void setAdmissionPolicyTestSettings(NavyConfig& config) {
  config.enableDynamicRandomAdmPolicy()
      .setAdmWriteRate(admissionWriteRate)
      .setMaxWriteRate(maxWriteRate)
      .setAdmSuffixLength(admissionSuffixLen)
      .setAdmProbBaseSize(admissionProbBaseSize)
      .setProbFactorRange(0.001, 2.0);
}

void setDeviceTestSettings(NavyConfig& config) {
  config.setBlockSize(blockSize);
  config.setRaidFiles(raidPaths, fileSize, truncateFile);
  config.setDeviceMetadataSize(deviceMetadataSize);
  config.setDeviceMaxWriteSize(deviceMaxWriteSize);
}

void setBlockCacheTestSettings(NavyConfig& config) {
  config.blockCache()
      .enableSegmentedFifo(blockCacheSegmentedFifoSegmentRatio)
      .enableHitsBasedReinsertion(blockCacheReinsertionHitsThreshold)
      .setCleanRegions(blockCacheCleanRegions, true)
      .setRegionSize(blockCacheRegionSize)
      .useSizeClasses(blockCacheSizeClasses)
      .setDataChecksum(blockCacheDataChecksum);
}

void setBigHashTestSettings(NavyConfig& config) {
  config.bigHash()
      .setSizePctAndMaxItemSize(bigHashSizePct, bigHashSmallItemMaxSize)
      .setBucketSize(bigHashBucketSize)
      .setBucketBfSize(bigHashBucketBfSize);
}

void setJobSchedulerTestSettings(NavyConfig& config) {
  config.setReaderAndWriterThreads(readerThreads, writerThreads);
  config.setNavyReqOrderingShards(navyReqOrderingShards);
}

void setTestNavyConfig(NavyConfig& config) {
  setAdmissionPolicyTestSettings(config);
  setDeviceTestSettings(config);
  setBlockCacheTestSettings(config);
  setBigHashTestSettings(config);
  setJobSchedulerTestSettings(config);
  config.setMaxConcurrentInserts(maxConcurrentInserts);
  config.setMaxParcelMemoryMB(maxParcelMemoryMB);
}
} // namespace
TEST(NavyConfigTest, DefaultVal) {
  NavyConfig config{};

  const auto dynamicRandomConfig = config.dynamicRandomAdmPolicy();
  EXPECT_EQ(config.getAdmissionPolicy(), "");
  EXPECT_EQ(config.randomAdmPolicy().getAdmProbability(), 0);
  EXPECT_EQ(dynamicRandomConfig.getAdmSuffixLength(), 0);
  EXPECT_EQ(dynamicRandomConfig.getProbFactorLowerBound(), 0);
  EXPECT_EQ(dynamicRandomConfig.getProbFactorUpperBound(), 0);
  EXPECT_EQ(dynamicRandomConfig.getAdmWriteRate(), 0);

  const auto& blockCacheConfig = config.blockCache();
  EXPECT_EQ(blockCacheConfig.isLruEnabled(), true);
  EXPECT_EQ(blockCacheConfig.getRegionSize(), 16 * 1024 * 1024);
  EXPECT_EQ(blockCacheConfig.getCleanRegions(), 1);
  EXPECT_TRUE(blockCacheConfig.getSizeClasses().empty());
  EXPECT_TRUE(blockCacheConfig.getSFifoSegmentRatio().empty());
  EXPECT_EQ(blockCacheConfig.getDataChecksum(), true);
  EXPECT_EQ(blockCacheConfig.getNumInMemBuffers(), 0);

  const auto& bigHashConfig = config.bigHash();
  EXPECT_EQ(bigHashConfig.getBucketSize(), 4096);
  EXPECT_EQ(bigHashConfig.getBucketBfSize(), 8);
  EXPECT_EQ(bigHashConfig.getSmallItemMaxSize(), 0);

  EXPECT_EQ(config.getMaxConcurrentInserts(), 1'000'000);
  EXPECT_EQ(config.getMaxParcelMemoryMB(), 256);

  EXPECT_EQ(config.getReaderThreads(), 32);
  EXPECT_EQ(config.getWriterThreads(), 32);
  EXPECT_EQ(config.getNavyReqOrderingShards(), 20);

  EXPECT_EQ(config.getBlockSize(), 4096);
  EXPECT_EQ(config.getTruncateFile(), false);
  EXPECT_EQ(config.getDeviceMetadataSize(), 0);
  EXPECT_EQ(config.getFileSize(), 0);
  EXPECT_EQ(config.getDeviceMaxWriteSize(), 0);

  EXPECT_EQ(config.usesSimpleFile(), false);
  EXPECT_EQ(config.usesRaidFiles(), false);
}

TEST(NavyConfigTest, Serialization) {
  NavyConfig config{};
  setTestNavyConfig(config);
  std::map<std::string, std::string> configMap = config.serialize();

  auto expectedConfigMap = std::map<std::string, std::string>();
  expectedConfigMap["navyConfig::admissionPolicy"] = "dynamic_random";
  expectedConfigMap["navyConfig::admissionProbability"] = "0";
  expectedConfigMap["navyConfig::admissionWriteRate"] = "100";
  expectedConfigMap["navyConfig::maxWriteRate"] = "160";
  expectedConfigMap["navyConfig::admissionSuffixLen"] = "1";
  expectedConfigMap["navyConfig::admissionProbBaseSize"] = "1024";
  expectedConfigMap["navyConfig::admissionProbFactorLowerBound"] = "0.001";
  expectedConfigMap["navyConfig::admissionProbFactorUpperBound"] = "2";

  expectedConfigMap["navyConfig::blockSize"] = "1024";
  expectedConfigMap["navyConfig::fileName"] = "";
  expectedConfigMap["navyConfig::raidPaths"] = "test1,test2";
  expectedConfigMap["navyConfig::deviceMetadataSize"] = "1073741824";
  expectedConfigMap["navyConfig::fileSize"] = "10485760";
  expectedConfigMap["navyConfig::truncateFile"] = "false";
  expectedConfigMap["navyConfig::deviceMaxWriteSize"] = "4194304";

  expectedConfigMap["navyConfig::blockCacheLru"] = "false";
  expectedConfigMap["navyConfig::blockCacheRegionSize"] = "16777216";
  expectedConfigMap["navyConfig::blockCacheSizeClasses"] = "1024,2048,4096";
  expectedConfigMap["navyConfig::blockCacheCleanRegions"] = "4";
  expectedConfigMap["navyConfig::blockCacheReinsertionHitsThreshold"] = "111";
  expectedConfigMap["navyConfig::blockCacheReinsertionPctThreshold"] = "0";
  expectedConfigMap["navyConfig::blockCacheNumInMemBuffers"] = "8";
  expectedConfigMap["navyConfig::blockCacheDataChecksum"] = "true";
  expectedConfigMap["navyConfig::blockCacheSegmentedFifoSegmentRatio"] =
      "111,222,333";

  expectedConfigMap["navyConfig::bigHashSizePct"] = "50";
  expectedConfigMap["navyConfig::bigHashBucketSize"] = "1024";
  expectedConfigMap["navyConfig::bigHashBucketBfSize"] = "4";
  expectedConfigMap["navyConfig::bigHashSmallItemMaxSize"] = "512";

  expectedConfigMap["navyConfig::maxConcurrentInserts"] = "50000";
  expectedConfigMap["navyConfig::maxParcelMemoryMB"] = "512";

  expectedConfigMap["navyConfig::readerThreads"] = "40";
  expectedConfigMap["navyConfig::writerThreads"] = "40";
  expectedConfigMap["navyConfig::navyReqOrderingShards"] = "30";

  EXPECT_EQ(configMap, expectedConfigMap);
}

TEST(NavyConfigTest, AdmissionPolicy) {
  // set random admission policy
  NavyConfig config{};
  EXPECT_THROW(config.enableRandomAdmPolicy().setAdmProbability(2),
               std::invalid_argument);
  config = NavyConfig{};
  EXPECT_NO_THROW(config.enableRandomAdmPolicy().setAdmProbability(0.5));
  EXPECT_EQ(config.getAdmissionPolicy(), NavyConfig::kAdmPolicyRandom);
  EXPECT_EQ(config.randomAdmPolicy().getAdmProbability(), 0.5);
  // cannot set dynamic_random parameters
  EXPECT_THROW(config.enableDynamicRandomAdmPolicy(), std::invalid_argument);

  // set dynamic_random policy
  config = NavyConfig{};
  EXPECT_NO_THROW(config.enableDynamicRandomAdmPolicy()
                      .setAdmWriteRate(admissionWriteRate)
                      .setMaxWriteRate(maxWriteRate)
                      .setAdmSuffixLength(admissionSuffixLen)
                      .setAdmProbBaseSize(admissionProbBaseSize)
                      .setProbFactorRange(0.1, 10));
  auto dynamicRandomConfig = config.dynamicRandomAdmPolicy();
  EXPECT_EQ(config.getAdmissionPolicy(), NavyConfig::kAdmPolicyDynamicRandom);
  EXPECT_EQ(dynamicRandomConfig.getAdmWriteRate(), admissionWriteRate);
  EXPECT_EQ(dynamicRandomConfig.getMaxWriteRate(), maxWriteRate);
  EXPECT_EQ(dynamicRandomConfig.getAdmSuffixLength(), admissionSuffixLen);
  EXPECT_EQ(dynamicRandomConfig.getAdmProbBaseSize(), admissionProbBaseSize);
  EXPECT_EQ(dynamicRandomConfig.getProbFactorLowerBound(), 0.1);
  EXPECT_EQ(dynamicRandomConfig.getProbFactorUpperBound(), 10);
  // cannot set random parameters
  EXPECT_THROW(config.enableRandomAdmPolicy(), std::invalid_argument);
}

TEST(NavyConfigTest, Device) {
  NavyConfig config1{};
  config1.setBlockSize(blockSize);
  config1.setDeviceMetadataSize(deviceMetadataSize);
  EXPECT_EQ(config1.getBlockSize(), blockSize);
  EXPECT_EQ(config1.getDeviceMetadataSize(), deviceMetadataSize);

  // set simple file
  config1.setSimpleFile(fileName, fileSize, truncateFile);
  EXPECT_EQ(config1.getFileName(), fileName);
  EXPECT_EQ(config1.getFileSize(), fileSize);
  EXPECT_EQ(config1.getTruncateFile(), truncateFile);
  EXPECT_THROW(config1.setRaidFiles(raidPaths, fileSize, truncateFile),
               std::invalid_argument);

  // set RAID files
  NavyConfig config2{};
  EXPECT_THROW(config2.setRaidFiles(raidPathsInvalid, fileSize, truncateFile),
               std::invalid_argument);
  config2.setRaidFiles(raidPaths, fileSize, truncateFile);
  EXPECT_EQ(config2.getRaidPaths(), raidPaths);
  EXPECT_EQ(config2.getFileSize(), fileSize);
  EXPECT_EQ(config1.getTruncateFile(), truncateFile);
  EXPECT_THROW(config2.setSimpleFile(fileName, fileSize, truncateFile),
               std::invalid_argument);
}

TEST(NavyConfigTest, BlockCache) {
  NavyConfig config{};
  // test general settings
  config.blockCache()
      .setRegionSize(blockCacheRegionSize)
      .setCleanRegions(blockCacheCleanRegions, true)
      .setDataChecksum(blockCacheDataChecksum)
      .useSizeClasses(blockCacheSizeClasses);
  auto& blockCacheConfig = config.blockCache();
  EXPECT_EQ(blockCacheConfig.getRegionSize(), blockCacheRegionSize);
  EXPECT_EQ(blockCacheConfig.getCleanRegions(), blockCacheCleanRegions);
  EXPECT_EQ(blockCacheConfig.getNumInMemBuffers(), blockCacheCleanRegions * 2);
  EXPECT_EQ(blockCacheConfig.getDataChecksum(), blockCacheDataChecksum);
  EXPECT_EQ(blockCacheConfig.getSizeClasses(), blockCacheSizeClasses);

  // test FIFO eviction policy
  config.blockCache().enableFifo();
  EXPECT_EQ(blockCacheConfig.isLruEnabled(), false);
  EXPECT_TRUE(blockCacheConfig.getSFifoSegmentRatio().empty());
  // test segmented FIFO eviction policy
  config.blockCache().enableSegmentedFifo(blockCacheSegmentedFifoSegmentRatio);
  EXPECT_EQ(blockCacheConfig.isLruEnabled(), false);
  EXPECT_EQ(blockCacheConfig.getSFifoSegmentRatio(),
            blockCacheSegmentedFifoSegmentRatio);

  // test cannot enable both hits-based and probability-based reinsertion policy
  config = NavyConfig{};
  EXPECT_THROW(
      config.blockCache()
          .enableHitsBasedReinsertion(blockCacheReinsertionHitsThreshold)
          .enablePctBasedReinsertion(50),
      std::invalid_argument);
  EXPECT_EQ(blockCacheConfig.getReinsertionConfig().getHitsThreshold(),
            blockCacheReinsertionHitsThreshold);
  EXPECT_EQ(blockCacheConfig.getReinsertionConfig().getPctThreshold(), 0);

  config = NavyConfig{};
  EXPECT_THROW(
      config.blockCache()
          .enablePctBasedReinsertion(50)
          .enableHitsBasedReinsertion(blockCacheReinsertionHitsThreshold),
      std::invalid_argument);
  EXPECT_EQ(blockCacheConfig.getReinsertionConfig().getPctThreshold(), 50);
  EXPECT_EQ(blockCacheConfig.getReinsertionConfig().getHitsThreshold(), 0);

  // test invalid input for percentage based reinsertion policy
  config = NavyConfig{};
  EXPECT_THROW(config.blockCache().enablePctBasedReinsertion(200),
               std::invalid_argument);
}

TEST(NavyConfigTest, BigHash) {
  NavyConfig config{};
  EXPECT_THROW(
      config.bigHash().setSizePctAndMaxItemSize(200, bigHashSmallItemMaxSize),
      std::invalid_argument);
  config.bigHash()
      .setSizePctAndMaxItemSize(bigHashSizePct, bigHashSmallItemMaxSize)
      .setBucketSize(bigHashBucketSize)
      .setBucketBfSize(bigHashBucketBfSize);
  auto& bigHashConfig = config.bigHash();
  EXPECT_EQ(bigHashConfig.getSizePct(), bigHashSizePct);
  EXPECT_EQ(bigHashConfig.getBucketSize(), bigHashBucketSize);
  EXPECT_EQ(bigHashConfig.getBucketBfSize(), bigHashBucketBfSize);
  EXPECT_EQ(bigHashConfig.getSmallItemMaxSize(), bigHashSmallItemMaxSize);
}

TEST(NavyConfigTest, JobScheduler) {
  NavyConfig config{};
  config.setReaderAndWriterThreads(readerThreads, writerThreads);
  ASSERT_THROW(config.setNavyReqOrderingShards(0), std::invalid_argument);
  config.setNavyReqOrderingShards(navyReqOrderingShards);
  EXPECT_EQ(config.getReaderThreads(), readerThreads);
  EXPECT_EQ(config.getWriterThreads(), writerThreads);
  EXPECT_EQ(config.getNavyReqOrderingShards(), navyReqOrderingShards);
}

TEST(NavyConfigTest, OtherSettings) {
  NavyConfig config{};
  config.setMaxConcurrentInserts(maxConcurrentInserts);
  config.setMaxParcelMemoryMB(maxParcelMemoryMB);
  EXPECT_EQ(config.getMaxConcurrentInserts(), maxConcurrentInserts);
  EXPECT_EQ(config.getMaxParcelMemoryMB(), maxParcelMemoryMB);
}
} // namespace tests
} // namespace cachelib
} // namespace facebook
