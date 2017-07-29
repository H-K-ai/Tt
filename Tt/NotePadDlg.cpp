// NotePadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tt.h"
#include "NotePadDlg.h"
#include "afxdialogex.h"


// CNotePadDlg 对话框

IMPLEMENT_DYNAMIC(CNotePadDlg, CDialogEx)

CNotePadDlg::CNotePadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNotePadDlg::IDD, pParent)
{

}

CNotePadDlg::~CNotePadDlg()
{
}

void CNotePadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_edit);
}


BEGIN_MESSAGE_MAP(CNotePadDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_COMMAND(ID_FILE_EXIT, &CNotePadDlg::OnFileExit)
	ON_COMMAND(ID_FILE_OPEN, &CNotePadDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CNotePadDlg::OnFileSave)
	ON_COMMAND(ID_FORMAT_FONT, &CNotePadDlg::OnFormatFont)
END_MESSAGE_MAP()


// CNotePadDlg 消息处理程序


void CNotePadDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


void CNotePadDlg::OnFileExit()
{
	// TODO:  在此添加命令处理程序代码
	CDialogEx::OnCancel();
}

/***************************************************************************
* 函数名称：   CNotePadDlg::OnFileOpen
* 摘    要：   打开文件
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CNotePadDlg::OnFileOpen()
{
	// TODO:  在此添加命令处理程序代码
	CFileDialog fd(TRUE, "*.txt", NULL,OFN_FILEMUSTEXIST, "文本文件(*.txt)|*.txt|所有文件|*.*|",NULL);
	if (fd.DoModal() == IDCANCEL)
		return;
	CFile file;
	file.Open(fd.GetPathName(), CFile::modeRead | CFile::shareDenyNone);
	CFileStatus stat;
	file.GetStatus(stat);
	char *pText = new char[stat.m_size + 1];
	int nRet = file.Read(pText, stat.m_size);
	pText[nRet] = 0;//'\0';
	SetDlgItemText(IDC_TEXT,pText);
	delete[]pText;//释放堆内存空间
}

/***************************************************************************
* 函数名称：   CNotePadDlg::OnFileSave
* 摘    要：   保存文件
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CNotePadDlg::OnFileSave()
{
	// TODO:  在此添加命令处理程序代码
	CFileDialog fd(FALSE, "*.txt", NULL, OFN_FILEMUSTEXIST, "文本文件(*.txt)|*.txt|所有文件|*.*|", NULL);
	if (fd.DoModal() == IDCANCEL)
		return;
	CFile file;
	file.Open(fd.GetPathName(), CFile::modeWrite | CFile::modeCreate);
	CWnd*pEdit = GetDlgItem(IDC_TEXT);
	int nLen = pEdit->GetWindowTextLength();
	char*pBuf = new char[nLen+1];
	pBuf[nLen] = 0;
	pEdit->GetWindowText(pBuf, nLen + 1);
	file.Write(pBuf, nLen);
	file.Close();
	delete[]pBuf;

}

/***************************************************************************
* 函数名称：   CNotePadDlg::OnFormatFont
* 摘    要：   字体设置
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CNotePadDlg::OnFormatFont()
{
	// TODO:  在此添加命令处理程序代码
	LOGFONT lf = { 0 };
	if (m_font.GetSafeHandle())
		m_font.GetLogFont(&lf);
	CFontDialog dlg(&lf);
	if (IDCANCEL == dlg.DoModal())
		return;
	dlg.GetCurrentFont(&lf);
	m_font.DeleteObject();
	m_font.CreateFontIndirect(&lf);
	m_edit.SetFont(&m_font);
}
