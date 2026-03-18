#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Produk {
    char nama[50];
    float harga;
    char kategori[30];
    int stok;
};

Produk data[100];
int n = 0;

// load filenya
void loadFile() {
    FILE *file = fopen("lelele.csv", "r");
    if (!file) return;

    n = 0;
    while (fscanf(file, " %[^,],%f,%[^,],%d\n",
        data[n].nama,
        &data[n].harga,
        data[n].kategori,
        &data[n].stok) != EOF) {
        n++;
    }

    fclose(file);
}

// simpen filenya
void saveFile() {
    FILE *file = fopen("lelele.csv", "w");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%.1f,%s,%d\n",
            data[i].nama,
            data[i].harga,
            data[i].kategori,
            data[i].stok);
    }

    fclose(file);
}

// tambah produk 
void tambahProduk() {
    cin.ignore();

    cout << "Nama: ";
    cin.getline(data[n].nama, 50);

    cout << "Harga: ";
    cin >> data[n].harga;

    do {
        cout << "Kategori (makanan/minuman): ";
        cin >> data[n].kategori;
    } while (strcmp(data[n].kategori, "makanan") != 0 &&
             strcmp(data[n].kategori, "minuman") != 0);

    cout << "Stok: ";
    cin >> data[n].stok;

    n++;
    saveFile();

    cout << "Produk berhasil ditambahkan!\n";
}

// menampilkan produk
void tampil() {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA PRODUK ===\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". "
             << data[i].nama << " | "
             << data[i].harga << " | "
             << data[i].kategori << " | "
             << data[i].stok << endl;
    }
}

// bubble sort
void bubbleSort() {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (strcmp(data[j].nama, data[j+1].nama) > 0) {
                swap(data[j], data[j+1]);
            }
        }
    }
    cout << "Data berhasil diurutkan (Nama ASC)\n";
}

// quick sort
void quickSort(int low, int high) {
    int i = low, j = high;
    float pivot = data[(low + high)/2].harga;

    while (i <= j) {
        while (data[i].harga > pivot) i++;
        while (data[j].harga < pivot) j--;

        if (i <= j) {
            swap(data[i], data[j]);
            i++; j--;
        }
    }

    if (low < j) quickSort(low, j);
    if (i < high) quickSort(i, high);
}

// sequental search
void sequentialSearch(char cari[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(data[i].nama, cari) == 0) {
            cout << "Produk ditemukan:\n";
            cout << data[i].nama << " | "
                 << data[i].harga << " | "
                 << data[i].kategori << " | "
                 << data[i].stok << endl;
            return;
        }
    }
    cout << "Produk tidak ditemukan!\n";
}

// binnary search
void binarySearch(char cari[]) {
    int l = 0, r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cmp = strcmp(data[mid].nama, cari);

        if (cmp == 0) {
            cout << "Produk ditemukan:\n";
            cout << data[mid].nama << " | "
                 << data[mid].harga << " | "
                 << data[mid].kategori << " | "
                 << data[mid].stok << endl;
            return;
        }
        else if (cmp < 0) l = mid + 1;
        else r = mid - 1;
    }

    cout << "Produk tidak ditemukan!\n";
}

// menuuu
int main() {
    int pilih, sub;
    char cari[50];

    loadFile();

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Produk\n";
        cout << "2. Urutkan Produk\n";
        cout << "3. Cari Produk\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambahProduk();
                break;

            case 2:
                cout << "\n-- Urutkan Produk --\n";
                cout << "1. Berdasarkan Nama (Bubble Sort)\n";
                cout << "2. Berdasarkan Harga (Quick Sort)\n";
                cout << "Pilih: ";
                cin >> sub;

                if (sub == 1) {
                    bubbleSort();
                    tampil();
                } else if (sub == 2) {
                    quickSort(0, n-1);
                    cout << "Data berhasil diurutkan (Harga DESC)\n";
                    tampil();
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
                break;

            case 3:
                cout << "\n-- Cari Produk --\n";
                cout << "1. Sequential Search\n";
                cout << "2. Binary Search\n";
                cout << "Pilih: ";
                cin >> sub;

                cin.ignore();
                cout << "Masukkan nama produk: ";
                cin.getline(cari, 50);

                if (sub == 1) {
                    sequentialSearch(cari);
                } else if (sub == 2) {
                    bubbleSort(); 
                    binarySearch(cari);
                } else {
                    cout << "Pilihan tidak valid!\n";
                }
                break;

            case 4:
                tampil();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 5);

    return 0;
}
