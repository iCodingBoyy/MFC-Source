// MFC_test_01Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_test_01Dlg �Ի���
class CMFC_test_01Dlg : public CDialog
{
// ����
public:
	CMFC_test_01Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_TEST_01_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit MyEdit1;
	CEdit MyEdit2;
	CButton check1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
};
