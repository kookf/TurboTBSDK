//
//  TurboSplashAd.h
//  TurboSDK
//
//  Created by turbo on 2025/8/21.
//

#import <Foundation/Foundation.h>
#import "TurboAdInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TurboSplashAdDelegate <NSObject>

@optional

/// 广告加载成功回调
/// - Parameter splashAd: TurboAdInfo 实例对象
- (void)onSplashAdDidLoad:(TurboAdInfo *)splashAd;

/// 广告加载失败回调
/// - Parameters:
///   - splashAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
-(void)onSplashAdLoadFail:(TurboAdInfo *)splashAd error:(NSError *_Nullable)error;

/// 广告即将曝光回调
/// - Parameter splashAd: TurboAdInfo 实例对象
-(void)onSplashAdWillPresentScreen:(TurboAdInfo *)splashAd;

/// 广告曝光成功回调
/// - Parameter splashAd: TurboAdInfo 实例对象
-(void)onSplashAdSuccessPresentScreen:(TurboAdInfo *)splashAd;

/// 广告曝光失败回调
/// - Parameters:
///   - splashAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
-(void)onSplashAdFailToPresent:(TurboAdInfo *)splashAd withError:(NSError *_Nullable)error;

/// 广告点击回调
/// - Parameter splashAd: TurboAdInfo 实例对象
- (void)onSplashAdClicked:(TurboAdInfo *)splashAd;

/// 广告跳过回调
/// - Parameter splashAd: TurboAdInfo 实例对象
- (void)onSplashAdSkiped:(TurboAdInfo *)splashAd;

/// 广告即将关闭回调
/// - Parameter splashAd: TurboAdInfo 实例对象
- (void)onSplashAdWillClosed:(TurboAdInfo *)splashAd;

/// 广告关闭回调
/// - Parameter splashAd: TurboAdInfo 实例对象
- (void)onSplashAdClosed:(TurboAdInfo *)splashAd;


@end


NS_ASSUME_NONNULL_END
