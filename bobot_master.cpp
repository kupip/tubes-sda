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
    // Algoritma
    printf("Bobot Tekanan Darah\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_td));
    (*a_bobot).bobot_td -= 6;

    printf("Bobot Detak Nadi\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_nadi));
    (*a_bobot).bobot_nadi -= 6;

    printf("Bobot Detak Jantung\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_hr));
    (*a_bobot).bobot_hr -= 6;

    printf("Bobot Frekuensi Napas\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_napas));
    (*a_bobot).bobot_napas -= 6;

    printf("Bobot Suhu Badan\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_suhu));
    (*a_bobot).bobot_suhu -= 6;

    printf("Bobot Tegangan Nadi\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_tegang_nadi));
    (*a_bobot).bobot_tegang_nadi -= 6;

    printf("Bobot Korelasi Detak Nadi dan Jantung \n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_n_hr));
    (*a_bobot).bobot_n_hr -= 6;

    printf("Bobot Elastisitas Nadi\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &((*a_bobot).bobot_elastis_nadi));
    (*a_bobot).bobot_elastis_nadi -= 6;
}