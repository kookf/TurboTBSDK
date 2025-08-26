//
//  TurboSDK.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillSDK.h>
#import "TurboRequest.h"
#import "TurboSplashAdDelegate.h"
#import "TurboRewardVideoAdDelegate.h"
#import "TurboInterstitialAdDelegate.h"
#import "TurboNativeAdDelegate.h"
#import "TurboBannerAdDelegate.h"
#import "TurboRequest.h"

@interface TurboSDK : NSObject

+ (instancetype)sharedInstance;

+ (NSString *)SDKVersion;

//是否启用日志。日志默认关闭，设置为YES时日志打开
@property (class, nonatomic, assign) BOOL logEnabled;

// 初始化sdk
+ (void)initSDKWithAppId:(NSString *)appid;


@property (nonatomic,strong) UIViewController *splashViewController;


// 开屏
/**
 *  广告发起请求并展示在Window中
 *  详解：当bottomView不为空，广告以半屏形式展示在传入的Window的上半部，剩余部分展示传入的bottomView
 *       请注意bottomView需设置好宽高，所占的空间不能过大，并保证广告界面的高度大于360。
 *       当bottomView为空，广告以全屏形式展示在传入的Window中
 *  @param bottomView [可选] 自定义底部View，可以在此View中设置应用Logo，
 *
 */
- (void)loadAndShowSplashWithPlacementId:(NSString *)placementId withBottomView:(UIView *)bottomView withDelegate:(id<TurboSplashAdDelegate>)delegate;


// 插屏
- (void)loadIntersititialWithPlacementId:(NSString *)placementId withDelegate:(id<TurboInterstitialAdDelegate>)delegate;

- (BOOL)checkIntersititialRead;

- (void)showIntersititialWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 激励

- (void)loadRewardVideoWithRequest:(TurboRequest *)request withDelegate:(id<TurboRewardVideoAdDelegate>)delegate;

- (BOOL)checkRewardRead;

- (void)showRewardWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 信息流
- (void)loadNativeWithPlacementId:(NSString *)placementId withAdSize:(CGSize )adSize withDelegate:(id<TurboNativeAdDelegate>)delegate;

- (UIView *)showNativeViewWithUIViewController:(UIViewController *)vc;



// 横幅
- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withDelegate:(id<TurboBannerAdDelegate>)delegate withRootViewController:(UIViewController *)vc;


@end
