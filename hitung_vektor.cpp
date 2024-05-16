#include "pasien.h"

float hitung_vektor(address_pasien *first)
{
    // Kamus Data
    float temp_vektor=1;
    (**first).vektor_total=0;
    
    // ALgoritma
    // penentuan bobot tekanan darah
    (**first).vektor_total += hitung_bobot_td((*first));
    // (**first).vektor_total += 
}

void set_krit(bobot_krit *a_bobot)
{
    int temp_divisor=0;
    temp_divisor += (*a_bobot).bobot_elastis_nadi + (*a_bobot).bobot_hr + (*a_bobot).bobot_n_hr +
                    (*a_bobot).bobot_nadi + (*a_bobot).bobot_napas + (*a_bobot).bobot_suhu +
                    (*a_bobot).bobot_td + (*a_bobot).bobot_tegang_nadi;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_elastis_nadi / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_hr / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_n_hr / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_nadi / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_napas / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_suhu / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_td / temp_divisor;
    (*a_bobot).bobot_elastis_nadi = (*a_bobot).bobot_tegang_nadi / temp_divisor;
}

float hitung_bobot_td(address_pasien first)
{
    // Kamus Data
    float temp_vektor_total=0;
    bobot_krit sebuah_bobot;
    
    // Algoritma
    set_krit(&sebuah_bobot);
    if ((*first).krit.td_sistole < 90) {
        temp_vektor_total += pow(3.0, -sebuah_bobot.bobot_td);
    } else if ((*first).krit.td_sistole >= 90 && (*first).krit.td_sistole <= 119 || (*first).krit.td_diastole < 80) {
        temp_vektor_total += pow(5.0, -sebuah_bobot.bobot_td);
    } else if (((*first).krit.td_sistole >= 120 && (*first).krit.td_sistole <= 139) || ((*first).krit.td_diastole >= 80 && (*first).krit.td_diastole <= 89)) {
        temp_vektor_total += pow(2.0, -sebuah_bobot.bobot_td);
    } else if (((*first).krit.td_sistole >= 140 && (*first).krit.td_sistole <= 159) || ((*first).krit.td_diastole >= 90 && (*first).krit.td_diastole <= 99)) {
        temp_vektor_total += pow(3.0, -sebuah_bobot.bobot_td);
    } else if (((*first).krit.td_sistole >= 160) || ((*first).krit.td_diastole >= 100)) {
        temp_vektor_total += pow(4.0, -sebuah_bobot.bobot_td);
    }
    return temp_vektor_total;
}