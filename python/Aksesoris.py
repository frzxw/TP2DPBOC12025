from PetShop import PetShop

class Aksesoris(PetShop):  # mendefinisikan kelas Aksesoris yang merupakan turunan dari PetShop
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0, kategori_produk="", bahan="", warna=""):  # konstruktor default, menginisialisasi atribut dengan nilai default
        super().__init__(id, nama_produk, harga_produk, stok_produk, kategori_produk)
        self.bahan = bahan  # atribut untuk menyimpan bahan aksesoris
        self.warna = warna  # atribut untuk menyimpan warna aksesoris

    # metode setter untuk atribut bahan
    def set_bahan(self, bahan):
        self.bahan = bahan

    # metode setter untuk atribut warna
    def set_warna(self, warna):
        self.warna = warna

    # metode getter untuk atribut bahan
    def get_bahan(self):
        return self.bahan

    # metode getter untuk atribut warna
    def get_warna(self):
        return self.warna