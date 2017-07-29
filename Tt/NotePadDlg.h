#pragma once
#include "afxwin.h"


// CNotePadDlg �Ի���

class CNotePadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNotePadDlg)

public:
	CNotePadDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNotePadDlg();

// �Ի�������
	enum { IDD = IDD_NOTEPAD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
