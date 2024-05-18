#include "pasien.h"

void hapus_pasien (Head *first){
    system("cls");
    if ((*first).prio == NULL ){
        printf("Belum terdapat data pasien");
    } else {
        address_pasien pdel=(*first).inp;
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
            printf("Nama: %s \n", (*trav).nama);
            
            trav = (*trav).p_input;
            }

            // menanyakan urutan data pasien yang ingin di hapus
            int count;
            // urutan pasien dalam daftar
            printf("Masukkan angka : ");
            scanf("%d", &count);

            // hapus sesuai daftar input
            address_pasien q = NULL;
 	        i=0;
            while (pdel != NULL &&  i!= (count-1))
                {
                    q = pdel;
                    pdel = pdel->p_input;
                    i++;
                }

            // countnya ga sesuai
            if (pdel == NULL)
            {
                printf("\ntidak terdapat data pada angka yang anda masukkan ");
            }


            if (q == NULL)
            {
                (*first).inp = pdel->p_input;
            } else {
                q->p_input = pdel->p_input;
            }

            
            // hapus sesuai daftar sesuai prio
            address_pasien trav2 = first->prio;
            address_pasien curr = NULL;
            while (trav2 != pdel)
                {
                    curr = trav2;
                    trav2 = trav2->p_prioritas;
                }

            if (curr == NULL) {
                (*first).prio = trav2->p_prioritas;
                } else {
                curr->p_prioritas = trav2->p_prioritas;
                }
               
            pdel->p_prioritas = NULL;
            pdel->p_input= NULL;
        }
        free(pdel);
        printf("data berhasil di hapus\n");
    }

    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}