#pragma once

#include <curl/curl.h>

enum STATUS_UPLOAD
{
	STATUS_UPLOAD_IS_NONE,
	STATUS_UPLOAD_IS_DOOWNLOADING,
	STATUS_UPLOAD_IS_COMPLETE,
	STATUS_UPLOAD_ERROR
};

typedef struct _PROGRESS_PARAMETER
{
	double dblNowProgress;
	double dblTotalProgress;
	
	STATUS_UPLOAD statUpload;

	CString strError;
}*PPROGRESS_PARAMETER, PROGRESS_PARAMETER;

class CFTP
{
public:
	CFTP();
	~CFTP();

	void LoadFileToFTP( 
		IN CString &strFileUpload,
		IN CString &strFTPUrl,
		IN PPROGRESS_PARAMETER progress_param = NULL);

private:
	CURL *m_curl;

	static size_t read_callback(
		void *ptr, 
		size_t size, 
		size_t nmemb, 
		void *stream);

	static int CallbackProgress( 
		void *ptr, 
		double t, 
		double d, 
		double ultotal, 
		double ulnow );

};