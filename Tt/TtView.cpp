
// TtView.cpp : CTtView 类的实现
//

#include "stdafx.h"


// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Tt.h"
#endif

#include "TtDoc.h"
#include "TtView.h"
#include "InformDlg.h"
#include "NotePadDlg.h"
#include "TextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTtView

IMPLEMENT_DYNCREATE(CTtView, CFormView)

BEGIN_MESSAGE_MAP(CTtView, CFormView)

	ON_BN_CLICKED(IDC_FONT_BUTTON, &CTtView::OnBnClickedFontButton)
	ON_WM_CREATE()

	ON_BN_CLICKED(IDC_ManagerInformation_Button, &CTtView::OnBnClickedManagerInformationButton)
	ON_COMMAND(IDM_FILE_WRITE, &CTtView::OnFileWrite)
	ON_COMMAND(IDM_FILE_READ, &CTtView::OnFileRead)
	/*ON_WM_SIZE()*/
	ON_BN_CLICKED(IDC_COLOR_BUTTON, &CTtView::OnBnClickedColorButton)
	ON_BN_CLICKED(IDC_WRITEINI_BUTTON, &CTtView::OnBnClickedWriteiniButton)
	ON_BN_CLICKED(IDC_READINI_BUTTON, &CTtView::OnBnClickedReadiniButton)
	ON_WM_ERASEBKGND()

	
	ON_BN_CLICKED(IDC_LEARNCFILE_BUTTON, &CTtView::OnBnClickedLearncfileButton)
	ON_BN_CLICKED(IDC_TEXT_BUTTON, &CTtView::OnBnClickedTextButton)
END_MESSAGE_MAP()

// CTtView 构造/析构

CTtView::CTtView()
	: CFormView(CTtView::IDD)
	
{
	// TODO:  在此处添加构造代码

}

CTtView::~CTtView()
{
}

void CTtView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT, m_edtRhContrl);

	DDX_Control(pDX, IDC_CARET_EDIT, m_strCaretEdit);
}

BOOL CTtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CTtView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	/*ResizeParentToFit();*/
	//((CBitmapButton *)GetDlgItem(IDC_FONT_BUTTON))->LoadBitmaps(IDB_PNG1);
	/*SetDlgItemTextW(IDC_FONT_BUTTON, _T("字体选择"));*/
	//m_strCaretEdit.CreateSolidCaret(0, 23);
	//m_strCaretEdit.ShowCaret();
}


// CTtView 诊断

#ifdef _DEBUG
void CTtView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTtView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTtDoc* CTtView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTtDoc)));
	return (CTtDoc*)m_pDocument;
}
#endif //_DEBUG


// CTtView 消息处理程序

/***************************************************************************
* 函数名称：   CTtView::OnDraw
* 摘    要：  窗口重绘、字符串显示
* 全局影响：   public
* 返回值：     void
*
* 修改记录：  
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯         
***************************************************************************/

void CTtView::OnDraw(CDC* pDC)
{
	CTtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*CString str(_T("相信自己，努力就会有收获！"));*/
	CString str;
	str = "坚持不一定成功，放弃一定失败!";
	pDC->TextOut(220, 220, str);
	//pDC->SetTextColor(RGB(255, 0, 0));
	str.LoadString(AFX_IDS_SCTASKLIST);
	pDC->TextOut(300, 300, str);
	str.LoadString(IDS_STRINDEMO);
	pDC->TextOut(600,600,str);
	str.LoadString(IDS_STRINGNH);
	pDC->TextOut(100, 100, str);
	//pDC->SetTextColor(RGB(0, 255, 0));
}

/***************************************************************************
* 函数名称：   CTtView::OnBnClickedFontButton
* 摘    要：   字体对话框的使用
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTtView::OnBnClickedFontButton()
{
	/***********************************************************

		利用RichEdit2控件演示CFontDialog的作用

	***********************************************************/
	//定义并初始化文字格式结构  
	CHARFORMAT cf = { 0 };
	cf.cbSize = sizeof(cf);
	///取得文本框当前文字的格式  
	m_edtRhContrl.GetSelectionCharFormat(cf);
	///创建字体对话框，并用取得的字体格式初始化对话框  
	CFontDialog dlg(cf);
	///显示对话框，选择字体信息  
	if (dlg.DoModal() == IDOK)
	{
		///取得用户所选的字体信息  
		dlg.GetCharFormat(cf);
		////将文本格式信息设置到文本框当前文本  
		m_edtRhContrl.SetSelectionCharFormat(cf);
	}
}
/***************************************************************************
* 函数名称：   CTtView::OnCreate
* 摘    要：   创建文本插入符、图形插入符
* 全局影响：   public
* 返回值：     int
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/

int CTtView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	//
	//CreateSolidCaret(0, 20);//由于创建的插入符默认是隐藏的，所以需要显示插入符
	//ShowCaret();
	//CClientDC dc(this);//创建设备描述表
	//TEXTMETRIC tm;
	//dc.GetTextMetrics(&tm);
	//CreateSolidCaret(tm.tmAveCharWidth / 8, tm.tmHeight);

	/*CBitmap bitmap;*///需定义为私有成员变量，否则当OnCreate函数执行完之后，bitmap将会被析构导致资源加载不了

	/*bitmap.LoadBitmap(IDB_BITMAP4);
	CreateCaret(&bitmap);

	ShowCaret();*/
	return 0;
}


/***************************************************************************
* 函数名称：   CTtView::OnBnClickedManagerInformationButton
* 摘    要：   弹出信息管理对话框
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedManagerInformationButton()
{
	// TODO:  在此添加控件通知处理程序代码
	CInformDlg dlg;
	dlg.DoModal();

}

/***************************************************************************
* 函数名称：   CTtView::OnFileWrite
* 摘    要：   文件写入
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnFileWrite()
{
	// TODO:  在此添加命令处理程序代码
	CFile fl("1.txt", CFile::modeCreate | CFile::modeReadWrite);
	fl.Write("南昌航空大学",strlen("南昌航空大学"));
	fl.Close();
	
}
/***************************************************************************
* 函数名称：   CTtView::OnFileRead
* 摘    要：   文件读取
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnFileRead()
{
	// TODO:  在此添加命令处理程序代码 
	CFile fl("1.txt", CFile::modeRead);
	char *pBuf;
	DWORD dwFileLen;
	dwFileLen = fl.GetLength();
	pBuf = new char[dwFileLen + 1];
	pBuf[dwFileLen] = 0;
	fl.Read( pBuf, dwFileLen);
	fl.Close();
	MessageBox(pBuf);
	delete[]pBuf;
}

/***************************************************************************
* 函数名称：   CTtView::OnBnClickedColorButton
* 摘    要：  颜色对话框的使用
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedColorButton()
{
	// TODO:  在此添加控件通知处理程序代码
	COLORREF color = RGB(255, 0, 0);      // 颜色对话框的初始颜色为红色  
	CColorDialog colorDlg(color);         // 构造颜色对话框，传入初始颜色值   

	if (IDOK == colorDlg.DoModal())       // 显示颜色对话框，并判断是否点击了“确定”   
	{
		color = colorDlg.GetColor();      // 获取颜色对话框中选择的颜色值   
		SetDlgItemInt(IDC_COLOR_EDIT, color);         // 在Color编辑框中显示所选颜色值   
		SetDlgItemInt(IDC_R_EDIT, GetRValue(color));  // 在R编辑框中显示所选颜色的R分量值   
		SetDlgItemInt(IDC_G_EDIT, GetGValue(color));  // 在G编辑框中显示所选颜色的G分量值   
		SetDlgItemInt(IDC_B_EDIT, GetBValue(color));  // 在B编辑框中显示所选颜色的B分量值   
	}
}






/***************************************************************************
* 函数名称：   CTtView::OnBnClickedWriteiniButton
* 摘    要：  写入INI文件
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedWriteiniButton()
{
	 //TODO:  在此添加控件通知处理程序代码
	CString strName, strTemp;
	int nAge;
	strName ="";
	nAge = 12;
	strTemp.Format("%d", nAge);
	GetDlgItemText(IDC_NAME_EDIT, strName);
	GetDlgItemText(IDC_AGE_EDIT,strTemp);

	WritePrivateProfileString("StudentInfo",
		                      "Name",
		                      strName,
		                     "..\\student.ini");
	//if (strTemp.IsEmpty())
		//strTemp.Format("%d", nAge);
	WritePrivateProfileString("StudentInfo",
								"Age",
								strTemp,
								"..\\student.ini");


	

}

/***************************************************************************
* 函数名称：   CTtView::OnBnClickedReadiniButton
* 摘    要：  读取INI文件
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedReadiniButton()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strName, strTemp;
	int nAge;
	strName ="";
	nAge = 12;

	GetPrivateProfileString("StudentInfo",
		                    "Name",
		                    "默认姓名",
		                    strName.GetBuffer(MAX_PATH),
		                    MAX_PATH,
		                    "..\\student.ini");
	nAge = GetPrivateProfileInt("StudentInfo", 
		                            "Age", 
		                            10, 
		                            "..\\student.ini");
	SetDlgItemText(IDC_NAME_EDIT, strName);
	strTemp.Format("%d", nAge);
	SetDlgItemText(IDC_AGE_EDIT,strTemp);



}

/***************************************************************************
* 函数名称：   CTtView::OnEraseBkgnd
* 摘    要：  修改视图背景颜色
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
BOOL CTtView::OnEraseBkgnd(CDC* pDC)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CRect rect;
	GetClientRect(rect);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 0, 0));
	pDC->FillSolidRect(rect, RGB(0, 255, 255));



	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP3);
	BITMAP bm;
	bmp.GetBitmap(&bm);
	CDC mdc;
	mdc.CreateCompatibleDC(pDC);
	mdc.SelectObject(&bmp);
	pDC->SetStretchBltMode(COLORONCOLOR);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &mdc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);// 图片拉伸
	return TRUE;
	//return CFormView::OnEraseBkgnd(pDC);
}
/***************************************************************************
* 函数名称：   CTtView::OnBnClickedLearncfileButton
* 摘    要：  弹出“CFile使用”模态对话框
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedLearncfileButton()
{
	// TODO:  在此添加控件通知处理程序代码
	CNotePadDlg dlg;
	dlg.DoModal();
}

/***************************************************************************
* 函数名称：   CTtView::OnBnClickedTextButton
* 摘    要：  弹出“文本编程”模态对话框
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11    莫宏凯
***************************************************************************/
void CTtView::OnBnClickedTextButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CTextDlg pdlg;
	pdlg.DoModal();
}



