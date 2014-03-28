
// MFC����һDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC����һ.h"
#include "MFC����һDlg.h"
#include "afxdialogex.h"
#include "Cinfo.h"

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


// CMFC����һDlg �Ի���




CMFC����һDlg::CMFC����һDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC����һDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC����һDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListControl);
	DDX_Control(pDX, IDC_EDIT1, CE_name);
	DDX_Control(pDX, IDC_EDIT2, CE_mima);
	DDX_Control(pDX, IDC_EDIT3, C_name);
}

BEGIN_MESSAGE_MAP(CMFC����һDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnLoad, &CMFC����һDlg::OnBnClickedBtnload)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFC����һDlg::clickcheck)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC����һDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFC����һDlg ��Ϣ�������

BOOL CMFC����һDlg::OnInitDialog()
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

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CE_name.SetWindowText(_T("����Ա"));

	m_ImageList.Create(48,48,ILC_COLOR32|ILC_MASK,1,1);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	//��ʼ���б���ͼ�ؼ�
	m_ListControl.SetImageList(&m_ImageList,LVSIL_NORMAL);  //��ͼ���б���б���ͼ�ؼ����й�����
	//LVSIL_SMALL����ʾͼ����ʾ���ͣ����������б���ͼ�ؼ�����ʽ����һ��
	m_ListControl.InsertItem(0,_T("����Ա"),0);
	m_ListControl.InsertItem(1,_T("ѧ��"),1);
	m_ListControl.InsertItem(2,_T("��ʦ"),2);
	m_ListControl.InsertItem(3,_T("ְԱ"),3);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC����һDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC����һDlg::OnPaint()
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
HCURSOR CMFC����һDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


Cinfo *ptr=NULL;
void CMFC����һDlg::OnBnClickedBtnload()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			//CMFC����һDlg::ShowWindow(SW_HIDE);
			ptr->ShowWindow(SW_SHOW); 
		}
		else
		{
			MessageBox(_T("�������"),_T("����"),MB_OK|MB_ICONWARNING);
			CE_mima.SetWindowText(_T(""));
		}
	}
	else
	{
		MessageBox(_T("�˺Ŵ���"),_T("����"),MB_OK|MB_ICONWARNING);
		C_name.SetWindowText(_T(""));
	}
	
	
}


void CMFC����һDlg::clickcheck(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	int pos  = m_ListControl.GetSelectionMark();
	str = m_ListControl.GetItemText(pos,0);
	CE_name.SetWindowText(str);
	*pResult = 0;
}


void CMFC����һDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CMFC����һDlg:OnCancel();
}
