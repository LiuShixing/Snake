// SnakeView.h : interface of the CSnakeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SNAKEVIEW_H__B9C31FEC_A777_4B9D_B802_6635B0ED440D__INCLUDED_)
#define AFX_SNAKEVIEW_H__B9C31FEC_A777_4B9D_B802_6635B0ED440D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Bitmap.h"

class CSnakeView : public CView
{
protected: // create from serialization only
	CSnakeView();
	DECLARE_DYNCREATE(CSnakeView)

// Attributes
public:
	CSnakeDoc* GetDocument();
    
// Operations
public:
	void    Setinit();
    //һ�º���������ViewFunction.cpp
	void    InitBitmap(CDC *pDC,Bitmap &bitmap);
	void    PaintBitmap( Bitmap &myb,const BITMAP& bm,CSnakeView *pt,bool flage=true);
	void    PaintBitmap( Bitmap &myb, Bitmap &myb2,const BITMAP& bm,CSnakeView *pt);
	void    ChangeFocus(int k,Bitmap &bshow,bool flage=true);
    void    ChangeFocus(int k,Bitmap &bshow,Bitmap &bhide1,Bitmap &bhide2);
	int     JudgeMouse(const CPoint& point,bool flage); 
    void    JudgeHero(int);
	void    ShowHero();  //��ʾӢ�۰�
	void    GetBest(int mode);

	friend  class CEnter;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool    m_isdraw;//��ʼ��Ϊtrue
	bool    m_is;//��Ӧ��ʱ������  ��ʼ��Ϊfalse
	bool    m_isfirst;//�Ƿ��ǵ�һ��  ��ʼ��true
	int     m_be_or_qu;
    int     m_be_or_qu2; //���title��Ϊ����ǰ��������λ��  ��ʼ��Ϊ0(��ʼ��Ϸ)
	bool    m_title; //�������Ƿ���title  
	bool    m_title2;  //�ж�title�Ƿ������ӽ���  ��ʼ��Ϊfalse
	bool    m_title3;  //�ж�title�Ƿ���Ҫȥ������  ��ʼ��Ϊfalse
	Bitmap m_Bbackground;
	Bitmap m_Bbackground2;
	Bitmap m_Bbackground3;
	Bitmap m_Bbackground4;
	Bitmap m_Bbackground5;
	Bitmap m_Bbackground6;

	Bitmap m_Btitle28;

    Bitmap m_Bbegin28;
	Bitmap m_Bquit28;
	Bitmap m_Bset28;

	CRect    m_ShowScoce;
	CRect    m_BestScoce;

	CString  m_strscoce;
    CString  m_strbestscoce;

//	CButton m_btn;
	virtual ~CSnakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSnakeView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SnakeView.cpp
inline CSnakeDoc* CSnakeView::GetDocument()
   { return (CSnakeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKEVIEW_H__B9C31FEC_A777_4B9D_B802_6635B0ED440D__INCLUDED_)
