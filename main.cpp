#include <iostream>
#include "tubes.h"

using namespace std;

int main()
{
    ListO LO;
    ListP LP;
    ListT LT;

    createListO(LO);
    createListP(LP);
    createListT(LT);

    infoO dataOjol;
    infoP dataPen;
    infoT dataTrans;

    int nomorMenu;
    adrO O;
    adrP P;
    adrT T;
    adrO AlamatDriver;
    string nama;
    string namaOjol;
    int jumlahPendapatan;
    bool program = true;
    while (program) {
        menu();
        cout << "Pilih Menu : ";
        cin >> nomorMenu;
        switch (nomorMenu) {
            case 1:
                cout << "Nama Ojol          : ";
                cin >> dataOjol.nama;
                cout << "No Telepon Ojol    : ";
                cin >> dataOjol.noTelp;
                cout << "Motor Ojol         : ";
                cin >> dataOjol.jenisMotor;
                cout << "Plat Nomor         : ";
                cin >> dataOjol.platNomor;
                O = createNewO(dataOjol);
                insertLastOjol(LO, O);
                break;

            case 2:
                cout << "Nama Penumpang             : ";
                cin >> dataPen.nama;
                cout << "No Telepon Penumpang       : ";
                cin >> dataPen.noTelp;
                cout << "Nama Driver Yang Melayani  : ";
                cin >> nama;

                AlamatDriver = findParent(LO, nama);
                if (AlamatDriver != nullptr) {
                    cout << "Tarif Pelayanan            : ";
                    cin >> dataTrans.cost;
                    P = createNewP(dataPen);
                    insertLastPen(LP, P);
                    T = createNewT(dataTrans);
                    insertFirstTrans(LT, LO, LP, T, nama, dataPen.nama);
                } else {
                    cout << "!!! Nama Driver Tidak Ditemukan !!!" << endl;
                }
                break;

            case 3:
                cout << "Nama Ojol Yang Ingin Diedit : ";
                cin >> nama;
                editDataOjol(LO, nama);
                break;

            case 4:
                cout << "Nama Penumpang Yang Ingin Diedit : ";
                cin >> nama;
                editDataPen(LP, nama);
                break;

            case 5:
                cout << "Masukan Nama Ojol Yang Ingin Dihapus : ";
                cin >> nama;
                deleteParentChild(LO, LP, LT, nama);
                break;

            case 6:
                cout << "Masukan Nama Penumpang Yang Ingin Dihapus : ";
                cin >> nama;
                cout << "Masukan Nama Ojol : ";
                cin >> namaOjol;
                deletePenFrom(LO, LP, LT, namaOjol, nama);
                break;

            case 7:
                cout << "Masukan Nama Ojol Yang Ingin Dicari : ";
                cin >> nama;
                O = findParent(LO, nama);
                if (O != nil) {
                    cout << "!! Data Ditemukan !!" << endl;
                    cout << "Nama Ojol          : " << info(O).nama << endl;
                    cout << "No Telepon ojol    : " << info(O).noTelp << endl;
                    cout << "Motor Ojol         : " << info(O).jenisMotor << endl;
                    cout << "Plat Nomor         : " << info(O).platNomor << endl;
                } else {
                    cout << "!!! Data Tidak Ditemukan !!!" << endl;
                }
                break;

            case 8:
                cout << "Masukan Nama Penumpang Yang Ingin Dicari : ";
                cin >> nama;
                P = findChild(LP, nama);
                if (P != nil) {
                    cout << "!! Data Ditemukan !!" << endl;
                    cout << "Nama Penumpang         : " << info(P).nama << endl;
                    cout << "No Telepon Penumpang   : " << info(P).noTelp << endl;
                } else {
                    cout << "!!! Data Tidak Ditemukan !!!" << endl;
                }
                break;

            case 9:
                cout << "Masukan Nama Ojol Yang Ingin Dihitung Pendapatannya : ";
                cin >> nama;
                jumlahPendapatan = sumCost(LO, LT, nama);
                cout << nama << " Memiliki Total Pendapatan Sebesar Rp. " << jumlahPendapatan << endl;
                break;

            case 10:
                showAll(LO, LT);

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
    return 0;
}
