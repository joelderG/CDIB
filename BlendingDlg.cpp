// BlendingDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "Pixelgrafiken.h"
#include "afxdialogex.h"
#include "BlendingDlg.h"
#include "PixelgrafikenDlg.h"


// BlendingDlg-Dialog

IMPLEMENT_DYNAMIC(BlendingDlg, CDialogEx)

BlendingDlg::BlendingDlg(CWnd* pParent, CPixelgrafikenDlg* pMainDlg)
	: CDialogEx(IDD_DIALOG_BLENDING, pParent)
{

}

BlendingDlg::~BlendingDlg()
{
}

void BlendingDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BlendingSlider, m_blendSlider);  // Slider ansteuern

    if (!pDX->m_bSaveAndValidate)
    {
        m_blendSlider.SetRange(0, 100);  // Setze den Wertebereich des Sliders (0-100%)
        m_blendSlider.SetPos(m_blendValue);  // Setze den Anfangswert des Sliders (0%)
        UpdateLabel();  // Textanzeige für den Slider-Wert aktualisieren
    }
}


BEGIN_MESSAGE_MAP(BlendingDlg, CDialogEx)
    ON_WM_HSCROLL()
END_MESSAGE_MAP()


// Funktion zur Aktualisierung der Textanzeige
void BlendingDlg::UpdateLabel()
{
    CString str;
    str.Format(L"Überblendung: %d%%", m_blendValue);  // Anzeige des aktuellen Werts
    SetDlgItemText(IDC_Blending, str);  // Text in der Anzeige setzen
}

void BlendingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_blendValue = m_blendSlider.GetPos();  // Den aktuellen Wert des Sliders abfragen
    UpdateLabel();  // Die Textanzeige mit dem neuen Wert aktualisieren

    // Wenn das Hauptdialogfenster (CPixelgrafikenDlg) existiert, das Bild live aktualisieren
    if (m_pDlg)  // Sicherstellen, dass der Zeiger gültig ist
    {
        // Die blending-Funktion im Hauptdialogfenster aufrufen und das Bild mit dem neuen Wert aktualisieren
        m_pDlg->m_dib.blending(m_pDlg->m_dibSave, m_pDlg->m_dibTemp, m_blendValue);
        m_pDlg->RedrawWindow();  // Bild neu zeichnen
    }

    CDialog::OnHScroll(nSBCode, nPos, pScrollBar);  // Standardbehandlung des Ereignisses
}
