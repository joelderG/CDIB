#include "pch.h"
#include "CDIB.h"

CDIB::CDIB() {
	m_pBMFH = 0;
	m_pBMI = 0;
	m_pBits = 0;
	m_dwLength = 0L; // init by Zero 
}

CDIB::~CDIB() {
	if (m_pBMFH != 0)
		delete[] m_pBMFH; // free the memory.
}

int CDIB::DibWidth() {
	if (m_pBMFH)
		return m_pBMI->bmiHeader.biWidth;
	else return 0;
}

int CDIB::DibHeight() {
	if (m_pBMFH)
		return m_pBMI->bmiHeader.biHeight;
	else return 0;
}

bool CDIB::Load(CString fname) {
	if (m_pBMFH != 0) delete[] m_pBMFH; // DIB must be empty
	FILE* fp;
	if ((fp = _wfopen(fname, L"rb")) == NULL) {
		AfxMessageBox(L"Unable to open CDIB-File");
		return false;
	}
	fseek(fp, 0L, SEEK_END); // L�nge der Datei ermitteln
	m_dwLength = ftell(fp); rewind(fp);
	if ((m_pBMFH = (BITMAPFILEHEADER*) new char[m_dwLength]) == 0) {
		AfxMessageBox(L"Unable to allocate DIB-Memory"); fclose(fp);
		return false;
	}
	if (fread(m_pBMFH, m_dwLength, 1, fp) != 1) {
		AfxMessageBox(L"Read error");
		delete[] m_pBMFH; m_pBMFH = 0; fclose(fp);
		return false;
	}
	if (m_pBMFH->bfType != 0x4d42) {
		AfxMessageBox(L"Invalid bitmap file");
		delete[] m_pBMFH; m_pBMFH = 0; fclose(fp);
		return false;
	}
	m_pBMI = (BITMAPINFO*)(m_pBMFH + 1);
	m_pBits = (BYTE*)m_pBMFH + m_pBMFH->bfOffBits;
	fclose(fp); return true;
}

bool CDIB::Save(CString fname) {
	if (!m_pBMFH) return false;
	FILE* fp;
	if ((fp = _wfopen(fname, L"wb")) == NULL) {
		AfxMessageBox(L"Unable to open CDIB-File");
		return false;
	}
	if (fwrite(m_pBMFH, m_dwLength, 1, fp) != 1) {
		AfxMessageBox(L"Write error");
		delete[] m_pBMFH; m_pBMFH = 0; fclose(fp);
		return false;
	}
	fclose(fp);
	return true;
}

void CDIB::Draw(CDC* pDC, int x, int y) {
	if (m_pBMFH != 0) {
		pDC->SetStretchBltMode(HALFTONE);
		StretchDIBits(pDC->GetSafeHdc(),
			x, // Destination x
			y, // Destination y
			DibWidth(), // Destination width
			DibHeight(), // Destination height
			0, // Source x
			0, // Source y
			DibWidth(), // Source width
			DibHeight(), // Source height
			m_pBits, // Pointer to bits
			m_pBMI, // BITMAPINFO
			DIB_RGB_COLORS, // Options
			SRCCOPY); // Raster operation code (ROP)
	}
}