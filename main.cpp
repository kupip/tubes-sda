#include "pasien.h"
void set_krit(bobot_krit *a_bobot);

int main() {
    // KAMUS DATA
    Head a_head;
    a_head.inp=NULL;
    a_head.prio=NULL;
    address_pasien trav=NULL;
    bobot_krit a_bobot;
    set_krit(&a_bobot);

    // ALGO
    // printf("%f\n", a_bobot.bobot_td);
    tambah_pasien(&(a_head.inp), &trav);
    hitung_vektor(&(a_head.inp));
    printf("%.5f\n", a_head.inp->vektor_total);
}