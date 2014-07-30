#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "LoadFileToFtp.h"
//#include "afxwin.h"

// ���������� ���� CProgressDlg

class CProgressDlg : public CDialog
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // ����������� �����������
	CProgressDlg(
		IN CString strFileUpload,
		IN CString strFTPUrl);

	virtual ~CProgressDlg();

// ������ ����������� ����
	enum { IDD = IDD_PROGRESS };

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCancel();

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_cProgressCtrl;
	CEdit m_editFileSizeUpload;

	CString m_strFileUpload;
	CString m_strFTPUrl;

	CLoadFileToFtp m_cLoadFile;
	PROGRESS_PARAMETER m_progress_param;
};
