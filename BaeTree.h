// BaeTree.h : main header file for the BAETREE application
//

#if !defined(AFX_BAETREE_H__09718629_ABF9_4670_B5A9_33B06257ED7C__INCLUDED_)
#define AFX_BAETREE_H__09718629_ABF9_4670_B5A9_33B06257ED7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaeTreeApp:
// See BaeTree.cpp for the implementation of this class
//

class CBaeTreeApp : public CWinApp
{
public:
	CBaeTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaeTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBaeTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAETREE_H__09718629_ABF9_4670_B5A9_33B06257ED7C__INCLUDED_)
