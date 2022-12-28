/***************************************************************************************************
* File name:smbus.h 	
* Description: smbus 系统管理总线（一种类IIC总线的总线）头文件   
* Function List:   
* History:  
*      1. Data：
*      2. Author：Charmander
*      3. Modification：
***********************************************************************************************************/

#ifndef __SMBUS_H
#define __SMBUS_H	 

#include "system.h"

/* SMBUS总线引脚资源在STM32上的映射 */
#define SMBUS_APB2Periph_GPIOx		RCC_APB2Periph_GPIOA
#define SMBUS_GPIOx 				GPIOA
#define SMBUS_SCL 					GPIO_Pin_11
#define SMBUS_SDA 					GPIO_Pin_12

/* 设置SDA引脚模式 */
#define SMBUS_SDA_IN()  {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=8<<16;}
#define SMBUS_SDA_OUT() {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=3<<16;}

/* 读写SMBUS引脚宏 */ 
#define SMBUS_WRITE_SCL    PAout(11) 		
#define SMBUS_WRITE_SDA    PAout(12) 			 
#define SMBUS_READ_SDA     PAin(12) 	

/*
 * 函数名：vSMBus_Init
 * 描述  ：初始化SMBUS
 * 输入  ：无
 * 输出  ：无
 * 返回  ：无
 * 调用  ：无 
 * 举例  ：无
 */
void vSMBus_Init(void) ;

/* 向从机写数据流 */
uint8_t ucSMBUS_StreamWrite(uint8_t ucSlaveAddr, uint8_t ucRegAddr \
							, uint8_t *pucRegDataBuf, uint16_t uiRegDataBufLength) ;

/* 从从机读入数据流 */
uint8_t ucSMBUS_StreamRead(uint8_t ucSlaveAddr, uint8_t ucRegAddr \
							, uint8_t *pucRegDataBuf, uint16_t uiRegDataBufLength) ;

#endif


