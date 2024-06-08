#include "pasien.h"

void tampil_panduan() {
    printf("Panduan Penggunaan Aplikasi\n");
    printf("1. Tambah Pasien\n");
    printf("\t- Pilihan ini digunakan untuk menambahkan data pasien baru ke dalam sistem.\n");
    printf("\t- Anda akan diminta untuk memasukkan informasi pasien seperti ID pasien, nama, alamat, jenis kelamin, tanggal lahir, tekanan darah (sistolik dan diastolik), detak nadi, detak jantung, korelasi nadi dan jantung, tegangan nadi, elastisitas pembuluh nadi, frekuensi pernafasan, dan suhu tubuh.\n");
    printf("\t- Data ini akan digunakan untuk menghitung prioritas penanganan pasien menggunakan metode Weight Product (WP).\n\n");

    printf("2. Tampil Daftar Pasien\n");
    printf("\t- Pilihan ini akan menampilkan daftar seluruh pasien yang telah dimasukkan ke dalam sistem, beserta informasi pasien yang telah diinputkan sebelumnya.\n\n");

    printf("3. Tampil Antrean Pasien\n");
    printf("\t- Pilihan ini akan menampilkan daftar antrean pasien yang diurutkan berdasarkan prioritas penanganan.\n");
    printf("\t- Urutan antrean ditentukan dengan menghitung nilai normalisasi total vektor untuk setiap pasien menggunakan metode WP, yang mempertimbangkan bobot kriteria dan nilai input kriteria dari masing-masing pasien.\n");
    printf("\t- Pasien dengan nilai normalisasi total vektor tertinggi akan mendapat prioritas penanganan pertama, dan seterusnya secara descending.\n\n");

    printf("4. Hapus Pasien\n");
    printf("\t- Terdapat tiga opsi penghapusan:\n");
    printf("\t\t1. Hapus pasien dari antrean,\n");
    printf("\t\t2. Hapus pasien dari daftar pasien, dan\n");
    printf("\t\t3. Hapus semua data pasien dari daftar pasien.\n\n");

    printf("5. Ubah Bobot Master\n");
    printf("\t- Pilihan ini digunakan untuk mengubah bobot kriteria yang digunakan dalam perhitungan metode WP.\n");
    printf("\t- Bobot kriteria ini akan memengaruhi prioritas penanganan pasien.\n");
    printf("\tAnda dapat mengubah bobot untuk kriteria seperti tekanan darah, detak nadi, detak jantung, korelasi nadi dan jantung, tegangan nadi, elastisitas pembuluh nadi, frekuensi pernafasan, dan suhu tubuh.\n\n");


    printf("6. Panduan\n");
    printf("\t- Pilihan ini akan menampilkan panduan penggunaan aplikasi yang Anda sedang membaca saat ini.\n\n");
    
    printf("7. Kredit\n");
    printf("\t- Pilihan ini akan menampilkan informasi kredit terkait pengembang aplikasi ini.\n\n");

    printf("8. Quit\n");
    printf("\t- Pilihan ini digunakan untuk keluar dari aplikasi.\n");
    printf("\t- Secara otomatis, aplikasi akan menyimpan data pasien ke fail.\n\n");
    
    printf("Tekan apapun untuk kembali\n");
    getchar();
}

void tampil_kredit() {
    printf("Aplikasi Sistem Antrian Pasien dengan Metode Weight Product\n");
    printf("Versi 1.0\n\n");

    printf("Dikembangkan oleh:\n");
    printf("Suryo Adi Wibowo\nYosep Agus Pranoto\n\n");

    printf("Politeknik Negeri Bandung\nJurusan Teknik Informatika\nTahun 2023");
    printf("Kontributor:\n");
    printf("Ade Hodijah, S.Kom, M.T.\n");
    printf("Luqmannul Hakim Firdaus, S.Kom., M.T. (Dosen Pembimbing)\n");
    printf("Andika Prisilia\n");
    printf("Nadia Rachma Yuninda\n\n");

    printf("Sumber Daya yang Digunakan:\n");
    printf("Visual Studio Code\n");
    printf("G++/GCC Compiler\n\n");

    printf("Informasi Kontak:\n");
    printf("muhammad.rafif.tif423@polban.ac.id\n");
    printf("nadia.rachma.tif423@polban.ac.id\n\n");

    printf("Kami mengucapkan terima kasih kepada seluruh staf dan dosen Jurusan Teknik Informatika ITN Malang atas bimbingan dan dukungannya dalam pengembangan aplikasi ini.");

    printf("Tekan apapun untuk kembali.\n");
    getchar();
}