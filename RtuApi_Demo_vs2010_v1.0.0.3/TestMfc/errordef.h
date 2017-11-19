#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "typedef.h"

#define	ERROR_NONE								0		//正常
#define	ERROR_SERVER_TYPE_ONLY_EXIST			-1		//该服务类型已存在并且是唯一的
#define	ERROR_SERVER_TYPE_UNKNOWN				-2		//未知的服务类型
#define	ERROR_SERVER_ID_EXIST					-3		//服务ID已存在
#define	ERROR_SERVER_ID_NOEXIST					-4		//服务ID不存在
#define	ERROR_SERVER_ID_ILLEGAL					-5		//非法服务ID
#define ERROR_SERVER_START_FAILED				-6		//启动服务失败
#define	ERROR_MODULE_INFO_NOEXIST				-7		//设备信息不存在
#define	ERROR_PARAM_UNIT_NUM_ILLEGAL			-8		//无效的参数单元数目
#define	ERROR_PARAM_UNIT_ILLEGAL				-9		//无效的参数单元
#define	ERROR_IP_IPSYMBOL_UNKNOWN				-10		//未知的IP层标识
#define	ERROR_IP_NPSYMBOL_UNKNOWN				-11		//未知的NP层标识
#define	ERROR_NP_LEN_ILLEGAL					-12		//非法的NP层长度
#define	ERROR_NP_APSYMBOL_UNKNOWN				-13		//未知的应用层标识
#define	ERROR_NP_CMD_UNKNOWN					-14		//未知的NP层命令标识
#define	ERROR_TCP_RECV_DATA_DUMP				-15		//TCP接收数据丢弃
#define	ERROR_CREATE_RECV_EVENT_FAILED			-16		//创建接收事件失败
#define	ERROR_CREATE_SEND_EVENT_FAILED			-17		//创建发送事件失败
#define	ERROR_CREATE_CALL_EVENT_FAILED			-18		//创建呼叫事件失败
#define	ERROR_CREATE_PACKAGE_FAILED				-19		//创建通信包失败
#define	ERROR_WAIT_ACK_TIMEOUT					-20		//等待应答超时
#define	ERROR_AP_DATA_LEN_ILLEGAL				-21		//应用层数据单元长度错误
#define	ERROR_AP_DATA_ILLEGAL					-22		//应用层数据单元值错误
#define	ERROR_ACK_PACK_IP_NPSYMBOL_UNKNOWN		-23		//未知的应答包接口层网络标识
#define	ERROR_ACK_PACK_IP_NPSYMBOL_UNMATCH		-24		//应答包接口层网络标识不匹配
#define	ERROR_ACK_PACK_NP_APSYMBOL_UNMATCH		-25		//应答包网络层应用标识不匹配
#define	ERROR_ACK_PACK_NP_SUB_INDEX_ERROR		-26		//应答包网络层分包序号错误
#define	ERROR_ACK_PACK_NP_MARK_UNKNOWN			-27		//未知的应答包网络层交互标识
#define	ERROR_ACK_PACK_NP_MARK_ERROR			-28		//应答包网络层交互标识错误
#define	ERROR_ACK_PACK_AP_CMD_UNMATCH			-29		//应答包应用层命令标识不匹配
#define	ERROR_AP_A_ACK_PART_ERROR				-30		//部份参数错误
#define	ERROR_AP_A_ACK_CMD_ERROR				-31		//命令标识错误
#define	ERROR_AP_A_ACK_LEN_ERROR				-32		//数据长度错误
#define	ERROR_AP_B_ACK_OPERATE_ERROR			-33		//操作失败
#define	ERROR_AP_C_ACK_OPERATE_ERROR			-34		//操作失败
#define	ERROR_AP_D_ACK_OPERATE_ERROR			-35		//操作失败
#define	ERROR_AP_ACK_CRC_ERROR					-36		//应答包CRC校验错误
#define	ERROR_AP_ACK_OTHER_ERROR				-37		//应答包其他未知错误
#define	ERROR_ACK_PACK_AP_CTL_UNMATCH			-38		//应答包应用层控制命令标识不匹配
#define	ERROR_ACK_PACK_AP_INDEX_UNMATCH			-39		//应答包应用层控件索引标识不匹配
#define	ERROR_ACK_PACK_AP_DATA_LEN_UNMATCH		-40		//应答包应用层数据单元长度不匹配
#define	ERROR_DOT_INFO_NOEXIST					-41		//应答包应用层控制命令标识不匹配
#define	ERROR_COMM_PARAM_SERVER_TYPE			-42		//通信参数异常：服务类型错误
#define	ERROR_COMM_PARAM_SERIAL_PORT_NAME		-43		//通信参数异常：串口号或串口名错误
#define ERROR_SCREEN_TYPE_UNKNOWN				-44		//未知的屏类型
#define ERROR_WINDOW_COMPONENT_TYPE_UNKNOWN		-45		//未知的点阵控件类型
#define ERROR_COMPONENT_TYPE_AND_PARAM_UNMATCH	-46		//控件类型与控件参数不匹配
#define ERROR_FILE_AND_COMPONENT_TYPE_UNMATCH	-47		//控件类型与文件类型不匹配
#define ERROR_FILE_INFO_INVALID					-48		//文件信息无效
#define ERROR_PARAM_UNIT_NOEXIST				-49		//参数单元不存在
#define ERROR_API_GETDIBITS_ERROR				-50		//API函数GetDIBits()执行错误
#define ERROR_COMPONENT_TYPE_INVALID			-51		//无效的控件类型
#define	ERROR_AP_C_CMD_UNKNOWN					-52		//未知的应用C层命令标识
#define	ERROR_ACK_PACK_AP_LEN_ILLEGAL			-53		//应答包应用层长度非法
#define	ERROR_FIIE_PATH_OR_FILE_NAME_WRONG		-54		//升级文件路径错误或者文件名错误

u32 WCharToMByte(CString CS_Src, u32 BufLen, u8 *pBuf);
//int MByteToWChar(LPCSTR lpcszStr, CString CS_Dest, DWORD dwSize);
void PrintCustomError(s32 ErrorSymbol, CString &CS_Error);