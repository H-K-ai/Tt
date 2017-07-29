// TextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tt.h"
#include "TextDlg.h"
#include "afxdialogex.h"


// CTextDlg 对话框

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEXT_DLG, pParent)
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTextDlg 消息处理程序
/***************************************************************************
* 函数名称：   CTextDlg::Normal
* 摘    要：  系统默认字体
* 全局影响：   public
* 返回值：     void
* 参数：      CDC *pDC, CFont *pFont
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Normal(CDC *pDC, CFont *pFont)
{
	pFont = pDC->SelectObject(pFont);
	pDC->TextOut(10, 40, "使用对话框字体输出!");
	pDC->SelectObject(pFont);//恢复进入函数前字体
}

/***************************************************************************
* 函数名称：   CTextDlg::Height
* 摘    要：   测试字体高度
* 全局影响：   public
* 返回值：     void
* 参数：      CDC *pDC, CFont *pFont
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Height(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 宋体
	lf.lfHeight *= 2;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 60,"测试字体高度(大小)加倍");
	pDC->SelectObject(pFont);//恢复进入函数前字体

}
/***************************************************************************
* 函数名称：   CTextDlg::Weight
* 摘    要：   测试字体重量
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Weight(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 宋体
	lf.lfWeight = 700;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 100,"测试粗体字");
	pDC->SelectObject(pFont);//恢复进入函数前字体

}
/***************************************************************************
* 函数名称：   CTextDlg::Width
* 摘    要：   测试字体宽度
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Width(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 宋体
	lf.lfWidth = lf.lfHeight;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 120,"测试字体宽度");
	pDC->SelectObject(pFont);//恢复进入函数前字体
}
/***************************************************************************
* 函数名称：   CTextDlg::Others
* 摘    要：   测试字体其他属性（斜体、下划线、删除线）
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Others(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 宋体
	lf.lfItalic = TRUE;
	lf.lfUnderline = TRUE;
	lf.lfStrikeOut = TRUE;
	lf.lfHeight *= 2;

	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 150,"测试斜体，下划线和删除线");
	pDC->SelectObject(pFont);//恢复进入函数前字体
}
/***************************************************************************
* 函数名称：   CTextDlg::Width
* 摘    要：   测试字体其他属性（斜体、下划线、删除线）
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::Escape(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 宋体
	lf.lfHeight *= 2;
	lf.lfEscapement = 200;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(300, 200,"测试字符串的倾斜度");
	pDC->SelectObject(pFont);//恢复进入函数前字体
}
/***************************************************************************
* 函数名称：   CTextDlg::CreateFont
* 摘    要：   创建字体
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::CreateFont(CDC* pDC)
{
	CFont ft1;
	ft1.CreatePointFont(120,"楷体_GB2312");//与实际字体相差10倍
	CFont *pFont = pDC->SelectObject(&ft1);
	pDC->TextOut(10, 240,"简单字体创建的方法!");

	LOGFONT lf = { 24 };
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE,"黑体");
	lf.lfCharSet = GB2312_CHARSET;
	lf.lfItalic = TRUE;
	lf.lfStrikeOut = TRUE;
	CFont ft2;
	ft2.CreateFontIndirect(&lf);
	pDC->SelectObject(&ft2);
	pDC->TextOut(10, 280,"完整字体创建的方法!");

	HFONT hFont = ft1;

	CFont* p = CFont::FromHandle(hFont);

	pDC->SelectObject(pFont);


}
/***************************************************************************
* 函数名称：   CTextDlg::SetColors
* 摘    要：   设置字体颜色及文字背景颜色
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::SetColors(CDC *pDC)
{
	COLORREF clBack = pDC->SetBkColor(RGB(255, 0, 255));
	pDC->TextOut(200, 200, "文字背景颜色");

	int nMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF clText = pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(10, 200,"文字颜色");

	pDC->SetBkMode(nMode);
	pDC->SetBkColor(clBack);
	pDC->SetTextColor(clText);
}

/***************************************************************************
* 函数名称：   CTextDlg::OnPaint
* 摘    要：   字体属性输出
* 全局影响：   public
* 返回值：     void
*
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CTextDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CFont * pFont = GetFont();
	Normal(&dc, pFont);
	Height(&dc, pFont);
	Weight(&dc, pFont);
	Width(&dc,  pFont);
	Others(&dc, pFont);
	Escape(&dc, pFont);
	CreateFont(&dc);
	SetColors(&dc);
	dc.TextOut(10, 10,"使用默认字体输出!");

	// 不为绘图消息调用 CDialogEx::OnPaint()
}
