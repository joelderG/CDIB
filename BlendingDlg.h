#pragma once
#include "afxdialogex.h"
class CPixelgrafikenDlg;

// BlendingDlg-Dialog

class BlendingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BlendingDlg)

public:
	BlendingDlg(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~BlendingDlg();
	int GetBlendValue() const { return m_blendValue; }
	void SetMainDialog(CPixelgrafikenDlg* pDlg) { m_pDlg = pDlg; }
// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BLENDING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

private:
	int m_blendValue;
	CSliderCtrl m_blendSlider;
	CPixelgrafikenDlg* m_pDlg;  // Zeiger auf das Hauptdialogfenster (CPixelgrafikenDlg)
	void UpdateLabel(); // Funktion zur Aktualisierung des Textes
};
