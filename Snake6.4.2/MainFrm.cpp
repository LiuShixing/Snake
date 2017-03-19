// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Snake.h"
#include "GameSound.h"
#include "MainFrm.h"
#include "mmsystem.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_SYSCOMMAND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here

}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
    m_wndToolBar.ShowWindow (SW_HIDE);//+++++���ع�����
	m_wndStatusBar.ShowWindow (SW_HIDE);//����״̬��	CMainFrame::ShowControlBar(&m_wndStatusBar,FALSE,FALSE);//�ر�״̬��  ++Ҳ����
//	m_btn.Create ("��ʼ",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,CRect(100,400,80,50),this,123);
//	m_btn.ShowWindow (SW_SHOWNORMAL);
	HICON hIcon=AfxGetApp()->LoadIcon (IDI_ICON1);
	SetIcon(hIcon,TRUE);
	SetIcon(hIcon,FALSE);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.x =300;
	cs.y=100;
	int k=GetSystemMetrics(SM_CYFRAME);//��ȡ�߿���
	cs.cx=794;
	cs.cy=594;
    cs.hMenu =0;//���ز˵�
	cs.style &=~WS_MAXIMIZEBOX;//��ֹ�������
//	cs.style &=~WS_SYSMENU;//ȡ��Title�ϵİ�ť
	cs.style &=~WS_THICKFRAME;//ʹ���ڲ��������ı��С
//	cs.lpszClass ="Snake";	
//	CWnd::SetWindowText ("Snake");
	cs.style &=~FWS_ADDTOTITLE;
	cs.lpszName =_T("Snake");//��һ��������ı�����
//	cs.lpszClass =AfxRegisterWndClass(0);
    
//	CMainFrame::ShowControlBar(&m_wndStatusBar,FALSE,FALSE);//�ر�״̬��    ++������

    
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

extern   GameSound  gamemusic;
void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	CFrameWnd::OnClose();
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFrameWnd::OnCommand(wParam, lParam);
}
void CMainFrame::OnSysCommand (UINT nID,LPARAM IParam)
{
	if(nID==SC_MINIMIZE)
	{
		gamemusic.GameSoundAllstop ();
	}
	CFrameWnd::OnSysCommand (nID,IParam);
}