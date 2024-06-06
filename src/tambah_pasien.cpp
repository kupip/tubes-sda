#include "pasien.h"
void input_kriteria(Pasien *temp_pasien);
void sambung_prio(address_pasien *prio, address_pasien* trav, address_pasien temp_pasien);

void tambah_pasien(Head *first, Pasien **trav, bobot_krit a_bobot)
{
    Pasien *temp_pasien = (Pasien*) malloc(sizeof(Pasien));
    static int id=0;

    // Pengisian nilai awal ke pointer
    temp_pasien->p_input=NULL;
    temp_pasien->p_prioritas=NULL;
    (*temp_pasien).id = ++id;

    system("cls");
    printf("\t\t\t\t\t\t\tMasukkan nama pasien: ");
    scanf("%[^\n]s", (*temp_pasien).nama);
    getchar();

    printf("\t\t\t\t\t\t\tMasukkan alamat: ");
    scanf("%[^\n]s", (*temp_pasien).alamat);
    getchar();

    printf("\t\t\t\t\t\t\tMasukkan jenis kelamin (L/P): ");
    scanf("%c", &((*temp_pasien).jenis_kelamin));
    getchar();
    strupr(&((*temp_pasien).jenis_kelamin));
    
    // antisipasi input error
    while ((*temp_pasien).jenis_kelamin != 'L' && (*temp_pasien).jenis_kelamin != 'P' ) {
        printf("\t\t\t\t\t\t\tMasukkan input yang sesuai (L/P): ");
        scanf("%c", &((*temp_pasien).jenis_kelamin));
        getchar();
    }
    input_kriteria(&(*temp_pasien));
    hitung_vektor(&temp_pasien, a_bobot);
    
    // penyambungan berdasarkan urutan input
    if ((*first).inp == NULL) {
        (*first).inp = temp_pasien;
    } else {
        *trav = (*first).inp;
        while ((*trav)->p_input != NULL) {
            (*trav) = (*trav)->p_input;
        }
        (*trav)->p_input = temp_pasien;
    }

    // penyambungan berdasarkan prioritas
    sambung_prio(&((*first).prio), &(*trav), temp_pasien);
}

void input_kriteria(Pasien *temp_pasien)
{
    // Kamus Data
    int temp=0;

    // Algoritma
    printf("\t\t\t\t\t\t\tMasukkan tekanan darah sistole: ");
    scanf("%d", &((*temp_pasien).krit.td_sistole));

    printf("\t\t\t\t\t\t\tMasukkan tekanan darah diastole: ");
    scanf("%d", &((*temp_pasien).krit.td_diastole));

    printf("\t\t\t\t\t\t\tMasukkan detak nadi: ");
    scanf("%d", &((*temp_pasien).krit.detak_nadi));

    printf("\t\t\t\t\t\t\tMasukkan detak jantung: ");
    scanf("%d", &((*temp_pasien).krit.detak_jantung));

    (*temp_pasien).krit.hr_x_nadi = (*temp_pasien).krit.detak_jantung - (*temp_pasien).krit.detak_nadi;
    
    printf("\t\t\t\t\t\t\tMasukkan frekuensi pernapasan: ");
    scanf("%d", &((*temp_pasien).krit.frek_napas));

    printf("\t\t\t\t\t\t\tMasukkan suhu tubuh: ");
    scanf("%f", &((*temp_pasien).krit.suhu_badan));

    printf("\t\t\t\t\t\t\tTegangan nadi\n\t\t\t\t\t\t\t1. Tidak Berubah\n\t\t\t\t\t\t\t2. Kuat dan Lemah Berubah-ubah\n\t\t\t\t\t\t\tMasukkan angka: ");
    scanf("%d", &temp);

    // antisipasi input error
    while (temp != 1 && temp != 2) {
        printf("\t\t\t\t\t\t\tMasukkan input yang valid: ");
        scanf("%d", &temp);
    }
    if (temp == 1) {
        (*temp_pasien).krit.tegangan_nadi = TIDAK_BERUBAH;
    } else {
        (*temp_pasien).krit.tegangan_nadi = BERUBAH;
    }

    printf("\n\t\t\t\t\t\t\tElastisitas pembuluh nadi\n\t\t\t\t\t\t\t1. Elastis\n\t\t\t\t\t\t\t2. Keras seperti kawat\n\t\t\t\t\t\t\tMasukkan angka: ");
    scanf("%d", &temp);

    // antisipasi input error
    while (temp != 1 && temp != 2) {
        printf("\t\t\t\t\t\t\tMasukkan input yang valid: ");
        scanf("%d", &temp);
    }

    if (temp == 1) {
        (*temp_pasien).krit.elastisitas_pembuluh_nadi = ELASTIS;
    } else {
        (*temp_pasien).krit.elastisitas_pembuluh_nadi = KERAS;
    }
    system("cls");
}

void sambung_prio(address_pasien *prio,  address_pasien* trav, address_pasien temp_pasien)
{
    // Kamus Data
    time_t rawtime;
    tm* local_time;

    // Algoritma
    time(&rawtime);
    local_time = localtime(&rawtime);
    temp_pasien->jam_datang = local_time->tm_hour;
    if ((*prio) == NULL) {
        *prio = temp_pasien;
    } else {
        if ((*prio)->jam_datang == temp_pasien->jam_datang && (*prio)->vektor_total < temp_pasien->vektor_total) {
            (*temp_pasien).p_prioritas = *prio;
            *prio = temp_pasien;
        } else {
            *trav = *prio;

            // loop jam
            while ((*trav)->p_prioritas != NULL && (*trav)->p_prioritas->jam_datang < temp_pasien->jam_datang) {
                *trav = (*trav)->p_prioritas;
            }

            // loop vektor
            while ((*trav)->p_prioritas != NULL && (*trav)->p_prioritas->vektor_total >= temp_pasien->vektor_total) {
                *trav = (*trav)->p_prioritas;
            }

            // penyesuaian pointer prio
            (*temp_pasien).p_prioritas = (**trav).p_prioritas;
            (**trav).p_prioritas = temp_pasien;
        }
    }
}