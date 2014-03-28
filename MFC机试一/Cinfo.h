#pragma once
#include "afxwin.h"


// Cinfo �Ի���

class Cinfo : public CDialog
{
	DECLARE_DYNAMIC(Cinfo)

public:
	Cinfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cinfo();
// �Ի�������
	enum { IDD = IDD_DIALOG1 };
	CListCtrl m_Grid;
	CToolTipCtrl m_ToolTip;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_Radio;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CButton check1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtndel();
	afx_msg void OnBnClickedBtnclear();
	CString C_name;
	CString C_class;
	CString C_age;
	CString C_month;
	CString C_day;
	CComboBox m_combo1;
	CComboBox m_combo2;
	CString C_year;
	CComboBox m_combo3;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnquit();
	CEdit name;
	CEdit Cclass;
	CEdit age;
};
