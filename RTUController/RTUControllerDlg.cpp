
// RTUControllerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RTUController.h"
#include "RTUControllerDlg.h"
#include "afxdialogex.h"
#include <WinSock2.h>  
#pragma comment(lib, "ws2_32.lib")  


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	CWinThread* pThread;
	bool isopen;

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRTUControllerDlg �Ի���




CRTUControllerDlg::CRTUControllerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRTUControllerDlg::IDD, pParent)
	, m_port(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRTUControllerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_port);
}

BEGIN_MESSAGE_MAP(CRTUControllerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRTUControllerDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CRTUControllerDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CRTUControllerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRTUControllerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(finishThreadButton, &CRTUControllerDlg::OnBnClickedfinishthreadbutton)
END_MESSAGE_MAP()


// CRTUControllerDlg ��Ϣ�������

BOOL CRTUControllerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRTUControllerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRTUControllerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRTUControllerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRTUControllerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CRTUControllerDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRTUControllerDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("���óɹ���"));
	UpdateData(TRUE);
}

UINT ThreadFun(LPVOID pParam){  //�߳�Ҫ���õĺ���
	
	struct fd_set rfds;
	struct timeval timeout = { 0, 1000 };
	WSADATA wsaData;		//����ṹ�������洢 ��WSAStartup�������ú󷵻ص� Windows Sockets���ݡ�
  
	CRTUControllerDlg* thiz  = (CRTUControllerDlg*)pParam;	
	int port = thiz->m_port;
	CString msg;
	msg.Format(_T("��ʼ����:%d"),port);
	MessageBox(NULL,msg, _T("thread func"),MB_OK);
	char buf[] = {0x01,0x03,0x00,0x02,0x75,0xc5};   
	for(int i=0;i<6;i++){
		printf("%02x\t",(unsigned char)buf[i]);
	}
	printf("\n");
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)		//makeword��ʹ�õ�socket�汾��  �˱�ʾ����2.2�汾��ִ�гɹ�����0
    {  
        printf("Failed to load Winsock");  
        return 0;  
    }  

	thiz->SetDlgItemTextW(IDC_EDIT2,_T("��ʼ����..\r\n"));  //ȡ������׷��
    
    //�������ڼ������׽���  
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);		//TCP UDPЭ��
	
    SOCKADDR_IN addrSrv;		
    addrSrv.sin_family = AF_INET;		  
    addrSrv.sin_port = htons(port); //1024���ϵĶ˿ں�  
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);		//����ʹ�õ����Լ���ip������htonlת��Ϊ�����룬���Ҫ���ð�����ip�Ļ���inet_addr("132.241.5.10");
    int retVal = bind(sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));			//�׽�����˿ڹ���
    if(retVal == SOCKET_ERROR){  
		closesocket(sockSrv);
		thiz->MessageBox(_T("��ʧ��"));
        return 0;  
    }  
  
    if(listen(sockSrv,10) ==SOCKET_ERROR){					//���ü������׽���
        printf("Listen failed:%d", WSAGetLastError());  
        return 0;  
    }  
  
    SOCKADDR_IN addrClient;  
    int len = sizeof(SOCKADDR);  
	thiz->isOpen = true;
	while(thiz->isOpen)  
    {  
        //�ȴ��ͻ������� 

		FD_ZERO(&rfds);  /* ��ռ��� */
        FD_SET(sockSrv, &rfds);  /* ��fp��ӵ����ϣ������FD_ISSET��FD_SETû�б�Ȼ��ϵ����������Ӽ�� */
		switch (select(0, &rfds, NULL, NULL, &timeout)) //selectʹ�� 
		{
		case 0:
			continue;
		case SOCKET_ERROR:
			break;
		default:
			SOCKET sockConn = accept(sockSrv, (SOCKADDR *) &addrClient, &len);			//������֪���������пͻ��˷���Ϣ����������accept�����
			if(sockConn == SOCKET_ERROR){  
				printf("Accept failed:%d", WSAGetLastError());  
				break;  
			}
			//printf("Accept client IP:[%s]\n", inet_ntoa(addrClient.sin_addr));			//��addrClient���ó���Ϣ
			CString lastStr;
			thiz->GetDlgItemTextW(IDC_EDIT2,lastStr);
			lastStr = lastStr + _T("\r\n");
			char *p = inet_ntoa(addrClient.sin_addr);
			CString ipmsg(p);
			ipmsg = lastStr + _T("Accept client IP:") +ipmsg;
			thiz->SetDlgItemTextW(IDC_EDIT2,ipmsg);
			//��������  
			int iSend = send(sockConn, buf, sizeof(buf) , 0);  
			if(iSend == SOCKET_ERROR){  
				printf("send failed");  
				break;  
			} 
  
			char recvBuf[100];  
			//memset(recvBuf, 0, sizeof(recvBuf));		//λ��ȫ��0
	//      //��������  
			if(recv(sockConn, recvBuf, sizeof(recvBuf), 0)!= -1){
				CString str2(recvBuf);
				thiz->SetDlgItemTextW(IDC_EDIT2,str2);
			}
			//printf("%s\n", recvBuf);  
			/*for(int i = 0;i<100;i++){
				printf("%02x\t",(unsigned char)recvBuf[i]);
			}*/
			closesocket(sockConn); 
			}
    }  
	closesocket(sockSrv);
	thiz->MessageBox(_T("������������"));
	return 0;
};

void CRTUControllerDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pThread = AfxBeginThread(ThreadFun, this);  //����Ǵ���һ���̲߳�ִ����,��������ĺ�������һ���Ի���.
}


void CRTUControllerDlg::OnBnClickedfinishthreadbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	isOpen = false;
}
