#include <iostream>
using namespace std;

// == Struktur Data == 
struct Laptop {
    string nama;
    int harga;      
    int ram;        
    int storage;    
    int skorOffice;
    int skorCoding;
    int skorGaming;
};

// == Ini data nya, pake struktur data di atas == 
void initLaptop(Laptop laptop[], int &n) {
    n = 20;

    // ini ai males nyari nya 
    laptop[0]  = {"Acer Aspire 3", 7, 8, 512, 8, 6, 3};
    laptop[1]  = {"Lenovo IdeaPad Slim", 8, 8, 512, 8, 6, 3};
    laptop[2]  = {"ASUS VivoBook 14", 8, 8, 512, 8, 7, 3};
    laptop[3]  = {"HP 14s", 7, 8, 256, 8, 6, 2};
    laptop[4]  = {"Dell Inspiron 14", 9, 16, 512, 8, 8, 4};

    // Coding / Business
    laptop[5]  = {"Lenovo ThinkPad T480", 8, 16, 512, 7, 9, 4};
    laptop[6]  = {"ThinkPad E14", 9, 16, 512, 7, 9, 4};
    laptop[7]  = {"HP ProBook 440", 9, 16, 512, 7, 8, 4};
    laptop[8]  = {"Dell Latitude 5490", 9, 16, 512, 7, 9, 4};
    laptop[9]  = {"ASUS ExpertBook", 8, 16, 512, 8, 8, 3};

    // Gaming ringan
    laptop[10] = {"ASUS TUF FX505", 10, 16, 1024, 5, 7, 9};
    laptop[11] = {"Acer Nitro 5", 11, 16, 1024, 5, 7, 9};
    laptop[12] = {"MSI GF63", 11, 16, 1024, 6, 8, 8};
    laptop[13] = {"HP Victus 16", 12, 16, 1024, 5, 7, 9};
    laptop[14] = {"Lenovo Legion 5", 13, 16, 1024, 5, 8, 9};

    // High performance
    laptop[15] = {"ASUS ROG Strix", 15, 32, 1024, 6, 9, 10};
    laptop[16] = {"MSI Katana", 14, 32, 1024, 6, 9, 9};
    laptop[17] = {"Acer Predator Helios", 16, 32, 1024, 6, 9, 10};
    laptop[18] = {"Dell G15", 14, 32, 1024, 6, 9, 9};
    laptop[19] = {"HP Omen 16", 15, 32, 1024, 6, 9, 10};
}


// == Ini tampilan awal pas di run nama kelompok dll ==
void start() {
       cout << R"(
 ____  __.     .__                                __      ____ 
|    |/ _|____ |  |   ____   _____ ______   ____ |  | __ /_   |
|      <_/ __ \|  |  /  _ \ /     \\____ \ /  _ \|  |/ /  |   |
|    |  \  ___/|  |_(  <_> )  Y Y  \  |_> >  <_> )    <   |   |
|____|__ \___  >____/\____/|__|_|  /   __/ \____/|__|_ \  |___|
        \/   \/                  \/|__|               \/      

<=================== Rekomendasi Laptop =======================>
<==============================================================>

<==================== Anggota Kelompok ========================>

    1) Erik Fahrizal (065125003)
    2) Khilfi Daifullah Keysar (065125005)
    3) Muhammad Al Hasan Siregar(065125016)
    4) Mohamad Dirham Fajari (065125017)
    5) Dimas Enggar Putra (065125018)

<==============================================================>
)";
}

// == Ini input kita buat masukin data ke program ==
void inputUser(int &budget, int &kebutuhan, int &ramMin, int &storageMin) {
    start();

    cout << endl;
    cout << "<===== Sesuaikan Budget =====>\n";
    cout << "=> Contoh: 20 jt\n";
    cout << ">>Budget (juta): ";
    cin >> budget;

    cout << endl;
    cout << "<===== Fokus Kemana? =====>\n";
    cout << "=> 1. Office\n";
    cout << "=> 2. Coding\n";
    cout << "=> 3. Gaming\n";
    cout << ">>Pilih: ";
    cin >> kebutuhan;

    cout << endl;
    cout << "<===== Ram Minimal =====>\n";
    cout << ">>RAM minimal (GB): ";
    cin >> ramMin;

    cout << endl;
    cout << "<===== Storage Minimal =====>\n";
    cout << ">>Storage minimal (GB): ";
    cin >> storageMin;
}

int hitungSkor(Laptop lp, int kebutuhan) {
    if (kebutuhan == 1) return lp.skorOffice;
    if (kebutuhan == 2) return lp.skorCoding;
    if (kebutuhan == 3) return lp.skorGaming;
    return 0;
}


// Ini logika utama program kita (pahamin ini aja kalo yang lain yang penting tau fungsi nya buat apa)
void rekomendasiLaptop(Laptop laptop[], int n, int budget, int kebutuhan, int ramMin, int storageMin) {
    int skorTerbaik = -1;
    int indexTerbaik = -1;

    for (int i = 0; i < n; i++) {
        if (laptop[i].harga <= budget &&
            laptop[i].ram >= ramMin &&
            laptop[i].storage >= storageMin) {

            int skor = hitungSkor(laptop[i], kebutuhan);
            

            if (kebutuhan == 1) {          
                skor += laptop[i].ram * 1;
            }
            else if (kebutuhan == 2) {     
                skor += laptop[i].ram * 2;
            }
            else if (kebutuhan == 3) {    
                skor += laptop[i].ram * 3;
            }

            skor += laptop[i].storage / 256;

            if (skor > skorTerbaik) {   
                skorTerbaik = skor;
                indexTerbaik = i;
            }
        }
    }

    cout << "\n<===== HASIL REKOMENDASI =====>\n";
    if (indexTerbaik == -1) {
        cout << "Tidak ada laptop yang sesuai kriteria.\n";
    } else {
        cout << "Laptop       : " << laptop[indexTerbaik].nama << endl;
        cout << "Harga        : " << laptop[indexTerbaik].harga << " juta\n";
        cout << "RAM          : " << laptop[indexTerbaik].ram << " GB\n";
        cout << "Storage      : " << laptop[indexTerbaik].storage << " GB\n";
        cout << "Skor AI      : " << skorTerbaik << endl;
        cout << "<===== Kesimpulan =====>\n";
        cout << endl;
        cout << "Skor terbaik untuk rekomendasi mu adalah " << skorTerbaik << " dari laptop " << laptop[indexTerbaik].nama << endl;
    }
}

// main function
int main() {
    Laptop laptop[28];
    int n; // ngikut init laptop

    int budget, kebutuhan, ramMin, storageMin;

    // manggil function
    initLaptop(laptop, n);
    inputUser(budget, kebutuhan, ramMin, storageMin);
    rekomendasiLaptop(laptop, n, budget, kebutuhan, ramMin, storageMin);
}
