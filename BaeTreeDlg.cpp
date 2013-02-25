// BaeTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BaeTree.h"
#include "BaeTreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaeTreeDlg dialog

CBaeTreeDlg::CBaeTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBaeTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaeTreeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaeTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaeTreeDlg)
	DDX_Control(pDX, IDC_EDIT1, m_editHtmlColor);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBaeTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CBaeTreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, OnStart)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaeTreeDlg message handlers

BOOL CBaeTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetWindowPos(&wndTopMost,0,0,0,0,SWP_SHOWWINDOW|SWP_NOSIZE|SWP_NOMOVE);
	m_bStartButton = false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBaeTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBaeTreeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBaeTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBaeTreeDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if( !m_bStartButton ) {
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x,point.y));
		CDialog::OnLButtonDown(nFlags, point);
		return;
	}
	CPoint pt;
	char str[10];
	COLORREF c;
	CString strColor;
	HDC hDC;
	short r,g,b;

	hDC = CreateDC("DISPLAY",0,0,0);
	GetCursorPos(&pt);
	c = GetPixel(hDC,pt.x,pt.y);
	r = GetRValue(c);
	g = GetGValue(c);
	b = GetBValue(c);
	
	sprintf(str,"%02x%02x%02x",r,g,b);
	strupr(str);

	if (c == 0) { 
		strcpy(str,"000000");
		r = 0; g = 0; b = 0;
	}
	strColor = "#";
	strColor += str;

	m_editHtmlColor.SetWindowText(strColor);
	ReleaseCapture();
	//SetCapture();
	
	DeleteDC(hDC);

	CRect       rect;
	CDC* pDC = GetDC();

	CBrush      brush(RGB(r, g, b));

	GetClientRect(&rect);
	rect.left = 3;
	rect.right = rect.left + 67;
	rect.top = 3;
	rect.bottom = rect.top + 67;
	pDC->FillRect(&rect, &brush);

	ReleaseDC(pDC);

	m_bStartButton = false;

	
	if( m_dlgShadow ) {
		m_dlgShadow->DestroyWindow();
		delete m_dlgShadow;
		m_dlgShadow = NULL;
	}

	CDialog::OnLButtonDown(nFlags, pt);
}

BOOL CBaeTreeDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if( pMsg->message == WM_KEYDOWN ) {
		if( pMsg->wParam == VK_RETURN ) SetColor();
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CBaeTreeDlg::OnOK()
{
}

short Hex2Dec( char ch )
{
	short rtn;
	switch( ch ) {
	case 0x30 : rtn = 0;break;
	case 0x31 : rtn = 1;break;
	case 0x32 : rtn = 2;break;
	case 0x33 : rtn = 3;break;
	case 0x34 : rtn = 4;break;
	case 0x35 : rtn = 5;break;
	case 0x36 : rtn = 6;break;
	case 0x37 : rtn = 7;break;
	case 0x38 : rtn = 8;break;
	case 0x39 : rtn = 9;break;
	case 0x65 : 
	case 0x97 : rtn = 10;break;
	case 0x66 : 
	case 0x98 : rtn = 11;break;
	case 0x67 : 
	case 0x99 : rtn = 12;break;
	case 0x68 : 
	case 0x100 : rtn = 13;break;
	case 0x69 : 
	case 0x101 : rtn = 14;break;
	case 0x70 : 
	case 0x102 : rtn = 15;break;
	}
	return rtn;
}

void CBaeTreeDlg::SetColor()
{
	char szR[4] = {0};
	char szG[4] = {0};
	char szB[4] = {0};
	char szc[8] = {0};

	m_editHtmlColor.GetWindowText( szc, 7 );

	short r = Hex2Dec(szc[1]) * 16 + Hex2Dec(szc[2]);
	short g = Hex2Dec(szc[3]) * 16 + Hex2Dec(szc[4]);
	short b = Hex2Dec(szc[5]) * 16 + Hex2Dec(szc[6]);

	CRect       rect;
	CDC* pDC = GetDC();

	CBrush      brush(RGB(r, g, b));

	GetClientRect(&rect);
	rect.left = 3;
	rect.right = rect.left + 80;
	rect.top = 3;
	rect.bottom = rect.top + 80;
	pDC->FillRect(&rect, &brush);	
}

BOOL CBaeTreeDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if( m_dlgShadow ) {
		m_dlgShadow->DestroyWindow();
		delete m_dlgShadow;
	}
	return CDialog::DestroyWindow();
}

BOOL CBaeTreeDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if( m_bStartButton ) {
		HCURSOR hCursor;

		hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		SetCursor(hCursor);
		
		return TRUE;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CBaeTreeDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if( m_bStartButton ) {
		HCURSOR hCursor;

		hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		SetCursor(hCursor);
		
	
	}
	// TODO: Add your message handler code here and/or call default
	if( m_bStartButton ) {
		ClientToScreen(&point);
		m_dlgShadow->SetWindowPos( this, point.x-5, point.y-5, 0, 0, SWP_NOSIZE);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CBaeTreeDlg::OnStart() 
{
	RECT rt;

	rt.left = 0;
	rt.right = 10;
	rt.top = 0;
	rt.bottom = 10;

	m_dlgShadow = new ShadowDlg;
	m_dlgShadow->Create( IDD_SHADOW_DIALOG, this );
	m_dlgShadow->ShowWindow( SW_SHOW );

	m_bStartButton = true;
	SetCapture();
}

 

void CBaeTreeDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here	
}
