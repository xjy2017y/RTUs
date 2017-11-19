
// TestMfcDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "RtuApi/RtuApi.h"
#pragma comment(lib, "./RtuApi/RtuApi.lib")
#include "testmyplayerctrl1.h"

// CTestMfcDlg �Ի���
class CTestMfcDlg : public CDialog
{
// ����
public:
	CTestMfcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	static void WINAPI RtuLogonCB(const void *pThiz, const u32 devAddr,const u8 bLogon, const LogonInfo info);
	static void WINAPI RtuInterfaceGetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
		const list<INTERFACE_RDV> *pList);
	static void WINAPI RtuInterfaceSetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
		const list<INTERFACE_CTL> *pFailedList);
	static void WINAPI RtuConfigGetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
		const list<CONFIG_ITEM> *pList);
	static void WINAPI RtuConfigSetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
		const list<CONFIG_ITEM> *pFailedList);
	static void WINAPI RtuGpsRebootCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult);
	static void WINAPI RtuInterfaceReportCB(const void *pThiz, const u32 devAddr, const list<INTERFACE_RDV> *pList);
	static void WINAPI RtuInterfaceAlarmCB(const void *pThiz, const u32 devAddr, const list<INTERFACE_ALARM> *pList);
	static void WINAPI RtuSmsAlarmCB(const void *pThiz, const u32 devAddr, const CString &strAlarm);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CTestmyplayerctrl1 m_player;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit1();
	CString test_result;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton5();
};

