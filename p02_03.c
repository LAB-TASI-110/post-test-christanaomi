#include <stdio.h>

// fungsi untuk menampilkan menu makanan
void tampilMenuMakanan() {
    printf("\n===== MENU MAKANAN =====\n");
    printf("1. PKL (Pisang Kulit Lumpia)  : Rp 5000\n");
    printf("2. Bakwan                     : Rp 2000\n");
    printf("3. Tempe                      : Rp 2000\n");
    printf("4. Batagor                    : Rp 7000\n");
    printf("5. RIA (Roti Isi Ayam)        : Rp 8000\n");
    printf("6. Sosis                      : Rp 5000\n");
    printf("7. Nugget                     : Rp 6000\n");
    printf("8. Gabin                      : Rp 4000\n");
}

// fungsi untuk menampilkan menu minuman
void tampilMenuMinuman() {
    printf("\n===== MENU MINUMAN =====\n");
    printf("9. Kopi                       : Rp 5000\n");
    printf("10. Capucinno                 : Rp 8000\n");
    printf("11. Lemon Tea                 : Rp 6000\n");
    printf("12. Teh Manis                 : Rp 4000\n");
    printf("13. Matcha                    : Rp 9000\n");
}

// fungsi untuk menentukan harga berdasarkan pilihan
int ambilHarga(int pilihan) {

    if(pilihan == 1) return 5000;
    else if(pilihan == 2) return 2000;
    else if(pilihan == 3) return 2000;
    else if(pilihan == 4) return 7000;
    else if(pilihan == 5) return 8000;
    else if(pilihan == 6) return 5000;
    else if(pilihan == 7) return 6000;
    else if(pilihan == 8) return 4000;
    else if(pilihan == 9) return 5000;
    else if(pilihan == 10) return 8000;
    else if(pilihan == 11) return 6000;
    else if(pilihan == 12) return 4000;
    else if(pilihan == 13) return 9000;
    else return 0;

}

// fungsi untuk menentukan nama menu
void namaMenu(int pilihan) {

    if(pilihan == 1) printf("PKL (Pisang Kulit Lumpia)");
    else if(pilihan == 2) printf("Bakwan");
    else if(pilihan == 3) printf("Tempe");
    else if(pilihan == 4) printf("Batagor");
    else if(pilihan == 5) printf("RIA (Roti Isi Ayam)");
    else if(pilihan == 6) printf("Sosis");
    else if(pilihan == 7) printf("Nugget");
    else if(pilihan == 8) printf("Gabin");
    else if(pilihan == 9) printf("Kopi");
    else if(pilihan == 10) printf("Capucinno");
    else if(pilihan == 11) printf("Lemon Tea");
    else if(pilihan == 12) printf("Teh Manis");
    else if(pilihan == 13) printf("Matcha");

}

int main() {

    int pilihan;
    int jumlah;
    int harga;
    int total = 0;
    char lagi;

    printf("=====================================\n");
    printf("        KAFETARIA IT DEL\n");
    printf("=====================================\n");

    tampilMenuMakanan();
    tampilMenuMinuman();

    printf("\nSilahkan memesan...\n");

    do {

        printf("\nMasukkan nomor menu : ");
        scanf("%d", &pilihan);

        harga = ambilHarga(pilihan);

        if(harga == 0) {
            printf("Menu tidak tersedia!\n");
        }
        else {

            printf("Jumlah pesanan : ");
            scanf("%d", &jumlah);

            printf("\nPesanan : ");
            namaMenu(pilihan);
            printf(" x %d", jumlah);

            printf("\nSubtotal : Rp %d\n", harga * jumlah);

            total = total + (harga * jumlah);
        }

        printf("\nTambah pesanan lagi? (y/n) : ");
        scanf(" %c", &lagi);

    } while(lagi == 'y' || lagi == 'Y');

    printf("\n\n========== STRUK BELANJA ==========\n");
    printf("Kafetaria IT Del\n");
    printf("-----------------------------------\n");
    printf("Total Pembayaran : Rp %d\n", total);
    printf("-----------------------------------\n");
    printf("Terima kasih telah berbelanja\n");
    printf("===================================\n");

    return 0;
}