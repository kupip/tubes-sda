#ifndef PASIEN_H
#define PASIEN_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define TIDAK_BERUBAH true
#define BERUBAH false
#define ELASTIS true
#define KERAS false

typedef struct pasien *address_pasien;

typedef struct bobot_krit
{
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

void hitung_vektor(address_pasien *first, bobot_krit a_bobot);
void tambah_pasien(Head *first, Pasien **trav, bobot_krit a_bobot);

void set_bobot_master(bobot_krit *a_bobot);
void ubah_bobot_master(bobot_krit *a_bobot);

void tampilkan_daftar_pasien(Pasien *first);
void tampilkan_antrian(Pasien *first);

void hapus_pasien (Head *first);
void hapus_data_pasien(Head *first);
void hapus_antrean_pasien(address_pasien *first);
void hapus_data_semua_pasien(Head *first);
void kursor(SHORT x, SHORT y);

void baca_file(Head *a_head);
void simpan_file(address_pasien trav);

void tampil_panduan();
void tampil_kredit();
#endif