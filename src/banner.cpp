#include "pasien.h"

void banner()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    center_text(".-------.       .-'''-.                  .-''-. ,---------. .---.  .---.    ____    ,---.   .--..-./`)     .-''-.    .---.     ", (unsigned) columns);
    printf("\n");
    center_text("|  _ _   \\     / _     \\               .'_ _   \\\\          \\|   |  |_ _|  .'  __ `. |    \\  |  |\\ .-.')  .'_ _   \\   | ,_|     ", (unsigned) columns);
    printf("\n");
    center_text("| ( ' )  |    (`' )/`--'              / ( ` )   '`--.  ,---'|   |  ( ' ) /   '  \\  \\|  ,  \\ |  |/ `-' \\ / ( ` )   ',-./  )     ", (unsigned) columns);
    printf("\n");
    center_text("|(_ o _) /   (_ o _).                . (_ o _)  |   |   \\   |   '-(_{;}_)|___|  /  ||  |\\_ \\|  | `-'`\"`. (_ o _)  |\\  '_ '`)    ", (unsigned) columns);
    printf("\n");
    center_text("| (_,_).' __  (_,_). '.              |  (_,_)___|   :_ _:   |      (_,_)    _.-`   ||  _( )_\\  | .---. |  (_,_)___| > (_)  )    ", (unsigned) columns);
    printf("\n");
    center_text("|  |\\ \\  |  |.---.  \\  : _ _         '  \\   .---.   (_I_)   | _ _--.   | .'   _    || (_ o _)  | |   | '  \\   .---.(  .  .-'    ", (unsigned) columns);
    printf("\n");
    center_text("|  | \\ `'   /\\    `-'  |( ` )         \\  `-'    /  (_(=)_)  |( ' ) |   | |  _( )_  ||  (_,_)\\  | |   |  \\  `-'    / `-'`-'|___ ", (unsigned) columns);
    printf("\n");
    center_text("|  |  \\    /  \\       /(_{;}_)         \\       /    (_I_)   (_{;}_)|   | \\ (_ o _) /|  |    |  | |   |   \\       /   |        \\", (unsigned) columns);
    printf("\n");
    center_text("''-'   `'-'    `-...-'  (_,_)           `'-..-'     '---'   '(_,_) '---'  '.(_,_).' '--'    '--' '---'    `'-..-'    `--------`", (unsigned) columns);
}