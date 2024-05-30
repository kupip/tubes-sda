#include "pasien.h"

void simpan_file(address_pasien trav) {
    FILE *tulis = fopen("save\\data.csv", "w");
    if (trav != NULL) {
        while (trav != NULL) {
            fprintf(tulis, "%d,%s,%s,%c,%f,", (*trav).id, (*trav).nama, (*trav).alamat, (*trav).jenis_kelamin, (*trav).vektor_total);
            fprintf(tulis, "%d,%d,%d,%d,%d,%f,%c,%d,%c\n", (*trav).krit.td_sistole, (*trav).krit.td_diastole, (*trav).krit.detak_nadi,
            (*trav).krit.detak_jantung, (*trav).krit.frek_napas, (*trav).krit.suhu_badan, ((*trav).krit.elastisitas_pembuluh_nadi?'t':'f'),
            (*trav).krit.hr_x_nadi, ((*trav).krit.elastisitas_pembuluh_nadi?'t':'f'));
            trav = (*trav).p_input;
        }
    } else {
        printf("Tidak ada data apapun.\n");
        Sleep(3000);
    }
    fclose(tulis);
}

void baca_file(Head *a_head) {
    FILE *baca = fopen("save\\data.csv", "r");
    address_pasien trav=NULL;
    char temp_elastis=' ';
    char temp_tegang=' ';

    if ((*a_head).inp == NULL) {
        (*a_head).inp = (address_pasien) malloc(sizeof(Pasien));
        if (fscanf(baca, "%d,%[^,],%[^,],%c,%f,", &((*a_head).inp->id), (*a_head).inp->nama, (*a_head).inp->alamat, &((*a_head).inp->jenis_kelamin), &((*a_head).inp->vektor_total)) != EOF) {
            fscanf(baca, "%d,%d,%d,%d,%d,%f,%c,%d,%c\n", &((*a_head).inp->krit.td_sistole), &((*a_head).inp->krit.td_diastole),
            &((*a_head).inp->krit.detak_nadi), &((*a_head).inp->krit.detak_jantung), &((*a_head).inp->krit.frek_napas), &((*a_head).inp->krit.suhu_badan),
            &(temp_tegang), &((*a_head).inp->krit.hr_x_nadi), &(temp_elastis));
            
            (*a_head).inp->krit.tegangan_nadi = (temp_tegang == 't'?true:false);
            (*a_head).inp->krit.elastisitas_pembuluh_nadi = (temp_elastis == 't' ? true:false);
            strcat((*a_head).inp->nama, "\0");
            strcat((*a_head).inp->alamat, "\0");
            (*a_head).inp->p_input = NULL;
            (*a_head).inp->p_prioritas = NULL;
            (*a_head).prio = (*a_head).inp;
            trav = (*a_head).inp;
            if (!feof(baca)) {
                trav->p_input = (address_pasien) malloc(sizeof(Pasien));
                while (fscanf(baca, "%d,%[^,],%[^,],%c,%f,", &(trav->p_input->id), trav->p_input->nama, trav->p_input->alamat, &(trav->p_input->jenis_kelamin), &(trav->p_input->vektor_total)) != EOF) {
                    fscanf(baca, "%d,%d,%d,%d,%d,%f,%c,%d,%c\n", &(trav->p_input->krit.td_sistole), &(trav->p_input->krit.td_diastole),
                    &(trav->p_input->krit.detak_nadi), &(trav->p_input->krit.detak_jantung), &(trav->p_input->krit.frek_napas),
                    &(trav->p_input->krit.suhu_badan), &(temp_tegang), &(trav->p_input->krit.hr_x_nadi), &(temp_elastis));
                    (*trav).krit.tegangan_nadi = (temp_tegang == 't'?true:false);
                    (*trav).krit.elastisitas_pembuluh_nadi = (temp_elastis == 't' ? true:false);
                    trav = trav->p_input;
                    trav->p_input = (address_pasien) malloc(sizeof(Pasien));
                    // trav->p_input = NULL;
                }
                trav->p_input = NULL;
            }
        } else {
            printf("File kosong.\n");
            free((*a_head).inp);
            (*a_head).inp = NULL;
        }
    }

    fclose(baca);
}