#pragma once

class CMy01SystemFunDlg : public CDialogEx
{
public:
    CMy01SystemFunDlg(CWnd* pParent = NULL);	// 标准构造函数

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_MY01SYSTEMFUN_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

protected:
    HICON m_hIcon;

    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButton1();
    afx_msg void OnBnClickedButton2();
    afx_msg void OnBnClickedButton3();
    afx_msg void OnBnClickedButtonGetlang();
};
