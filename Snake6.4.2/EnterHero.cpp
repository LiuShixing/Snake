// EnterHero.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "EnterHero.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// EnterHero dialog


EnterHero::EnterHero(CWnd* pParent /*=NULL*/)
	: CDialog(EnterHero::IDD, pParent)
{
	//{{AFX_DATA_INIT(EnterHero)
	m_NAME = _T("无名英雄");
	//}}AFX_DATA_INIT
}


void EnterHero::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EnterHero)
	DDX_Text(pDX, IDC_NAME, m_NAME);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(EnterHero, CDialog)
	//{{AFX_MSG_MAP(EnterHero)
	ON_EN_UPDATE(IDC_NAME, OnUpdateName)
	ON_EN_CHANGE(IDC_NAME, OnChangeName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EnterHero message handlers

void EnterHero::OnUpdateName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
//	GetDlgItemText(IDC_NAME,m_NAME);  
}

void EnterHero::OnChangeName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
    GetDlgItemText(IDC_NAME,m_NAME);
}

void EnterHero::OnOK() 
{
	// TODO: Add extra validation here
	if(m_NAME.GetLength()==0)
		MessageBox("请输入有效内容",NULL,MB_OK);
	else
	    CDialog::OnOK();
}
