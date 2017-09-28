// AVLView.h : interface of the CAVLView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVLVIEW_H__38E40091_A9AE_46F6_897C_6F7A575D1D64__INCLUDED_)
#define AFX_AVLVIEW_H__38E40091_A9AE_46F6_897C_6F7A575D1D64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAVLView : public CView
{
protected: // create from serialization only
	CAVLView();
	DECLARE_DYNCREATE(CAVLView)

// Attributes
public:
	CAVLDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVLView)
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
	virtual ~CAVLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAVLView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AVLView.cpp
inline CAVLDoc* CAVLView::GetDocument()
   { return (CAVLDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVLVIEW_H__38E40091_A9AE_46F6_897C_6F7A575D1D64__INCLUDED_)
