#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "typedef.h"

#define	ERROR_NONE								0		//����
#define	ERROR_SERVER_TYPE_ONLY_EXIST			-1		//�÷��������Ѵ��ڲ�����Ψһ��
#define	ERROR_SERVER_TYPE_UNKNOWN				-2		//δ֪�ķ�������
#define	ERROR_SERVER_ID_EXIST					-3		//����ID�Ѵ���
#define	ERROR_SERVER_ID_NOEXIST					-4		//����ID������
#define	ERROR_SERVER_ID_ILLEGAL					-5		//�Ƿ�����ID
#define ERROR_SERVER_START_FAILED				-6		//��������ʧ��
#define	ERROR_MODULE_INFO_NOEXIST				-7		//�豸��Ϣ������
#define	ERROR_PARAM_UNIT_NUM_ILLEGAL			-8		//��Ч�Ĳ�����Ԫ��Ŀ
#define	ERROR_PARAM_UNIT_ILLEGAL				-9		//��Ч�Ĳ�����Ԫ
#define	ERROR_IP_IPSYMBOL_UNKNOWN				-10		//δ֪��IP���ʶ
#define	ERROR_IP_NPSYMBOL_UNKNOWN				-11		//δ֪��NP���ʶ
#define	ERROR_NP_LEN_ILLEGAL					-12		//�Ƿ���NP�㳤��
#define	ERROR_NP_APSYMBOL_UNKNOWN				-13		//δ֪��Ӧ�ò��ʶ
#define	ERROR_NP_CMD_UNKNOWN					-14		//δ֪��NP�������ʶ
#define	ERROR_TCP_RECV_DATA_DUMP				-15		//TCP�������ݶ���
#define	ERROR_CREATE_RECV_EVENT_FAILED			-16		//���������¼�ʧ��
#define	ERROR_CREATE_SEND_EVENT_FAILED			-17		//���������¼�ʧ��
#define	ERROR_CREATE_CALL_EVENT_FAILED			-18		//���������¼�ʧ��
#define	ERROR_CREATE_PACKAGE_FAILED				-19		//����ͨ�Ű�ʧ��
#define	ERROR_WAIT_ACK_TIMEOUT					-20		//�ȴ�Ӧ��ʱ
#define	ERROR_AP_DATA_LEN_ILLEGAL				-21		//Ӧ�ò����ݵ�Ԫ���ȴ���
#define	ERROR_AP_DATA_ILLEGAL					-22		//Ӧ�ò����ݵ�Ԫֵ����
#define	ERROR_ACK_PACK_IP_NPSYMBOL_UNKNOWN		-23		//δ֪��Ӧ����ӿڲ������ʶ
#define	ERROR_ACK_PACK_IP_NPSYMBOL_UNMATCH		-24		//Ӧ����ӿڲ������ʶ��ƥ��
#define	ERROR_ACK_PACK_NP_APSYMBOL_UNMATCH		-25		//Ӧ��������Ӧ�ñ�ʶ��ƥ��
#define	ERROR_ACK_PACK_NP_SUB_INDEX_ERROR		-26		//Ӧ��������ְ���Ŵ���
#define	ERROR_ACK_PACK_NP_MARK_UNKNOWN			-27		//δ֪��Ӧ�������㽻����ʶ
#define	ERROR_ACK_PACK_NP_MARK_ERROR			-28		//Ӧ�������㽻����ʶ����
#define	ERROR_ACK_PACK_AP_CMD_UNMATCH			-29		//Ӧ���Ӧ�ò������ʶ��ƥ��
#define	ERROR_AP_A_ACK_PART_ERROR				-30		//���ݲ�������
#define	ERROR_AP_A_ACK_CMD_ERROR				-31		//�����ʶ����
#define	ERROR_AP_A_ACK_LEN_ERROR				-32		//���ݳ��ȴ���
#define	ERROR_AP_B_ACK_OPERATE_ERROR			-33		//����ʧ��
#define	ERROR_AP_C_ACK_OPERATE_ERROR			-34		//����ʧ��
#define	ERROR_AP_D_ACK_OPERATE_ERROR			-35		//����ʧ��
#define	ERROR_AP_ACK_CRC_ERROR					-36		//Ӧ���CRCУ�����
#define	ERROR_AP_ACK_OTHER_ERROR				-37		//Ӧ�������δ֪����
#define	ERROR_ACK_PACK_AP_CTL_UNMATCH			-38		//Ӧ���Ӧ�ò���������ʶ��ƥ��
#define	ERROR_ACK_PACK_AP_INDEX_UNMATCH			-39		//Ӧ���Ӧ�ò�ؼ�������ʶ��ƥ��
#define	ERROR_ACK_PACK_AP_DATA_LEN_UNMATCH		-40		//Ӧ���Ӧ�ò����ݵ�Ԫ���Ȳ�ƥ��
#define	ERROR_DOT_INFO_NOEXIST					-41		//Ӧ���Ӧ�ò���������ʶ��ƥ��
#define	ERROR_COMM_PARAM_SERVER_TYPE			-42		//ͨ�Ų����쳣���������ʹ���
#define	ERROR_COMM_PARAM_SERIAL_PORT_NAME		-43		//ͨ�Ų����쳣�����ںŻ򴮿�������
#define ERROR_SCREEN_TYPE_UNKNOWN				-44		//δ֪��������
#define ERROR_WINDOW_COMPONENT_TYPE_UNKNOWN		-45		//δ֪�ĵ���ؼ�����
#define ERROR_COMPONENT_TYPE_AND_PARAM_UNMATCH	-46		//�ؼ�������ؼ�������ƥ��
#define ERROR_FILE_AND_COMPONENT_TYPE_UNMATCH	-47		//�ؼ��������ļ����Ͳ�ƥ��
#define ERROR_FILE_INFO_INVALID					-48		//�ļ���Ϣ��Ч
#define ERROR_PARAM_UNIT_NOEXIST				-49		//������Ԫ������
#define ERROR_API_GETDIBITS_ERROR				-50		//API����GetDIBits()ִ�д���
#define ERROR_COMPONENT_TYPE_INVALID			-51		//��Ч�Ŀؼ�����
#define	ERROR_AP_C_CMD_UNKNOWN					-52		//δ֪��Ӧ��C�������ʶ
#define	ERROR_ACK_PACK_AP_LEN_ILLEGAL			-53		//Ӧ���Ӧ�ò㳤�ȷǷ�
#define	ERROR_FIIE_PATH_OR_FILE_NAME_WRONG		-54		//�����ļ�·����������ļ�������

u32 WCharToMByte(CString CS_Src, u32 BufLen, u8 *pBuf);
//int MByteToWChar(LPCSTR lpcszStr, CString CS_Dest, DWORD dwSize);
void PrintCustomError(s32 ErrorSymbol, CString &CS_Error);