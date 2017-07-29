// InputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tt.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg �Ի���

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInputDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CInputDlg ��Ϣ�������

/***************************************************************************
* �������ƣ�   CInputDlg::OnBnClickedOk
* ժ    Ҫ��   ȷ���Ƿ������Ϣ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInputDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (GetFocus()!=GetDlgItem(IDOK))
	{
		NextDlgCtrl();
		return;
	}
	if (IDOK == AfxMessageBox("ȷ�������", MB_OKCANCEL | MB_ICONQUESTION))
		InsertData();
	SetDlgItemText(IDC_NAME, "");
	SetDlgItemText(IDC_NUMBER, "");
	SetDlgItemText(IDC_PROFESSION, "");
	SetDlgItemText(IDC_SEX, "");
	SetDlgItemText(IDC_DOMITORY, "");
	GetDlgItem(IDC_NAME)->SetFocus();
	CDialogEx::OnOK();
}

/***************************************************************************
* �������ƣ�   CInputDlg::InsertData
* ժ    Ҫ��   ¼����Ϣ����
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInputDlg::InsertData()
{
	CListCtrl*pList = (CListCtrl*)m_pDlg->GetDlgItem(IDC_INFORMATION_LIST);
	int i = pList->GetItemCount();
	CString str = "";
	str.Format("%d", i + 1);
	pList->InsertItem(i, str);
	GetDlgItemText(IDC_NAME, str);
	pList->SetItemText(i, 1, str);
	GetDlgItemText(IDC_NUMBER, str);
	pList->SetItemText(i, 2, str);
	GetDlgItemText(IDC_PROFESSION, str);
	pList->SetItemText(i,3, str);
	GetDlgItemText(IDC_SEX, str);
	pList->SetItemText(i, 4, str);
	GetDlgItemText(IDC_DOMITORY, str);
	pList->SetItemText(i, 5, str);

}
