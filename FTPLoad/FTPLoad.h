
// FTPLoad.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CFTPLoadApp:
// О реализации данного класса см. FTPLoad.cpp
//

class CFTPLoadApp : public CWinAppEx
{
public:
	CFTPLoadApp();

// Переопределение
	public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CFTPLoadApp theApp;