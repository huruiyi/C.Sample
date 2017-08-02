#include<Windows.h>
#include<WinUser.h>

HINSTANCE hInstance;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		CreateWindow(L"Button", L"��ťsi", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 35, 180, 180, 60, hWnd, NULL, hInstance, NULL);
	}
	break;
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
		MessageBox(hWnd, chp, TEXT("����"), MB_HELP);
	}
	break;
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
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
}

// GetEnvironmentStrings();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR     lpCmdLine, int       nCmdShow/*��ʾ������󻯣���С��������*/)
{
	hInstance = hInstance;
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
			TEXT("Windows���ڱ���"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			hInstance,
			NULL);

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

	return msg.wParam;
}

/*
MessageBox��

MB_ABORTRETRYIGNORE
0x00000002L The message box contains three push buttons: Abort, Retry, and Ignore.

MB_CANCELTRYCONTINUE
0x00000006L The message box contains three push buttons: Cancel, Try Again, Continue. Use this message box type instead of MB_ABORTRETRYIGNORE.

MB_HELP
0x00004000L Adds a Help button to the message box. When the user clicks the Help button or presses F1, the system sends a WM_HELP message to the owner.

MB_OK
0x00000000L The message box contains one push button: OK. This is the default.

MB_OKCANCEL
0x00000001L The message box contains two push buttons: OK and Cancel.

MB_RETRYCANCEL
0x00000005L The message box contains two push buttons: Retry and Cancel.

MB_YESNO
0x00000004L The message box contains two push buttons: Yes and No.

MB_YESNOCANCEL
0x00000003L The message box contains three push buttons: Yes, No, and Cancel.
*/