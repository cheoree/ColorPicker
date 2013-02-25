// BaeTreeDlg.h : header file
//

#if !defined(AFX_BAETREEDLG_H__3B32032C_881B_4BB6_9663_D701E8DEAC2D__INCLUDED_)
#define AFX_BAETREEDLG_H__3B32032C_881B_4BB6_9663_D701E8DEAC2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CBaeTreeDlg dialog
#include "ShadowDlg.h"
class CBaeTreeDlg : public CDialog
{
// Construction
public:
	CBaeTreeDlg(CWnd* pParent = NULL);	// standard constructor
	void SetColor();
// Dialog Data
	//{{AFX_DATA(CBaeTreeDlg)
	enum { IDD = IDD_BAETREE_DIALOG };
	CEdit	m_editHtmlColor;
	CString	m_editColor;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaeTreeDlg)
	public:
	virtual BOOL DestroyWindow();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBaeTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnStart();
	afx_msg void OnChangeEdit1();
	afx_msg void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	RECT m_rect;
	bool m_bIn;
	bool m_bStartButton;
	ShadowDlg* m_dlgShadow;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
#endif // !defined(AFX_BAETREEDLG_H__3B32032C_881B_4BB6_9663_D701E8DEAC2D__INCLUDED_)
