//
//  TurboRequest.h
//  TurboSDK
//
//  Created by mac on 2024/11/21.
//

#import <WindMillSDK/WindMillSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TurboRequest : WindMillAdRequest



+ (id)requestWithPlacementId:(NSString *)placementId;


/// 【可选】，媒体用户ID。
@property (nonatomic,copy) NSString *userId;

/// 【可选】，服务端激励回传时，透传参数。
@property (nonatomic,strong) NSDictionary<NSString *, NSString *> *options;




@end

NS_ASSUME_NONNULL_END
