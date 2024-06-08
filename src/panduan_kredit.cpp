#include "pasien.h"

void tampil_panduan() {
    int jmlh_pasien = 0;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    short columns;
    short kolom=0;
    short baris=0;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (short) (csbi.srWindow.Right - csbi.srWindow.Left + 1);
    baris=10;
    kolom=(short) ((columns/2)-40);
    kursor(kolom, ++baris);
    printf("Panduan Penggunaan Aplikasi");
    kursor(kolom, ++baris);
    printf("1. Tambah Pasien");
    kursor(kolom, ++baris);
    printf("   - Pilihan ini digunakan untuk menambahkan data pasien baru ke dalam sistem.");
    kursor(kolom, ++baris);
    printf("   - Anda akan diminta untuk memasukkan informasi pasien seperti ID pasien, nama,");
    kursor(kolom, ++baris);
    printf("     alamat, jenis kelamin, tanggal lahir, tekanan darah (sistolik dan diastolik),");
    kursor(kolom, ++baris);
    printf("     detak nadi, detak jantung, korelasi nadi dan jantung, tegangan nadi,");
    kursor(kolom, ++baris);
    printf("     elastisitas pembuluh nadi, frekuensi pernafasan, dan suhu tubuh.");
    kursor(kolom, ++baris);
    printf("   - Data ini akan digunakan untuk menghitung prioritas penanganan pasien");
    kursor(kolom, ++baris);
    printf("     menggunakan metode Weight Product (WP).");

    kursor(kolom, ++baris);
    printf("2. Tampil Daftar Pasien");
    kursor(kolom, ++baris);
    printf("   - Pilihan ini akan menampilkan daftar seluruh pasien yang telah dimasukkan");
    kursor(kolom, ++baris);
    printf("     ke dalam sistem, beserta informasi pasien yang telah diinputkan sebelumnya.");

    baris++;
    kursor(kolom, ++baris);
    printf("3. Tampil Antrean Pasien");
    kursor(kolom, ++baris);
    printf("   - Pilihan ini akan menampilkan daftar antrean pasien yang diurutkan");
    kursor(kolom, ++baris);
    printf("     berdasarkan prioritas penanganan.");
    kursor(kolom, ++baris);
    printf("   - Urutan antrean ditentukan dengan menghitung nilai normalisasi total vektor");
    kursor(kolom, ++baris);
    printf("     untuk setiap pasien menggunakan metode WP, yang mempertimbangkan bobot kriteria");
    kursor(kolom, ++baris);
    printf("     dan nilai input kriteria dari masing-masing pasien.");
    kursor(kolom, ++baris);
    printf("   - Pasien dengan nilai normalisasi total vektor tertinggi akan mendapat prioritas");
    kursor(kolom, ++baris);
    printf("     penanganan pertama, dan seterusnya secara descending.");

    baris++;
    kursor(kolom, ++baris);
    printf("4. Hapus Pasien");
    kursor(kolom, ++baris);
    printf("   - Terdapat tiga opsi penghapusan:");
    kursor(kolom, ++baris);
    printf("     1. Hapus pasien dari antrean,");
    kursor(kolom, ++baris);
    printf("     2. Hapus pasien dari daftar pasien, dan");
    kursor(kolom, ++baris);
    printf("     3. Hapus semua data pasien dari daftar pasien.");

    baris++;
    kursor(kolom, ++baris);
    printf("5. Ubah Bobot Master");
    kursor(kolom, ++baris);
    printf("   - Pilihan ini digunakan untuk mengubah bobot kriteria yang digunakan");
    printf("     dalam perhitungan metode WP.");
    kursor(kolom, ++baris);
    printf("   - Bobot kriteria ini akan memengaruhi prioritas penanganan pasien.");
    kursor(kolom, ++baris);
    printf("   - Anda dapat mengubah bobot untuk kriteria seperti tekanan darah, detak nadi,");
    kursor(kolom, ++baris);
    printf("     detak jantung, korelasi nadi dan jantung, tegangan nadi, elastisitas pembuluh nadi,");
    kursor(kolom, ++baris);
    printf("     frekuensi pernafasan, dan suhu tubuh.");

    baris++;
    kursor(kolom, ++baris);
    printf("6. Panduan");
    kursor(kolom, ++baris);
    printf("- Pilihan ini akan menampilkan panduan penggunaan aplikasi yang Anda sedang membaca saat ini.");
    
    baris++;
    kursor(kolom, ++baris);
    printf("7. Kredit");
    kursor(kolom, ++baris);
    printf("- Pilihan ini akan menampilkan informasi kredit terkait pengembang aplikasi ini.");

    baris++;
    printf("8. Quit");
    kursor(kolom, ++baris);
    printf("- Pilihan ini digunakan untuk keluar dari aplikasi.");
    kursor(kolom, ++baris);
    printf("- Secara otomatis, aplikasi akan menyimpan data pasien ke fail.");
    
    baris++;
    kursor(kolom, ++baris);
    printf("Tekan apapun untuk kembali");
    getchar();
}

void tampil_kredit() {
    printf("Aplikasi Sistem Antrian Pasien dengan Metode Weight Product");
    printf("Versi 1.0");

    printf("Dikembangkan oleh:");
    printf("Suryo Adi WibowoYosep Agus Pranoto");

    printf("Politeknik Negeri BandungJurusan Teknik InformatikaTahun 2023");
    printf("Kontributor:");
    printf("Ade Hodijah, S.Kom, M.T.");
    printf("Luqmannul Hakim Firdaus, S.Kom., M.T. (Dosen Pembimbing)");
    printf("Andika Prisilia");
    printf("Nadia Rachma Yuninda");

    printf("Sumber Daya yang Digunakan:");
    printf("Visual Studio Code");
    printf("G++/GCC Compiler");

    printf("Informasi Kontak:");
    printf("muhammad.rafif.tif423@polban.ac.id");
    printf("nadia.rachma.tif423@polban.ac.id");

    printf("Kami mengucapkan terima kasih kepada seluruh staf dan dosen Jurusan Teknik Informatika ITN Malang atas bimbingan dan dukungannya dalam pengembangan aplikasi ini.");

    printf("Tekan apapun untuk kembali.");
    getchar();
}