#include<Windows.h>
#include<WinUser.h>

HINSTANCE hInstance;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
	{
		CreateWindow(L"Button", L"按钮si", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 35, 180, 180, 60, hWnd, NULL, hInstance, NULL);
	}
	break;
	//所有以XXXWindow的方法都不会进入到消息队列中，而是直接执行的
	case WM_CLOSE://发送关闭的消息:WM_DESTROY
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
		MessageBox(hWnd, chp, TEXT("标题"), MB_HELP);
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
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR     lpCmdLine, int       nCmdShow/*显示命令最大化，最小化，正常*/)
{
	hInstance = hInstance;
	/*
	//1：设计窗口
	//2：注册窗口
	//3：创建窗口
	//4：显示和更新
	//5：通过循环取消息
	//6：处理消息（窗口过程）
	*/

	//1：设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0;//类的额外内存
	wc.cbWndExtra = 0;//窗口的额外内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 设置背景
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);// 光标 第一个参数为NULL代表使用系统提供的光标
	wc.hIcon = LoadIcon(NULL, IDI_QUESTION);//图标
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = "MyWindow";
	wc.lpszMenuName = NULL;
	wc.style = 0;

	//2：注册窗口
	RegisterClass(&wc);

	//CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, \
    //    nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\

	//3：创建窗口

	HWND WINAPI  hwnd =
		CreateWindow(wc.lpszClassName,
			TEXT("Windows窗口标题"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			NULL,
			NULL,
			hInstance,
			NULL);

	//4：显示和更新
	ShowWindow(hwnd, SW_NORMAL);
	UpdateWindow(hwnd);

	//5：通过循环取消息
	/*\
	HWND        hwnd;
	UINT        message; 消息名称
	WPARAM      wParam; 附加消息（键盘消息）
	LPARAM      lParam;    附加消息（鼠标消息）
	DWORD       time;       消息产生时间
	POINT       pt;              鼠标的点击位置
	*/
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		/*
		GetMessageW(
		_Out_ LPMSG lpMsg,   MSG消息指针
		_In_opt_ HWND hWnd, 捕获窗口，填NULL代表捕获所有窗口
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

	//6：处理消息（窗口过程）

	return msg.wParam;
}

/*
MessageBox：

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