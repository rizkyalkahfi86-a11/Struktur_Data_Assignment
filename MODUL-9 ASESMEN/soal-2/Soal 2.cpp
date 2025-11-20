// #include "DLLPlaylist.h"

// float popScore(Song S) {
//     return 0.8f * S.PlayCount + 20.0f * S.Rating;
// }

// bool isEmpty(List L) {
//     return L.head == NULL;
// }

// void createList(List &L) {
//     L.head = L.tail = NULL;
// }

// Node* allocate(Song S) {
//     Node *P = new Node;
//     P->info = S;
//     P->prev = P->next = NULL;
//     return P;
// }

// void deallocate(Node *P) { delete P; }

// // ============= INSERT =============
// void insertFirst(List &L, Song S) {
//     Node *P = allocate(S);
//     if (isEmpty(L)) L.head = L.tail = P;
//     else {
//         P->next = L.head;
//         L.head->prev = P;
//         L.head = P;
//     }
// }

// void insertLast(List &L, Song S) {
//     Node *P = allocate(S);
//     if (isEmpty(L)) L.head = L.tail = P;
//     else {
//         P->prev = L.tail;
//         L.tail->next = P;
//         L.tail = P;
//     }
// }

// void insertAfter(List &L, Node *Q, Song S) {
//     if (!Q) return;
//     Node *P = allocate(S);
//     P->next = Q->next;
//     P->prev = Q;
//     if (Q->next) Q->next->prev = P; else L.tail = P;
//     Q->next = P;
// }

// void insertBefore(List &L, Node *Q, Song S) {
//     if (!Q) return;
//     Node *P = allocate(S);
//     P->prev = Q->prev;
//     P->next = Q;
//     if (Q->prev) Q->prev->next = P; else L.head = P;
//     Q->prev = P;
// }

// // ============= DELETE =============
// void deleteFirst(List &L, Song &S) {
//     if (isEmpty(L)) return;
//     Node *P = L.head;
//     S = P->info;
//     if (L.head == L.tail) L.head = L.tail = NULL;
//     else {
//         L.head = P->next;
//         L.head->prev = NULL;
//     }
//     deallocate(P);
// }

// void deleteLast(List &L, Song &S) {
//     if (isEmpty(L)) return;
//     Node *P = L.tail;
//     S = P->info;
//     if (L.head == L.tail) L.head = L.tail = NULL;
//     else {
//         L.tail = P->prev;
//         L.tail->next = NULL;
//     }
//     deallocate(P);
// }

// void deleteAfter(List &L, Node *Q, Song &S) {
//     if (!Q || !Q->next) return;
//     Node *P = Q->next;
//     S = P->info;

//     Q->next = P->next;
//     if (P->next) P->next->prev = Q; else L.tail = Q;

//     deallocate(P);
// }

// void deleteBefore(List &L, Node *Q, Song &S) {
//     if (!Q || !Q->prev) return;
//     Node *P = Q->prev;
//     S = P->info;

//     if (P->prev) P->prev->next = Q; else L.head = Q;
//     Q->prev = P->prev;

//     deallocate(P);
// }

// // ============= UPDATE =============
// void updateAtPosition(List &L, int pos) {
//     Node *P = L.head;
//     for (int i = 1; P && i < pos; i++) P = P->next;

//     if (!P) return;

//     cout << "Title: "; getline(cin, P->info.Title);
//     cout << "Artist: "; getline(cin, P->info.Artist);
//     cout << "DurationSec: "; cin >> P->info.DurationSec;
//     cout << "PlayCount: "; cin >> P->info.PlayCount;
//     cout << "Rating: "; cin >> P->info.Rating;
//     cin.ignore();
// }

// void updateBefore(List &L, Node *Q) {
//     if (!Q || !Q->prev) return;
//     Node *P = Q->prev;

//     cout << "Title: "; getline(cin, P->info.Title);
//     cout << "Artist: "; getline(cin, P->info.Artist);
//     cout << "DurationSec: "; cin >> P->info.DurationSec;
//     cout << "PlayCount: "; cin >> P->info.PlayCount;
//     cout << "Rating: "; cin >> P->info.Rating;
//     cin.ignore();
// }

// // ============= VIEW =============
// void viewList(List L) {
//     Node *P = L.head;
//     int pos = 1;

//     while (P) {
//         cout << pos << ". " << P->info.Title << " | " << P->info.Artist
//              << " | " << P->info.DurationSec << "s | PC:" << P->info.PlayCount
//              << " | Rating:" << P->info.Rating
//              << " | Score:" << popScore(P->info) << endl;
//         P = P->next;
//         pos++;
//     }
// }

// // ============= SEARCH =============
// void searchByPopularityRange(List L, float minS, float maxS) {
//     Node *P = L.head;
//     int pos = 1;

//     while (P) {
//         float sc = popScore(P->info);
//         if (sc >= minS && sc <= maxS) {
//             cout << pos << ". " << P->info.Title
//                  << " | Score: " << sc << endl;
//         }
//         P = P->next;
//         pos++;
//     }
// }
// #include "DLLPlaylist.h"

// int main() {
//     List L;
//     createList(L);

//     // 3 lagu
//     insertLast(L, {"Senja di Kota","Nona Band",210,150,4.2f});
//     insertLast(L, {"Langkahmu","Delta",185,320,4.8f});
//     insertLast(L, {"Hujan Minggu","Arka",240,90,3.9f});

//     cout << "\n== LIST AWAL ==\n";
//     viewList(L);

//     // deleteLast
//     Song X;
//     deleteLast(L, X);

//     cout << "\n== SETELAH deleteLast ==\n";
//     viewList(L);

//     // update posisi 2
//     cout << "\n== UPDATE POSISI 2 ==\n";
//     Node *pos2 = L.head->next;
//     pos2->info = {"Pelita","Luna",200,260,4.5f};

//     cout << "\n== LIST SETELAH UPDATE ==\n";
//     viewList(L);

//     // insertBefore posisi 2
//     cout << "\n== INSERT BEFORE POSISI 2 ==\n";
//     insertBefore(L, L.head->next, {"Senandung","Mira",175,120,4.0f});
//     viewList(L);

//     // updateBefore posisi 2
//     cout << "\n== UPDATE BEFORE POSISI 2 ==\n";
//     updateBefore(L, L.head->next);
//     viewList(L);

//     // deleteBefore posisi 3
//     cout << "\n== DELETE BEFORE POSISI 3 ==\n";
//     Node *pos3 = L.head->next->next;
//     deleteBefore(L, pos3, X);
//     viewList(L);

//     // Search score
//     cout << "\n== SEARCH SCORE 150 - 300 ==\n";
//     searchByPopularityRange(L, 150, 300);

//     return 0;
// }
