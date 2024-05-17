#include "pasien.h"

int main() {
    // KAMUS DATA
    Head a_head;
    a_head.inp=NULL;
    a_head.prio=NULL;
    address_pasien trav=NULL;
    bobot_krit sebuah_bobot;
    int menu;

    // Algoritma
    while (menu != 6){
        system("cls");
        banner();
        printf("1. Tambah Pasien\n");
        printf("2. Tampil Daftar Pasien\n");
        printf("3. Tampil Antrean Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Ubah Bobot Master\n");
        printf("6. Quit\n");
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
                break;
            case 5:
                ubah_bobot_master(&sebuah_bobot);
                break;
            case 6:
                break;
        }
    }
}