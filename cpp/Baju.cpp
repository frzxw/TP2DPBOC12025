#pragma once             // mencegah multiple inclusion dari header file yang sama
#include "Aksesoris.cpp" // menyertakan header file Aksesoris

using namespace std; // menggunakan namespace standar C++

class Baju : public Aksesoris // mendefinisikan kelas Baju yang merupakan turunan dari Aksesoris
{
private:           // akses private, hanya bisa diakses oleh kelas ini
    string ukuran; // atribut untuk menyimpan ukuran baju

public: // akses public, bisa diakses dari luar kelas
    // konstruktor default, menginisialisasi atribut dengan nilai default
    Baju() : Aksesoris(), ukuran("") {}

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang diberikan
    Baju(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk, string bahan, string warna, string ukuran)
        : Aksesoris(id, nama_produk, harga_produk, stok_produk, kategori_produk, bahan, warna), ukuran(ukuran) {}

    // metode setter untuk atribut ukuran
    void set_ukuran(string ukuran) { this->ukuran = ukuran; }

    // metode getter untuk atribut ukuran
    string get_ukuran() const { return ukuran; }

    // destruktor, membersihkan objek saat tidak digunakan lagi
    ~Baju() {}
};