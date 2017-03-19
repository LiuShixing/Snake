// Bitmap.h: interface for the Bitmap class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAP_H__74A1E1AC_6342_404F_972E_343BA5748370__INCLUDED_)
#define AFX_BITMAP_H__74A1E1AC_6342_404F_972E_343BA5748370__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Bitmap  
{
public:
	Bitmap();
	void SetMyBitmap(int x,int y,int id)
	{
		m_location.x=x;
		m_location.y=y;
		m_ID=id;
	}
	virtual ~Bitmap();
public:
	CBitmap m_bitmap;
	CPoint  m_location;
	CDC     m_BITMAP;
	int     m_ID;
};

#endif // !defined(AFX_BITMAP_H__74A1E1AC_6342_404F_972E_343BA5748370__INCLUDED_)
