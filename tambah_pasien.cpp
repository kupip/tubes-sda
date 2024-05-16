#include "pasien.h"
void input_kriteria(Pasien *temp_pasien);

void tambah_pasien(Pasien **first, Pasien **trav) {
    Pasien *temp_pasien = (Pasien*) malloc(sizeof(Pasien));
    temp_pasien->p_input=NULL;
    temp_pasien->p_prioritas=NULL;

    printf("Masukkan nama pasien: ");
    scanf("%s", (*temp_pasien).nama);
    getchar();

    printf("Masukkan alamat: ");
    scanf("%s", (*temp_pasien).alamat);
    getchar();

    printf("Masukkan jenis kelamin (L/P): ");
    scanf("%c", &((*temp_pasien).jenis_kelamin));
    getchar();
    strupr(&((*temp_pasien).jenis_kelamin));
    while ((*temp_pasien).jenis_kelamin != 'L' && (*temp_pasien).jenis_kelamin != 'P' )
    {
        /* code */
        printf("Masukkan input yang sesuai (L/P): ");
        scanf("%c", &((*temp_pasien).jenis_kelamin));
        getchar();
    }
    input_kriteria(&(*temp_pasien));

    if ((*first) == NULL) {
        (*first) = temp_pasien;
    } else {
        *trav = (*first);
        while ((*trav)->p_input != NULL)
        {
            /* code */
            (*trav) = (*trav)->p_input;
        }
        (*trav)->p_input = temp_pasien;
    }
}

void input_kriteria(Pasien *temp_pasien) {
    int temp=0;

    printf("Masukkan tekanan darah sistole: ");
    scanf("%d", &((*temp_pasien).krit.td_sistole));

    printf("Masukkan tekanan darah diastole: ");
    scanf("%d", &((*temp_pasien).krit.td_diastole));

    printf("Masukkan detak nadi: ");
    scanf("%d", &((*temp_pasien).krit.detak_nadi));

    printf("Masukkan detak jantung: ");
    scanf("%d", &((*temp_pasien).krit.detak_jantung));

    (*temp_pasien).krit.hr_x_nadi = (*temp_pasien).krit.detak_jantung - (*temp_pasien).krit.detak_nadi;
    
    printf("Masukkan frekuensi pernapasan: ");
    scanf("%d", &((*temp_pasien).krit.frek_napas));

    printf("Masukkan suhu tubuh: ");
    scanf("%f", &((*temp_pasien).krit.suhu_badan));

    printf("Tegangan nadi\n1. Tidak Berubah\n2. Kuat dan Lemah Berubah-ubah\nMasukkan angka: ");
    scanf("%d", &temp);
    // antisipasi input error
    while (temp != 1 && temp != 2)
    {
        /* code */
        printf("Masukkan input yang valid: ");
        scanf("%d", &temp);
    }
    if (temp == 1) {
        (*temp_pasien).krit.tegangan_nadi = TIDAK_BERUBAH;
    } else {
        (*temp_pasien).krit.tegangan_nadi = BERUBAH;
    }

    printf("\nElastisitas pembuluh nadi\n1. Elastis\n2. Keras seperti kawat\nMasukkan angka: ");
    scanf("%d", &temp);
    // antisipasi input error
    while (temp != 1 && temp != 2)
    {
        /* code */
        printf("Masukkan input yang valid: ");
        scanf("%d", &temp);
    }
    if (temp == 1) {
        /* code */
        (*temp_pasien).krit.elastisitas_pembuluh_nadi = ELASTIS;
    } else {
        (*temp_pasien).krit.elastisitas_pembuluh_nadi = KERAS;
    }
    system("cls");
}