#include "pasien.h"

void hapus_pasien(Head *first)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    short baris=0;
    short kolom=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    if ((*first).prio == NULL ) {
        kolom=(short) ((columns/2)-13);
        system("cls");
        banner();
        kursor(kolom, 11);
        printf("Belum terdapat data pasien");
    } else {
        int menu=0;
        while (menu != 3) {
            baris=10;
            kolom=(short) ((columns/2)-18);
            system("cls");
            banner();
            kursor(kolom, ++baris);
            printf("Menu hapus");
            kursor(kolom, ++baris);
            printf("1. Hapus data pasien dari daftar");
            kursor(kolom, ++baris);
            printf("2. Hapus data semua pasien");
            kursor(kolom, ++baris);
            printf("3. Keluar");
            kursor(kolom, ++baris);
            printf("Masukkan angka: ");
            scanf("%d", &menu);
            switch (menu) {
                case 1:
                    hapus_data_pasien(&(*first));
                    break;
                case 2:
                    kursor(kolom, ++baris);
                    printf("Anda yakin ingin menghapus data seluruh pasien?");
                    kursor(kolom, ++baris);
                    printf("1. Ya");
                    kursor(kolom, ++baris);
                    printf("2. Tidak");
                    kursor(kolom, ++baris);
                    printf("Masukkan angka: ");
                    scanf("%d", &menu);
                    while (menu != 1 && menu != 2) {
                        kursor(kolom, ++baris);
                        printf("Masukkan input yang valid: ");
                        scanf("%d", &menu);
                    }
                    if (menu == 1) {
                        hapus_data_semua_pasien(&(*first));
                    } else {
                        kursor(kolom, ++baris);
                        printf("Penghapusan dibatalkan.");
                        Sleep(2000);
                    }
                    break;
                case 3:
                    break;
                default:
                    kursor(kolom, ++baris);
                    printf("Masukkan input yang valid.");
                    Sleep(2000);
                    break;
            }
        }
    }
    kursor(kolom, ++baris);
    printf("Tekan apapun untuk kembali.");
    getchar();
}

void hapus_data_pasien(Head *first)
{
    address_pasien pdel = (*first).inp;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    short baris=0;
    short kolom=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    baris=10;
    system("cls");
    banner();
    if ((*first).prio->p_input == NULL) {
        kolom=(short) ((columns/2)-19);
        kursor(kolom, ++baris);
        printf("Tersisa satu pasien yaitu %s", (*first).prio->nama);
        kursor(kolom, ++baris);
        printf("Apakah anda ingin menghapus datanya?");
        kursor(kolom, ++baris);
        printf("1. Ya");
        kursor(kolom, ++baris);
        printf("2. Tidak");
        kursor(kolom, ++baris);
        printf("Masukkan input");
        int temp;
        scanf("%d", &temp);
        while (temp != 1 && temp != 2) {
            kursor(kolom, ++baris);
            printf("Masukkan input yang valid: ");
            scanf("%d", &temp);
        }
        if (temp == 1) {
            (*first).inp = NULL;
            (*first).prio = NULL;
            kursor(kolom, ++baris);
            printf("Pasien berhasil dihapus");
            Sleep(2000);
        }
    } else {
        address_pasien trav=first->inp;
        // menampilkan daftar pasien yang ada
        int i=0;
        kursor((short) ((columns/2)-3), ++baris);
        printf("DAFTAR DATA PASIEN");
        kolom=(short) ((columns/2)-17);
        while (trav != NULL)
            {
                /* code */
                i++;
                kursor(kolom, ++baris);
                printf("Data pasien ke-%d",i);
                kursor(kolom, ++baris);
                printf("Nama: %s", (*trav).nama);
                baris++;
                trav = (*trav).p_input;
            }

        // menanyakan urutan data pasien yang ingin dihapus
        int count;
        // urutan pasien dalam daftar
        kursor(kolom, ++baris);
        printf("Masukkan angka (nol untuk batal): ");
        scanf("%d", &count);

        if (count == 0) {
            kursor(kolom, ++baris);
            printf("Penghapusan dibatalkan.");
            Sleep(2000);
        } else {
            // hapus sesuai daftar input
            address_pasien prev_del_inp = NULL;
            i = 0;
            while (pdel != NULL &&  i != (count-1)) {
                prev_del_inp = pdel;
                pdel = pdel->p_input;
                i++;
            }

            // countnya ga sesuai
            if (pdel == NULL) {
                kursor(kolom, ++baris);
                printf("Tidak terdapat data pada angka yang anda masukkan.");
                kursor(kolom, ++baris);
                printf("Penghapusan dibatalkan.");
                Sleep(2000);
            } else {
                // penyambungan pointer inp
                if (prev_del_inp == NULL) { // node yang dihapus adalah node pertama
                    (*first).inp = pdel->p_input;
                } else {
                    prev_del_inp->p_input = pdel->p_input;
                }
                    
                // penyambungan pointer prio
                address_pasien trav2 = first->prio;
                address_pasien prev_del_prio = NULL;
                while (trav2 != pdel) {
                    prev_del_prio = trav2;
                    trav2 = trav2->p_prioritas;
                }

                if (prev_del_prio == NULL) { // node yang dihapus adalah node pertama
                    (*first).prio = trav2->p_prioritas;
                } else {
                    prev_del_prio->p_prioritas = trav2->p_prioritas;
                }

                free(pdel);
                kursor(kolom, ++baris);
                printf("Data berhasil di hapus.");
                Sleep(2000);
            }
        }
    }
}

void panggil_antrean_pasien(address_pasien *first_prio)
{
    int temp;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    short baris=0;
    short kolom=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    baris=10;
    if ((*first_prio)->p_prioritas== NULL) {
        (*first_prio) = NULL;
        system("cls");
        banner();
        kolom=(short) ((columns/2)-15);
        kursor(kolom, ++baris);
        printf("Tidak ada pasien yang tersisa.");
    } else {
        system("cls");
        banner();
        kolom=(short) ((columns/2)-30);
        kursor(kolom, ++baris);
        printf("Anda yakin akan memanggil pasien dengan nama %s dari %s?", (*first_prio)->nama, (*first_prio)->alamat);
        kursor(kolom, ++baris);
        printf("1. Ya");
        kursor(kolom, ++baris);
        printf("2. Tidak");
        kursor(kolom, ++baris);
        printf("Masukkan input: ");
        scanf("%d", &temp);
        getchar();
        while (temp != 1 && temp != 2) {
            kursor(kolom, ++baris);
            printf("Masukkan input yang valid: ");
            scanf("%d", &temp);
            getchar();
        }
        if (temp == 1) {
            kursor(kolom, ++baris);
            printf("Pasien dengan nama %s dari %s", (*first_prio)->nama,(*first_prio)->alamat);
            kursor(kolom, ++baris);
            printf("Silakan memasuki ruangan pemeriksaan");
            (*first_prio) = (*first_prio)->p_prioritas ;
        }
    }  
    kursor(kolom, ++baris);
    printf("Tekan apa pun untuk kembali.");
    getchar();
}

void hapus_data_semua_pasien(Head *first)
{
	address_pasien pdel = (*first).prio;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    (*first).inp = NULL;
	while ((*first).prio != NULL){
        (*first).prio = (*first).prio->p_input;
        free(pdel);
        pdel = (*first).prio;
    }
    system("cls");
    banner();
    kursor((short) ((columns/2)-18), 12);
    printf("Data semua pasien berhasil dihapus.");
    Sleep(2000);
}