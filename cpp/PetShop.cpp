#pragma once             // mencegah multiple inclusion dari header file yang sama
#include <bits/stdc++.h> // menyertakan semua library standar C++

using namespace std; // menggunakan namespace standar C++

class PetShop // mendefinisikan kelas PetShop
{
protected:                  // akses protected, hanya bisa diakses oleh kelas ini dan turunannya
    int id;                 // atribut untuk menyimpan ID produk
    string nama_produk;     // atribut untuk menyimpan nama produk
    int harga_produk;       // atribut untuk menyimpan harga produk
    int stok_produk;        // atribut untuk menyimpan stok produk
    string kategori_produk; // atribut untuk menyimpan kategori produk

public: // akses public, bisa diakses dari luar kelas
    // konstruktor default, menginisialisasi atribut dengan nilai default
    PetShop() : id(0), nama_produk(""), harga_produk(0), stok_produk(0), kategori_produk("") {}

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang diberikan
    PetShop(int id, string nama_produk, int harga_produk, int stok_produk, string kategori_produk)
    {
        this->id = id;
        this->nama_produk = nama_produk;
        this->harga_produk = harga_produk;
        this->stok_produk = stok_produk;
        this->kategori_produk = kategori_produk;
    }

    // metode setter dari masing-masing atribut
    void set_id(int id) { this->id = id; }
    void set_nama_produk(string nama_produk) { this->nama_produk = nama_produk; }
    void set_harga_produk(int harga_produk) { this->harga_produk = harga_produk; }
    void set_stok_produk(int stok_produk) { this->stok_produk = stok_produk; }
    void set_kategori_produk(string kategori_produk) { this->kategori_produk = kategori_produk; }

    // metode getter dari masing-masing atribut
    int get_id() const { return id; }
    string get_nama_produk() const { return nama_produk; }
    int get_harga_produk() const { return harga_produk; }
    int get_stok_produk() const { return stok_produk; }
    string get_kategori_produk() const { return kategori_produk; }

    // destruktor virtual, membersihkan objek saat tidak digunakan lagi
    virtual ~PetShop() {}
};
