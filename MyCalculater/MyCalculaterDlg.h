
// MyCalculaterDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMyCalculaterDlg �Ի���
class CMyCalculaterDlg : public CDialogEx
{
// ����
public:
	CMyCalculaterDlg(CWnd* pParent = NULL);	// ��׼���캯��
	double m_first;
	double m_second;
	double m_coff;
	CString m_operator;
	CString m_display;
	CButton* pBtn;
// �Ի�������
	enum { IDD = IDD_MYCALCULATER_DIALOG };
	void Calculate(void);
	void UpdateDisplay(double lVal);
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton11();
	CEdit m_dispaly;
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton25();
};
