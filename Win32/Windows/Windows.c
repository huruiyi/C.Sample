#include<Windows.h>
#include<WinUser.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        //������XXXWindow�ķ�����������뵽��Ϣ�����У�����ֱ��ִ�е�
    case WM_CLOSE://���͹رյ���Ϣ:WM_DESTROY
        DestroyWindow(hWnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_LBUTTONDOWN:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        char chp[100] = { 0 };
        wsprintf(chp, TEXT("X=%d,Y=%d"), x, y);
        MessageBox(hWnd, chp, TEXT("����"), MB_OK);
    }
    case WM_KEYDOWN:
    {
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 200, 100, TEXT("Win32 Sample"), strlen("Win32 Sample"));
        EndPaint(hWnd, &ps);
    }
    break;

    default:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

// GetEnvironmentStrings();
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine, //char * argv[]
    int       nCmdShow   //��ʾ������󻯣���С��������
)
{
    /*
    //1����ƴ���
    //2��ע�ᴰ��
    //3����������
    //4����ʾ�͸���
    //5��ͨ��ѭ��ȡ��Ϣ
    //6��������Ϣ�����ڹ��̣�
    */

    //1����ƴ���
    WNDCLASS wc;
    wc.cbClsExtra = 0;//��Ķ����ڴ�
    wc.cbWndExtra = 0;//���ڵĶ����ڴ�
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���ñ���
    wc.hCursor = LoadCursor(NULL, IDC_CROSS);// ��� ��һ������ΪNULL����ʹ��ϵͳ�ṩ�Ĺ��
    wc.hIcon = LoadIcon(NULL, IDI_QUESTION);//ͼ��
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "MyWindow";
    wc.lpszMenuName = NULL;
    wc.style = 0;

    //2��ע�ᴰ��
    RegisterClass(&wc);

    //CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, \
    //    nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\

    //3����������

    HWND WINAPI  hwnd =
        CreateWindow(wc.lpszClassName,
            TEXT("WindowsName"),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            NULL,
            NULL,
            hInstance
            , NULL);

    //4����ʾ�͸���
    ShowWindow(hwnd, SW_NORMAL);
    UpdateWindow(hwnd);

    //5��ͨ��ѭ��ȡ��Ϣ
    /*\
    HWND        hwnd;
    UINT        message; ��Ϣ����
    WPARAM      wParam; ������Ϣ��������Ϣ��
    LPARAM      lParam;    ������Ϣ�������Ϣ��
    DWORD       time;       ��Ϣ����ʱ��
    POINT       pt;              ���ĵ��λ��
    */
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        /*
        GetMessageW(
        _Out_ LPMSG lpMsg,   MSG��Ϣָ��
        _In_opt_ HWND hWnd, ���񴰿ڣ���NULL���������д���
        _In_ UINT wMsgFilterMin,
        _In_ UINT wMsgFilterMax);
        */

        /*
        BOOL WINAPI bresult = GetMessage(&msg, NULL, 0, 0);
        if (!bresult)
        {
        break;
        }
        */
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    //6��������Ϣ�����ڹ��̣�

    return 0;
}