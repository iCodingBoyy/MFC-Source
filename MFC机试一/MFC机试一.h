
// MFC����һ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC����һApp:
// �йش����ʵ�֣������ MFC����һ.cpp
//

class CMFC����һApp : public CWinApp
{
public:
	CMFC����һApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC����һApp theApp;