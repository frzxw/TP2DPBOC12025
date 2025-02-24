from PetShop import PetShop
from Aksesoris import Aksesoris
from Baju import Baju

def print_table(produk):
    # inisialisasi panjang maksimum untuk setiap kolom
    max_id = len("ID")
    max_nama = len("Nama Produk")
    max_harga = len("Harga")
    max_stok = len("Stok")
    max_kategori = len("Kategori")
    max_bahan = len("Bahan")
    max_warna = len("Warna")
    max_ukuran = len("Ukuran")

    # loop untuk menghitung panjang maksimum setiap kolom
    for item in produk:
        max_id = max(max_id, len(str(item.get_id())))
        max_nama = max(max_nama, len(item.get_nama_produk()))
        max_harga = max(max_harga, len(str(item.get_harga_produk())))
        max_stok = max(max_stok, len(str(item.get_stok_produk())))
        max_kategori = max(max_kategori, len(item.get_kategori_produk()))

        if isinstance(item, Aksesoris):
            max_bahan = max(max_bahan, len(item.get_bahan()))
            max_warna = max(max_warna, len(item.get_warna()))

        if isinstance(item, Baju):
            max_ukuran = max(max_ukuran, len(item.get_ukuran()))

    # mencetak header tabel
    print("+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+" % (
        '-' * max_id, '-' * max_nama, '-' * max_harga, '-' * max_stok, '-' * max_kategori, '-' * max_bahan, '-' * max_warna, '-' * max_ukuran))
    print("| %s | %s | %s | %s | %s | %s | %s | %s |" % (
        "ID".ljust(max_id), "Nama Produk".ljust(max_nama), "Harga".ljust(max_harga), "Stok".ljust(max_stok), "Kategori".ljust(max_kategori), "Bahan".ljust(max_bahan), "Warna".ljust(max_warna), "Ukuran".ljust(max_ukuran)))
    print("+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+" % (
        '-' * max_id, '-' * max_nama, '-' * max_harga, '-' * max_stok, '-' * max_kategori, '-' * max_bahan, '-' * max_warna, '-' * max_ukuran))

    # loop untuk mencetak setiap baris produk
    for item in produk:
        print("| %s | %s | %s | %s | %s" % (
            str(item.get_id()).ljust(max_id), item.get_nama_produk().ljust(max_nama), str(item.get_harga_produk()).ljust(max_harga), str(item.get_stok_produk()).ljust(max_stok), item.get_kategori_produk().ljust(max_kategori)), end="")

        if isinstance(item, Aksesoris):
            print(" | %s | %s" % (item.get_bahan().ljust(max_bahan), item.get_warna().ljust(max_warna)), end="")
        else:
            print(" | %s | %s" % ('-'.ljust(max_bahan), '-'.ljust(max_warna)), end="")

        if isinstance(item, Baju):
            print(" | %s" % item.get_ukuran().ljust(max_ukuran), end="")
        else:
            print(" | %s" % '-'.ljust(max_ukuran), end="")

        print(" |")

    # mencetak garis pemisah akhir
    print("+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+-%s-+" % (
        '-' * max_id, '-' * max_nama, '-' * max_harga, '-' * max_stok, '-' * max_kategori, '-' * max_bahan, '-' * max_warna, '-' * max_ukuran))

def find_produk_by_id(produk, id):
    for item in produk:
        if item.get_id() == id:
            return item
    return None

def main():
    produk = []  # deklarasi list untuk menyimpan produk
    scanner = input  # menggunakan input untuk scanner
    choice = 0  # deklarasi variabel untuk menyimpan pilihan menu

    # menambahkan beberapa produk ke dalam list
    produk.append(Baju(1, "Baju Anjing", 50000, 10, "Baju", "Katun", "Merah", "M"))
    produk.append(Baju(2, "Baju Kucing", 45000, 15, "Baju", "Wol", "Biru", "S"))
    produk.append(Aksesoris(3, "Kalung Anjing", 30000, 20, "Aksesoris", "Kulit", "Hitam"))
    produk.append(Aksesoris(4, "Mainan Kucing", 20000, 25, "Aksesoris", "Plastik", "Kuning"))
    produk.append(PetShop(5, "Makanan Anjing", 100000, 30, "Makanan"))

    while choice != 3:
        # menampilkan menu
        print("\nMenu:")
        print("1. Tambah Produk")
        print("2. Tampilkan Produk")
        print("3. Keluar")
        choice = int(input("Pilih opsi: "))

        if choice == 1:
            id = int(input("Masukkan ID: "))
            if find_produk_by_id(produk, id) is not None:
                print("ID sudah ada. Silakan masukkan ID yang berbeda.")
                continue

            nama = input("Masukkan Nama Produk: ")
            harga = int(input("Masukkan Harga Produk: "))
            stok = int(input("Masukkan Stok Produk: "))
            kategori = input("Masukkan Kategori Produk: ")

            if kategori == "Baju":
                bahan = input("Masukkan Bahan: ")
                warna = input("Masukkan Warna: ")
                ukuran = input("Masukkan Ukuran: ")
                produk.append(Baju(id, nama, harga, stok, kategori, bahan, warna, ukuran))
            elif kategori == "Aksesoris":
                bahan = input("Masukkan Bahan: ")
                warna = input("Masukkan Warna: ")
                produk.append(Aksesoris(id, nama, harga, stok, kategori, bahan, warna))
            else:
                produk.append(PetShop(id, nama, harga, stok, kategori))

            print("Produk berhasil ditambahkan.")
        elif choice == 2:
            print_table(produk)
        elif choice == 3:
            print("Keluar dari program.")
        else:
            print("Opsi tidak valid. Silakan coba lagi.")

if __name__ == "__main__":
    main()