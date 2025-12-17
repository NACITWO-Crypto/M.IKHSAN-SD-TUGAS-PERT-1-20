#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nim;
    string gender;
    float nilai;
    Node* next;
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
        baru->next = head;
    } else if (baru->nim < head->nim) {
        Node* bantu = head;
        while (bantu->next != head) {
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->next = head;
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != head && bantu->next->nim < baru->nim) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
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
    Node* prev = NULL;

    do {
        if (bantu->nim == target)
            break;
        prev = bantu;
        bantu = bantu->next;
    } while (bantu != head);

    if (bantu->nim != target) {
        animasi("Data tidak ditemukan");
        return;
    }

    if (bantu == head && bantu->next == head) {
        delete head;
        head = NULL;
    } else if (bantu == head) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete bantu;
    } else {
        prev->next = bantu->next;
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
        cout << "CIRCULAR LINKED LIST" << endl;
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

