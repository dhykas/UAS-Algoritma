#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Pengeluaran {
    string kategori;
    int jumlah;
};

int main() {
    int saldoAwal, totalPengeluaran = 0, pilihan;
    vector<Pengeluaran> daftarPengeluaran;

    cout << "Selamat datang di Aplikasi Keuangan Harian!\n";
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldoAwal;

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Pengeluaran\n";
        cout << "2. Tampilkan Total Pengeluaran\n";
        cout << "3. Tampilkan Sisa Saldo\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Pengeluaran pengeluaranBaru;
            cout << "Masukkan nama kategori pengeluaran: ";
            cin.ignore(); // Membersihkan buffer input
            getline(cin, pengeluaranBaru.kategori);
            cout << "Masukkan jumlah pengeluaran: ";
            cin >> pengeluaranBaru.jumlah;

            if (pengeluaranBaru.jumlah <= saldoAwal) {
                daftarPengeluaran.push_back(pengeluaranBaru);
                totalPengeluaran += pengeluaranBaru.jumlah;
                saldoAwal -= pengeluaranBaru.jumlah;
                cout << "Pengeluaran berhasil ditambahkan!\n";
            } else {
                cout << "Saldo tidak cukup untuk pengeluaran ini!\n";
            }
            break;
        }
        case 2:
            cout << "Total pengeluaran Anda sejauh ini: " << totalPengeluaran << "\n";
            break;

        case 3:
            cout << "Sisa saldo Anda: " << saldoAwal << "\n";
            break;

        case 4:
            cout << "Terima kasih telah menggunakan Aplikasi Keuangan Harian!\n";
            break;

        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 4);

    return 0;
}
