#include "pasien.h"


void hapus_pasien (Head *first){
    system("cls");
    if ((*first).prio == NULL ){
        printf("Belum terdapat data pasien");
    } else {
        int menu;
        printf("Menu hapus\n");
        printf("1. Hapus data pasien dari daftar\n");
        printf("2. Hapus data pasien dari antrean\n");
        printf("Masukkan angka: ");
        scanf("%d", &menu);
        if (menu == 1){
            hapus_data_pasien(&(*first));
        } else if (menu == 2){
            hapus_antrean_pasien(&((*first).prio));
        } else {
            printf("Masukkan angka yang benar\n");
            while (menu != 1 && menu != 2) {
                printf("Masukkan angka: ");
                scanf("%d", &menu);
            }
        }
    }

    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}

void hapus_data_pasien(Head *first){
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
        printf("Masukkan angka: ");
        scanf("%d", &count);

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
               
        pdel->p_prioritas = NULL;
        pdel->p_input= NULL;
          }
        free(pdel);
        printf("data berhasil di hapus\n");
}

void hapus_antrean_pasien(address_pasien *first){
    if ((*first)->p_prioritas== NULL){
        (*first) = NULL;
    } else {
        (*first) = (*first)->p_prioritas ;
    }
    system("cls");
    printf("Antrean saat ini");
    address_pasien trav = *first;
    int jmlh_pasien=0;
     while (trav != NULL)
    {   
        jmlh_pasien++;
        /* code */
        printf("%d. %s dengan nilai vektor %.4f\n", jmlh_pasien, (*trav).nama, (*trav).vektor_total);
        trav = (*trav).p_prioritas;
    }
}