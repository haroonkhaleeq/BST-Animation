// AVLDoc.cpp : implementation of the CAVLDoc class
//

#include "stdafx.h"
#include "AVL.h"

#include "AVLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAVLDoc

IMPLEMENT_DYNCREATE(CAVLDoc, CDocument)

BEGIN_MESSAGE_MAP(CAVLDoc, CDocument)
	//{{AFX_MSG_MAP(CAVLDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAVLDoc construction/destruction

CAVLDoc::CAVLDoc()
{
	// TODO: add one-time construction code here

}

CAVLDoc::~CAVLDoc()
{
}

BOOL CAVLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAVLDoc serialization

void CAVLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAVLDoc diagnostics

#ifdef _DEBUG
void CAVLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAVLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAVLDoc commands
