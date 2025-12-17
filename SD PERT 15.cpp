#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    string gender;
    float nilai;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void animasi(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        cout << teks[i];
    }
    cout << endl;
}

void insertData() {
    Node* baru = new Node;
    cin.ignore();
    animasi("Input Data Mahasiswa");
    cout << "Nama   : ";
    getline(cin, baru->nama);
    cout << "NIM    : ";
    getline(cin, baru->nim);
    cout << "Gender : ";
    getline(cin, baru->gender);
    cout << "Nilai  : ";
    cin >> baru->nilai;

    if (head == NULL) {
        head = baru;
        baru->next = baru;
        baru->prev = baru;
    } else if (baru->nim < head->nim) {
        Node* last = head->prev;
        baru->next = head;
        baru->prev = last;
        last->next = baru;
        head->prev = baru;
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != head && bantu->next->nim < baru->nim) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        baru->prev = bantu;
        bantu->next->prev = baru;
        bantu->next = baru;
    }

    animasi("Data berhasil di INSERT");
}

void hapusData() {
    if (head == NULL) {
        animasi("Data masih kosong");
        return;
    }

    string target;
    cin.ignore();
    cout << "Masukkan NIM yang akan dihapus : ";
    getline(cin, target);

    Node* bantu = head;
    do {
        if (bantu->nim == target)
            break;
        bantu = bantu->next;
    } while (bantu != head);

    if (bantu->nim != target) {
        animasi("Data tidak ditemukan");
        return;
    }

    if (bantu->next == bantu) {
        delete bantu;
        head = NULL;
    } else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
        if (bantu == head)
            head = bantu->next;
        delete bantu;
    }

    animasi("Data berhasil di HAPUS");
}

void cetakData() {
    if (head == NULL) {
        animasi("Data masih kosong");
    } else {
        animasi("Menampilkan Data Mahasiswa");
        Node* bantu = head;
        do {
            cout << "Nama   : " << bantu->nama << endl;
            cout << "NIM    : " << bantu->nim << endl;
            cout << "Gender : " << bantu->gender << endl;
            cout << "Nilai  : " << bantu->nilai << endl;
            cout << "---------------------------" << endl;
            bantu = bantu->next;
        } while (bantu != head);
    }
}

int main() {
    int pilih;

    do {
        cout << endl;
        cout << "CIRCULAR DOUBLY" << endl;
        cout << "==========================" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilihan (1 - 4) : ";
        cin >> pilih;

        if (pilih == 1) {
            insertData();
        } else if (pilih == 2) {
            hapusData();
        } else if (pilih == 3) {
            cetakData();
        } else if (pilih == 4) {
            animasi("Program selesai");
        } else {
            animasi("Pilihan tidak valid");
        }

    } while (pilih != 4);

    return 0;
}

