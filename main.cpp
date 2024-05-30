#include "pasien.h"
int main() {
    // Kamus Data
    Head a_head;
    a_head.inp=NULL;
    a_head.prio=NULL;
    address_pasien trav=NULL;
    bobot_krit sebuah_bobot;
    int menu;

    // Algoritma
   baca_file(&a_head);
    while (menu != 8){
        system("cls");
        banner();
        printf("1. Tambah Pasien\n");
        printf("2. Tampil Daftar Pasien\n");
        printf("3. Tampil Antrean Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Ubah Bobot Master\n");
        printf("6. Panduan\n");
        printf("7. Kredit\n");
        printf("8. Quit\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d",&menu);
        getchar();

        switch (menu) {
            case 1:
                tambah_pasien(&(a_head), &trav, sebuah_bobot);
                break;
            case 2:
                tampilkan_daftar_pasien(a_head.inp);
                break;
            case 3:
                tampilkan_antrian(a_head.prio);
                break;
            case 4:
                hapus_pasien (&(a_head));
                break;
            case 5:
                ubah_bobot_master(&sebuah_bobot);
                break;
            case 6:
                tampil_panduan();
                break;
            case 7:
                tampil_kredit();
                break;
            case 8:
                simpan_file(a_head.inp);
                break;
            default:
                printf("Masukkan input yang valid");
                Sleep(3000);
                break;
        }
    }
}