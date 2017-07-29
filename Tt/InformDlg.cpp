// Info
//InformDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Tt.h"
#include "InformDlg.h"
#include "InputDlg.h"
#include "afxdialogex.h"

#include <locale.h>

// CInformDlg 对话框

IMPLEMENT_DYNAMIC(CInformDlg, CDialogEx)

CInformDlg::CInformDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInformDlg::IDD, pParent)
{

}

CInformDlg::~CInformDlg()
{
}

void CInformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INFORMATION_LIST, m_list);
}


BEGIN_MESSAGE_MAP(CInformDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD, &CInformDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CInformDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_MOD, &CInformDlg::OnBnClickedMod)
	ON_BN_CLICKED(IDC_SAVE, &CInformDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CInformDlg::OnBnClickedLoad)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CInformDlg 消息处理程序

/***************************************************************************
* 函数名称：   CInformDlg::OnInitDialog
* 摘    要：   列表控件初始化
* 全局影响：   public
* 返回值：     void
* 参数：     
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
BOOL CInformDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*CListCtrl*pList = (CListCtrl*)GetDlgItem(IDC_txtRMATION_LIST);
	pList->InsertColumn(0, _T("序号"), LVCFMT_CENTER, 80);
	pList->InsertColumn(1, _T("学号"), LVCFMT_CENTER, 100);
	pList->InsertColumn(2, _T("姓名"), LVCFMT_CENTER, 100);
	pList->InsertColumn(3, _T("专业"), LVCFMT_CENTER, 100);
	pList->InsertColumn(4, _T("性别"), LVCFMT_CENTER, 80);
	pList->InsertColumn(5, _T("年龄"), LVCFMT_CENTER, 80);
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);*/
	/************************************************************************/
	/*                         常用建立控件型关联变量实现                   */
	/************************************************************************/
	m_list.InsertColumn(0, "序号", LVCFMT_CENTER, 40);
	m_list.InsertColumn(1, "姓名", LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, "学号", LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, "专业", LVCFMT_CENTER, 100);
	m_list.InsertColumn(4, "性别", LVCFMT_CENTER, 80);
	m_list.InsertColumn(5, "宿舍号", LVCFMT_CENTER, 80);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//设置表格线

		// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

/***************************************************************************
* 函数名称：   CInformDlg::OnBnClickedAdd
* 摘    要：   弹出数据录入对话框
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInformDlg::OnBnClickedAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	CInputDlg ldlg;
	ldlg.m_pDlg = this;
	ldlg.DoModal();
	
}

/***************************************************************************
* 函数名称：   CInformDlg::OnBnClickedDel
* 摘    要：   删除信息
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInformDlg::OnBnClickedDel()
{
	// TODO:  在此添加控件通知处理程序代码
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (!pos)
	{
		AfxMessageBox("请选择一行再删除！");
		return;
	}
	int nSel = m_list.GetNextSelectedItem(pos);
	CString str = m_list.GetItemText(nSel, 0);
	str = "确认删除" + str + "号信息吗？";
	if (AfxMessageBox(str,MB_YESNO)==IDYES)
	{
		m_list.DeleteItem(nSel);
	}
}

/***************************************************************************
* 函数名称：   CInformDlg::OnBnClickedMod
* 摘    要：   修改信息
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInformDlg::OnBnClickedMod()
{
	// TODO:  在此添加控件通知处理程序代码
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel<0)
	{
		AfxMessageBox("请选择一行再修改！");
		return;
	}
	
	
}

/***************************************************************************
* 函数名称：   CInformDlg::OnBnClickedSave
* 摘    要：   保存信息
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInformDlg::OnBnClickedSave()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog fd(FALSE, "*.txt", NULL, OFN_OVERWRITEPROMPT, "学生信息文件(*.txt)|*.txt|所有文件|*.*||", NULL);
	if (IDCANCEL == fd.DoModal())
		return;

	CString str = fd.GetPathName();

	CFile file;
	if (!file.Open(str,CFile::modeWrite|CFile::modeCreate))
	{
		AfxMessageBox("保存失败！");
		return;
	}
	m_list.GetDlgItem(IDC_INFORMATION_LIST);
	int i = 0, nCount = m_list.GetItemCount();
	char s[6][100];
	ZeroMemory(s, 6*100);
	while (i<nCount)
	{
		int j = -1;
		while (++j<6)
			m_list.GetItemText(i, j, s[j], sizeof(s[j]));
		file.Write(s, sizeof(s));
		++i;
     }
	
	file.Close();
	
}

/***************************************************************************
* 函数名称：   CInformDlg::OnBnClickedLoad
* 摘    要：   加载信息
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
void CInformDlg::OnBnClickedLoad()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog fd(TRUE, "*.txt", NULL, OFN_FILEMUSTEXIST, "信息文件(*.txt)|*.*||", NULL);
	if (IDCANCEL == fd.DoModal())
		return;
	CString str = fd.GetPathName();
	CFile file;
	if (!file.Open(str,CFile::modeRead))
	{
		AfxMessageBox("打开失败");
		return;
	}
	//char s[6][100];
	//ZeroMemory(s, 6 * 100);

	char* s = new char[600];
	int i = 0, j = 0;
	m_list.GetDlgItem(IDC_INFORMATION_LIST);
	m_list.DeleteAllItems();
	
	while (file.Read(s,600))
	{
		char tem[100];
		ZeroMemory(tem, 100);
		memcpy(tem, s, 100);
		m_list.InsertItem(i,tem);
		j = 0;
		while (j < 6)
		{
			ZeroMemory(tem, 100);
			memcpy(tem, s+100*j, 100);
			m_list.SetItemText(i, j, tem);
			j++;
		}
		++i;

	}
	file.Close();
	delete[] s;
	
}

/***************************************************************************
* 函数名称：   CInformDlg::OnCtlColor
* 摘    要：   背景设置
* 全局影响：   public
* 返回值：     void
* 参数：
* 修改记录：
*  [日期]     [作者/修改者]  [修改原因]
*2016/04/11       莫宏凯
***************************************************************************/
HBRUSH CInformDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	// TODO:  在此更改 DC 的任何特性
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 255, 0));
	static CBrush br(RGB(0, 0, 255));
	return br;
	
}
