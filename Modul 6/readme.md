# <h1 align="center">Laporan Praktikum Modul 6 Double Linked List (Bagian 1) </h1>
<p align="center">Rizky Al Kahfi</p>

## Dasar Teori
Double Linked List

Doubly Linked list adalah linked list yang masing – masing elemen nya memiliki 2 successor, yaitu
successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen
sesudahnya (next).

Doubly linked list juga menggunakan dua buah successor utama yang terdapat pada list, yaitu first
(successor yang menunjuk elemen pertama) dan last (susesor yang menunjuk elemen terakhir list).
Komponen-komponen dalam Doubly linked list:
1. First : pointer pada list yang menunjuk pada elemen pertama list.
2. Last : pointer pada list yang menunjuk pada elemen terakhir list.
3. Next : pointer pada elemen sebagai successor yang menunjuk pada elemen didepannya.
4. Prev : pointer pada elemen sebagai successor yang menunjuk pada elemen dibelakangnya.


## Guided 

### 1. [DLLPlayList.h]

```C++
#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;    
};

typedef struct Node* address;

struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address Q, Song S);
void insertBefore(List &L, address Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address Q);

void viewList(List L);
void searchByPopularityRange(List L, float minScore, float maxScore);

float getPopularityScore(Song S);

#endif
```
Program ini merupakan implementasi Doubly Linked List yang digunakan untuk mengelola data playlist lagu, di mana setiap node menyimpan informasi lagu dan terhubung dua arah. Program menyediakan fungsi untuk menambah, menghapus, memperbarui, menampilkan, serta mencari lagu berdasarkan nilai popularitas.

### 2. [DLLPlayList.cpp]

```C++
#include "DLLPlaylist.h"

bool isEmpty(List L) {
    return L.head == nullptr;
}

void createList(List &L) {
    L.head = nullptr;
    L.tail = nullptr;
}

address allocate(Song S) {
    address P = new Node;
    P->info = S;
    P->prev = nullptr;
    P->next = nullptr;
    return P;
}

void deallocate(address P) {
    delete P;
}

float getPopularityScore(Song S) {
    return 0.8 * S.PlayCount + 20.0 * S.Rating;
}

void insertFirst(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, Song S) {
    if (Q != nullptr) {
        address P = allocate(S);
        P->next = Q->next;
        P->prev = Q;

        if (Q->next != nullptr)
            Q->next->prev = P;
        else
            L.tail = P;

        Q->next = P;
    }
}

void insertBefore(List &L, address Q, Song S) {
    if (Q != nullptr) {
        if (Q == L.head) {
            insertFirst(L, S);
        } else {
            address P = allocate(S);
            P->next = Q;
            P->prev = Q->prev;

            Q->prev->next = P;
            Q->prev = P;
        }
    }
}

void deleteFirst(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.head;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.head = P->next;
            L.head->prev = nullptr;
        }
        deallocate(P);
    }
}

void deleteLast(List &L, Song &S) {
    if (!isEmpty(L)) {
        address P = L.tail;
        S = P->info;

        if (L.head == L.tail) {
            L.head = L.tail = nullptr;
        } else {
            L.tail = P->prev;
            L.tail->next = nullptr;
        }
        deallocate(P);
    }
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->next != nullptr) {
        address P = Q->next;
        S = P->info;

        Q->next = P->next;
        if (P->next != nullptr)
            P->next->prev = Q;
        else
            L.tail = Q;

        deallocate(P);
    }
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;
        S = P->info;

        if (P == L.head) {
            deleteFirst(L, S);
        } else {
            P->prev->next = Q;
            Q->prev = P->prev;
            deallocate(P);
        }
    }
}

void updateAtPosition(List &L, int posisi) {
    int idx = 1;
    address P = L.head;

    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != nullptr) {
        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void updateBefore(List &L, address Q) {
    if (Q != nullptr && Q->prev != nullptr) {
        address P = Q->prev;

        cout << "Masukkan Title baru: ";
        cin >> P->info.Title;
        cout << "Masukkan Artist baru: ";
        cin >> P->info.Artist;
        cout << "Masukkan Duration baru: ";
        cin >> P->info.DurationSec;
        cout << "Masukkan PlayCount baru: ";
        cin >> P->info.PlayCount;
        cout << "Masukkan Rating baru: ";
        cin >> P->info.Rating;
    }
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int idx = 1;

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        cout << idx << ". "
             << P->info.Title << " | " << P->info.Artist
             << " | " << P->info.DurationSec << "s | PC: "
             << P->info.PlayCount << " | Rating: "
             << P->info.Rating << " | PopularityScore: "
             << pop << endl;

        P = P->next;
        idx++;
    }
}

void searchByPopularityRange(List L, float minScore, float maxScore) {
    address P = L.head;
    int idx = 1;

    cout << "\nHasil searching PopularityScore in [" 
         << minScore << ", " << maxScore << "]\n";

    while (P != nullptr) {
        float pop = getPopularityScore(P->info);

        if (pop >= minScore && pop <= maxScore) {
            cout << idx << ". " << P->info.Title 
                 << " | PopularityScore: " << pop << endl;
        }

        P = P->next;
        idx++;
    }
}
```
Program ini merupakan implementasi lengkap Doubly Linked List untuk pengelolaan playlist lagu, yang mencakup proses alokasi dan dealokasi node, operasi penyisipan dan penghapusan di berbagai posisi, pembaruan data lagu, perhitungan skor popularitas, penelusuran data berdasarkan rentang skor, serta penampilan seluruh isi playlist secara terurut. Program ini mengatur setiap lagu sebagai node yang terhubung dua arah sehingga memudahkan manipulasi data playlist secara fleksibel.

### 3. [main.cpp]

```C++
#include "DLLPlaylist.h"

address getNodeAt(List L, int posisi) {
    int idx = 1;
    address P = L.head;
    while (P != nullptr && idx < posisi) {
        P = P->next;
        idx++;
    }
    return P;
}

int main() {
    List L;
    createList(L);

    insertLast(L, {"Senja di Kota", "Nona Band", 210, 150, 4.2});
    insertLast(L, {"Langkahmu", "Delta", 185, 320, 4.8});
    insertLast(L, {"Hujan Minggu", "Arka", 240, 90, 3.95});

    cout << "\n=== List Awal ===\n";
    viewList(L);

    Song removed;
    deleteLast(L, removed);

    cout << "\n Setelah deleteLast \n";
    viewList(L);

    cout << "\n Update posisi ke-2 \n";
    updateAtPosition(L, 2);

    cout << "\n Setelah Update \n";
    viewList(L);

    address pos2 = getNodeAt(L, 2);

    insertBefore(L, pos2, {"Senandung", "Mira", 175, 120, 4.0});
    cout << "\n Setelah insertBefore posisi 2 \n";
    viewList(L);

    cout << "\n UpdateBefore posisi 2 \n";
    pos2 = getNodeAt(L, 2);
    updateBefore(L, pos2);

    cout << "\n Setelah updateBefore \n";
    viewList(L);

    cout << "\n deleteBefore posisi 3 \n";
    Song removed2;
    address pos3 = getNodeAt(L, 3);
    deleteBefore(L, pos3, removed2);

    cout << "\n Setelah deleteBefore \n";
    viewList(L);

    cout << "\n Searching PopularityScore 150–300 \n";
    searchByPopularityRange(L, 150.0, 300.0);

    return 0;
}
```
Program ini digunakan untuk mengatur data playlist lagu, seperti menambah, menghapus, menyisipkan, dan memperbarui lagu pada posisi tertentu.
Seluruh pengelolaan playlist dilakukan menggunakan struktur data Doubly Linked List, sehingga setiap lagu dapat diakses, dipindahkan, atau dimodifikasi melalui node yang saling terhubung dua arah.

## Unguided 
### 1. [doublelist.h]

```C++
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#define NIL NULL
#include <iostream>
using namespace std;

struct film {
    string kodeFilm;
    string judul;
    int tahunRilis;
};

typedef film infotype;
typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, string kodeFilm);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prec);

#endif

```
### 2. [doublelist.cpp]
```C++
#include "doublelist.h"

void CreateList(List &L) {
    L.first = NIL;
    L.last = NIL;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = NIL;
    P->prev = NIL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NIL;
}

void insertLast(List &L, address P) {
    if (L.first == NIL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NIL) {
        cout << "Kode Film   : " << P->info.kodeFilm << endl;
        cout << "Judul Film  : " << P->info.judul << endl;
        cout << "Tahun Rilis : " << P->info.tahunRilis << endl;
        cout << endl;
        P = P->next;
    }
}

address findElm(List L, string kodeFilm) {
    address P = L.first;
    while (P != NIL) {
        if (P->info.kodeFilm == kodeFilm)
            return P;
        P = P->next;
    }
    return NIL;
}

void deleteFirst(List &L) {
    if (L.first != NIL) {
        address P = L.first;
        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.first = P->next;
            L.first->prev = NIL;
        }
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first != NIL) {
        address P = L.last;
        if (L.first == L.last) {
            L.first = L.last = NIL;
        } else {
            L.last = P->prev;
            L.last->next = NIL;
        }
        dealokasi(P);
    }
}

void deleteAfter(List &L, address Prec) {
    if (Prec != NIL && Prec->next != NIL) {
        address P = Prec->next;
        Prec->next = P->next;
        if (P->next != NIL) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        dealokasi(P);
    }
}

```
### 3. [main.cpp]

```C++
#include "doublelist.h"

int main() {
    List L;
    CreateList(L);

    infotype x;
    address P;
    string kodeCari;

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan kode film: ";
        cin >> x.kodeFilm;

        if (findElm(L, x.kodeFilm) != NIL) {
            cout << "Kode film sudah terdaftar\n\n";
            continue;
        }

        cout << "Masukkan judul film: ";
        cin >> x.judul;

        cout << "Masukkan tahun rilis: ";
        cin >> x.tahunRilis;
        cout << endl;

        P = alokasi(x);
        insertLast(L, P);
    }

    cout << "DATA FILM BIOSKOP\n";
    printInfo(L);

    cout << "Masukkan kode film yang dicari: ";
    cin >> kodeCari;

    address found = findElm(L, kodeCari);
    if (found != NIL) {
        cout << "Film ditemukan:\n";
        cout << "Judul : " << found->info.judul << endl;
        cout << "Tahun : " << found->info.tahunRilis << endl;
    } else {
        cout << "Film tidak ditemukan.\n";
    }

    cout << "\nMasukkan kode film yang akan dihapus: ";
    cin >> kodeCari;

    address target = findElm(L, kodeCari);
    if (target != NIL) {
        if (target == L.first)
            deleteFirst(L);
        else if (target == L.last)
            deleteLast(L);
        else
            deleteAfter(L, target->prev);

        cout << "Data film berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    cout << "\nDATA FILM SETELAH PENGHAPUSAN\n";
    printInfo(L);

    return 0;
}

#### Output:

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/9c2d0951-4254-4b85-b6c9-c32be278f817" />

Program ini dibuat untuk mengelola data film bioskop menggunakan struktur data Doubly Linked List. Setiap node menyimpan informasi berupa kode film, judul, dan tahun rilis. Program mampu menambahkan data ke akhir list, menampilkan seluruh data, mencari film berdasarkan kode, serta menghapus data dari awal, akhir, maupun tengah list. Selain itu, program juga mencegah terjadinya duplikasi data berdasarkan kode film. Secara keseluruhan, program ini membantu memahami penggunaan pointer, manajemen memori dinamis, serta cara kerja Doubly Linked List dalam pengolahan data secara dinamis.

## Full Code ScreenShot
<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/adfaeebe-0753-4697-8450-e2bf65a5035b" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/8b08bb9e-59fc-4591-b1c9-a67f58790587" />
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/5c38e52e-1164-4d83-a944-04c97f6b61d4" />

## Kesimpulan
Ringkasan dan interpretasi pandangan penulis dari hasil praktikum dan pembelajaran yang didapat.
Pada modul ini dapat disimpulkan bahwa struktur data Doubly Linked List sangat efektif digunakan untuk mengelola data secara dinamis karena setiap node memiliki dua pointer, yaitu menunjuk ke node berikutnya dan node sebelumnya. Hal ini memudahkan proses penelusuran, pencarian, penambahan, serta penghapusan data tanpa perlu memindahkan seluruh elemen dalam list. Dibandingkan dengan Single Linked List, Doubly Linked List memberikan fleksibilitas yang lebih besar, terutama dalam operasi penyisipan dan penghapusan data di bagian tengah list.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.

Keluaran:
tangkapan layar

Tangkapan Layar Kode Lengkap:
tangkapan layar





