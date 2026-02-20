#include <iostream> 
using namespace std; 

int main() {

    int arr[] = {3, 7, 2, 9, 5}; // ini array isi bebas
    int n = 5; // jumlah data di array

    int *ptr = arr; // pointer diarahkan ke awal array

    int max = *ptr; // anggap sementara nilai pertama itu paling besar
    int min = *ptr; // anggap sementara nilai pertama itu paling kecil
    int jumlah = 0; // buat nampung total penjumlahan

    cout << "Isi array: "; // judul output

    // looping buat baca semua isi array pake pointer
    for (int i = 0; i < n; i++) {

        cout << *(ptr + i) << " "; // nampilin nilai array pake pointer

        jumlah += *(ptr + i); // nambahin ke total

        if (*(ptr + i) > max) // cek kalo ada yang lebih gede
            max = *(ptr + i);

        if (*(ptr + i) < min) // cek kalo ada yang lebih kecil
            min = *(ptr + i);
    }

    float rata = (float)jumlah / n; // hitung rata-rata

    cout << endl;
    cout << "Max = " << max << endl; // tampil nilai terbesar
    cout << "Min = " << min << endl; // tampil nilai terkecil
    cout << "Jumlah = " << jumlah << endl; // tampil total
    cout << "Rata-rata = " << rata << endl; // tampil rata-rata


}