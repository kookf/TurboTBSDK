//
//  TurboAdInfo.h
//  TurboSDK
//
//  Created by turbo on 2025/8/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TurboAdInfo : NSObject

/// 广告位ID
@property (nonatomic,strong, readonly, nonnull) NSString *placementId;

- (instancetype)initWithPlacementId:(NSString *)placementId;
@end

NS_ASSUME_NONNULL_END
