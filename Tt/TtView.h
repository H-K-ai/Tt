
// TtView.h : CTtView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"


class CTtView : public CFormView
{
protected: // 仅从序列化创建
	CTtView();
	DECLARE_DYNCREATE(CTtView)

public:
	enum{ IDD = IDD_TT_FORM };

// 特性
public:
	CTtDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CTtView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
//	CBrush m_brushBkground;//创建位图画刷

	afx_msg void OnBnClickedLearncfileButton();
	CEdit m_strCaretEdit;
	afx_msg void OnBnClickedTextButton();

};

#ifndef _DEBUG  // TtView.cpp 中的调试版本
inline CTtDoc* CTtView::GetDocument() const
   { return reinterpret_cast<CTtDoc*>(m_pDocument); }
#endif

