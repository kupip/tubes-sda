#include "pasien.h"

void tampilkan_antrian(Pasien *first)
{
    address_pasien trav=first;
    int jmlh_pasien = 0;

    system("cls");
    banner();
    printf("\n\n\n");
    if (first == NULL){
        printf("\t\t\t\t\t\t\t");
        printf("belum terdapat data antrean pasien\n");
    } else {
        printf("\t\t\t\t\t\t\t");
        printf("Antrian pasien\n");
        while (trav != NULL)
        {
            jmlh_pasien++;
            printf("\t\t\t\t\t\t\t");
            printf("%d. %s dengan nilai vektor %.4f\n", jmlh_pasien, (*trav).nama, (*trav).vektor_total);
            trav = (*trav).p_prioritas;
        }
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}