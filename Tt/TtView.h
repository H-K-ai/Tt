
// TtView.h : CTtView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"


class CTtView : public CFormView
{
protected: // �������л�����
	CTtView();
	DECLARE_DYNCREATE(CTtView)

public:
	enum{ IDD = IDD_TT_FORM };

// ����
public:
	CTtDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CTtView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()


public:

	void OnDraw(CDC* pDC);
	afx_msg void OnBnClickedFontButton();
//private:
//	CFont m_font;
private:
	CBitmap bitmap;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CRichEditCtrl m_edtRhContrl;

	afx_msg void OnBnClickedManagerInformationButton();
	afx_msg void OnFileWrite();
	afx_msg void OnFileRead();
	afx_msg void OnBnClickedColorButton();
	afx_msg void OnBnClickedWriteiniButton();
	afx_msg void OnBnClickedReadiniButton();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

//public:
//	CBrush m_brushBkground;//����λͼ��ˢ

	afx_msg void OnBnClickedLearncfileButton();
	CEdit m_strCaretEdit;
	afx_msg void OnBnClickedTextButton();

};

#ifndef _DEBUG  // TtView.cpp �еĵ��԰汾
inline CTtDoc* CTtView::GetDocument() const
   { return reinterpret_cast<CTtDoc*>(m_pDocument); }
#endif

