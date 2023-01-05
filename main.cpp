#include "perpustakaan.h"

#include <iostream>

using namespace std;

int main()
{
    // Define List Variable
    listBuku LB;
    listMahasiswa LM;
    listRelasi LR;

    // Define Variable
    mahasiswa MHS;
    buku BUKU;


    // Define adr of List
    adrRelasi R;
    adrBuku B;
    adrMahasiswa M;

    // Create List For All Defined List
    CreateListBuku(LB);
    CreateListMahasiswa(LM);
    CreateListRelasi(LR);

    // Akses menu
    int masukan;
    char kembali;
    masukan = menu();
    while(masukan != 0){
        if(masukan == 1){
            // Defined i
            int N;
            int i = 0;
            cout << "Banyaknya Input:";
            cin >> N;
            cout << endl;
            while(i < N){
                cout << "Nomor Induk Buku: ";
                cin >> BUKU.noIndukBuku;
                cout << "Judul Buku: ";
                cin >> BUKU.judulBuku;
                cout << "Nama Penulis: ";
                cin >> BUKU.namaPenulis;
                cout << "Tahun Terbit: ";
                cin >> BUKU.tahunTerbit;
                cout << endl;
                B = newElementBuku(BUKU);
                insertLastBuku(LB, B);
                i++;

            //i = 0;
            }
        }else if(masukan == 2){
            cout << "========== SHOW BUKU ==========" << endl;
            showBuku(LB);
            cout << endl;
        }else if(masukan == 3){
            cout<<"============== Masukan Data Mahasiswa ============"<<endl;
            cout << "Banyaknya Mahasiswa:";
            int N,i;
            i = 0;
            cin >> N;
            while(i < N) {
                int h = 0;
                cout << "Nama Mahasiswa: ";
                cin >> MHS.namaMahasiswa;
                cout << "ID Mahasiswa: ";
                cin >> MHS.id;
                cout << "Tanggal Pinjam: ";
                cin >> MHS.tanggalPinjam;
                cout << "Tanggal Kembali: ";
                cin >> MHS.tanggalKembali;
                cout << endl;
                cout << "Jumlah Buku Yang Dipinjam:";
                cin >> MHS.jumlahDipinjam;
                while (h < MHS.jumlahDipinjam) {
                    cout << "Nomor Induk Buku: ";
                    cin >> BUKU.noIndukBuku;
                    B = searchBuku(LB, BUKU.noIndukBuku);
                    R = newElementRelasi(B);
                    insertLastRelasi(LR, R);
                    h++;
                }
                M = newElementMahasiswa(MHS);
                insertLastMahasiswa(LM, M, LR);
                i++;
                cout << endl;
            }
        }else if(masukan == 4){
            cout << "=================== SHOW MAHASISWA ===================" << endl;
            showMahasiswa(LM);
            cout << endl;
        }else if(masukan == 5){
            cout << "=================== SHOW ALL ===================" << endl;
            showAll(LM);
            cout << endl;
        }else if(masukan == 6){
            cout << "========== Menghitung Jumlah Data ==========" << endl;
            cout << "Jumlah Buku :" << hitungBuku(LB) << endl;
            cout << "Jumlah Mahasiswa :" << hitungMahasiswa(LM) << endl;
        }else if(masukan == 7){
            cout << "Menghapus Data Pertama"<< endl;
            deleteFirstMahasiswa(LM,M);
            cout << endl;
            showAll(LM);
            cout<<endl;
        }else if(masukan == 8){
            cout<<"Menghapus Data Terakhir"<<endl;
            deleteLastMahasiswa(LM, M);
            cout << endl;
            showAll(LM);
            cout<<endl;
        }else{
            cout<<"Menu tidak ditemukan"<<endl;
        }
        cout<<endl;
        cout<<"Kembali ke menu ? (Y/N) : ";
        cin>>kembali;

        if(kembali == 'Y'){
            cout<<endl;
            masukan = menu();
        }else if(kembali=='N'){
            masukan = 0;
        }
    }
    cout<<endl;
    cout << "EXIT" << endl;
    return 0;
}



//    while(masukan != 0){
//        switch(masukan){
//    case 1:{
//        // Defined i
//        int N;
//        int i = 0;
//        cout << "Banyaknya Input:";
//        cin >> N;
//        cout<<endl;
//        while(i < N){
//            cout << "Nomor Induk Buku: ";
//            cin >> BUKU.noIndukBuku;
//            cout << "Judul Buku: ";
//            cin >> BUKU.judulBuku;
//            cout << "Nama Penulis: ";
//            cin >> BUKU.namaPenulis;
//            cout << "Tahun Terbit: ";
//            cin >> BUKU.tahunTerbit;
//            cout << endl;
//            B = newElementBuku(BUKU);
//            insertLastBuku(LB, B);
//            i++;
//            cout << endl;
//            break;
//        }
//    }
//    case 2:{
//        cout << "========== SHOW BUKU ==========" << endl;
//        showBuku(LB);
//        cout << endl;
//        break;
//    }
//
//    case 3:{
//        cout << "Banyaknya Mahasiswa:";
//        int N;
//        int i = 0;
//        cin >> N;
//        while(i < N) {
//            int h = 0;
//            cout << "Nama Mahasiswa: ";
//            cin >> MHS.namaMahasiswa;
//            cout << "ID Mahasiswa: ";
//            cin >> MHS.id;
//            cout << "Tanggal Pinjam: ";
//            cin >> MHS.tanggalPinjam;
//            cout << "Tanggal Kembali: ";
//            cin >> MHS.tanggalKembali;
//            cout << endl;
//            cout << "Jumlah Buku Yang Dipinjam:";
//            cin >> MHS.jumlahDipinjam;
//            while (h < MHS.jumlahDipinjam) {
//                cout << "Nomor Induk Buku: ";
//                cin >> BUKU.noIndukBuku;
//                B = searchBuku(LB, BUKU.noIndukBuku);
//                R = newElementRelasi(B);
//                insertLastRelasi(LR, R);
//                h++;
//            }
//            M = newElementMahasiswa(MHS);
//            insertLastMahasiswa(LM, M, LR);
//            i++;
//            cout << endl;
//            break;
//        }
//    }
//
//    case 4:{
//        cout << "=================== SHOW MAHASISWA ===================" << endl;
//        showMahasiswa(LM);
//        cout << endl;
//        break;
//    }
//
//    case 5:{
//        cout << "=================== SHOW ALL ===================" << endl;
//        showAll(LM);
//        cout << endl;
//        break;
//    }
//
//    case 6:{
//        cout << "========== Menghitung Jumlah Data ==========" << endl;
//        cout << "Jumlah Buku :" << hitungBuku(LB) << endl;
//        cout << "Jumlah Mahasiswa :" << hitungMahasiswa(LM) << endl;
//        cout << "Jumlah Peminjam Terbanyak :" << findMaxDipinjam(LM) << endl;
//        cout << "Jumlah Peminjam Terdikit :" << findMinDipinjam(LM) << endl;
//        cout << "DELETE RELASI" << endl;
//        cout << "Masukkan id mahasiswa yang ingin dihapus: ";
//        cin >> MHS.id;
//        cout << "Masukkan buku yang ingin dihapus: ";
//        cin >> BUKU.judulBuku;
//        cout << endl;
//        break;
//    }
//
//    case 7:{
//        deleteFirstMahasiswa(LM,M);
//        cout << endl;
//        showAll(LM);
//        cout << endl;
//        break;
//    }
//
//    case 8:{
//        deleteLastMahasiswa(LM, M);
//        cout << endl;
//        showAll(LM);
//        cout << endl;
//        break;
//            }
//        }
//        cout<<endl;
//        cout<<"Kembali ke menu ? (Y/N) : ";
//        cin>>kembali;
//
//        if(kembali == 'Y'){
//            cout<<endl;
//            masukan = menu();
//        }else if(kembali=='N'){
//            masukan = 0;
//        }
//    }
//    cout<<endl;
//    cout << "EXIT" << endl;
//    return 0;
//}

//    cout << "\n\t\t\t Perpustakaan Umum Bahagia \n" << endl;
//    // Defined i
//    int N;
//    int i = 0;
//    cout << "Banyaknya Input:";
//    cin >> N;
//    cout << endl;
//    while(i < N){
//        cout << "Nomor Induk Buku: ";
//        cin >> BUKU.noIndukBuku;
//        cout << "Judul Buku: ";
//        cin >> BUKU.judulBuku;
//        cout << "Nama Penulis: ";
//        cin >> BUKU.namaPenulis;
//        cout << "Tahun Terbit: ";
//        cin >> BUKU.tahunTerbit;
//        cout << endl;
//        B = newElementBuku(BUKU);
//        insertLastBuku(LB, B);
//        i++;
//
//    i = 0;
//    cout << "========== SHOW BUKU ==========" << endl;
//    showBuku(LB);
//    cout << endl;
//    cout << "Banyaknya Mahasiswa:";
//    cin >> N;
//    while(i < N) {
//        int h = 0;
//        cout << "Nama Mahasiswa: ";
//        cin >> MHS.namaMahasiswa;
//        cout << "ID Mahasiswa: ";
//        cin >> MHS.id;
//        cout << "Tanggal Pinjam: ";
//        cin >> MHS.tanggalPinjam;
//        cout << "Tanggal Kembali: ";
//        cin >> MHS.tanggalKembali;
//        cout << endl;
//        cout << "Jumlah Buku Yang Dipinjam:";
//        cin >> MHS.jumlahDipinjam;
//        while (h < MHS.jumlahDipinjam) {
//            cout << "Nomor Induk Buku: ";
//            cin >> BUKU.noIndukBuku;
//            B = searchBuku(LB, BUKU.noIndukBuku);
//            R = newElementRelasi(B);
//            insertLastRelasi(LR, R);
//            h++;
//        }
//        M = newElementMahasiswa(MHS);
//        insertLastMahasiswa(LM, M, LR);
//        i++;
//        cout << endl;

//    cout << "=================== SHOW MAHASISWA ===================" << endl;
//    showMahasiswa(LM);
//    cout << endl;
//    cout << "=================== SHOW ALL ===================" << endl;
//    showAll(LM);
//    cout << endl;
//    cout << "========== Menghitung Jumlah Data ==========" << endl;
//    cout << "Jumlah Buku :" << hitungBuku(LB) << endl;
//    cout << "Jumlah Mahasiswa :" << hitungMahasiswa(LM) << endl;
//    cout << "Jumlah Peminjam Terbanyak :" << findMaxDipinjam(LM) << endl;
//    cout << "Jumlah Peminjam Terdikit :" << findMinDipinjam(LM) << endl;
//    cout << "DELETE RELASI" << endl;
//    cout << "Masukkan id mahasiswa yang ingin dihapus: ";
//    cin >> MHS.id;
//    cout << "Masukkan buku yang ingin dihapus: ";
//    cin >> BUKU.judulBuku;
//    deleteFirstMahasiswa(LM,M);
//    cout << endl;
//    showAll(LM);
//    cout << endl;
//        deleteLastMahasiswa(LM, M);
//        cout << endl;
//        showAll(LM);
