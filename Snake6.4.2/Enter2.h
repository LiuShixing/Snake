#if !defined(AFX_ENTER2_H__9DBDC443_A326_4B3A_89C6_CD2D14376A55__INCLUDED_)
#define AFX_ENTER2_H__9DBDC443_A326_4B3A_89C6_CD2D14376A55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Enter2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Enter2 dialog

class Enter2 : public CDialog
{
// Construction
public:
	Enter2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Enter2)
	enum { IDD = IDD_DIALOG2 };
	CString	m_NAME1;
	CString	m_NAME2;
	CString	m_NAME3;
	CString	m_NAME4;
	CString	m_MARK1;
	CString	m_MARK2;
	CString	m_MARK3;
	CString	m_MARK4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Enter2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Enter2)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTER2_H__9DBDC443_A326_4B3A_89C6_CD2D14376A55__INCLUDED_)
