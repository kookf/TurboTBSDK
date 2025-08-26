//
//  TurboBannerAdDelegate.h
//  TurboSDK
//
//  Created by turbo on 2025/8/25.
//

#import <Foundation/Foundation.h>
#import "TurboAdInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TurboBannerAdDelegate <NSObject>

@optional

/// 广告自动刷新成功回调
/// - Parameter bannerAd: TurboAdInfo 实例对象
- (void)bannerAdViewDidAutoRefresh:(TurboAdInfo *)bannerAd;

/// 广告自动刷新失败回调
/// - Parameters:
///   - bannerAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)bannerView:(TurboAdInfo *)bannerAd failedToAutoRefreshWithError:(NSError *_Nullable)error;

/// 广告加载成功回调
/// - Parameter bannerAdView: TurboAdInfo 实例对象
- (void)bannerAdViewLoadSuccess:(TurboAdInfo *)bannerAd bannerAdSize:(CGSize) adSize;

/// 广告加载失败回调
/// - Parameters:
///   - bannerAd: TurboAdInfo 实例对象
///   - error: 具体错误信息
- (void)bannerAdViewFailedToLoad:(TurboAdInfo *)bannerAd
                           error:(NSError *_Nullable)error;

/// 广告曝光回调
/// - Parameter bannerAd: TurboAdInfo 实例对象
- (void)bannerAdViewWillExpose:(TurboAdInfo *)bannerAd;

/// 广告点击回调
/// - Parameter bannerAd: TurboAdInfo 实例对象
- (void)bannerAdViewDidClicked:(TurboAdInfo *)bannerAd;

/// 广告视图被移除
/// - Parameter bannerAd: TurboAdInfo 实例对象
- (void)bannerAdViewDidRemoved:(TurboAdInfo *)bannerAd;


@end

NS_ASSUME_NONNULL_END
