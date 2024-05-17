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
    short inp;
    
    printf("Bobot Tekanan Darah\n");
    printf("1. Sangat Tinggi\n");
    printf("2. Tinggi\n");
    printf("3. Cukup\n");
    printf("4. Rendah\n");
    printf("5. Sangat Rendah\n");
    printf("Masukkan angka: ");
    scanf("%d", &inp);

    (*a_bobot).bobot_td = inp%inp+
}