#include <iostream>
#include <windows.h>

const int ALT_KEY {VK_LMENU};
const int EXIT_KEY {VK_ESCAPE};
int clickDelay {};

int main()
{
    SetConsoleTitleA("Auto Clicker");
    std::cout << "| Welcome to my 'Auto Clicker'!" << std::endl;
    std::cout << "\n| L Alt  --> Toggle clicking\n| Escape --> Exit the program" << std::endl;
    std::cout << "Enter a click delay (ms): ";
    std::cin >> clickDelay;

    bool clicking {false};
    bool prevAltState {false};
    DWORD lastClickTime {};

    while (true)
    {
        bool currAltState = GetAsyncKeyState(ALT_KEY) & 0x8000;

        if (currAltState && !prevAltState)
        {
            clicking = !clicking;
        }

        else if (GetAsyncKeyState(EXIT_KEY))
        {
            return 0;
        }

        prevAltState = currAltState;

        if (clicking && GetTickCount() - lastClickTime >= clickDelay)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            lastClickTime = GetTickCount();
        }
    }

    return 0;
}
