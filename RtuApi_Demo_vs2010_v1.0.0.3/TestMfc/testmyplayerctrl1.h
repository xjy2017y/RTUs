#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CTestmyplayerctrl1 包装类

class CTestmyplayerctrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CTestmyplayerctrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x36578F76, 0x8A5A, 0x46BE, { 0xB8, 0x50, 0x9B, 0x34, 0x43, 0x97, 0x2B, 0xA9 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 属性
public:


// 操作
public:

// _DTestMyPlayer

// Functions
//

	void Play(VARIANT bstrUrl, VARIANT bstrUser, VARIANT bstrPasswd, VARIANT varMode, VARIANT varAutoReconnect)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &bstrUrl, &bstrUser, &bstrPasswd, &varMode, &varAutoReconnect);
	}
	void TestPlay()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Plays(VARIANT bstrUrl, VARIANT bstrUser, VARIANT bstrPasswd, VARIANT varMode, VARIANT varAutoReconnect)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &bstrUrl, &bstrUser, &bstrPasswd, &varMode, &varAutoReconnect);
	}

// Properties
//



};
