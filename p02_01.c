#include <stdio.h>

int getOngkirPerKg(const char kode[]) {
    if (kode[0] == 'M' && kode[1] == 'D' && kode[2] == 'N' && kode[3] == '\0')
        return 8000;
    if (kode[0] == 'B' && kode[1] == 'L' && kode[2] == 'G' && kode[3] == '\0')
        return 5000;
    if (kode[0] == 'J' && kode[1] == 'K' && kode[2] == 'T' && kode[3] == '\0')
        return 12000;
    if (kode[0] == 'S' && kode[1] == 'B' && kode[2] == 'Y' && kode[3] == '\0')
        return 13000;

    return -1;
}

void getNamaKota(const char kode[], char nama[]) {
    if (kode[0] == 'M' && kode[1] == 'D' && kode[2] == 'N' && kode[3] == '\0') {
        sprintf(nama, "Medan");
    } else if (kode[0] == 'B' && kode[1] == 'L' && kode[2] == 'G' && kode[3] == '\0') {
        sprintf(nama, "Balige");
    } else if (kode[0] == 'J' && kode[1] == 'K' && kode[2] == 'T' && kode[3] == '\0') {
        sprintf(nama, "Jakarta");
    } else if (kode[0] == 'S' && kode[1] == 'B' && kode[2] == 'Y' && kode[3] == '\0') {
        sprintf(nama, "Surabaya");
    } else {
        sprintf(nama, "Tidak Diketahui");
    }
}

int isLuarPulau(const char kode[]) {
    if ((kode[0] == 'J' && kode[1] == 'K' && kode[2] == 'T' && kode[3] == '\0') ||
        (kode[0] == 'S' && kode[1] == 'B' && kode[2] == 'Y' && kode[3] == '\0')) {
        return 1;
    }
    return 0;
}

float hitungBeratUcok(float beratButet) {
    return 1.5f * beratButet;
}

float hitungSubtotal(float berat, int ongkir) {
    return berat * ongkir;
}

float hitungDiskon(float berat, float subtotal) {
    if (berat > 10.0f) {
        return subtotal * 0.10f;
    }
    return 0.0f;
}

float hitungTotal(float subtotal, float diskon) {
    return subtotal - diskon;
}

void cetakDetailPaket(const char namaPengirim[], float berat, int ongkir, int luarPulau) {
    float subtotal, diskon, total;
    char statusAsuransi[20];

    subtotal = hitungSubtotal(berat, ongkir);
    diskon = hitungDiskon(berat, subtotal);
    total = hitungTotal(subtotal, diskon);

    if (luarPulau) {
        sprintf(statusAsuransi, "Gratis");
    } else {
        sprintf(statusAsuransi, "Tidak");
    }

    printf("| %-30s |\n", namaPengirim);
    printf("| Berat Paket        : %10.2f kg |\n", berat);
    printf("| Ongkir / Kg        : Rp %8d |\n", ongkir);
    printf("| Subtotal           : Rp %8.2f |\n", subtotal);
    printf("| Diskon             : Rp %8.2f |\n", diskon);
    printf("| Asuransi           : %10s |\n", statusAsuransi);
    printf("| Total Bayar        : Rp %8.2f |\n", total);
    printf("+--------------------------------+\n");
}

void cetakStruk(const char kodeKota[], float beratButet, int nomorTransaksi) {
    char namaKota[30];
    int ongkir, luarPulau;
    float beratUcok;

    ongkir = getOngkirPerKg(kodeKota);

    if (ongkir == -1) {
        printf("\n");
        printf("+================================+\n");
        printf("|       STRUK DEL-EXPRESS        |\n");
        printf("+================================+\n");
        printf("| Transaksi ke-%-18d |\n", nomorTransaksi);
        printf("| Kode kota tidak valid          |\n");
        printf("+================================+\n");
        return;
    }

    getNamaKota(kodeKota, namaKota);
    luarPulau = isLuarPulau(kodeKota);
    beratUcok = hitungBeratUcok(beratButet);

    printf("\n");
    printf("+================================+\n");
    printf("|         DEL-EXPRESS            |\n");
    printf("|      STRUK PENGIRIMAN          |\n");
    printf("+================================+\n");
    printf("| Transaksi ke-%-18d |\n", nomorTransaksi);
    printf("| Tujuan   : %-19s |\n", namaKota);
    printf("| Kode     : %-19s |\n", kodeKota);
    printf("+================================+\n");

    cetakDetailPaket("Paket Butet", beratButet, ongkir, luarPulau);
    cetakDetailPaket("Paket Ucok", beratUcok, ongkir, luarPulau);

    printf("| Promo Lebaran:                  |\n");
    printf("| - Diskon 10%% jika > 10 kg       |\n");
    printf("| - Asuransi gratis luar pulau    |\n");
    printf("+================================+\n");
}

int isEnd(const char kode[]) {
    return (kode[0] == 'E' && kode[1] == 'N' && kode[2] == 'D' && kode[3] == '\0');
}

int main() {
    char kodeKota[10];
    float beratButet;
    int nomorTransaksi = 1;

    while (1) {
        scanf("%s", kodeKota);

        if (isEnd(kodeKota)) {
            break;
        }

        scanf("%f", &beratButet);

        cetakStruk(kodeKota, beratButet, nomorTransaksi);
        nomorTransaksi++;
    }

    printf("\nTerima kasih telah menggunakan Del-Express.\n");

    return 0;
}
