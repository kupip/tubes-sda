#include "pasien.h"

void hapus_pasien(Head *first)
{
    if ((*first).prio == NULL ){
        system("cls");
        printf("Belum terdapat data pasien");
    } else {
        int menu=0;
        while (menu != 3) {
            system("cls");
            printf("Menu hapus\n");
            printf("1. Hapus data pasien dari daftar\n");
            printf("2. Hapus data semua pasien\n");
            printf("3. Keluar\n");
            printf("Masukkan angka: ");
            scanf("%d", &menu);
            switch (menu) {
                case 1:
                    hapus_data_pasien(&(*first));
                    break;
                case 2:
                    hapus_data_semua_pasien(&(*first));
                    break;
                case 3:
                    break;
                default:
                    printf("Masukkan input yang valid.");
                    Sleep(2000);
                    break;
            }
        }
    }

    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}

void hapus_data_pasien(Head *first)
{
    address_pasien pdel = (*first).inp;
    if ((*first).prio->p_input == NULL){
         (*first).inp = NULL;
          (*first).prio = NULL;
    } else {
        address_pasien trav=first->inp;
            
        // menampilkan daftar pasien yang ada
        int i=0;
        printf("DAFTAR DATA PASIEN\n");
        while (trav != NULL)
            {
                /* code */
                i++;
                printf("data pasien ke-%d\n",i);
                printf("Nama: %s \n\n", (*trav).nama);
                
                trav = (*trav).p_input;
            }

        // menanyakan urutan data pasien yang ingin dihapus
        int count;
        // urutan pasien dalam daftar
        printf("Masukkan angka (nol untuk batal): ");
        scanf("%d", &count);

        if (count == 0) {
            printf("Penghapusan dibatalkan");
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
                printf("\nTidak terdapat data pada angka yang anda masukkan.");
            }

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
            printf("data berhasil di hapus\n");
            Sleep(2000);
        }
    }
}

void panggil_antrean_pasien(address_pasien *first_prio)
{
    int temp;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    if ((*first_prio)->p_prioritas== NULL) {
        (*first_prio) = NULL;
        system("cls");
        banner();
        printf("\n\n\n");
        center_text("Tidak ada pasien yang tersisa", (unsigned) columns);
    } else {
        system("cls");
        banner();
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t");
        printf("Anda yakin akan memanggil pasien dengan nama %s dari %s?\n", (*first_prio)->nama, (*first_prio)->alamat);
        printf("\t\t\t\t\t\t\t");
        printf("1. Ya\n");
        printf("\t\t\t\t\t\t\t");
        printf("2. Tidak\n");
        printf("\t\t\t\t\t\t\t");
        printf("Masukkan input: ");
        scanf("%d", &temp);
        getchar();
        while (temp != 1 && temp != 2) {
            printf("\t\t\t\t\t\t\t");
            printf("Masukkan input yang valid (1/2): ");
            scanf("%d", &temp);
            getchar();
        }
        if (temp == 1) {
            printf("\t\t\t\t\t\t\t");
            printf("Pasien dengan nama %s dari %s\n", (*first_prio)->nama,(*first_prio)->alamat);
            printf("\t\t\t\t\t\t\t");
            printf("Silakan memasuki ruangan pemeriksaan\n");
            (*first_prio) = (*first_prio)->p_prioritas ;
        }
    }  
    printf("\t\t\t\t\t\t\t");
    printf("Tekan apa pun untuk kembali.");
    getchar();
}

void hapus_data_semua_pasien(Head *first)
{
	address_pasien pdel = (*first).prio;
	
    (*first).inp = NULL;
	while ((*first).prio != NULL){
        (*first).prio = (*first).prio->p_input;
        free(pdel);
        pdel = (*first).prio;
    }
    printf("Data semua pasien berhasil dihapus");
    Sleep(3000);
}