
// MFC_test_02Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_test_02.h"
#include "MFC_test_02Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_test_02Dlg �Ի���




CMFC_test_02Dlg::CMFC_test_02Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_test_02Dlg::IDD, pParent)
{
	m_Num = 1;
	m_Text = _T("");
	m_hIcon = AfxGetApp()->LoadIcon(IDB_PNG1);
}

void CMFC_test_02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_EDIT1, m_string);
	DDX_Text(pDX, IDC_EDIT3, m_Num);
	DDX_Text(pDX, IDC_EDIT4, m_Text);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_CHKLIST, m_chklist);
	DDX_Control(pDX, IDC_EDIT4, m_editlist);
}

BEGIN_MESSAGE_MAP(CMFC_test_02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_test_02Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_test_02Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_test_02Dlg::Btnclickok)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_test_02Dlg::Radio2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFC_test_02Dlg::Radio1)
	ON_BN_CLICKED(IDC_RADIO3, &CMFC_test_02Dlg::Radio3)
	ON_BN_CLICKED(IDC_RADIO4, &CMFC_test_02Dlg::Radio4)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_test_02Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_test_02Dlg::btnclickok)
	ON_LBN_DBLCLK(IDC_CHKLIST, &CMFC_test_02Dlg::dbclickok)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_test_02Dlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CMFC_test_02Dlg ��Ϣ�������

BOOL CMFC_test_02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// ��ʼ����Ͽ�ؼ�
	m_combo.InsertString(0,_T("ʮ��������ãã��"));
	m_combo.AddString(_T("��˼������������"));
	m_combo.AddString(_T("ǧ��»꣬�δ���������"));
	m_combo.AddString(_T("ҹ�����κ����磬"));
	m_combo.AddString(_T("����ױ��"));
	m_combo.InsertString(4,_T("С������"));
	m_combo.AddString(_T("������ԣ�Ψ����ǧ�С�"));
	m_combo.AddString(_T("����ҹ�����ɸԡ�"));
	UINT nCount = m_combo.GetCount();
	m_combo.DeleteString(nCount-1);
	m_combo.SetCurSel(6);

	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1);
	Radiobutton->SetCheck(1);
	m_Radio = 1;



	m_list.AddString(_T("��ɽ�ᱱ������ˮ�ƶ��ǡ�"));
	m_list.AddString(_T("�˵�һΪ�𣬹�����������"));
	m_list.AddString(_T("���������⣬���չ����顣"));
	m_list.AddString(_T("��������ȥ��������������"));


	m_chklist.SetCheckStyle(BS_AUTOCHECKBOX);
	m_chklist.AddString(_T("����ļ�"));
	m_chklist.AddString(_T("�������ݿ�"));
	m_chklist.AddString(_T("ǰ̨����"));
	m_chklist.AddString(_T("��̨����"));

	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_test_02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_test_02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_test_02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_test_02Dlg::OnBnClickedButton2()
{
	CString str;
	m_string.GetWindowText(str);
	if (str=="")
	{
		MessageBox(_T("���ܲ�������ݣ�"));
	}//if
	else
	{
			UINT temp=m_combo.GetCurSel();
			m_combo.InsertString(temp+1,str);
			m_combo.SetCurSel(temp+1);
			m_string.SetWindowText(_T(""));
	}

}


void CMFC_test_02Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UINT temp;
	temp = m_combo.GetCurSel();
	int ret=MessageBox(_T("ȷ��ɾ����ɾ���󲻿ɻָ�1"),_T("����"),MB_OKCANCEL|MB_ICONWARNING);
	if (IDOK==ret)
	{
		m_combo.DeleteString(temp);
	}
	m_combo.SetCurSel(m_combo.GetCount()-1);
}


void CMFC_test_02Dlg::Btnclickok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1 + m_Radio - 1);
	Radiobutton->GetWindowText(str);
	MessageBox(str);

}


void CMFC_test_02Dlg::Radio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 1;
}


void CMFC_test_02Dlg::Radio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 2;
}


void CMFC_test_02Dlg::Radio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 3;
}


void CMFC_test_02Dlg::Radio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio = 4;
}


void CMFC_test_02Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);	
	UINT uCount = m_list.GetCount();
	CString csStr;
	m_editlist.GetWindowText(csStr);
	if (csStr=="")
	{
		MessageBox(_T("���ܲ�������ݣ�"));
	}//if
	else
	{
		if (m_Num>uCount+1)
		{
			MessageBox(_T("�кŴ��ڵ�ǰ�������������������кţ�"));
		}//if
		else
		{
			for (UINT i=0;i<uCount;i++)
			{

				m_list.GetText(i,csStr);
				if (m_Text == csStr)
				{		
					MessageBox(_T("���ݴ��ڣ�����������"));
					return;
				}//if
			}//for

			m_list.InsertString(m_Num-1,m_Text);
		}//else
		
	}//else
	
}


void CMFC_test_02Dlg::btnclickok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int j=m_chklist.GetCurSel();
	for (int i=0;i<=j;i++)
	{
		if (m_chklist.GetCheck(i))
		{
			GetDlgItem(IDC_BUTTON5+i)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(IDC_BUTTON5+i)->EnableWindow(FALSE);
		}
	}
	/*if(m_chklist.GetCheck(0))
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(1))
		GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(2))
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	if(m_chklist.GetCheck(3))
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	else
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);*/
}


void CMFC_test_02Dlg::dbclickok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i=m_chklist.GetCurSel();
	if(i<0)return;
	if(m_chklist.GetCheck(i)<1)
		m_chklist.SetCheck(i,1);
	else
		m_chklist.SetCheck(i,0);
}


void CMFC_test_02Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret=MessageBox(_T("ȷ��ɾ����ɾ���󲻿ɻָ�1"),_T("����"),MB_OKCANCEL|MB_ICONWARNING);
	if (IDOK==ret)
	{
		m_list.DeleteString(m_list.GetCurSel());
	}
	

}
