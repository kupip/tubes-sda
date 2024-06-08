#include "pasien.h"

void tampilkan_daftar_pasien(Pasien *first)
{
    address_pasien trav = first;
    int jml_pasien = 0;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    short columns;
    short kolom=0;
    short baris=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (short) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    system("cls");
    banner();
    baris=11;
    kolom=(short) ((columns/2)-9);
    kursor(kolom, baris++);
    printf("DAFTAR DATA PASIEN");
    if (first == NULL) {
        kolom=(short) ((columns/2)-24);
        kursor(kolom, ++baris);
        printf("Belum terdapat data dalam daftar pasien");
    } else {
        kolom=(short) ((columns/2)-73);
        kursor(kolom, ++baris);
        printf("No. Nama                  Alamat                JK TD Sistole TD Diastole Detak Nadi Detak Jantung Frek. Napas Suhu Badan Elastisitas Tegangan Nadi");
        kursor(kolom, ++baris);
        printf("--- --------------------- --------------------- -- ---------- ----------- ---------- ------------- ----------- ---------- ----------- ------------");
        while (trav != NULL) {
            jml_pasien++;
            kursor(kolom, ++baris);
            printf("%2d. %-21s %-21s %c  %10d %11d %10d %13d %11d %10.1f %-11s %-15s", jml_pasien, (*trav).nama, (*trav).alamat, (*trav).jenis_kelamin, (*trav).krit.td_sistole, (*trav).krit.td_diastole, (*trav).krit.detak_nadi, (*trav).krit.detak_jantung, (*trav).krit.frek_napas, (*trav).krit.suhu_badan, ((*trav).krit.elastisitas_pembuluh_nadi == ELASTIS) ? "elastis" : "keras", ((*trav).krit.tegangan_nadi == TIDAK_BERUBAH) ? "tidak berubah" : "berubah-ubah");
            trav = (*trav).p_input;
        }
        baris++;
        kursor(kolom, ++baris);
        printf("JK: Jenis Kelamin");
    }
    kursor(kolom, ++baris);
    printf("Tekan apapun untuk kembali.");
    getchar();
}

void tampilkan_antrian(Pasien *first)
{
    address_pasien trav = first;
    int jmlh_pasien = 0;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    short columns;
    short kolom=0;
    short baris=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (short) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    system("cls");
    banner();
    kolom=(short) ((columns/2)-7);
    kursor(kolom, 12);
    printf("ANTRIAN PASIEN");
    baris = 14;
    if (first == NULL) {
        kolom=(short) ((columns/2)-17);
        kursor(kolom, baris++);
        printf("Belum terdapat data antrean pasien");
        kursor(kolom, baris);
        printf("Tekan apapun untuk kembali.");
        getchar();
    } else {
        kolom=(short) ((columns/2)-26);
        kursor(kolom, baris++);
        printf("No. Nama Pasien                         Nilai Vektor");
        kursor(kolom, baris++);
        printf("--- ----------------------------------- ------------");
        
        while (trav != NULL) {
            jmlh_pasien++;
            kursor(kolom, baris++);
            printf("%2d. %-35s %.4f", jmlh_pasien, (*trav).nama, (*trav).vektor_total);
            baris++;
            trav = (*trav).p_prioritas;
        }
        kursor(kolom, ++baris);
        printf("Tekan apa pun untuk kembali.");
        getchar();
    }
}