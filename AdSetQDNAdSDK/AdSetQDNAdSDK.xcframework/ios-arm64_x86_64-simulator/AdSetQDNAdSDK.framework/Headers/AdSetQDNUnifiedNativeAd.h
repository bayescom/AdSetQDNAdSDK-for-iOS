//
//  AdSetQDNUnifiedNativeAd.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/1/8.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdSetQDNUnifiedNativeAdDataObject.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdSetQDNUnifiedNativeAdDelegate <NSObject>

/**
 广告数据回调

 @param unifiedNativeAdDataObjects 广告数据数组
 @param error 错误信息
 */
- (void)adsetqdn_unifiedNativeAdLoaded:(NSArray<AdSetQDNUnifiedNativeAdDataObject *> * _Nullable)unifiedNativeAdDataObjects error:(NSError * _Nullable)error;

@end

@interface AdSetQDNUnifiedNativeAd : NSObject <AdSetQDNServerBiddingProtocol>

@property (nonatomic, weak) id<AdSetQDNUnifiedNativeAdDelegate> delegate;

/// 构造方法
/// @param adspotId 广告Id
/// @param delegate 代理对象
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                          delegate:(id<AdSetQDNUnifiedNativeAdDelegate> _Nullable)delegate;

/// 构造方法 (可携带自定义参数)
/// @param adspotId 广告id
/// @param ext 自定义参数
/// @param delegate 代理
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                         customExt:(NSDictionary * _Nullable)ext
                          delegate:(id<AdSetQDNUnifiedNativeAdDelegate> _Nullable)delegate;

/**
 加载广告，仅加载一条数据
 */
- (void)loadAd;

/**
 加载广告
 @param adCount 加载条数
 */
- (void)loadAdWithAdCount:(NSInteger)adCount __attribute__((deprecated("已弃用，只支持返回1个广告")));

@end

NS_ASSUME_NONNULL_END
