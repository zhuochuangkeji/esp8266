/**
************************************************************
* @file         gizwits_protocol.h
* @brief        对应gizwits_protocol.c的头文件 (包含产品相关定义)
* @author       Gizwits
* @date         2016-09-05
* @version      V03010201
* @copyright    Gizwits
* 
* @note         机智云.只为智能硬件而生
*               Gizwits Smart Cloud  for Smart Products
*               链接|增值ֵ|开放|中立|安全|自有|自由|生态
*               www.gizwits.com
*
***********************************************************/
#ifndef _GIZWITS_PROTOCOL_H
#define _GIZWITS_PROTOCOL_H
#include <stdint.h>
#include "osapi.h"
#include "user_interface.h"
#include "user_webserver.h"
#include "gizwits_product.h"
#include "driver/modbus.h"

/**
* @name 协议版本号
* @{
*/
#define PROTOCOL_VERSION              "00000004"
/**@} */

/**@name P0协议版本号
* @{
*/
#define P0_VERSION                    "00000002"
/**@} */

#define BUFFER_LEN_MAX                900
#define REPORT_TIME_MAX               6000          ///< 6s


/**@name 定时器相关状态
* @{
*/
#define SOC_TIME_OUT                  10
#define MIN_INTERVAL_TIME             2000          ///< The minimum interval for sending
#define MAX_SOC_TIMOUT                1             ///< 1ms
#define TIM_REP_TIMOUT                600000        ///< 600s Regularly report
/**@} */

/**@name task相关定义
* @{
*/
#define SIG_ISSUED_DATA               0x01          ///< 协议处理任务
#define SIG_PASSTHROUGH               0x02          ///< 协议透传任务
#define SIG_IMM_REPORT                0x09          ///< 协议立即上报任务
/**@} */

/** WiFi模组配置参数*/
typedef enum
{
  WIFI_RESET_MODE = 0x00,                           ///< WIFI模组复位
  WIFI_SOFTAP_MODE,                                 ///< WIFI模组softAP模式
  WIFI_AIRLINK_MODE,                                ///< WIFI模组AirLink模式
  WIFI_PRODUCTION_TEST,                             ///< MCU请求WiFi模组进入产测模式
  WIFI_NINABLE_MODE,                                ///< MCU请求模组进入可绑定模式
}WIFI_MODE_TYPE_T;

/** WiFi模组工作状态*/
typedef union
{
    uint16_t value;
    struct
    {
        uint16_t            softap:1;               ///< 表示WiFi模组所处的SOFTAP模式状态，类型为bool
        uint16_t            station:1;              ///< 表示WiFi模组所处的STATION模式状态，类型为bool
        uint16_t            onboarding:1;           ///< 表示WiFi模组所处的配置状态，类型为bool
        uint16_t            binding:1;              ///< 表示WiFi模组所处的绑定状态，类型为bool
        uint16_t            con_route:1;            ///< 表示WiFi模组与路由器的连接状态，类型为bool
        uint16_t            con_m2m:1;              ///< 表示WiFi模组与云端m2m的状态，类型为bool
        uint16_t            reserve1:2;             ///< 数据位补齐
        uint16_t            rssi:3;                 ///< 表示路由的信号强度，类型为数值
        uint16_t            app:1;                  ///< 表示WiFi模组与APP端的连接状态，类型为bool
        uint16_t            test:1;                 ///< 表示WiFi模组所处的场测模式状态，类型为bool
        uint16_t            reserve2:3;             ///< 数据位补齐
    }types;
} wifi_status_t;

/** wifi信号强度数值结构体 */
typedef struct {
    uint8_t rssi;                                   ///< WIFI信号强度
}moduleStatusInfo_t;

#pragma pack(1)
/**@name Product Key (产品标识码)
* @{
*/
#define PRODUCT_KEY "9f6d544e042a40c3a6d1f1e424c25c54"
/**@} */
/**@name Product Secret (产品密钥)
* @{
*/
#define PRODUCT_SECRET "99dbed6c21144d54a3305ddd7d7fe36a"
/**@} */
#define MAX_PACKAGE_LEN    (sizeof(devStatus_t)+sizeof(attrFlags_t)+10)                ///< 数据缓冲区最大长度
#define RB_MAX_LEN          (MAX_PACKAGE_LEN*2)     ///< 环形缓冲区最大长度
/**@name 数据点相关定义
* @{
*/
#define RELAY_BYTEOFFSET                    0
#define RELAY_BITOFFSET                     0
#define RELAY_LEN                           1

#define RELAY1_BYTEOFFSET                    0
#define RELAY1_BITOFFSET                     1
#define RELAY1_LEN                           1

#define RELAY2_BYTEOFFSET                    0
#define RELAY2_BITOFFSET                     2
#define RELAY2_LEN                           1

#define RELAY3_BYTEOFFSET                    0
#define RELAY3_BITOFFSET                     3
#define RELAY3_LEN                           1

#define ENUMERATION_BYTEOFFSET                    0
#define ENUMERATION_BITOFFSET                     4
#define ENUMERATION_LEN                           4


#define DATA0_RATIO                         1
#define DATA0_ADDITION                      0
#define DATA0_MIN                           0
#define DATA0_MAX                           255

#define DATA1_RATIO                         1
#define DATA1_ADDITION                      0
#define DATA1_MIN                           0
#define DATA1_MAX                           255

#define DATA2_RATIO                         1
#define DATA2_ADDITION                      0
#define DATA2_MIN                           0
#define DATA2_MAX                           255

#define DATA3_RATIO                         1
#define DATA3_ADDITION                      0
#define DATA3_MIN                           0
#define DATA3_MAX                           255

#define DATA4_RATIO                         1
#define DATA4_ADDITION                      0
#define DATA4_MIN                           0
#define DATA4_MAX                           255

#define DATA5_RATIO                         1
#define DATA5_ADDITION                      0
#define DATA5_MIN                           0
#define DATA5_MAX                           255

#define DATA6_RATIO                         1
#define DATA6_ADDITION                      0
#define DATA6_MIN                           0
#define DATA6_MAX                           255

#define DATA7_RATIO                         1
#define DATA7_ADDITION                      0
#define DATA7_MIN                           0
#define DATA7_MAX                           255

#define DATA8_RATIO                         1
#define DATA8_ADDITION                      0
#define DATA8_MIN                           0
#define DATA8_MAX                           255

#define DATA9_RATIO                         1
#define DATA9_ADDITION                      0
#define DATA9_MIN                           0
#define DATA9_MAX                           255

#define DATA10_RATIO                         1
#define DATA10_ADDITION                      0
#define DATA10_MIN                           0
#define DATA10_MAX                           255

#define ADC_RATIO                         0.1
#define ADC_ADDITION                      1
#define ADC_MIN                           0
#define ADC_MAX                           990

/**@} */


/** 可写型数据点 布尔和枚举变量 所占字节大小*/
#define COUNT_W_BIT 1







typedef enum
{
    ENUMERATION_VALUE0 = 0,//0
    ENUMERATION_VALUE1 = 1,//1
    ENUMERATION_VALUE2 = 2,//2
    ENUMERATION_VALUE3 = 3,//3
    ENUMERATION_VALUE4 = 4,//4
    ENUMERATION_VALUE5 = 5,//5
    ENUMERATION_VALUE6 = 6,//6
    ENUMERATION_VALUE7 = 7,//7
    ENUMERATION_VALUE8 = 8,//8
    ENUMERATION_VALUE9 = 9,//9
    ENUMERATION_VALUE_MAX,
} ENUMERATION_ENUM_T;

/** 事件枚举*/
typedef enum
{
  WIFI_SOFTAP = 0x00,                               ///< WiFi SOFTAP 配置事件
  WIFI_AIRLINK,                                     ///< WiFi模块 AIRLINK 配置事件
  WIFI_STATION,                                     ///< WiFi模块 STATION 配置事件
  WIFI_OPEN_BINDING,                                ///< WiFi模块开启绑定事件
  WIFI_CLOSE_BINDING,                               ///< WiFi模块关闭绑定事件
  WIFI_CON_ROUTER,                                  ///< WiFi模块已连接路由事件
  WIFI_DISCON_ROUTER,                               ///< WiFi模块已断开连接路由事件
  WIFI_CON_M2M,                                     ///< WiFi模块已连服务器M2M事件
  WIFI_DISCON_M2M,                                  ///< WiFi模块已断开连服务器M2M事件
  WIFI_OPEN_TESTMODE,                               ///< WiFi模块开启测试模式事件
  WIFI_CLOSE_TESTMODE,                              ///< WiFi模块关闭测试模式事件
  WIFI_CON_APP,                                     ///< WiFi模块连接APP事件
  WIFI_DISCON_APP,                                  ///< WiFi模块断开APP事件
  WIFI_RSSI,                                        ///< WiFi模块信号事件
  WIFI_NTP,                                         ///< 网络时间事件
  TRANSPARENT_DATA,                                 ///< 透传事件
  EVENT_RELAY,
  EVENT_RELAY1,
  EVENT_RELAY2,
  EVENT_RELAY3,
  EVENT_ENUMERATION,
  EVENT_DATA0,
  EVENT_DATA1,
  EVENT_DATA2,
  EVENT_DATA3,
  EVENT_DATA4,
  EVENT_DATA5,
  EVENT_DATA6,
  EVENT_DATA7,
  EVENT_DATA8,
  EVENT_DATA9,
  EVENT_DATA10,
  EVENT_BIG_DATA,
  EVENT_TYPE_MAX                                    ///< 枚举成员数量计算 (用户误删)
} EVENT_TYPE_T;


/** 用户区设备状态结构体*/
typedef_t struct {
  bool valueRelay;
  bool valueRelay1;
  bool valueRelay2;
  bool valueRelay3;
  uint32_t valueEnumeration;
  uint32_t valueData0;
  uint32_t valueData1;
  uint32_t valueData2;
  uint32_t valueData3;
  uint32_t valueData4;
  uint32_t valueData5;
  uint32_t valueData6;
  uint32_t valueData7;
  uint32_t valueData8;
  uint32_t valueData9;
  uint32_t valueData10;
  uint8_t valueBig_data[10];
  float valueADC;
} dataPoint_t;

/** 对应协议“4.10 WiFi模组控制设备”中的标志位"attr_flags" */ 
typedef_t struct {
  uint8_t flagRelay:1;
  uint8_t flagRelay1:1;
  uint8_t flagRelay2:1;
  uint8_t flagRelay3:1;
  uint8_t flagEnumeration:1;
  uint8_t flagData0:1;
  uint8_t flagData1:1;
  uint8_t flagData2:1;
  uint8_t flagData3:1;
  uint8_t flagData4:1;
  uint8_t flagData5:1;
  uint8_t flagData6:1;
  uint8_t flagData7:1;
  uint8_t flagData8:1;
  uint8_t flagData9:1;
  uint8_t flagData10:1;
  uint8_t flagBig_data:1;
} attrFlags_t;

/** 对应协议“4.10 WiFi模组控制设备”中的数据值"attr_vals" */
typedef_t struct {
  uint8_t wBitBuf[COUNT_W_BIT];
  uint8_t valueData0;
  uint8_t valueData1;
  uint8_t valueData2;
  uint8_t valueData3;
  uint8_t valueData4;
  uint8_t valueData5;
  uint8_t valueData6;
  uint8_t valueData7;
  uint8_t valueData8;
  uint8_t valueData9;
  uint8_t valueData10;
  uint8_t valueBig_data[10];
} attrVals_t;

/** 对应协议“4.10 WiFi模组控制设备”中“P0协议区”的标志位"attr_flags(1B)" + 数据值"attr_vals(6B)" */ 
typedef_t struct {
    attrFlags_t attrFlags;
    attrVals_t  attrVals;
}gizwitsIssued_t;

/** 对应协议“4.9 设备MCU向WiFi模组主动上报当前状态”中的设备状态"dev_status(11B)" */ 
typedef_t struct {
  uint8_t wBitBuf[COUNT_W_BIT];

  uint8_t valueData0;
  uint8_t valueData1;
  uint8_t valueData2;
  uint8_t valueData3;
  uint8_t valueData4;
  uint8_t valueData5;
  uint8_t valueData6;
  uint8_t valueData7;
  uint8_t valueData8;
  uint8_t valueData9;
  uint8_t valueData10;
  uint8_t valueBig_data[10];


  uint16_t valueADC;


} devStatus_t; 

/** P0 command 命令码*/
typedef enum
{
    ACTION_CONTROL_DEVICE       = 0x01,             ///< 协议4.10 WiFi模组控制设备 WiFi模组发送
    ACTION_READ_DEV_STATUS      = 0x02,             ///< 协议4.8 WiFi模组读取设备的当前状态 WiFi模组发送
    ACTION_READ_DEV_STATUS_ACK  = 0x03,             ///< 协议4.8 WiFi模组读取设备的当前状态 设备MCU回复
    ACTION_REPORT_DEV_STATUS    = 0X04,             ///< 协议4.9 设备MCU向WiFi模组主动上报当前状态 设备MCU发送
    ACTION_W2D_TRANSPARENT_DATA = 0x05,             ///< WiFi到设备MCU透传
    ACTION_D2W_TRANSPARENT_DATA = 0x06,             ///< 设备MCU到WiFi透传
} actionType_t;

                                                                                       
/** 事件队列结构体 */                               
typedef_t struct {                           
    uint8_t num;                                    ///< 队列成员个数
    uint8_t event[EVENT_TYPE_MAX];                  ///< 队列成员事件内容
}eventInfo_t;                                



/** 对应协议“4.9 设备MCU向WiFi模组主动上报当前状态” 中的 设备状态位"dev_status(11B)"  */ 
typedef_t struct {   
    uint8_t action;                        
    devStatus_t devStatus;                          ///< 作用：用来存放待上报的设备状态数据
}gizwitsReport_t;
/** 协议处理相关结构体 */
typedef_t struct
{
    uint32_t timerMsCount;                          ///< 时间计数(Ms)
    uint8_t transparentBuff[BUFFER_LEN_MAX];        ///< 透传数据存储区
    uint32_t transparentLen;                        ///< 透传数据长度
    dataPoint_t gizCurrentDataPoint;                ///< 当前设备状态数据
    dataPoint_t gizLastDataPoint;                   ///< 上次上报的设备状态数据
    gizwitsReport_t reportData;                     ///< 协议上报实际数据
    eventInfo_t issuedProcessEvent;                 ///< 控制事件
}gizwitsProtocol_t;

#pragma pack()

/**@name Gizwits 用户API接口
* @{
*/
void gizwitsSetMode(uint8_t mode);
uint32_t gizwitsGetTimeStamp(void);
void gizwitsInit(void);
int8_t gizwitsHandle(dataPoint_t *dataPoint);
int32_t gizwitsPassthroughData(uint8_t * data, uint32_t len);
/**@} */

#endif
