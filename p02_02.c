#include <stdio.h>

int hitungTotalKategori(int stok[], int n, int kategori)
{
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        int posisiKategori = (i % 4) + 1;

        if(posisiKategori == kategori)
        {
            total += stok[i];
        }
    }

    return total;
}

void tampilKategori()
{
    printf("\nKode Kategori Barang\n");
    printf("1 = Dasi SD\n");
    printf("2 = Gula\n");
    printf("3 = Rok Pramuka\n");
    printf("4 = Minyak\n");
}

int main()
{
    int N;
    int kategori;
    
    printf("Masukkan jumlah total data stok: ");
    scanf("%d", &N);

    int stok[N];

    printf("\nMasukkan deret stok barang:\n");
    for(int i = 0; i < N; i++)
    {
        printf("Stok ke-%d : ", i+1);
        scanf("%d", &stok[i]);
    }

    tampilKategori();

    printf("\nMasukkan kode kategori yang ingin dihitung: ");
    scanf("%d", &kategori);

    int total = hitungTotalKategori(stok, N, kategori);

    printf("\nTotal stok kategori yang dipilih = %d\n", total);

    return 0;
}