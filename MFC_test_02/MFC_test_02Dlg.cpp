
// MFC_test_02Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_test_02.h"
#include "MFC_test_02Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC_test_02Dlg 对话框




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


// CMFC_test_02Dlg 消息处理程序

BOOL CMFC_test_02Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// 初始化组合框控件
	m_combo.InsertString(0,_T("十年生死两茫茫，"));
	m_combo.AddString(_T("不思量，自难忘。"));
	m_combo.AddString(_T("千里孤魂，何处话凄凉？"));
	m_combo.AddString(_T("夜来幽梦忽还乡，"));
	m_combo.AddString(_T("正梳妆，"));
	m_combo.InsertString(4,_T("小轩窗，"));
	m_combo.AddString(_T("相顾无言，唯有泪千行。"));
	m_combo.AddString(_T("明月夜，短松冈。"));
	UINT nCount = m_combo.GetCount();
	m_combo.DeleteString(nCount-1);
	m_combo.SetCurSel(6);

	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1);
	Radiobutton->SetCheck(1);
	m_Radio = 1;



	m_list.AddString(_T("青山横北郭，白水绕东城。"));
	m_list.AddString(_T("此地一为别，孤蓬万里征。"));
	m_list.AddString(_T("浮云游子意，落日故人情。"));
	m_list.AddString(_T("挥手自兹去，萧萧班马鸣。"));


	m_chklist.SetCheckStyle(BS_AUTOCHECKBOX);
	m_chklist.AddString(_T("浏览文件"));
	m_chklist.AddString(_T("操作数据库"));
	m_chklist.AddString(_T("前台操作"));
	m_chklist.AddString(_T("后台管理"));

	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_test_02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
		MessageBox(_T("不能插入空数据！"));
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
	// TODO: 在此添加控件通知处理程序代码
	UINT temp;
	temp = m_combo.GetCurSel();
	int ret=MessageBox(_T("确定删除？删除后不可恢复1"),_T("警告"),MB_OKCANCEL|MB_ICONWARNING);
	if (IDOK==ret)
	{
		m_combo.DeleteString(temp);
	}
	m_combo.SetCurSel(m_combo.GetCount()-1);
}


void CMFC_test_02Dlg::Btnclickok()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1 + m_Radio - 1);
	Radiobutton->GetWindowText(str);
	MessageBox(str);

}


void CMFC_test_02Dlg::Radio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 1;
}


void CMFC_test_02Dlg::Radio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 2;
}


void CMFC_test_02Dlg::Radio3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 3;
}


void CMFC_test_02Dlg::Radio4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio = 4;
}


void CMFC_test_02Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);	
	UINT uCount = m_list.GetCount();
	CString csStr;
	m_editlist.GetWindowText(csStr);
	if (csStr=="")
	{
		MessageBox(_T("不能插入空数据！"));
	}//if
	else
	{
		if (m_Num>uCount+1)
		{
			MessageBox(_T("行号大于当前总行数，请重新输入行号！"));
		}//if
		else
		{
			for (UINT i=0;i<uCount;i++)
			{

				m_list.GetText(i,csStr);
				if (m_Text == csStr)
				{		
					MessageBox(_T("数据存在，请重新输入"));
					return;
				}//if
			}//for

			m_list.InsertString(m_Num-1,m_Text);
		}//else
		
	}//else
	
}


void CMFC_test_02Dlg::btnclickok()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	int i=m_chklist.GetCurSel();
	if(i<0)return;
	if(m_chklist.GetCheck(i)<1)
		m_chklist.SetCheck(i,1);
	else
		m_chklist.SetCheck(i,0);
}


void CMFC_test_02Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret=MessageBox(_T("确定删除？删除后不可恢复1"),_T("警告"),MB_OKCANCEL|MB_ICONWARNING);
	if (IDOK==ret)
	{
		m_list.DeleteString(m_list.GetCurSel());
	}
	

}
