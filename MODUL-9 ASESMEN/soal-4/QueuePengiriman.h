#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
const int BIAYA_KG = 8250;

struct Paket {
    string KodeResi, NamaPengirim, Tujuan;
    int BeratBarang;
};

struct QueueEkspedisi {
    Paket data[MAX];
    int Head, Tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enQueue(QueueEkspedisi &Q, Paket P);
void deQueue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
int TotalBiayaPengiriman(QueueEkspedisi Q);

#endif
