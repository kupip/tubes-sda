#include "pasien.h"

void print_menu_utama();
void center_text(const char *text, unsigned int field_width);

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
    while (menu != 9){
        system("cls");
        banner();
        print_menu_utama();
        // printf("1. Tambah Pasien\n");
        // printf("2. Tampil Daftar Pasien\n");
        // printf("3. Tampil Antrean Pasien\n");
        // printf("4. Proses antrean (panggil pasien)\n");
        // printf("5. Hapus Pasien\n");
        // printf("6. Ubah Bobot Master\n");
        // printf("7. Panduan\n");
        // printf("8. Kredit\n");
        // printf("9. Quit\n");
        // printf("Masukkan pilihan anda: ");
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
                hapus_pasien (&(a_head));
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
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    
    center_text("1. Tambah Pasien", columns);
    // printf("1. Tambah Pasien\n");
    // printf("2. Tampil Daftar Pasien\n");
    // printf("3. Tampil Antrean Pasien\n");
    // printf("4. Proses antrean (panggil pasien)\n");
    // printf("5. Hapus Pasien\n");
    // printf("6. Ubah Bobot Master\n");
    // printf("7. Panduan\n");
    // printf("8. Kredit\n");
    // printf("9. Quit\n");   
}

void center_text(const char *text, unsigned int field_width) {
    unsigned int pad_len = (field_width - strlen(text)) / 2;
    printf("%*s%s%*s\n", pad_len, "", text, pad_len, "");
} 