
// FTPLoad.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CFTPLoadApp:
// � ���������� ������� ������ ��. FTPLoad.cpp
//

class CFTPLoadApp : public CWinAppEx
{
public:
	CFTPLoadApp();

// ���������������
	public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CFTPLoadApp theApp;