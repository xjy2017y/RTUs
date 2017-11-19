
// TestMfcDlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTestMfcDlg �Ի���


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

// CTestMfcDlg ��Ϣ�������

BOOL CTestMfcDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestMfcDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		g_devAddr = devAddr;		//��¼��ַ
		msg.Format(_T("%d ����"), devAddr);
	}
	else
	{
		msg.Format(_T("%d ����"), devAddr);
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
		msg.Format(_T("��%d·:number:%d  common:%d  "),i,it->number,it->valueUnit.common);
		num[i] =it->valueUnit.common.val;
		msg += "\r\n";
		fprintf(file,"��%d·:number:%d  common:%d  \r\n",i,it->number,it->valueUnit.common);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret = Rtu_StartServer(30002, CTestMfcDlg::RtuLogonCB, this, CTestMfcDlg::RtuInterfaceReportCB, CTestMfcDlg::RtuInterfaceAlarmCB, 
		CTestMfcDlg::RtuSmsAlarmCB);

	//�������Ҫ�����ϱ�
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
	ret = Rtu_SetServerParam(30,120);		//���ó�ʱ����
}

void CTestMfcDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Rtu_StopServer();
	OnCancel();
}

void CTestMfcDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (g_devAddr == 0)		//�����ַΪ0
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (g_devAddr == 0)
	{
		return;
	}
	u32 nRequestID;
	list<CONFIG_ITEM> config;
	CONFIG_ITEM item;
	item.id = 113;
	item.type = STRINGTYPE;
	item.strVal = _T("���õĶԶԶԶ���1111333ddd��");
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

	// TODO: �ڴ˴������Ϣ����������
}

void CTestMfcDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//s32 WINAPI Rtu_InterfaceSet(u32 devAddr, RtuInterfaceSetCallBack fun, void *pThiz, u32 &RequestID, const list<INTERFACE_CTL> *pList);
	if (g_devAddr == 0)
	{
		return;
	}
	list<INTERFACE_CTL> config;
	//*********���Ƽ̵���***************************
	//��Ҫ���� ��RTU�����̺�Peripth���ƽ���ͨ��Э��v2.2.doc��
	//���Ƽ̵��� ��1·   �պ�
	INTERFACE_CTL relay1;
	relay1.type = 0x02;  // �̵��� ���� 02 
	relay1.number = 0x00;  // 00�̵�����һ· (�±��ȡ�����Ǵ�1��ʼ���޸��Ǵ�0��ʼ )
	relay1.val = 0x02;		    // 0x01 �Ͽ���00x02�պϼ̵���
	config.push_back(relay1);
	//���Ƽ̵��� ��2· �պ�
	INTERFACE_CTL relay2;
	relay2.type = 0x02;
	relay2.number = 0x01;  // 01�̵����ڶ�·
	relay2.val = 0x02;         // 0x01 �Ͽ���00x02�պϼ̵���
	config.push_back(relay2);
	//���Ƽ̵��� ��3· �Ͽ�
	INTERFACE_CTL relay3;
	relay3.type = 0x02;
	relay3.number = 0x02;  // 02�̵�������·
	relay3.val = 0x01;         // 0x01 �Ͽ���00x02�պϼ̵���
	config.push_back(relay3);
	//���Ƽ̵��� ��4· �Ͽ�
	INTERFACE_CTL relay4;
	relay4.type = 0x02;
	relay4.number = 0x03; // 03�̵�������·
	relay4.val = 0x01;        // 0x01 �Ͽ���00x02�պϼ̵���
	config.push_back(relay4);
	//************************************

	//*********�����������***************************
	//��Ҫ���� ��RTU�����̺�Peripth���ƽ���ͨ��Э��v2.2.doc��
	//����������� ��1·  �ߵ�ƽ
	INTERFACE_CTL digitout1;
	digitout1.type = 0x01;  // �̵��� ������� 02 
	digitout1.number = 0x00;  // 00���������һ· (�±��ȡ�����Ǵ�1��ʼ���޸��Ǵ�0��ʼ )
	digitout1.val = 0x01;		    //1-�ߵ�ƽ,2-�͵�ƽ,3-����
	config.push_back(digitout1);
	//����������� ��2· �ߵ�ƽ
	INTERFACE_CTL digitout2;
	digitout2.type = 0x01;
	digitout2.number = 0x01;  // 01��������ڶ�·
	digitout2.val = 0x01;         // 1-�ߵ�ƽ,2-�͵�ƽ,3-����
	config.push_back(digitout2);
	//����������� ��3· �͵�ƽ
	INTERFACE_CTL digitout3;
	digitout3.type = 0x01;
	digitout3.number = 0x02;  // 02�����������·
	digitout3.val = 0x02;         // 1-�ߵ�ƽ,2-�͵�ƽ,3-����
	config.push_back(digitout3);
	//����������� ��4· �͵�ƽ
	INTERFACE_CTL digitout4;
	digitout4.type = 0x01;
	digitout4.number = 0x03; // 03�����������·
	digitout4.val = 0x02;        // 1-�ߵ�ƽ,2-�͵�ƽ,3-����
	config.push_back(digitout4);
	//************************************

	u32 nRequestID;

	int ret = Rtu_InterfaceSet(g_devAddr,RtuInterfaceSetCB,this,nRequestID,&config);
}


void CTestMfcDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 mysql_init(&m_sqlCon);    
	 // localhost:������ root/123456Ϊ�˺����� managesystemdbΪ���ݿ��� 3306Ϊ�˿�    
	 if(!mysql_real_connect(&m_sqlCon,"localhost","root","123456","rtu_test",3306,NULL,0))    
	 {    
		 AfxMessageBox(_T("�������ݿ�ʧ��!"));  
		/* CString e= mysql_error(&m_sqlCon);//��Ҫ����Ŀ�������ַ����޸�Ϊ��ʹ�ö��ֽ��ַ�������δ���á�  
		 MessageBox(e);  */
		 return;  
	 }else{    
		 AfxMessageBox(_T("���ӳɹ�!"));  
		 mysql_query(&m_sqlCon,"SET NAMES 'gb2312'");//��������ݿ��ж�ȡ���ݺ���������ʾ������   
	}
}
