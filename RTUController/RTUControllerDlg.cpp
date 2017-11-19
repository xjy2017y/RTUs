
// RTUControllerDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	CWinThread* pThread;
	bool isopen;

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CRTUControllerDlg 对话框




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


// CRTUControllerDlg 消息处理程序

BOOL CRTUControllerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRTUControllerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRTUControllerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRTUControllerDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CRTUControllerDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CRTUControllerDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("设置成功！"));
	UpdateData(TRUE);
}

UINT ThreadFun(LPVOID pParam){  //线程要调用的函数
	
	struct fd_set rfds;
	struct timeval timeout = { 0, 1000 };
	WSADATA wsaData;		//这个结构被用来存储 被WSAStartup函数调用后返回的 Windows Sockets数据。
  
	CRTUControllerDlg* thiz  = (CRTUControllerDlg*)pParam;	
	int port = thiz->m_port;
	CString msg;
	msg.Format(_T("开始监听:%d"),port);
	MessageBox(NULL,msg, _T("thread func"),MB_OK);
	char buf[] = {0x01,0x03,0x00,0x02,0x75,0xc5};   
	for(int i=0;i<6;i++){
		printf("%02x\t",(unsigned char)buf[i]);
	}
	printf("\n");
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)		//makeword是使用的socket版本号  此表示的是2.2版本，执行成功返回0
    {  
        printf("Failed to load Winsock");  
        return 0;  
    }  

	thiz->SetDlgItemTextW(IDC_EDIT2,_T("开始监听..\r\n"));  //取出来在追加
    
    //创建用于监听的套接字  
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);		//TCP UDP协议
	
    SOCKADDR_IN addrSrv;		
    addrSrv.sin_family = AF_INET;		  
    addrSrv.sin_port = htons(port); //1024以上的端口号  
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);		//这里使用的是自己的ip，所以htonl转换为网络码，如果要设置绑定其他ip的话用inet_addr("132.241.5.10");
    int retVal = bind(sockSrv, (LPSOCKADDR)&addrSrv, sizeof(SOCKADDR_IN));			//套接字与端口关联
    if(retVal == SOCKET_ERROR){  
		closesocket(sockSrv);
		thiz->MessageBox(_T("绑定失败"));
        return 0;  
    }  
  
    if(listen(sockSrv,10) ==SOCKET_ERROR){					//设置监听的套接字
        printf("Listen failed:%d", WSAGetLastError());  
        return 0;  
    }  
  
    SOCKADDR_IN addrClient;  
    int len = sizeof(SOCKADDR);  
	thiz->isOpen = true;
	while(thiz->isOpen)  
    {  
        //等待客户请求到来 

		FD_ZERO(&rfds);  /* 清空集合 */
        FD_SET(sockSrv, &rfds);  /* 将fp添加到集合，后面的FD_ISSET和FD_SET没有必然关系，这里是添加检测 */
		switch (select(0, &rfds, NULL, NULL, &timeout)) //select使用 
		{
		case 0:
			continue;
		case SOCKET_ERROR:
			break;
		default:
			SOCKET sockConn = accept(sockSrv, (SOCKADDR *) &addrClient, &len);			//阻塞，知道监听到有客户端发消息过来，调用accept后继续
			if(sockConn == SOCKET_ERROR){  
				printf("Accept failed:%d", WSAGetLastError());  
				break;  
			}
			//printf("Accept client IP:[%s]\n", inet_ntoa(addrClient.sin_addr));			//从addrClient中拿出消息
			CString lastStr;
			thiz->GetDlgItemTextW(IDC_EDIT2,lastStr);
			lastStr = lastStr + _T("\r\n");
			char *p = inet_ntoa(addrClient.sin_addr);
			CString ipmsg(p);
			ipmsg = lastStr + _T("Accept client IP:") +ipmsg;
			thiz->SetDlgItemTextW(IDC_EDIT2,ipmsg);
			//发送数据  
			int iSend = send(sockConn, buf, sizeof(buf) , 0);  
			if(iSend == SOCKET_ERROR){  
				printf("send failed");  
				break;  
			} 
  
			char recvBuf[100];  
			//memset(recvBuf, 0, sizeof(recvBuf));		//位置全置0
	//      //接收数据  
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
	thiz->MessageBox(_T("结束监听！！"));
	return 0;
};

void CRTUControllerDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	pThread = AfxBeginThread(ThreadFun, this);  //这就是创建一个线程并执行了,调用上面的函数弹出一个对话框.
}


void CRTUControllerDlg::OnBnClickedfinishthreadbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	isOpen = false;
}
