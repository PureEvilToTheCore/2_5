#include "asserts.h"

void Assert(bool condition, const char* message, const char* file, int line)
{
    bool retry = true; 
    while (retry)
    {
        if (!condition)
        {
            char assertionMessage[512];
            snprintf(assertionMessage, sizeof(assertionMessage), "Assertion Failed!\n\nFile: %s\nLine: %d\n\n%s", file, line, message);
            int choice = MessageBoxA(NULL, assertionMessage, "Assertion Failed!", MB_ABORTRETRYIGNORE | MB_ICONERROR | MB_TOPMOST);
            if (choice == IDABORT)
            {
                ExitProcess(EXIT_FAILURE);
            }
            else if (choice == IDIGNORE)
            {
                retry = false;
            }
        }
        else // condition == true
        {
            retry = false; // если условие выполняется, выходим из цикла
        }

    }
}
void FatalError(bool condition, const char* message, int returnValue)
{
    if (!condition)
    {
        MessageBoxA(NULL, message, "Fatal Error", MB_OK | MB_ICONERROR | MB_TOPMOST);
        ExitProcess(returnValue);
    }
}
