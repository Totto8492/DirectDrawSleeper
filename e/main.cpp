#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    STARTUPINFOW startupInfo = {};
    startupInfo.cb = sizeof(STARTUPINFOW);
    PROCESS_INFORMATION info = {};
    if (!CreateProcessW(L"UA.EXE", nullptr, nullptr, nullptr,
                        FALSE, CREATE_SUSPENDED, nullptr, nullptr,
                        &startupInfo, &info))
    {
        return 1;
    }
    void *buffer = VirtualAllocEx(info.hProcess, nullptr, MAX_PATH, MEM_RESERVE|MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    WriteProcessMemory(info.hProcess, buffer, "libd.dll", 9, nullptr);
    const HMODULE module = GetModuleHandleW(L"kernel32");
    const FARPROC api = GetProcAddress(module, "LoadLibraryA");
    const HANDLE thread = CreateRemoteThread(info.hProcess, nullptr, 0, (LPTHREAD_START_ROUTINE)api, buffer, 0, nullptr);
    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);
    VirtualFreeEx(info.hProcess, buffer, 9, MEM_RELEASE);
    ResumeThread(info.hThread);
    return 0;
}
