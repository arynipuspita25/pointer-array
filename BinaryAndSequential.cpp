#include <iostream>
using namespace std;

struct Buku {
    string nama;
    int harga;
};
Buku dataBuku[5] = {
    {"Let Them Theory", 50000},
    {"Laut Bercerita", 60000},
    {"How to Win friends and Influence People", 70000},
    {"Master Coding", 80000},
    {"Fact Fullness", 90000}
};

int n = 5;
// menampilkan data buku
void tampilkanBuku() {
    cout << "\nDAFTAR BUKU:\n";
    for (int i = 0; i < n; i++) {
        cout << "- " << dataBuku[i].nama << endl;
    }
    cout << endl;
}

// sequental tanpa sentinel
void seqTanpaSentinel(string cari) {
    bool ketemu = false;

    for (int i = 0; i < n; i++) {
        if (dataBuku[i].nama == cari) {
            cout << "Buku ditemukan!\nHarga: " << dataBuku[i].harga << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu)
        cout << "Buku tidak ditemukan\n";
}

// sequential dengan sentinel
void seqDenganSentinel(string cari) {
    Buku temp[6];
    for (int i = 0; i < n; i++)
        temp[i] = dataBuku[i];
    temp[n].nama = cari;
    int i = 0;
    while (temp[i].nama != cari)
        i++;
    if (i < n)
        cout << "Buku ditemukan!\nHarga: " << temp[i].harga << endl;
    else
        cout << "Buku tidak ditemukan\n";
}
// binary search
void binarySearch(string cari) {
    int kiri = 0, kanan = n - 1;
    bool ketemu = false;

    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;

        if (dataBuku[tengah].nama == cari) {
            cout << "Buku ditemukan!\nHarga: " << dataBuku[tengah].harga << endl;
            ketemu = true;
            break;
        }
        else if (cari < dataBuku[tengah].nama)
            kanan = tengah - 1;
        else
            kiri = tengah + 1;
    }
    if (!ketemu)
        cout << "Buku tidak ditemukan\n";
}
// menu
int main() {
    int pilih, sub;
    string cari;
    
    tampilkanBuku();
    
    cout << "MENU PENCARIAN BUKU\n";
    cout << "1. Sequential Search\n";
    cout << "2. Binary Search\n";
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 1) {
        cout << "1. Dengan Sentinel\n";
        cout << "2. Tanpa Sentinel\n";
        cout << "Pilih: ";
        cin >> sub;

        cout << "Masukkan nama buku: ";
        cin >> cari;

        if (sub == 1)
            seqDenganSentinel(cari);
        else
            seqTanpaSentinel(cari);
    }
    else if (pilih == 2) {
        cout << "Masukkan nama buku: ";
        cin >> cari;
        binarySearch(cari);
    }
    else {
        cout << "Pilihan tidak valid\n";
    }
}
