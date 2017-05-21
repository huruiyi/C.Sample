#pragma once

__declspec(dllexport) void * InEncry(char * ch, int len);
__declspec(dllexport) char * OutEncry(void * ch, int len);