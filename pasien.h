#ifndef PASIEN_H
#define PASIEN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIDAK_BERUBAH true
#define BERUBAH false
#define ELASTIS true
#define KERAS false

typedef struct pasien *address_pasien;

typedef struct kriteria {
    int td_sistole;
    int td_diastole;
    int detak_nadi;
    int detak_jantung;
    int frekuensi_pernafasan;
    float suhu_badan;
    bool tegangan_nadi;
    int hr_nadi;
    bool elastisitas_pembuluh_nadi;
} Kriteria;

typedef struct pasien {
    char nama[50];
    char alamat[50];
    char jenis_kelamin;
    char tanggal_kunjungan[20];
    float vektor_total;
    Kriteria krit;
    address_pasien p_input;
    address_pasien p_prioritas;
} Pasien;

void menu_hapus_pasien();
void menu_tambah_pasien();
int menu_utama();
void banner();
void hapus_pasien ();
// float hitung_vektor;
void proses_pasien ();
void tambah_pasien(Pasien **first, Pasien **trav);
void tampilkan_daftar_pasien(Pasien *first);
void tampilkan_antrian();
#endif