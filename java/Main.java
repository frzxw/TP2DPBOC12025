import java.util.ArrayList;
import java.util.Scanner;

public class Main { // mendefinisikan kelas Main

    // fungsi untuk mencetak tabel produk
    public static void printTable(ArrayList<PetShop> produk) {
        // inisialisasi panjang maksimum untuk setiap kolom
        int maxId = "ID".length();
        int maxNama = "Nama Produk".length();
        int maxHarga = "Harga".length();
        int maxStok = "Stok".length();
        int maxKategori = "Kategori".length();
        int maxBahan = "Bahan".length();
        int maxWarna = "Warna".length();
        int maxUkuran = "Ukuran".length();

        // loop untuk menghitung panjang maksimum setiap kolom
        for (PetShop item : produk) {
            maxId = Math.max(maxId, String.valueOf(item.getId()).length());
            maxNama = Math.max(maxNama, item.getNamaProduk().length());
            maxHarga = Math.max(maxHarga, String.valueOf(item.getHargaProduk()).length());
            maxStok = Math.max(maxStok, String.valueOf(item.getStokProduk()).length());
            maxKategori = Math.max(maxKategori, item.getKategoriProduk().length());

            if (item instanceof Aksesoris) {
                Aksesoris aksesoris = (Aksesoris) item;
                maxBahan = Math.max(maxBahan, aksesoris.getBahan().length());
                maxWarna = Math.max(maxWarna, aksesoris.getWarna().length());
            }

            if (item instanceof Baju) {
                Baju baju = (Baju) item;
                maxUkuran = Math.max(maxUkuran, baju.getUkuran().length());
            }
        }

        // mencetak header tabel
        System.out.printf(
                "+-%-" + maxId + "s-+-%-" + maxNama + "s-+-%-" + maxHarga + "s-+-%-" + maxStok + "s-+-%-" + maxKategori
                        + "s-+-%-" + maxBahan + "s-+-%-" + maxWarna + "s-+-%-" + maxUkuran + "s-+\n",
                "-".repeat(maxId), "-".repeat(maxNama), "-".repeat(maxHarga), "-".repeat(maxStok), "-".repeat(maxKategori),
                "-".repeat(maxBahan), "-".repeat(maxWarna), "-".repeat(maxUkuran));

        // mencetak judul kolom
        System.out.printf(
                "| %-" + maxId + "s | %-" + maxNama + "s | %-" + maxHarga + "s | %-" + maxStok + "s | %-" + maxKategori
                        + "s | %-" + maxBahan + "s | %-" + maxWarna + "s | %-" + maxUkuran + "s |\n",
                "ID", "Nama Produk", "Harga", "Stok", "Kategori", "Bahan", "Warna", "Ukuran");

        // mencetak garis pemisah
        System.out.printf(
                "+-%-" + maxId + "s-+-%-" + maxNama + "s-+-%-" + maxHarga + "s-+-%-" + maxStok + "s-+-%-" + maxKategori
                        + "s-+-%-" + maxBahan + "s-+-%-" + maxWarna + "s-+-%-" + maxUkuran + "s-+\n",
                "-".repeat(maxId), "-".repeat(maxNama), "-".repeat(maxHarga), "-".repeat(maxStok), "-".repeat(maxKategori),
                "-".repeat(maxBahan), "-".repeat(maxWarna), "-".repeat(maxUkuran));

        // loop untuk mencetak setiap baris produk
        for (PetShop item : produk) {
            System.out.printf(
                    "| %-" + maxId + "d | %-" + maxNama + "s | %-" + maxHarga + "d | %-" + maxStok + "d | %-"
                            + maxKategori + "s",
                    item.getId(), item.getNamaProduk(), item.getHargaProduk(), item.getStokProduk(),
                    item.getKategoriProduk());

            if (item instanceof Aksesoris) {
                Aksesoris aksesoris = (Aksesoris) item;
                System.out.printf(" | %-" + maxBahan + "s | %-" + maxWarna + "s", aksesoris.getBahan(),
                        aksesoris.getWarna());
            } else {
                System.out.printf(" | %-" + maxBahan + "s | %-" + maxWarna + "s", "-", "-");
            }

            if (item instanceof Baju) {
                Baju baju = (Baju) item;
                System.out.printf(" | %-" + maxUkuran + "s", baju.getUkuran());
            } else {
                System.out.printf(" | %-" + maxUkuran + "s", "-");
            }

            System.out.println(" |");
        }

        // mencetak garis pemisah akhir
        System.out.printf(
                "+-%-" + maxId + "s-+-%-" + maxNama + "s-+-%-" + maxHarga + "s-+-%-" + maxStok + "s-+-%-" + maxKategori
                        + "s-+-%-" + maxBahan + "s-+-%-" + maxWarna + "s-+-%-" + maxUkuran + "s-+\n",
                "-".repeat(maxId), "-".repeat(maxNama), "-".repeat(maxHarga), "-".repeat(maxStok), "-".repeat(maxKategori),
                "-".repeat(maxBahan), "-".repeat(maxWarna), "-".repeat(maxUkuran));
    }

    // fungsi untuk mencari produk berdasarkan id
    public static PetShop findProdukById(ArrayList<PetShop> produk, int id) {
        for (PetShop item : produk) {
            if (item.getId() == id) {
                return item;
            }
        }
        return null;
    }

    public static void main(String[] args) {
        ArrayList<PetShop> produk = new ArrayList<>(); // deklarasi ArrayList untuk menyimpan produk
        Scanner scanner = new Scanner(System.in); // deklarasi Scanner untuk input
        int choice; // deklarasi variabel untuk menyimpan pilihan menu

        // menambahkan beberapa produk ke dalam ArrayList
        produk.add(new Baju(1, "Baju Anjing", 50000, 10, "Baju", "Katun", "Merah", "M"));
        produk.add(new Baju(2, "Baju Kucing", 45000, 15, "Baju", "Wol", "Biru", "S"));
        produk.add(new Aksesoris(3, "Kalung Anjing", 30000, 20, "Aksesoris", "Kulit", "Hitam"));
        produk.add(new Aksesoris(4, "Mainan Kucing", 20000, 25, "Aksesoris", "Plastik", "Kuning"));
        produk.add(new PetShop(5, "Makanan Anjing", 100000, 30, "Makanan"));

        do {
            // menampilkan menu
            System.out.println("\nMenu:");
            System.out.println("1. Tambah Produk");
            System.out.println("2. Tampilkan Produk");
            System.out.println("3. Keluar");
            System.out.print("Pilih opsi: ");
            while (!scanner.hasNextInt()) { // validasi input pilihan menu
                System.out.print("Input tidak valid. Silakan masukkan angka: ");
                scanner.next();
            }
            choice = scanner.nextInt();

            switch (choice) { // switch case untuk menangani pilihan menu
                case 1: {
                    int id, harga, stok; // deklarasi variabel untuk menyimpan input produk
                    String nama, kategori, bahan, warna, ukuran;

                    System.out.print("Masukkan ID: ");
                    while (!scanner.hasNextInt()) { // validasi input id
                        System.out.print("Input tidak valid. Silakan masukkan angka: ");
                        scanner.next();
                    }
                    id = scanner.nextInt();

                    if (findProdukById(produk, id) != null) { // cek apakah id sudah ada
                        System.out.println("ID sudah ada. Silakan masukkan ID yang berbeda.");
                        break;
                    }

                    scanner.nextLine(); // clear buffer
                    System.out.print("Masukkan Nama Produk: ");
                    nama = scanner.nextLine(); // input nama produk

                    System.out.print("Masukkan Harga Produk: ");
                    while (!scanner.hasNextInt()) { // validasi input harga
                        System.out.print("Input tidak valid. Silakan masukkan angka: ");
                        scanner.next();
                    }
                    harga = scanner.nextInt();

                    System.out.print("Masukkan Stok Produk: ");
                    while (!scanner.hasNextInt()) { // validasi input stok
                        System.out.print("Input tidak valid. Silakan masukkan angka: ");
                        scanner.next();
                    }
                    stok = scanner.nextInt();

                    scanner.nextLine(); // clear buffer
                    System.out.print("Masukkan Kategori Produk: ");
                    kategori = scanner.nextLine(); // input kategori produk

                    if (kategori.equals("Baju")) { // jika kategori adalah Baju
                        System.out.print("Masukkan Bahan: ");
                        bahan = scanner.nextLine(); // input bahan
                        System.out.print("Masukkan Warna: ");
                        warna = scanner.nextLine(); // input warna
                        System.out.print("Masukkan Ukuran: ");
                        ukuran = scanner.nextLine(); // input ukuran
                        produk.add(new Baju(id, nama, harga, stok, kategori, bahan, warna, ukuran)); // menambahkan
                                                                                                     // produk Baju ke
                                                                                                     // ArrayList
                    } else if (kategori.equals("Aksesoris")) { // jika kategori adalah Aksesoris
                        System.out.print("Masukkan Bahan: ");
                        bahan = scanner.nextLine(); // input bahan
                        System.out.print("Masukkan Warna: ");
                        warna = scanner.nextLine(); // input warna
                        produk.add(new Aksesoris(id, nama, harga, stok, kategori, bahan, warna)); // menambahkan produk
                                                                                                  // Aksesoris ke
                                                                                                  // ArrayList
                    } else { // jika kategori adalah selain Baju dan Aksesoris
                        produk.add(new PetShop(id, nama, harga, stok, kategori)); // menambahkan produk PetShop ke
                                                                                  // ArrayList
                    }
                    System.out.println("Produk berhasil ditambahkan.");
                    break;
                }
                case 2:
                    printTable(produk); // memanggil fungsi untuk mencetak tabel produk
                    break;
                case 3:
                    System.out.println("Keluar dari program."); // keluar dari program
                    break;
                default:
                    System.out.println("Opsi tidak valid. Silakan coba lagi."); // pesan jika opsi tidak valid
                    break;
            }
        } while (choice != 3); // loop sampai pilihan adalah keluar

        scanner.close();
    }
}