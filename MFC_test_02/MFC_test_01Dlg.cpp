// MFC_test_01Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_test_01.h"
#include "MFC_test_01Dlg.h"
#include ".\mfc_test_01dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMFC_test_01Dlg �Ի���



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


// CMFC_test_01Dlg ��Ϣ�������

BOOL CMFC_test_01Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CButton* pBtnCheck = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtnCheck->SetCheck(TRUE);//���ø�ѡ��Ϊѡ��״̬
	pBtnCheck->EnableWindow(FALSE);
	pBtnCheck = (CButton*)GetDlgItem(IDC_CHECK2);
	pBtnCheck->SetCheck(TRUE);
	pBtnCheck->EnableWindow(FALSE);		//���ø�ѡ��Ϊ������״̬
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_test_01Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CMFC_test_01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFC_test_01Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str,temp;
	str = "";
	CButton* pBtn = (CButton*)GetDlgItem(IDC_EDIT1);
	//pBtn->EnableWindow(TRUE);
	pBtn->GetWindowText(temp);
	if (temp=="")
	{
		MessageBox("ѧ�Ų���Ϊ�գ�","��ʾ",MB_OK|MB_ICONWARNING);
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
			//MessageBox("ѧ��ֻ��Ϊ���֣�","��ʾ",MB_OK|MB_ICONWARNING);
		//}//if
		//else
		//{
			str +="ѧ��: " +temp + "\r";

			pBtn = (CButton*)GetDlgItem(IDC_EDIT2);
			//pBtn->EnableWindow(TRUE);
			pBtn->GetWindowText(temp);
			if (temp=="")
			{
				MessageBox("��������Ϊ�գ�","��ʾ",MB_OK|MB_ICONWARNING);
			}//if
			else
			{
				str +="����: " +temp + "\n\n���޿γ̣�\n";
				for (int i=0;i<=1;i++)
				{
					pBtn = (CButton*)GetDlgItem(IDC_CHECK1 + i);	//��ȡcheck��ѡ��ָ��
					//pBtnCheck->EnableWindow(TRUE);
					if ( pBtn->GetCheck())		//�жϸø�ѡ���Ƿ�ѡ��
					{
						pBtn->GetWindowText(temp);
						str += temp + " ";		//׷�����ݣ���������ʾ

					}//if
				}//for
				str += "\n\nѡ�޿γ̣�\n";
				for (int i=2;i<=7;i++)
				{
					pBtn = (CButton*)GetDlgItem(IDC_CHECK1 + i);	//��ȡcheck��ѡ��ָ��
					//pBtnCheck->EnableWindow(TRUE);
					if ( pBtn->GetCheck())		//�жϸø�ѡ���Ƿ�ѡ��
					{
						pBtn->GetWindowText(temp);
						str += temp + " ";		//׷�����ݣ���������ʾ

					}//if
				}//for
				int ret = MessageBox("ȷ�����룿","��ʾ",MB_OKCANCEL|MB_ICONQUESTION);
				if (ret == IDOK)
				{
					
					MessageBox(str,"ѡ����Ϣ",MB_OK|MB_ICONMASK);
					OnCancel();
					
				}//if
				
			}//else

		//}//else
		

	}//else
	
	
}//CMFC_test_01Dlg

void CMFC_test_01Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CMFC_test_01Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnCancel();
}
