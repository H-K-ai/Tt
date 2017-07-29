#pragma once


// CTextDlg 对话框

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTextDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
