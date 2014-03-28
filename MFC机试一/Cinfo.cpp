// Cinfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC����һ.h"
#include "MFC����һDlg.h"
#include "Cinfo.h"
#include "afxdialogex.h"


// Cinfo �Ի���

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
	SetIcon(m_hIcon, FALSE);

	// ����Сͼ��
	CButton* Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1);
	Radiobutton->SetCheck(1);
	m_Radio = 1;

	m_Grid.SetBkColor(RGB(193,187,191));
	//m_Grid.SetTextBkColor(RGB(24,34,45));
	m_Grid.SetExtendedStyle(LVS_EX_FLATSB	//��ƽ�����ʾ������
		|LVS_EX_FULLROWSELECT				//��������ѡ��
		|LVS_EX_HEADERDRAGDROP				//���������϶�
		|LVS_EX_ONECLICKACTIVATE			//����ѡ����
		|LVS_EX_GRIDLINES);					//����������
	//���ñ�ͷ
	m_Grid.InsertColumn(0,_T("����"),LVCFMT_LEFT,100,0); //����������
	m_Grid.InsertColumn(1,_T("�༶"),LVCFMT_LEFT,100,1); //������
	m_Grid.InsertColumn(2,_T("�Ա�"),LVCFMT_LEFT,100,2); //������
	m_Grid.InsertColumn(3,_T("����"),LVCFMT_LEFT,100,3); //������
	m_Grid.InsertColumn(4,_T("����"),LVCFMT_LEFT,120,4); //������
	m_Grid.InsertColumn(5,_T("����"),LVCFMT_LEFT,120,5); //������
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(1000);
	m_ToolTip.SetMaxTipWidth(300);
	m_ToolTip.AddTool(GetDlgItem(IDC_LIST1),_T(""));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT1),_T("����������"));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT2),_T("������༶"));
	m_ToolTip.AddTool(GetDlgItem(IDC_EDIT3),_T("����������"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO3),_T("��ѡ����"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO1),_T("��ѡ����"));
	m_ToolTip.AddTool(GetDlgItem(IDC_COMBO2),_T("��ѡ����"));
	m_ToolTip.AddTool(GetDlgItem(IDC_STATIC),_T("ͼ��"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


HCURSOR Cinfo::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cinfo::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio=1;
}


void Cinfo::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Radio=2;
}

void Cinfo::OnBnClickedBtnadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (C_name=="")
	{
		MessageBox(_T("����������"),_T("����"),MB_OK|MB_ICONERROR);
		return;
	}//if
	else 
	{
		if (C_class=="")
		{
			MessageBox(_T("������༶"),_T("����"),MB_OK|MB_ICONERROR);
			return;
		}//if
		else
		{
			if (C_age=="")
			{
				MessageBox(_T("����������"),_T("����"),MB_OK|MB_ICONERROR);
				return;
			}//if
			else
			{
				if (C_year==""||C_month==""||C_day=="")
				{
					MessageBox(_T("��ѡ������"),_T("����"),MB_OK|MB_ICONERROR);
					return;
				}//if
				else
				{
					int count = m_Grid.GetItemCount();
					for (int i=0;i<count;i++)
					{
						if (m_Grid.GetItemText(i,0) == C_name)
						{		
							MessageBox(_T("�����Ѵ��ڣ�����������"));
							return;
						}//if
					}//for

					m_Grid.InsertItem(count,_T(""));//����հ���
					m_Grid.SetItemText(count,0,C_name);//��������

					m_Grid.SetItemText(count,1,C_class);//����༶
					m_Grid.SetItemText(count,3,C_age);//��������

					CString birthday;
					birthday = C_year+"/"+C_month+"/"+C_day;
					m_Grid.SetItemText(count,4,birthday);//��������

					//�����Ա�
					CString str1;
					CButton *Radiobutton = (CButton*)GetDlgItem(IDC_RADIO1+m_Radio-1);
					Radiobutton->GetWindowText(str1);
					m_Grid.SetItemText(count,2,str1);
					//MessageBox(str1);

					//���밮��
					CString favourate;
					CButton *pBtn;
					favourate = _T("");
					for (int i=0;i<=2;i++)
					{
						CString temp;
						pBtn = (CButton*)GetDlgItem(IDC_CHECK1+i);	//��ȡcheck��ѡ��ָ��
						if (pBtn->GetCheck())		//�жϸø�ѡ���Ƿ�ѡ��
						{
							pBtn->GetWindowText(temp);
							favourate+=temp + _T("/");		//׷�����ݣ���������ʾ

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret = MessageBox(_T("ȷ��ɾ����"),_T("����"),MB_YESNO|MB_ICONWARNING);
	if(IDYES==ret)
	{
		int pos  = m_Grid.GetSelectionMark();
		m_Grid.DeleteItem(pos);
	}
}


void Cinfo::OnBnClickedBtnclear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ret = MessageBox(_T("���֮�󲻿ɻָ��������������"),_T("����"),MB_YESNO|MB_ICONWARNING);
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
		m_ToolTip.UpdateTipText(_T("�༭��ؼ�"),GetDlgItem(IDC_LIST1));
	}

	return CDialog::PreTranslateMessage(pMsg);

}

void Cinfo::OnBnClickedBtnquit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//Cinfo::ShowWindow(SW_HIDE);
	//CDialog::ShowWindow(SW_SHOW);
	Cinfo::OnCancel();
}
