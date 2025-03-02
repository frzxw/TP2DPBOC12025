<?php

require_once 'PetShop.php';

class Aksesoris extends PetShop
{ // mendefinisikan kelas Aksesoris yang merupakan turunan dari PetShop
    protected $bahan; // atribut untuk menyimpan bahan aksesoris
    protected $warna; // atribut untuk menyimpan warna aksesoris

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public function __construct($id = 0, $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $kategori_produk = "", $foto = "", $bahan = "", $warna = "")
    {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $kategori_produk, $foto);
        $this->bahan = $bahan;
        $this->warna = $warna;
    }

    // metode setter untuk atribut bahan
    public function setBahan($bahan)
    {
        $this->bahan = $bahan;
    }

    // metode setter untuk atribut warna
    public function setWarna($warna)
    {
        $this->warna = $warna;
    }

    // metode getter untuk atribut bahan
    public function getBahan()
    {
        return $this->bahan;
    }

    // metode getter untuk atribut warna
    public function getWarna()
    {
        return $this->warna;
    }
}
?>