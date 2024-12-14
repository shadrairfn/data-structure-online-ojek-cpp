#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#define info(p) p->info
#define next(p) p->next
#define prev(p) p->prev
#define firstOjol(p) p->firstOjol
#define firstPen(p) p->firstPen
#define first(L) L.first
#define last(L) L.last
#define nil NULL

using namespace std;

typedef struct elmOjol *adrO;
typedef struct elmPen *adrP;
typedef struct elmTrans *adrT;

struct ojol {
    string nama;
    string noTelp;
    string jenisMotor;
    string platNomor;
};
struct penumpang {
    string nama;
    string noTelp;
};
struct transaksi {
    int cost;
};

typedef ojol infoO;
typedef penumpang infoP;
typedef transaksi infoT;

struct elmOjol {
    infoO info;
    adrO next;
    adrO prev;
};
struct elmPen {
    infoP info;
    adrP next;
    adrP prev;
};
struct elmTrans {
    infoT info;
    adrT next;
    adrT prev;
    adrO firstOjol;
    adrP firstPen;
};

struct ListO {
    adrO first;
    adrO last;
};
struct ListP {
    adrP first;
    adrP last;
};
struct ListT {
    adrT first;
    adrT last;
};

// Primitive dari soal
void insertFirstOjol(ListO &L, adrO pointerO);
void insertLastOjol(ListO &L, adrO pointerO);
void deleteParentChild(ListO &LO, ListP &LP, ListT &LT, string namaOjol);
void showParent(ListO L);
adrO findParent(ListO L, string namaOjol);
void insertFirstPen(ListP &L, adrP pointerP);
void insertLastPen(ListP &L, adrP pointerP);
void editDataOjol(ListO &L, string namaData);
void editDataPen(ListP &L, string namaData);
void showAll(ListO LO, ListT LT);
adrP findPenFrom(ListO LO, ListP LP, ListT LT, string namaOjol, string namaPen);
void deletePenFrom(ListO LO, ListP &LP, ListT &LT, string namaOjol, string namaPen);
int sumCost(ListO LO, ListT LT, string namaOjol);

// Primitive tambahan

void createListO(ListO &L);
void createListP(ListP &L);
void createListT(ListT &L);
bool isEmptyO(ListO L);
bool isEmptyP(ListP L);
bool isEmptyT(ListT L);
adrO createNewO(infoO data);
adrP createNewP(infoP data);
adrT createNewT(infoT data);
adrT findOT(ListO LO, ListT LT, string namaOjol);
adrT findPT(ListP LP, ListT LT, string namaPen);
void deleteAfterO(ListO &L, adrO prec, adrO &pointerO);
void deleteFirstO(ListO &L, adrO &pointerO);
void deleteLastO(ListO &L, adrO &pointerO);

void deleteAfterP(ListP &L, adrP prec, adrP &pointerP);
void deleteFirstP(ListP &L, adrP &pointerP);
void deleteLastP(ListP &L, adrP &pointerP);

void deleteAfterT(ListT &L, adrT prec, adrP &pointerT);
void deleteFirstT(ListT &L, adrT &pointerT);
void deleteLastT(ListT &L, adrT &pointerT);

void insertFirstTrans(ListT &LT, ListO LO, ListP LP, adrT pointerT, string namaOjol, string namaPen);
void insertLastTrans(ListT &L, ListO LO, ListP LP, adrT pointerT, string namaOjol, string namaPen);

adrP findChild(ListP L, string namaPen);

void showChild(ListP L);
void showRelation(ListT L);

void menu();
#endif // TUBES_H_INCLUDED
