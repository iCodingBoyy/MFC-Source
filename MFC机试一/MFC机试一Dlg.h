
// MFC����һDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC����һDlg �Ի���
class CMFC����һDlg : public CDialogEx
{
// ����
public:
	CMFC����һDlg(CWnd* pParent = NULL);	// ��׼���캯��
// �Ի�������
	enum { IDD = IDD_MFC_DIALOG };
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
	afx_msg void OnBnClickedBtnload();
	CImageList m_ImageList;	//ͼ���б�
	CBitmap bitmap;
	CListCtrl m_ListControl;
	afx_msg void clickcheck(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit CE_name;
	CEdit CE_mima;
	afx_msg void OnBnClickedButton1();
	CEdit C_name;
};
