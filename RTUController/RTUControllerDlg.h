
// RTUControllerDlg.h : ͷ�ļ�
//

#pragma once


// CRTUControllerDlg �Ի���
class CRTUControllerDlg : public CDialogEx
{
// ����
public:
	CRTUControllerDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CWinThread* pThread;
	bool isOpen;
	SOCKET sockConn;

// �Ի�������
	enum { IDD = IDD_RTUCONTROLLER_DIALOG };

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
