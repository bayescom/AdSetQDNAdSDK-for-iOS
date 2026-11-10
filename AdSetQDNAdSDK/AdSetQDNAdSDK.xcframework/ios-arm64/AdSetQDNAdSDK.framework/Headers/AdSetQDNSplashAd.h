//
//  AdSetQDNSplashAd.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/3/27.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdSetQDNAdProtocol.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNSplashAd;
@protocol AdSetQDNSplashAdDelegate <NSObject>

@optional
/// 开屏广告素材加载成功
- (void)adsetqdn_splashAdDidLoad:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告加载失败
- (void)adsetqdn_splashAdFailToLoad:(AdSetQDNSplashAd * _Nullable)splashAd error:(NSError * _Nullable)error;

/// 开屏广告视图渲染成功
- (void)adsetqdn_splashAdRenderSuccess:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告视图渲染失败
- (void)adsetqdn_splashAdRenderFail:(AdSetQDNSplashAd * _Nullable)splashAd error:(NSError * _Nullable)error;

/// 开屏广告曝光
- (void)adsetqdn_splashAdExposured:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告点击
- (void)adsetqdn_splashAdClicked:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告跳过按钮点击
- (void)adsetqdn_splashAdSkipClicked:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告关闭
- (void)adsetqdn_splashAdClosed:(AdSetQDNSplashAd * _Nullable)splashAd;

/// 开屏广告剩余时间
- (void)adsetqdn_splashAdLifeTime:(NSUInteger)time;

@end

@interface AdSetQDNSplashAd : NSObject <AdSetQDNAdProtocol, AdSetQDNServerBiddingProtocol>

/// 代理对象
@property (nonatomic, weak) id<AdSetQDNSplashAdDelegate> delegate;

/**
 *  开屏广告的背景图片
 *  可设置背景图片作为开屏加载时的默认背景
 */
@property (nonatomic, strong) UIImage *placeholderImage;

/// 开屏广告底部Logo视图
@property (nonatomic, strong) UIView *bottomLogoView;

/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 广告是否有效，建议在展示广告之前判断，否则会影响计费或展示失败
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// 实时价格（分）
@property (nonatomic, assign, readonly) NSInteger price;

/// 构造方法
/// @param adspotId 广告Id
/// @param delegate 代理
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                          delegate:(id<AdSetQDNSplashAdDelegate> _Nullable)delegate;

/// 构造方法
/// @param adspotId 广告Id
/// @param ext 自定义参数
/// @param delegate 代理
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                         customExt:(NSDictionary * _Nullable)ext
                          delegate:(id<AdSetQDNSplashAdDelegate> _Nullable)delegate;

/// 拉取广告数据
- (void)loadAd;

/// 展示广告
- (void)showAdInWindow:(UIWindow *)window;

@end

NS_ASSUME_NONNULL_END
