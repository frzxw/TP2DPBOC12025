public class Baju extends Aksesoris { // mendefinisikan kelas Baju yang merupakan turunan dari Aksesoris
    private String ukuran; // atribut untuk menyimpan ukuran baju

    // konstruktor default, menginisialisasi atribut dengan nilai default
    public Baju() {
        super();
        this.ukuran = "";
    }

    // konstruktor dengan parameter, menginisialisasi atribut dengan parameter yang
    // diberikan
    public Baju(int id, String nama_produk, int harga_produk, int stok_produk, String kategori_produk, String bahan,
            String warna, String ukuran) {
        super(id, nama_produk, harga_produk, stok_produk, kategori_produk, bahan, warna);
        this.ukuran = ukuran;
    }

    // metode setter untuk atribut ukuran
    public void setUkuran(String ukuran) {
        this.ukuran = ukuran;
    }

    // metode getter untuk atribut ukuran
    public String getUkuran() {
        return ukuran;
    }
}