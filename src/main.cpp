#include "pasien.h"

int main() {
    // Kamus Data
    Head a_head;
    a_head.inp=NULL;
    a_head.prio=NULL;
    address_pasien trav=NULL;
    bobot_krit sebuah_bobot;
    int menu;

    // maximize window
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    // Algoritma
    baca_file(&a_head);
    while (menu != 9){
        system("cls");
        banner();
        print_menu_utama();
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
                panggil_antrean_pasien(&(a_head.prio));
                break;
            case 5:
                tampil_menu_hapus_pasien(&(a_head));
                break;
            case 6:
                ubah_bobot_master(&sebuah_bobot);
                break;
            case 7:
                tampil_panduan();
                break;
            case 8:
                tampil_kredit();
                break;
            case 9:
                simpan_file(a_head.inp);
                break;
            default:
                printf("Masukkan input yang valid");
                Sleep(3000);
                break;
        }
    }
}

void print_menu_utama()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    short kolom, baris;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    kolom = (short) ((columns/2)-19);
    baris=10;
    
    kursor(kolom, ++baris);
    printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");
    kursor(kolom, ++baris);
    printf("\xBA 1. Tambah Pasien                   \xBA");
    kursor(kolom, ++baris);
    printf("\xBA 2. Tampil Daftar Pasien            \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 3. Tampil Antrean Pasien           \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 4. Proses antrean (panggil pasien) \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 5. Hapus Pasien                    \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 6. Ubah Bobot Master               \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 7. Panduan                         \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 8. Kredit                          \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xBA 9. Quit                            \xBA", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC", (unsigned) columns);
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
}