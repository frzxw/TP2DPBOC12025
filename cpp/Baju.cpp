#pragma once
#include "Aksesoris.cpp"

using namespace std;

class Baju : public Aksesoris
{
private:
    string ukuran;

public:
    Baju() : Aksesoris(), ukuran("") {}
    Baju(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk, string bahan, string warna, string ukuran)
        : Aksesoris(id, nama_produk, harga_produk, stok_produk, kategori_produk, bahan, warna), ukuran(ukuran) {}

    void set_ukuran(string ukuran) { this->ukuran = ukuran; }
    string get_ukuran() const { return ukuran; }

    ~Baju() {}
};