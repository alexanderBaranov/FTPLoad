#include "stdafx.h"
#include "resource.h"

#include "FTP.h"
#include <sys/stat.h>

//CFTP

CFTP::CFTP()
{
	m_curl = curl_easy_init();
}

CFTP::~CFTP()
{
	curl_easy_cleanup(m_curl);
}

void CFTP::LoadFileToFTP(
	CString &strFileUpload, 
	CString &strFTPUrl, 
	PPROGRESS_PARAMETER progress_param)
{
	USES_CONVERSION;

	CString sFileName = strFileUpload.Right(strFileUpload.GetLength() - strFileUpload.ReverseFind('\\')-1);

	if(strFTPUrl.Right(1) != _T("/"))
	{
		strFTPUrl.Append(_T("/"));
	}

	strFTPUrl.Append(sFileName);

    CURLcode res;

	char chErrorBuffer[CURLOPT_ERRORBUFFER];
	memset(chErrorBuffer, 0, CURLOPT_ERRORBUFFER);
	curl_easy_setopt(m_curl, CURLOPT_ERRORBUFFER, chErrorBuffer);

	CString strError;

	if( m_curl )
    {
		FILE *pFile = fopen(W2A(strFileUpload.GetString()), "rb");
		if(pFile)
		{
			struct stat file_info;
			curl_off_t fsize;

			stat(W2A(strFileUpload.GetString()), &file_info);
			fsize = (curl_off_t)file_info.st_size;

			curl_easy_setopt(m_curl, CURLOPT_UPLOAD, 1L);
			curl_easy_setopt(m_curl, CURLOPT_READDATA, pFile);
			curl_easy_setopt(m_curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)fsize);
			curl_easy_setopt(m_curl, CURLOPT_URL, T2A(strFTPUrl.GetString()));
			curl_easy_setopt(m_curl, CURLOPT_FTP_CREATE_MISSING_DIRS, 1L);
			curl_easy_setopt(m_curl, CURLOPT_READFUNCTION, read_callback);
			curl_easy_setopt(m_curl, CURLOPT_PROGRESSFUNCTION, CallbackProgress );
			curl_easy_setopt(m_curl, CURLOPT_NOPROGRESS, FALSE);
			curl_easy_setopt(m_curl, CURLOPT_PROGRESSDATA, progress_param);
			
			if(progress_param)
			{
				progress_param->statUpload = STATUS_UPLOAD_IS_DOOWNLOADING;
			}

			res = curl_easy_perform(m_curl);

			if(progress_param)
			{
				progress_param->statUpload = STATUS_UPLOAD_IS_COMPLETE;
			}

			fclose(pFile);
		}
		else
		{
			strError.LoadString(IDS_FILE_NOT_LOAD);
		}
	}

	if( (CURLE_OK != res) || strError.GetLength())
	{
		char *chErr;
		if(strError.GetLength())
		{
			chErr = T2A(strError.GetString());
		}
		else
		{
			chErr = strcat((char*)curl_easy_strerror(res), ".\n");
			chErr = strcat(chErr, chErrorBuffer);
		}

		if(progress_param)
		{
			progress_param->statUpload = STATUS_UPLOAD_ERROR;
			progress_param->strError = A2T(chErr);
		}
		else
		{
			throw std::exception(chErr);
		}
	}
}

size_t CFTP::read_callback(
	void *ptr, 
	size_t size, 
	size_t nmemb, 
	void *stream)
{
  curl_off_t nread;
  size_t retcode = fread(ptr, size, nmemb, (FILE *)stream);
  nread = (curl_off_t)retcode;

  double fg = nread;
 
  return retcode;
}

int CFTP::CallbackProgress( 
	void *ptr, 
	double t, 
	double d, 
	double ultotal, 
	double ulnow )
{
	if(ptr)
	{
		PPROGRESS_PARAMETER progress_param = (PPROGRESS_PARAMETER)ptr;
		progress_param->dblNowProgress = ulnow;
		progress_param->dblTotalProgress = ultotal;
	}
    return  0;
}