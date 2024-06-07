#include "pasien.h"
#define ATAS_KIRI 196
#define ATAS_KANAN 191
#define BAWAH_KIRI 192
#define BAWAH_KANAN 217
#define HORIZONTAL 196
#define VERTIKAL 179
#define T 194
#define T_PANJANG_KIRI 180
#define T_PANJANG_ATAS 193
#define T_PANJANG_KANAN 195
#define PEREMPATAN 197

void tampilkan_daftar_pasien(Pasien *first)
{
    address_pasien trav=first;
    int jml_pasien=0;

    system("cls");
    if (first == NULL){
        printf("belum terdapat data dalam daftar pasien\n");
    } else {
        printf("DAFTAR DATA PASIEN\n");
        while (trav != NULL)
        {
            /* code */
            jml_pasien++;
            printf("data pasien ke-%d\n", jml_pasien);
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
    }
    
    printf("\n");
    printf("Tekan apapun untuk kembali.\n");
    getchar();
}