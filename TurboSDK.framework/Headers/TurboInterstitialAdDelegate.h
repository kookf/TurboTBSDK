//
//  TurboInterstitialAdDelegate.h
//  TurboSDK
//
//  Created by turbo on 2025/8/22.
//

#import <Foundation/Foundation.h>
#import "TurboAdInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TurboInterstitialAdDelegate<NSObject>

@optional

/// 广告加载成功回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidLoad:(TurboAdInfo *)intersititialAd;

/// 广告加载失败回调
/// - Parameters:
///   - intersititialAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidLoad:(TurboAdInfo *)intersititialAd didFailWithError:(NSError *_Nullable)error;

/// 广告即将曝光回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdWillVisible:(TurboAdInfo *)intersititialAd;

/// 广告曝光回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidVisible:(TurboAdInfo *)intersititialAd;

/// 广告展示失败
/// - Parameters:
///   - intersititialAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidShowFailed:(TurboAdInfo *)intersititialAd error:(NSError *_Nullable)error;

/// 广告点击回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidClick:(TurboAdInfo *)intersititialAd;

/// 广告跳过回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidClickSkip:(TurboAdInfo *)intersititialAd;

/// 广告关闭回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidClose:(TurboAdInfo *)intersititialAd;

/// 广告视频播放完成或播放出错时回调
/// - Parameters:
///   - intersititialAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidPlayFinish:(TurboAdInfo *)intersititialAd didFailWithError:(NSError * _Nullable)error;

/// 广告播放中加载成功回调
/// - Parameter intersititialAd: TurboAdInfo 实例对象
- (void)intersititialAdDidAutoLoad:(TurboAdInfo *)intersititialAd;

/// 广告播放中加载失败回调
/// - Parameters:
///   - intersititialAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)intersititialAd:(TurboAdInfo *)intersititialAd didAutoLoadFailWithError:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
