#include "pasien.h"

float hitung_vektor(address_pasien *first) {
    float temp_vektor=1;
    bobot_krit sebuah_bobot;
    set_krit(&sebuah_bobot);
    
    // penentuan bobot tekanan dara
    if ((**first).krit.td_sistole < 90)
    {
        /* code */
        (*first)->vektor_total = 3*sebuah_bobot.bobot_td;
        exp(sebuah_bobot.bobot_td);
    }
    
}

void set_krit(bobot_krit *a_bobot) {
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