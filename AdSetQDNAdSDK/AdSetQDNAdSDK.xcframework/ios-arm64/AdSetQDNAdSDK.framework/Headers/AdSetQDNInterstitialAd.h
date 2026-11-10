//
//  AdSetQDNInterstitialAd.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2023/12/25.
//  Copyright © 2023 AdSetQDN. All rights reserved.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdSetQDNAdProtocol.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNInterstitialAd;
@protocol AdSetQDNInterstitialAdDelegate <NSObject>

@optional

/**
 *  插屏广告预加载成功回调
 *  当接收服务器返回的广告数据成功且预加载后调用该函数
 */
- (void)adsetqdn_interstitialSuccessToLoadAd:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告预加载失败回调
 *  当接收服务器返回的广告数据失败后调用该函数
 */
- (void)adsetqdn_interstitialFailToLoadAd:(AdSetQDNInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 *  插屏广告视频缓存完成
 */
- (void)adsetqdn_interstitialDidDownloadVideo:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告渲染成功
 */
- (void)adsetqdn_interstitialRenderSuccess:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告渲染失败
 */
- (void)adsetqdn_interstitialRenderFail:(AdSetQDNInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 *  插屏广告视图展示成功回调
 *  插屏广告展示成功回调该函数
 */
- (void)adsetqdn_interstitialDidPresentScreen:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告视图展示失败回调
 *  插屏广告展示失败回调该函数
 */
- (void)adsetqdn_interstitialFailToPresent:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告展示结束回调
 *  插屏广告展示结束回调该函数
 */
- (void)adsetqdn_interstitialDidDismissScreen:(AdSetQDNInterstitialAd *)interstitialAd;

/**
 *  插屏广告点击回调
 */
- (void)adsetqdn_interstitialClicked:(AdSetQDNInterstitialAd *)interstitialAd;

@end


@interface AdSetQDNInterstitialAd : NSObject <AdSetQDNAdProtocol, AdSetQDNServerBiddingProtocol>

/// 代理对象
@property (nonatomic, weak) id<AdSetQDNInterstitialAdDelegate> delegate;

/// 广告是否有效，建议在展示广告之前判断，否则会影响计费或展示失败
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// 实时价格（分）
@property (nonatomic, assign, readonly) NSInteger price;

/// 初始方法
/// @param adspotId 广告Id
/// @param delegate 代理对象
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                          delegate:(id<AdSetQDNInterstitialAdDelegate> _Nullable)delegate;


/// 初始方法
/// @param adspotId 广告Id
/// @param delegate 代理对象
/// @param ext 自定义拓展参数
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                         customExt:(NSDictionary *_Nullable)ext
                          delegate:(id<AdSetQDNInterstitialAdDelegate> _Nullable)delegate;

/**
 *  广告发起请求方法
 *  详解：[必选]发起拉取广告请求
 */
- (void)loadAd;

/**
 *  广告展示方法
 *  详解：[必选]发起展示广告请求, 必须传入用于显示插屏广告的UIViewController
 */
- (void)presentAdFromViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
