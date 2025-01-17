#ifndef __HOSTPCDEBUG_AT24CXXMEM_H
#define __HOSTPCDEBUG_AT24CXXMEM_H

#include "stm32f4xx_hal.h"
#include "usart.h"
#include "Wireless_AS32_TTL_1W.h"
#include "AT24Cxx.h" 
#include "Data_Generic.h"
#include "spi.h"
#include "can.h"
//#include "HostPCDisplay.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
/*------------存储在EEPROM中的地址------------*/
#define Mileage_ID 														0xFF						//里程数据，两字节
#define LeakageCurrentLimit_State_Data_ID			0x0101					//IMD 漏电超限 状态数据，单字节		
/*------------Labview——ECU1&ECU1——LabviewID--------------------*/
//ECU1接收&发送模块1,该列ID同为EEPROM中的存储地址
#define Transmit1AndReceiveLabviewHeader		(uint16_t)0xA6A6		  //ECU1接收&发送的数据表头
#define BrakePressure_Range_High_ID								0x00 						//制动踏板油压传感器压力量程高数据ID，用于无线串口接收&发送
#define BrakePressure_Range_Low_ID								0x02						//制动踏板油压传感器压力量程低数据ID，用于无线串口接收&发送
#define BrakePressure_Range_ActualHigh_ID					0x04						//制动踏板油压传感器实际高ID，用于无线串口接收&发送
#define BrakePressure_Range_ActualLow_ID					0x06						//制动踏板油压传感器实际礗D停糜谖尴叽诮邮�&发送
#define AccPeda_Range_High_ID											0x08						//加速踏板行程上限数据ID，用于无线串口接收&发送
#define AccPeda_Range_Low_ID											0x0A						//加速踏板行程下限数据ID，用于无线串口接收&发送
#define AccPeda_InitialDiff_Of_LandR_ID						0x0C						//左右加速踏板初始时差异值ID，用于无线串口接收&发送
#define SterringWheelAngle_Range_ID		 						0x0E						//方向盘转角传感器最大转动角度数据ID，用于无线串口接收&发送
#define SterringWheel_ADMiddle_ID									0x10						//方向盘中间位置AD数字量ID，用于无线串口接收&发送
#define SterringWheel_TurnRange_ID								0x12						//方向盘左右转动范围AD数字量 ID，用于无线串口接收&发送
#define MotCtrllerTempThreshold_High_ID						0x14						//控制水泵开启的电机控制器温度数据ID，用于无线串口接收&发送
#define MotCtrllerTempThreshold_Low_ID						0x16						//控制水泵关闭的电机控制器温度数据ID，用于无线串口接收&发送
#define Line_Corners_TCSMode_Angle_ID							0x18						//控制牵引力模式选择的方向盘角度数据ID，用于无线串口接收&发送
#define DRS_SteeringWheel_Angle_ID								0x1A						//控制DRS开启的方向盘角度数据ID，用于无线串口接收&发送
#define Close_DRS_AdjustAngle_ID									0x1C						//开启DRS时，尾翼保持的角度数据ID，用于无线串口接收&发送
#define Open_DRS_AdjustAngle_ID										0x1E						//关闭DRS时，尾翼保持的角度数据ID，用于无线串口接收&发送
#define TCS_PID_Kp_ID															0x20						//牵引力控制比例系数数据ID，用于无线串口接收&发送
#define TCS_PID_Ki_ID															0x22						//牵引力控制积分系数数据ID，用于无线串口接收&发送
#define TCS_PID_Kd_ID															0x24						//牵引力控制微分系数数据ID，用于无线串口接收&发送
#define OptimalSlipRate_ID												0x26						//牵引力控制最优滑移率数据ID，用于无线串口接收&发送
#define SuspensionLineDistF1_ADMiddle_ID					0x28						//前悬架线位移左的中间位置AD数据ID，用于无线串口接收&发送
#define SuspensionLineDistF2_ADMiddle_ID					0x2A						//前悬架线位移右的中间位置AD数据ID，用于无线串口接收&发送
#define SuspensionLineDistB1_ADMiddle_ID					0x2C						//后悬架线位移左的中间位置AD数据ID，用于无线串口接收&发送
#define SuspensionLineDistB2_ADMiddle_ID					0x2E						//后悬架线位移右的中间位置AD数据ID，用于无线串口接收&发送
#define WirelessReceiveDataNum										24							//无线接收Labview的数据数量
//ECU1发送模块2
#define TransmitLabviewModule2Header		(uint16_t)0xA7A7					//ECU1发送到Labview模块2数据表头
#define BrakePressureFrontDisplay_ID							0x64						//刹车油压前数据显示ID,用于无线串口发送到上位机
#define BrakePressureBackDisplay_ID								0x66						//刹车油压后数据显示ID,用于无线串口发送到上位机
#define AccPedaLeftAdDigitalValueDisplay_ID				0x68						//加速踏板左AD数字量ID,用于无线串口发送到上位机
#define AccPedaRightAdDigitalValueDisplay_ID			0x6A						//加速踏板右AD数字量ID,用于无线串口发送到上位机
#define SterringWheelAdDigitalValueDisplay_ID			0x6C						//方向盘AD数字量ID,用于无线串口发送到上位机
#define WheelSpeedFrontDisplay_ID									0x6E						//前轮轮速ID,用于无线串口发送到上位机
#define WheelSpeedBackDisplay_ID									0x70						//后轮轮速ID,用于无线串口发送到上位机
#define CurrentSlipRateDisplay_ID									0x72						//当前滑移率ID,用于无线串口发送到上位机
#define SuspensionLineDistF1_ADView_ID					 	0x74						//前悬架线位移左当前AD数据的ID，用于无线串口发送到上位机
#define SuspensionLineDistF2_ADView_ID					 	0x76						//前悬架线位移右当前AD数据的ID，用于无线串口发送到上位机
#define SuspensionLineDistB1_ADView_ID					 	0x78						//后悬架线位移左当前AD数据的ID，用于无线串口发送到上位机
#define SuspensionLineDistB2_ADView_ID						0x7A						//后悬架线位移右当前AD数据的ID，用于无线串口发送到上位机
#define TCS_PID_OUT_View_ID												0x7C						//TCS的PID调节输出数据的ID，用于无线串口发送到上位机
#define WirelessTransmitData2Num									13							//无线发送到Labview模块2的数据数量

//存储悬架线位移调零AD值到EEPROM中的存储地址
#define SuspensionLineShiftF1_ADMiddle_For_Key_ZeroSetting_ID  	0x30 	//前悬架线位移左的中间位置AD数据
#define SuspensionLineShiftF2_ADMiddle_For_Key_ZeroSetting_ID		0x32	//前悬架线位移右的中间位置AD数据
#define SuspensionLineShiftB1_ADMiddle_For_Key_ZeroSetting_ID		0x34	//后悬架线位移左的中间位置AD数据
#define SuspensionLineShiftB2_ADMiddle_For_Key_ZeroSetting_ID		0x36	//后悬架线位移右的中间位置AD数据

typedef struct{
	uint8_t EEPROMMemoryID;
	uint8_t EEPROMMemoryData[2];
}EEPROMMemoryMessageTypedef;


typedef struct{
	uint8_t WirelessTransmitID;
	uint8_t WirelessTransmitData[2];
}WirelessTransmit1And2_MessageTypedef;


typedef enum{
	BrakePressure_Range_High_n=250,		
	BrakePressure_Range_Low_n,
	BrakePressure_Range_ActualHigh_n,
	BrakePressure_Range_ActualLow_n,
	AccPeda_Range_High_n,
	AccPeda_Range_Low_n,	
	AccPeda_InitialDiff_Of_LandR_n,
	SterringWheelAngle_Range_n,
	SterringWheel_ADMiddle_n,
	SterringWheel_TurnRange_n,
	MotCtrllerTempThreshold_High_n,
	MotCtrllerTempThreshold_Low_n,
	Line_Corners_TCSMode_Angle_n,
	DRS_SteeringWheel_Angle_n,
	Close_DRS_AdjustAngle_n,
	Open_DRS_AdjustAngle_n,
	TCS_PID_Kp_n,
	TCS_PID_Ki_n,
	TCS_PID_Kd_n,
	OptimalSlipRate_n,
	SuspensionLineDistF1_ADMiddle_n,
	SuspensionLineDistF2_ADMiddle_n,
	SuspensionLineDistB1_ADMiddle_n,
	SuspensionLineDistB2_ADMiddle_n,
	
	TCS_PID_OUT_n,
}Wireless_ReceiveData_n;

typedef enum{
	SuspensionLineShiftF1_ADMiddle_For_Key_ZeroSetting_n=290,	//前悬架线位移左的中间位置AD数据
	SuspensionLineShiftF2_ADMiddle_For_Key_ZeroSetting_n,			//前悬架线位移右的中间位置AD数据
	SuspensionLineShiftB1_ADMiddle_For_Key_ZeroSetting_n,			//后悬架线位移左的中间位置AD数据
	SuspensionLineShiftB2_ADMiddle_For_Key_ZeroSetting_n			//后悬架线位移右的中间位置AD数据
}SuspensionLineShift_ADMiddle_For_Key_ZeroSetting_n;

void Wireless_FREERTOS_Init(void);															//Wireless通信中建立任务的函数

osThreadId Get_WirelessTransmit1And2_LabviewQueueHandle(void);	//存放Wireless发送到Labview数据的队列

void Wireless_DATA_Send1And2(uint8_t Labview_ID);								//投递Wireless发送内容到队列的函数，发送模块1和2的数据

void FirstPowerOnReadEEPROMInit(void);													//第一次上电读取EEPROM中数据

void Get_Wireless_DataFrom_EEPROM(Wireless_ReceiveData_n name_num,void*extern_data);//取值函数，搬运Wireless接收并解析好的数据,@Wireless_ReceiveData_n
void Get_TCS_PID_OUT_Data(Wireless_ReceiveData_n name_num,void*extern_data);//取值函数，搬运TCS_PID_OUT相关数据@Wireless_ReceiveData_n
void Get_SuspensionLineShift_ADMiddle_For_Key_ZeroSetting_Data(SuspensionLineShift_ADMiddle_For_Key_ZeroSetting_n name_num,void*extern_data);//取值函数，搬运 悬架线位移调零时，悬架线位移所处位置的AD值
void Set_Wireless_DataFrom_EEPROM(Wireless_ReceiveData_n name_num,void*extern_data);//修改Wireless接收并解析好的数据,@Wireless_ReceiveData_n
void Set_TCS_PID_OUT_Data(Wireless_ReceiveData_n name_num,void*extern_data);//修改TCS_PID_OUT相关变量@Wireless_ReceiveData_n
void Set_SuspensionLineShift_ADMiddle_For_Key_ZeroSetting_Data(SuspensionLineShift_ADMiddle_For_Key_ZeroSetting_n name_num,void*extern_data);//修改函数，修改 悬架线位移调零时，悬架线位移所处位置的AD值
#endif

