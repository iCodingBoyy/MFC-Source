// MFC_test_01.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h��
#endif

#include "resource.h"		// ������


// CMFC_test_01App:
// �йش����ʵ�֣������ MFC_test_01.cpp
//

class CMFC_test_01App : public CWinApp
{
public:
	CMFC_test_01App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_test_01App theApp;
