#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) { return Q.Head == -1; }
bool isFull(QueueEkspedisi Q)  { return Q.Tail == MAX - 1; }

void createQueue(QueueEkspedisi &Q) {
    Q.Head = Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket P) {
    if (isFull(Q)) return;

    if (isEmpty(Q)) Q.Head = Q.Tail = 0;
    else Q.Tail++;

    Q.data[Q.Tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) return;

    for (int i = 0; i < Q.Tail; i++)
        Q.data[i] = Q.data[i+1];

    Q.Tail--;
    if (Q.Tail == -1) Q.Head = -1;
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << i+1 << ". " << Q.data[i].KodeResi << " | "
             << Q.data[i].NamaPengirim << " | "
             << Q.data[i].BeratBarang << " kg | "
             << Q.data[i].Tujuan << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++)
        total += Q.data[i].BeratBarang * BIAYA_KG;
    return total;
}
#include "QueuePengiriman.h"

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    Paket P;

    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            cout << "Kode Resi      : "; getline(cin, P.KodeResi);
            cout << "Nama Pengirim  : "; getline(cin, P.NamaPengirim);
            cout << "Berat Barang   : "; cin >> P.BeratBarang; cin.ignore();
            cout << "Tujuan         : "; getline(cin, P.Tujuan);
            enQueue(Q, P);
            break;

        case 2:
            deQueue(Q);
            cout << "1 paket dihapus.\n";
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman: Rp "
                 << TotalBiayaPengiriman(Q) << endl;
            break;
        }
    } while (pilihan != 0);

    return 0;
}
