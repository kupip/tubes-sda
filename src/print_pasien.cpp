#include "pasien.h"

void tampilkan_daftar_pasien(Pasien *first)
{
    address_pasien trav = first;
    int jml_pasien = 0;

    system("cls");
    kursor(30, 2);
    printf("DAFTAR DATA PASIEN");

    if (first == NULL) {
        kursor(10, 5);
        printf("Belum terdapat data dalam daftar pasien");
    } else {
        kursor(5, 5);
        printf("No. Nama                  Alamat                JK TD Sistole TD Diastole Detak Nadi Detak Jantung Frek. Napas Suhu Badan Elastisitas Tegangan Nadi");
        kursor(5, 6);
        printf("--- --------------------- --------------------- -- ---------- ----------- ---------- ------------- ----------- ---------- ----------- ------------");

        int baris = 7;
        while (trav != NULL) {
            jml_pasien++;
            kursor(5, (short) baris);
            printf("%2d. %-21s %-21s %c  %10d %11d %10d %13d %11d %10.1f %-11s %-15s", jml_pasien, (*trav).nama, (*trav).alamat, (*trav).jenis_kelamin, (*trav).krit.td_sistole, (*trav).krit.td_diastole, (*trav).krit.detak_nadi, (*trav).krit.detak_jantung, (*trav).krit.frek_napas, (*trav).krit.suhu_badan, ((*trav).krit.elastisitas_pembuluh_nadi == ELASTIS) ? "elastis" : "keras", ((*trav).krit.tegangan_nadi == TIDAK_BERUBAH) ? "tidak berubah" : "berubah-ubah");
            baris++;
            trav = (*trav).p_input;
        }
        kursor(5, (short) ++baris);
        printf("JK: Jenis Kelamin");
    }
    printf("\n");
    printf("\tTekan apapun untuk kembali.\n");
    getchar();
}

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