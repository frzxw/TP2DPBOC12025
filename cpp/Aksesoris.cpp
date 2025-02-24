#pragma once
#include "PetShop.cpp"

using namespace std;

class Aksesoris : public PetShop
{
protected:
    string bahan;
    string warna;

public:
    Aksesoris() : PetShop(), bahan(""), warna("") {}
    Aksesoris(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk, string bahan, string warna)
        : PetShop(id, nama_produk, harga_produk, stok_produk, kategori_produk), bahan(bahan), warna(warna) {}

    void set_bahan(string bahan) { this->bahan = bahan; }
    void set_warna(string warna) { this->warna = warna; }

    string get_bahan() const { return bahan; }
    string get_warna() const { return warna; }

    ~Aksesoris() {}
};