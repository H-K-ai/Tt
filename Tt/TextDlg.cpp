// TextDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tt.h"
#include "TextDlg.h"
#include "afxdialogex.h"


// CTextDlg �Ի���

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


// CTextDlg ��Ϣ�������
/***************************************************************************
* �������ƣ�   CTextDlg::Normal
* ժ    Ҫ��  ϵͳĬ������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������      CDC *pDC, CFont *pFont
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Normal(CDC *pDC, CFont *pFont)
{
	pFont = pDC->SelectObject(pFont);
	pDC->TextOut(10, 40, "ʹ�öԻ����������!");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����
}

/***************************************************************************
* �������ƣ�   CTextDlg::Height
* ժ    Ҫ��   ��������߶�
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������      CDC *pDC, CFont *pFont
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Height(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 ����
	lf.lfHeight *= 2;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 60,"��������߶�(��С)�ӱ�");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����

}
/***************************************************************************
* �������ƣ�   CTextDlg::Weight
* ժ    Ҫ��   ������������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Weight(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 ����
	lf.lfWeight = 700;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 100,"���Դ�����");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����

}
/***************************************************************************
* �������ƣ�   CTextDlg::Width
* ժ    Ҫ��   ����������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Width(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 ����
	lf.lfWidth = lf.lfHeight;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 120,"����������");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����
}
/***************************************************************************
* �������ƣ�   CTextDlg::Others
* ժ    Ҫ��   ���������������ԣ�б�塢�»��ߡ�ɾ���ߣ�
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Others(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 ����
	lf.lfItalic = TRUE;
	lf.lfUnderline = TRUE;
	lf.lfStrikeOut = TRUE;
	lf.lfHeight *= 2;

	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(10, 150,"����б�壬�»��ߺ�ɾ����");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����
}
/***************************************************************************
* �������ƣ�   CTextDlg::Width
* ժ    Ҫ��   ���������������ԣ�б�塢�»��ߡ�ɾ���ߣ�
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::Escape(CDC *pDC, CFont *pFont)
{
	LOGFONT lf;
	pFont->GetLogFont(&lf);//-12 400 134 ����
	lf.lfHeight *= 2;
	lf.lfEscapement = 200;
	CFont font;
	font.CreateFontIndirect(&lf);
	pFont = pDC->SelectObject(&font);
	pDC->TextOut(300, 200,"�����ַ�������б��");
	pDC->SelectObject(pFont);//�ָ����뺯��ǰ����
}
/***************************************************************************
* �������ƣ�   CTextDlg::CreateFont
* ժ    Ҫ��   ��������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::CreateFont(CDC* pDC)
{
	CFont ft1;
	ft1.CreatePointFont(120,"����_GB2312");//��ʵ���������10��
	CFont *pFont = pDC->SelectObject(&ft1);
	pDC->TextOut(10, 240,"�����崴���ķ���!");

	LOGFONT lf = { 24 };
	_tcscpy_s(lf.lfFaceName, LF_FACESIZE,"����");
	lf.lfCharSet = GB2312_CHARSET;
	lf.lfItalic = TRUE;
	lf.lfStrikeOut = TRUE;
	CFont ft2;
	ft2.CreateFontIndirect(&lf);
	pDC->SelectObject(&ft2);
	pDC->TextOut(10, 280,"�������崴���ķ���!");

	HFONT hFont = ft1;

	CFont* p = CFont::FromHandle(hFont);

	pDC->SelectObject(pFont);


}
/***************************************************************************
* �������ƣ�   CTextDlg::SetColors
* ժ    Ҫ��   ����������ɫ�����ֱ�����ɫ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CTextDlg::SetColors(CDC *pDC)
{
	COLORREF clBack = pDC->SetBkColor(RGB(255, 0, 255));
	pDC->TextOut(200, 200, "���ֱ�����ɫ");

	int nMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF clText = pDC->SetTextColor(RGB(255, 0, 0));
	pDC->TextOut(10, 200,"������ɫ");

	pDC->SetBkMode(nMode);
	pDC->SetBkColor(clBack);
	pDC->SetTextColor(clText);
}

/***************************************************************************
* �������ƣ�   CTextDlg::OnPaint
* ժ    Ҫ��   �����������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
*
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
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
	dc.TextOut(10, 10,"ʹ��Ĭ���������!");

	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
