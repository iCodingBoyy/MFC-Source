
// MFC_test_02Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_test_02Dlg �Ի���
class CMFC_test_02Dlg : public CDialogEx
{
// ����
public:
	CMFC_test_02Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_TEST_02_DIALOG };
	int	m_Radio;
	UINT m_Num;
	CString m_Text;
	CCheckListBox m_chklist;
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
	CComboBox m_combo;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CEdit m_cout;
	CEdit m_string;
	afx_msg void Btnclickok();
	afx_msg void Radio1();
	afx_msg void Radio2();
	afx_msg void Radio3();
	afx_msg void Radio4();
	afx_msg void OnBnClickedButton4();
	CListBox m_list;
	afx_msg void btnclickok();
	afx_msg void dbclickok();
	afx_msg void OnBnClickedButton10();
	CEdit m_editlist;
};
