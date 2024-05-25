#include "pasien.h"

void kursor(SHORT x, SHORT y) {
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursor_co;
    LPSTR
    
    cursor_co.X = x;
    cursor_co.Y = y;
    SetConsoleCursorPosition(out_handle, cursor_co);
}