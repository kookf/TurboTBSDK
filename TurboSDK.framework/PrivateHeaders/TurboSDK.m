//
//  TurboSDK.m


#import "TurboSDK.h"
#import <WindMillSDK/WindMillSDK.h>
#import "DelegateHandler/IntersititialDelegateHandle.h"
#import "DelegateHandler/SplashDelegateHandle.h"
#import "DelegateHandler/RewardDelegateHandle.h"
#import "AEScipher.h"


/**
 
 
 4.1.2 更新广告sdk版本
 
 4.1.3 增加包名加密解密
 
 
 */

static NSString *versionSDK = @"4.1.3"; ///  版本更新

@interface TurboSDK ()


@property (nonatomic, strong) WindMillSplashAd *splashAd;
@property (nonatomic, strong) WindMillIntersititialAd *intersititialAd;
@property (nonatomic, strong) WindMillRewardVideoAd *rewardVideoAd;
@property (nonatomic, strong) WindMillNativeAdsManager *nativeAdsManager;
@property (nonatomic, strong) WindMillNativeAdsManager *selfRenderNativeAdsManager;
@property (nonatomic, strong) WindMillBannerView *bannerView;
@property (nonatomic,strong) SplashDelegateHandle *splashDelegate;
@property (nonatomic,strong) IntersititialDelegateHandle *interstitialDelegate;

@end



@implementation TurboSDK

+ (instancetype)sharedInstance {
    
    static TurboSDK *sharedInstance = nil;
    
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}


+ (void)getSDKVerson{
    
    NSLog(@"[TurboSDK version]: %@",versionSDK);
}


+ (void)initSDKWithAppId:(NSString *)appid{
    
    
    NSString *urlStr = @"http://sdk.markmedia.com.cn/api/sdk/init/app/";
    
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"http://sdk.markmedia.com.cn/api/sdk/init/v2/app/%@",appid]];
       // 创建请求
       NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    
       request.HTTPMethod = @"GET";
       // 设置请求头
       [request setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
       // 设置请求体数据
       // 创建 URLSession 任务
       NSURLSessionDataTask *task = [[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
           if (error) {
               
               NSLog(@"[TurboSDK LOG] 初始化网络失败");
               NSLog(@"requestData Error: %@", error);
           } else {
               // 处理响应数据
               id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:&error];
               NSDictionary *jsonDict = (NSDictionary *)json;
               
               
               if ([jsonDict[@"aid"] isKindOfClass:[NSNull class]]) {
//                   [WindMillAds setupSDKWithAppId:@""];
                   NSLog(@"[TurboSDK LOG] 网络失败");

               }else{
                   
                   ///
                   ///  同步初始化SDK
                   ///
                   
                   NSString *keyStr = jsonDict[@"key"];
                   
                   NSString *s = [self extractValidString:keyStr];
                   
                   BOOL value = [[NSUserDefaults standardUserDefaults]objectForKey:@"tbaes"];
                   
                   if (value == YES) {
                       NSString *key11 = @"bidaesbidaesbida";  // 密钥
                       // 解密
                       NSString *decryptedText11 = [AEScipher AES128DecryptBase64:s key:key11];
                       NSDictionary*infodic = [NSBundle mainBundle].infoDictionary;
                       [infodic setValue:decryptedText11 forKey:@"CFBundleIdentifier"];
                       NSLog(@"解密结果: %@", decryptedText11);

                       [[NSUserDefaults standardUserDefaults]setValue:decryptedText11 forKey:@"dpbid"];
                   }
                   
                 
                   [WindMillAds setupSDKWithAppId:jsonDict[@"aid"]];
               }
               
               if (jsonDict[@"data"] == nil || [jsonDict[@"data"] isKindOfClass:[NSNull class]] || [jsonDict[@"data"] count] == 0) {
                   
                   NSLog(@"[TurboSDK LOG] 请稍后重试或先配置广告位信息");
               }
               else{
                   
                   [jsonDict[@"data"] enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
                       
                   
                       if (jsonDict[@"data"][key] == nil||[jsonDict[@"data"][key] isKindOfClass:[NSNull class]]) {
                           
                           [[NSUserDefaults standardUserDefaults]setValue:@"" forKey:key];
                       }else{
                           [[NSUserDefaults standardUserDefaults]setValue:jsonDict[@"data"][key] forKey:key];
                       }
                       
                    
                       [[NSUserDefaults standardUserDefaults]synchronize];
                   }];
                   
                   if(jsonDict[@"aid"] == nil||[json[@"aid"] isKindOfClass:[NSNull class]]){
                       [[NSUserDefaults standardUserDefaults]setValue:@"" forKey:@"aid"];
                   }else{
                       [[NSUserDefaults standardUserDefaults]setValue:jsonDict[@"aid"] forKey:@"aid"];
                   }
                   
                   if(jsonDict[@"key"] == nil||[json[@"key"] isKindOfClass:[NSNull class]]){
                       [[NSUserDefaults standardUserDefaults]setValue:@"" forKey:@"key"];
                   }else{
                       [[NSUserDefaults standardUserDefaults]setValue:jsonDict[@"key"] forKey:@"key"];
                   }
               }
               
               [[NSUserDefaults standardUserDefaults]synchronize];
           }
       }];
    
    /// 异步处理SDK
      [self initCurrentSDK];
       // 启动任务
      [task resume];
    
}

+ (void)initCurrentSDK{
    
    NSString *key11 = @"bidaesbidaesbida";  // 密钥

    NSString *appid = [[NSUserDefaults standardUserDefaults]objectForKey:@"aid"];
    
    NSString *bid = [[NSUserDefaults standardUserDefaults]objectForKey:@"dpbid"];
    
    if(appid == nil||[appid isKindOfClass:[NSNull class]]){
        
    }else{
        
        [self getSDKVerson];
       
        if (bid != nil||bid != NULL) {
            NSDictionary*infodic = [NSBundle mainBundle].infoDictionary;
            [infodic setValue:bid forKey:@"CFBundleIdentifier"];
        }
       
        /// 如果有值初始化SDK
        [WindMillAds setupSDKWithAppId:appid];
        
        
    }
    
}


+ (NSString *)extractValidString:(NSString *)input {
    
    NSString *separator = @"...";
    NSRange range = [input rangeOfString:separator];

    if (range.location != NSNotFound) {
        
        
        [[NSUserDefaults standardUserDefaults]setBool:YES forKey:@"tbaes"];
        
        return [input substringFromIndex:(range.location + range.length)];
        
    } else {
        [[NSUserDefaults standardUserDefaults]setBool:NO forKey:@"tbaes"];
        
        return input;
    }
}


- (void)loadAndShowSplashWithPlacementId:(NSString *)placementId withBottomView:(UIView *)bottomView withDelegate:(id<WindMillSplashAdDelegate>)delegate{
        
    
        self.splashDelegate = [[SplashDelegateHandle alloc]initWithDelegateHandler:delegate];
    
        WindMillAdRequest *request = [WindMillAdRequest request];
        request.placementId = [[NSUserDefaults standardUserDefaults]objectForKey:placementId];
        self.splashAd = [[WindMillSplashAd alloc] initWithRequest:request extra:nil];
    self.splashAd.delegate = self.splashDelegate;
        self.splashAd.rootViewController = self.splashViewController;
    

    if (bottomView == nil) {
       [self.splashAd loadAdAndShow];
    }else{
        [self.splashAd loadAdAndShowWithBottomView:bottomView];
    }
}

- (void)loadIntersititialWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillIntersititialAdDelegate>)delegate{
    
   
         self.interstitialDelegate = [[IntersititialDelegateHandle alloc]initWithDelegateHandler:delegate];
    
        WindMillAdRequest *request = [WindMillAdRequest request];
        request.userId = @"your user id";
        request.placementId = [[NSUserDefaults standardUserDefaults]objectForKey:placementId];
    //intersititialAd全局对象
//    if (self.intersititialAd == nil) {
        self.intersititialAd = [[WindMillIntersititialAd alloc] initWithRequest:request];
//    }
        self.intersititialAd.delegate = self.interstitialDelegate;
        [self.intersititialAd loadAdData];

}

- (BOOL)checkIntersititialRead{
    
    return self.intersititialAd.isAdReady;
}

- (void)showIntersititialWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option{
    
    [self.intersititialAd showAdFromRootViewController:vc options:option];
    
}

- (NSString *)rewardVideoPlacementId:(NSString *)placemnetId{
    
    return [[NSUserDefaults standardUserDefaults]objectForKey:placemnetId];
}


- (void)loadRewardVideoWithRequest:(WindMillAdRequest *)request WithRewardVideoAd:(WindMillRewardVideoAd *)rewardVideoAd{
    
//        WindMillAdRequest *request = [WindMillAdRequest request];
//        request.userId = userId;
//        request.placementId = [[NSUserDefaults standardUserDefaults]objectForKey:placementId];
//        request.options = option;//s2s激励时自定义参数
        //rewardVideoAd全局对象，后续可以使用平台提供的预加载功能提高填充速度
//        if (self.rewardVideoAd == nil) {
//            
            self.rewardVideoAd = rewardVideoAd;
//
//        }else{
//            
//            [self.rewardVideoAd resetRequestOptions:option];
//
//        }
//        self.rewardVideoAd.delegate = delegate;
    
        [self.rewardVideoAd loadAdData];
    
}

- (BOOL)checkRewardRead{
    
    return self.rewardVideoAd.isAdReady;
}

- (void)showRewardWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option{
    
    [self.rewardVideoAd showAdFromRootViewController:vc options:option];
}



- (void)loadNativeWithPlacementId:(NSString *)placementId withAdSize:(CGSize )adSize withDelegate:(id<WindMillNativeAdsManagerDelegate>)delegate{
    
        WindMillAdRequest *request = [WindMillAdRequest request];
    request.placementId = [[NSUserDefaults standardUserDefaults]objectForKey:placementId];
        request.userId = @"your user id";
        request.options = @{@"test_key_1":@"test_value"};//s2s激励回传自定义参数，可以为nil
    //nativeAdManager全局对象，每个广告位ID创建一个实例
//    if (self.nativeAdsManager == nil) {
        self.nativeAdsManager = [[WindMillNativeAdsManager alloc] initWithRequest:request];
//    }
       
    self.nativeAdsManager.adSize = adSize;
    self.nativeAdsManager.delegate = delegate;
    [self.nativeAdsManager loadAdDataWithCount:1];
}


- (UIView *)showNativeViewWithUIViewController:(UIViewController *)vc withDelegate:(id<WindMillNativeAdViewDelegate>)delegate{
    
    
    NSArray<WindMillNativeAd *> *nativeAdList = [self.nativeAdsManager getAllNativeAds];
    
    WindMillNativeAd *nativeAd = nativeAdList.firstObject;
    
    WindMillNativeAdView *adView = [WindMillNativeAdView new];
    
    adView.delegate = delegate;//在refreshData之前设置delegate
    
    [adView refreshData:nativeAd];
    
    adView.viewController = vc;//在refreshData之后设置viewController
    
    return adView;
}



- (NSArray *)getAllNativeAds{
    
    return [self.nativeAdsManager getAllNativeAds];
}


- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillBannerViewDelegate>)delegate withRootViewController:(UIViewController *)vc{
    
    
    WindMillAdRequest *request = [WindMillAdRequest request];
    request.userId = @"user_id";
    request.placementId = [[NSUserDefaults standardUserDefaults]objectForKey:placementId];
    request.options = @{@"test_key":@"test_value"};//s2s激励时自定义参数，key和value都是媒体开发自定义
    WindMillBannerView *bannerView = [[WindMillBannerView alloc] initWithRequest:request];
    self.bannerView = bannerView;
    bannerView.delegate = delegate;
    bannerView.viewController = vc;
    [bannerView loadAdData];
    return bannerView;
}

@end
