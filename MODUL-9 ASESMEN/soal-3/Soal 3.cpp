#include "StackMahasiswa.h"

bool isEmpty(StackMahasiswa S) { return S.Top == -1; }
bool isFull(StackMahasiswa S)  { return S.Top == MAX - 1; }
void createStack(StackMahasiswa &S) { S.Top = -1; }

float NilaiAkhir(Mahasiswa M) {
    return 0.2*M.Tugas + 0.4*M.UTS + 0.4*M.UAS;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (isFull(S)) return;
    S.data[++S.Top] = M;
}

void Pop(StackMahasiswa &S) {
    if (!isEmpty(S)) S.Top--;
}

void Update(StackMahasiswa &S, int pos, Mahasiswa M) {
    if (pos >= 1 && pos <= S.Top+1)
        S.data[pos-1] = M;
}

void View(StackMahasiswa S) {
    for (int i = S.Top; i >= 0; i--) {
        cout << i+1 << ". " << S.data[i].Nama 
             << " (" << S.data[i].NIM << ") | "
             << "NA: " << NilaiAkhir(S.data[i]) << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float minA, float maxA) {
    for (int i = 0; i <= S.Top; i++) {
        float NA = NilaiAkhir(S.data[i]);
        if (NA >= minA && NA <= maxA)
            cout << "Posisi " << i+1 << ": " << S.data[i].Nama 
                 << " | NA = " << NA << endl;
    }
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) return;
    float maxN = NilaiAkhir(S.data[0]);
    int idx = 0;

    for (int i = 1; i <= S.Top; i++) {
        float NA = NilaiAkhir(S.data[i]);
        if (NA > maxN) { maxN = NA; idx = i; }
    }

    cout << "\nNilaiAkhir Tertinggi:\n";
    cout << "Posisi " << idx+1 << ": "
         << S.data[idx].Nama << " | NA = " << maxN << endl;
}
#include "StackMahasiswa.h"

int main() {
    StackMahasiswa S;
    createStack(S);

    Mahasiswa M[] = {
        {"Venti","11111",75.7,82.1,65.5},
        {"Xiao","22222",87.4,88.9,81.9},
        {"Kazuha","33333",92.3,88.8,82.4},
        {"Wanderer","44444",95.5,85.5,90.5},
        {"Lynette","55555",77.7,65.4,79.9},
        {"Chasca","66666",99.9,93.6,87.3}
    };

    for (int i=0; i<6; i++) Push(S, M[i]);

    cout << "\n== Stack Awal ==\n";
    View(S);

    Pop(S);

    cout << "\n== Setelah 1x Pop ==\n";
    View(S);

    Mahasiswa upd = {"Heizou","77777",99.9,88.8,77.7};
    Update(S, 3, upd);

    cout << "\n== Setelah Update Posisi 3 ==\n";
    View(S);

    cout << "\n== Searching NA 85.5 - 95.5 ==\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    // Bagian B
    MaxNilaiAkhir(S);

    return 0;
}
