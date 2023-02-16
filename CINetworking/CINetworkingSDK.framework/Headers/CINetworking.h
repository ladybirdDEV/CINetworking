//
//  CINetworking.h
//  CINetWorking
//
//  Created by 曹中浩 on 2020/2/28.
//

#import <Foundation/Foundation.h>
#import "CIHTTPSessionManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface CINetworking : NSObject

/// 获取共享单例
+(instancetype)sharedInstance;

@property CIHTTPSessionManager* sessionManager;

///  服务器根路径
@property NSString * baseURL;

/// 通用请求头
@property (nonatomic) NSDictionary * commonRequestHeaders;

/// 通用请求参数
@property (nonatomic) NSDictionary * commonRequestParameters;

/// HTTP Pipelining
@property BOOL usePipelining;

/// 编码格式
@property NSStringEncoding encoding;

/// 缓存策略
@property NSURLRequestCachePolicy cachePolicy;

/// 是否处理cookie
@property BOOL handleCookies;

/// 超时时间
@property NSTimeInterval timeoutInterval;

/// 是否允许蜂窝移动访问
@property BOOL allowsCellularAccess;

/// 可接受StatusCode
@property NSIndexSet * acceptableStatusCodes;

/// 可接受ContentType
@property NSSet<NSString *> * acceptableContentTypes;

/// 网络服务类型
@property NSURLRequestNetworkServiceType networkServiceType;

/// 成功回调
@property void(^onSuccess)(id _Nullable responseObject);
/// 失败回调
@property void(^onFailure)(NSError * error);

// 是否需要打印网络日志

/* 当使用打印日志的时候 只在debug环境适用
 #if defined(DEBUG)
     [[CINetworking sharedInstance] showNetworkingLog];
 #endif
 */
- (void)showNetworkingLog;


///// 设置服务器根路径
///// 请求时使用完整路径时会忽略根路径设置
///// @param baseURL 服务器路径
//-(void)setBaseURL:(NSString *)baseURL;
//
//
//
///// 设置通用请求头
///// 设置后每次请求将会携带该头部数据
///// @param commonRequestHeaders 请求头
//-(void)setCommonRequestHeaders:(NSDictionary * _Nonnull)commonRequestHeaders;
//
///// 设置通用请求参数
///// 设置后每次请求将会携带该参数
///// @param commonRequestParameters 请求参数
//-(void)setCommonRequestParameters:(NSDictionary * _Nonnull)commonRequestParameters;
//
//
///// 设置请求编码格式，默认值为NSUTF8StringEncoding
///// @param encoding 编码格式
//-(void)setEncoding:(NSStringEncoding)encoding;
//
//
///// 设置是否处理set-cookie
///// @param handleCookies 默认为是
//-(void)setHandleCookies:(BOOL)handleCookies;
//
//
///// 设置缓存策略
///// @param cachePolicy 默认为NSURLRequestUseProtocolCachePolicy
//-(void)setCachePolicy:(NSURLRequestCachePolicy)cachePolicy;
//
//
///// 超时时间
///// @param timeoutInterval 默认值60
//-(void)setTimeoutInterval:(NSTimeInterval)timeoutInterval;
//
//
///// 设置可以接受的响应代码
///// @param acceptableStatusCodes 可接受代码
//-(void)setAcceptableStatusCodes:(NSIndexSet * _Nonnull)acceptableStatusCodes;
//
//
///// 设置可以接受的响应类型
///// @param acceptableContentTypes 可接受类型
//-(void)setAcceptableContentTypes:(NSSet<NSString *> * _Nonnull)acceptableContentTypes;
//
//
///// 设置是否允许使用蜂窝连接
///// @param allowsCellularAccess 默认
//-(void)setAllowsCellularAccess:(BOOL)allowsCellularAccess;
//
//
/////  设置网络服务类型，控制优先级
///// @param networkServiceType 默认NSURLNetworkServiceTypeDefault
//-(void)setNetworkServiceType:(NSURLRequestNetworkServiceType)networkServiceType;
//
//
///// 设置是否使用HTTP管线化
///// @param usePipelining 默认值NO
//-(void)setUsePipelining:(BOOL)usePipelining;
//
//
///// 设置失败回调
///// @param onFailure block
//-(void)setOnFailure:(void (^ _Nonnull)(NSError * _Nonnull))onFailure;
//
//
///// 设置成功回调
///// @param onSuccess block
//-(void)setOnSuccess:(void (^ _Nonnull)(id _Nullable))onSuccess;




-(nullable NSURLSessionDataTask *)GET:(NSString *)URLString
                               parameters:(nullable NSDictionary *)parameters
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

-(nullable NSURLSessionDataTask *)GET:(NSString *)URLString
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;


/// GET
/// @param URLString 服务器相对URL或绝对URL
/// @param headers 请求头
/// @param parameters 请求参数
/// @param progress 请求进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)GET:(NSString *)URLString
                                  headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

-(nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                               parameters:(nullable NSDictionary *)parameters
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

-(nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;


/// POST
/// @param URLString 服务器地址
/// @param headers 请求头
/// @param parameters 请求参数
/// @param progress 请求进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)POST:(NSString *)URLString
                                  headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

-(nullable NSURLSessionDataTask *)request:(NSString *)URLString
                                   method:(CIHTTPMethod)method
                               parameters:(nullable NSDictionary *)parameters
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

-(nullable NSURLSessionDataTask *)request:(NSString *)URLString
                                   method:(CIHTTPMethod)method
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

/// 发起请求
/// @param URLString 服务器地址
/// @param method 请求方法
/// @param headers 请求头
/// @param parameters 请求参数
/// @param progress 请求进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)request:(NSString *)URLString
                                   method:(CIHTTPMethod)method
                                  headers:(nullable NSDictionary <NSString *, NSString *> *)headers
                               parameters:(nullable NSDictionary *)parameters
                                 progress:(nullable void(^)(NSProgress * progress))progress
                                  success:(nullable void(^)(id _Nullable responseObject))success
                                  failure:(nullable void(^)(NSError * error))failure;

/// 上传文件
/// @param URLString 服务器URL
/// @param parameters 请求参数
/// @param fileParameters 文件参数
/// @param progress 进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)uploadFile:(NSString *)URLString
                                  parameters:(nullable NSDictionary *)parameters
                              fileParameters:(NSDictionary *)fileParameters
                                    progress:(nullable void(^)(NSProgress * progress))progress
                                     success:(nullable void(^)(id _Nullable responseObject))success
                                     failure:(nullable void(^)(NSError * error))failure;


/// 创建上传任务
/// @param request 请求对象
/// @param progress 进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)uploadTask:(NSURLRequest *)request
                                    progress:(nullable void(^)(NSProgress * progress))progress
                                     success:(nullable void(^)(NSURLResponse * _Nonnull response, id  _Nullable responseObject))success
                                     failure:(nullable void(^)(NSURLResponse * _Nonnull response,NSError * error))failure;


/// 下载文件
/// @param URLString 服务器地址
/// @param parameters 请求参数
/// @param progress 下载进度
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDataTask *)downloadFile:(NSString *)URLString
                                    parameters:(nullable NSDictionary *)parameters
                                      progress:(nullable void(^)(NSProgress * progress))progress
                                       success:(nullable void(^)(id _Nullable responseObject))success
                                       failure:(nullable void(^)(NSError * error))failure;


/// 创建下载任务
/// @param request 请求对象
/// @param parameters 请求参数
/// @param progress 下载进度
/// @param destination 存储路径
/// @param success 成功回调
/// @param failure 失败回调
-(nullable NSURLSessionDownloadTask *)downloadTask:(NSURLRequest *)request
                                        parameters:(nullable NSDictionary *)parameters
                                          progress:(nullable void(^)(NSProgress * progress))progress
                                       destination:(NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destination
                                           success:(nullable void(^)(NSURLResponse * response,NSURL * filePath))success
                                           failure:(nullable void(^)(NSURLResponse * _Nonnull response,NSError * error))failure;
@end

NS_ASSUME_NONNULL_END
