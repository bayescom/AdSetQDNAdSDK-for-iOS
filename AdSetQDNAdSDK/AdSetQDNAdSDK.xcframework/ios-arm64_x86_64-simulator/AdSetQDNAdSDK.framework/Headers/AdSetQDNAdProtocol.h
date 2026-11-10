//
//  AdSetQDNAdProtocol.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2025/9/16.
//  Copyright © 2025 AdSetQDN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 竞败原因
typedef NS_ENUM(NSInteger, AdSetQDNAdBidLossReason) {
    /// 其他原因
    AdSetQDNAdBidLossReasonOther = 0,
    /// 比价落败
    AdSetQDNAdBidLossReasonLowPrice = 1,
    /// 出价低于底价
    AdSetQDNAdBidLossReasonBelowFloorPrice = 2,
};

@protocol AdSetQDNAdProtocol <NSObject>

@optional

/// 获取广告剩余有效时间（秒）
- (NSTimeInterval)getAdValidSeconds;

/// 竞胜之后调用
/// - Parameters:
///   - winPrice: 竞胜价格，单位：分/CPM（千次展示）
///   - highestLossPrice: 最高竞败价格，单位：分/CPM（千次展示）
- (void)sendWinNotificationWithWinPrice:(double)winPrice
                       highestLossPrice:(double)highestLossPrice;

/// 竞败之后调用
/// - Parameters:
///   - winPrice: 竞胜价格，单位：分/CPM（千次展示）
///   - lossReason: 竞败原因
- (void)sendLossNotificationWithWinPrice:(double)winPrice
                              lossReason:(AdSetQDNAdBidLossReason)lossReason;

/// 竞败之后调用
/// - Parameter price: 竞胜价格，单位：分/CPM（千次展示）
- (void)sendLossNotificationWithPrice:(NSInteger)price
    __attribute__((deprecated("Use sendLossNotificationWithWinPrice:lossReason: instead.")));


@end

NS_ASSUME_NONNULL_END
