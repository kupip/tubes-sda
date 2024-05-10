#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef PASIEN_H
#define PASIEN_H
typedef struct pasien *address_pasien;

struct kriteria {
    int tekanan_darah;
    int detak_jantung;
    int detak_nadi;
    int relasi_hr_tegangan_nadi;
    int elastisitas_pembuluh_nadi;
    int frekuensi_pernafasan;
    int suhu_badan;
};

typedef struct pasien {
    char nama[50];
    char alamat[50];
    char jenis_kelamin;
    char tanggal_kunjungan[20];
    float vektor_total;
    kriteria Kriteria;
    Pasien *pointer_pertama;
    Pasien *pointer_kedua;
} Pasien;

void menu_hapus_pasien();
void menu_tambah_pasien();
void menu_utama();
void banner();
void hapus_pasien ();
float hitung_vektor;
void proses_pasien ();
void tambah_pasien();
void tampilkan_daftar_pasien();
void tampilkan_antrian();
#endif