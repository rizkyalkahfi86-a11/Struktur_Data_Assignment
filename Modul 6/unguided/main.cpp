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
