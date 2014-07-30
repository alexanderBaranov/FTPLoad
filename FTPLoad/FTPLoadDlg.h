
// FTPLoadDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CFTPLoadDlg
class CFTPLoadDlg : public CDialog
{
// Создание
public:
	CFTPLoadDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_FTPLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
