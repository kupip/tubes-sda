#ifndef PASIEN_H
#define PASIEN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TIDAK_BERUBAH true
#define BERUBAH false
#define ELASTIS true
#define KERAS false

typedef struct pasien *address_pasien;

typedef struct bobot_krit
{
    /* data */
    float bobot_td=5;
    float bobot_nadi=5;
    float bobot_hr=5;
    float bobot_n_hr=4;
    float bobot_tegang_nadi=3;
    float bobot_elastis_nadi=3;
    float bobot_napas=3;
    float bobot_suhu=2;
} bobot_krit;

typedef struct kriteria {
    int td_sistole;
    int td_diastole;
    int detak_nadi;
    int detak_jantung;
    int frek_napas;
    float suhu_badan;
    bool tegangan_nadi;
    int hr_x_nadi;
    bool elastisitas_pembuluh_nadi;
} Kriteria;

typedef struct pasien {
    int id;
    char nama[50];
    char alamat[50];
    char jenis_kelamin;
    float vektor_total;
    Kriteria krit;
    address_pasien p_input;
    address_pasien p_prioritas;
} Pasien;

typedef struct head_p {
    address_pasien inp;
    address_pasien prio;
} Head;


int menu_utama();
void banner();
void hapus_pasien ();
void hitung_vektor(address_pasien *first);
void tambah_pasien(Head *first, Pasien **trav);
void tampilkan_daftar_pasien(Pasien *first);
void tampilkan_antrian(Pasien *first);
#endif