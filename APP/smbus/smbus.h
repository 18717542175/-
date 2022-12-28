/***************************************************************************************************
* File name:smbus.h 	
* Description: smbus ϵͳ�������ߣ�һ����IIC���ߵ����ߣ�ͷ�ļ�   
* Function List:   
* History:  
*      1. Data��
*      2. Author��Charmander
*      3. Modification��
***********************************************************************************************************/

#ifndef __SMBUS_H
#define __SMBUS_H	 

#include "system.h"

/* SMBUS����������Դ��STM32�ϵ�ӳ�� */
#define SMBUS_APB2Periph_GPIOx		RCC_APB2Periph_GPIOA
#define SMBUS_GPIOx 				GPIOA
#define SMBUS_SCL 					GPIO_Pin_11
#define SMBUS_SDA 					GPIO_Pin_12

/* ����SDA����ģʽ */
#define SMBUS_SDA_IN()  {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=8<<16;}
#define SMBUS_SDA_OUT() {GPIOA->CRH&=0XFFF0FFFF;GPIOA->CRH|=3<<16;}

/* ��дSMBUS���ź� */ 
#define SMBUS_WRITE_SCL    PAout(11) 		
#define SMBUS_WRITE_SDA    PAout(12) 			 
#define SMBUS_READ_SDA     PAin(12) 	

/*
 * ��������vSMBus_Init
 * ����  ����ʼ��SMBUS
 * ����  ����
 * ���  ����
 * ����  ����
 * ����  ���� 
 * ����  ����
 */
void vSMBus_Init(void) ;

/* ��ӻ�д������ */
uint8_t ucSMBUS_StreamWrite(uint8_t ucSlaveAddr, uint8_t ucRegAddr \
							, uint8_t *pucRegDataBuf, uint16_t uiRegDataBufLength) ;

/* �Ӵӻ����������� */
uint8_t ucSMBUS_StreamRead(uint8_t ucSlaveAddr, uint8_t ucRegAddr \
							, uint8_t *pucRegDataBuf, uint16_t uiRegDataBufLength) ;

#endif


