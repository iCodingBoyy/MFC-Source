
// MFC_test_02.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_test_02App:
// �йش����ʵ�֣������ MFC_test_02.cpp
//

class CMFC_test_02App : public CWinApp
{
public:
	CMFC_test_02App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_test_02App theApp;