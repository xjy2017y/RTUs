
// TestMfcDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#include "RtuApi/RtuApi.h"
#pragma comment(lib, "./RtuApi/RtuApi.lib")
#include "testmyplayerctrl1.h"

// CTestMfcDlg 对话框
class CTestMfcDlg : public CDialog
{
// 构造
public:
	CTestMfcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

