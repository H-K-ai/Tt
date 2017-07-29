// NotePadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tt.h"
#include "NotePadDlg.h"
#include "afxdialogex.h"


// CNotePadDlg �Ի���

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


// CNotePadDlg ��Ϣ�������


void CNotePadDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}


void CNotePadDlg::OnFileExit()
{
	// TODO:  �ڴ���������������
	CDialogEx::OnCancel();
}

/***************************************************************************
* �������ƣ�   CNotePadDlg::OnFileOpen
* ժ    Ҫ��   ���ļ�
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CNotePadDlg::OnFileOpen()
{
	// TODO:  �ڴ���������������
	CFileDialog fd(TRUE, "*.txt", NULL,OFN_FILEMUSTEXIST, "�ı��ļ�(*.txt)|*.txt|�����ļ�|*.*|",NULL);
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
	delete[]pText;//�ͷŶ��ڴ�ռ�
}

/***************************************************************************
* �������ƣ�   CNotePadDlg::OnFileSave
* ժ    Ҫ��   �����ļ�
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CNotePadDlg::OnFileSave()
{
	// TODO:  �ڴ���������������
	CFileDialog fd(FALSE, "*.txt", NULL, OFN_FILEMUSTEXIST, "�ı��ļ�(*.txt)|*.txt|�����ļ�|*.*|", NULL);
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
* �������ƣ�   CNotePadDlg::OnFormatFont
* ժ    Ҫ��   ��������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CNotePadDlg::OnFormatFont()
{
	// TODO:  �ڴ���������������
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
