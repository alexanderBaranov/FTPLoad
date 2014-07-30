
// FTPLoadDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "FTPLoad.h"
#include "FTPLoadDlg.h"
#include "ProgressDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CFTPLoadDlg




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

// обработчики сообщений CFTPLoadDlg

BOOL CFTPLoadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CFTPLoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CFTPLoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFTPLoadDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
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
	// TODO: добавьте свой код обработчика уведомлений
	OnCancel();
}
