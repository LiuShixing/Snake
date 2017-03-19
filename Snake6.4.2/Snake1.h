// Snake1.h: interface for the Snake class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKE1_H__9436413D_2248_492A_8C6C_94BA6D49C06D__INCLUDED_)
#define AFX_SNAKE1_H__9436413D_2248_492A_8C6C_94BA6D49C06D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Snake  
{
public:
	Snake();
	virtual ~Snake();
	void SetSnake();
	void PaintSnake(CClientDC &dc,CBrush &brush);
	void ShowFool(CClientDC &dc,CBrush &brush);
	void SnakeMove();
	void ShowSnake(CClientDC &dc,CBrush &brush);
	bool GameOver();
	void EatFool();
	void RePaintSnake(HWND hWnd,bool bErase);
	void ChangeDirection(int dx,int dy,char OldOppositeDire,char NewDire);

public:
	bool    m_iseat;//食物被吃没有  初始化true
    CRect   m_brect[200];
	CRect   m_eat;//食物
	CRect   m_oldtail;
	int     m_width;
	int     m_num;
	char    m_dire;       //当前运动方向
    char    m_tempdire;   //保存方向指令
	int     m_dx;        //x方向增量
	int     m_dy;
    int     m_kx;
	int  	m_ky;
	int     m_degree;

	int     m_temp;
};

#endif // !defined(AFX_SNAKE1_H__9436413D_2248_492A_8C6C_94BA6D49C06D__INCLUDED_)
