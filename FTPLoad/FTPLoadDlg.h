
// FTPLoadDlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CFTPLoadDlg
class CFTPLoadDlg : public CDialog
{
// ��������
public:
	CFTPLoadDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_FTPLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnUpload();
	afx_msg void OnBnClickedBtnBrows();
protected:
	CEdit m_editFileUpload;
	CEdit m_editFTPUrl;
public:
	afx_msg void OnBnClickedCancel();
};
