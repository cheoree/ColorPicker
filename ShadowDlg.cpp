// ShadowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaeTree.h"
#include "ShadowDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WS_EX_LAYERED 0x00080000
#define LWA_ALPHA     0x00000002
/////////////////////////////////////////////////////////////////////////////
// ShadowDlg dialog


ShadowDlg::ShadowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ShadowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ShadowDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ShadowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShadowDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ShadowDlg, CDialog)
	//{{AFX_MSG_MAP(ShadowDlg)
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ShadowDlg message handlers

BOOL ShadowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ShadowDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	typedef BOOL(WINAPI *SLWA)(HWND, COLORREF, BYTE, DWORD);
	SLWA pSetLayeredWindowAttributes = NULL;
	HINSTANCE hmodUSER32 = LoadLibrary("USER32.DLL");
	pSetLayeredWindowAttributes = (SLWA)GetProcAddress(hmodUSER32,"SetLayeredWindowAttributes");
	HWND hwnd = this->m_hWnd; 
	SetWindowLong(hwnd, GWL_EXSTYLE,GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	
	if(nState == 0)
	{
		// 가려질 때
		pSetLayeredWindowAttributes(hwnd, 0, (255 * 0) / 100, LWA_ALPHA);
	}
	else if(nState == 1)
	{
		//기본
		pSetLayeredWindowAttributes(hwnd, 0, (255 * 1) / 100, LWA_ALPHA);	
	}
	else if(nState == 2)
	{
		// 튀어나올때 
		pSetLayeredWindowAttributes(hwnd, 0, (255 * 0) / 100, LWA_ALPHA);	
	}
	CDialog::OnActivate(nState, pWndOther, bMinimized);	
	
	// TODO: Add your message handler code here
	
}
