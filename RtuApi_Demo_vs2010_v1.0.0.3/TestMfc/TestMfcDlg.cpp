
// TestMfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestMfc.h"
#include "TestMfcDlg.h"
#include "winsock.h"   
#include "mysql.h"   
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "testmyplayerctrl1.h"
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestMfcDlg 对话框


MYSQL m_sqlCon;  

CTestMfcDlg::CTestMfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMfcDlg::IDD, pParent)
	, test_result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_TESTMYPLAYERCTRL1, m_player);
	DDX_Text(pDX, IDC_EDIT1, test_result);
}

BEGIN_MESSAGE_MAP(CTestMfcDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestMfcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestMfcDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestMfcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestMfcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestMfcDlg::OnBnClickedButton3)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON4, &CTestMfcDlg::OnBnClickedButton4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CTestMfcDlg::OnBnClickedButton5)
END_MESSAGE_MAP()

// CTestMfcDlg 消息处理程序

BOOL CTestMfcDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

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

void CTestMfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestMfcDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestMfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int g_devAddr=0;

void CTestMfcDlg::RtuLogonCB(const void *param, const u32 devAddr, const u8 online, const LogonInfo info)
{
	CString msg;
	if (online)
	{
		g_devAddr = devAddr;		//记录地址
		msg.Format(_T("%d 上线"), devAddr);
	}
	else
	{
		msg.Format(_T("%d 下线"), devAddr);
		g_devAddr = 0;
	}
	CTestMfcDlg *pthis = (CTestMfcDlg*)param;
	pthis->MessageBox(msg);
}
void CTestMfcDlg::RtuInterfaceGetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
									const list<INTERFACE_RDV> *pList)
{
	if (nResult >= 0)
	{
		/*list<INTERFACE_RDV>::const_iterator it=pList->begin();
		for (;it!=pList->end();++it)
		{
			INTERFACE_RDV info = *it;

			int type = info.type;
			int number = info.number;
		}*/
	list<INTERFACE_RDV>::const_iterator it = pList->begin();
	for(int i = 0;i < 16;i++){
		++it;
	}
	CString msg,strTime;
	FILE *file;
	file = fopen("log.txt","a");
	CTestMfcDlg *pthis = (CTestMfcDlg*)pThiz;
	SYSTEMTIME st;
	GetLocalTime(&st);
	strTime.Format(_T("%2d:%2d:%2d\r\n"),st.wHour,st.wMinute,st.wSecond);
	fprintf(file,"%2d:%2d:%2d\r\n",st.wHour,st.wMinute,st.wSecond);
	pthis->test_result = strTime;
	int num[10];
	for(int i = 1;it!=pList->end();++it,++i){
		msg.Format(_T("第%d路:number:%d  common:%d  "),i,it->number,it->valueUnit.common);
		num[i] =it->valueUnit.common.val;
		msg += "\r\n";
		fprintf(file,"第%d路:number:%d  common:%d  \r\n",i,it->number,it->valueUnit.common);
		pthis->test_result = pthis->test_result + msg;
	}
	CString xmsg;
	xmsg.Format(_T("insert into rtu_table(rtu1,rtu2,rtu3,rtu4,rtu5,rtu6,rtu7,rtu8,time,date) values(%d,%d,%d,%d,%d,%d,%d,%d,curtime(),curdate())"),num[1],num[2],num[3],num[4],num[5],num[6],num[7],num[8]);
	char *xx =(LPSTR)(LPCTSTR)xmsg;
	int ret = mysql_query(&m_sqlCon,xx);
	if(ret){
		CString msg;
		msg.Format(_T("error:%s"),mysql_error(&m_sqlCon));
		pthis->MessageBox(msg);
	     }
	pthis->SetDlgItemTextA(IDC_EDIT1,pthis->test_result);
	fclose(file);
	}
}
void CTestMfcDlg::RtuInterfaceSetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
									const list<INTERFACE_CTL> *pFailedList)
{

}
void CTestMfcDlg::RtuConfigGetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
								 const list<CONFIG_ITEM> *pList)
{
	if (nResult >= 0)
	{
		list<CONFIG_ITEM>::const_iterator it=pList->begin();
		for (;it!=pList->end();++it)
		{
			CONFIG_ITEM info = *it;
			int type = info.type;
			int id = info.id;
		}
	}
}
void CTestMfcDlg::RtuConfigSetCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult,
								 const list<CONFIG_ITEM> *pFailedList)
{

}
void CTestMfcDlg::RtuGpsRebootCB(const void *pThiz, const u32 devAddr, const u32 nRequestID, const s32 nResult)
{

}
void CTestMfcDlg::RtuInterfaceReportCB(const void *pThiz, const u32 devAddr, const list<INTERFACE_RDV> *pList)
{
	list<INTERFACE_RDV>::const_iterator it=pList->begin();
	for (;it!=pList->end();++it)
	{
		INTERFACE_RDV info = *it;
	}
}
void CTestMfcDlg::RtuInterfaceAlarmCB(const void *pThiz, const u32 devAddr, const list<INTERFACE_ALARM> *pList)
{
	list<INTERFACE_ALARM>::const_iterator it=pList->begin();
	for (;it!=pList->end();++it)
	{
		INTERFACE_ALARM info = *it;
	}

}
void CTestMfcDlg::RtuSmsAlarmCB(const void *pThiz, const u32 devAddr, const CString &strAlarm)
{

}

void CTestMfcDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CComVariant varUser("888888");
	CComVariant varPasswd("888888");
	CComVariant varMode(0L);
	CComVariant varReconn(0L);

	//CString strUrl = "rtsp://27.154.56.174:10081/9f8b2af0-3c52-499d-9b0e-40aca5ce7500/c1v2.3gp";

	//GetDlgItemText(IDC_URL1, strUrl);
	//CComBSTR bstrUrl(static_cast<LPCTSTR>(strUrl));
	//CComVariant varUrl(static_cast<BSTR>(bstrUrl));
	//m_player.Plays(varUrl, varUser, varPasswd, varMode, varReconn);
	//return;
	// TODO: 在此添加控件通知处理程序代码
	int ret = Rtu_StartServer(30002, CTestMfcDlg::RtuLogonCB, this, CTestMfcDlg::RtuInterfaceReportCB, CTestMfcDlg::RtuInterfaceAlarmCB, 
		CTestMfcDlg::RtuSmsAlarmCB);

	//如果不需要主动上报
	//int ret = Rtu_StartServer(7878, CTestMfcDlg::RtuLogonCB, this);

	if (ret > 0)
	{
		//success
		MessageBox(_T("start ok"));
	}
	else
	{
		//failed
		MessageBox(_T("start failed"));
	}
	ret = Rtu_SetServerParam(30,120);		//设置超时参数
}

void CTestMfcDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	Rtu_StopServer();
	OnCancel();
}

void CTestMfcDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_devAddr == 0)
	{
		return;
	}
	u32 nRequestID;
	int ret = Rtu_ConfigGet(g_devAddr, RtuConfigGetCB, this, nRequestID);
	if (ret >= 0)
	{
		MessageBox(_T("GetConfig ok"));
	}
}

void CTestMfcDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_devAddr == 0)		//如果地址为0
	{
		return;
	}
	u32 nRequestID;
	int ret = Rtu_InterfaceGet(g_devAddr, RtuInterfaceGetCB, this, nRequestID);
	SetTimer(1,30000,NULL);
	
	if (ret >= 0)
	{
		MessageBox(_T("GetInterface ok"));
	}
}

void CTestMfcDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (g_devAddr == 0)
	{
		return;
	}
	u32 nRequestID;
	list<CONFIG_ITEM> config;
	CONFIG_ITEM item;
	item.id = 113;
	item.type = STRINGTYPE;
	item.strVal = _T("设置的对对对订单1111333ddd；");
	config.push_back(item);
	int ret = Rtu_ConfigSet(g_devAddr,RtuConfigSetCB,this,nRequestID,&config);
	if (ret >= 0)
	{
		MessageBox(_T("SetInterface ok"));
	}
}

void CTestMfcDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}

void CTestMfcDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//s32 WINAPI Rtu_InterfaceSet(u32 devAddr, RtuInterfaceSetCallBack fun, void *pThiz, u32 &RequestID, const list<INTERFACE_CTL> *pList);
	if (g_devAddr == 0)
	{
		return;
	}
	list<INTERFACE_CTL> config;
	//*********控制继电器***************************
	//需要参照 《RTU主进程和Peripth控制进程通信协议v2.2.doc》
	//控制继电器 第1路   闭合
	INTERFACE_CTL relay1;
	relay1.type = 0x02;  // 继电器 类型 02 
	relay1.number = 0x00;  // 00继电器第一路 (下标读取外设是从1开始，修改是从0开始 )
	relay1.val = 0x02;		    // 0x01 断开，00x02闭合继电器
	config.push_back(relay1);
	//控制继电器 第2路 闭合
	INTERFACE_CTL relay2;
	relay2.type = 0x02;
	relay2.number = 0x01;  // 01继电器第二路
	relay2.val = 0x02;         // 0x01 断开，00x02闭合继电器
	config.push_back(relay2);
	//控制继电器 第3路 断开
	INTERFACE_CTL relay3;
	relay3.type = 0x02;
	relay3.number = 0x02;  // 02继电器第三路
	relay3.val = 0x01;         // 0x01 断开，00x02闭合继电器
	config.push_back(relay3);
	//控制继电器 第4路 断开
	INTERFACE_CTL relay4;
	relay4.type = 0x02;
	relay4.number = 0x03; // 03继电器第四路
	relay4.val = 0x01;        // 0x01 断开，00x02闭合继电器
	config.push_back(relay4);
	//************************************

	//*********设置数字输出***************************
	//需要参照 《RTU主进程和Peripth控制进程通信协议v2.2.doc》
	//设置数字输出 第1路  高电平
	INTERFACE_CTL digitout1;
	digitout1.type = 0x01;  // 继电器 数字输出 02 
	digitout1.number = 0x00;  // 00数字输出第一路 (下标读取外设是从1开始，修改是从0开始 )
	digitout1.val = 0x01;		    //1-高电平,2-低电平,3-方波
	config.push_back(digitout1);
	//设置数字输出 第2路 高电平
	INTERFACE_CTL digitout2;
	digitout2.type = 0x01;
	digitout2.number = 0x01;  // 01数字输出第二路
	digitout2.val = 0x01;         // 1-高电平,2-低电平,3-方波
	config.push_back(digitout2);
	//设置数字输出 第3路 低电平
	INTERFACE_CTL digitout3;
	digitout3.type = 0x01;
	digitout3.number = 0x02;  // 02数字输出第三路
	digitout3.val = 0x02;         // 1-高电平,2-低电平,3-方波
	config.push_back(digitout3);
	//设置数字输出 第4路 低电平
	INTERFACE_CTL digitout4;
	digitout4.type = 0x01;
	digitout4.number = 0x03; // 03数字输出第四路
	digitout4.val = 0x02;        // 1-高电平,2-低电平,3-方波
	config.push_back(digitout4);
	//************************************

	u32 nRequestID;

	int ret = Rtu_InterfaceSet(g_devAddr,RtuInterfaceSetCB,this,nRequestID,&config);
}


void CTestMfcDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (g_devAddr == 0)
	{
		return;
	}
	u32 nRequestID;
	int ret = Rtu_InterfaceGet(g_devAddr, RtuInterfaceGetCB, this, nRequestID);
	CDialog::OnTimer(nIDEvent);
}


void CTestMfcDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	 mysql_init(&m_sqlCon);    
	 // localhost:服务器 root/123456为账号密码 managesystemdb为数据库名 3306为端口    
	 if(!mysql_real_connect(&m_sqlCon,"localhost","root","123456","rtu_test",3306,NULL,0))    
	 {    
		 AfxMessageBox(_T("访问数据库失败!"));  
		/* CString e= mysql_error(&m_sqlCon);//需要将项目属性中字符集修改为“使用多字节字符集”或“未设置”  
		 MessageBox(e);  */
		 return;  
	 }else{    
		 AfxMessageBox(_T("连接成功!"));  
		 mysql_query(&m_sqlCon,"SET NAMES 'gb2312'");//解决从数据库中读取数据后汉字乱码显示的问题   
	}
}
