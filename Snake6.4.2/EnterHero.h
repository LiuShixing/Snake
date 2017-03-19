#if !defined(AFX_ENTERHERO_H__B81B91C2_18F2_4A06_869D_35FE06D1AA58__INCLUDED_)
#define AFX_ENTERHERO_H__B81B91C2_18F2_4A06_869D_35FE06D1AA58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterHero.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// EnterHero dialog

class EnterHero : public CDialog
{
// Construction
public:
	EnterHero(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(EnterHero)
	enum { IDD = IDD_GETNAME };
	CString	m_NAME;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EnterHero)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(EnterHero)
	afx_msg void OnUpdateName();
	afx_msg void OnChangeName();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERHERO_H__B81B91C2_18F2_4A06_869D_35FE06D1AA58__INCLUDED_)
