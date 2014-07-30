
// FTPLoad.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "FTPLoad.h"
#include "FTPLoadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTPLoadApp

BEGIN_MESSAGE_MAP(CFTPLoadApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// �������� CFTPLoadApp

CFTPLoadApp::CFTPLoadApp()
{
	// TODO: �������� ��� ��������,
	// ��������� ���� ������ ��� ������������� � InitInstance
}


// ������������ ������ CFTPLoadApp

CFTPLoadApp theApp;


// ������������� CFTPLoadApp

BOOL CFTPLoadApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// ����������� �������������
	// ���� ��� ����������� �� ������������ � ���������� ��������� ������
	// ��������� ������������ �����, ���������� ������� �� ���������
	// ���������� �������� �������������, ������� �� ���������
	// �������� ������ �������, � ������� �������� ���������
	// TODO: ������� �������� ��� ������ �� ���-������ ����������,
	// �������� �� �������� �����������
	//SetRegistryKey(_T("��������� ����������, ��������� � ������� ������� ����������"));

	CFTPLoadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "��"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "������"
	}

	// ��������� ���������� ���� �������, ���������� �������� FALSE, ����� ����� ���� ����� ��
	//  ���������� ������ ������� ���������� ��������� ����������.
	return FALSE;
}
