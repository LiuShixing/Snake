// Enter.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "Enter.h"
#include "Snake1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnter dialog

extern Snake snake;
CEnter::CEnter(CWnd* pParent /*=NULL*/)
	: CDialog(CEnter::IDD, pParent)
{ 
//	((CButton*)GetDlgItem(IDC_HARD))
	//{{AFX_DATA_INIT(CEnter)
	m_EASY = 1;
	m_Shanks = 2;
	m_OPEN = 0;
	//}}AFX_DATA_INIT
	m_choose=HARD;
	m_chooseBackground=UNKOWN;
	m_Backmusic=true;
	m_BackmusicChoose=true;
}


void CEnter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnter)
	DDX_Radio(pDX, IDC_EASY, m_EASY);
	DDX_Radio(pDX, IDC_Shanks, m_Shanks);
	DDX_Radio(pDX, IDC_OPEN, m_OPEN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnter, CDialog)
	//{{AFX_MSG_MAP(CEnter)
	ON_BN_CLICKED(IDC_EASY, OnEasy)
	ON_BN_CLICKED(IDC_HARD, OnHard)
	ON_BN_CLICKED(IDC_VERYHARD, OnVeryhard)
	ON_BN_CLICKED(IDC_MOST, OnMost)
	ON_BN_CLICKED(IDC_Shanks, OnShanks)
	ON_BN_CLICKED(IDC_Space, OnSpace)
	ON_BN_CLICKED(IDC_Unkown, OnUnkown)
	ON_BN_CLICKED(IDC_SnakeI, OnSnakeI)
	ON_BN_CLICKED(IDC_SnakeII, OnSnakeII)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	ON_BN_CLICKED(IDC_OFF, OnOff)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnter message handlers

void CEnter::OnOK() 
{
	// TODO: Add extra validation here
	snake.m_degree =m_choose;
	snake.m_temp=m_chooseBackground;//Ê×Ò³±³¾°
	m_Backmusic=m_BackmusicChoose;
	CDialog::OnOK();
}

void CEnter::OnEasy() 
{
	// TODO: Add your control notification handler code here
	m_choose=EASY;
}

void CEnter::OnHard() 
{
	// TODO: Add your control notification handler code here
	m_choose=HARD;
}

void CEnter::OnVeryhard() 
{
	// TODO: Add your control notification handler code here
	m_choose=VERYHARD;
}

void CEnter::OnMost() 
{
	// TODO: Add your control notification handler code here
	m_choose=MOST;
}

void CEnter::OnShanks() 
{
	m_chooseBackground=SHANKS;
	// TODO: Add your control notification handler code here
	
}

void CEnter::OnSpace() 
{
	// TODO: Add your control notification handler code here
	m_chooseBackground=SPACE;
}

void CEnter::OnUnkown() 
{
	// TODO: Add your control notification handler code here
	m_chooseBackground=UNKOWN;
}

void CEnter::OnSnakeI() 
{
	// TODO: Add your control notification handler code here
	m_chooseBackground=SNAKEI;
}

void CEnter::OnSnakeII() 
{
	// TODO: Add your control notification handler code here
	m_chooseBackground=SNAKEII;
}

void CEnter::OnOpen() 
{
	// TODO: Add your control notification handler code here
	m_BackmusicChoose=true;
}

void CEnter::OnOff() 
{
	// TODO: Add your control notification handler code here
	m_BackmusicChoose=false;
}
