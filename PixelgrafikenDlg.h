
// PixelgrafikenDlg.h: Headerdatei
//

#pragma once
#include "CDIB.h"
#include "BlendingDlg.h"

// CPixelgrafikenDlg-Dialogfeld
class CPixelgrafikenDlg : public CDialogEx
{
// Konstruktion
public:
	CPixelgrafikenDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PIXELGRAFIKEN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;
	float m_fScale;  // Skalierungsfaktor

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMenuladen();
	afx_msg void OnMenuspeichern();
	afx_msg void OnMenuaufhellen();
	afx_msg void OnMenuabdunkeln();
	afx_msg void OnMenugraustufen();
	afx_msg void OnMenunegativ();
	afx_msg void OnMenukontrast();
	afx_msg void OnMenublending();
	afx_msg void OnMenuhistogramm();
	afx_msg void OnMenurotebene();
	afx_msg void On32800();
	afx_msg void OnMenublauebene();
	afx_msg void OnMenuschaerfe();
	afx_msg void OnMenuunschaerfe();
	afx_msg void OnMenuemboss();
	afx_msg void OnMenukantenerkennung();
	afx_msg void OnMenurelief();
	afx_msg void OnMenufliphori();
	afx_msg void OnMenuflipverti();
	void draw_histogramm();
	void LoadFile();
	void SaveFile();
	void OnBlending();

	CDIB m_dib;
	CDIB m_dibTemp;  // Temporäres Bild für Blending
	CDIB m_dibSave;
};
