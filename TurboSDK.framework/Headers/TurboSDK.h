//
//  TurboSDK.h


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindMillSDK/WindMillSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TurboSDK : NSObject

+ (instancetype)sharedInstance;

+ (NSString *)SDKVersion;

// 初始化sdk
+ (void)initSDKWithAppId:(NSString *)appid;


//设置广告位预置策略所在的Bundle路径,发起加载广告之前调用
+ (void)setPresetPlacementConfigPathBundle:(NSBundle *) bundle;
// 设置流量分组自定义规则【应用级维度】
+ (void)initCustomGroup:(NSDictionary<NSString *, NSString *> *)group;
// 设置流量分组自定义规则【广告位级维度】
+ (void)initCustomGroup:(NSDictionary<NSString *, NSString *> *)group forPlacementId:(NSString *)placementId;

@property (nonatomic,strong) UIViewController *splashViewController;


// 开屏
- (void)loadAndShowSplashWithPlacementId:(NSString *)placementId withBottomView:(UIView *)bottomView withDelegate:(nullable id<WindMillSplashAdDelegate>)delegate;


// 插屏
- (void)loadIntersititialWithPlacementId:(NSString *)placementId withDelegate:(nullable id<WindMillIntersititialAdDelegate>)delegate;

- (BOOL)checkIntersititialReady;

- (void)showIntersititialWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;



// 激励
- (void)loadRewardVideoWithPlacementId:(NSString *)placementId
                            withUserId:(nullable NSString *)userId
                           withOptions:(nullable NSDictionary *)option
                          withDelegate:(nullable id<WindMillRewardVideoAdDelegate>)delegate;

- (BOOL)checkRewardReady;


- (void)showRewardWithRootViewController:(UIViewController *)vc withOptions:(NSDictionary *)option;


// 信息流
- (void)loadNativeWithPlacementId:(NSString *)placementId withAdSize:(CGSize )adSize withDelegate:(nullable id<WindMillNativeAdsManagerDelegate>)delegate;

- (UIView *)showNativeViewWithUIViewController:(UIViewController *)vc withDelegate:(nullable id<WindMillNativeAdViewDelegate>)delegate;

- (NSArray *)getAllNativeAds;


// 横幅
- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withDelegate:(nullable id<WindMillBannerViewDelegate>)delegate withRootViewController:(UIViewController *)vc;

// 横幅
//withExpectSize: 传入期望的横幅广告视图大小
- (UIView *)loadBannerWithPlacementId:(NSString *)placementId withExpectSize:(CGSize )expectSize withDelegate:(nullable id<WindMillBannerViewDelegate>)delegate withRootViewController:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END
