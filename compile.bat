mkdir .\build\Debug
@ g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\banner.cpp -o .\build\Debug\banner.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\bobot_master.cpp -o .\build\Debug\bobot_master.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\hapus_pasien.cpp -o .\build\Debug\hapus_pasien.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\hitung_vektor.cpp -o .\build\Debug\hitung_vektor.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\kursor.cpp -o .\build\Debug\kursor.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\main.cpp -o .\build\Debug\main.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\operasi_file.cpp -o .\build\Debug\operasi_file.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\panduan_kredit.cpp -o .\build\Debug\panduan_kredit.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\print_pasien.cpp -o .\build\Debug\print_pasien.o && g++ -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wcast-align -Wconversion -Wsign-conversion -Wnull-dereference -g3 -O0 -c .\src\tambah_pasien.cpp -o .\build\Debug\tambah_pasien.o && g++ .\build\Debug\banner.o .\build\Debug\bobot_master.o .\build\Debug\hapus_pasien.o .\build\Debug\hitung_vektor.o .\build\Debug\kursor.o .\build\Debug\main.o .\build\Debug\operasi_file.o .\build\Debug\panduan_kredit.o .\build\Debug\print_pasien.o .\build\Debug\tambah_pasien.o -o .\build\Debug\outDebug.exe && copy .\build\Debug\outDebug.exe .\