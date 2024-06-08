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
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    short columns;
    short kolom=0;
    short baris=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (short) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    system("cls");
    banner();
    kolom=(short) ((columns/2)-26);
    baris=10;
    kursor(kolom, ++baris);
    printf("Masukkan angka 0 untuk membatalkan pengubahan");
    kursor(kolom, ++baris);
    printf("Bobot Tekanan Darah");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_td));
    if ((*a_bobot).bobot_td == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_td = 6 - (*a_bobot).bobot_td;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Detak Nadi");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_nadi));
    if ((*a_bobot).bobot_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_nadi = 6 - (*a_bobot).bobot_nadi;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Detak Jantung");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_hr));
    if ((*a_bobot).bobot_hr == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_hr = 6 - (*a_bobot).bobot_hr;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Frekuensi Napas");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_napas));
    if ((*a_bobot).bobot_napas == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_napas = 6 - (*a_bobot).bobot_napas;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Suhu Badan");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_suhu));
    if ((*a_bobot).bobot_suhu == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_suhu = 6 - (*a_bobot).bobot_suhu;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Tegangan Nadi");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_tegang_nadi));
    if ((*a_bobot).bobot_tegang_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_tegang_nadi = 6 - (*a_bobot).bobot_tegang_nadi;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Korelasi Detak Nadi dan Jantung ");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_n_hr));
    if ((*a_bobot).bobot_n_hr == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_n_hr = 6 - (*a_bobot).bobot_n_hr;

    baris++;
    kursor(kolom, ++baris);
    printf("Bobot Elastisitas Nadi");
    kursor(kolom, ++baris);
    printf("1. Sangat Tinggi");
    kursor(kolom, ++baris);
    printf("2. Tinggi");
    kursor(kolom, ++baris);
    printf("3. Cukup");
    kursor(kolom, ++baris);
    printf("4. Rendah");
    kursor(kolom, ++baris);
    printf("5. Sangat Rendah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%f", &((*a_bobot).bobot_elastis_nadi));
    if ((*a_bobot).bobot_elastis_nadi == 0) {
        (*a_bobot)=temp_bobot;
        return;
    }
    (*a_bobot).bobot_elastis_nadi = 6 - (*a_bobot).bobot_elastis_nadi;
}