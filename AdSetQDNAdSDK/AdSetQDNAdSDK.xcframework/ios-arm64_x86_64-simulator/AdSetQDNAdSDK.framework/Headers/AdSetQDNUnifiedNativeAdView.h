//
//  AdSetQDNUnifiedNativeAdView.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/1/8.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdSetQDNUnifiedNativeAdDataObject.h"
#import "AdSetQDNLogoView.h"
#import "AdSetQDNMediaView.h"
#import "AdSetQDNVideoConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNUnifiedNativeAdView;

@protocol AdSetQDNUnifiedNativeAdViewDelegate <NSObject>

@optional
/// 广告曝光回调
- (void)adsetqdn_unifiedNativeAdViewWillExpose:(AdSetQDNUnifiedNativeAdView *)unifiedNativeAdView;

/// 广告点击回调
- (void)adsetqdn_unifiedNativeAdViewDidClick:(AdSetQDNUnifiedNativeAdView *)unifiedNativeAdView;

/// 广告关闭回调
- (void)adsetqdn_unifiedNativeAdViewDidClose:(AdSetQDNUnifiedNativeAdView *)unifiedNativeAdView;

/// 广告详情页面即将展示回调
- (void)adsetqdn_unifiedNativeAdDetailViewWillPresentScreen:(AdSetQDNUnifiedNativeAdView *)unifiedNativeAdView;

/// 广告详情页关闭回调
- (void)adsetqdn_unifiedNativeAdDetailViewClosed:(AdSetQDNUnifiedNativeAdView *)unifiedNativeAdView;

@end


@interface AdSetQDNUnifiedNativeAdView : UIView

/// 广告View 事件回调对象
@property (nonatomic, weak) id<AdSetQDNUnifiedNativeAdViewDelegate> delegate;

/// 开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
@property (nonatomic, weak) UIViewController *viewController;

/// 绑定的数据对象
@property (nonatomic, strong, readonly) AdSetQDNUnifiedNativeAdDataObject *dataObject;

/**
 倍业广告 LogoView，自动生成
 
 @warning 开发者无需 addSubview 操作，建议布局尺寸：{ width: 40.0f, width: 15.0f }
 */
@property (nonatomic, strong, readonly) AdSetQDNLogoView *logoView;

/**
 视频广告的媒体View，自动生成
 
 @warning 开发者无需 addSubview 操作，建议使用视频素材宽高比尺寸进行布局
 */
@property (nonatomic, strong, readonly) AdSetQDNMediaView *mediaView;

/**
 自渲染 视图注册方法
 
 @warning 当广告不需要展示并且销毁的时候，需要调用 -[AdSetQDNUnifiedNativeAdView unregisterDataObject]方法
 
 @param dataObject 数据对象，必传字段
 @param clickableViews 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
 @param closeableViews 可关闭的视图数组，此数组内的广告元素才可以响应广告对应的关闭事件
 */
- (void)registerDataObject:(AdSetQDNUnifiedNativeAdDataObject *_Nonnull)dataObject
            clickableViews:(NSArray<UIView *> *_Nullable)clickableViews
            closeableViews:(NSArray<UIView *> *_Nullable)closeableViews;

/**
 注销数据对象，在 tableView、collectionView 等场景需要复用 AdSetQDNUnifiedNativeAdView 时，
 需要在合适的时机，例如 cell 的 prepareForReuse 方法内执行 unregisterDataObject 方法，
 将广告对象与 AdSetQDNUnifiedNativeAdView 解绑，具体可参考示例 demo 的 AdSetQDNUnifiedNativeAdCell 类
 */
- (void)unregisterDataObject;

@end

NS_ASSUME_NONNULL_END
