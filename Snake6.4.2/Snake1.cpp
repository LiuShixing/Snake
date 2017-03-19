// Snake1.cpp: implementation of the Snake class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Snake.h"
#include "Snake1.h"
#include "Enter.h"
#include "GameSound.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern int ox;
extern int oy;
extern   GameSound  gamemusic;
Snake::Snake()
{	
	m_iseat=true;
	m_width=20;
	m_num=3;
	m_kx=0;
	m_ky=0;
    m_degree=HARD;
	m_dire='s';//当前运动方向
	m_tempdire='s';
	m_dx=0;
	m_dy=+m_width;

	m_temp=UNKOWN;

	m_brect[2].SetRect (CPoint(ox,oy),CPoint(ox+20,oy+20));
	m_brect[1].SetRect (CPoint(ox,oy-20),CPoint(ox+20,oy-20));
	m_brect[0].SetRect (CPoint(ox,oy-40),CPoint(ox+20,oy-40));

	m_oldtail=m_brect[0];
}
void Snake::SetSnake ()
{
	m_iseat=true;
    m_num=3;
	m_kx=0;
	m_ky=0;
	m_dire='s';//当前运动方向
	m_tempdire='s';
	m_dx=0;
	m_dy=+m_width;

	CRect temp;
	temp.SetRect (CPoint(0,0),CPoint(20,20));
    for(int k=3;k<200;k++)
	{
		m_brect[k]=temp;
	}
	m_brect[2].SetRect (CPoint(ox,oy),CPoint(ox+20,oy+20));
	m_brect[1].SetRect (CPoint(ox,oy-20),CPoint(ox+20,oy-20));
	m_brect[0].SetRect (CPoint(ox,oy-40),CPoint(ox+20,oy-40));

	m_oldtail=m_brect[0];
}

Snake::~Snake()
{

}

void Snake::PaintSnake(CClientDC &dc,CBrush &brush)
{
	dc.FillRect( &m_brect[0],&brush);
   	dc.FillRect (&m_brect[1],&brush);
   	dc.FillRect (&m_brect[2],&brush);
}
void Snake::ShowFool(CClientDC &dc,CBrush &brush)
{
	if(m_iseat)
	{
	   	srand((unsigned int)time(NULL));
        m_kx=rand()%39;
        srand((unsigned int)time(NULL));
	    m_ky=rand()%25;
	  	m_eat.SetRect (CPoint(ox+m_kx*20,oy+m_ky*20),CPoint(ox+m_kx*20+20,oy+m_ky*20+20));
		m_iseat=false;
	}
	dc.FillRect (&m_eat,&brush);//显示食物
}

void Snake::SnakeMove()
{
    m_dire=m_tempdire;
	m_oldtail=m_brect[0];
    for(int i=0;i<m_num-1;++i)
	{			
		m_brect[i]=m_brect[i+1];
	}
	m_brect[m_num-1].SetRect (CPoint(m_brect[m_num-2].TopLeft ().x+m_dx,m_brect[m_num-2].TopLeft ().y+m_dy ),//左上角坐标
		CPoint(m_brect[m_num-2].BottomRight ().x+m_dx,m_brect[m_num-2].BottomRight ().y +m_dy));//右下角坐标
}

void Snake::ShowSnake(CClientDC &dc,CBrush &brush)
{
	for(int j=0;j<m_num;j++)
			dc.FillRect( &m_brect[j],&brush);
}

bool Snake::GameOver()
{
	 //判断出界
	if(((m_brect[m_num-1].TopLeft ().x<=0)&&(m_dire=='a')) || ((m_brect[m_num-1].TopLeft ().y<0/*不等于0*/)&&(m_dire=='w')) ||   
			((m_brect[m_num-1].BottomRight ().x>=800)&&(m_dire=='d')) ||((m_brect[m_num-1].BottomRight ().y>=570)&&(m_dire=='s'))  )
	{
		 return true;
	}
	for(int i=0;i<m_num-2;++i)//判断撞到自己
	{
		//	if(((m_brect[m_num-1].TopLeft ()==m_brect[i].BottomRight() )&&(m_dire=='a' || m_brect[m_num-1].BottomRight()  ==m_brect[i].TopLeft ())
	    if(m_brect[m_num-1].TopLeft ()==m_brect[i].TopLeft ())
		{
			return true;	
		}
	}
	return false;
}

void Snake::EatFool()
{
	
	if(m_brect[m_num-1].TopLeft ()==m_eat.TopLeft ())
	{
	//	gamemusic.GameSoundAllstop ();
	//	gamemusic.GameSoundplay (gamemusic.pwinmusic );
		sndPlaySound((LPCSTR)IDR_CHIMES,SND_ASYNC|SND_RESOURCE);
    	m_iseat=true;
		m_num++;
		//在蛇尾增加矩形
/*		m_brect[m_num-1].SetRect (m_oldtail.TopLeft (),m_oldtail.BottomRight ());
		CRect temp=m_brect[m_num-2];
		for(int i=m_num-2;i>0;i--)
		{
			m_brect[i]=m_brect[i-1];
		}
		m_brect[0]=m_brect[m_num-1];
		m_brect[m_num-1]=temp;
		*/
		for(int i=m_num;i>0;i--)
		{
			m_brect[i]=m_brect[i-1];
		}
		m_brect[0].SetRect (m_oldtail.TopLeft (),m_oldtail.BottomRight ());
	 }
}

void Snake::RePaintSnake(HWND hWnd,bool bErase )
{
	for(int i=0;i<m_num;i++)
	{
    	InvalidateRect(hWnd,&m_brect[i],bErase);
	}
	InvalidateRect(hWnd,&m_oldtail,bErase);
	InvalidateRect(hWnd,&m_eat,bErase);
}

void Snake::ChangeDirection(int dx,int dy,char OldOppositeDire,char NewDire)
{
	if(!(m_dire==OldOppositeDire))//判断方向是否矛盾        !!!!!!!!  取!时加括号
	{
    	m_dx=dx;
    	m_dy=dy;
    	m_tempdire=NewDire;
	}
}