from Aksesoris import Aksesoris

class Baju(Aksesoris):  # mendefinisikan kelas Baju yang merupakan turunan dari Aksesoris
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0, kategori_produk="", bahan="", warna="", ukuran=""):  # konstruktor default, menginisialisasi atribut dengan nilai default
        super().__init__(id, nama_produk, harga_produk, stok_produk, kategori_produk, bahan, warna)
        self.ukuran = ukuran  # atribut untuk menyimpan ukuran baju

    # metode setter untuk atribut ukuran
    def set_ukuran(self, ukuran):
        self.ukuran = ukuran

    # metode getter untuk atribut ukuran
    def get_ukuran(self):
        return self.ukuran