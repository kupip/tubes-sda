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
        printf("1. Tambah Pasien");
        printf("2. Tampil Daftar Pasien");
        printf("3. Tampil Antrean Pasien");
        printf("4. Hapus Pasien");
        printf("5. Ubah Bobot Master");
        printf("6. Quit");
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
                break;
            default:
                printf("Masukkan input yang valid");
                Sleep(3000);
                break;
        }
    }
}