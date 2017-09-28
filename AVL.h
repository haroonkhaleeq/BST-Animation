// AVL.h : main header file for the AVL application
//

#if !defined(AFX_AVL_H__C24070AE_380E_4CD5_82B2_596E463BBA50__INCLUDED_)
#define AFX_AVL_H__C24070AE_380E_4CD5_82B2_596E463BBA50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAVLApp:
// See AVL.cpp for the implementation of this class
//

class CAVLApp : public CWinApp
{
public:
	CAVLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAVLApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVL_H__C24070AE_380E_4CD5_82B2_596E463BBA50__INCLUDED_)
