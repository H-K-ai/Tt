// Info
//InformDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Tt.h"
#include "InformDlg.h"
#include "InputDlg.h"
#include "afxdialogex.h"

#include <locale.h>

// CInformDlg �Ի���

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


// CInformDlg ��Ϣ�������

/***************************************************************************
* �������ƣ�   CInformDlg::OnInitDialog
* ժ    Ҫ��   �б�ؼ���ʼ��
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������     
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
BOOL CInformDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*CListCtrl*pList = (CListCtrl*)GetDlgItem(IDC_txtRMATION_LIST);
	pList->InsertColumn(0, _T("���"), LVCFMT_CENTER, 80);
	pList->InsertColumn(1, _T("ѧ��"), LVCFMT_CENTER, 100);
	pList->InsertColumn(2, _T("����"), LVCFMT_CENTER, 100);
	pList->InsertColumn(3, _T("רҵ"), LVCFMT_CENTER, 100);
	pList->InsertColumn(4, _T("�Ա�"), LVCFMT_CENTER, 80);
	pList->InsertColumn(5, _T("����"), LVCFMT_CENTER, 80);
	pList->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);*/
	/************************************************************************/
	/*                         ���ý����ؼ��͹�������ʵ��                   */
	/************************************************************************/
	m_list.InsertColumn(0, "���", LVCFMT_CENTER, 40);
	m_list.InsertColumn(1, "����", LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, "ѧ��", LVCFMT_CENTER, 100);
	m_list.InsertColumn(3, "רҵ", LVCFMT_CENTER, 100);
	m_list.InsertColumn(4, "�Ա�", LVCFMT_CENTER, 80);
	m_list.InsertColumn(5, "�����", LVCFMT_CENTER, 80);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);//���ñ����

		// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

/***************************************************************************
* �������ƣ�   CInformDlg::OnBnClickedAdd
* ժ    Ҫ��   ��������¼��Ի���
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInformDlg::OnBnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CInputDlg ldlg;
	ldlg.m_pDlg = this;
	ldlg.DoModal();
	
}

/***************************************************************************
* �������ƣ�   CInformDlg::OnBnClickedDel
* ժ    Ҫ��   ɾ����Ϣ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInformDlg::OnBnClickedDel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (!pos)
	{
		AfxMessageBox("��ѡ��һ����ɾ����");
		return;
	}
	int nSel = m_list.GetNextSelectedItem(pos);
	CString str = m_list.GetItemText(nSel, 0);
	str = "ȷ��ɾ��" + str + "����Ϣ��";
	if (AfxMessageBox(str,MB_YESNO)==IDYES)
	{
		m_list.DeleteItem(nSel);
	}
}

/***************************************************************************
* �������ƣ�   CInformDlg::OnBnClickedMod
* ժ    Ҫ��   �޸���Ϣ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInformDlg::OnBnClickedMod()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	int nSel = m_list.GetNextSelectedItem(pos);
	if (nSel<0)
	{
		AfxMessageBox("��ѡ��һ�����޸ģ�");
		return;
	}
	
	
}

/***************************************************************************
* �������ƣ�   CInformDlg::OnBnClickedSave
* ժ    Ҫ��   ������Ϣ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInformDlg::OnBnClickedSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fd(FALSE, "*.txt", NULL, OFN_OVERWRITEPROMPT, "ѧ����Ϣ�ļ�(*.txt)|*.txt|�����ļ�|*.*||", NULL);
	if (IDCANCEL == fd.DoModal())
		return;

	CString str = fd.GetPathName();

	CFile file;
	if (!file.Open(str,CFile::modeWrite|CFile::modeCreate))
	{
		AfxMessageBox("����ʧ�ܣ�");
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
* �������ƣ�   CInformDlg::OnBnClickedLoad
* ժ    Ҫ��   ������Ϣ
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
void CInformDlg::OnBnClickedLoad()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog fd(TRUE, "*.txt", NULL, OFN_FILEMUSTEXIST, "��Ϣ�ļ�(*.txt)|*.*||", NULL);
	if (IDCANCEL == fd.DoModal())
		return;
	CString str = fd.GetPathName();
	CFile file;
	if (!file.Open(str,CFile::modeRead))
	{
		AfxMessageBox("��ʧ��");
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
* �������ƣ�   CInformDlg::OnCtlColor
* ժ    Ҫ��   ��������
* ȫ��Ӱ�죺   public
* ����ֵ��     void
* ������
* �޸ļ�¼��
*  [����]     [����/�޸���]  [�޸�ԭ��]
*2016/04/11       Ī�꿭
***************************************************************************/
HBRUSH CInformDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 255, 0));
	static CBrush br(RGB(0, 0, 255));
	return br;
	
}
