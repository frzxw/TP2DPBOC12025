<?php
// memuat file kelas yang diperlukan
require_once 'PetShop.php';
require_once 'Aksesoris.php';
require_once 'Baju.php';

// memulai sesi untuk menyimpan data
session_start();

// menginisialisasi array produk dalam sesi jika belum ada
if (!isset($_SESSION['produk'])) {
    $_SESSION['produk'] = [
        new Baju(1, "Baju Anjing", 50000, 10, "Baju", "1.png", "Katun", "Merah", "M"),
        new Baju(2, "Baju Kucing", 45000, 15, "Baju", "2.png", "Wol", "Biru", "S"),
        new Aksesoris(3, "Kalung Anjing", 30000, 20, "Aksesoris", "3.png", "Kulit", "Hitam"),
        new Aksesoris(4, "Mainan Kucing", 20000, 25, "Aksesoris", "4.png", "Plastik", "Kuning"),
        new PetShop(5, "Makanan Anjing", 100000, 30, "Produk", "5.png")
    ];
}

// mengambil produk dari sesi
$produk = $_SESSION['produk'];

// fungsi untuk mengecek apakah id sudah ada
function is_id_exists($id, $produk, $exclude_id = null)
{
    foreach ($produk as $item) {
        if ($item->getId() == $id && $id != $exclude_id) {
            return true;
        }
    }
    return false;
}

// fungsi untuk menambahkan produk baru ke array produk
function add_produk(&$produk, $produk_baru)
{
    $produk[] = $produk_baru;
    // memperbarui sesi
    $_SESSION['produk'] = $produk;
}

// mengecek apakah request method adalah post untuk create
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // mengambil data dari form
    $id = $_POST['id'];
    $nama_produk = $_POST['nama_produk'];
    $harga_produk = $_POST['harga_produk'];
    $stok_produk = $_POST['stok_produk'];
    $kategori_produk = $_POST['kategori_produk'];
    $bahan = $_POST['bahan'] ?? null;
    $warna = $_POST['warna'] ?? null;
    $ukuran = $_POST['ukuran'] ?? null;

    // mengecek apakah id sudah ada
    if (is_id_exists($id, $produk)) {
        $_SESSION['flash_message'] = "Error! ID sudah digunakan. Silakan gunakan ID yang berbeda.";
        $_SESSION['flash_type'] = "danger";
        header('Location: index.php');
        exit;
    }

    // mengolah upload foto
    $foto = null;
    if (isset($_FILES['foto']) && $_FILES['foto']['error'] == UPLOAD_ERR_OK) {
        $fileTmpPath = $_FILES['foto']['tmp_name'];
        $fileName = $id . '.' . pathinfo($_FILES['foto']['name'], PATHINFO_EXTENSION);
        $uploadFileDir = 'uploads/';

        // membuat direktori jika belum ada
        if (!is_dir($uploadFileDir)) {
            mkdir($uploadFileDir, 0777, true);
        }

        $dest_path = "{$uploadFileDir}{$fileName}";

        if (move_uploaded_file($fileTmpPath, $dest_path)) {
            $foto = $fileName;
        } else {
            $_SESSION['flash_message'] = "Error! Terjadi kesalahan saat memindahkan file yang diunggah.";
            $_SESSION['flash_type'] = "danger";
            header('Location: index.php');
            exit;
        }
    }

    // membuat objek produk berdasarkan kategori
    if ($kategori_produk == 'Baju') {
        $produk_baru = new Baju($id, $nama_produk, $harga_produk, $stok_produk, $kategori_produk, $foto, $bahan, $warna, $ukuran);
    } elseif ($kategori_produk == 'Aksesoris') {
        $produk_baru = new Aksesoris($id, $nama_produk, $harga_produk, $stok_produk, $kategori_produk, $foto, $bahan, $warna);
    } else {
        $produk_baru = new PetShop($id, $nama_produk, $harga_produk, $stok_produk, $kategori_produk, $foto);
    }

    // menambahkan produk baru ke array produk
    add_produk($produk, $produk_baru);

    // tambahkan pesan flash
    $_SESSION['flash_message'] = "Produk berhasil ditambahkan!";
    $_SESSION['flash_type'] = "success";

    // redirect ke halaman index.php
    header('Location: index.php');
    exit;
}

// mengambil pesan flash jika ada
$flash_message = $_SESSION['flash_message'] ?? null;
$flash_type = $_SESSION['flash_type'] ?? 'success';

// menghapus pesan flash setelah ditampilkan
unset($_SESSION['flash_message']);
unset($_SESSION['flash_type']);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pet Shop</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/sweetalert2@10/dist/sweetalert2.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.1/css/all.min.css">
    <style>
        .table-responsive {
            overflow-x: auto;
        }

        .hidden-field {
            display: none;
        }
    </style>
</head>

<body>
    <div class="container mt-5">
        <h1 class="mb-4">Pet Shop</h1>

        <!-- menampilkan pesan flash jika ada -->
        <?php if ($flash_message): ?>
            <div class="alert alert-<?= $flash_type ?> alert-dismissible fade show" role="alert">
                <?= $flash_message ?>
                <button type="button" class="close" data-dismiss="alert" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>
            </div>
        <?php endif; ?>

        <div class="table-responsive">
            <table class="table table-bordered table-striped table-hover">
                <thead class="thead-dark">
                    <tr>
                        <th>ID</th>
                        <th>Nama Produk</th>
                        <th>Harga</th>
                        <th>Stok</th>
                        <th>Kategori</th>
                        <th>Bahan</th>
                        <th>Warna</th>
                        <th>Ukuran</th>
                        <th>Foto</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($produk as $item): ?>
                        <tr>
                            <td><?= $item->getId() ?></td>
                            <td><?= $item->getNamaProduk() ?></td>
                            <td>Rp. <?= number_format($item->getHargaProduk(), 0, ',', '.') ?></td>
                            <td><?= $item->getStokProduk() ?></td>
                            <td><?= $item->getKategoriProduk() ?></td>
                            <td><?= method_exists($item, 'getBahan') ? $item->getBahan() : '-' ?></td>
                            <td><?= method_exists($item, 'getWarna') ? $item->getWarna() : '-' ?></td>
                            <td><?= method_exists($item, 'getUkuran') ? $item->getUkuran() : '-' ?></td>
                            <td>
                                <?php if ($item->getFoto()): ?>
                                    <img src="uploads/<?= $item->getFoto() ?>" alt="<?= $item->getNamaProduk() ?>" width="50">
                                <?php else: ?>
                                    <span>No Image</span>
                                <?php endif; ?>
                            </td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        </div>
        <!-- tombol untuk membuka modal tambah produk -->
        <button class="btn btn-primary" data-toggle="modal" data-target="#addProductModal">
            <i class="fas fa-plus"></i> Tambah Produk
        </button>
    </div>

    <!-- modal tambah produk -->
    <div class="modal fade" id="addProductModal" tabindex="-1" aria-labelledby="addProductModalLabel"
        aria-hidden="true">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header bg-primary text-white">
                    <h5 class="modal-title" id="addProductModalLabel">Tambah Produk</h5>
                    <button type="button" class="close text-white" data-dismiss="modal" aria-label="Close">
                        <span aria-hidden="true">&times;</span>
                    </button>
                </div>
                <div class="modal-body">
                    <form id="addProductForm" action="index.php" method="post" enctype="multipart/form-data">
                        <div class="form-group">
                            <label for="kategori_produk">Kategori Produk <span class="text-danger">*</span></label>
                            <select class="form-control" id="kategori_produk" name="kategori_produk" required>
                                <option value="">-- Pilih Kategori --</option>
                                <option value="Baju">Baju</option>
                                <option value="Aksesoris">Aksesoris</option>
                                <option value="Produk">Produk</option>
                            </select>
                            <small class="form-text text-muted">Pilih kategori terlebih dahulu untuk menampilkan field
                                yang sesuai</small>
                        </div>

                        <div id="product-fields" class="d-none">
                            <div class="form-group">
                                <label for="id">ID Produk <span class="text-danger">*</span></label>
                                <input type="number" class="form-control" id="id" name="id" required>
                            </div>
                            <div class="form-group">
                                <label for="nama_produk">Nama Produk <span class="text-danger">*</span></label>
                                <input type="text" class="form-control" id="nama_produk" name="nama_produk" required>
                            </div>
                            <div class="form-group">
                                <label for="harga_produk">Harga (Rp) <span class="text-danger">*</span></label>
                                <input type="number" class="form-control" id="harga_produk" name="harga_produk"
                                    required>
                            </div>
                            <div class="form-group">
                                <label for="stok_produk">Stok <span class="text-danger">*</span></label>
                                <input type="number" class="form-control" id="stok_produk" name="stok_produk" required>
                            </div>

                            <div id="bahan-group" class="form-group hidden-field">
                                <label for="bahan">Bahan</label>
                                <input type="text" class="form-control" id="bahan" name="bahan">
                            </div>
                            <div id="warna-group" class="form-group hidden-field">
                                <label for="warna">Warna</label>
                                <input type="text" class="form-control" id="warna" name="warna">
                            </div>
                            <div id="ukuran-group" class="form-group hidden-field">
                                <label for="ukuran">Ukuran</label>
                                <input type="text" class="form-control" id="ukuran" name="ukuran">
                            </div>
                            <div class="form-group">
                                <label for="foto">Foto Produk</label>
                                <input type="file" class="form-control-file" id="foto" name="foto">
                                <small class="form-text text-muted">Format: jpg, jpeg, png. Max: 2MB</small>
                            </div>

                            <button type="submit" class="btn btn-primary btn-block">
                                <i class="fas fa-save"></i> Simpan Produk
                            </button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>

    <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@10"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.bundle.min.js"></script>
    <script>
        // fungsi untuk mengatur tampilan field form berdasarkan kategori
        function updateFormFields() {
            var category = document.getElementById('kategori_produk').value;
            var productFields = document.getElementById('product-fields');
            var bahanGroup = document.getElementById('bahan-group');
            var warnaGroup = document.getElementById('warna-group');
            var ukuranGroup = document.getElementById('ukuran-group');

            // tampilkan/sembunyikan seluruh field produk
            if (category === '') {
                productFields.classList.add('d-none');
                return;
            } else {
                productFields.classList.remove('d-none');
            }

            // sembunyikan semua field opsional terlebih dahulu
            bahanGroup.classList.add('hidden-field');
            warnaGroup.classList.add('hidden-field');
            ukuranGroup.classList.add('hidden-field');

            // tampilkan field sesuai kategori
            if (category === 'Baju') {
                bahanGroup.classList.remove('hidden-field');
                warnaGroup.classList.remove('hidden-field');
                ukuranGroup.classList.remove('hidden-field');
            } else if (category === 'Aksesoris') {
                bahanGroup.classList.remove('hidden-field');
                warnaGroup.classList.remove('hidden-field');
            }
        }

        // reset form saat modal ditutup
        function resetForm() {
            document.getElementById('addProductForm').reset();
            document.getElementById('product-fields').classList.add('d-none');
        }

        // jalankan saat halaman dimuat
        document.addEventListener('DOMContentLoaded', function () {
            // update field saat kategori berubah
            document.getElementById('kategori_produk').addEventListener('change', updateFormFields);

            // reset form saat modal ditutup
            $('#addProductModal').on('hidden.bs.modal', resetForm);

            // knfirmasi saat menambah produk
            document.getElementById('addProductForm').addEventListener('submit', function (event) {
                event.preventDefault();

                Swal.fire({
                    title: 'Konfirmasi',
                    text: "Apakah Anda yakin ingin menambahkan produk ini?",
                    icon: 'question',
                    showCancelButton: true,
                    confirmButtonColor: '#3085d6',
                    cancelButtonColor: '#d33',
                    confirmButtonText: 'Ya, tambahkan!',
                    cancelButtonText: 'Batal'
                }).then((result) => {
                    if (result.isConfirmed) {
                        this.submit();
                    }
                });
            });
        });

        // tampilkan SweetAlert jika ada flash message
        <?php if ($flash_message): ?>
            Swal.fire({
                title: '<?= $flash_type === "success" ? "Berhasil!" : "Perhatian!" ?>',
                text: "<?= $flash_message ?>",
                icon: '<?= $flash_type ?>',
                timer: 3000,
                timerProgressBar: true
            });
        <?php endif; ?>
    </script>
</body>

</html>