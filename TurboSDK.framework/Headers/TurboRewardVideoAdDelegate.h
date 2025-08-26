//
//  TurboRewardVideoAdDelegate.h
//  TurboSDK
//
//  Created by turbo on 2025/8/22.
//

#import <Foundation/Foundation.h>
#import "TurboAdInfo.h"
#import "TurboRewardInfo.h"

NS_ASSUME_NONNULL_BEGIN


@protocol TurboRewardVideoAdDelegate<NSObject>

@required

/// 广告获得激励时回调
/// - Parameters:
///   - rewardVideoAd: TurboAdInfo 实例对象
///   - reward: 激励信息
- (void)rewardVideoAd:(TurboAdInfo *)rewardVideoAd reward:(TurboRewardInfo *)reward;

@optional

/// 广告加载成功
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidLoad:(TurboAdInfo *)rewardVideoAd;

/// 广告加载失败
/// - Parameters:
///   - rewardVideoAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidLoad:(TurboAdInfo *)rewardVideoAd didFailWithError:(NSError *_Nullable)error;

/// 广告即将曝光回调
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdWillVisible:(TurboAdInfo *)rewardVideoAd;

/// 广告曝光回调
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidVisible:(TurboAdInfo *)rewardVideoAd;

/// 广告播放失败回调
/// - Parameters:
///   - rewardVideoAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidShowFailed:(TurboAdInfo *)rewardVideoAd error:(NSError *_Nullable)error;

/// 广告点击回调
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidClick:(TurboAdInfo *)rewardVideoAd;

/// 广告跳过回调
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidClickSkip:(TurboAdInfo *)rewardVideoAd;

/// 广告闭关回调
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidClose:(TurboAdInfo *)rewardVideoAd;

/// 广告视频播放完成或者视频播放出错
/// - Parameters:
///   - rewardVideoAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAdDidPlayFinish:(TurboAdInfo *)rewardVideoAd didFailWithError:(NSError * _Nullable)error;

/// 广告播放中加载成功
/// - Parameter rewardVideoAd: TurboAdInfo 实例对象
- (void)rewardVideoAdDidAutoLoad:(TurboAdInfo *)rewardVideoAd;

/// 广告播放中加载失败
/// - Parameters:
///   - rewardVideoAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)rewardVideoAd:(TurboAdInfo *)rewardVideoAd didAutoLoadFailWithError:(NSError *_Nullable)error;


@end

NS_ASSUME_NONNULL_END
