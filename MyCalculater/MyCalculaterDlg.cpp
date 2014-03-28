
// MyCalculaterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyCalculater.h"
#include "MyCalculaterDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include <stdlib.h>
using namespace std;
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


// CMyCalculaterDlg 对话框




CMyCalculaterDlg::CMyCalculaterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyCalculaterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyCalculatorDlg)
	m_display = _T("0.0");
	m_first = 0.0;
	m_second= 0.0;
	m_operator=_T("+");
	m_coff  = 1.0;

	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyCalculaterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_dispaly);
}

BEGIN_MESSAGE_MAP(CMyCalculaterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CMyCalculaterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyCalculaterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyCalculaterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyCalculaterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyCalculaterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyCalculaterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyCalculaterDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyCalculaterDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyCalculaterDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMyCalculaterDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON14, &CMyCalculaterDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CMyCalculaterDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CMyCalculaterDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON12, &CMyCalculaterDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON16, &CMyCalculaterDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON11, &CMyCalculaterDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON17, &CMyCalculaterDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON20, &CMyCalculaterDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON22, &CMyCalculaterDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON18, &CMyCalculaterDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMyCalculaterDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON21, &CMyCalculaterDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON25, &CMyCalculaterDlg::OnBnClickedButton25)
END_MESSAGE_MAP()


// CMyCalculaterDlg 消息处理程序

BOOL CMyCalculaterDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyCalculaterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyCalculaterDlg::OnPaint()
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
HCURSOR CMyCalculaterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyCalculaterDlg::OnBnClickedButton2()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 8;
	else  
	{
		m_second = m_second + 8*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton1()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 7;
	else  
	{
		m_second = m_second + 7*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);


}


void CMyCalculaterDlg::OnBnClickedButton3()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 9;
	else  
	{
		m_second = m_second + 9*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	 
	CMyCalculaterDlg::Calculate(); 
	m_operator="+";

}


void CMyCalculaterDlg::OnBnClickedButton5()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 4;
	else  
	{
		m_second = m_second + 4*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton6()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 5;
	else  
	{m_second = m_second + 5*m_coff; 
	m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton7()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 6;
	else  
	{
		m_second = m_second + 6*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);
}


void CMyCalculaterDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyCalculaterDlg::Calculate(); 
	m_operator="-";

}


void CMyCalculaterDlg::OnBnClickedButton9()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 1;
	else  
	{
		m_second = m_second + 1*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton10()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 2;
	else  
	{
		m_second = m_second + 2*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton14()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 03;
	else  
	{
		m_second = m_second + 3*m_coff; 
	    m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CMyCalculaterDlg::Calculate(); 
	m_operator="*";

}


void CMyCalculaterDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	m_first=0.0;
	m_second=0.0;
	m_coff = 1.0;
	m_dispaly.SetWindowText(_T("0.0"));
}


void CMyCalculaterDlg::OnBnClickedButton12()
{
	if( m_coff == 1.0)
		m_second = m_second*10 + 0;
	else  
	{
		m_second = m_second + 0*m_coff; 
		m_coff *= 0.1;
	}

	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码

	//CMyCalculaterDlg::Calculate(); 
	m_second=0.0;
	m_coff = 1.0;
	m_operator="";
	UpdateDisplay(m_first);

}


void CMyCalculaterDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CMyCalculaterDlg::Calculate(); 
	m_operator="/";
	

}
void CMyCalculaterDlg::Calculate(void)
{
	
	switch(m_operator.GetAt(0))
	{
	case '+':
		m_first +=m_second;
		break;
	case '-':
		m_first -=m_second;
		break;
	case '*':
		m_first *=m_second;
		break;
	case '/':
		if(fabs(m_second)<= 0.000001)
		{ 
			//m_display = "除数不能为零";
			//MessageBox(m_display);
		   //UpdateDisplay(m_first);
		   UpdateData(false);
		  return;
		}
		m_first /=m_second;
		//UpdateDisplay(m_first);
		break;
	}
	m_second=0.0;
	m_coff = 1.0;
	m_operator="";
	UpdateDisplay(m_first);
}
void CMyCalculaterDlg::UpdateDisplay(double lVal)
{
	m_display.Format( _T("%f"),lVal);
	int i=m_display.GetLength();

	//格式化输出，将输出结果后的零全部截去
	while(m_display.GetAt(i-1)=='0')
	{
		m_display.Delete(i-1,1);
		i--;
	}
	UpdateData(false); //更新显示编辑框变量m_display
	m_dispaly.SetWindowText(m_display);
}		



void CMyCalculaterDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second = sqrt(m_second);
	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	m_second = -m_second;	 
	UpdateDisplay(m_second);

}


void CMyCalculaterDlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	m_first=0.0;
	m_second=0.0;
	//m_operator = "+";
	m_coff = 1.0;
	UpdateDisplay(0.0);

}


void CMyCalculaterDlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	int first =(int)m_first;
	int second = (int)m_second;
	first %= second;
	UpdateDisplay(first);
}


void CMyCalculaterDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CMyCalculaterDlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	m_coff	= 0.1;
}


void CMyCalculaterDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	CButton* pBtnCheck = (CButton*)GetDlgItem(IDC_EDIT1);
	pBtnCheck->EnableWindow(FALSE);

}
