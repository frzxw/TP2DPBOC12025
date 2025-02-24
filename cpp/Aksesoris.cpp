#pragma once           // mencegah multiple inclusion dari header file yang sama
#include "PetShop.cpp" // menyertakan header file PetShop

using namespace std; // menggunakan namespace standar C++

class Aksesoris : public PetShop // mendefinisikan kelas Aksesoris yang merupakan turunan dari PetShop
{
protected:        // akses protected, hanya bisa diakses oleh kelas ini dan turunannya
    string bahan; // atribut untuk menyimpan bahan aksesoris
    string warna; // atribut untuk menyimpan warna aksesoris

public: // akses public, bisa diakses dari luar kelas
    // konstruktor default, menginisialisasi atribut dengan nilai default
    Aksesoris() : PetShop(), bahan(""), warna("") {}

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang diberikan
    Aksesoris(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk, string bahan, string warna)
        : PetShop(id, nama_produk, harga_produk, stok_produk, kategori_produk), bahan(bahan), warna(warna) {}

    // metode setter untuk atribut bahan
    void set_bahan(string bahan) { this->bahan = bahan; }

    // metode setter untuk atribut warna
    void set_warna(string warna) { this->warna = warna; }

    // metode getter untuk atribut bahan
    string get_bahan() const { return bahan; }

    // metode getter untuk atribut warna
    string get_warna() const { return warna; }

    // destruktor, membersihkan objek saat tidak digunakan lagi
    ~Aksesoris() {}
};