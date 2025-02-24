public class PetShop { // mendefinisikan kelas PetShop
    protected int id; // atribut untuk menyimpan ID produk
    protected String nama_produk; // atribut untuk menyimpan nama produk
    protected int harga_produk; // atribut untuk menyimpan harga produk
    protected int stok_produk; // atribut untuk menyimpan stok produk
    protected String kategori_produk; // atribut untuk menyimpan kategori produk

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public PetShop() {
        this.id = 0;
        this.nama_produk = "";
        this.harga_produk = 0;
        this.stok_produk = 0;
        this.kategori_produk = "";
    }

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang
    // diberikan
    public PetShop(int id, String nama_produk, int harga_produk, int stok_produk, String kategori_produk) {
        this.id = id;
        this.nama_produk = nama_produk;
        this.harga_produk = harga_produk;
        this.stok_produk = stok_produk;
        this.kategori_produk = kategori_produk;
    }

    // metode setter dari masing-masing atribut
    public void setId(int id) {
        this.id = id;
    }

    public void setNamaProduk(String nama_produk) {
        this.nama_produk = nama_produk;
    }

    public void setHargaProduk(int harga_produk) {
        this.harga_produk = harga_produk;
    }

    public void setStokProduk(int stok_produk) {
        this.stok_produk = stok_produk;
    }

    public void setKategoriProduk(String kategori_produk) {
        this.kategori_produk = kategori_produk;
    }

    // metode getter dari masing-masing atribut
    public int getId() {
        return id;
    }

    public String getNamaProduk() {
        return nama_produk;
    }

    public int getHargaProduk() {
        return harga_produk;
    }

    public int getStokProduk() {
        return stok_produk;
    }

    public String getKategoriProduk() {
        return kategori_produk;
    }
}