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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push() {
        Node* baru = new Node;
        cin.ignore();
        cout << "Nama   : ";
        getline(cin, baru->nama);
        cout << "NIM    : ";
        getline(cin, baru->nim);
        cout << "Gender : ";
        getline(cin, baru->gender);
        cout << "Nilai Struktur Data : ";
        cin >> baru->nilai;

        baru->next = top;
        top = baru;

        cout << "Data berhasil diinsert" << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack kosong" << endl;
        } else {
            Node* hapus = top;
            top = top->next;
            cout << "Data " << hapus->nama << " berhasil dihapus" << endl;
            delete hapus;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "Stack kosong" << endl;
        } else {
            Node* bantu = top;
            int i = 1;
            while (bantu != NULL) {
                cout << "Data ke-" << i << endl;
                cout << "Nama   : " << bantu->nama << endl;
                cout << "NIM    : " << bantu->nim << endl;
                cout << "Gender : " << bantu->gender << endl;
                cout << "Nilai  : " << bantu->nilai << endl;
                cout << "----------------------" << endl;
                bantu = bantu->next;
                i++;
            }
        }
    }
};

int main() {
    Stack s;
    int pilihan;

    do {
        cout << "===== MENU STACK MAHASISWA =====" << endl;
        cout << "1. INSERT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. CETAK DATA" << endl;
        cout << "4. EXIT" << endl;
        cout << "Pilih menu [1-4]: ";
        cin >> pilihan;

        if (pilihan == 1) {
            s.push();
        } else if (pilihan == 2) {
            s.pop();
        } else if (pilihan == 3) {
            s.display();
        } else if (pilihan == 4) {
            cout << "Program selesai" << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }

        cout << endl;
    } while (pilihan != 4);

    return 0;
}

