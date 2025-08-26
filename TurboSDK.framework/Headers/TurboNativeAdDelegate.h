//
//  TurboNativeAdDelegate.h
//  TurboSDK
//
//  Created by turbo on 2025/8/22.
//

#import <Foundation/Foundation.h>
#import "TurboAdInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TurboNativeAdDelegate<NSObject>

@optional
//加载相关回调
/// 广告加载成功回调
/// - Parameter adsManager: TurboAdInfo 实例对象
- (void)nativeAdDidLoad:(TurboAdInfo *)nativeAd;

/// 广告加载出错
/// - Parameters:
///   - adsManager: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)nativeAdDidLoad:(TurboAdInfo *)nativeAd didFailWithError:(NSError *_Nullable)error;

/// 广告播放中加载成功回调
/// - Parameter adsManager: TurboAdInfo 实例对象
- (void)nativeAdDidAutoLoad:(TurboAdInfo *)nativeAd;

/// 广告播放中加载出错
/// - Parameters:
///   - adsManager: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)nativeAd:(TurboAdInfo *)nativeAd didAutoLoadFailWithError:(NSError *_Nullable)error;


//展示相关回调
/**
 * 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderSuccess:(TurboAdInfo *)nativeAd nativeAdView:(UIView *)nativeAdView;

/**
 * 原生模板广告渲染失败
 * （只针对模版渲染）
 */
- (void)nativeExpressAdViewRenderFail:(TurboAdInfo *)nativeAd error:(NSError *_Nullable)error;

/**
 广告曝光回调

 @param nativeAd TurboAdInfo 实例
 */
- (void)nativeAdViewWillExpose:(TurboAdInfo *)nativeAd;

/**
 广告点击回调

 @param nativeAd TurboAdInfo 实例
 */
- (void)nativeAdViewDidClick:(TurboAdInfo *)nativeAd;

/**
 点击dislike回调
 开发者需要在这个回调中移除视图，否则会出现用户点击叉无效的情况
 
 */
- (void)nativeAdViewDislike:(TurboAdInfo *)nativeAd;

@end


NS_ASSUME_NONNULL_END
