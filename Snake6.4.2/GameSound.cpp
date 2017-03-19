// GameSound.cpp: implementation of the GameSound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Snake.h"
#include "GameSound.h"
#include "Enter.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

extern CEnter enter;
GameSound::GameSound()
{

}

//GameSound::~GameSound()
//{

//}
void GameSound::GameSoundInit (HWND hwnd)
{
	this->pDS ;
	this->soundhwnd =hwnd;
	this->result =DirectSoundCreate(NULL,&pDS,NULL);//DirectSoundEnumerate
	if(this->result !=DS_OK)
		MessageBox(hwnd,"����DirectSound����ʧ�ܣ�",NULL,MB_OK);
	this->result =this->pDS ->SetCooperativeLevel(hwnd,DSSCL_PRIORITY);
	if(this->result !=DS_OK)
		MessageBox(hwnd,"�趨����Э���㼶ʧ�ܣ�",NULL,MB_OK);
	this->GameSoundbufferConstruct ();

}

void GameSound::GameSoundbufferConstruct()
{
	memset(&this->desc ,0,sizeof(desc));
	desc.dwSize =sizeof(desc);
	desc.dwFlags =DSBCAPS_PRIMARYBUFFER;
	desc.dwBufferBytes =0;
	desc.lpwfxFormat =NULL;
	result=pDS->CreateSoundBuffer (&desc,&this->pMainBuf ,NULL);
	if(this->result !=DS_OK)
		MessageBox(this->soundhwnd ,"��������������ʧ�ܣ�",NULL,MB_OK);
	this->GameSoundReadinbuffer (this->pTalkmusic ,"res\\guit1.wav");
	this->GameSoundReadinbuffer (this->pStartmusic ,"res\\SoundTest.wav");
	this->GameSoundReadinbuffer (this->pAttacksound ,"res\\friend_join.wav");
	this->GameSoundReadinbuffer (this->pWalkmusic ,"res\\flesh7.wav");
	this->GameSoundReadinbuffer (this->plosemusic ,"res\\thunder_clap.wav");
	this->GameSoundReadinbuffer (this->pwinmusic ,"res\\CHIMES.WAV");
//	this->GameSoundReadinbuffer (this->pWarmusic ,"sound//talk2.wav");
/*	this->GameSoundReadinbuffer (this->pAIAttacksound ,"sound//talk2.wav");
	this->GameSoundReadinbuffer (this->pyudimusic ,"sound//talk2.wav");	MAKEINTRESOURCE
	*/
}
void GameSound::GameSoundSomestop ()
{
	this->plosemusic ->Stop ();
	this->pwinmusic ->Stop ();
	this->pAttacksound ->Stop ();
	this->pWalkmusic ->Stop ();
}
void GameSound::GameSoundAllstop ()
{
	this->pTalkmusic ->Stop ();
	this->pStartmusic ->Stop ();
	this->pAttacksound ->Stop ();
	this->pWalkmusic ->Stop ();
	this->plosemusic ->Stop ();
	this->pwinmusic ->Stop ();
/*	this->pWarmusic ->Stop ();
	this->pyudimusic ->Stop ();
	
	this->pAIAttacksound ->Stop ();
    this->pAttacksound ->SetCurrentPosition (0);
	this->pStartmusic ->SetCurrentPosition (0);
	this->pTalkmusic ->SetCurrentPosition (0);
	this->pWalkmusic ->SetCurrentPosition (0);
	this->pWarmusic ->SetCurrentPosition (0);
	this->pyudimusic ->SetCurrentPosition (0);
	this->pwinmusic ->SetCurrentPosition (0);
	this->plosemusic ->SetCurrentPosition (0);
	this->pAIAttacksound ->SetCurrentPosition (0);*/

}


void GameSound::GameSoundfmtSet(int channels,int SamplesPerSec,int wBitPerSample)
{
	memset(&this->pwfmt,0,sizeof(pwfmt));
	this->pwfmt .wFormatTag =WAVE_FORMAT_PCM;
	this->pwfmt .nChannels =channels;
	this->pwfmt .nSamplesPerSec =SamplesPerSec;
	this->pwfmt .wBitsPerSample =wBitPerSample;
	this->pwfmt .nBlockAlign =this->pwfmt .wBitsPerSample /8*this->pwfmt .nChannels ;
	this->pwfmt .nAvgBytesPerSec =this->pwfmt .nSamplesPerSec *this->pwfmt .nBlockAlign ;
	this->result =this->pMainBuf ->SetFormat (&this->pwfmt );
	if(this->result !=DS_OK)
		MessageBox(this->soundhwnd ,"�趨���Ÿ�ʽʧ�ܣ�",NULL,MB_OK);
}

void GameSound::GameSoundReadWAVfile ( char* filename,HMMIO& hmmbackground)
{
	hmmbackground=mmioOpen(filename,NULL,MMIO_ALLOCBUF|MMIO_READ);//���ļ�
	if(hmmbackground==NULL)
		MessageBox(this->soundhwnd ,"�ļ������ڣ�",NULL,MB_OK);
	//��������
	ckRiff.fccType =mmioFOURCC('W','A','V','E');//�趨�ļ�����
	mmresult=mmioDescend(hmmbackground,&ckRiff,NULL,MMIO_FINDRIFF);
	if(mmresult!=MMSYSERR_NOERROR)
		MessageBox(this->soundhwnd ,"��",NULL,MB_OK);
	ckInfo.ckid =mmioFOURCC('f','m','t',' ');//�趨��������
	mmresult=mmioDescend(hmmbackground,&ckInfo,&ckRiff,MMIO_FINDCHUNK);
	if(mmresult!=MMSYSERR_NOERROR)
		MessageBox(this->soundhwnd ,"�ļ���ʽ����",NULL,MB_OK);
	if(mmioRead(hmmbackground,(HPSTR)&swfmt,sizeof(swfmt))==-1)
		MessageBox(this->soundhwnd ,"��ȡ��ʽʧ�ܣ�",NULL,MB_OK);

	mmresult=mmioAscend(hmmbackground,&ckInfo,0);//����������
	//����������
	ckInfo.ckid =mmioFOURCC('d','a','t','a');
	mmresult=mmioDescend(hmmbackground,&ckInfo,&ckRiff,MMIO_FINDCHUNK);
	if(mmresult!=MMSYSERR_NOERROR)
		MessageBox(this->soundhwnd ,"�ļ���ʽ����",NULL,MB_OK);
	size=ckInfo.cksize ;

}
void GameSound::GameSoundReadinbuffer (LPDIRECTSOUNDBUFFER& buffer, char* filename)
{
	LPVOID pAudio;
	DWORD bytesAudio;

	this->GameSoundReadWAVfile (filename,this->hbackground );
	memset(&this->desc,0,sizeof(desc));//��սṹ����
	desc.dwSize =sizeof(desc);//���������ṹ��С
	desc.dwFlags =DSBCAPS_STATIC|DSBCAPS_CTRLPAN|DSBCAPS_CTRLVOLUME|DSBCAPS_GLOBALFOCUS;
	desc.dwBufferBytes =this->size ;
	desc.lpwfxFormat =&this->swfmt ;
	result=pDS->CreateSoundBuffer (&desc,&buffer,NULL);
	if(this->result !=DS_OK)
		MessageBox(this->soundhwnd ,"�����λ�������ʧ�ܣ�",NULL,MB_OK);
	result=buffer->Lock(0,this->size ,&pAudio,&bytesAudio,NULL,NULL,NULL);
	if(this->result !=DS_OK)
		MessageBox(this->soundhwnd ,"������������ʧ�ܣ�",NULL,MB_OK);
	this->mmresult =mmioRead(this->hbackground ,(HPSTR)pAudio,bytesAudio);
	if(mmresult==-1)
		MessageBox(this->soundhwnd ,"��ȡ�����ļ�����ʧ�ܣ�",NULL,MB_OK);
	this->result =buffer->Unlock (pAudio,bytesAudio,NULL,NULL);
	if(this->result !=DS_OK)
		MessageBox(this->soundhwnd ,"�������������ʧ�ܣ�",NULL,MB_OK);
	mmioClose(this->hbackground ,0);
}

void GameSound::GameMusicplay (LPDIRECTSOUNDBUFFER& buffer)
{
	if(enter.m_Backmusic )
	{
	    this->GameSoundAllstop ();
    	buffer->Play (0,0,1);
	}
}
void GameSound::GameSoundplay (LPDIRECTSOUNDBUFFER& buffer)
{
	buffer->Play (0,0,0);
}