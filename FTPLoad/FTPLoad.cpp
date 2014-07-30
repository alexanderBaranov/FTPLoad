
// FTPLoad.cpp : Определяет поведение классов для приложения.
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


// создание CFTPLoadApp

CFTPLoadApp::CFTPLoadApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CFTPLoadApp

CFTPLoadApp theApp;


// инициализация CFTPLoadApp

BOOL CFTPLoadApp::InitInstance()
{
	CWinAppEx::InitInstance();

	// Стандартная инициализация
	// Если эти возможности не используются и необходимо уменьшить размер
	// конечного исполняемого файла, необходимо удалить из следующих
	// конкретных процедур инициализации, которые не требуются
	// Измените раздел реестра, в котором хранятся параметры
	// TODO: следует изменить эту строку на что-нибудь подходящее,
	// например на название организации
	//SetRegistryKey(_T("Локальные приложения, созданные с помощью мастера приложений"));

	CFTPLoadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "ОК"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Введите код для обработки закрытия диалогового окна
		//  с помощью кнопки "Отмена"
	}

	// Поскольку диалоговое окно закрыто, возвратите значение FALSE, чтобы можно было выйти из
	//  приложения вместо запуска генератора сообщений приложения.
	return FALSE;
}
