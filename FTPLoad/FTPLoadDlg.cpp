
// FTPLoadDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "FTPLoad.h"
#include "FTPLoadDlg.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CFTPLoadDlg




CFTPLoadDlg::CFTPLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFTPLoadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTPLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILE_TO_UPLOAD, m_editFileUpload);
	DDX_Control(pDX, IDC_FTP_URL, m_editFTPUrl);
}

BEGIN_MESSAGE_MAP(CFTPLoadDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CFTPLoadDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_UPLOAD, &CFTPLoadDlg::OnBnClickedBtnUpload)
	ON_BN_CLICKED(IDC_BTN_BROWS, &CFTPLoadDlg::OnBnClickedBtnBrows)
	ON_BN_CLICKED(IDCANCEL, &CFTPLoadDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

// ����������� ��������� CFTPLoadDlg

BOOL CFTPLoadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CFTPLoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CFTPLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFTPLoadDlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	OnOK();
}

void CFTPLoadDlg::OnBnClickedBtnUpload()
{
	CString strFileUpload;
	m_editFileUpload.GetWindowText(strFileUpload);
	
	if(!PathFileExists(strFileUpload))
	{
		CString strRes;
		strRes.LoadString(IDS_FILE_NOT_FOUND);
		MessageBox(strRes.GetString(), 0, MB_ICONWARNING);
		return;
	}

	CString strFTPUrl;
	m_editFTPUrl.GetWindowText(strFTPUrl);

	CProgressDlg progressDlg(strFileUpload,
		/*_T("ftp://ftp.intel.com/Pub/Incoming/")*/strFTPUrl);
	progressDlg.DoModal();
}

void CFTPLoadDlg::OnBnClickedBtnBrows()
{
	CFileDialog FindFileMsg( TRUE);

    if ( FindFileMsg.DoModal() == IDOK )
    {
		m_editFileUpload.SetWindowText( FindFileMsg.GetPathName());
        //UpdateData( FALSE );
    }
}

void CFTPLoadDlg::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	OnCancel();
}
