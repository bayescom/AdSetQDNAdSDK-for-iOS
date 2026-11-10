//
//  AdSetQDNMediaView.h
//  AdSetQDNSDK
//
//  Created by guangyao on 2024/1/9.
//  Copyright © 2024 AdSetQDN. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AdSetQDNMediaView;
@protocol AdSetQDNMediaViewDelegate <NSObject>

@optional

- (void)adsetqdn_mediaViewDidPlayFinish:(AdSetQDNMediaView *)mediaView;

@end

@interface AdSetQDNMediaView : UIView

/// AdSetQDNMediaView 回调对象
@property (nonatomic, weak) id <AdSetQDNMediaViewDelegate> delegate;

/// 播放静音开关
/// - Parameter flag: 是否静音
- (void)muteEnable:(BOOL)flag;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 销毁播放器视图
- (void)destroy;

@end

NS_ASSUME_NONNULL_END
