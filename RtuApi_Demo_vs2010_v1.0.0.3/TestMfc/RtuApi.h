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

//�豸�����߻ص�
/*@pThiz: �ص�����*/
/*@devAddr: �豸��ַ*/
/*@bLogon: 1������ 0������*/
/*@info: ע����Ϣ*/
typedef void (WINAPI *RtuLogonCallBack) (const void *pThiz, const u32 devAddr,const u8 bLogon, const LogonInfo info);

//�ӿ�״̬��ȡ�Ļص�
/*@pThiz: �ص�����*/
/*@devAddr: �豸��ַ*/
/*@nRequestID: ͨ�Ű���ʶ��*/
/*@nResult: >=0���ʾ�ɹ�������ʧ��*/
/*@pList: �ӿ�״̬���������ʽ����Э�飩*/
typedef void (WINAPI *RtuInterfaceGetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											   const list<INTERFACE_RDV> *pList);

//�ӿ����õĻص�
/*@pFailedList: ��������ʧ�ܵ����������ʽ����Э�飩*/
typedef void (WINAPI *RtuInterfaceSetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											   const list<INTERFACE_CTL> *pFailedList);

//���û�ȡ�Ļص�
/*@pList: ���ò��������������ʽ����Э�飩*/
typedef void (WINAPI *RtuConfigGetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											const list<CONFIG_ITEM> *pList);

//�������õĻص�
/*@pFailedList: ��������ʧ�ܵ����������ʽ����Э�飩*/
typedef void (WINAPI *RtuConfigSetCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
											const list<CONFIG_ITEM> *pFailedList);

//gps�����Ļص�
typedef void (WINAPI *RtuGpsRebootCallBack)(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult);

//�ӿ�״̬�����ϱ��Ļص�: @pList �ӿ�״̬���������ʽ����Э�飩
typedef void (WINAPI *RtuInterfaceReport)(const void *pThiz, const u32 devAddr, const list<INTERFACE_RDV> *pList);

//�ӿڱ��������ϱ��Ļص�: @pList �ӿڱ������������ʽ����Э�飩
typedef void (WINAPI *RtuInterfaceAlarm)(const void *pThiz, const u32 devAddr, const list<INTERFACE_ALARM> *pList);

//���ű��������ϱ��Ļص�: @strAlarm ��������
typedef void (WINAPI *RtuSmsAlarm)(const void *pThiz, const u32 devAddr, const CString &strAlarm);
//=================================================================================================================================
extern "C"
{
	//������������@Port �˿ں�;@fun �����߻ص�����; @pThiz �ص�����;@handle1 �ӿ�״̬�����ϱ��ص�����;@handle2 �ӿ�״̬�����ص�����;@handle3 ���ű����ص����� ;
	//����ֵ>0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_StartServer(u16 Port, RtuLogonCallBack fun, void *pThiz, RtuInterfaceReport handle1=0, RtuInterfaceAlarm handle2=0, RtuSmsAlarm handle3=0);
	
	//ֹͣ������
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_StopServer();

	//���ó�ʱ��������λ �룩��@PackTimeOut ͨ�Ű���ʱʱ��;@ConnectTimeOut ������ʱʱ��;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_SetServerParam(u16 PackTimeOut, u16 ConnectTimeOut);

	//��ȡ�ӿ�״̬��@devAddr �豸��ַ;@fun �ص�����;@pThiz �ص�����;@RequestID ͨ�Ű���ʶ��;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_InterfaceGet(u32 devAddr, RtuInterfaceGetCallBack fun, void *pThiz, u32 &RequestID);

	//���ýӿ�״̬��@devAddr �豸��ַ;@fun �ص�����;@pThiz �ص�����;@RequestID ͨ�Ű���ʶ��;@pList Ҫ���õĽӿ�״̬�б�;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_InterfaceSet(u32 devAddr, RtuInterfaceSetCallBack fun, void *pThiz, u32 &RequestID, const list<INTERFACE_CTL> *pList);

	//��ȡ���ò�����@devAddr �豸��ַ;@fun �ص�����;@pThiz �ص�����;@RequestID ͨ�Ű���ʶ��;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_ConfigGet(u32 devAddr, RtuConfigGetCallBack fun, void *pThiz, u32 &RequestID);

	//���ýӿ�״̬��@devAddr �豸��ַ;@fun �ص�����;@pThiz �ص�����;@RequestID ͨ�Ű���ʶ��;@pList Ҫ���õ����ò����б�;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_ConfigSet(u32 devAddr, RtuConfigSetCallBack fun, void *pThiz, u32 &RequestID, const list<CONFIG_ITEM> *pList);

	//Gps������@devAddr �豸��ַ;@fun �ص�����;@pThiz �ص�����;@RequestID ͨ�Ű���ʶ��;
	//����ֵ>=0��ʾ���óɹ�������ʧ��
	s32 WINAPI Rtu_GpsReboot(u32 devAddr, RtuGpsRebootCallBack fun, void *pThiz, u32 &RequestID);
};

#endif
