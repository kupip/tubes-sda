#include "pasien.h"

void tampilkan_daftar_pasien(Pasien *first)
{
    address_pasien trav=first;

    system("cls");
    printf("DAFTAR DATA PASIEN\n");
    while (trav != NULL)
    {
        /* code */
        printf("data pasien ke-%d\n",(*trav).id);
        printf("Nama: %s \n", (*trav).nama);
        printf("Alamat: %s\n", (*trav).alamat);
        printf("Jenis kelamin: %c\n", (*trav).jenis_kelamin);
        printf("Tekanan darah sistolik: %d\n", (*trav).krit.td_sistole);
        printf("Tekanan darah diastolik: %d\n", (*trav).krit.td_diastole);
        printf("Detak nadi: %d\n",(*trav).krit.detak_nadi);
        printf("Detak jantung: %d\n", (*trav).krit.detak_jantung);
        printf("Frekuensi pernapasan: %d\n", (*trav).krit.frek_napas);
        printf("Suhu badan: %.1f\n", (*trav).krit.suhu_badan);
        if((*trav).krit.elastisitas_pembuluh_nadi == ELASTIS){
            printf("Elastisitas pembuluh nadi: elastis\n");
        } else {
            printf("Elastisitas pembuluh nadi: keras seperti kawat\n");
        }
        if((*trav).krit.tegangan_nadi == TIDAK_BERUBAH){
            printf("Tegangan nadi: tidak berubah-ubah\n");
        } else {
            printf("Tegangan nadi: kuat dan lemah berubah-ubah\n");
        }
        printf("\n");
        trav = (*trav).p_input;
    }
    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}