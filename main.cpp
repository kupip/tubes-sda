#include "pasien.h"

int main() {
    address_pasien first=NULL;
    address_pasien trav=NULL;
    tambah_pasien(&first, &trav);
    tampilkan_daftar_pasien(first);
    tambah_pasien(&first, &trav);
    tampilkan_daftar_pasien(first);
}