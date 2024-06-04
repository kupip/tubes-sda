#include "pasien.h"

void simpan_file(address_pasien trav) {
    // Kamus Data
    FILE *tulis = fopen("save\\data.csv", "w");

    // Algoritma
    if (trav != NULL) {
        while (trav != NULL) {
            fprintf(tulis, "%d,%s,%s,%c,%f,", (*trav).id, (*trav).nama, (*trav).alamat, (*trav).jenis_kelamin, (*trav).vektor_total);
            fprintf(tulis, "%d,%d,%d,%d,%d,%f,%c,%d,%c,%d\n", (*trav).krit.td_sistole, (*trav).krit.td_diastole, (*trav).krit.detak_nadi,
            (*trav).krit.detak_jantung, (*trav).krit.frek_napas, (*trav).krit.suhu_badan, ((*trav).krit.elastisitas_pembuluh_nadi?'t':'f'),
            (*trav).krit.hr_x_nadi, ((*trav).krit.elastisitas_pembuluh_nadi?'t':'f'), trav->jam_datang);
            trav = (*trav).p_input;
        }
    } else {
        printf("Tidak ada data apapun.\n");
        Sleep(3000);
    }
    fclose(tulis);
}

void baca_file(Head *a_head) {
    // Kamus Data
    FILE *baca = fopen("save\\data.csv", "r");
    address_pasien trav_inp=NULL;
    address_pasien trav_prio=NULL;
    char temp_elastis=' ';
    char temp_tegang=' ';

    // Algoritma
    if ((*a_head).inp == NULL) {
        (*a_head).inp = (address_pasien) malloc(sizeof(Pasien));
        if (fscanf(baca, "%d,%[^,],%[^,],%c,%f,", &((*a_head).inp->id), (*a_head).inp->nama, (*a_head).inp->alamat, &((*a_head).inp->jenis_kelamin), &((*a_head).inp->vektor_total)) != EOF) {
            fscanf(baca, "%d,%d,%d,%d,%d,%f,%c,%d,%c,%d\n", &((*a_head).inp->krit.td_sistole), &((*a_head).inp->krit.td_diastole),
            &((*a_head).inp->krit.detak_nadi), &((*a_head).inp->krit.detak_jantung), &((*a_head).inp->krit.frek_napas), &((*a_head).inp->krit.suhu_badan),
            &(temp_tegang), &((*a_head).inp->krit.hr_x_nadi), &(temp_elastis), &(a_head->inp->jam_datang));
            (*a_head).inp->krit.tegangan_nadi = (temp_tegang == 't'?true:false);
            (*a_head).inp->krit.elastisitas_pembuluh_nadi = (temp_elastis == 't' ? true:false);
            strcat((*a_head).inp->nama, "\0");
            strcat((*a_head).inp->alamat, "\0");
            
            (*a_head).inp->p_input = NULL;
            (*a_head).inp->p_prioritas = NULL;
            (*a_head).prio = (*a_head).inp;
            trav_inp = (*a_head).inp;
            if (!feof(baca)) {
                trav_inp->p_input = (address_pasien) malloc(sizeof(Pasien));
                while (fscanf(baca, "%d,%[^,],%[^,],%c,%f,", &(trav_inp->p_input->id), trav_inp->p_input->nama, trav_inp->p_input->alamat, &(trav_inp->p_input->jenis_kelamin), &(trav_inp->p_input->vektor_total)) != EOF) {
                    fscanf(baca, "%d,%d,%d,%d,%d,%f,%c,%d,%c,%d\n", &(trav_inp->p_input->krit.td_sistole), &(trav_inp->p_input->krit.td_diastole),
                    &(trav_inp->p_input->krit.detak_nadi), &(trav_inp->p_input->krit.detak_jantung), &(trav_inp->p_input->krit.frek_napas),
                    &(trav_inp->p_input->krit.suhu_badan), &(temp_tegang), &(trav_inp->p_input->krit.hr_x_nadi), &(temp_elastis), &(trav_inp->p_input->jam_datang));
                    (*trav_inp).p_input->krit.tegangan_nadi = (temp_tegang == 't'?true:false);
                    (*trav_inp).p_input->krit.elastisitas_pembuluh_nadi = (temp_elastis == 't' ? true:false);
                    (*trav_inp).krit.tegangan_nadi = (temp_tegang == 't'?true:false);
                    (*trav_inp).krit.elastisitas_pembuluh_nadi = (temp_elastis == 't' ? true:false);

                    trav_inp->p_input->p_prioritas = NULL;
                    
                    // menyambungkan berdasarkan prio
                    if ((*a_head).prio->vektor_total < (*trav_inp).p_input->vektor_total && (*a_head).prio->jam_datang >= trav_inp->p_input->jam_datang) {
                        (*trav_inp).p_input->p_prioritas = (*a_head).prio;
                        (*a_head).prio = trav_inp->p_input;
                    } else {
                        trav_prio = (*a_head).prio;
                        
                        // loop utk jam datang
                        while (trav_prio->p_prioritas != NULL && trav_prio->p_prioritas->jam_datang < trav_inp->p_input->jam_datang) {
                            trav_prio = trav_prio->p_prioritas;
                        }

                        // loop utk vektor
                        while (trav_prio->p_prioritas != NULL && trav_prio->p_prioritas->vektor_total >= trav_inp->p_input->vektor_total) {
                            trav_prio = trav_prio->p_prioritas;
                        }
                        trav_inp->p_input->p_prioritas = trav_prio->p_prioritas;
                        trav_prio->p_prioritas = trav_inp->p_input;
                    }
                    
                    // menyambungkan berdasarkan input
                    trav_inp = trav_inp->p_input;
                    trav_inp->p_input = (address_pasien) malloc(sizeof(Pasien));
                }
                trav_inp->p_input = NULL;
            }
        } else {
            printf("File kosong.\n");
            free((*a_head).inp);
            (*a_head).inp = NULL;
        }
    }

    fclose(baca);
}