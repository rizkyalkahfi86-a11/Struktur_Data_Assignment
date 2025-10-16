 <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">RIZKY AL KAHFI</p>

## Dasar Teori

Bahasa C++ adalah salah satu bahasa pemrograman tingkat tinggi yang sangat populer dan banyak digunakan di berbagai bidang. C++ juga adalah bahasa pemrograman berorientasi objek (Object-Oriented Programming / OOP) yang dikembangkan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai pengembangan dari bahasa C. Dalam modul ini kita belajar tentang array dan pointer. Adapun pengertian array dalam C++ adalah sekumpulan data dengan tipe yang sama yang disimpan berurutan dalam memori dan diakses melalui indeks. Array memudahkan penyimpanan serta pengolahan data dalam jumlah banyak, misalnya menampilkan, menjumlahkan, atau mencari nilai tertentu dengan bantuan perulangan.Dan pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, programmer dapat mengakses dan memanipulasi data secara langsung melalui alamat tersebut.

## Guided 

### 1. ARRAY

```C++
#include <iostream>
using namespace std;

int main() {
    //--- array 1 dimensi ---
    int arrID[5] = {10, 20, 30, 40, 50};
    cout << "array 1 dimensi;" <<endl;
    for (int i = 0; i < 5; i++) {
        cout << "arrID[" << i << "] = " << arrID[i] << endl; 
    }

    cout << endl;

    // --- array 2 dimensi (baris x kolom) ---
    int arr2D[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    cout << "array 2 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D [i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // --- array multi dimensi (3D) ---
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "array 3 dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j <<"][" << k << "] = " << arr3D[i][j][k] << endl;
            }
        }
    }
    return 0;
}
```
Kode di atas menunjukkan perulangan array yg dimana dimensi 1 itu merintah agar data tersimpan berurutan, dan dimensi 2 membuat baris dan kolom dan dimensi 3 menyimpan data dalam bentuk lebih kompleks seperti kumpulan beberapa tabel

### 2. FUNCTION PROCEDUR
```C++
#include <iostream>
using namespace std;

void tulis(int x) {
    for(int i = 0; i < x; i++) {
        cout << "baris ke -: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}
```
Program ini berfungsi untuk menampilkan sejumlah baris teks sesuai jumlah yang dimasukkan oleh pengguna.Fungsi utamanya adalah melatih penggunaan fungsi (function) dan perulangan for dalam C++.

### 3. POINTER
```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp= *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;
    
    cout << "value of a: " << a << endl;
    cout << "addres of a: " << &a << endl;
    cout << "value stored in ptr (addres of a) : " << ptr << endl;
    cout << "value pointed to by ptr : " << *ptr << endl;
    
    tukar (&a, &b);
    cout << "after swapping, value of a = " << a << " end b = " << b << endl;
    return 0;
}
```
Program ini bertujuan untuk memahami cara kerja pointer dan proses pertukaran nilai (swap) antar dua variabel menggunakan fungsi dan pointer di C++.
Melalui contoh ini, kamu bisa melihat bagaimana variabel, alamat memori, dan pointer saling berhubungan

### 4. REFERENCE
```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp= x;
    x = y;
    y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;
    
    cout << "nilai a: " << a << endl;
    cout << "alamat a (&a): " << &a << endl;
    cout << "nilai ref (alias a) : " << ref << endl;
    cout << "alamat ref (&ref) : " << &ref << endl;

    // mengubah nilai a lewat reference 

    ref = 50;
    cout << "\nsetelah ref = 50;" << endl;
    cout << "nilai a:" << a << endl;
    cout << "nilai ref:" << ref << endl;
    
    tukar (a, b);
    cout << "after swapping, value of a = " << a << " end b = " << b << endl;
    return 0;
}
```
Program ini bertujuan untuk menjelaskan konsep referensi (reference) dalam C++ serta cara menukar nilai dua variabel menggunakan fungsi dengan parameter referensi.
Berbeda dengan pointer, reference tidak menyimpan alamat memori, tetapi menjadi nama lain dari variabel yang dirujuk



## Unguided 

### 1. SOAL.1
<img width="1750" height="144" alt="image" src="https://github.com/user-attachments/assets/008e026c-eb5f-4ad4-9b50-633ba153f013" />

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];

    cout << "Buat Matrix A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Buat Matrix B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> B[i][j];
        }
    }

    cout << "\nHasil Penjumlahan:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] - B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="189" height="439" alt="image" src="https://github.com/user-attachments/assets/7e441dec-6695-4736-a04a-e1fddc6bf4bb" />



Program ini memperlihatkan cara melakukan operasi dasar pada matriks 3×3 di C++. menggunakan array dua dimensi untuk menyimpan data, Perulangan bersarang (for di dalam for) untuk mengakses elemen matriks, Menampilkan hasil penjumlahan, pengurangan, dan perkalian secara terpisah dengan tampilan rapi.


#### Full code Screenshot:
<img width="548" height="1000" alt="image" src="https://github.com/user-attachments/assets/b579a85f-a07d-4761-9820-138c5b354ecd" />



### 2. SOAL.2
<img width="1781" height="135" alt="image" src="https://github.com/user-attachments/assets/05cd34aa-56b1-4cf2-8a10-27aa90a1607c" />

```c++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 1, b = 2, c = 3;
    cout << "pointer" << "(nilai sebelum tukar): " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "pointer" << "(nilai setelah tukar): " << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl << endl;


    int a2 = 1, b2 = 2, c2 = 3;
    cout << "reference" << "(nilai sebelum tukar): " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    tukarReference(a2, b2, c2);

    cout << "reference" << "(nilai sesudah proses): " << endl;
    cout << "a2 = " << a2 << ", b2 = " << b2 << ", c2 = " << c2 << endl;

    return 0;
}

```

### OUTPUT
<img width="408" height="225" alt="image" src="https://github.com/user-attachments/assets/b58731bf-5f47-48f0-a340-a13c6c7a47f4" />


Program ini memperlihatkan dua konsep penting dalam C++:
-Pointer → Mengakses dan memodifikasi data melalui alamat memori (*x, &a).
-Reference → Mengakses dan memodifikasi data secara langsung dengan nama lain dari variabel yang sama (int &x).
keduanya dapat mengubah nilai asli dari variabel yang dikirim ke fungsi, tapi reference lebih sederhana digunakan, sedangkan pointer lebih fleksibel dalam menggunakan alamat memori.

### FULL CODE SCREENSHOT
<img width="667" height="1012" alt="image" src="https://github.com/user-attachments/assets/c69d0448-2dde-4e9f-87ec-59e9bc8eaa46" />


### 3. SOAL.3
<img width="1814" height="825" alt="image" src="https://github.com/user-attachments/assets/f17fa8a6-c1fc-4408-b9a4-9bf7d9890732" />

```C++
#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void hitungRataRata(int arr[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    cout << "Nilai rata-rata = " << total / n << endl;
}

int main() {
    int arrA[] = {13, 10, 7, 9, 14, 28, 5, 56, 35, 57};
    int n = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;

    do {
        cout << "\n === menu program array ===" << endl;
        cout << "1. tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. hitung nilai rata-rata" << endl;
        cout << "5. keluar" << endl;
        cout << "pilih menu (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Terima kasih telah menggunakan! Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid, monggoh coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}

```

### OUTPUT
<img width="467" height="927" alt="image" src="https://github.com/user-attachments/assets/d0124165-d813-4e3a-89c8-95f1ca398e14" />



Program ini berfungsi untuk mengolah data pada array satu dimensi — tepatnya untuk:
1.Menampilkan isi array
2.Mencari nilai maksimum
3.Mencari nilai minimum
4.Menghitung nilai rata-rata
Program menggunakan fungsi (function) untuk operasi pencarian nilai dan perhitungan, serta struktur switch–case agar pengguna bisa memilih menu yang diinginkan.
Program diatas juga memperlihatkan cara menggunakan fungsi dan prosedur untuk mengolah data array satu dimensi.
Dengan menggunakan switch–case, program menjadi interaktif dan fleksibel, serta user dapat memilih apakah ingin melihat isi array, mencari nilai tertinggi, terendah, atau rata-ratanya.

### FULL CODE SCREENSHOT
<img width="1083" height="1058" alt="image" src="https://github.com/user-attachments/assets/6092bedf-a9f3-488a-942d-9552f220aec0" />




## Kesimpulan
ringkasan dari modul ini menunjukkan penerapan array satu dimensi dan penggunaan fungsi serta prosedur dalam bahasa C++. Melalui fungsi cariMaksimum() dan cariMinimum(), program dapat menemukan nilai tertinggi dan terendah dalam array, sedangkan prosedur hitungRataRata() digunakan untuk menghitung rata-rata dari seluruh elemen array. Struktur switch–case dimanfaatkan untuk membuat menu yang memudahkan user memilih operasi yang diinginkan, seperti menampilkan isi array, mencari nilai maksimum, minimum, atau menghitung rata-rata. Secara keseluruhan, program ini melatih pemahaman tentang cara mengolah data array menggunakan fungsi, perulangan, dan percabangan, serta memperkuat konsep dasar dalam bahasa C++.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
