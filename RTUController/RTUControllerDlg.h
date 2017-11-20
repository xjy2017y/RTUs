
// RTUControllerDlg.h : 头文件
//

#pragma once


// CRTUControllerDlg 对话框
class CRTUControllerDlg : public CDialogEx
{
// 构造
public:
	CRTUControllerDlg(CWnd* pParent = NULL);	// 标准构造函数
	CWinThread* pThread;
	bool isOpen;
	SOCKET sockConn;

// 对话框数据
	enum { IDD = IDD_RTUCONTROLLER_DIALOG };

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	int m_port;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedfinishthreadbutton();
	afx_msg void OnEnChangeEdit3();
	CString m_input;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton5();
};
