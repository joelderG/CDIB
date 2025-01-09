
// PixelgrafikenDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "Pixelgrafiken.h"
#include "PixelgrafikenDlg.h"
#include "afxdialogex.h"
#include "QualityDlg.h"
#include "BlendingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPixelgrafikenDlg-Dialogfeld



CPixelgrafikenDlg::CPixelgrafikenDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PIXELGRAFIKEN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPixelgrafikenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPixelgrafikenDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_MenuLaden, &CPixelgrafikenDlg::OnMenuladen)
	ON_COMMAND(ID_MenuSpeichern, &CPixelgrafikenDlg::OnMenuspeichern)
	ON_COMMAND(ID_MenuAufhellen, &CPixelgrafikenDlg::OnMenuaufhellen)
	ON_COMMAND(ID_MenuAbdunkeln, &CPixelgrafikenDlg::OnMenuabdunkeln)
	ON_COMMAND(ID_MenuGraustufen, &CPixelgrafikenDlg::OnMenugraustufen)
	ON_COMMAND(ID_MenuNegativ, &CPixelgrafikenDlg::OnMenunegativ)
	ON_COMMAND(ID_MenuKontrast, &CPixelgrafikenDlg::OnMenukontrast)
	ON_COMMAND(ID_MenuBlending, &CPixelgrafikenDlg::OnMenublending)
	ON_COMMAND(ID_MenuHistogramm, &CPixelgrafikenDlg::OnMenuhistogramm)
	ON_COMMAND(ID_MenuRotebene, &CPixelgrafikenDlg::OnMenurotebene)
	ON_COMMAND(32800, &CPixelgrafikenDlg::On32800)
	ON_COMMAND(ID_MenuBlauebene, &CPixelgrafikenDlg::OnMenublauebene)
	ON_COMMAND(ID_MenuSchaerfe, &CPixelgrafikenDlg::OnMenuschaerfe)
	ON_COMMAND(ID_MenuUnschaerfe, &CPixelgrafikenDlg::OnMenuunschaerfe)
	ON_COMMAND(ID_MenuEmboss, &CPixelgrafikenDlg::OnMenuemboss)
	ON_COMMAND(ID_MenuKantenerkennung, &CPixelgrafikenDlg::OnMenukantenerkennung)
	ON_COMMAND(ID_MenuRelief, &CPixelgrafikenDlg::OnMenurelief)
	ON_COMMAND(ID_MenuFlipHori, &CPixelgrafikenDlg::OnMenufliphori)
	ON_COMMAND(ID_MenuFlipVerti, &CPixelgrafikenDlg::OnMenuflipverti)
END_MESSAGE_MAP()


// CPixelgrafikenDlg-Meldungshandler

BOOL CPixelgrafikenDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CPixelgrafikenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CPixelgrafikenDlg::OnPaint()
{
	CPaintDC dc(this); // Gerätekontext zum Zeichnen
	if (IsIconic())
	{	
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		m_dib.Draw(&dc, 0, 0);

		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CPixelgrafikenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPixelgrafikenDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	//CClientDC dc(this);

	//// TODO: Fügen Sie hier Ihren Meldungshandlercode ein, und/oder benutzen Sie den Standard.
	//BYTE* p = (BYTE*) m_dib.GetPixelAddress(point.x, point.y);
	//if (p) {
	//	p[0] = p[1] = p[2] = 0;
	//	m_dib.Draw(&dc, 0, 0);
	//	m_dib.Save(L"test.bmp");
	//}
	CDialogEx::OnMouseMove(nFlags, point);
}

void CPixelgrafikenDlg::LoadFile()
{
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		L"Image Files (*.bmp;*.jpg;*.jpeg)|*.bmp;*.jpg;*.jpeg|All Files (*.*)|*.*||");

	if (dlg.DoModal() == IDOK)
	{
		CString ext = dlg.GetFileExt().MakeLower();
		bool loadSuccess = false;

		if (ext == L"bmp")
			loadSuccess = m_dib.Load(dlg.GetPathName());
		else if (ext == L"jpg" || ext == L"jpeg")
			loadSuccess = m_dib.LoadJpeg(dlg.GetPathName());

		if (!loadSuccess)
		{
			AfxMessageBox(L"Fehler beim Laden der Bilddatei!");
			return;
		}

		// Fenster neu zeichnen um das Bild anzuzeigen
		Invalidate();
	}
}

void CPixelgrafikenDlg::SaveFile()
{
	if (m_dib.DibWidth() == 0 || m_dib.DibHeight() == 0)
	{
		AfxMessageBox(L"Kein Bild geladen!");
		return;
	}

	CFileDialog dlg(FALSE, L"bmp", NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"Bitmap Files (*.bmp)|*.bmp|JPEG Files (*.jpg)|*.jpg||");

	if (dlg.DoModal() == IDOK)
	{
		CString ext = dlg.GetFileExt().MakeLower();
		bool saveSuccess = false;

		if (ext == L"bmp")
		{
			saveSuccess = m_dib.Save(dlg.GetPathName());
		}
		else if (ext == L"jpg")
		{
			QualityDlg qualityDlg(this);
			if (qualityDlg.DoModal() == IDOK)
			{
				int quality = qualityDlg.GetQuality();
				saveSuccess = m_dib.SaveJpeg(dlg.GetPathName(), quality);
			}
		}

		if (!saveSuccess)
		{
			AfxMessageBox(L"Fehler beim Speichern der Datei!");
		}
	}
}

void CPixelgrafikenDlg::OnMenuladen()
{
	LoadFile();
	RedrawWindow();	// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuspeichern()
{
	SaveFile();
}


void CPixelgrafikenDlg::OnMenuaufhellen()
{
	m_dib.brighten(10); // Aufhellen um 10 Prozent 
	RedrawWindow();     // sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuabdunkeln()
{
	m_dib.darken(-10); // Abdunkeln um 10 Prozent 
	RedrawWindow();     // sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenugraustufen()
{
	m_dib.grey();		// graustufen erstellen
	RedrawWindow();     // sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenunegativ()
{
	m_dib.negative();	// negativ erstellen
	RedrawWindow();     // sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenukontrast()
{
	m_dib.contrast(1.2f);	// Kontrast erhöhen
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenublending()
{
	if (m_dib.DibWidth() == 0 || m_dib.DibHeight() == 0)
	{
		AfxMessageBox(L"Kein Ausgangsbild geladen!");
		return;
	}

	// Zweites Bild laden
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
		L"Image Files (*.bmp;*.jpg;*.jpeg)|*.bmp;*.jpg;*.jpeg|All Files (*.*)|*.*||");

	m_dibSave.Load(L"bild.bmp");
	m_dibSave.flip('v');

	if (dlg.DoModal() == IDOK)
	{
		CString ext = dlg.GetFileExt().MakeLower();
		bool loadSuccess = false;

		// Temporäres Bild laden
		if (ext == L"bmp")
			loadSuccess = m_dibTemp.Load(dlg.GetPathName());
		else if (ext == L"jpg" || ext == L"jpeg")
			loadSuccess = m_dibTemp.LoadJpeg(dlg.GetPathName());

		if (!loadSuccess)
		{
			AfxMessageBox(L"Fehler beim Laden des zweiten Bildes!");
			return;
		}

		// Prüfen ob die Bilder die gleiche Größe haben
		if (m_dibSave.DibWidth() != m_dibTemp.DibWidth() ||
			m_dibSave.DibHeight() != m_dibTemp.DibHeight())
		{
			AfxMessageBox(L"Die Bilder müssen die gleiche Größe haben!");
			return;
		}

		// Blending-Dialog anzeigen und den Zeiger auf das Hauptdialogfenster übergeben
		BlendingDlg dlgBlend(this, this);
		if (dlgBlend.DoModal() == IDOK)
		{
			// Blending auf das Bild anwenden und das Bild neu zeichnen
			m_dib.blending(m_dibSave, m_dibTemp, dlgBlend.GetBlendValue());
			Invalidate();  // Bild neu zeichnen
		}
	}
}


void CPixelgrafikenDlg::OnMenuhistogramm()
{
	draw_histogramm();
}

void CPixelgrafikenDlg::draw_histogramm() {
	float h[256] = { 0.f };
	int x = 10, y = 105;
	CClientDC dc(this);
	m_dib.histogramm(h, 20.f);
	dc.MoveTo(x, y);
	dc.LineTo(x + 255 + 2, y);
	dc.LineTo(x + 255 + 2, y - 101);
	dc.LineTo(x, y - 101);
	dc.LineTo(x, y);
	CPen p(PS_SOLID, 1, RGB(255, 255, 0));
	dc.SelectObject(&p); for (int i = 0; i < 255; i++) {
		dc.MoveTo(x + i + 1, y - 1);
		dc.LineTo(x + i + 1, y - 1 - (100 * h[i]));
	}
}

void CPixelgrafikenDlg::OnMenurotebene()
{
	m_dib.rgb('r');			// Rot
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::On32800()
{
	m_dib.rgb('g');			// Grün
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenublauebene()
{
	m_dib.rgb('b');			// Blau
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuschaerfe()
{
	int f = 1;
	int sharpen_matrix[9] = { -f,-f,-f,-f,9 * f,-f,-f,-f,-f };
	m_dib.matrix(sharpen_matrix, 1, f);
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuunschaerfe()
{
	int soften_matrix[9] = { 6,12,6,12,25,12,6,12,6 };
	m_dib.matrix(soften_matrix, 1, 97);
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuemboss()
{
	int emboss_matrix[9] = { -1,0,0,0,0,0,0,0,1 };
	m_dib.matrix(emboss_matrix, 1, 1, 127);
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenukantenerkennung()
{
	int edge_matrix[9] = { -1,-1,-1,-1,8,-1,-1,-1,-1 };
	m_dib.matrix(edge_matrix, 1, 1);
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenurelief()
{
	int relief_matrix[9] = { -2,-1,0,-1,1,1,0,1,2 };
	m_dib.matrix(relief_matrix, 1, 1);
	RedrawWindow();			// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenufliphori()
{
	m_dib.flip('h');	// flip horizontal
	RedrawWindow();		// sende WM_PAINT-Ereignis
}


void CPixelgrafikenDlg::OnMenuflipverti()
{
	m_dib.flip('v');	// flip vertikal
	RedrawWindow();		// sende WM_PAINT-Ereignis
}
