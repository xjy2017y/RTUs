#pragma once


// CMyDialog �Ի���

class CMyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDialog)

public:
	CMyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDialog();

// �Ի�������
	enum { IDD = IDD_RTUCONTROLLER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
