#include <iostream>
using namespace std;

int main() {
    int data[10] = {5, 7, 12, 15, 17, 19, 22, 25, 27, 32};
    int N;
    bool ketemu = false;

    cout << "Masukkan nilai yang dicari (N): ";
    cin >> N;

    cout << endl;
    cout << "Iterasi | Index | Data | Keterangan" << endl;
    cout << "------------------------------------" << endl;

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "\t   " << i << "\t   " << data[i];

        if (data[i] == N) {
            cout << "\t DITEMUKAN" << endl;
            cout << endl;
            cout << "Kesimpulan:" << endl;
            cout << "Nilai " << N << " ditemukan pada iterasi ke-" << i + 1 << endl;
            cout << "Index ke-" << i << endl;
            ketemu = true;
            break;
        } else {
            cout << "\t Tidak sama" << endl;
        }
    }

    if (!ketemu) {
        cout << endl;
        cout << "Kesimpulan:" << endl;
        cout << "Nilai " << N << " TIDAK ditemukan" << endl;
    }

    return 0;
}

