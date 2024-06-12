#ifndef PASIEN_H
#define PASIEN_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
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
    int jam_datang;
    Kriteria krit;
    address_pasien p_input;
    address_pasien p_prioritas;
} Pasien;

typedef struct head_p {
    address_pasien inp;
    address_pasien prio;
} Head;


/**
 * Menampilkan menu utama
 *
 * I.S.: Menu utama belum tampil.
 * F.S.: Menu utama sudah tampil.
 */
void print_menu_utama();

/**
 * Menampilkan banner.
 *
 * I.S.: Banner belum tampil.
 * F.S.: Banner sudah tampil.
 * 
 * Return:
 * void
 */
void banner();

/**
 * Menghitung nilai vektor dari tiap pasien yang diinputkan  
 *
 * I.S.: Nilai vektor pada pasien yang diinputkan masih tak tentu.
 * F.S.: Nilai vektor pada pasien yang diinputkan sudah ditetapkan.
 *
 * Parameter:
 * first - alamat penunjuk pasien yang akan dihitung nilai vektornya
 * a_bobot - bobot yang digunakan untuk melakukan penghitungan
 */
void hitung_vektor(address_pasien *first, bobot_krit a_bobot);

/**
 * Menambah data pasien baru \n 
 *
 * I.S.: Belum atau sudah terdapat antrean pasien.
 * F.S.: Pasien baru berhasil ditambahkan ke antrean.
 * 
 * Parameter:
 * first - penunjuk struct yang berisi penunjuk pasien pertama berdasarkan input dan pasien pertama berdasarkan prioritas
 * trav - variabel untuk melakukan traversing pada list
 * a_bobot - bobot yang akan digunakan pada penghitungan nilai vektor
 * 
 * Return:
 * void
 */
void tambah_pasien(Head *first, Pasien **trav, bobot_krit a_bobot);

/**
 * Menginisialisasi bobot master yang digunakan dalam penghitungan dengan nilai seharusnya setelah kalkulasi
 * 
 * I.S.: Bobot master belum dikalkulasi.
 * F.S.: Bobot master sudah dikalkulasi.
 * 
 * Parameter:
 * a_bobot - bobot master yang akan diinisialisasi
 * 
 * Return:
 * void
 */
void set_bobot_master(bobot_krit *a_bobot);

/**
 * Mengubah bobot master yang digunakan dalam penghitungan nilai vektor
 * 
 * I.S.: Bobot master yang digunakan belum berubah.
 * F.S.: Bobot master yang digunakan sudah berubah nilainya.
 * 
 * Parameter:
 * a_bobot - bobot master yang akan diubah
 * 
 * Return:
 * void
 */
void ubah_bobot_master(bobot_krit *a_bobot);

/**
 * Menampilkan data seluruh pasien yang diinputkan beserta atributnya
 * 
 * I.S.: Daftar pasien yang diinputkan belum tampil.
 * F.S.: Daftar pasien yang diinputkan sudah tampil.
 * 
 * Parameter:
 * first - penunjuk pasien urutan pertama berdasarkan input
 * 
 * Return:
 * void
 */
void tampilkan_daftar_pasien(Pasien *first);

/**
 * Menampilkan antrean terkini dari pasien yang telah diinputkan datanya
 * 
 * I.S.: Antrean pasien belum tampil.
 * F.S.: Antrean pasien sudah tampil.
 * 
 * Parameter:
 * first - penunjuk pasien urutan pertama berdasarkan prioritas
 * 
 * Return:
 * void
 */
void tampilkan_antrian(Pasien *first);

/**
 * Menampilkan menu penghapusan pasien
 * 
 * I.S.: Menu penghapusan pasien belum tampil.
 * F.S.: Menu penghapusan pasien sudah tampil.
 * 
 * Parameter:
 * first - penunjuk struct yang berisi penunjuk pasien urutan pertama berdasarkan input dan pasien pertama berdasarkan prioritas
 */
void tampil_menu_hapus_pasien(Head *first);

/**
 * Menghapus data pasien tertentu berdasarkan urutan kedatangan
 * 
 * I.S.: Data pasien yang ingin dihapus masih ada.
 * F.S.: Data pasien yang ingin dihapus masih ada (jika proses dibatalkan) atau sudah dihapus.
 * 
 * Parameter:
 * first - penunjuk struct yang berisi penunjuk pasien pertama berdasarkan kedatangan dan pasien pertama berdasarkan prioritas
 * 
 * Return:
 * void
 */
void hapus_data_pasien(Head *first);

/**
 * Memindahkan penunjuk pasien pertama berdasarkan prioritas ke pasien selanjutnya
 *
 * I.S.: Penunjuk pasien pertama berdasarkan prioritas belum dipindahkan.
 * F.S.: Penunjuk pasien pertama berdasarkan prioritas sudah dipindahkan.
 *
 * Parameter:
 * first_prio - penunjuk pasien pertama berdasarkan prioritas
 * 
 * Return:
 * void
 */
void panggil_antrean_pasien(address_pasien *first_prio);

/**
 * Menghapus data semua pasien
 *
 * I.S.: Masih terdapat data pasien.
 * F.S.: Sudah tidak terdapat data pasien.
 * 
 * Parameter:
 * first - penunjuk struct yang berisi penunjuk pasien pertama berdasarkan kedatangan dan pasien pertama berdasarkan prioritas
 * 
 * Return:
 * void
 */
void hapus_data_semua_pasien(Head *first);

/**
 * Memosisikan kursor print/scan di lokasi tertentu di console
 * 
 * I.S.: Kursor tidak berada di posisi yang diinginkan.
 * F.S.: Kursor tidak berada di posisi yang diinginkan.
 * 
 * Parameter:
 * x - koordinat kursor di sumbu-x (kolom pada console)
 * y - koordinat kursor di sumbu-y (baris pada console)
 * 
 * Return:
 * void
 */
void kursor(SHORT x, SHORT y);

/**
 * Membaca fail yang bisa berisi data ataupun tidak
 * 
 * I.S.: Fail belum terbaca.
 * F.S.: Fail sudah terbaca.
 * 
 * Parameter:
 * a_head - penunjuk struct yang berisi penunjuk pasien pertama berdasarkan input dan pasien pertama berdasarkan prioritas
 * 
 * Return:
 * void
 */
void baca_file(Head *a_head);

/**
 * Menyimpan data antrean pasien pada fail
 * 
 * I.S.: Antrean pasien belum disimpan di fail.
 * F.S.: Antrean pasien sudah disimpan di fail.
 * 
 * Parameter:
 * trav - penunjuk pasien pertama berdasarkan kedatangan
 * 
 * Return:
 * void
 */
void simpan_file(address_pasien trav);

/**
 * Menampilkan panduan
 * 
 * I.S.: Panduan belum tampil.
 * F.S.: Panduan sudah tampil.
 * 
 * Return:
 * void
 */
void tampil_panduan();

/**
 * Menampilkan kredit program
 * 
 * I.S.: Kredit belum tampil.
 * F.S.: Kredit sudah tampil.
 * 
 * Return:
 * void
 */
void tampil_kredit();
#endif