#include "pasien.h"

void tampilkan_antrian(Pasien *first) {
    address_pasien trav=first;
    int jmlh_pasien = 0;

    system("cls");
    printf("Antrian pasien\n");
    while (trav != NULL)
    {   
        jmlh_pasien++;
        /* code */
        printf("%d. %s dengan nilai vektor %.4f\n", jmlh_pasien, (*trav).nama, (*trav).vektor_total);
        trav = (*trav).p_prioritas;
    }
    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}