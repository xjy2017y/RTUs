
// RTUController.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRTUControllerApp:
// �йش����ʵ�֣������ RTUController.cpp
//

class CRTUControllerApp : public CWinApp
{
public:
	CRTUControllerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRTUControllerApp theApp;