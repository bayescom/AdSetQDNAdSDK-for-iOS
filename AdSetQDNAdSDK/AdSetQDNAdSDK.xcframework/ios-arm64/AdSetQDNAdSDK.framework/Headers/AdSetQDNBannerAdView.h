//
//  AdSetQDNBannerAdView.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/3/22.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdSetQDNAdProtocol.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNBannerAdView;
@protocol AdSetQDNBannerAdViewDelegate <NSObject>

@optional
/// 请求广告条数据成功后调用
- (void)adsetqdn_bannerViewDidReceived:(AdSetQDNBannerAdView *_Nonnull)banner;

/// 请求广告条数据失败后调用
- (void)adsetqdn_bannerViewFailToReceived:(AdSetQDNBannerAdView *_Nonnull)banner error:(NSError *_Nullable)error;

/// banner条渲染失败回调
- (void)adsetqdn_bannerViewRenderFail:(AdSetQDNBannerAdView *_Nonnull)banner error:(NSError *_Nullable)error;

/// banner条曝光回调
- (void)adsetqdn_bannerViewWillExposure:(AdSetQDNBannerAdView *_Nonnull)banner;

/// banner条点击回调
- (void)adsetqdn_bannerViewClicked:(AdSetQDNBannerAdView *_Nonnull)banner;

/// banner条被用户关闭时调用
- (void)adsetqdn_bannerViewWillClose:(AdSetQDNBannerAdView *_Nonnull)banner;

@end

@interface AdSetQDNBannerAdView : UIView <AdSetQDNAdProtocol, AdSetQDNServerBiddingProtocol>

/// 委托 [可选]
@property(nonatomic, weak) id<AdSetQDNBannerAdViewDelegate> delegate;

/// 用来显示广告的ViewController [必选]
@property (nonatomic, weak) UIViewController *controller;

/// 广告刷新间隔，范围 [10, 120] 秒，设 0 则不刷新。[可选]
@property(nonatomic, assign) NSInteger interval;

/// 广告是否有效
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// 实时价格（分）
@property(nonatomic, assign, readonly) NSInteger price;

/// 初始方法
/// @param frame banner 展示的位置和大小
/// @param adspotId 广告位id
/// @param delegate 代理
- (instancetype)initWithFrame:(CGRect)frame
                     adspotId:(NSString *_Nonnull)adspotId
                     delegate:(id<AdSetQDNBannerAdViewDelegate> _Nullable)delegate;

/// 初始方法
/// @param frame banner 展示的位置和大小
/// @param adspotId 广告位id
/// @param ext 自定义拓展参数
/// @param delegate 代理
- (instancetype)initWithFrame:(CGRect)frame
                     adspotId:(NSString *_Nonnull)adspotId
                    customExt:(NSDictionary *_Nullable)ext
                     delegate:(id<AdSetQDNBannerAdViewDelegate> _Nullable)delegate;

/// 拉取并展示广告
- (void)loadAdAndShow;

@end

NS_ASSUME_NONNULL_END
