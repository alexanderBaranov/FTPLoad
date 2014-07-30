// CProgressDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "FTPLoad.h"
#include "ProgressDlg.h"

// диалоговое окно CProgressDlg

IMPLEMENT_DYNAMIC(CProgressDlg, CDialog)

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgressDlg::IDD, pParent)
{

}

CProgressDlg::CProgressDlg(
		IN CString strFileUpload,
		IN CString strFTPUrl)
		: CDialog(CProgressDlg::IDD)
{
	m_strFileUpload = strFileUpload;
	m_strFTPUrl = strFTPUrl;

	m_cLoadFile.m_strFileUpload = strFileUpload;
	m_cLoadFile.m_strFTPUrl = strFTPUrl;
	
	PROGRESS_PARAMETER temp = {};
	m_progress_param = temp;
}

CProgressDlg::~CProgressDlg()
{
	m_cLoadFile.Close();

	if(m_progress_param.statUpload == STATUS_UPLOAD_ERROR)
	{
		MessageBox(m_progress_param.strError, 0, MB_ICONERROR);
	}
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_cProgressCtrl);
	DDX_Control(pDX, IDC_EDIT_FILE_SIZE_UPLOAD, m_editFileSizeUpload);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// обработчики сообщений CProgressDlg

BOOL CProgressDlg::OnInitDialog()
{
	USES_CONVERSION;
	CDialog::OnInitDialog();

	SetTimer(NULL, NULL, NULL);
	m_cLoadFile.RunThread(m_strFileUpload, m_strFTPUrl, &m_progress_param);

	return TRUE;
}

afx_msg void CProgressDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(m_progress_param.statUpload == STATUS_UPLOAD_IS_DOOWNLOADING)
	{
		m_cProgressCtrl.SetRange32(0, m_progress_param.dblTotalProgress);
		m_cProgressCtrl.SetPos(m_progress_param.dblNowProgress);

		CString strStatFileSizeUpload;
		strStatFileSizeUpload.AppendFormat(
			IDS_STATUS_FILE_SIZE_UPLOAD, 
			(int)m_progress_param.dblNowProgress/(1000 * 1000),
			(int)m_progress_param.dblTotalProgress/(1000 * 1000));

		m_editFileSizeUpload.SetWindowText(strStatFileSizeUpload);

	}
	else if((m_progress_param.statUpload == STATUS_UPLOAD_IS_COMPLETE) ||
			(m_progress_param.statUpload == STATUS_UPLOAD_ERROR))
	{
		OnBnClickedCancel();
	}

	CDialog::OnTimer(nIDEvent);
}

void CProgressDlg::OnBnClickedCancel()
{
	OnCancel();
}
