// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tt.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg 对话框

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


// CInputDlg 消息处理程序

/***************************************************************************
* 函数名称：   CInputDlg::OnBnClickedOk
* 摘    要：   确定是否添加信息
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInputDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	if (GetFocus()!=GetDlgItem(IDOK))
	{
		NextDlgCtrl();
		return;
	}
	if (IDOK == AfxMessageBox("确定添加吗？", MB_OKCANCEL | MB_ICONQUESTION))
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
* 函数名称：   CInputDlg::InsertData
* 摘    要：   录入信息数据
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
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
