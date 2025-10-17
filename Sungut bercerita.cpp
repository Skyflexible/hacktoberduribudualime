#include <iostream>
#include <string>
#include <vector>
#include <cctype> // Untuk fungsi tolower

// --- Status Global Game ---
// Variabel ini akan melacak progres pemain di seluruh permainan.
bool punyaPedang = false;
bool punyaKunci = false;
bool goblinTerkalahkan = false;
int lokasiSekarang = 0; // 0: Desa, 1: Jalan Setapak, 2: Sungai, 3: Sarang Goblin

// --- Fungsi Bantu ---

// Fungsi untuk membersihkan layar (cross-platform)
void bersihkanLayar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk menampilkan garis pemisah
void garisPemisah() {
    std::cout << "--------------------------------------------------\n";
}

// Fungsi untuk mendapatkan input pemain dan mengubahnya menjadi huruf kecil
std::string dapatkanInput() {
    std::cout << "\n> ";
    std::string input;
    std::getline(std::cin, input);
    for (char &c : input) {
        c = tolower(c);
    }
    return input;
}

// --- Deklarasi Fungsi Lokasi ---
// Kita deklarasikan di sini agar bisa dipanggil dari mana saja.
void mulaiDariDesa();
void pergiKeJalanSetapak();
void menyeberangSungai();
void masukSarangGoblin();


// --- Implementasi Fungsi Lokasi ---

// LOKASI 0: Desa Tenteram
void mulaiDariDesa() {
    bersihkanLayar();
    garisPemisah();
    std::cout << "Kamu berada di Desa Tenteram. Udara terasa damai.\n";
    std::cout << "Di utara, sebuah jalan setapak menuju Hutan Bisikan yang gelap.\n";
    if (!punyaPedang) {
        std::cout << "Di sudut desa ada sebuah gudang tua yang sedikit terbuka.\n";
    }
    garisPemisah();
    std::cout << "Apa yang akan kamu lakukan?\n";
    std::cout << "[1] Pergi ke utara menuju hutan\n";
    if (!punyaPedang) {
        std::cout << "[2] Periksa gudang tua\n";
    }
    std::cout << "[3] Menyerah dan pulang (Keluar dari Game)\n";

    std::string pilihan = dapatkanInput();

    if (pilihan == "1" || pilihan == "utara") {
        lokasiSekarang = 1;
    } else if ((pilihan == "2" || pilihan == "periksa gudang") && !punyaPedang) {
        std::cout << "\nKamu mengintip ke dalam gudang dan menemukan sebuah pedang pendek peninggalan kakekmu.\n";
        std::cout << "Kamu mengambil pedang itu. Ini akan berguna!\n";
        punyaPedang = true;
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
        lokasiSekarang = 0; // Tetap di desa
    } else if (pilihan == "3" || pilihan == "menyerah") {
        std::cout << "\nKamu memutuskan petualangan ini terlalu berat. Desa akan kecewa.\n";
        lokasiSekarang = -1; // Kode untuk keluar
    } else {
        std::cout << "\nPilihan tidak valid. Coba lagi.\n";
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
    }
}

// LOKASI 1: Jalan Setapak Hutan
void pergiKeJalanSetapak() {
    bersihkanLayar();
    garisPemisah();
    std::cout << "Kamu berada di jalan setapak Hutan Bisikan. Pohon-pohon tinggi menjulang.\n";
    std::cout << "Jalan ini bercabang. Ke utara kamu mendengar suara gemericik air sungai.\n";
    std::cout << "Ke selatan kamu bisa kembali ke desa.\n";
    garisPemisah();
    std::cout << "Apa yang akan kamu lakukan?\n";
    std::cout << "[1] Lanjut ke utara menuju sungai\n";
    std::cout << "[2] Kembali ke selatan menuju desa\n";

    std::string pilihan = dapatkanInput();
    if (pilihan == "1" || pilihan == "utara") {
        lokasiSekarang = 2;
    } else if (pilihan == "2" || pilihan == "selatan") {
        lokasiSekarang = 0;
    } else {
        std::cout << "\nPilihan tidak valid. Coba lagi.\n";
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
    }
}

// LOKASI 2: Tepi Sungai
void menyeberangSungai() {
    bersihkanLayar();
    garisPemisah();
    std::cout << "Kamu tiba di tepi sungai yang arusnya cukup deras.\n";
    std::cout << "Ada jembatan tali yang goyang di utara untuk menyeberang.\n";
    std::cout << "Jalan setapak di selatan mengarah kembali ke hutan.\n";
    garisPemisah();
    std::cout << "Apa yang akan kamu lakukan?\n";
    std::cout << "[1] Seberangi jembatan ke utara\n";
    std::cout << "[2] Kembali ke selatan\n";

    std::string pilihan = dapatkanInput();
    if (pilihan == "1" || pilihan == "utara") {
        std::cout << "\nDengan hati-hati, kamu menyeberangi jembatan tali.\n";
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
        lokasiSekarang = 3;
    } else if (pilihan == "2" || pilihan == "selatan") {
        lokasiSekarang = 1;
    } else {
        std::cout << "\nPilihan tidak valid. Coba lagi.\n";
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
    }
}

// LOKASI 3: Sarang Goblin
void masukSarangGoblin() {
    bersihkanLayar();
    garisPemisah();
    std::cout << "Kamu tiba di depan sebuah gua kecil, sarang si goblin.\n";
    
    if (!goblinTerkalahkan) {
        std::cout << "Di dalam, seekor goblin jelek sedang mengagumi artefak yang berkilau!\n";
        std::cout << "Goblin itu melihatmu dan menyeringai licik.\n";
        garisPemisah();
        std::cout << "Apa yang akan kamu lakukan?\n";
        std::cout << "[1] Lawan goblin!\n";
        std::cout << "[2] Coba bernegosiasi\n";
        std::cout << "[3] Lari kembali ke jembatan\n";
        
        std::string pilihan = dapatkanInput();
        if (pilihan == "1" || pilihan == "lawan") {
            if (punyaPedang) {
                std::cout << "\nKamu mencabut pedangmu! Setelah pertarungan singkat, kamu berhasil mengalahkan goblin!\n";
                std::cout << "Goblin itu menjatuhkan sebuah kunci kecil berkarat sebelum pingsan.\n";
                goblinTerkalahkan = true;
                punyaKunci = true;
            } else {
                std::cout << "\nKamu mencoba melawan dengan tangan kosong, tapi goblin itu terlalu kuat.\n";
                std::cout << "Kamu kalah. Petualanganmu berakhir di sini.\n";
                std::cout << "--- GAME OVER ---\n";
                lokasiSekarang = -1; // Keluar dari game
            }
        } else if (pilihan == "2" || pilihan == "negosiasi") {
            std::cout << "\nKamu mencoba berbicara, tapi goblin itu hanya tertawa dan melemparimu dengan batu.\n";
            std::cout << "Kamu terpaksa mundur.\n";
        } else if (pilihan == "3" || pilihan == "lari") {
            std::cout << "\nKamu memutuskan ini terlalu berbahaya dan berlari kembali.\n";
            lokasiSekarang = 2;
        } else {
            std::cout << "\nPilihan tidak valid. Coba lagi.\n";
        }
    } else {
        std::cout << "Sarang ini sekarang sepi. Goblin yang kalah tergeletak di pojok.\n";
        std::cout << "Di tengah ruangan ada sebuah peti kayu terkunci.\n";
        garisPemisah();
        std::cout << "Apa yang akan kamu lakukan?\n";
        std::cout << "[1] Buka peti\n";
        std::cout << "[2] Kembali ke luar\n";

        std::string pilihan = dapatkanInput();
        if (pilihan == "1" || pilihan == "buka peti") {
            if (punyaKunci) {
                std::cout << "\nKamu menggunakan kunci kecil yang didapat dari goblin. Peti itu terbuka!\n";
                std::cout << "Di dalamnya, 'Jantung Hutan' bersinar terang. Kamu berhasil!\n";
                std::cout << "Kamu mengambil artefak itu dan kembali ke desa sebagai pahlawan.\n";
                std::cout << "--- SELAMAT! KAMU MENANG! ---\n";
                lokasiSekarang = -1; // Selesaikan game
            } else {
                std::cout << "\nPeti ini terkunci rapat. Kamu butuh sebuah kunci.\n";
            }
        } else if (pilihan == "2" || pilihan == "kembali") {
            lokasiSekarang = 2;
        } else {
             std::cout << "\nPilihan tidak valid. Coba lagi.\n";
        }
    }

    if(lokasiSekarang != -1) {
        std::cout << "(Tekan Enter untuk melanjutkan...)";
        std::cin.get();
    }
}


// --- Fungsi Main (Loop Utama Game) ---
int main() {
    bersihkanLayar();
    std::cout << "=======================================\n";
    std::cout << "||    PENCARIAN ARTEFAK HILANG     ||\n";
    std::cout << "=======================================\n";
    std::cout << "Selamat datang, petualang! Nasib Desa Tenteram ada di tanganmu.\n";
    std::cout << "(Tekan Enter untuk memulai...)\n";
    std::cin.get();

    while (lokasiSekarang != -1) {
        switch (lokasiSekarang) {
            case 0:
                mulaiDariDesa();
                break;
            case 1:
                pergiKeJalanSetapak();
                break;
            case 2:
                menyeberangSungai();
                break;
            case 3:
                masukSarangGoblin();
                break;
            default:
                std::cout << "Terjadi kesalahan, lokasi tidak ditemukan.\n";
                lokasiSekarang = -1;
                break;
        }
    }

    std::cout << "\nTerima kasih telah bermain!\n";

    return 0;
}
