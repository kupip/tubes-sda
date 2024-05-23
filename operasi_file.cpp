#include "pasien.h"

void simpan_file(address_pasien trav) {
    FILE *tulis = fopen("file\\data.dat", "wb");

    while (trav != NULL)
    {
        /* code */
        fwrite(trav, sizeof(Pasien), 1, tulis);
        trav = (*trav).p_input;
    }
}