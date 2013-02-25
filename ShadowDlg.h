#if !defined(AFX_SHADOWDLG_H__30D623A5_C655_41A0_BAF4_743B2FC4F56A__INCLUDED_)
#define AFX_SHADOWDLG_H__30D623A5_C655_41A0_BAF4_743B2FC4F56A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShadowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ShadowDlg dialog

class ShadowDlg : public CDialog
{
// Construction
public:
	ShadowDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ShadowDlg)
	enum { IDD = IDD_SHADOW_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShadowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ShadowDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHADOWDLG_H__30D623A5_C655_41A0_BAF4_743B2FC4F56A__INCLUDED_)
