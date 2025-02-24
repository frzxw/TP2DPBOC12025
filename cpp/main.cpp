#include <bits/stdc++.h> // menyertakan semua header standar c++
#include "PetShop.cpp" // menyertakan file header PetShop
#include "Aksesoris.cpp" // menyertakan file header Aksesoris
#include "Baju.cpp" // menyertakan file header Baju

using namespace std; // menggunakan namespace standar

// fungsi untuk mencetak tabel produk
void print_table(const vector<PetShop *> &produk)
{
    // inisialisasi panjang maksimum untuk setiap kolom
    int max_id = strlen("ID");
    int max_nama = strlen("Nama Produk");
    int max_harga = strlen("Harga");
    int max_stok = strlen("Stok");
    int max_kategori = strlen("Kategori");
    int max_bahan = strlen("Bahan");
    int max_warna = strlen("Warna");
    int max_ukuran = strlen("Ukuran");

    // loop untuk menghitung panjang maksimum setiap kolom
    for (size_t i = 0; i < produk.size(); ++i)
    {
        PetShop *item = produk[i]; // mengambil item produk
        max_id = max(max_id, (int)to_string(item->get_id()).length()); // menghitung panjang maksimum id
        max_nama = max(max_nama, (int)item->get_nama_produk().length()); // menghitung panjang maksimum nama produk
        max_harga = max(max_harga, (int)to_string(item->get_harga_produk()).length()); // menghitung panjang maksimum harga
        max_stok = max(max_stok, (int)to_string(item->get_stok_produk()).length()); // menghitung panjang maksimum stok
        max_kategori = max(max_kategori, (int)item->get_kategori_produk().length()); // menghitung panjang maksimum kategori

        const Aksesoris *aksesoris = dynamic_cast<const Aksesoris *>(item); // mencoba cast ke tipe Aksesoris
        const Baju *baju = dynamic_cast<const Baju *>(item); // mencoba cast ke tipe Baju

        if (aksesoris)
        {
            max_bahan = max(max_bahan, (int)aksesoris->get_bahan().length()); // menghitung panjang maksimum bahan
            max_warna = max(max_warna, (int)aksesoris->get_warna().length()); // menghitung panjang maksimum warna
        }

        if (baju)
        {
            max_ukuran = max(max_ukuran, (int)baju->get_ukuran().length()); // menghitung panjang maksimum ukuran
        }
    }

    // mencetak header tabel
    cout << "+" << string(max_id + 2, '-') << "+"
         << string(max_nama + 2, '-') << "+"
         << string(max_harga + 2, '-') << "+"
         << string(max_stok + 2, '-') << "+"
         << string(max_kategori + 2, '-') << "+"
         << string(max_bahan + 2, '-') << "+"
         << string(max_warna + 2, '-') << "+"
         << string(max_ukuran + 2, '-') << "+"
         << endl;

    // mencetak judul kolom
    cout << "| " << left << setw(max_id) << "ID"
         << " | " << setw(max_nama) << "Nama Produk"
         << " | " << setw(max_harga) << "Harga"
         << " | " << setw(max_stok) << "Stok"
         << " | " << setw(max_kategori) << "Kategori"
         << " | " << setw(max_bahan) << "Bahan"
         << " | " << setw(max_warna) << "Warna"
         << " | " << setw(max_ukuran) << "Ukuran"
         << " |" << endl;

    // mencetak garis pemisah
    cout << "+" << string(max_id + 2, '-') << "+"
         << string(max_nama + 2, '-') << "+"
         << string(max_harga + 2, '-') << "+"
         << string(max_stok + 2, '-') << "+"
         << string(max_kategori + 2, '-') << "+"
         << string(max_bahan + 2, '-') << "+"
         << string(max_warna + 2, '-') << "+"
         << string(max_ukuran + 2, '-') << "+"
         << endl;

    // loop untuk mencetak setiap baris produk
    for (size_t i = 0; i < produk.size(); ++i)
    {
        PetShop *item = produk[i]; // mengambil item produk
        const Aksesoris *aksesoris = dynamic_cast<const Aksesoris *>(item); // mencoba cast ke tipe Aksesoris
        const Baju *baju = dynamic_cast<const Baju *>(item); // mencoba cast ke tipe Baju

        // mencetak data produk
        cout << "| " << left << setw(max_id) << item->get_id()
             << " | " << setw(max_nama) << item->get_nama_produk()
             << " | " << setw(max_harga) << item->get_harga_produk()
             << " | " << setw(max_stok) << item->get_stok_produk()
             << " | " << setw(max_kategori) << item->get_kategori_produk();

        if (aksesoris)
        {
            cout << " | " << setw(max_bahan) << aksesoris->get_bahan()
                 << " | " << setw(max_warna) << aksesoris->get_warna();
        }
        else
        {
            cout << " | " << setw(max_bahan) << "-"
                 << " | " << setw(max_warna) << "-";
        }

        if (baju)
        {
            cout << " | " << setw(max_ukuran) << baju->get_ukuran();
        }
        else
        {
            cout << " | " << setw(max_ukuran) << "-";
        }

        cout << " |" << endl;
    }

    // mencetak garis pemisah akhir
    cout << "+" << string(max_id + 2, '-') << "+"
         << string(max_nama + 2, '-') << "+"
         << string(max_harga + 2, '-') << "+"
         << string(max_stok + 2, '-') << "+"
         << string(max_kategori + 2, '-') << "+"
         << string(max_bahan + 2, '-') << "+"
         << string(max_warna + 2, '-') << "+"
         << string(max_ukuran + 2, '-') << "+"
         << endl;
}

// fungsi untuk mencari produk berdasarkan id
PetShop *find_produk_by_id(const vector<PetShop *> &produk, int id)
{
    for (PetShop *item : produk) // loop untuk setiap item produk
    {
        if (item->get_id() == id) // jika id produk sama dengan id yang dicari
        {
            return item; // mengembalikan produk yang ditemukan
        }
    }
    return nullptr; // mengembalikan nullptr jika produk tidak ditemukan
}

int main()
{
    vector<PetShop *> produk; // deklarasi vector untuk menyimpan produk
    int choice; // deklarasi variabel untuk menyimpan pilihan menu

    // menambahkan beberapa produk ke dalam vector
    produk.push_back(new Baju(1, "Baju Anjing", 50000, 10, "Baju", "Katun", "Merah", "M"));
    produk.push_back(new Baju(2, "Baju Kucing", 45000, 15, "Baju", "Wol", "Biru", "S"));
    produk.push_back(new Aksesoris(3, "Kalung Anjing", 30000, 20, "Aksesoris", "Kulit", "Hitam"));
    produk.push_back(new Aksesoris(4, "Mainan Kucing", 20000, 25, "Aksesoris", "Plastik", "Kuning"));
    produk.push_back(new PetShop(5, "Makanan Anjing", 100000, 30, "Makanan"));

    do
    {
        // menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        while (!(cin >> choice)) // validasi input pilihan menu
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka: ";
        }

        switch (choice) // switch case untuk menangani pilihan menu
        {
        case 1:
        {
            int id, harga, stok; // deklarasi variabel untuk menyimpan input produk
            string nama, kategori, bahan, warna, ukuran;

            cout << "Masukkan ID: ";
            while (!(cin >> id)) // validasi input id
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            if (find_produk_by_id(produk, id) != nullptr) // cek apakah id sudah ada
            {
                cout << "ID sudah ada. Silakan masukkan ID yang berbeda.\n";
                break;
            }

            cout << "Masukkan Nama Produk: ";
            cin.ignore();
            getline(cin, nama); // input nama produk

            cout << "Masukkan Harga Produk: ";
            while (!(cin >> harga)) // validasi input harga
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            cout << "Masukkan Stok Produk: ";
            while (!(cin >> stok)) // validasi input stok
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            cout << "Masukkan Kategori Produk: ";
            cin.ignore();
            getline(cin, kategori); // input kategori produk

            if (kategori == "Baju") // jika kategori adalah Baju
            {
                cout << "Masukkan Bahan: ";
                getline(cin, bahan); // input bahan
                cout << "Masukkan Warna: ";
                getline(cin, warna); // input warna
                cout << "Masukkan Ukuran: ";
                getline(cin, ukuran); // input ukuran
                produk.push_back(new Baju(id, nama, harga, stok, kategori, bahan, warna, ukuran)); // menambahkan produk Baju ke vector
            }
            else if (kategori == "Aksesoris") // jika kategori adalah Aksesoris
            {
                cout << "Masukkan Bahan: ";
                getline(cin, bahan); // input bahan
                cout << "Masukkan Warna: ";
                getline(cin, warna); // input warna
                produk.push_back(new Aksesoris(id, nama, harga, stok, kategori, bahan, warna)); // menambahkan produk Aksesoris ke vector
            }
            else // jika kategori adalah selain Baju dan Aksesoris
            {
                produk.push_back(new PetShop(id, nama, harga, stok, kategori)); // menambahkan produk PetShop ke vector
            }
            cout << "Produk berhasil ditambahkan.\n";
            break;
        }
        case 2:
            print_table(produk); // memanggil fungsi untuk mencetak tabel produk
            break;
        case 3:
            cout << "Keluar dari program.\n"; // keluar dari program
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi.\n"; // pesan jika opsi tidak valid
            break;
        }
    } while (choice != 3); // loop sampai pilihan adalah keluar

    for (size_t i = 0; i < produk.size(); ++i) // loop untuk menghapus semua produk dari memori
    {
        delete produk[i];
    }

    return 0; // mengembalikan nilai 0
}