#pragma once
#include "afxcmn.h"


// CInformDlg �Ի���

class CInformDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInformDlg)

public:
	CInformDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInformDlg();

// �Ի�������
	enum { IDD = IDD_MANAGERINF_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedMod();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
