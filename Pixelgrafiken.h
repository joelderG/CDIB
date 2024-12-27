
// Pixelgrafiken.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CPixelgrafikenApp:
// Siehe Pixelgrafiken.cpp für die Implementierung dieser Klasse
//

class CPixelgrafikenApp : public CWinApp
{
public:
	CPixelgrafikenApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CPixelgrafikenApp theApp;
