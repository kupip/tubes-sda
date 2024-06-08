#include "pasien.h"
#define ATAS_KIRI 196
#define ATAS_KANAN 191
#define BAWAH_KIRI 192
#define BAWAH_KANAN 217
#define HORIZONTAL 196
#define VERTIKAL 179
#define T 194
#define T_PANJANG_KIRI 180
#define T_PANJANG_ATAS 193
#define T_PANJANG_KANAN 195
#define PEREMPATAN 197

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
        printf("No. Nama                  Alamat                Jenis Kelamin TD Sistole TD Diastole Detak Nadi Detak Jantung Frek. Napas Suhu Badan Elastisitas Tegangan Nadi");
        kursor(5, 6);
        printf("--- ---------------------- ---------------------- ------------- ---------- ------------ ---------- ------------- ----------- ---------- ----------- ------------");

        int baris = 7;
        while (trav != NULL) {
            jml_pasien++;
            kursor(5, (short) baris);
            printf("%2d. %-21s %-21s %c             %3d        %3d         %3d        %3d          %3d        %4.1f   %-11s %-15s", jml_pasien, (*trav).nama, (*trav).alamat, (*trav).jenis_kelamin, (*trav).krit.td_sistole, (*trav).krit.td_diastole, (*trav).krit.detak_nadi, (*trav).krit.detak_jantung, (*trav).krit.frek_napas, (*trav).krit.suhu_badan, ((*trav).krit.elastisitas_pembuluh_nadi == ELASTIS) ? "elastis" : "keras", ((*trav).krit.tegangan_nadi == TIDAK_BERUBAH) ? "tidak berubah" : "berubah-ubah");
            baris++;
            trav = (*trav).p_input;
        }
    }
    
    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}