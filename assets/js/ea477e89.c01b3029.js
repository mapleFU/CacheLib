"use strict";(self.webpackChunkmy_website=self.webpackChunkmy_website||[]).push([[3464],{3905:function(e,t,a){a.d(t,{Zo:function(){return h},kt:function(){return p}});var n=a(7294);function o(e,t,a){return t in e?Object.defineProperty(e,t,{value:a,enumerable:!0,configurable:!0,writable:!0}):e[t]=a,e}function i(e,t){var a=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),a.push.apply(a,n)}return a}function r(e){for(var t=1;t<arguments.length;t++){var a=null!=arguments[t]?arguments[t]:{};t%2?i(Object(a),!0).forEach((function(t){o(e,t,a[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(a)):i(Object(a)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(a,t))}))}return e}function l(e,t){if(null==e)return{};var a,n,o=function(e,t){if(null==e)return{};var a,n,o={},i=Object.keys(e);for(n=0;n<i.length;n++)a=i[n],t.indexOf(a)>=0||(o[a]=e[a]);return o}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(n=0;n<i.length;n++)a=i[n],t.indexOf(a)>=0||Object.prototype.propertyIsEnumerable.call(e,a)&&(o[a]=e[a])}return o}var s=n.createContext({}),c=function(e){var t=n.useContext(s),a=t;return e&&(a="function"==typeof e?e(t):r(r({},t),e)),a},h=function(e){var t=c(e.components);return n.createElement(s.Provider,{value:t},e.children)},u={inlineCode:"code",wrapper:function(e){var t=e.children;return n.createElement(n.Fragment,{},t)}},m=n.forwardRef((function(e,t){var a=e.components,o=e.mdxType,i=e.originalType,s=e.parentName,h=l(e,["components","mdxType","originalType","parentName"]),m=c(a),p=o,g=m["".concat(s,".").concat(p)]||m[p]||u[p]||i;return a?n.createElement(g,r(r({ref:t},h),{},{components:a})):n.createElement(g,r({ref:t},h))}));function p(e,t){var a=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var i=a.length,r=new Array(i);r[0]=m;var l={};for(var s in t)hasOwnProperty.call(t,s)&&(l[s]=t[s]);l.originalType=e,l.mdxType="string"==typeof e?e:o,r[1]=l;for(var c=2;c<i;c++)r[c]=a[c];return n.createElement.apply(null,r)}return n.createElement.apply(null,a)}m.displayName="MDXCreateElement"},5576:function(e,t,a){a.r(t),a.d(t,{frontMatter:function(){return l},contentTitle:function(){return s},metadata:function(){return c},toc:function(){return h},default:function(){return m}});var n=a(7462),o=a(3366),i=(a(7294),a(3905)),r=["components"],l={id:"pool_rebalance_strategy",title:"Pool rebalance strategy"},s="When do you need pool rebalancing?",c={unversionedId:"Cache_Library_User_Guides/pool_rebalance_strategy",id:"Cache_Library_User_Guides/pool_rebalance_strategy",isDocsHomePage:!1,title:"Pool rebalance strategy",description:"If your cachelib use case always allocates objects of a single size, then rebalancing is almost always not required for you. Rebalancing of cache becomes important only when you store variable sized objects in cache and your workload's footprint of access across these objects can potentially change over time. Often when you cache objects of variable size, the distribution of find() and allocate() across object sizes would vary over time. This leads to poor fragmentation in the cache memory footprint. For example, imagine you had a cache of 30 GB and store objects of size 100 bytes, 500 bytes, and 1,000 bytes, each occupying 10 GB when warmed up. When your application workload changes over time, the optimal sizes for these objects could vary as well requiring more memory for one vs. other. With pool rebalancing, this kind of workload change would usually result in metrics like eviction age and hit ratios being sub-optimal over time.",source:"@site/docs/Cache_Library_User_Guides/pool_rebalance_strategy.md",sourceDirName:"Cache_Library_User_Guides",slug:"/Cache_Library_User_Guides/pool_rebalance_strategy",permalink:"/docs/Cache_Library_User_Guides/pool_rebalance_strategy",editUrl:"https://github.com/facebook/docusaurus/edit/master/website/docs/Cache_Library_User_Guides/pool_rebalance_strategy.md",tags:[],version:"current",frontMatter:{id:"pool_rebalance_strategy",title:"Pool rebalance strategy"},sidebar:"someSidebar",previous:{title:"Oom protection",permalink:"/docs/Cache_Library_User_Guides/oom_protection"},next:{title:"Automatic pool resizing",permalink:"/docs/Cache_Library_User_Guides/automatic_pool_resizing"}},h=[{value:"Lru TailAge",id:"lru-tailage",children:[]},{value:"Hit based",id:"hit-based",children:[]},{value:"Marginal hits",id:"marginal-hits",children:[]},{value:"Writing your own strategy",id:"writing-your-own-strategy",children:[]}],u={toc:h};function m(e){var t=e.components,a=(0,o.Z)(e,r);return(0,i.kt)("wrapper",(0,n.Z)({},u,a,{components:t,mdxType:"MDXLayout"}),(0,i.kt)("h1",{id:"when-do-you-need-pool-rebalancing"},"When do you need pool rebalancing?"),(0,i.kt)("p",null,"If your cachelib use case always allocates objects of a single size, then rebalancing is almost always not required for you. Rebalancing of cache becomes ",(0,i.kt)("em",{parentName:"p"},"important only when you store variable sized objects")," in cache and your workload's footprint of access across these objects can potentially change over time. Often when you cache objects of variable size, the distribution of ",(0,i.kt)("inlineCode",{parentName:"p"},"find()")," and ",(0,i.kt)("inlineCode",{parentName:"p"},"allocate()")," across object sizes would vary over time. This leads to poor fragmentation in the cache memory footprint. For example, imagine you had a cache of 30 GB and store objects of size 100 bytes, 500 bytes, and 1,000 bytes, each occupying 10 GB when warmed up. When your application workload changes over time, the optimal sizes for these objects could vary as well requiring more memory for one vs. other. With pool rebalancing, this kind of workload change would usually result in metrics like eviction age and hit ratios being sub-optimal over time."),(0,i.kt)("p",null,"Cachelib offers several rebalancing strategies to offset this behavior by asking the cache to restructure the underlying memory allocated among objects of different sizes."),(0,i.kt)("h1",{id:"how-does-it-work"},"How does it work?"),(0,i.kt)("p",null,"Internally, cachelib divides up memory into slabs and allocates slabs across objects of various sizes. When pool rebalancing is enabled, cachelib evicts objects of one size in favor of other and moves the backing slabs to the other objects to enable caching more of them. Cachelib can do this automatically and periodically. However, you will have to pick a strategy that matters to you and configure how often the rebalancing happens."),(0,i.kt)("p",null,"Rebalancing is an asynchronous operation and does not impact the latencies of other cachelib operations like ",(0,i.kt)("inlineCode",{parentName:"p"},"find()"),", ",(0,i.kt)("inlineCode",{parentName:"p"},"insertOrReplace()"),", or ",(0,i.kt)("inlineCode",{parentName:"p"},"allocate()"),". ***Rebalancing moves memory at the rate of 4 MB for every interval that you configure if you would like to estimate a good rate."),(0,i.kt)("h1",{id:"enabling-pool-rebalancing"},"Enabling pool rebalancing"),(0,i.kt)("p",null,"To enable pool rebalancing, specify these two parameters:"),(0,i.kt)("ol",null,(0,i.kt)("li",{parentName:"ol"},(0,i.kt)("strong",{parentName:"li"},"Strategy")," for re-evaluating metrics about your cache and figuring out a rebalancing action"),(0,i.kt)("li",{parentName:"ol"},(0,i.kt)("strong",{parentName:"li"},"Interval")," of executing the rebalancing")),(0,i.kt)("p",null,"For example:"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"auto rebalanceStrategy =\n  std::make_shared<cachelib::LruTailAgeStrategy>(rebalanceConfig);\n\nconfig.enablePoolRebalancing(\n  rebalanceStrategy,\n  std::chrono::seconds(kRebalanceIntervalSecs)\n);\n")),(0,i.kt)("h1",{id:"picking-a-strategy"},"Picking a strategy"),(0,i.kt)("p",null,"Cachelib offers a few pre-package strategies for rebalancing that you can pick from. They differ by what they try to optimize for based on traditional wisdom of caches like TAO and Memcache. These are good defaults to start with, but you can also come up with your own implementation if you have other goals."),(0,i.kt)("h2",{id:"lru-tailage"},"Lru TailAge"),(0,i.kt)("p",null,"LruTailAge is a fair policy that ensures that objects of different sizes get the same eviction age in cache.  For example, in steady state for your cache, you could have 100 byte objects getting 1 hr lifetime vs 1000 byte objects getting 30 min lifetime. This strategy tries to make the eviction age for various sizes similar. You can configure the following parameters(LruTailAgeStrategy::Config) (whose default values are pretty good to begin with):"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},(0,i.kt)("inlineCode",{parentName:"p"},"tailAgeDiffRatio"),"\nThis defines how tight the tail age of various object sizes you want them to be. Setting it to 0.1 means that you don't want the min and max age to differ by more than 10%.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},(0,i.kt)("inlineCode",{parentName:"p"},"minTailAgeDifference"),"\nThis specifies a threshold of how big the actual diff ratio should be to warrant a rebalancing. For example, your min and max might be more than 10% off, but the real difference is insignificant.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},(0,i.kt)("inlineCode",{parentName:"p"},"minSlabs"),"\nThis specifies the minimum amount of memory in slabs that specific object size can not go below while rebalancing. Keep in mind that this is specified in slabs and not in bytes.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},(0,i.kt)("inlineCode",{parentName:"p"},"numSlabsFreeMem"),"\nWhen you specify rebalancing under this mode, cachlib aggressively moves memory from object sizes that have a lot of free memory. This specifies the threshold for triggering that behavior.")),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("p",{parentName:"li"},(0,i.kt)("inlineCode",{parentName:"p"},"slabProjectionLength"),"\nThis lets you estimate the min and max by picking a projected eviction age instead of the real eviction age. This can sometimes let you get better results."))),(0,i.kt)("p",null,"For example:"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"cachelib::LruTailAgeStrategy::Config cfg(ratio, kLruTailAgeStrategyMinSlabs);\ncfg.slabProjectionLength = 0; // dont project or estimate tail age\ncfg.numSlabsFreeMem = 10;     // ok to have ~40 MB free memory in unused allocations\nauto rebalanceStrategy = std::make_shared<cachelib::LruTailAgeStrategy>(cfg);\n\n// every 5 seconds, re-evaluate the eviction ages and rebalance the cache.\nconfig.enablePoolRebalancing(std::move(rebalanceStrategy), std::chrono::seconds(5));\n")),(0,i.kt)("h2",{id:"hit-based"},"Hit based"),(0,i.kt)("p",null,"HitBased approach tries to optimize the overall hit ratio rather than ensuring a fairness in the cache eviction age. This should result in a relatively higher hit ratio. However, it might potentially make your cache contain more of objects that give hits vs. objects that are expensive to recompute. For example, the cost of miss on objects is not uniform. To control the downsides of such implications, cachelib offers these parameters(HitsPerSlabStrategy::Config). Most of these are similar to the LruTailAge parameters, however, their semantics could slightly differ in the following ways:"),(0,i.kt)("ul",null,(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"minDiff"),"\nLike tailAgeDiffRatio, this controls the minimum improvement that should trigger a rebalancing."),(0,i.kt)("li",{parentName:"ul"},(0,i.kt)("inlineCode",{parentName:"li"},"minLruTailAge"),"\nWhen using hit based rebalancing, if you want to ensure some level of fairness by guaranteeing some eviction age, you can configure it through this parameter.")),(0,i.kt)("h2",{id:"marginal-hits"},"Marginal hits"),(0,i.kt)("p",null,"This strategy ensures that the marginal hits (estimated by the hits in the tail part of LRU) across different object sizes are similar. Unlike hit based strategy which counts for historical count of hits across the entire cache, this tracks which objects could marginally benefit from getting more memory. To enable this,  you need to use the MM2Q eviction policy and enable tail hits tracking (",(0,i.kt)("inlineCode",{parentName:"p"},"Allocator::Config::enableTailHitsTracking()"),")."),(0,i.kt)("h2",{id:"writing-your-own-strategy"},"Writing your own strategy"),(0,i.kt)("p",null,"In addition, if you have some application specific context on how you can improve your cache, you can implement your own strategy and pass it to cachelib for rebalancing. Your rebalancing strategy will have to extend the type ",(0,i.kt)("inlineCode",{parentName:"p"},"RebalanceStrategy")," and implement the following two methods that define where to take memory from and where to give more memory to:"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-cpp"},"virtual RebalanceContext pickVictimAndReceiverImpl(\n  const CacheBase& /*cache*/,\n  PoolId /*pid*/\n) {\n  return {};\n}\n\nvirtual ClassId pickVictimImpl(\n  const CacheBase& /*cache*/,\n  PoolId /*pid*/\n) {\n  return Slab::kInvalidClassId;\n}\n")))}m.isMDXComponent=!0}}]);