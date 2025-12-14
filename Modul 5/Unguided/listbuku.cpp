#include "listbuku.h"

void createList(List &L) {
    L.first = Nil;
}

bool isEmpty(List L) {
    return (L.first == Nil);
}

address alokasi(string judul, string penulis, int harga) {
    address P = new Node;
    P->info.judul = judul;
    P->info.penulis = penulis;
    P->info.harga = harga;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != Nil) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "List buku kosong." << endl;
    } else {
        address P = L.first;
        while (P != Nil) {
            cout << "Judul Buku : " << P->info.judul << endl;
            cout << "Penulis    : " << P->info.penulis << endl;
            cout << "Harga      : " << P->info.harga << endl;
            cout << "---------------------------" << endl;
            P = P->next;
        }
    }
}

address findBuku(List L, string judul) {
    address P = L.first;
    while (P != Nil && P->info.judul != judul) {
        P = P->next;
    }
    return P;
}

void updateBuku(List &L, string judulCari, string penulisBaru, int hargaBaru) {
    address P = findBuku(L, judulCari);
    if (P != Nil) {
        P->info.penulis = penulisBaru;
        P->info.harga = hargaBaru;
        cout << "Data buku \"" << judulCari << "\" berhasil diperbarui!" << endl;
    } else {
        cout << "Buku \"" << judulCari << "\" tidak ditemukan dalam list." << endl;
    }
}

int totalHarga(List L) {
    address P = L.first;
    int total = 0;
    while (P != Nil) {
        total += P->info.harga;
        P = P->next;
    }
    return total;
}
