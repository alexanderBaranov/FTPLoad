#pragma once

#include "FTP.h"

class CLoadFileToFtp
{
public:

	CLoadFileToFtp();
	CLoadFileToFtp( 
		IN CString &strFileUpload,
		IN CString &strFTPUrl );

	~CLoadFileToFtp();

	void RunThread(
		IN CString &strFileUpload,
		IN CString &strFTPUrl,
		IN PPROGRESS_PARAMETER progress_param = NULL);
	void Wait();
	void Close();

	static void Work(
		IN CString &strFileUpload,
		IN CString &strFTPUrl,
		IN PPROGRESS_PARAMETER progress_param = NULL);

	CString m_strFileUpload;
	CString m_strFTPUrl;

protected:
	static DWORD WINAPI CallBackOfThread( LPVOID lpThreadParameter );

	HANDLE m_hThread;
	DWORD m_dwExitCode;

	CString m_strError;

	class CAuxParams
	{
	public:
		CAuxParams(
			IN CString &strFileUpload,
			IN CString &strFTPUrl,
			IN PPROGRESS_PARAMETER progress_param = NULL);

		~CAuxParams();

		CString m_strFileUpload;
		CString m_strFTPUrl;
		PPROGRESS_PARAMETER m_progress_param;
	};
};