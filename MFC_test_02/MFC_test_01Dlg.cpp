// MFC_test_01Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_test_01.h"
#include "MFC_test_01Dlg.h"
#include ".\mfc_test_01dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMFC_test_01Dlg 对话框



CMFC_test_01Dlg::CMFC_test_01Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFC_test_01Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_test_01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, MyEdit1);
	DDX_Control(pDX, IDC_EDIT2, MyEdit2);
	DDX_Control(pDX, IDC_CHECK1, check1);
}

BEGIN_MESSAGE_MAP(CMFC_test_01Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC_test_01Dlg 消息处理程序

BOOL CMFC_test_01Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	CButton* pBtnCheck = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtnCheck->SetCheck(TRUE);//设置复选框为选中状态
	pBtnCheck->EnableWindow(FALSE);
	pBtnCheck = (CButton*)GetDlgItem(IDC_CHECK2);
	pBtnCheck->SetCheck(TRUE);
	pBtnCheck->EnableWindow(FALSE);		//设置复选框为不可用状态
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CMFC_test_01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_test_01Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CMFC_test_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC_test_01Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str,temp;
	str = "";
	CButton* pBtn = (CButton*)GetDlgItem(IDC_EDIT1);
	//pBtn->EnableWindow(TRUE);
	pBtn->GetWindowText(temp);
	if (temp=="")
	{
		MessageBox("学号不能为空！","提示",MB_OK|MB_ICONWARNING);
	}
	else
	{
		
		//TCHAR nstring[256];
		//strcpy(nstring, temp);
		//int i=atoi(nstring);
		//TCHAR strtemp[256];
		//wsprintf(strtemp,"%i",i);
		//if (strcmp(nstring,strtemp)!=0)
		//{
			//MessageBox("学号只能为数字！","提示",MB_OK|MB_ICONWARNING);
		//}//if
		//else
		//{
			str +="学号: " +temp + "\r";

			pBtn = (CButton*)GetDlgItem(IDC_EDIT2);
			//pBtn->EnableWindow(TRUE);
			pBtn->GetWindowText(temp);
			if (temp=="")
			{
				MessageBox("姓名不能为空！","提示",MB_OK|MB_ICONWARNING);
			}//if
			else
			{
				str +="姓名: " +temp + "\n\n必修课程：\n";
				for (int i=0;i<=1;i++)
				{
					pBtn = (CButton*)GetDlgItem(IDC_CHECK1 + i);	//获取check复选框指针
					//pBtnCheck->EnableWindow(TRUE);
					if ( pBtn->GetCheck())		//判断该复选框是否被选中
					{
						pBtn->GetWindowText(temp);
						str += temp + " ";		//追加内容，并换行显示

					}//if
				}//for
				str += "\n\n选修课程：\n";
				for (int i=2;i<=7;i++)
				{
					pBtn = (CButton*)GetDlgItem(IDC_CHECK1 + i);	//获取check复选框指针
					//pBtnCheck->EnableWindow(TRUE);
					if ( pBtn->GetCheck())		//判断该复选框是否被选中
					{
						pBtn->GetWindowText(temp);
						str += temp + " ";		//追加内容，并换行显示

					}//if
				}//for
				int ret = MessageBox("确定输入？","提示",MB_OKCANCEL|MB_ICONQUESTION);
				if (ret == IDOK)
				{
					
					MessageBox(str,"选课信息",MB_OK|MB_ICONMASK);
					OnCancel();
					
				}//if
				
			}//else

		//}//else
		

	}//else
	
	
}//CMFC_test_01Dlg

void CMFC_test_01Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFC_test_01Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}
