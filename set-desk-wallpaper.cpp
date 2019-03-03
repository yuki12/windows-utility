// call SETDESKWALLPAPER
// Usage: set-desk-wallpaper [file name]
//   [file name] may also be relative path.
//   Unset wallpaper if [file name] is empty.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

extern "C" int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
    if (argc <= 1)
    {
        ::SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (PVOID)L"", SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        return EXIT_SUCCESS;
    }
    else
    {
        wchar_t *relative = argv[1];
        wchar_t full[MAX_PATH];
        DWORD length = ::GetFullPathNameW(relative, MAX_PATH, full, nullptr);
        if (0 == length)
        {
            return EXIT_FAILURE;
        }
        BOOL result = ::SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, full, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
        return result ? EXIT_SUCCESS : EXIT_FAILURE;
    }
}
