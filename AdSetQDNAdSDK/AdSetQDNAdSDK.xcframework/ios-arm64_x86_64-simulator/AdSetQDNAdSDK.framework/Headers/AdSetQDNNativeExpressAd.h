//
//  AdSetQDNNativeExpressAd.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/1/22.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdSetQDNNativeExpressAdView.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNNativeExpressAd;
@protocol AdSetQDNNativeExpressAdDelegate <NSObject>

@optional
/// 拉取原生模板广告成功
- (void)adsetqdn_nativeExpressAdSuccessToLoad:(AdSetQDNNativeExpressAd *)nativeExpressAd views:(NSArray<AdSetQDNNativeExpressAdView *> *)views;

/// 拉取原生模板广告失败
- (void)adsetqdn_nativeExpressAdFailToLoad:(AdSetQDNNativeExpressAd *)nativeExpressAd error:(NSError *)error;

/// 原生模板广告渲染成功, 此时的 nativeExpressAdView.size.height 根据 size.width 完成了动态更新。
- (void)adsetqdn_nativeExpressAdViewRenderSuccess:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 原生模板广告渲染失败
- (void)adsetqdn_nativeExpressAdViewRenderFail:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 原生模板广告曝光回调
- (void)adsetqdn_nativeExpressAdViewExposure:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 原生模板广告点击回调
- (void)adsetqdn_nativeExpressAdViewClicked:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 原生模板广告被关闭
- (void)adsetqdn_nativeExpressAdViewClosed:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 广告详情页面即将展示回调
- (void)adsetqdn_nativeExpressAdDetailViewWillPresentScreen:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

/// 广告详情页关闭回调
- (void)adsetqdn_nativeExpressAdDetailViewDidDismissScreen:(AdSetQDNNativeExpressAdView *)nativeExpressAdView;

@end

/// 历史拼写兼容，请使用 AdSetQDNNativeExpressAdDelegate。
__attribute__((deprecated("Use AdSetQDNNativeExpressAdDelegate instead")))
@protocol AdSetQDNNativeExpressAdDelegete <AdSetQDNNativeExpressAdDelegate>
@end

@interface AdSetQDNNativeExpressAd : NSObject <AdSetQDNServerBiddingProtocol>

/// 广告展示的尺寸
/// 可将宽度设置为屏宽，自适应时，可将高度直接设置为0
@property (nonatomic, assign) CGSize renderSize;

/// 广告展示的内部间距。范围[0, 30] pt，默认值12.f
@property (nonatomic, assign) CGFloat padding;

/// 代理
@property (nonatomic, weak) id<AdSetQDNNativeExpressAdDelegate> delegate;

/// 构造方法
/// @param adspotId 广告位 ID
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId;

/// 构造方法
/// @param adspotId 广告位 ID
/// @param ext 自定义拓展参数
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                         customExt:(NSDictionary *_Nullable)ext;

/**
 加载广告，仅加载一条数据
 */
- (void)loadAd;

/**
 加载广告
 @param count 加载条数
 */
- (void)loadAdWithCount:(NSInteger)count __attribute__((deprecated("已弃用，只支持返回1个广告")));

@end

NS_ASSUME_NONNULL_END
