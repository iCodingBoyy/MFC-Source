// Cinfo.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC机试一.h"
#include "MFC机试一Dlg.h"
#include "Cinfo.h"
#include "afxdialogex.h"


// Cinfo 对话框

IMPLEMENT_DYNAMIC(Cinfo, CDialog)

Cinfo::Cinfo(CWnd* pParent /*=NULL*/)
	: CDialog(Cinfo::IDD, pParent)
	, m_Radio(0)
	, C_name(_T(""))
	, C_class(_T(""))
	, C_age(_T(""))
	, C_year(_T(""))
	, C_month(_T(""))
	, C_day(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Cinfo::~Cinfo()
{
}

void Cinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_LIST1, m_Grid);
	DDX_Text(pDX, IDC_EDIT1, C_name);
	DDX_Text(pDX, IDC_EDIT2, C_class);
	DDX_Text(pDX, IDC_EDIT3, C_age);
	DDX_CBString(pDX, IDC_COMBO1, C_month);
	DDX_CBString(pDX, IDC_COMBO2, C_day);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_CBString(pDX, IDC_COMBO3, C_year);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_EDIT1, name);
	DDX_Control(pDX, IDC_EDIT2, Cclass);
	DDX_Control(pDX, IDC_EDIT3, age);
}


BEGIN_MESSAGE_MAP(Cinfo, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &Cinfo::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Cinfo::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BtnAdd, &Cinfo::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BtnDel, &Cinfo::OnBnClickedBtndel)
	ON_BN_CLICKED(IDC_BtnClear, &Cinfo::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_Btnquit, &Cinfo::OnBnClickedBtnquit)
END_MESSAGE_MAP()


BOOL Cinfo::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	SetIcon(m_hIcon, FALSE);

	// 设置小图标
	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1);
	Radiobutton->SetCheck(1);
	m_Radio = 1;

	m_Grid.SetBkColor(RGB(193,187,191));
	//m_Grid.SetTextBkColor(RGB(24,34,45));
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB	//扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT				//允许整行选中
		|LVS_EX_HEADERDRAGDROP				//允许整列拖动
		|LVS_EX_ONECLICKACTIVATE			//单击选中项
		|LVS_EX_GRIDLINES);					//画出网格线
	//设置表头
	m_Grid.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,100,0); //设置姓名列
	m_Grid.InsertColumn(1,_T("班级"),LVCFMT_LEFT,100,1); //设置列
	m_Grid.InsertColumn(2,_T("性别"),LVCFMT_LEFT,100,2); //设置列
	m_Grid.InsertColumn(3,_T("年龄"),LVCFMT_LEFT,100,3); //设置列
	m_Grid.InsertColumn(4,_T("生日"),LVCFMT_LEFT,120,4); //设置列
	m_Grid.InsertColumn(5,_T("爱好"),LVCFMT_LEFT,120,5); //设置列
	// TODO:  在此添加额外的初始化

	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(1000);
	m_ToolTip.SetMaxTipWidth(300);
	m_ToolTip.AddTool(GetDlgItem(IDC_LIST1),_T(""));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT1),_T("请输入姓名"));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT2),_T("请输入班级"));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT3),_T("请输入年龄"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO3),_T("请选择年"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO1),_T("请选择月"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO2),_T("请选择日"));
	m_ToolTip.AddTool(GetDlgItem(IDC_STATIC),_T("图像"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


HCURSOR Cinfo::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cinfo::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio=1;
}


void Cinfo::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Radio=2;
}

void Cinfo::OnBnClickedBtnadd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (C_name=="")
	{
		MessageBox(_T("请输入姓名"),_T("提醒"),MB_OK|MB_ICONERROR);
		return;
	}//if
	else 
	{
		if (C_class=="")
		{
			MessageBox(_T("请输入班级"),_T("提醒"),MB_OK|MB_ICONERROR);
			return;
		}//if
		else
		{
			if (C_age=="")
			{
				MessageBox(_T("请输入年龄"),_T("提醒"),MB_OK|MB_ICONERROR);
				return;
			}//if
			else
			{
				if (C_year==""||C_month==""||C_day=="")
				{
					MessageBox(_T("请选择生日"),_T("提醒"),MB_OK|MB_ICONERROR);
					return;
				}//if
				else
				{
					int count = m_Grid.GetItemCount();
					for (int i=0;i<count;i++)
					{
						if (m_Grid.GetItemText(i,0) == C_name)
						{		
							MessageBox(_T("姓名已存在，请重新输入"));
							return;
						}//if
					}//for

					m_Grid.InsertItem(count,_T(""));//插入空白行
					m_Grid.SetItemText(count,0,C_name);//插入姓名

					m_Grid.SetItemText(count,1,C_class);//插入班级
					m_Grid.SetItemText(count,3,C_age);//插入年龄

					CString birthday;
					birthday = C_year+"/"+C_month+"/"+C_day;
					m_Grid.SetItemText(count,4,birthday);//插入生日

					//插入性别
					CString str1;
					CButton *Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1+m_Radio-1);
					Radiobutton->GetWindowText(str1);
					m_Grid.SetItemText(count,2,str1);
					//MessageBox(str1);

					//插入爱好
					CString favourate;
					CButton *pBtn;
					favourate = _T("");
					for (int i=0;i<=2;i++)
					{
						CString temp;
						pBtn = (CButton*)GetDlgItem(IDC_CHECK1+i);	//获取check复选框指针
						if (pBtn->GetCheck())		//判断该复选框是否被选中
						{
							pBtn->GetWindowText(temp);
							favourate+=temp + _T("/");		//追加内容，并换行显示

						}//if
					}//for
					m_Grid.SetItemText(count,5,favourate);
				}//else
			}//else

		}//else
		
	}//else
	name.SetWindowText(_T(""));
	//Cclass.SetWindowText(_T(""));
	//age.SetWindowText(_T(""));
}


void Cinfo::OnBnClickedBtndel()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret = MessageBox(_T("确定删除？"),_T("警告"),MB_YESNO|MB_ICONWARNING);
	if(IDYES==ret)
	{
		int pos  = m_Grid.GetSelectionMark();
		m_Grid.DeleteItem(pos);
	}
}


void Cinfo::OnBnClickedBtnclear()
{
	// TODO: 在此添加控件通知处理程序代码
	int ret = MessageBox(_T("清空之后不可恢复，请谨慎操作！"),_T("警告"),MB_YESNO|MB_ICONWARNING);
	if(IDYES==ret)
	{
		m_Grid.DeleteAllItems();
	}
}
BOOL Cinfo::PreTranslateMessage(MSG* pMsg)
{

	if (NULL != m_ToolTip)
	{
		m_ToolTip.RelayEvent(pMsg);	
		m_ToolTip.UpdateTipText(_T("编辑框控件"),GetDlgItem(IDC_LIST1));
	}

	return CDialog::PreTranslateMessage(pMsg);

}

void Cinfo::OnBnClickedBtnquit()
{
	// TODO: 在此添加控件通知处理程序代码
	//Cinfo::ShowWindow(SW_HIDE);
	//CDialog::ShowWindow(SW_SHOW);
	Cinfo::OnCancel();
}
