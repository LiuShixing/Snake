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
    m_wndToolBar.ShowWindow (SW_HIDE);//+++++隐藏工具栏
	m_wndStatusBar.ShowWindow (SW_HIDE);//隐藏状态栏	CMainFrame::ShowControlBar(&m_wndStatusBar,FALSE,FALSE);//关闭状态栏  ++也可行
//	m_btn.Create ("开始",BS_DEFPUSHBUTTON|WS_VISIBLE|WS_CHILD,CRect(100,400,80,50),this,123);
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
	int k=GetSystemMetrics(SM_CYFRAME);//获取边框宽度
	cs.cx=794;
	cs.cy=594;
    cs.hMenu =0;//隐藏菜单
	cs.style &=~WS_MAXIMIZEBOX;//禁止窗口最大化
//	cs.style &=~WS_SYSMENU;//取消Title上的按钮
	cs.style &=~WS_THICKFRAME;//使窗口不能用鼠标改变大小
//	cs.lpszClass ="Snake";	
//	CWnd::SetWindowText ("Snake");
	cs.style &=~FWS_ADDTOTITLE;
	cs.lpszName =_T("Snake");//上一句和这句更改标题栏
//	cs.lpszClass =AfxRegisterWndClass(0);
    
//	CMainFrame::ShowControlBar(&m_wndStatusBar,FALSE,FALSE);//关闭状态栏    ++不可行

    
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