#include "pasien.h"

float hitung_bobot_td(address_pasien first, bobot_krit sebuah_bobot);
float hitung_bobot_nadi(address_pasien to_count, bobot_krit sebuah_bobot);
float hitung_bobot_hr(address_pasien to_count, bobot_krit sebuah_bobot);
float hitung_bobot_korelasi(address_pasien to_count, bobot_krit a_bobot);
float hitung_bobot_tegang_nadi(address_pasien to_decide, bobot_krit a_bobot);
float hitung_bobot_elastis_nadi(address_pasien to_decide, bobot_krit a_bobot);
float hitung_bobot_napas(address_pasien to_decide, bobot_krit a_bobot);
float hitung_bobot_suhu(address_pasien to_decide, bobot_krit a_bobot);

void hitung_vektor(address_pasien *first)
{
    // Kamus Data
    (**first).vektor_total=0;
    bobot_krit sebuah_bobot;
    
    // Algoritma
    set_bobot_master(&sebuah_bobot);
    (**first).vektor_total += hitung_bobot_td(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_nadi(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_hr(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_korelasi(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_tegang_nadi(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_elastis_nadi(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_napas(*first, sebuah_bobot);
    (**first).vektor_total += hitung_bobot_suhu(*first, sebuah_bobot);
}

float hitung_bobot_td(address_pasien to_count, bobot_krit sebuah_bobot)
{
    // Algoritma
    if ((*to_count).krit.td_sistole < 90) {
        return powf(3.0, -sebuah_bobot.bobot_td);
    } else if (((*to_count).krit.td_sistole >= 90 && (*to_count).krit.td_sistole <= 119) || (*to_count).krit.td_diastole < 80) {
        return powf(5.0, -sebuah_bobot.bobot_td);
    } else if (((*to_count).krit.td_sistole >= 120 && (*to_count).krit.td_sistole <= 139) || ((*to_count).krit.td_diastole >= 80 && (*to_count).krit.td_diastole <= 89)) {
        return powf(2.0, -sebuah_bobot.bobot_td);
    } else if (((*to_count).krit.td_sistole >= 140 && (*to_count).krit.td_sistole <= 159) || ((*to_count).krit.td_diastole >= 90 && (*to_count).krit.td_diastole <= 99)) {
        return powf(3.0, -sebuah_bobot.bobot_td);
    } else if (((*to_count).krit.td_sistole >= 160) || ((*to_count).krit.td_diastole >= 100)) {
        return powf(4.0, -sebuah_bobot.bobot_td);
    }
    return 0;
}

float hitung_bobot_nadi(address_pasien to_count, bobot_krit sebuah_bobot)
{
    // Algoritma
    if ((*to_count).krit.detak_nadi < 60) {
        return powf(2.0, -sebuah_bobot.bobot_nadi);
    } else if (((*to_count).krit.detak_nadi >= 60 && (*to_count).krit.detak_nadi <= 100)) {
        return powf(3.0, -sebuah_bobot.bobot_nadi);
    } else if ((*to_count).krit.detak_nadi > 100) {
        return powf(2.0, -sebuah_bobot.bobot_nadi);
    }
    return 0;
}

float hitung_bobot_hr(address_pasien to_count, bobot_krit sebuah_bobot)
{
    // Algoritma
    if ((*to_count).krit.detak_jantung < 60) {
        return powf(2.0, -sebuah_bobot.bobot_hr);
    } else if (((*to_count).krit.detak_jantung >= 60 && (*to_count).krit.detak_jantung <= 100)) {
        return powf(3.0, -sebuah_bobot.bobot_hr);
    } else if ((*to_count).krit.detak_jantung > 100) {
        return powf(2.0, -sebuah_bobot.bobot_hr);
    }
    return 0;
}

float hitung_bobot_korelasi(address_pasien to_count, bobot_krit a_bobot)
{
    if (((*to_count).krit.hr_x_nadi <= 10)) {
        return powf(3.0, -a_bobot.bobot_n_hr);
    } else {
        return powf(2.0, -a_bobot.bobot_n_hr);
    }
}

float hitung_bobot_tegang_nadi(address_pasien to_decide, bobot_krit a_bobot)
{
    if ((*to_decide).krit.tegangan_nadi == TIDAK_BERUBAH) {
        return powf(3.0, -a_bobot.bobot_tegang_nadi);
    } else {
        return powf(2.0, -a_bobot.bobot_tegang_nadi);
    }
}

float hitung_bobot_elastis_nadi(address_pasien to_decide, bobot_krit a_bobot)
{
    if ((*to_decide).krit.elastisitas_pembuluh_nadi == ELASTIS) {
        return powf(3.0, -a_bobot.bobot_elastis_nadi);
    } else {
        return powf(2.0, -a_bobot.bobot_elastis_nadi);
    }
}

float hitung_bobot_napas(address_pasien to_decide, bobot_krit a_bobot)
{
    if ((*to_decide).krit.frek_napas < 12) {
        return powf(2.0, -a_bobot.bobot_napas);
    } else if ((*to_decide).krit.frek_napas >= 12 && (*to_decide).krit.frek_napas <= 20) {
        return powf(3.0, -a_bobot.bobot_napas);
    } else {
        return powf(2.0, -a_bobot.bobot_napas);
    }
}

float hitung_bobot_suhu(address_pasien to_decide, bobot_krit a_bobot)
{
    if ((*to_decide).krit.suhu_badan < 36.5) {
        return powf(2.0, -a_bobot.bobot_suhu);
    } else if ((*to_decide).krit.suhu_badan >= 36.5 && (*to_decide).krit.suhu_badan <= 37.4) {
        return powf(4.0, -a_bobot.bobot_suhu);
    } else if ((*to_decide).krit.suhu_badan >= 37.5 && (*to_decide).krit.suhu_badan <= 37.9) {
        return powf(2.0, -a_bobot.bobot_suhu);
    } else {
        return powf(3.0, -a_bobot.bobot_suhu);
    }
}