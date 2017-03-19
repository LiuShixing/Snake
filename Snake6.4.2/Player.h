// Player.h: interface for the Player class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__A536949F_8A42_45B0_A076_3BB703E1BFAB__INCLUDED_)
#define AFX_PLAYER_H__A536949F_8A42_45B0_A076_3BB703E1BFAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<iostream>
#include<string>
using namespace std;
class Player  
{
public:
	Player();
	virtual ~Player();
	Player& operator=(const Player& player);
	
	char*  m_name;
	char*      m_mark;
	char      m_number;
};

void OpenMyFile( FILE* &file,int ,char*);
void Addplay(int,int);  //弹出窗口获取玩家姓名，并保存进文件

#endif // !defined(AFX_PLAYER_H__A536949F_8A42_45B0_A076_3BB703E1BFAB__INCLUDED_)
