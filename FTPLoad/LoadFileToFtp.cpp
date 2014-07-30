#include "stdafx.h"
#include "LoadFileToFtp.h"

//CLoadFileToFtp

CLoadFileToFtp::CLoadFileToFtp()
{
}

CLoadFileToFtp::CLoadFileToFtp(
	IN CString &strFileUpload, 
	IN CString &strFTPUrl)
{
	m_hThread = NULL;
	m_dwExitCode = (DWORD)-1;

	m_strFileUpload = strFileUpload;
	m_strFTPUrl = strFTPUrl;
}

CLoadFileToFtp::~CLoadFileToFtp()
{
	Close();
}

void CLoadFileToFtp::Close()
{
	if( m_hThread )
	{
		TerminateThread( m_hThread, 0 );
		CloseHandle( m_hThread );
		m_hThread = NULL;
	}

	return;
}

void CLoadFileToFtp::RunThread(
		IN CString &strFileUpload,
		IN CString &strFTPUrl,
		IN PPROGRESS_PARAMETER progress_param)
{
	USES_CONVERSION;
	DWORD dwThreadId;

	ATLASSERT(m_strFileUpload);
	ATLASSERT(m_strFTPUrl);

	CAuxParams *pAuxParams = new CAuxParams( strFileUpload, strFTPUrl, progress_param);

	m_hThread = CreateThread( NULL, 0, CallBackOfThread, pAuxParams, 0, &dwThreadId );

	if( !m_hThread || m_hThread == INVALID_HANDLE_VALUE )
	{
		m_hThread = NULL;

		CString strError;
		strError.AppendFormat(_T("%d"), GetLastError());
		if(progress_param)
		{
			progress_param->strError = strError;
		}
		else
		{
			throw std::exception(T2A(strError.GetString()));
		}
	}
}

DWORD WINAPI CLoadFileToFtp::CallBackOfThread( LPVOID lpThreadParameter )
{
	CAuxParams *pAuxParams = reinterpret_cast<CAuxParams *>( lpThreadParameter );

	CString sError;

	Work(pAuxParams->m_strFileUpload, pAuxParams->m_strFTPUrl, pAuxParams->m_progress_param);

	return 0;
}

void CLoadFileToFtp::Work(
		IN CString &strFileUpload,
		IN CString &strFTPUrl,
		IN PPROGRESS_PARAMETER progress_param)
{
	CFTP cFtp;
	cFtp.LoadFileToFTP(strFileUpload, strFTPUrl, progress_param);
} 

CLoadFileToFtp::CAuxParams::CAuxParams(
	IN CString &strFileUpload,
	IN CString &strFTPUrl,
	IN PPROGRESS_PARAMETER progress_param)
{
	m_strFileUpload = strFileUpload;
	m_strFTPUrl = strFTPUrl;
	m_progress_param = progress_param;
}

CLoadFileToFtp::CAuxParams::~CAuxParams()
{
}