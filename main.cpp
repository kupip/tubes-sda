#include "pasien.h"

int main() {
    // KAMUS DATA
    Head a_head;
    a_head.inp=NULL;
    a_head.prio=NULL;
    address_pasien trav=NULL;
    int menu;

    // Algoritma
    while (menu != 5){
        system("cls");
        banner();
        printf("1. Tambah Pasien\n");
        printf("2. Tampil Daftar Pasien\n");
        printf("3. Tampil Antrean Pasien\n");
        printf("4. Hapus Pasien\n");
        printf("5. Quit\n");
        printf("Masukkan pilihan anda :");
        scanf("%d",&menu);
        getchar();

        switch (menu) {
            case 1:
                tambah_pasien(&(a_head), &trav);
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
                break;
        }
    }
}