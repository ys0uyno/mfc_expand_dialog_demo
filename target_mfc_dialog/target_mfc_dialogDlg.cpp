
// target_mfc_dialogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "target_mfc_dialog.h"
#include "target_mfc_dialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctarget_mfc_dialogDlg dialog




Ctarget_mfc_dialogDlg::Ctarget_mfc_dialogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctarget_mfc_dialogDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctarget_mfc_dialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctarget_mfc_dialogDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_EXPAND_COLLAPSE, &Ctarget_mfc_dialogDlg::OnBnClickedButtonExpandCollapse)
	ON_BN_CLICKED(IDC_BUTTON_HIDED, &Ctarget_mfc_dialogDlg::OnBnClickedButtonHided)
END_MESSAGE_MAP()


// Ctarget_mfc_dialogDlg message handlers

BOOL Ctarget_mfc_dialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	GetWindowRect(&expand_crect);
	is_show = FALSE;
	OnBnClickedButtonExpandCollapse();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctarget_mfc_dialogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctarget_mfc_dialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctarget_mfc_dialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctarget_mfc_dialogDlg::OnBnClickedButtonExpandCollapse()
{
	// TODO: Add your control notification handler code here
	CButton *btn_Hide = (CButton *)GetDlgItem(IDC_BUTTON_EXPAND_COLLAPSE);
	btn_Hide->GetWindowRect(&collapse_crect);
	if (is_show == TRUE)
	{
		SetWindowPos(NULL, 0, 0, expand_crect.Width(), expand_crect.Height(),
			SWP_NOZORDER | SWP_NOMOVE);

		is_show = FALSE;
		this->SetDlgItemText(IDC_BUTTON_EXPAND_COLLAPSE, L"¦æ");
	}
	else
	{
		is_show = TRUE;
		SetWindowPos(NULL, 0, 0, expand_crect.Width(), expand_crect.Height() - 100, SWP_NOZORDER | SWP_NOMOVE);
		this->SetDlgItemText(IDC_BUTTON_EXPAND_COLLAPSE, L"¦ç");
	}
}


void Ctarget_mfc_dialogDlg::OnBnClickedButtonHided()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"ButtonHided click");
}
