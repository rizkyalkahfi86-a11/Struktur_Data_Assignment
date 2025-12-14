#include "listbuku.h"

int main() {
    List L;
    createList(L);

    insertLast(L, alokasi("Laskar Pelangi", "Andrea Hirata", 85000));
    insertLast(L, alokasi("Negeri 5 Menara", "Ahmad Fuadi", 78000));
    insertLast(L, alokasi("Bumi", "Tere Liye", 90000));
    insertLast(L, alokasi("Dilan 1990", "Pidi Baiq", 75000));

    cout << "=== Data Buku Perpustakaan ===" << endl;
    printInfo(L);

    cout << "\nCari buku 'Bumi':" << endl;
    address cari = findBuku(L, "Bumi");
    if (cari != Nil)
        cout << "Buku ditemukan! Penulis: "
             << cari->info.penulis
             << ", Harga: Rp " << cari->info.harga << endl;
    else
        cout << "Buku tidak ditemukan." << endl;

    cout << "\nUpdate buku 'Laskar Pelangi'" << endl;
    updateBuku(L, "Laskar Pelangi", "Andrea Hirata", 90000);

    cout << "\n=== Data Setelah Update ===" << endl;
    printInfo(L);

    int total = totalHarga(L);
    cout << "\nTotal harga semua buku: Rp " << total << endl;

    return 0;
}
