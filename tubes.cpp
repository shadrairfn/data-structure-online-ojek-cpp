#include "tubes.h"
#include <iostream>

using namespace std;

// Membuat list
void createListO(ListO &L){
    first(L) = nil;
    last(L) = nil;
}

void createListP(ListP &L){
    first(L) = nil;
    last(L) = nil;
}

void createListT(ListT &L){
    first(L) = nil;
    last(L) = nil;
}

// Mengecek list kosong
bool isEmptyO(ListO L) {
    if (first(L) == nil) {
        return true;
    }

    return false;
}

bool isEmptyP(ListP L) {
    if (first(L) == nil) {
        return true;
    }

    return false;
}

bool isEmptyT(ListT L) {
    if (first(L) == nil) {
        return true;
    }

    return false;
}

// Membuat kotak
adrO createNewO(infoO data) {
    adrO p = new elmOjol;
    info(p) = data;
    next(p) = nil;
    prev(p) = nil;

    return p;
}

adrP createNewP(infoP data) {
    adrP p = new elmPen;
    info(p) = data;
    next(p) = nil;
    prev(p) = nil;

    return p;
}

adrT createNewT(infoT data) {
    adrT t = new elmTrans;
    info(t) = data;
    next(t) = nil;
    prev(t) = nil;
    firstOjol(t) = nil;
    firstPen(t) = nil;

    return t;
}

// Memasukan data
void insertFirstOjol(ListO &L, adrO pointerO){
    if (isEmptyO(L)) {
        first(L) = pointerO;
        last(L) = pointerO;
    } else {
        next(pointerO) = first(L);
        prev(first(L)) = pointerO;
        first(L) = pointerO;
    }
}

void insertLastOjol(ListO &L, adrO pointerO){
    if (isEmptyO(L)) {
        first(L) = pointerO;
        last(L) = pointerO;
    } else {
        next(last(L)) = pointerO;
        prev(pointerO) = last(L);
        last(L) = pointerO;
    }
}

void insertFirstPen(ListP &L, adrP pointerP){
    if (isEmptyP(L)) {
        first(L) = pointerP;
        last(L) = pointerP;
    } else {
        next(pointerP) = first(L);
        prev(first(L)) = pointerP;
        first(L) = pointerP;
    }
}

void insertLastPen(ListP &L, adrP pointerP){
    if (isEmptyP(L)) {
        first(L) = pointerP;
        last(L) = pointerP;
    } else {
        next(last(L)) = pointerP;
        prev(pointerP) = last(L);
        last(L) = pointerP;
    }
}

void insertFirstTrans(ListT &LT, ListO LO, ListP LP, adrT pointerT, string namaOjol, string namaPen) {
    adrO o = findParent(LO, namaOjol);
    adrP p = findChild(LP, namaPen);
    if (isEmptyT(LT)) {
        first(LT) = pointerT;
        last(LT) = pointerT;
        firstOjol(pointerT) = o;
        firstPen(pointerT) = p;
    } else {
        next(pointerT) = first(LT);
        prev(first(LT)) = pointerT;
        first(LT) = pointerT;
        firstOjol(pointerT) = o;
        firstPen(pointerT) = p;
    }
}

void insertLastTrans(ListT &LT, ListO LO, ListP LP, adrT pointerT, string namaOjol, string namaPen){
    adrO o = findParent(LO, namaOjol);
    adrP p = findChild(LP, namaPen);
    if (isEmptyT(LT)) {
        first(LT) = pointerT;
        last(LT) = pointerT;
        firstOjol(pointerT) = o;
        firstPen(pointerT) = p;
    } else {
        prev(pointerT) = last(LT);
        next(last(LT)) = pointerT;
        last(LT) = pointerT;
        firstOjol(pointerT) = o;
        firstPen(pointerT) = p;
    }
}

void deleteFirstO(ListO &L, adrO &pointerO) {
    if (isEmptyO(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerO = first(L);
        first(L) = next(pointerO);
        prev(first(L)) = nil;
        next(pointerO) = nil;
    }
}

void deleteLastO(ListO &L, adrO &pointerO){
    if (isEmptyO(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerO = last(L);
        last(L) = prev(pointerO);
        next(last(L)) = nil;
        prev(pointerO) = nil;
    }
}

void deleteAfterO(ListO &L, adrO prec, adrO &pointerO){
    pointerO = next(prec);
    next(prec) = next(pointerO);
    prev(next(pointerO)) = prec;
    next(pointerO) = nil;
    prev(pointerO) = nil;
}



void deleteFirstP(ListP &L, adrP &pointerP) {
    if (isEmptyP(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerP = first(L);
        first(L) = next(pointerP);
        prev(first(L)) = nil;
        next(pointerP) = nil;
    }
}

void deleteLastP(ListP &L, adrP &pointerP){
    if (isEmptyP(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerP = last(L);
        last(L) = prev(pointerP);
        next(last(L)) = nil;
        prev(pointerP) = nil;
    }
}

void deleteAfterP(ListP &L, adrP prec, adrP &pointerP){
    pointerP = next(prec);
    next(prec) = next(pointerP);
    prev(next(pointerP)) = prec;
    next(pointerP) = nil;
    prev(pointerP) = nil;
}

void deleteFirstT(ListT &L, adrT &pointerT) {
    if (isEmptyT(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerT = first(L);
        first(L) = next(pointerT);
        prev(first(L)) = nil;
        next(pointerT) = nil;
        firstOjol(pointerT) = nil;
        firstPen(pointerT) = nil;
    }
}

void deleteLastT(ListT &L, adrT &pointerT){
    if (isEmptyT(L)) {
        cout << "List Ojol Kosong" << endl;
    } else {
        pointerT = last(L);
        last(L) = prev(pointerT);
        next(last(L)) = nil;
        prev(pointerT) = nil;
        firstOjol(pointerT) = nil;
        firstPen(pointerT) = nil;
    }
}

void deleteAfterT(ListT &L, adrT prec, adrT &pointerT){
    pointerT = next(prec);
    next(prec) = next(pointerT);
    prev(next(pointerT)) = prec;
    next(pointerT) = nil;
    prev(pointerT) = nil;
    firstOjol(pointerT) = nil;
    firstPen(pointerT) = nil;
}

void showParent(ListO L){
    adrO o = first(L);
    if (isEmptyO(L)) {
        cout << "List ojol kosong" << endl;
    } else {
        while (o != nil) {
            cout << info(o).nama << " " << info(o).noTelp << " " << info(o).jenisMotor << " " << info(o).platNomor << endl;
            o = next(o);
        }
    }
}

void showChild(ListP L) {
    adrP p = first(L);
    if (isEmptyP(L)) {
        cout << "List penumpang kosong" << endl;
    } else {
        while (p != nil) {
            cout << info(p).nama << " " << info(p).noTelp << endl;
            p = next(p);
        }
    }
}

void showRelation(ListT L) {
    adrT t = first(L);
    if (isEmptyT(L)) {
        cout << "List relasi kosong" << endl;
    } else {
        while (t != nil) {
            cout << info(t).cost << endl;
            t = next(t);
        }
    }
}

adrO findParent(ListO L, string namaOjol) {
    adrO o = first(L);
    while (o != nil) {
        if (info(o).nama == namaOjol) {
            return o;
        }
        o = next(o);
    }
    return nil;
}

adrP findChild(ListP L, string namaPen) {
    adrP p = first(L);
    while (p != nil) {
        if (info(p).nama == namaPen) {
            return p;
        }
        p = next(p);
    }
    return nil;
}

adrP findPenFrom(ListO LO, ListP LP, ListT LT, string namaOjol, string namaPen){
    adrT t = first(LT);
    adrO o = findParent(LO, namaOjol);
    adrP p = first(LP);

    while (p != nil) {
        if (info(p).nama == namaPen) {
            break;
        }
        p = next(p);
    }

    while (t != nil) {
        if (firstOjol(t) == o && firstPen(t) == p) {
            return p;
        }
        t = next(t);
    }

    return nil;
}


void editDataOjol(ListO &L, string namaData){
    adrO o = findParent(L, namaData);
    if (o != nil) {
        infoO data;
        cout << "Nama Ojol : ";
        cin >> data.nama;
        cout << "No Telepon Ojol : ";
        cin >> data.noTelp;
        cout << "Motor Ojol : ";
        cin >> data.jenisMotor;
        cout << "Plat Nomor : ";
        cin >> data.platNomor;
        info(o).nama = data.nama;
        info(o).noTelp = data.noTelp;
        info(o).jenisMotor = data.jenisMotor;
        info(o).platNomor = data.platNomor;
    } else {
        cout << "!!! Nama ojol tidak terdaftar !!!" << endl;
    }
}

void editDataPen(ListP &L, string namaPen){
    adrP p = findChild(L, namaPen);
    if (p != nil) {
        infoP data;
        cout << "Nama Penumpang : ";
        cin >> data.nama;
        cout << "No Telepon Penumpang : ";
        cin >> data.noTelp;
        info(p).nama = data.nama;
        info(p).noTelp = data.noTelp;
    } else {
        cout << "!!! Nama Penumpang Tidak Terdaftar !!!" << endl;
    }
}

void showAll(ListO LO, ListT LT){
    adrO o = first(LO);
    while (o != nil) {
        cout << "Nama ojol : " << info(o).nama << endl;
        cout << "No Telp : " << info(o).noTelp << endl;
        cout << "Jenis Motor : " << info(o).jenisMotor << endl;
        cout << "Plat Nomor : " << info(o).platNomor << endl;

        adrT t = first(LT);
        cout << "Penumpang : " << endl;
        while (t != nil) {
            if (firstOjol(t) == o) {
                cout << "- Nama : " << info(firstPen(t)).nama << endl;
                cout << "- No telp : " << info(firstPen(t)).noTelp << endl;
            }
            t = next(t);
        }

        o = next(o);
    }

}

void deleteParentChild(ListO &LO, ListP &LP, ListT &LT, string namaOjol){
    adrT alamatRelasi;
    adrO alamatOjol = findParent(LO, namaOjol);
    if (alamatOjol != nil) {
        alamatRelasi = first(LT);
        while (alamatRelasi != nil) {
            if (firstOjol(alamatRelasi) == alamatOjol) {
                firstOjol(alamatRelasi) = nil;
            }
            alamatRelasi = next(alamatRelasi);
        }

        alamatRelasi = first(LT);
        while (alamatRelasi != nil) {
            if (firstOjol(alamatRelasi) == nil) {
                string namaPenumpang = info(firstPen(alamatRelasi)).nama;
                adrP alamatPenumpang = findChild(LP, namaPenumpang);
                adrT alamatRelasiPenumpang = first(LT);
                int jumlahDriver = 0;
                while (alamatRelasiPenumpang != nil) {
                    if (firstPen(alamatRelasiPenumpang) == alamatPenumpang) {
                        jumlahDriver++;
                    }
                    alamatRelasiPenumpang = next(alamatRelasiPenumpang);
                }
                if (jumlahDriver == 1) {
                    firstPen(alamatRelasi) = nil;
                    adrP deletePenumpang;
                    if (alamatPenumpang == first(LP)) {
                        deleteFirstP(LP, deletePenumpang);
                    } else if (alamatPenumpang == last(LP)) {
                        deleteLastP(LP, deletePenumpang);
                    } else {
                        deleteAfterP(LP, prev(alamatPenumpang), deletePenumpang);
                    }
                } else {
                    firstPen(alamatRelasi) = nil;
                }
                adrT deleteRelasi;
                if (alamatRelasi == first(LT)) {
                    deleteFirstT(LT, deleteRelasi);
                } else if (alamatRelasi == last(LT)) {
                    deleteLastT(LT, deleteRelasi);
                } else {
                    deleteAfterT(LT, prev(alamatRelasi), deleteRelasi);
                }
            }
            alamatRelasi = next(alamatRelasi);
        }

        adrO deleteOjol;
        if (alamatOjol == first(LO)) {
            deleteFirstO(LO, deleteOjol);
        } else if (alamatOjol == last(LO)) {
            deleteLastO(LO, deleteOjol);
        } else {
            deleteAfterO(LO, prev(alamatOjol), deleteOjol);
        }
    } else {
        cout << "!!! Nama Ojol Tidak Ditemukan !!!" << endl;
    }
}

void deletePenFrom(ListO LO, ListP &LP, ListT &LT, string namaOjol, string namaPen){
    adrP alamatPenumpang = findChild(LP, namaPen);
    adrO alamatDriver = findParent(LO, namaOjol);
    adrT alamatRelasi;
    if (alamatDriver != nil && alamatPenumpang != nil) {
        alamatRelasi = first(LT);
        while (alamatRelasi != nil) {
            if (firstPen(alamatRelasi) == alamatPenumpang && firstOjol(alamatRelasi) == alamatDriver) {
                firstPen(alamatRelasi) = nil;
                firstOjol(alamatRelasi) = nil;
            }
            alamatRelasi = next(alamatRelasi);
        }
        alamatRelasi = first(LT);
        int jumlah = 0;
        while (alamatRelasi != nil) {
            if (firstPen(alamatRelasi) == alamatPenumpang) {
                jumlah++;
            }
            alamatRelasi = next(alamatRelasi);
        }

        if (jumlah == 0) {
            adrP deletePenumpang;
            if (alamatPenumpang == first(LP)) {
                deleteFirstP(LP, deletePenumpang);
            } else if (alamatPenumpang == last(LP)) {
                deleteLastP(LP, deletePenumpang);
            } else {
                deleteAfterP(LP, prev(alamatPenumpang), deletePenumpang);
            }
        }

        alamatRelasi = first(LT);
        adrT deleteAlamatRelasi;
        while (alamatRelasi != nil) {
            if (firstPen(alamatRelasi) == nil && firstOjol(alamatRelasi) == nil) {
                deleteAlamatRelasi = alamatRelasi;
            }
            alamatRelasi = next(alamatRelasi);
        }
        adrT deleteRelasi;
        if (deleteAlamatRelasi == first(LT)) {
            deleteFirstT(LT, deleteRelasi);
        } else if (deleteAlamatRelasi == last(LT)) {
            deleteLastT(LT, deleteRelasi);
        } else {
            deleteAfterT(LT, prev(deleteAlamatRelasi), deleteRelasi);
        }
    } else {
        cout << "!!! Terdapat Data Yang Tidak Ditemukan !!!" << endl;
    }
}
int sumCost(ListO LO, ListT LT, string namaOjol){
    adrO o = findParent(LO, namaOjol);
    adrT t = first(LT);
    int jumlah = 0;
    if (o != nil) {
        while (t != nil) {
            if (firstOjol(t) == o) {
                jumlah += info(t).cost;
            }
            t = next(t);
        }
    } else {
        cout << "Nama ojol tidak ditemukan" << endl;
    }

    return jumlah;
}

void menu() {
    cout << "=====================================" << endl;
    cout << "||   1. Daftarkan Ojek Online      ||" << endl;
    cout << "||   2. Masukan Penumpang          ||" << endl;
    cout << "||   3. Edit Data Ojol             ||" << endl;
    cout << "||   4. Edit Data Penumpang        ||" << endl;
    cout << "||   5. Hapus Data Ojol            ||" << endl;
    cout << "||   6. Hapus Data Penumpang       ||" << endl;
    cout << "||   7. Cari Data Ojol             ||" << endl;
    cout << "||   8. Cari Data Penumpang        ||" << endl;
    cout << "||   9. Hitung Pendapatan          ||" << endl;
    cout << "||   10. Tampilkan Semua Data      ||" << endl;
    cout << "=====================================" << endl;
}
