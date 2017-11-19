#ifndef _RTUAPI_H
#define _RTUAPI_H

#include <list>
#include <string>
using std::list;
using std::string;
//=================================================================================================================================

typedef unsigned long long u64;			//uint8
typedef long long s64;					//sint8
typedef unsigned int u32;				//uint4
typedef int s32;						//sint4
typedef unsigned short u16;				//uint2
typedef short s16;						//sint2
typedef unsigned char u8;				//uint1
typedef char s8;						//sint1

typedef struct _logonInfo
{
	CString strSIM;
	CString strIMEI;
	CString strVer;
	CString strModule;
}LogonInfo;

typedef struct _digital_out_ 
{
	int state;
	int cycle;
}DIGITAL_OUT;

typedef struct _pwm_
{
	int cycle;
	int duty;
}PWM;

typedef struct _counter_
{
	__int64 val;
}COUNTER;

typedef struct _common_
{
	int val;
}COMMON;

typedef union _interface_value_
{
	DIGITAL_OUT digitalOut;
	PWM			pwm;
	COUNTER		counter;
	COMMON		common;
}INTERFACE_VAL;

typedef struct _interface_rdv_
{
	int type;
	int number;
	INTERFACE_VAL valueUnit;
}INTERFACE_RDV;

typedef struct _interface_ctl_
{
	int type;
	int number;
	int val;
}INTERFACE_CTL;

enum ValueType
{
	STRINGTYPE,
	INTTYPE,
};

typedef struct _config_item_
{
	int id;
	ValueType type;
	int intVal;
	CString strVal;
}CONFIG_ITEM;

typedef struct _interface_alarm_
{
	int type;
	int number;
	string strAlarm;
}INTERFACE_ALARM;

//设备上下线回调
/*@pThiz: 回调对象*/
/*@devAddr: 设备地址*/
/*@bLogon: 1是上线 0是下线*/
/*@info: 注册信息*/
typedef void (WINAPI *RtuLogonCallBack) (const void *pThiz, const u32 devAddr,const u8 bLogon, const LogonInfo info);

//接口状态获取的回调
/*@pThiz: 回调对象*/
/*@devAddr: 设备地址*/
/*@nRequestID: 通信包标识号*/
/*@nResult: >=0则表示成功，否则失败*/
/*@pList: 接口状态链表（具体格式参照协议）*/
typedef void (WINAPI *RtuInterfaceGetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											   const list<INTERFACE_RDV> *pList);

//接口设置的回调
/*@pFailedList: 返回设置失败的链表（具体格式参照协议）*/
typedef void (WINAPI *RtuInterfaceSetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											   const list<INTERFACE_CTL> *pFailedList);

//配置获取的回调
/*@pList: 配置参数的链表（具体格式参照协议）*/
typedef void (WINAPI *RtuConfigGetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											const list<CONFIG_ITEM> *pList);

//配置设置的回调
/*@pFailedList: 返回设置失败的链表（具体格式参照协议）*/
typedef void (WINAPI *RtuConfigSetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											const list<CONFIG_ITEM> *pFailedList);

//gps重启的回调
typedef void (WINAPI *RtuGpsRebootCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult);

//接口状态主动上报的回调: @pList 接口状态链表（具体格式参照协议）
typedef void (WINAPI *RtuInterfaceReport)(const void *pThiz, const u32 devAddr, const list<INTERFACE_RDV> *pList);

//接口报警主动上报的回调: @pList 接口报警链表（具体格式参照协议）
typedef void (WINAPI *RtuInterfaceAlarm)(const void *pThiz, const u32 devAddr, const list<INTERFACE_ALARM> *pList);

//短信报警主动上报的回调: @strAlarm 报警内容
typedef void (WINAPI *RtuSmsAlarm)(const void *pThiz, const u32 devAddr, const CString &strAlarm);
//=================================================================================================================================
extern "C"
{
	//启动服务器：@Port 端口号;@fun 上下线回调函数; @pThiz 回调对象;@handle1 接口状态主动上报回调函数;@handle2 接口状态报警回调函数;@handle3 短信报警回调函数 ;
	//返回值>0表示调用成功，否则失败
	s32 WINAPI Rtu_StartServer(u16 Port, RtuLogonCallBack fun, void *pThiz, RtuInterfaceReport handle1=0, RtuInterfaceAlarm handle2=0, RtuSmsAlarm handle3=0);
	
	//停止服务器
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_StopServer();

	//设置超时参数（单位 秒）：@PackTimeOut 通信包超时时间;@ConnectTimeOut 心跳超时时间;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_SetServerParam(u16 PackTimeOut, u16 ConnectTimeOut);

	//获取接口状态：@devAddr 设备地址;@fun 回调函数;@pThiz 回调对象;@RequestID 通信包标识号;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_InterfaceGet(u32 devAddr, RtuInterfaceGetCallBack fun, void *pThiz, u32 &RequestID);

	//设置接口状态：@devAddr 设备地址;@fun 回调函数;@pThiz 回调对象;@RequestID 通信包标识号;@pList 要设置的接口状态列表;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_InterfaceSet(u32 devAddr, RtuInterfaceSetCallBack fun, void *pThiz, u32 &RequestID, const list<INTERFACE_CTL> *pList);

	//获取配置参数：@devAddr 设备地址;@fun 回调函数;@pThiz 回调对象;@RequestID 通信包标识号;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_ConfigGet(u32 devAddr, RtuConfigGetCallBack fun, void *pThiz, u32 &RequestID);

	//设置接口状态：@devAddr 设备地址;@fun 回调函数;@pThiz 回调对象;@RequestID 通信包标识号;@pList 要设置的配置参数列表;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_ConfigSet(u32 devAddr, RtuConfigSetCallBack fun, void *pThiz, u32 &RequestID, const list<CONFIG_ITEM> *pList);

	//Gps重启：@devAddr 设备地址;@fun 回调函数;@pThiz 回调对象;@RequestID 通信包标识号;
	//返回值>=0表示调用成功，否则失败
	s32 WINAPI Rtu_GpsReboot(u32 devAddr, RtuGpsRebootCallBack fun, void *pThiz, u32 &RequestID);
};

#endif
