#include "pasien.h"

void set_bobot_master(bobot_krit *a_bobot)
{
    float temp_divisor=0;
    temp_divisor += (*a_bobot).bobot_elastis_nadi + (*a_bobot).bobot_hr + (*a_bobot).bobot_n_hr +
                    (*a_bobot).bobot_nadi + (*a_bobot).bobot_napas + (*a_bobot).bobot_suhu +
                    (*a_bobot).bobot_td + (*a_bobot).bobot_tegang_nadi;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_elastis_nadi / temp_divisor;
    (*a_bobot).bobot_hr = (*a_bobot).bobot_hr / temp_divisor;
    (*a_bobot).bobot_n_hr = (*a_bobot).bobot_n_hr / temp_divisor;
    (*a_bobot).bobot_nadi = (*a_bobot).bobot_nadi / temp_divisor;
    (*a_bobot).bobot_napas = (*a_bobot).bobot_napas / temp_divisor;
    (*a_bobot).bobot_suhu = (*a_bobot).bobot_suhu / temp_divisor;
    (*a_bobot).bobot_td = (*a_bobot).bobot_td / temp_divisor;
    (*a_bobot).bobot_tegang_nadi = (*a_bobot).bobot_tegang_nadi / temp_divisor;
}

void ubah_bobot_master(bobot_krit *a_bobot)
{   
    bobot_krit temp_bobot=(*a_bobot);
    // Algoritma
    system("cls");
    banner();
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka 0 untuk membatalkan pengubahan\n");
    printf("\t\t\t\t\t\t\t");
    printf("Bobot Tekanan Darah\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_td));
    if ((*a_bobot).bobot_td == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_td = 6 - (*a_bobot).bobot_td;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Detak Nadi\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_nadi));
    if ((*a_bobot).bobot_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_nadi = 6 - (*a_bobot).bobot_nadi;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Detak Jantung\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_hr));
    if ((*a_bobot).bobot_hr == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_hr = 6 - (*a_bobot).bobot_hr;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Frekuensi Napas\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_napas));
    if ((*a_bobot).bobot_napas == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_napas = 6 - (*a_bobot).bobot_napas;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Suhu Badan\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_suhu));
    if ((*a_bobot).bobot_suhu == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_suhu = 6 - (*a_bobot).bobot_suhu;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Tegangan Nadi\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_tegang_nadi));
    if ((*a_bobot).bobot_tegang_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_tegang_nadi = 6 - (*a_bobot).bobot_tegang_nadi;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Korelasi Detak Nadi dan Jantung \n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_n_hr));
    if ((*a_bobot).bobot_n_hr == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_n_hr = 6 - (*a_bobot).bobot_n_hr;

    printf("\t\t\t\t\t\t\t");
    printf("Bobot Elastisitas Nadi\n");
    printf("\t\t\t\t\t\t\t");
    printf("1. Sangat Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("2. Tinggi\n");
    printf("\t\t\t\t\t\t\t");
    printf("3. Cukup\n");
    printf("\t\t\t\t\t\t\t");
    printf("4. Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("5. Sangat Rendah\n");
    printf("\t\t\t\t\t\t\t");
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_elastis_nadi));
    if ((*a_bobot).bobot_elastis_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_elastis_nadi = 6 - (*a_bobot).bobot_elastis_nadi;
}