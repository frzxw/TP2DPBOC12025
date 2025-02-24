#include <bits/stdc++.h>
#include "PetShop.cpp"
#include "Aksesoris.cpp"
#include "Baju.cpp"

using namespace std;

void print_table(const vector<PetShop *> &produk)
{
    int max_id = strlen("ID");
    int max_nama = strlen("Nama Produk");
    int max_harga = strlen("Harga");
    int max_stok = strlen("Stok");
    int max_kategori = strlen("Kategori");
    int max_bahan = strlen("Bahan");
    int max_warna = strlen("Warna");
    int max_ukuran = strlen("Ukuran");

    for (size_t i = 0; i < produk.size(); ++i)
    {
        PetShop *item = produk[i];
        max_id = max(max_id, (int)to_string(item->get_id()).length());
        max_nama = max(max_nama, (int)item->get_nama_produk().length());
        max_harga = max(max_harga, (int)to_string(item->get_harga_produk()).length());
        max_stok = max(max_stok, (int)to_string(item->get_stok_produk()).length());
        max_kategori = max(max_kategori, (int)item->get_kategori_produk().length());

        const Aksesoris *aksesoris = dynamic_cast<const Aksesoris *>(item);
        const Baju *baju = dynamic_cast<const Baju *>(item);

        if (aksesoris)
        {
            max_bahan = max(max_bahan, (int)aksesoris->get_bahan().length());
            max_warna = max(max_warna, (int)aksesoris->get_warna().length());
        }

        if (baju)
        {
            max_ukuran = max(max_ukuran, (int)baju->get_ukuran().length());
        }
    }

    cout << "+" << string(max_id + 2, '-') << "+"
         << string(max_nama + 2, '-') << "+"
         << string(max_harga + 2, '-') << "+"
         << string(max_stok + 2, '-') << "+"
         << string(max_kategori + 2, '-') << "+"
         << string(max_bahan + 2, '-') << "+"
         << string(max_warna + 2, '-') << "+"
         << string(max_ukuran + 2, '-') << "+"
         << endl;

    cout << "| " << left << setw(max_id) << "ID"
         << " | " << setw(max_nama) << "Nama Produk"
         << " | " << setw(max_harga) << "Harga"
         << " | " << setw(max_stok) << "Stok"
         << " | " << setw(max_kategori) << "Kategori"
         << " | " << setw(max_bahan) << "Bahan"
         << " | " << setw(max_warna) << "Warna"
         << " | " << setw(max_ukuran) << "Ukuran"
         << " |" << endl;

    cout << "+" << string(max_id + 2, '-') << "+"
         << string(max_nama + 2, '-') << "+"
         << string(max_harga + 2, '-') << "+"
         << string(max_stok + 2, '-') << "+"
         << string(max_kategori + 2, '-') << "+"
         << string(max_bahan + 2, '-') << "+"
         << string(max_warna + 2, '-') << "+"
         << string(max_ukuran + 2, '-') << "+"
         << endl;

    for (size_t i = 0; i < produk.size(); ++i)
    {
        PetShop *item = produk[i];
        const Aksesoris *aksesoris = dynamic_cast<const Aksesoris *>(item);
        const Baju *baju = dynamic_cast<const Baju *>(item);

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

PetShop *find_produk_by_id(const vector<PetShop *> &produk, int id)
{
    for (PetShop *item : produk)
    {
        if (item->get_id() == id)
        {
            return item;
        }
    }
    return nullptr;
}

int main()
{
    vector<PetShop *> produk;
    int choice;

    produk.push_back(new Baju(1, "Baju Anjing", 50000, 10, "Baju", "Katun", "Merah", "M"));
    produk.push_back(new Baju(2, "Baju Kucing", 45000, 15, "Baju", "Wol", "Biru", "S"));
    produk.push_back(new Aksesoris(3, "Kalung Anjing", 30000, 20, "Aksesoris", "Kulit", "Hitam"));
    produk.push_back(new Aksesoris(4, "Mainan Kucing", 20000, 25, "Aksesoris", "Plastik", "Kuning"));
    produk.push_back(new PetShop(5, "Makanan Anjing", 100000, 30, "Makanan"));

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Tampilkan Produk\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka: ";
        }

        switch (choice)
        {
        case 1:
        {
            int id, harga, stok;
            string nama, kategori, bahan, warna, ukuran;

            cout << "Masukkan ID: ";
            while (!(cin >> id))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            if (find_produk_by_id(produk, id) != nullptr)
            {
                cout << "ID sudah ada. Silakan masukkan ID yang berbeda.\n";
                break;
            }

            cout << "Masukkan Nama Produk: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Masukkan Harga Produk: ";
            while (!(cin >> harga))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            cout << "Masukkan Stok Produk: ";
            while (!(cin >> stok))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Silakan masukkan angka: ";
            }

            cout << "Masukkan Kategori Produk: ";
            cin.ignore();
            getline(cin, kategori);

            if (kategori == "Baju")
            {
                cout << "Masukkan Bahan: ";
                getline(cin, bahan);
                cout << "Masukkan Warna: ";
                getline(cin, warna);
                cout << "Masukkan Ukuran: ";
                getline(cin, ukuran);
                produk.push_back(new Baju(id, nama, harga, stok, kategori, bahan, warna, ukuran));
            }
            else if (kategori == "Aksesoris")
            {
                cout << "Masukkan Bahan: ";
                getline(cin, bahan);
                cout << "Masukkan Warna: ";
                getline(cin, warna);
                produk.push_back(new Aksesoris(id, nama, harga, stok, kategori, bahan, warna));
            }
            else
            {
                produk.push_back(new PetShop(id, nama, harga, stok, kategori));
            }
            cout << "Produk berhasil ditambahkan.\n";
            break;
        }
        case 2:
            print_table(produk);
            break;
        case 3:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi.\n";
            break;
        }
    } while (choice != 3);

    for (size_t i = 0; i < produk.size(); ++i)
    {
        delete produk[i];
    }

    return 0;
}