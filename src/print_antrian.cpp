#include "pasien.h"

void tampilkan_antrian(Pasien *first)
{
    address_pasien trav = first;
    int jmlh_pasien = 0;

    system("cls");


    kursor(30, 5);
    printf("ANTRIAN PASIEN");
    int baris = 10;
    if (first == NULL) {
        kursor(20, 8);
        printf("Belum terdapat data antrean pasien");
    } else {
        kursor(5, 8);
        printf("No. Nama Pasien                          Nilai Vektor");
        kursor(5, 9);
        printf("--- -------------------------------------- ------------");

        
        while (trav != NULL) {
            jmlh_pasien++;
            kursor(5, (short)baris);
            printf("%2d. %-35s %.4f", jmlh_pasien, (*trav).nama, (*trav).vektor_total);
            baris++;
            trav = (*trav).p_prioritas;
        }
    }

    kursor(20,(short) (baris + 2));
    printf("\n");
    printf("\t\t\t\t\t\t\t");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}