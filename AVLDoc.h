// AVLDoc.h : interface of the CAVLDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AVLDOC_H__BE168749_8ED0_4679_B205_3CADF1FFDA4F__INCLUDED_)
#define AFX_AVLDOC_H__BE168749_8ED0_4679_B205_3CADF1FFDA4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAVLDoc : public CDocument
{
protected: // create from serialization only
	CAVLDoc();
	DECLARE_DYNCREATE(CAVLDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVLDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAVLDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAVLDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVLDOC_H__BE168749_8ED0_4679_B205_3CADF1FFDA4F__INCLUDED_)
