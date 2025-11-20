// #include "SLLInventory.h"

// // ========================
// // Bagian A
// // ========================

// // CEK LIST KOSONG
// bool isEmpty(List L) {
//     return (L.head == NULL);
// }

// // MEMBUAT LIST KOSONG
// void createList(List &L) {
//     L.head = NULL;
// }

// // ALOKASI NODE
// address allocate(Product P) {
//     address newNode = new Node;
//     newNode->info = P;
//     newNode->next = NULL;
//     return newNode;
// }

// // DEALOKASI
// void deallocate(address addr) {
//     delete addr;
// }

// // INSERT FIRST
// void insertFirst(List &L, Product P) {
//     address newNode = allocate(P);
//     newNode->next = L.head;
//     L.head = newNode;
// }

// // INSERT LAST
// void insertLast(List &L, Product P) {
//     address newNode = allocate(P);

//     if (isEmpty(L)) {
//         L.head = newNode;
//     } else {
//         address temp = L.head;
//         while (temp->next != NULL) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// // INSERT AFTER
// void insertAfter(List &L, address Q, Product P) {
//     if (Q != NULL) {
//         address newNode = allocate(P);
//         newNode->next = Q->next;
//         Q->next = newNode;
//     }
// }

// // DELETE FIRST
// void deleteFirst(List &L, Product &P) {
//     if (!isEmpty(L)) {
//         address temp = L.head;
//         P = temp->info;
//         L.head = temp->next;
//         deallocate(temp);
//     }
// }

// // DELETE LAST
// void deleteLast(List &L, Product &P) {
//     if (!isEmpty(L)) {
//         address temp = L.head;

//         if (temp->next == NULL) {
//             P = temp->info;
//             L.head = NULL;
//             deallocate(temp);
//         } else {
//             address prev = NULL;
//             while (temp->next != NULL) {
//                 prev = temp;
//                 temp = temp->next;
//             }
//             P = temp->info;
//             prev->next = NULL;
//             deallocate(temp);
//         }
//     }
// }

// // DELETE AFTER
// void deleteAfter(List &L, address Q, Product &P) {
//     if (Q != NULL && Q->next != NULL) {
//         address temp = Q->next;
//         P = temp->info;
//         Q->next = temp->next;
//         deallocate(temp);
//     }
// }

// // UPDATE AT POSITION
// void updateAtPosition(List &L, int posisi) {
//     address temp = L.head;
//     int counter = 1;

//     while (temp != NULL && counter < posisi) {
//         temp = temp->next;
//         counter++;
//     }

//     if (temp != NULL) {
//         Product baru;

//         cout << "Masukkan Nama Baru: ";
//         cin >> baru.Nama;

//         cout << "Masukkan SKU Baru: ";
//         cin >> baru.SKU;

//         cout << "Masukkan Jumlah Baru: ";
//         cin >> baru.Jumlah;

//         cout << "Masukkan Harga Satuan Baru: ";
//         cin >> baru.HargaSatuan;

//         cout << "Masukkan Diskon (%) Baru: ";
//         cin >> baru.DiskonPersen;

//         temp->info = baru;
//         cout << "Data pada posisi " << posisi << " berhasil diupdate.\n";
//     } else {
//         cout << "Posisi tidak ditemukan.\n";
//     }
// }

// // VIEW LIST
// void viewList(List L) {
//     if (isEmpty(L)) {
//         cout << "List kosong.\n";
//         return;
//     }

//     address temp = L.head;
//     int posisi = 1;

//     while (temp != NULL) {
//         float hargaAkhir =
//             temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

//         cout << posisi << ". "
//              << "Nama: " << temp->info.Nama << " | "
//              << "SKU: " << temp->info.SKU << " | "
//              << "Jumlah: " << temp->info.Jumlah << " | "
//              << "Harga Satuan: " << temp->info.HargaSatuan << " | "
//              << "Diskon: " << temp->info.DiskonPersen << "% | "
//              << "Harga Akhir: " << hargaAkhir << endl;

//         posisi++;
//         temp = temp->next;
//     }
// }

// // SEARCH BY FINAL PRICE RANGE
// void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
//     address temp = L.head;
//     int posisi = 1;
//     bool found = false;

//     while (temp != NULL) {
//         float hargaAkhir =
//             temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

//         if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
//             cout << posisi << ". "
//                  << temp->info.Nama << " | Harga Akhir: " << hargaAkhir << endl;
//             found = true;
//         }

//         posisi++;
//         temp = temp->next;
//     }

//     if (!found)
//         cout << "Tidak ada produk dalam rentang harga tersebut.\n";
// }

// // =======================================
// // Bagian B: MAX HARGA AKHIR
// // =======================================
// void MaxHargaAkhir(List L) {
//     if (isEmpty(L)) {
//         cout << "List kosong.\n";
//         return;
//     }

//     address temp = L.head;
//     float maxHarga = -999999;

//     // 1. Cari harga akhir max
//     while (temp != NULL) {
//         float hargaAkhir =
//             temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

//         if (hargaAkhir > maxHarga)
//             maxHarga = hargaAkhir;

//         temp = temp->next;
//     }

//     // 2. Tampilkan semua yang sesuai nilai max
//     cout << "\n=== Produk dengan HargaAkhir TERTINGGI ===\n";
//     cout << "Harga maksimum: " << maxHarga << endl;

//     temp = L.head;
//     int posisi = 1;

//     while (temp != NULL) {
//         float hargaAkhir =
//             temp->info.HargaSatuan * (1 - temp->info.DiskonPersen / 100);

//         if (hargaAkhir == maxHarga) {
//             cout << posisi << ". "
//                  << temp->info.Nama << " | HargaAkhir: " << hargaAkhir << endl;
//         }

//         posisi++;
//         temp = temp->next;
//     }
// }

// #include "SLLInventory.h"

// int main() {

//     List L;
//     createList(L);

//     Product P;

//     // INSERT DATA
//     P = {"Pulpen", "A001", 20, 2500, 0};
//     insertLast(L, P);

//     P = {"BukuTulis", "A002", 15, 5000, 10};
//     insertLast(L, P);

//     P = {"Penghapus", "A003", 30, 1500, 0};
//     insertLast(L, P);

//     cout << "\n=== LIST AWAL ===\n";
//     viewList(L);

//     // DELETE FIRST
//     Product removed;
//     deleteFirst(L, removed);

//     cout << "\n=== LIST SETELAH deleteFirst ===\n";
//     viewList(L);

//     // UPDATE POSISI 2
//     cout << "\n=== UPDATE POSISI 2 ===\n";
//     updateAtPosition(L, 2);

//     cout << "\n=== LIST SETELAH UPDATE ===\n";
//     viewList(L);

//     // SEARCH RANGE
//     cout << "\n=== SEARCH Produk HargaAkhir 2000–7000 ===\n";
//     searchByFinalPriceRange(L, 2000, 7000);

//     // BAGIAN B
//     cout << "\n=== PRODUK DENGAN HARGA AKHIR TERTINGGI ===\n";
//     MaxHargaAkhir(L);   // panggil fungsi Bagian B

//     return 0;
// }

