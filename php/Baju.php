<?php

require_once 'Aksesoris.php';

class Baju extends Aksesoris
{ // mendefinisikan kelas Baju yang merupakan turunan dari Aksesoris
    private $ukuran; // atribut untuk menyimpan ukuran baju

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public function __construct($id = 0, $nama_produk = "", $harga_produk = 0, $stok_produk = 0, $kategori_produk = "", $foto = "", $bahan = "", $warna = "", $ukuran = "")
    {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $kategori_produk, $foto, $bahan, $warna);
        $this->ukuran = $ukuran;
    }

    // metode setter untuk atribut ukuran
    public function setUkuran($ukuran)
    {
        $this->ukuran = $ukuran;
    }

    // metode getter untuk atribut ukuran
    public function getUkuran()
    {
        return $this->ukuran;
    }
}
?>