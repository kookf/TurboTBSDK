//
//  TurboSDK.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillSDK.h>
#import <TurboSDK/TurboRequest.h>

@interface TurboSDK : NSObject

+ (instancetype)sharedInstance;

+ (NSString *)SDKVersion;

// 初始化sdk
+ (void)initSDKWithAppId:(NSString *)appid;


@property (nonatomic,strong) UIViewController *splashViewController;


// 开屏
/// @params userId 用户的唯一标识符，可以是手机号,User ID等。如果没有，可以传nil或空字符。
- (void)loadAndShowSplashWithPlacementId:(NSString *)placementId withBottomView:(UIView *)bottomView withDelegate:(id<WindMillSplashAdDelegate>)delegate withUserId:(NSString * _Nullable)userId;


// 插屏
/// @params userId 用户的唯一标识符，可以是手机号,User ID等。如果没有，可以传nil或空字符。
- (void)loadIntersititialWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillIntersititialAdDelegate>)delegate withUserId:(NSString * _Nullable)userId;

- (BOOL)checkIntersititialReady;

- (void)showIntersititialWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 激励
/// @params userId 用户的唯一标识符，可以是手机号,User ID等。如果没有，可以传nil或空字符。
- (void)loadRewardVideoWithRequest:(WindMillAdRequest *)request WithRewardVideoAd:(WindMillRewardVideoAd *)rewardVideoAd withUserId:(NSString * _Nullable)userId;

- (BOOL)checkRewardReady;


- (void)showRewardWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 信息流
/// @params userId 用户的唯一标识符，可以是手机号,User ID等。如果没有，可以传nil或空字符。
- (void)loadNativeWithPlacementId:(NSString *)placementId withAdSize:(CGSize )adSize withDelegate:(id<WindMillNativeAdsManagerDelegate>)delegate withUserId:(NSString * _Nullable)userId;

- (UIView *)showNativeViewWithUIViewController:(UIViewController *)vc withDelegate:(id<WindMillNativeAdViewDelegate>)delegate;

- (NSArray *)getAllNativeAds;


// 横幅
/// @params userId 用户的唯一标识符，可以是手机号,User ID等。如果没有，可以传nil或空字符。
- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withDelegate:(id<WindMillBannerViewDelegate>)delegate withRootViewController:(UIViewController *)vc withUserId:(NSString * _Nullable)userId;


@end
