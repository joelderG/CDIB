// QualityDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "Pixelgrafiken.h"
#include "afxdialogex.h"
#include "QualityDlg.h"


// QualityDlg-Dialog

IMPLEMENT_DYNAMIC(QualityDlg, CDialogEx)

QualityDlg::QualityDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_QUALITY, pParent)
{

}

QualityDlg::~QualityDlg()
{
}

void QualityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_QualitySlider, m_qualitySlider);

    if (!pDX->m_bSaveAndValidate)
    {
        m_qualitySlider.SetRange(1, 100);
        m_qualitySlider.SetPos(m_quality);
        UpdateQualityLabel();
    }
}


BEGIN_MESSAGE_MAP(QualityDlg, CDialogEx)
    ON_WM_HSCROLL()
END_MESSAGE_MAP()


// QualityDlg-Meldungshandler

void QualityDlg::UpdateQualityLabel()
{
    CString str;
    str.Format(L"JPEG-Qualität: %d%%", m_quality);
    SetDlgItemText(IDC_qualityText, str);
}

void QualityDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    m_quality = m_qualitySlider.GetPos();
    UpdateQualityLabel();
    CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
