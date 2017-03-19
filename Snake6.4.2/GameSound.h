// GameSound.h: interface for the GameSound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GAMESOUND_H__56321890_FB26_4FE5_BF1B_E99CDD291A25__INCLUDED_)
#define AFX_GAMESOUND_H__56321890_FB26_4FE5_BF1B_E99CDD291A25__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mmsystem.h"
#include "dsound.h"
#include "windows.h"
#include "mmreg.h"
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"dsound.lib")
//#ifndef GAMESOUND
//#define GAMESOUND

class GameSound  
{
private:
//	virtual ~GameSound();
	HWND                soundhwnd;

	HRESULT             result; //�������ܽ�����ķ���ֵ
	LPDIRECTSOUND       pDS;  //����������DirectSound����
	LPDIRECTSOUNDBUFFER pMainBuf;  //������������ָ��
	DSBUFFERDESC        desc;  //���������ṹ��������ʼ����������
	WAVEFORMATEX        pwfmt;  //���������ṹ�������趨���Ÿ�ʽ

    WAVEFORMATEX        swfmt;  //���������ṹ
	MMCKINFO            ckRiff;  //RIFF�������Ϣ
	MMCKINFO            ckInfo;  //���������Ϣ
	MMRESULT            mmresult;  //���ؽ��
	DWORD               size;   //ʵ�����ϵĴ�С
	HMMIO               hbackground;  //�򿪵Ķ�ý���ļ�
public:
	GameSound();
	void GameSoundInit(HWND);      //GameSound����Ľ���   0
	void GameSoundbufferConstruct();   //�������Ĵ���     0
	void GameSoundfmtSet(int,int,int);   //ͨ����������ָ�������ò��Ÿ�ʽ
	void GameSoundReadWAVfile(char*,HMMIO&);  //�������ļ����벢����ϸ����HMMIO�ṹ��  0
	void GameSoundReadinbuffer(LPDIRECTSOUNDBUFFER&,char*);   //�������ļ�����λ�������  0

	LPDIRECTSOUNDBUFFER pStartmusic;   //�����ӻ�����ָ��
	LPDIRECTSOUNDBUFFER pTalkmusic;
	LPDIRECTSOUNDBUFFER pWalkmusic;
	LPDIRECTSOUNDBUFFER pWarmusic;
	LPDIRECTSOUNDBUFFER pyudimusic;   //��������ָ��
	LPDIRECTSOUNDBUFFER pwinmusic;
	LPDIRECTSOUNDBUFFER plosemusic;
	LPDIRECTSOUNDBUFFER pAttacksound;
	LPDIRECTSOUNDBUFFER pAIAttacksound;
    
	void GameSoundSomestop ();
	void GameSoundAllstop();   //for�������֣��ñ������ָ���ʱ����ǰ���������ֶ�ֹͣ���Ӷ������µ�����
	void GameMusicplay(LPDIRECTSOUNDBUFFER&);  //��������ѭ������
	void GameSoundplay(LPDIRECTSOUNDBUFFER&);	//��������һ������Ч
};

#endif // !defined(AFX_GAMESOUND_H__56321890_FB26_4FE5_BF1B_E99CDD291A25__INCLUDED_)
