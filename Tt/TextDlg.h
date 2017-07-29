#pragma once


// CTextDlg �Ի���

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTextDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void SetColors(CDC* pDC);
	void CreateFont(CDC* pDC);
	void Escape(CDC*pDC, CFont* pFont);
	void Others(CDC* pDC, CFont *pFont);
	void Width(CDC* pDC, CFont* pFont);
	void Weight(CDC* pDC, CFont* pFont);
	void Height(CDC* pDC, CFont* pFont);
	void Normal(CDC* pDC, CFont* pFont);
	afx_msg void OnPaint();
};
