/**
************************************************************
* @file         gizwits_product.c
* @brief        Gizwits 控制协议处理,及平台相关的硬件初始化 
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
#include <stdio.h>
#include <string.h>
#include "gizwits_protocol.h"
#include "driver/hal_key.h"
#include "driver/GPIO_Init.h"

/** 用户区当前设备状态结构体*/
extern dataPoint_t currentDataPoint;

/**@name Gizwits 用户API接口
* @{
*/

/**
* @brief 事件处理接口

* 说明：

* 1.用户可以对WiFi模组状态的变化进行自定义的处理

* 2.用户可以在该函数内添加数据点事件处理逻辑，如调用相关硬件外设的操作接口

* @param[in] info : 事件队列
* @param[in] data : 协议数据
* @param[in] len : 协议数据长度
* @return NULL
* @ref gizwits_protocol.h
*/
int8_t ICACHE_FLASH_ATTR gizwitsEventProcess(eventInfo_t *info, uint8_t *data, uint32_t len)
{
  uint8_t i = 0;
  unsigned int HEAD,KAI;

   HEAD=MODBUS_HEAD;
  	KAI=OPEN;
  dataPoint_t *dataPointPtr = (dataPoint_t *)data;
  moduleStatusInfo_t *wifiData = (moduleStatusInfo_t *)data;

  if((NULL == info) || (NULL == data))
  {
    return -1;
  }

  for(i=0; i<info->num; i++)
  {
    switch(info->event[i])
    {
      case EVENT_RELAY:
        currentDataPoint.valueRelay = dataPointPtr->valueRelay;
        os_printf("Evt: EVENT_RELAY %d \n", currentDataPoint.valueRelay);
        if(0x01 == currentDataPoint.valueRelay)
        {
        	RELAY_ON(RELAY_ONE);//12
        	//uart0_sendStr("one_on");
        // COIL_STATUS(HEAD,READ_COIL_STATUS,KAI);

          //user handle
        }
        else
        {
        	RELAY_OFF(RELAY_ONE);//12
        	uart0_sendStr("one_off");

          //user handle    
        }
        break;
      case EVENT_RELAY1:
        currentDataPoint.valueRelay1 = dataPointPtr->valueRelay1;
        os_printf("Evt: EVENT_RELAY1 %d \n", currentDataPoint.valueRelay1);
        if(0x01 == currentDataPoint.valueRelay1)
        {
        	RELAY_ON(RELAY_TWO);//13
        	uart0_sendStr("two_on");
          //user handle
        }
        else
        {
        	RELAY_OFF(RELAY_TWO);//13
         	uart0_sendStr("two_off");
          //user handle    
        }
        break;
      case EVENT_RELAY2:
        currentDataPoint.valueRelay2 = dataPointPtr->valueRelay2;
        os_printf("Evt: EVENT_RELAY2 %d \n", currentDataPoint.valueRelay2);
        if(0x01 == currentDataPoint.valueRelay2)
        {
        	RELAY_ON(RELAY_THREE);//14
        	uart0_sendStr("three_on");

          //user handle
        }
        else
        {
        	RELAY_OFF(RELAY_THREE);//14
         	uart0_sendStr("three_off");

          //user handle    
        }
        break;
      case EVENT_RELAY3:
        currentDataPoint.valueRelay3 = dataPointPtr->valueRelay3;
        os_printf("Evt: EVENT_RELAY3 %d \n", currentDataPoint.valueRelay3);
        if(0x01 == currentDataPoint.valueRelay3)
        {
        	RELAY_ON(RELAY_FOUR);//16
        	uart0_sendStr("four_on");

          //user handle
        }
        else
        {
        	RELAY_OFF(RELAY_FOUR);//16
         	uart0_sendStr("four_off");

          //user handle    
        }
        break;

      case EVENT_ENUMERATION:
        currentDataPoint.valueEnumeration = dataPointPtr->valueEnumeration;
        os_printf("Evt: EVENT_ENUMERATION %d\n", currentDataPoint.valueEnumeration);
        switch(currentDataPoint.valueEnumeration)
        {
          case ENUMERATION_VALUE0:
            //user handle
            break;
          case ENUMERATION_VALUE1:
            //user handle
            break;
          case ENUMERATION_VALUE2:
            //user handle
            break;
          case ENUMERATION_VALUE3:
            //user handle
            break;
          case ENUMERATION_VALUE4:
            //user handle
            break;
          case ENUMERATION_VALUE5:
            //user handle
            break;
          case ENUMERATION_VALUE6:
            //user handle
            break;
          case ENUMERATION_VALUE7:
            //user handle
            break;
          case ENUMERATION_VALUE8:
            //user handle
            break;
          case ENUMERATION_VALUE9:
            //user handle
            break;
          default:
            break;
        }
        break;

      case EVENT_DATA0:
        currentDataPoint.valueData0 = dataPointPtr->valueData0;
        os_printf("Evt:EVENT_DATA0 %d\n",currentDataPoint.valueData0);
        //user handle
        break;
      case EVENT_DATA1:
        currentDataPoint.valueData1 = dataPointPtr->valueData1;
        os_printf("Evt:EVENT_DATA1 %d\n",currentDataPoint.valueData1);
        //user handle
        break;
      case EVENT_DATA2:
        currentDataPoint.valueData2 = dataPointPtr->valueData2;
        os_printf("Evt:EVENT_DATA2 %d\n",currentDataPoint.valueData2);
        //user handle
        break;
      case EVENT_DATA3:
        currentDataPoint.valueData3 = dataPointPtr->valueData3;
        os_printf("Evt:EVENT_DATA3 %d\n",currentDataPoint.valueData3);
        //user handle
        break;
      case EVENT_DATA4:
        currentDataPoint.valueData4 = dataPointPtr->valueData4;
        os_printf("Evt:EVENT_DATA4 %d\n",currentDataPoint.valueData4);
        //user handle
        break;
      case EVENT_DATA5:
        currentDataPoint.valueData5 = dataPointPtr->valueData5;
        os_printf("Evt:EVENT_DATA5 %d\n",currentDataPoint.valueData5);
        //user handle
        break;
      case EVENT_DATA6:
        currentDataPoint.valueData6 = dataPointPtr->valueData6;
        os_printf("Evt:EVENT_DATA6 %d\n",currentDataPoint.valueData6);
        //user handle
        break;
      case EVENT_DATA7:
        currentDataPoint.valueData7 = dataPointPtr->valueData7;
        os_printf("Evt:EVENT_DATA7 %d\n",currentDataPoint.valueData7);
        //user handle
        break;
      case EVENT_DATA8:
        currentDataPoint.valueData8 = dataPointPtr->valueData8;
        os_printf("Evt:EVENT_DATA8 %d\n",currentDataPoint.valueData8);
        //user handle
        break;
      case EVENT_DATA9:
        currentDataPoint.valueData9 = dataPointPtr->valueData9;
        os_printf("Evt:EVENT_DATA9 %d\n",currentDataPoint.valueData9);
        //user handle
        break;
      case EVENT_DATA10:
        currentDataPoint.valueData10 = dataPointPtr->valueData10;
        os_printf("Evt:EVENT_DATA10 %d\n",currentDataPoint.valueData10);
        //user handle
        break;

      case EVENT_BIG_DATA:
        os_printf("Evt: EVENT_BIG_DATA\n");
        memcpy((uint8_t *)&currentDataPoint.valueBig_data,(uint8_t *)&dataPointPtr->valueBig_data,sizeof(currentDataPoint.valueBig_data));
        //user handle
        break;

      case WIFI_SOFTAP:
        break;
      case WIFI_AIRLINK:
        break;
      case WIFI_STATION:
        break;
      case WIFI_CON_ROUTER:
        break;
      case WIFI_DISCON_ROUTER:
        break;
      case WIFI_CON_M2M:
        break;
      case WIFI_DISCON_M2M:
        break;
      case WIFI_RSSI:
        os_printf("RSSI %d\n", wifiData->rssi);
        break;
      case TRANSPARENT_DATA:
        os_printf("TRANSPARENT_DATA \n");
        //user handle , Fetch data from [data] , size is [len]
        break;
      default:
        break;
    }
  }
  system_os_post(USER_TASK_PRIO_0, SIG_UPGRADE_DATA, 0);
  return 0;
}
/**@} */
