
// MyCalculater.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyCalculaterApp:
// �йش����ʵ�֣������ MyCalculater.cpp
//

class CMyCalculaterApp : public CWinApp
{
public:
	CMyCalculaterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyCalculaterApp theApp;