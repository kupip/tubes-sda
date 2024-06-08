#include "pasien.h"
void input_kriteria(Pasien *temp_pasien, short baris, short kolom);
void sambung_prio(address_pasien *prio, address_pasien* trav, address_pasien temp_pasien);

void tambah_pasien(Head *first, Pasien **trav, bobot_krit a_bobot)
{
    Pasien *temp_pasien = (Pasien*) malloc(sizeof(Pasien));
    static int id=0;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    short columns;
    short kolom=0;
    short baris=0;
  
    // Pengisian nilai awal ke pointer
    temp_pasien->p_input=NULL;
    temp_pasien->p_prioritas=NULL;
    (*temp_pasien).id = ++id;

    // Penyesuaian layout
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (short) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    system("cls");
    kolom=(short) ((columns/2)-30);
    baris=10;

    banner();
    kursor(kolom, ++baris);
    printf("Masukkan nama pasien: ");
    scanf("%[^\n]s", (*temp_pasien).nama);
    getchar();

    kursor(kolom, ++baris);
    printf("Masukkan alamat: ");
    scanf("%[^\n]s", (*temp_pasien).alamat);
    getchar();

    kursor(kolom, ++baris);
    printf("Masukkan jenis kelamin (L/P): ");
    scanf("%c", &((*temp_pasien).jenis_kelamin));
    getchar();
    strupr(&((*temp_pasien).jenis_kelamin));
    
    // antisipasi input error
    while ((*temp_pasien).jenis_kelamin != 'L' && (*temp_pasien).jenis_kelamin != 'P' ) {
        kursor(kolom, ++baris);
        printf("Masukkan input yang sesuai (L/P): ");
        scanf("%c", &((*temp_pasien).jenis_kelamin));
        strupr(&((*temp_pasien).jenis_kelamin));
        getchar();
    }
    input_kriteria(&(*temp_pasien), baris, kolom);
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

void input_kriteria(Pasien *temp_pasien, short baris, short kolom)
{
    // Kamus Data
    int temp=0;

    // Algoritma
    kursor(kolom, ++baris);
    printf("Masukkan tekanan darah sistole: ");
    scanf("%d", &((*temp_pasien).krit.td_sistole));

    kursor(kolom, ++baris);
    printf("Masukkan tekanan darah diastole: ");
    scanf("%d", &((*temp_pasien).krit.td_diastole));

    kursor(kolom, ++baris);
    printf("Masukkan detak nadi: ");
    scanf("%d", &((*temp_pasien).krit.detak_nadi));

    kursor(kolom, ++baris);
    printf("Masukkan detak jantung: ");
    scanf("%d", &((*temp_pasien).krit.detak_jantung));

    (*temp_pasien).krit.hr_x_nadi = (*temp_pasien).krit.detak_jantung - (*temp_pasien).krit.detak_nadi;
    
    kursor(kolom, ++baris);
    printf("Masukkan frekuensi pernapasan: ");
    scanf("%d", &((*temp_pasien).krit.frek_napas));

    kursor(kolom, ++baris);
    printf("Masukkan suhu tubuh: ");
    scanf("%f", &((*temp_pasien).krit.suhu_badan));

    kursor(kolom, ++baris);
    printf("Tegangan nadi");
    kursor(kolom, ++baris);
    printf("1. Tidak Berubah");
    kursor(kolom, ++baris);
    printf("2. Kuat dan Lemah Berubah-ubah");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%d", &temp);

    // antisipasi input error
    while (temp != 1 && temp != 2) {
        kursor(kolom, ++baris);
        printf("Masukkan input yang valid: ");
        scanf("%d", &temp);
    }
    if (temp == 1) {
        (*temp_pasien).krit.tegangan_nadi = TIDAK_BERUBAH;
    } else {
        (*temp_pasien).krit.tegangan_nadi = BERUBAH;
    }

    baris++;
    kursor(kolom, ++baris);
    printf("Elastisitas pembuluh nadi");
    kursor(kolom, ++baris);
    printf("1. Elastis");
    kursor(kolom, ++baris);
    printf("2. Keras seperti kawat");
    kursor(kolom, ++baris);
    printf("Masukkan angka: ");
    scanf("%d", &temp);

    // antisipasi input error
    while (temp != 1 && temp != 2) {
        kursor(kolom, ++baris);
        printf("Masukkan input yang valid: ");
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