<?php

class PetShop
{ // mendefinisikan kelas PetShop
    protected $id; // atribut untuk menyimpan ID produk
    protected $nama_produk; // atribut untuk menyimpan nama produk
    protected $harga_produk; // atribut untuk menyimpan harga produk
    protected $stok_produk; // atribut untuk menyimpan stok produk
    protected $kategori_produk; // atribut untuk menyimpan kategori produk
    protected $foto; // atribut untuk menyimpan foto produk

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public function __construct($id = 0, $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $kategori_produk = "", $foto = "")
    {
        $this->id = $id;
        $this->nama_produk = $nama_produk;
        $this->harga_produk = $harga_produk;
        $this->stok_produk = $stok_produk;
        $this->kategori_produk = $kategori_produk;
        $this->foto = $foto;
    }

    // metode setter dari masing-masing atribut
    public function setId($id)
    {
        $this->id = $id;
    }

    public function setNamaProduk($nama_produk)
    {
        $this->nama_produk = $nama_produk;
    }

    public function setHargaProduk($harga_produk)
    {
        $this->harga_produk = $harga_produk;
    }

    public function setStokProduk($stok_produk)
    {
        $this->stok_produk = $stok_produk;
    }

    public function setKategoriProduk($kategori_produk)
    {
        $this->kategori_produk = $kategori_produk;
    }

    public function setFoto($foto)
    {
        $this->foto = $foto;
    }

    // metode getter dari masing-masing atribut
    public function getId()
    {
        return $this->id;
    }

    public function getNamaProduk()
    {
        return $this->nama_produk;
    }

    public function getHargaProduk()
    {
        return $this->harga_produk;
    }

    public function getStokProduk()
    {
        return $this->stok_produk;
    }

    public function getKategoriProduk()
    {
        return $this->kategori_produk;
    }

    public function getFoto()
    {
        return $this->foto;
    }
}
?>