**MNA IOS\_SDK接口文档v1.0.0**

## **一、SDK说明**
1. 本SDK支持的最低IOS版本是13.0，建议在IOS13.0以上版本使用

## **二、SDK 接入文件**
使用pod 搜索MNA\_IOSSDK查看最新版本，在Podfile中添加依赖：pod 'MNA\_IOSSDK'
## **三、SDK 依赖库**
1. other linker Flags：-lz -lstdc++
1. ios需开启http权限：App Transport Security Settings->Allow Arbitrary Loads->Yes

## **四、SDK 需要的权限**
为给您带来更好的产品和服务体验，我们在持续努力改进我们的技术，随之我们可能会不时推出新的或优化后的功能、服务，可能需要收集、使用新的个人信息或变更个人信息使用目的或方式。对此，我们将通过弹窗或更新本政策等方式向您说明对应信息的收集目的、范围及使用方式，并为您提供自主选择同意的方式，且在征得您明示同意收集、使用。

`       `**1.加速功能**

`        `当您使用软件开发工具包（SDK）提供的Qos加速功能时，我们需要获取您当前设备的运营商信息，公网IP以及您的**私网IP**地址来发起加速，我们会严格遵守相关法律法规将这类信息做匿名化、去标识化处理。

`        `**2.网络监听功能**

`        `当您使用SDK的网络监听功能时，为向您提供更直观的加速结果数据展示，SDK会基于您所在的基站小区位置进行节点测速，我们需要获取您当前设备的相关信息（包含设备型号、操作系统版本、等设备标识符）我们会请求您授权**网络权限。**

`        `您的信任对我们非常重要，我们深知个人信息对您的重要性， 我们将按法律法规要求，采取相应安全保护措施，尽力保护您的个人信息安全可控。如对本政策内容有任何疑问、意见或者建议，您可通过腾讯方提供的联系方式与我们联系。

## **五、API 接口描述**
### **1、MNA加速API**
#### **（1）初始化MnaClient**
```objective-c
(void)InitMnaClient:(NSString *)secretId secretKey:(NSString *)secretKey;
```



|**参数**|**含义**|
| :-: | :-: |
|secretId|腾讯云账号的secretId|
|secretKey|腾讯云账号的secretKey|
secretId 和 secretKey申请详情请见：

<https://cloud.tencent.com/login?s_url=https%3A%2F%2Fconsole.cloud.tencent.com%2Fcam%2Fcapi>

临时secretId 和 secretKey申请详情请见（客户端保留永久密钥有泄露风险，建议使用临时密钥）：

<https://cloud.tencent.com/document/product/436/14048>

#### **（2）反初始化MnaClient**
```objective-c
- (void)UninitMnaClient;
```

清理释放资源。

#### **（3）创建应用模版（不建议调用）**

```objective-c
- (NSString *)CreateAppTemplate:(NSString *)appName 
					menu (NSString *)menu appType:(int)appType duration:(int)duration;
```

| 参数名称 | 必选 | 类型    | 描述                                                         |
| -------- | ---- | ------- | ------------------------------------------------------------ |
| Region   | 否   | String  | 公共参数，本接口不需要传递此参数。                           |
| AppName  | 是   | String  | 最长支持60个字符                                             |
| QosMenu  | 是   | String  | 加速套餐T100K：上/下行保障 100kbps  T200K：上/下行保障 200kbps T400K：上/下行保障 400kbps BD1M：下行带宽保障1Mbps BD2M：下行带宽保障2Mbps BD4M：下行带宽保障4Mbps BU1M：上行带宽保障1Mbps BU2M：上行带宽保障2Mbps BU4M：上行带宽保障4Mbps 以下为推荐参数：● 游戏：T100K● 视频：BD4M● 直播：BU4M● 支付：T400K● 其他：T100K |
| AppType  | 是   | Integer | 1. 游戏2. 视频3. 直播4. 支付99. 其他                         |
| Duration | 是   | Integer | 单次加速时长(分钟)，取值范围为5到60                          |

若成功返回templateId（应用模版ID 最长32个字符）。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（4）修改应用模版（不建议调用）**
```objective-c
-(NSString *)ModifyAppTemplate:(NSString *)templateId appName:(NSString *)appName

                        menu:(NSString *)menu appType:(int)appType duration:(int)duration;
```

| 参数名称   | 必选 | 类型    | 描述                                                         |
| ---------- | ---- | ------- | ------------------------------------------------------------ |
| Region     | 否   | String  | 公共参数，本接口不需要传递此参数。                           |
| TemplateId | 是   | String  | 应用模板ID                                                   |
| AppName    | 是   | String  | 新的应用模板名称                                             |
| AppType    | 是   | Integer | 1. 游戏2. 视频3. 直播4. 支付99. 其他                         |
| QosMenu    | 是   | String  | 加速套餐：T100K：上/下行保障 100kbps T200K：上/下行保障 200kbps T400K：上/下行保障 400kbps BD1M：下行带宽保障1Mbps BD2M：下行带宽保障2Mbps BD4M：下行带宽保障4Mbps BU1M：上行带宽保障1Mbps BU2M：上行带宽保障2Mbps BU4M：上行带宽保障4Mbps |
| Duration   | 是   | Integer | 单次加速时长(分钟)，取值范围为5到60                          |

若成功返回 requestId。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（5）删除应用模版（不建议调用）**
```objective-c
- (NSString *)DeleteAppTemplate:(NSString *)templateId;
```

| 参数名称   | 必选 | 类型   | 描述                               |
| ---------- | ---- | ------ | ---------------------------------- |
| Region     | 否   | String | 公共参数，本接口不需要传递此参数。 |
| TemplateId | 是   | String | 应用模板ID                         |

若成功返回 requestId。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（6）获取应用模版列表（不建议调用）**
```objective-c
//查询使用默认值 调用此接口

- (NSString *)DescribeAppTemplateItem;

- (NSString *)DescribeAppTemplateItem:(int)offset limit:(int)limit namePattern:(NSString *)namePattern;
```

| 参数名称    | 必选 | 类型    | 描述                                   |
| ----------- | ---- | ------- | -------------------------------------- |
| Region      | 否   | String  | 公共参数，本接口不需要传递此参数。     |
| Offset      | 否   | Integer | 数据的页面偏移编号，默认为0,即第一页。 |
| Limit       | 否   | Integer | 单页面数据条目限制，默认为20           |
| NamePattern | 否   | String  | 用于AppName模糊查询                    |

返回值：

若成功返回包含模版的json字符串。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（7）发起MNA加速**
```objective-c
- (NSString *)CreateQos:(NSArray *)destIpArray duration:(int)duration

             menu:(NSString *)menu templateId:(NSString *)templateId;
```

| 参数       | 必选 | 类型    | 含义                                                         |
| ---------- | ---- | ------- | ------------------------------------------------------------ |
| destIp     | 是   | NSArray | String数组类型，加速业务目标IP地址数组，最多支持4个Ipv4地址  |
| qosMenu    | 是   | String  | 加速套餐T100K：上/下行保障 100kbpsT200K：上/下行保障 200kbpsT400K：上/下行保障 400kbpsBD1M：下行带宽保障1MbpsBD2M：下行带宽保障2MbpsBD4M：下行带宽保障4MbpsBU1M：上行带宽保障1MbpsBU2M：上行带宽保障2MbpsBU4M：上行带宽保障4Mbps |
| duration   | 是   | Integer | 期望加速时长（单位分钟）                                     |
| templateId | 是   | String  | 应用模板ID                                                   |

返回值：

若成功返回sessionId。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（8）取消MNA加速**
此接口默认关闭最后一次加速ip

```objective-c
- (NSString *)DeleteQos;
```

根据sessionId结束加速。

```objective-c
- (NSString *)DeleteQos:(NSString *)sessionId;
```

返回值：

若成功返回sessionId。

失败返回nil，调用GetErrorCode(), GetErrorMsg(), GetRequestId()获取相应信息。

#### **（9）获取错误码**
```objective-c
- (NSString *)GetErrorCode;
```

返回值：返回最后一次请求失败对应错误码。

#### **（10）获取错误信息**
```objective-c
- (NSString *)GetErrorMsg;
```

返回值：返回最后一次请求失败对应错误信息。

#### **（11）获取请求Id**
```objective-c
- (NSString *)GetRequestId;
```

返回值：返回最后一次请求Id。

### **2、网络监听API**
1. #### **初始化监听器**
  ```objective-c
  - (void)InitNetworkListener;
  ```

1. #### **开始监听**

  ```
  typedef void(^OnSuggestBlock)(int SuggestType, NSString *info) ;
  
  - (void)StartListen:(NSString *)destIp onSuggestCB:(OnSuggestBlock)onSuggestCB;
  
  ```

  

1. **停止监听**

  ```objective-c
  - (void)StopListen;
  ```

  

  ## **六、错误码**

错误码列表：

| 错误码                            | 说明                                                         |
| --------------------------------- | ------------------------------------------------------------ |
| ActionOffline                     | 接口已下线。                                                 |
| AuthFailure.InvalidAuthorization  | 请求头部的 Authorization 不符合腾讯云标准。                  |
| AuthFailure.InvalidSecretId       | 密钥非法（不是云 API 密钥类型）。                            |
| AuthFailure.MFAFailure            | [MFA](https://cloud.tencent.com/document/product/378/12036) 错误。 |
| AuthFailure.SecretIdNotFound      | 密钥不存在。请在控制台检查密钥是否已被删除或者禁用，如状态正常，请检查密钥是否填写正确，注意前后不得有空格。 |
| AuthFailure.SignatureExpire       | 签名过期。Timestamp 和服务器时间相差不得超过五分钟，请检查本地时间是否和标准时间同步。 |
| AuthFailure.SignatureFailure      | 签名错误。签名计算错误，请对照调用方式中的签名方法文档检查签名计算过程。 |
| AuthFailure.TokenFailure          | token 错误。                                                 |
| AuthFailure.UnauthorizedOperation | 请求未授权。请参考 [CAM](https://cloud.tencent.com/document/product/598) 文档对鉴权的说明。 |
| DryRunOperation                   | DryRun 操作，代表请求将会是成功的，只是多传了 DryRun 参数。  |
| FailedOperation                   | 操作失败。                                                   |
| InternalError                     | 内部错误。                                                   |
| InvalidAction                     | 接口不存在。                                                 |
| InvalidParameter                  | 参数错误（包括参数格式、类型等错误）。                       |
| InvalidParameterValue             | 参数取值错误。                                               |
| InvalidRequest                    | 请求 body 的 multipart 格式错误。                            |
| LimitExceeded                     | 超过配额限制。                                               |
| MissingParameter                  | 缺少参数。                                                   |
| NoSuchProduct                     | 产品不存在                                                   |
| NoSuchVersion                     | 接口版本不存在。                                             |
| RequestLimitExceeded              | 请求的次数超过了频率限制。                                   |
| RequestSizeLimitExceeded          | 请求包超过限制大小。                                         |
| ResourceInUse                     | 资源被占用。                                                 |
| ResourceInsufficient              | 资源不足。                                                   |
| ResourceNotFound                  | 资源不存在。                                                 |
| ResourceUnavailable               | 资源不可用。                                                 |
| ServiceUnavailable                | 当前服务暂时不可用。                                         |
| UnauthorizedOperation             | 未授权操作。                                                 |
| UnknownParameter                  | 未知参数错误，用户多传未定义的参数会导致错误。               |
| UnsupportedOperation              | 操作不支持。                                                 |
| UnsupportedProtocol               | http(s) 请求协议错误，只支持 GET 和 POST 请求。              |
| UnsupportedRegion                 | 接口不支持所传地域。                                         |

业务错误码：

| 错误码                               | 说明                               |
| ------------------------------------ | ---------------------------------- |
| AuthFailure                          | CAM签名/鉴权错误。                 |
| InvalidParameterValue.VendorNotFound | 无法获取到可加速的运营商信息       |
| OperationDenied                      | 操作被拒绝。                       |
| OperationDenied.CTCCTokenExpired     | 中国电信加速token过期。            |
| OperationDenied.CreateQosExceedLimit | 相同加速间隔时间过短。             |
| OperationDenied.RequestQosTimeout    | 请求运营商加速超时。               |
| OperationDenied.UserNonAccelerated   | 该用户加速已取消，不处于加速状态。 |
| OperationDenied.UserOutOfCoverage    | 该用户不在运营商网络可加速范围内   |
| OperationDenied.VendorReturnError    | 运营商返回结果错误。               |
| OperationDenied.VendorServerError    | 运营商服务器临时错误。             |

