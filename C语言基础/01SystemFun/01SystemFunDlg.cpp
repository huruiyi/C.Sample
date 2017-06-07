// 01SystemFunDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "01SystemFun.h"
#include "01SystemFunDlg.h"
#include "afxdialogex.h"
#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy01SystemFunDlg �Ի���

CMy01SystemFunDlg::CMy01SystemFunDlg(CWnd* pParent /*=NULL*/)
    : CDialogEx(IDD_MY01SYSTEMFUN_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01SystemFunDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy01SystemFunDlg, CDialogEx)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CMy01SystemFunDlg::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &CMy01SystemFunDlg::OnBnClickedButton2)
    ON_BN_CLICKED(IDC_BUTTON3, &CMy01SystemFunDlg::OnBnClickedButton3)
    ON_BN_CLICKED(IDC_BUTTON_GetLang, &CMy01SystemFunDlg::OnBnClickedButtonGetlang)
END_MESSAGE_MAP()

// CMy01SystemFunDlg ��Ϣ�������

BOOL CMy01SystemFunDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
    //  ִ�д˲���
    SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
    SetIcon(m_hIcon, FALSE);		// ����Сͼ��

    // TODO: �ڴ���Ӷ���ĳ�ʼ������

    return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy01SystemFunDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // ���ڻ��Ƶ��豸������

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // ʹͼ���ڹ����������о���
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // ����ͼ��
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy01SystemFunDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CMy01SystemFunDlg::OnBnClickedButton1()
{
    WinExec("calc", SW_NORMAL);
}

void CMy01SystemFunDlg::OnBnClickedButton2()
{
    WinExec("mspaint", SW_NORMAL);
}

void CMy01SystemFunDlg::OnBnClickedButton3()
{
    WinExec("notepad", SW_NORMAL);
}

void CMy01SystemFunDlg::OnBnClickedButtonGetlang()
{
    CString LikeList, Like;
    LikeList = "";
    for (int i = IDC_CHECKC; i < IDC_CHECKCS + 1; i++)
    {
        CButton *pBtn = static_cast<CButton *>(GetDlgItem(i));

        if (pBtn != NULL)
        {
            if (pBtn->GetCheck() == BST_CHECKED)
            {
                pBtn->GetWindowText(Like);
                LikeList += Like + "\r\n";
            }
        }
    }
    MessageBox(LikeList, "��ѡ��İ���");
}