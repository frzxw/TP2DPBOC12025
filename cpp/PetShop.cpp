#pragma once
#include <bits/stdc++.h>

using namespace std;

class PetShop
{
protected:
    int id;
    string nama_produk;
    int harga_produk;
    int stok_produk;
    string kategori_produk;

public:
    PetShop() : id(0), nama_produk(""), harga_produk(0), stok_produk(0), kategori_produk("") {}
    PetShop(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk)
    {
        this->id = id;
        this->nama_produk = nama_produk;
        this->harga_produk = harga_produk;
        this->stok_produk = stok_produk;
        this->kategori_produk = kategori_produk;
    }

    void set_id(int id) { this->id = id; }
    void set_nama_produk(string nama_produk) { this->nama_produk = nama_produk; }
    void set_harga_produk(int harga_produk) { this->harga_produk = harga_produk; }
    void set_stok_produk(int stok_produk) { this->stok_produk = stok_produk; }
    void set_kategori_produk(string kategori_produk) { this->kategori_produk = kategori_produk; }

    int get_id() const { return id; }
    string get_nama_produk() const { return nama_produk; }
    int get_harga_produk() const { return harga_produk; }
    int get_stok_produk() const { return stok_produk; }
    string get_kategori_produk() const { return kategori_produk; }

    virtual ~PetShop() {}
};
