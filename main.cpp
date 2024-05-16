#include "pasien.h"

int main() {
    // KAMUS DATA
    address_pasien first_inp=NULL;
    address_pasien first_prio=NULL;
    address_pasien trav=NULL;

    // ALGO
    tambah_pasien(&first, &trav);
    tampilkan_daftar_pasien(first);
    tambah_pasien(&first, &trav);
    tampilkan_daftar_pasien(first);
}