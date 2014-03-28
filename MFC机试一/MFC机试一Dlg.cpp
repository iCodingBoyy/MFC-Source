
// MFC机试一Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC机试一.h"
#include "MFC机试一Dlg.h"
#include "afxdialogex.h"
#include "Cinfo.h"

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


// CMFC机试一Dlg 对话框




CMFC机试一Dlg::CMFC机试一Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC机试一Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC机试一Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListControl);
	DDX_Control(pDX, IDC_EDIT1, CE_name);
	DDX_Control(pDX, IDC_EDIT2, CE_mima);
	DDX_Control(pDX, IDC_EDIT3, C_name);
}

BEGIN_MESSAGE_MAP(CMFC机试一Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnLoad, &CMFC机试一Dlg::OnBnClickedBtnload)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFC机试一Dlg::clickcheck)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC机试一Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC机试一Dlg 消息处理程序

BOOL CMFC机试一Dlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码
	CE_name.SetWindowText(_T("管理员"));

	m_ImageList.Create(48,48,ILC_COLOR32|ILC_MASK,1,1);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	//初始化列表视图控件
	m_ListControl.SetImageList(&m_ImageList,LVSIL_NORMAL);  //把图像列表和列表视图控件进行关联，
	//LVSIL_SMALL：表示图像显示类型，这个必须和列表视图控件的样式保持一致
	m_ListControl.InsertItem(0,_T("管理员"),0);
	m_ListControl.InsertItem(1,_T("学生"),1);
	m_ListControl.InsertItem(2,_T("教师"),2);
	m_ListControl.InsertItem(3,_T("职员"),3);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC机试一Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC机试一Dlg::OnPaint()
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
HCURSOR CMFC机试一Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


Cinfo *ptr=NULL;
void CMFC机试一Dlg::OnBnClickedBtnload()
{
	// TODO: 在此添加控件通知处理程序代码
	CString sercet=_T("123");
	CString name=_T("abc");
	CString temp,temp1;
	CE_mima.GetWindowText(temp);
	C_name.GetWindowText(temp1);
	if (temp1==name)
	{
		if (temp==sercet)
		{
			if (NULL==ptr)
			{
				ptr = new Cinfo;
				ptr->Create(IDD_DIALOG1);
			}
			//CMFC机试一Dlg::ShowWindow(SW_HIDE);
			ptr->ShowWindow(SW_SHOW); 
		}
		else
		{
			MessageBox(_T("密码错误！"),_T("警告"),MB_OK|MB_ICONWARNING);
			CE_mima.SetWindowText(_T(""));
		}
	}
	else
	{
		MessageBox(_T("账号错误！"),_T("警告"),MB_OK|MB_ICONWARNING);
		C_name.SetWindowText(_T(""));
	}
	
	
}


void CMFC机试一Dlg::clickcheck(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int pos  = m_ListControl.GetSelectionMark();
	str = m_ListControl.GetItemText(pos,0);
	CE_name.SetWindowText(str);
	*pResult = 0;
}


void CMFC机试一Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CMFC机试一Dlg:OnCancel();
}
