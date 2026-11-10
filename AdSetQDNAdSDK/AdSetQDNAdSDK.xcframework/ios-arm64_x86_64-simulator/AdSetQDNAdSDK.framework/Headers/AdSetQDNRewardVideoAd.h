//
//  AdSetQDNRewardVideoAd.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2023/12/19.
//  Copyright © 2023 AdSetQDN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdSetQDNRewardedVideoModel.h"
#import "AdSetQDNAdProtocol.h"
#import "AdSetQDNServerBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNRewardVideoAd;
@protocol AdSetQDNRewardVideoAdDelegate <NSObject>

@optional
/// 广告数据加载成功回调
- (void)adsetqdn_rewardVideoAdDidLoad:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频广告各种错误信息回调
- (void)adsetqdn_rewardVideoAd:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd didFailWithError:(NSError *_Nullable)error;

/// 视频数据下载成功回调，已经下载过的视频会直接回调
- (void)adsetqdn_rewardVideoAdVideoDidLoad:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频播放页即将曝光回调
- (void)adsetqdn_rewardVideoAdWillVisible:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频广告曝光回调
- (void)adsetqdn_rewardVideoAdDidExposed:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频播放页关闭回调
- (void)adsetqdn_rewardVideoAdDidClose:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频广告信息点击回调
- (void)adsetqdn_rewardVideoAdDidClicked:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 视频广告播放达到激励条件回调
- (void)adsetqdn_rewardVideoAdDidRewardEffective:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

/// 服务端验证奖励失败回调
- (void)adsetqdn_rewardVideoAdServerRewardDidFail:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd error:(NSError *_Nullable)error;

/// 视频广告视频播放完成
- (void)adsetqdn_rewardVideoAdDidPlayFinish:(AdSetQDNRewardVideoAd *_Nonnull)rewardVideoAd;

@end


@interface AdSetQDNRewardVideoAd : NSObject <AdSetQDNAdProtocol, AdSetQDNServerBiddingProtocol>

@property (nonatomic, weak) id<AdSetQDNRewardVideoAdDelegate> delegate;

@property (nonatomic, strong) AdSetQDNRewardedVideoModel *rewardedVideoModel;

/// 广告是否有效
@property (nonatomic, assign, readonly) BOOL isAdValid;

/// 实时价格（分）
@property (nonatomic, assign, readonly) NSInteger price;

/// 初始化激励广告
/// @param adspotId 广告Id
/// @param delegate 代理对象
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                          delegate:(id<AdSetQDNRewardVideoAdDelegate> _Nullable)delegate;

/// 构造方法 (可携带自定义参数)
/// @param adspotId 广告id
/// @param ext 自定义参数
/// @param delegate 代理
- (instancetype)initAdWithAdspotId:(NSString * _Nonnull)adspotId
                         customExt:(NSDictionary * _Nullable)ext
                          delegate:(id<AdSetQDNRewardVideoAdDelegate> _Nullable)delegate;

/// 加载广告
- (void)loadAd;

/// 展示广告
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
