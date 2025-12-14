#ifndef LISTBUKU_H
#define LISTBUKU_H
#define Nil NULL

#include <iostream>
using namespace std;

// Struktur data buku
struct buku {
    string judul;
    string penulis;
    int harga;
};

typedef buku infotype;
typedef struct Node *address;

// Node Linked List
struct Node {
    infotype info;
    address next;
};

// Struktur List
struct List {
    address first;
};

// Deklarasi fungsi
void createList(List &L);
bool isEmpty(List L);
address alokasi(string judul, string penulis, int harga);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);
address findBuku(List L, string judul);
void updateBuku(List &L, string judulCari, string penulisBaru, int hargaBaru);
int totalHarga(List L);

#endif
