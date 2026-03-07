#include <iostream>
#include <string>
using namespace std;

// Bubble Sort ascending
void bubbleSort(string arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j] > arr[j+1]){ 
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Quick Sort descending
void quickSort(string arr[], int low, int high){
    int i = low;
    int j = high;
    string pivot = arr[(low+high)/2]; // ambil pivot tengah

    while(i <= j){
        while(arr[i] > pivot) i++; 
        while(arr[j] < pivot) j--; 

        if(i <= j){
            string temp = arr[i]; 
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if(low < j) quickSort(arr, low, j); 
    if(i < high) quickSort(arr, i, high); 
}

int main(){

    int n;
    cout<<"Jumlah mahasiswa: ";
    cin>>n;

    string nama[n];

    for(int i=0;i<n;i++){
        cout<<"Nama ke-"<<i+1<<": ";
        cin>>nama[i];
    }

    string asc[n], desc[n];

    for(int i=0;i<n;i++){
        asc[i] = nama[i];
        desc[i] = nama[i];
    }

    bubbleSort(asc,n); // ascending
    quickSort(desc,0,n-1); // descending

    cout<<"\nAscending (Bubble Sort):\n";
    for(int i=0;i<n;i++)
        cout<<asc[i]<<endl;

    cout<<"\nDescending (Quick Sort):\n";
    for(int i=0;i<n;i++)
        cout<<desc[i]<<endl;

}