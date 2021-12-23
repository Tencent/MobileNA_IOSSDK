//  Copyright (c) 2021-2022.
//  mna_1_0_0.h
//  mna-1.0.0
//
//  Created by klaus on 2021/8/4.
//

#import <Foundation/Foundation.h>

static const int SuggestTypeCreateQos = 1;
static const int SuggestTypeDeleteQos = 2;
static const int SuggestTypeOnError = 3;
static const int SuggestTypeOnPingInfo = 4;
static const int SuggestTypeOnReportResult = 5;

typedef void(^OnSuggestBlock)(int SuggestType, NSString *info);

/**
    the main file of mna sdk, control the qos create and delete.
        control the network listen start ,report data and stop listen.
 */
@interface IOS_MnaClient : NSObject
{
@private
    NSString *_templateId;
    NSString *_sessionId;     //最后一次发起加速的sessionId
    
    NSString *_secretId;
    NSString *_secretKey;
    NSString *_requestId;
    
    NSString *_errorMsg;
    NSString *_errorCode;
    NSString *_requestInfo;
    

    
    void *_mnaClient;
    
    OnSuggestBlock _listenerCallBack;
    
}


- (void)InitMnaClient:(NSString *)secretId secretKey:(NSString *)secretKey;

- (NSString *)CreateAppTemplate:(NSString *)appName menu:(NSString *)menu
                       appType:(int)appType duration:(int)duration;

- (NSString *)ModifyAppTemplate:(NSString *)templateId appName:(NSString *)appName
                          menu:(NSString *)menu appType:(int)appType duration:(int)duration;

//查询使用默认值 调用此接口
- (NSString *)DescribeAppTemplateItem;

- (NSString *)DescribeAppTemplateItem:(int)offset limit:(int)limit namePattern:(NSString *)namePattern;

- (NSString *)DeleteAppTemplate:(NSString *)templateId;

- (NSString *)CreateQos:(NSArray *)destIpArray duration:(int)duration
             menu:(NSString *)menu templateId:(NSString *)templateId protocol:(int)protocol;

//此接口默认关闭最后一次加速ip
- (NSString *)DeleteQos;

- (NSString *)DeleteQos:(NSString*)sessionId;

- (void)UninitMnaClient;

- (NSString *)GetErrorCode;

- (NSString *)GetErrorMsg;

- (NSString *)GetRequestId;

- (void)InitNetworkListener;

- (void)StartListen:(NSString *)destIp templateId:(NSString *)templateId
            onSuggestCB:(OnSuggestBlock)onSuggestCB;

- (void)StopListen;

@end
