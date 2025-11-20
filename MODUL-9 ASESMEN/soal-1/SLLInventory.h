// #ifndef SLLINVENTORY_H
// #define SLLINVENTORY_H

// #include <iostream>
// using namespace std;

// //  STRUCT PRODUCT
// struct Product {
//     string Nama;
//     string SKU;
//     int Jumlah;
//     float HargaSatuan;
//     float DiskonPersen; 
// };

// typedef struct Node* address;

// //  STRUCT NODE
// struct Node {
//     Product info;
//     address next;
// };

// //  STRUCT LIST
// struct List {
//     address head;
// };

// //  DEKLARASI ADT
// bool isEmpty(List L);
// void createList(List &L);
// address allocate(Product P);
// void deallocate(address addr);

// void insertFirst(List &L, Product P);
// void insertLast(List &L, Product P);
// void insertAfter(List &L, address Q, Product P);

// void deleteFirst(List &L, Product &P);
// void deleteLast(List &L, Product &P);
// void deleteAfter(List &L, address Q, Product &P);

// void updateAtPosition(List &L, int posisi);
// void viewList(List L);
// void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

// // ==========================
// //   BAGIAN B (DITAMBAHKAN)
// // ==========================
// void MaxHargaAkhir(List L);   // mencari produk dengan HargaAkhir terbesar

// #endif
