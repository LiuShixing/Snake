#if !defined(AFX_ENTER_H__584CBB41_EC57_4A49_9F0C_4ED0C2128557__INCLUDED_)
#define AFX_ENTER_H__584CBB41_EC57_4A49_9F0C_4ED0C2128557__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Enter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnter dialog

#define EASY     200
#define HARD     100
#define VERYHARD 50
#define MOST     30
#define SHANKS   1
#define SPACE    2
#define UNKOWN   3
#define SNAKEI   4
#define SNAKEII  5
class CEnter : public CDialog
{
// Construction
public:
	CEnter(CWnd* pParent = NULL);   // standard constructor
    int m_choose;    //选择模式
	int m_chooseBackground;  //首页背景
	bool m_Backmusic;
	bool m_BackmusicChoose;
// Dialog Data
	//{{AFX_DATA(CEnter)
	enum { IDD = IDD_DIALOG1 };
	int		m_EASY;
	int		m_Shanks;
	int		m_OPEN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnter)
	virtual void OnOK();
	afx_msg void OnEasy();
	afx_msg void OnHard();
	afx_msg void OnVeryhard();
	afx_msg void OnMost();
	afx_msg void OnShanks();
	afx_msg void OnSpace();
	afx_msg void OnUnkown();
	afx_msg void OnSnakeI();
	afx_msg void OnSnakeII();
	afx_msg void OnOpen();
	afx_msg void OnOff();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTER_H__584CBB41_EC57_4A49_9F0C_4ED0C2128557__INCLUDED_)
