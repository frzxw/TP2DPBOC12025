class PetShop:  # mendefinisikan kelas PetShop
    def __init__(self, id=0, nama_produk="", harga_produk=0, stok_produk=0, kategori_produk=""):  # konstruktor default, menginisialisasi atribut dengan nilai default
        self.id = id  # atribut untuk menyimpan ID produk
        self.nama_produk = nama_produk  # atribut untuk menyimpan nama produk
        self.harga_produk = harga_produk  # atribut untuk menyimpan harga produk
        self.stok_produk = stok_produk  # atribut untuk menyimpan stok produk
        self.kategori_produk = kategori_produk  # atribut untuk menyimpan kategori produk

    # metode setter dari masing-masing atribut
    def set_id(self, id):
        self.id = id

    def set_nama_produk(self, nama_produk):
        self.nama_produk = nama_produk

    def set_harga_produk(self, harga_produk):
        self.harga_produk = harga_produk

    def set_stok_produk(self, stok_produk):
        self.stok_produk = stok_produk

    def set_kategori_produk(self, kategori_produk):
        self.kategori_produk = kategori_produk

    # metode getter dari masing-masing atribut
    def get_id(self):
        return self.id

    def get_nama_produk(self):
        return self.nama_produk

    def get_harga_produk(self):
        return self.harga_produk

    def get_stok_produk(self):
        return self.stok_produk

    def get_kategori_produk(self):
        return self.kategori_produk