/**
  ******************************************************************************
  * File Name          : readme.txt
  *	Author			   : Endeavor
  * Description        : Introduction for this program
  ******************************************************************************
  * Copyright (c) 2017 CSU_FSAE 
  * All rights reserved.
  *
  ******************************************************************************
  **/
  
	枚举类型编号:
	Can.h						:1~149						(未使用的为保留编号)
	Data_Generic.h				:150~199
	spi.h						:200~249
	HostPCDebug_AT24CxxMem.h	:250~299	
	GPS_UBLOX_NEO_M8N.h			:300~349
	
	Fram存储器，地址分配:
	(占两个字节)
	BrakePressure_Range_High_ID					0x00 				//制动踏板油压传感器压力量程高数据ID，用于无线串口接收&发送
	BrakePressure_Range_Low_ID					0x02				//制动踏板油压传感器压力量程低数据ID，用于无线串口接收&发送
	BrakePressure_Range_ActualHigh_ID			0x04				//制动踏板油压传感器实际高ID，用于无线串口接收&发送
	BrakePressure_Range_ActualLow_ID			0x06				//制动踏板油压传感器实际礗D停糜谖尴叽诮邮�&发送
	AccPeda_Range_High_ID						0x08				//加速踏板行程上限数据ID，用于无线串口接收&发送
	AccPeda_Range_Low_ID						0x0A				//加速踏板行程下限数据ID，用于无线串口接收&发送
	AccPeda_InitialDiff_Of_LandR_ID				0x0C				//左右加速踏板初始时差异值ID，用于无线串口接收&发送
	SterringWheelAngle_Range_ID		 			0x0E				//方向盘转角传感器最大转动角度数据ID，用于无线串口接收&发送
	SterringWheel_ADMiddle_ID					0x10				//方向盘中间位置AD数字量ID，用于无线串口接收&发送
	SterringWheel_TurnRange_ID					0x12				//方向盘左右转动范围AD数字量 ID，用于无线串口接收&发送
	MotCtrllerTempThreshold_High_ID				0x14				//控制水泵开启的电机控制器温度数据ID，用于无线串口接收&发送
	MotCtrllerTempThreshold_Low_ID				0x16				//控制水泵关闭的电机控制器温度数据ID，用于无线串口接收&发送
	Line_Corners_TCSMode_Angle_ID				0x18				//控制牵引力模式选择的方向盘角度数据ID，用于无线串口接收&发送
	DRS_SteeringWheel_Angle_ID					0x1A				//控制DRS开启的方向盘角度数据ID，用于无线串口接收&发送
	Close_DRS_AdjustAngle_ID					0x1C				//开启DRS时，尾翼保持的角度数据ID，用于无线串口接收&发送
	Open_DRS_AdjustAngle_ID						0x1E				//关闭DRS时，尾翼保持的角度数据ID，用于无线串口接收&发送
	TCS_PID_Kp_ID								0x20				//牵引力控制比例系数数据ID，用于无线串口接收&发送
	TCS_PID_Ki_ID								0x22				//牵引力控制积分系数数据ID，用于无线串口接收&发送
	TCS_PID_Kd_ID								0x24				//牵引力控制微分系数数据ID，用于无线串口接收&发送
	OptimalSlipRate_ID							0x26				//牵引力控制最优滑移率数据ID，用于无线串口接收&发送
	SuspensionLineDistF1_ADMiddle_ID			0x28				//前悬架线位移左的中间位置AD数据ID，用于无线串口接收&发送
	SuspensionLineDistF2_ADMiddle_ID			0x2A				//前悬架线位移右的中间位置AD数据ID，用于无线串口接收&发送
	SuspensionLineDistB1_ADMiddle_ID			0x2C				//后悬架线位移左的中间位置AD数据ID，用于无线串口接收&发送
	SuspensionLineDistB2_ADMiddle_ID			0x2E				//后悬架线位移右的中间位置AD数据ID，用于无线串口接收&发送
	
	Mileage_ID 									0xFF				//里程数据
	
	(占一个字节)
	LeakageCurrentLimit_State_Data_ID			0x0101				//IMD 漏电超限 状态数据					
	
	
	