public class Aksesoris extends PetShop { // mendefinisikan kelas Aksesoris yang merupakan turunan dari PetShop
    protected String bahan; // atribut untuk menyimpan bahan aksesoris
    protected String warna; // atribut untuk menyimpan warna aksesoris

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public Aksesoris() {
        super();
        this.bahan = "";
        this.warna = "";
    }

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang
    // diberikan
    public Aksesoris(int id, String nama_produk, int harga_produk, int stok_produk, String kategori_produk,
            String bahan, String warna) {
        super(id, nama_produk, harga_produk, stok_produk, kategori_produk);
        this.bahan = bahan;
        this.warna = warna;
    }

    // metode setter untuk atribut bahan
    public void setBahan(String bahan) {
        this.bahan = bahan;
    }

    // metode setter untuk atribut warna
    public void setWarna(String warna) {
        this.warna = warna;
    }

    // metode getter untuk atribut bahan
    public String getBahan() {
        return bahan;
    }

    // metode getter untuk atribut warna
    public String getWarna() {
        return warna;
    }
}