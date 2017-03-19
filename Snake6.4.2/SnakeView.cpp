// SnakeView.cpp : implementation of the CSnakeView class
//

#include "stdafx.h"
#include "Snake.h"

#include "SnakeDoc.h"
#include "SnakeView.h"
#include "Enter.h"
#include "Enter2.h"
#include "Snake1.h"
#include "GameSound.h"
#include "mmsystem.h"
#include "Player.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnakeView

IMPLEMENT_DYNCREATE(CSnakeView, CView)

BEGIN_MESSAGE_MAP(CSnakeView, CView)
	//{{AFX_MSG_MAP(CSnakeView)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeView construction/destruction
//int ox=405,oy=105;
int ox=2,oy=40;
Snake snake;
CEnter enter;
Enter2 enter2;
GameSound  gamemusic;



int   ChooseMode;//选择的模式
CSnakeView::CSnakeView()
{
	// TODO: add construction code here
	m_isdraw=true;
	m_is=false;
	m_isfirst=true;
	m_be_or_qu=0;//begin
	m_be_or_qu2=0;
	m_title=false;
	m_title2=false;
	m_title3=false;

	m_strscoce.Format("%d",0);
    
	m_Bbackground.m_ID =IDB_BACKGROUND;
	m_Bbackground2.m_ID =IDB_BACKGROUND2;
	m_Bbackground3.m_ID =IDB_BACKGROUND3;
	m_Bbackground4.m_ID =IDB_BACKGROUND4;
	m_Bbackground5.m_ID =IDB_BACKGROUND5;
	m_Bbackground6.m_ID =IDB_BACKGROUND6;

    m_Btitle28.SetMyBitmap (200,50,IDB_TITLE28);

    m_Bbegin28.SetMyBitmap(280,350,IDB_BEGIN28);    
	m_Bset28.SetMyBitmap (280,410,IDB_SET28);
	m_Bquit28.SetMyBitmap (280,470,IDB_QUIT28);	

	m_ShowScoce.SetRect(CPoint(0,0),CPoint(60,40));
    m_BestScoce.SetRect(CPoint(60,0),CPoint(120,40));
}
//#include<Ctime>
void CSnakeView::Setinit()
{
	m_isdraw=true;
	m_is=false;
	m_be_or_qu=0;//begin
	snake.SetSnake ();
    
}
CSnakeView::~CSnakeView()
{
}

BOOL CSnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView drawing

    BITMAP bm2;//获取位图大小
    BITMAP bm28;
void CSnakeView::OnDraw(CDC* pDC)
{ //  MessageBox("没错1");
	CSnakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	CBrush brush(RGB(5,255,255));
	CClientDC dc(this);

	//加入位图 并初始化  放在这容易出错！！！！！
	if(m_isdraw&&m_isfirst)  //防止重复初始化     
	{   
		gamemusic.GameSoundInit (m_hWnd);
		m_isfirst=false;
		InitBitmap(pDC,m_Bbackground);
		InitBitmap(pDC,m_Bbackground2);
		InitBitmap(pDC,m_Bbackground3);
		InitBitmap(pDC,m_Bbackground4);
		InitBitmap(pDC,m_Bbackground5);
		InitBitmap(pDC,m_Bbackground6);

        InitBitmap(pDC,m_Btitle28);
        InitBitmap(pDC,m_Bbegin28);
	    InitBitmap(pDC,m_Bquit28);
        InitBitmap(pDC,m_Bset28);
       
	}
	//获取位图大小
    m_Btitle28.m_bitmap .GetBitmap (&bm2);
    m_Bbegin28.m_bitmap .GetBitmap (&bm28);

	//贴图操作	
	if(m_isdraw)
	{  
		gamemusic.GameMusicplay (gamemusic.pStartmusic      );
		switch(snake.m_temp )
		{
		case SHANKS:
			pDC->BitBlt (0,0,800,600,&m_Bbackground.m_BITMAP ,0,0,SRCCOPY);
			break;
		case UNKOWN:
			pDC->BitBlt (0,0,800,600,&m_Bbackground2.m_BITMAP ,0,0,SRCCOPY);
			break;
		case SPACE:
			pDC->BitBlt (0,0,800,600,&m_Bbackground3.m_BITMAP ,0,0,SRCCOPY);
			break;
		case SNAKEI:
			pDC->BitBlt (0,0,800,600,&m_Bbackground5.m_BITMAP ,0,0,SRCCOPY);
			break;
		case SNAKEII:
			pDC->BitBlt (0,0,800,600,&m_Bbackground6.m_BITMAP ,0,0,SRCCOPY);
			break;
		}
        PaintBitmap(m_Btitle28,bm2,this);
        PaintBitmap(m_Bbegin28,bm28,this);
        PaintBitmap(m_Bquit28,bm28,this);
		PaintBitmap(m_Bset28,bm28,this);
		switch(m_be_or_qu)      //设焦点
		{
		case 0:
			PaintBitmap(m_Bbegin28,m_Bbegin28,bm28,this);
			break;
		case 1:
			PaintBitmap(m_Bset28,m_Bset28,bm28,this);
			break;
		case 2:
			PaintBitmap(m_Bquit28,m_Bquit28,bm28,this);
			break;
		}
//		m_btn.Create ("开始",BS_DEFPUSHBUTTON|/*WS_VISIBLE|*/WS_CHILD,CRect(100,400,80,50),this,123);
//    	m_btn.ShowWindow (SW_SHOWNORMAL);
	}
    if(!m_isdraw)
	{
		switch(snake.m_degree  )
		{
		case EASY:
			pDC->BitBlt (0,0,800,600,&m_Bbackground3.m_BITMAP ,0,0,SRCCOPY);
			 ChooseMode=0;
			break;
		case HARD:	
			pDC->BitBlt (0,0,800,600,&m_Bbackground.m_BITMAP ,0,0,SRCCOPY);
			 ChooseMode=1;
			break;
		case VERYHARD:
			pDC->BitBlt (0,0,800,600,&m_Bbackground2.m_BITMAP ,0,0,SRCCOPY);
			 ChooseMode=2;
			break;
		case MOST:
			pDC->BitBlt (0,0,800,600,&m_Bbackground6.m_BITMAP ,0,0,SRCCOPY);
			 ChooseMode=3;
			break;
		}
		GetBest(ChooseMode);//读取。。模式下最好成绩进m_strbestscoce
		CFont font;
		font.CreatePointFont (300,"华文行楷",NULL);
		CFont *pOldFont=pDC->SelectObject (&font);
		pDC->SetTextColor (RGB(225,0,50));
    	pDC->SetBkMode (TRANSPARENT);  //OPAQUE
		pDC->DrawText (m_strscoce,&m_ShowScoce,DT_CENTER||DT_VCENTER);
		pDC->DrawText (m_strbestscoce,&m_BestScoce,DT_CENTER||DT_VCENTER);
		pDC->SelectObject (pOldFont);
	}

	if(!m_isdraw && !m_is)//未开始且定时器未工作
	{
		snake.PaintSnake (dc,brush);
	/*		dc.FillRect( &snake.m_brect[0],&brush);
   	dc.FillRect (&snake.m_brect[1],&brush);
   	dc.FillRect (&snake.m_brect[2],&brush);*/
	}
	if(m_is)  //游戏开始
	{
		snake.ShowFool (dc,brush);//MessageBox("没错1");
        snake.SnakeMove (); 
		snake.ShowSnake(dc,brush);
		if(snake.GameOver ())
		{			
			KillTimer(1);
			Sleep(500);
			gamemusic.GameSoundAllstop ();
		//    gamemusic.GameSoundplay (gamemusic.plosemusic  );
			sndPlaySound((LPCSTR)IDR_THUNDER,SND_ASYNC|SND_RESOURCE);
		   	MessageBox("ABANDON ALL HOPE...");	
            JudgeHero(ChooseMode);
			Setinit();
			Invalidate();//强制重画窗口		
		}
	    snake.EatFool ();//包含是否吃到食物及其处理
		if(snake.m_iseat==true)
		{
			int i=snake.m_num -3;
			m_strscoce.Format("%d",i);
			CFont font;
	    	font.CreatePointFont (300,"华文行楷",NULL);
	    	CFont *pOldFont=pDC->SelectObject (&font);
	    	pDC->SetTextColor (RGB(225,50,50));
        	pDC->SetBkMode (TRANSPARENT);  //OPAQUE
	    	pDC->DrawText (m_strscoce,&m_ShowScoce,DT_CENTER||DT_VCENTER);
	    	pDC->SelectObject (pOldFont);
            InvalidateRect(&m_ShowScoce);
			dc.FillRect( &snake.m_brect[0],&brush);//画蛇尾
		}
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView printing

BOOL CSnakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSnakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSnakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSnakeView diagnostics

#ifdef _DEBUG
void CSnakeView::AssertValid() const
{
	CView::AssertValid();
}
void CSnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSnakeDoc* CSnakeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnakeDoc)));
	return (CSnakeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnakeView message handlers

void CSnakeView::OnLButtonDown(UINT nFlags, CPoint point) 
{

	// TODO: Add your message handler code here and/or call default
	if(m_isdraw)
	{
		switch(JudgeMouse(point,true))
		{
		case 0: 
			gamemusic.GameSoundplay (gamemusic.pAttacksound );
		   	m_isdraw=false;
        	Invalidate();//强制重画窗口
			gamemusic.GameMusicplay (gamemusic.pTalkmusic      );
    		SetTimer(1,snake.m_degree,NULL);
			break;
		case 1:
			gamemusic.GameSoundplay (gamemusic.pAttacksound );
			enter.DoModal ();
			gamemusic.GameSoundAllstop ();
			Invalidate();//强制重画窗口
			
			break;
	    case 2:
	    //	DestroyWindow();
			exit(0);
   	        m_isdraw=false;
			break;
		case 3:
			gamemusic.GameSoundplay (gamemusic.pAttacksound );
			ShowHero();
			break;
		}    		    					
    	CView::OnLButtonDown(nFlags, point);
	}
}

void CSnakeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_is=true;//定时器启动
	snake.RePaintSnake (m_hWnd,true);
	CView::OnTimer(nIDEvent);
}

int CSnakeView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	return 0;
}

void CSnakeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
//	CClientDC dc(this);
	if(!m_isdraw)//点击开始后才进行响应
	{
    	switch(nChar)
		{
		case'W':
    	case 'w':
		case VK_UP:
			snake.ChangeDirection (0,-snake.m_width,'s','w');
			break;
		case'S':
    	case 's':
		case VK_DOWN:
			snake.ChangeDirection (0,+snake.m_width,'w','s');
			break;
		case'A':
    	case 'a':
		case VK_LEFT:
			snake.ChangeDirection (-snake.m_width,0,'d','a');
			break;
		case'D':
    	case 'd':
		case VK_RIGHT:
			snake.ChangeDirection (+snake.m_width,0,'a','d');
			break;
		}
    	CView::OnChar(nChar, nRepCnt, nFlags);
	}
	if(m_isdraw)
	{
		switch(nChar)
		{
		case VK_UP:
			{
				switch(m_be_or_qu2)
				{
				case 1:				
					ChangeFocus(0,m_Bbegin28,m_Bquit28,m_Bset28);	//改焦点	   
					break;					
				case 2:				
					ChangeFocus(1,m_Bset28,m_Bquit28,m_Bbegin28);
					break;				
				}
			    break;
			}
		case VK_DOWN:
			{
				switch(m_be_or_qu2)
				{
				case 0:
					ChangeFocus(1,m_Bset28,m_Bquit28,m_Bbegin28);
					break;			
				case 1:
					ChangeFocus(2,m_Bquit28,m_Bbegin28,m_Bset28);			        	
					break;
				}
				break;
			}	
		case VK_RETURN:
			{
				switch(m_be_or_qu2)
				{
				case 0:
			        m_isdraw=false;
					gamemusic.GameSoundplay (gamemusic.pAttacksound );
                   	Invalidate();//强制重画窗口
					gamemusic.GameMusicplay (gamemusic.pTalkmusic      );
    	           	SetTimer(1,snake.m_degree ,NULL);
					break;
				case 2:
			//		DestroyWindow();
					exit(0);
					break;
				case 1:
					gamemusic.GameSoundplay (gamemusic.pAttacksound );
					enter.DoModal ();	
					gamemusic.GameSoundAllstop ();
			        Invalidate();//强制重画窗口
					break;
				}
				break;
			}		
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CSnakeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if(m_isdraw)
	{
		switch(JudgeMouse(point,false))
		{
		case 0: 
		    ChangeFocus(0,m_Bbegin28,m_Bquit28,m_Bset28);
			break;
		case 1:
			ChangeFocus(1,m_Bset28,m_Bquit28,m_Bbegin28);
			break;
		case 2:
			ChangeFocus(2,m_Bquit28,m_Bbegin28,m_Bset28);
			break;
		case 3:
		case 4:
			ChangeFocus(3,m_Btitle28);
			break;
		default:
			if(m_title2&&(!m_title) && m_title3)
			    ChangeFocus(9,m_Btitle28,false);//4为区分值
			break;
		}   			   					        		     			      
    	CView::OnMouseMove(nFlags, point);
	}
}
