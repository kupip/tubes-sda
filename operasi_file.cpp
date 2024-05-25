#include "pasien.h"

void simpan_file(address_pasien trav) {
    FILE *tulis = fopen("file\\data.dat", "wb");

    while (trav != NULL) {
        fwrite(trav, sizeof(Pasien), 1, tulis);
        trav = (*trav).p_input;
    }

    fclose(tulis);
}