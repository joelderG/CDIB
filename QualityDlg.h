#pragma once
#include "afxdialogex.h"


// QualityDlg-Dialog

class QualityDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QualityDlg)

public:
	QualityDlg(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~QualityDlg();
	int GetQuality() const { return m_quality; }
// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_QUALITY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	int m_quality;
	CSliderCtrl m_qualitySlider;
	void UpdateQualityLabel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
