
// �߼��ؼ���ʹ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�߼��ؼ���ʹ��App:
// �йش����ʵ�֣������ �߼��ؼ���ʹ��.cpp
//

class C�߼��ؼ���ʹ��App : public CWinApp
{
public:
	C�߼��ؼ���ʹ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�߼��ؼ���ʹ��App theApp;