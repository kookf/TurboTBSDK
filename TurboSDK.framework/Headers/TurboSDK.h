//
//  TurboSDK.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillSDK.h>
#import <TurboSDK/TurboRequest.h>

@interface TurboSDK : NSObject

+ (instancetype)sharedInstance;

// 初始化sdk
+ (void)initSDKWithAppId:(NSString *)appid;


@property(nonatomic,strong)UIViewController *splashViewController;

// 开屏
- (void)loadAndShowSplashWithPlacementId:(NSString *)placementId withBottomView:(UIView *)bottomView withDelegate:(id<WindMillSplashAdDelegate>)delegate;

// 插屏
- (void)loadIntersititialWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillIntersititialAdDelegate>)delegate;

- (BOOL)checkIntersititialRead;

- (void)showIntersititialWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 激励

- (void)loadRewardVideoWithRequest:(WindMillAdRequest *)request WithRewardVideoAd:(WindMillRewardVideoAd *)rewardVideoAd;

- (BOOL)checkRewardRead;


- (void)showRewardWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 信息流
- (void)loadNativeWithPlacementId:(NSString *)placementId withAdSize:(CGSize )adSize withDelegate:(id<WindMillNativeAdsManagerDelegate>)delegate;

// 广告
- (UIView *)showNativeViewWithUIViewController:(UIViewController *)vc withDelegate:(id<WindMillNativeAdViewDelegate>)delegate;



- (NSArray *)getAllNativeAds;


// 横幅
- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillBannerViewDelegate>)delegate withRootViewController:(UIViewController *)vc;



@end
