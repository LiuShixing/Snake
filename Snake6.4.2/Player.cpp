// Player.cpp: implementation of the Player class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Snake.h"
#include "Player.h"
#include "EnterHero.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

extern int   ChooseMode;
Player::Player()
{
    m_name="wuming";
	m_mark="0";
	m_number='1';
}

Player::~Player()
{

}

void OpenMyFile ( FILE* &file,int mode,char *ch)
{
	switch(mode)
	 {
	 case 0:
		  file=fopen("hero1.txt","a");
		  fclose(file);
		  file=fopen ("hero1.txt",ch);
		 break;
	 case 1:
		  file=fopen("hero2.txt","a");
		  fclose(file);
		  file=fopen("hero2.txt",ch);
		 break;
	 case 2:
		  file=fopen("hero3.txt","a");
		  fclose(file);
		  file=fopen ("hero3.txt",ch);
		 break;
	 case 3:
		  file=fopen("hero4.txt","a");
		  fclose(file);
		  file=fopen ("hero4.txt",ch);
		  break;
	 }
}