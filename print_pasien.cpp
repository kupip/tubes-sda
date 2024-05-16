#include "pasien.h"

void tampilkan_daftar_pasien(Pasien *first) {
    address_pasien trav=first;
    while (trav != NULL)
    {
        /* code */
        printf("Nama: %s ", (*trav).nama);
        printf("Suhu badan: %.1f", (*trav).krit.suhu_badan);
        printf("\n");
        trav = (*trav).p_input;
    }
    printf("\n");
}