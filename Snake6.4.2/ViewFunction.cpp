#include "stdafx.h"
#include "Snake.h"
#include "Snake1.h"
#include "SnakeDoc.h"
#include "SnakeView.h"
#include "Enter.h"
#include "Enter2.h"
#include "mmsystem.h"
#include "Player.h"
#include "GameSound.h"
#include "EnterHero.h"
#include  <string.h>
void CSnakeView::InitBitmap (CDC *pDC,Bitmap &bitmap)
{
	bitmap.m_bitmap .LoadBitmap (bitmap.m_ID );
	bitmap.m_BITMAP .CreateCompatibleDC (pDC);
	bitmap.m_BITMAP .SelectObject (bitmap.m_bitmap );
}

void CSnakeView::PaintBitmap ( Bitmap &myb,const BITMAP& bm,CSnakeView *pt,bool flage)
{
	CClientDC dc(pt);
	dc.BitBlt (myb.m_location .x,myb.m_location.y,bm.bmWidth ,bm.bmHeight ,&myb.m_BITMAP ,0,0,MERGEPAINT);//改位图背景色
	if(flage==true)
	{
    	dc.BitBlt (myb.m_location .x,myb.m_location.y,bm.bmWidth ,bm.bmHeight ,&myb.m_BITMAP ,0,0,SRCAND);
	}
}
void CSnakeView::PaintBitmap ( Bitmap &myb, Bitmap &myb2,const BITMAP& bm,CSnakeView *pt)
{   
	CClientDC dc(pt);
	dc.BitBlt (myb.m_location .x,myb.m_location.y,bm.bmWidth ,bm.bmHeight ,&myb.m_BITMAP ,0,0,MERGEPAINT);//改位图背景色
	dc.BitBlt (myb.m_location .x,myb.m_location.y,bm.bmWidth ,bm.bmHeight ,&myb.m_BITMAP ,0,0,SRCAND);
    dc.BitBlt (myb.m_location .x,myb.m_location.y,bm.bmWidth ,bm.bmHeight ,&myb2.m_BITMAP ,0,0,MERGEPAINT);
	//StretchBlt函数可以拉伸位图
}
//获取位图大小
extern   BITMAP bm2;
extern   BITMAP bm28;
extern   GameSound  gamemusic;
extern   Snake snake;
extern   Enter2 enter2;
void CSnakeView::ChangeFocus(int k,Bitmap &bshow,bool flage)
{

	if(flage)
	{
		m_title2=false;  ////判断title是否可以添加焦点  初始化为false
		m_title3=true;//说明待会得去除焦点
		m_be_or_qu=k;
		gamemusic.GameSoundplay  (gamemusic.pWalkmusic );  
        PaintBitmap(bshow,bm2,this, false);//以MERGEPAINT模式贴图
	}
	else
	{   
		m_title=true;
        m_title3=false;
		PaintBitmap(bshow,bm2,this);
	}
}
void CSnakeView::ChangeFocus(int k,Bitmap &bshow,Bitmap &bhide1,Bitmap &bhide2)
{
	
	m_be_or_qu=k; 
	m_be_or_qu2=k;
	PaintBitmap(bshow,bm28,this, false);//以MERGEPAINT模式贴图
				//恢复另两个的颜色
    PaintBitmap(bhide1,bm28,this);
	PaintBitmap(bhide2,bm28,this);
//	gamemusic.GameSoundplay (gamemusic.pWalkmusic );
	sndPlaySound((LPCSTR)IDR_FLESH,SND_ASYNC|SND_RESOURCE);
//	PlaySound((LPCSTR)IDR_SOUNDTEST,NULL,SND_ASYNC|SND_RESOURCE|SND_NODEFAULT|SND_LOOP);
}
int CSnakeView::JudgeMouse(const CPoint& point,bool flage)
{
	if(point.x >=m_Bbegin28.m_location .x &&point.x<=m_Bbegin28.m_location .x+bm28.bmWidth &&point.y>=m_Bbegin28.m_location .y 
		&&point.y <=m_Bbegin28.m_location .y+bm28.bmHeight )
	{
		if(m_be_or_qu!=0 ||flage==true)
	    	return 0;
	}
	if(point.x>=m_Bset28.m_location .x  &&point.x<=m_Bset28.m_location .x+bm28.bmWidth && point.y>=m_Bset28.m_location .y 
		&&point.y<=m_Bset28.m_location .y+bm28.bmHeight )
	{
		if(m_be_or_qu!=1 ||flage==true)
		return 1;
	}
	if(point.x>=m_Bquit28.m_location .x  &&point.x<=m_Bquit28.m_location.x+bm28.bmWidth && point.y>=m_Bquit28.m_location.y 
		&&point.y<=m_Bquit28.m_location.y+bm28.bmHeight )
	{
		if(m_be_or_qu!=2 ||flage==true)
		return 2;
	}
	if(point.x>=m_Btitle28.m_location .x  &&point.x<=m_Btitle28.m_location.x+bm2.bmWidth && point.y>=m_Btitle28.m_location.y 
		&&point.y<=m_Btitle28.m_location.y+bm2.bmHeight )
	{
		m_title=true;
		if(m_be_or_qu!=3 ||flage==true)
		return 3;
	}
	else 
	{
		m_title=false;
	    m_title2=true;   ////判断title是否可以添加焦点  初始化为false
	}
	if(m_title==true&&m_title2==true)  //
        return 4;
	return 9;
}
Player    play[4][3];
EnterHero enterhero;
void CSnakeView::JudgeHero(int mode)
{
	FILE* f1;
	char ch[4];
    OpenMyFile(f1,mode,"r");
	bool flag=false;
	int len1=0;
    if(fgetc(f1)!=EOF)
	{
		rewind(f1); 
		while(fgetc(f1)!='\0')
		{
			len1++;
		}
		rewind(f1);
		fread(ch ,1,len1+1,f1);
	}
	else
		flag=true;
	fclose(f1);
    OpenMyFile(f1,mode,"r+");
	ch[len1]='\0';
	int lastbest=atoi(ch);
	int total=snake.m_num -3;
	char totalmark[4];
    itoa(total,totalmark,10);
	int lenmark=strlen(totalmark);
	totalmark[lenmark]='\0';
	if((total>lastbest)||(flag==true))
	{
		enterhero.DoModal ();
		char* name;
		name=enterhero.m_NAME .GetBuffer (20);
        enterhero.m_NAME.ReleaseBuffer ();
		int lenname=strlen(name);
		name[lenname]='\0';	
		//开始写入文件
		rewind(f1);
		fwrite(totalmark,1,lenmark+1,f1);
		fwrite(name,1,lenname+1,f1);
		fclose(f1);	
		ShowHero();
	}
	else
   	    fclose(f1);	
//	MessageBox("没错",NULL,MB_OK);
}
void CSnakeView::ShowHero() //显示英雄榜
{
	FILE *f1;
    OpenMyFile(f1,0,"r");
	int len1=0;
	int len2=0;
	char ch1[4];
	char ch2[20];
	char c=fgetc(f1);
    if(c!=EOF)
	{
		rewind(f1); 
		while(fgetc(f1)!='\0')
		{
			len1++;
		}
		
		while(fgetc(f1)!='\0')
		{
			len2++;
		}
		rewind(f1);
		fread(ch1 ,1,len1+1,f1);
		fread(ch2 ,1,len2+1,f1);
		ch1[len1]='\0';
		ch2[len2]='\0';
		enter2.m_MARK1 =ch1;
		enter2.m_NAME1 =ch2;
	}
	fclose(f1);

	FILE *f2;
    OpenMyFile(f2,1,"r");
	int len3=0;
	int len4=0;
	char ch3[4];
	char ch4[20];
    if(fgetc(f2)!=EOF)
	{
		rewind(f2); 
		while(fgetc(f2)!='\0')
		{
			len3++;
		}
		
		while(fgetc(f2)!='\0')
		{
			len4++;
		}
		rewind(f2);
		fread(ch3 ,1,len3+1,f2);
		fread(ch4 ,1,len4+1,f2);
		ch3[len3]='\0';
		ch4[len4]='\0';
		enter2.m_MARK2 =ch3;
    	enter2.m_NAME2 =ch4;
	}
	fclose(f2);

	FILE *f3;
    OpenMyFile(f3,2,"r");
	int len5=0;
	int len6=0;
	char ch5[4];
	char ch6[20];
    if(fgetc(f3)!=EOF)
	{
		rewind(f3); 
		while(fgetc(f3)!='\0')
		{
			len5++;
		}
		
		while(fgetc(f3)!='\0')
		{
			len6++;
		}
		rewind(f3);
		fread(ch5 ,1,len5+1,f3);
		fread(ch6 ,1,len6+1,f3);
		ch5[len5]='\0';
		ch6[len6]='\0';
		enter2.m_MARK3 =ch5;
	    enter2.m_NAME3 =ch6;
	}
	fclose(f3);

	FILE *f4;
    OpenMyFile(f4,3,"r");
	int len7=0;
	int len8=0;
	char ch7[4];
	char ch8[20];
    if(fgetc(f4)!=EOF)
	{
		rewind(f4); 
		while(fgetc(f4)!='\0')
		{
			len7++;
		}
		
		while(fgetc(f4)!='\0')
		{
			len8++;
		}
		rewind(f4);
		fread(ch7 ,1,len7+1,f4);
		fread(ch8 ,1,len8+1,f4);
		ch7[len7]='\0';
		ch8[len8]='\0';
		enter2.m_MARK4 =ch7;
    	enter2.m_NAME4 =ch8;
	}
	fclose(f4);

	enter2.DoModal ();
}
void CSnakeView::GetBest(int mode)
{
	FILE* f1;
	char ch[4];
    OpenMyFile(f1,mode,"r");
	int len1=0;
    if(fgetc(f1)!=EOF)
	{
		rewind(f1); 
		while(fgetc(f1)!='\0')
		{
			len1++;
		}
		rewind(f1);
		fread(ch ,1,len1+1,f1);
		int i=atoi(ch);
        m_strbestscoce.Format("%d",i);
	}
	else
	{
		m_strbestscoce.Format("%d",0);
	}
	fclose(f1);
}