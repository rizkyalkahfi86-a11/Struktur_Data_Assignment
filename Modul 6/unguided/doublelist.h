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
