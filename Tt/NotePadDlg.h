#pragma once
#include "afxwin.h"


// CNotePadDlg 对话框

class CNotePadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNotePadDlg)

public:
	CNotePadDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNotePadDlg();

// 对话框数据
	enum { IDD = IDD_NOTEPAD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnFileExit();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFormatFont();
public:
	CFont m_font;
	CEdit m_edit;
};
