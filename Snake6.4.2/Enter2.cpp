// Enter2.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "Enter2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Enter2 dialog


Enter2::Enter2(CWnd* pParent /*=NULL*/)
	: CDialog(Enter2::IDD, pParent)
{
	//{{AFX_DATA_INIT(Enter2)
	m_NAME1 = _T("");
	m_NAME2 = _T("");
	m_NAME3 = _T("");
	m_NAME4 = _T("");
	m_MARK1 = _T("");
	m_MARK2 = _T("");
	m_MARK3 = _T("");
	m_MARK4 = _T("");
	//}}AFX_DATA_INIT
}


void Enter2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Enter2)
	DDX_Text(pDX, IDC_NAME1, m_NAME1);
	DDX_Text(pDX, IDC_NAME2, m_NAME2);
	DDX_Text(pDX, IDC_NAME3, m_NAME3);
	DDX_Text(pDX, IDC_NAME4, m_NAME4);
	DDX_Text(pDX, IDC_MARK1, m_MARK1);
	DDX_Text(pDX, IDC_MARK2, m_MARK2);
	DDX_Text(pDX, IDC_MARK3, m_MARK3);
	DDX_Text(pDX, IDC_MARK4, m_MARK4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Enter2, CDialog)
	//{{AFX_MSG_MAP(Enter2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Enter2 message handlers
