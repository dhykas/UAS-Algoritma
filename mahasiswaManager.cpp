#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float nilaiAkhir;
};

void tambahData(vector<Mahasiswa>& data) {
    Mahasiswa m;
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, m.nama);
    cout << "Masukkan Nilai Akhir: ";
    cin >> m.nilaiAkhir;
    data.push_back(m);
    cout << "Data berhasil ditambahkan!\n";
}

void tampilkanData(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }
    cout << left << setw(15) << "NIM" << setw(25) << "Nama" << setw(10) << "Nilai Akhir" << endl;
    for (const auto& m : data) {
        cout << left << setw(15) << m.nim << setw(25) << m.nama << setw(10) << m.nilaiAkhir << endl;
    }
}

void cariData(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "Data kosong.\n";
        return;
    }
    string nim;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nim;
    for (const auto& m : data) {
        if (m.nim == nim) {
            cout << "Data ditemukan:\n";
            cout << "NIM: " << m.nim << ", Nama: " << m.nama << ", Nilai Akhir: " << m.nilaiAkhir << endl;
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void urutkanData(vector<Mahasiswa>& data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j].nilaiAkhir < data[j + 1].nilaiAkhir) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan Nilai Akhir (descending).\n";
}

int main() {
    vector<Mahasiswa> data;
    int pilihan;

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Mahasiswa\n";
        cout << "4. Urutkan Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(data);
                break;
            case 2:
                tampilkanData(data);
                break;
            case 3:
                cariData(data);
                break;
            case 4:
                urutkanData(data);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
