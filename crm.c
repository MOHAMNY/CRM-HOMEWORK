#include <stdio.h>
#include <limits.h>

#define MAKS_MUSTERI 10
#define MAKS_TEMSILCI 10
#define MAKS_KAMPANYA 100
#define MAKS_BUTCE 10000

int musteri_sayisi, temsilci_sayisi;
int uygunluk_matrisi[MAKS_MUSTERI][MAKS_TEMSILCI];
int dp_yonlendirme[MAKS_MUSTERI][1 << MAKS_TEMSILCI];

int kampanya_sayisi, butce;
int maliyet[MAKS_KAMPANYA], getiri[MAKS_KAMPANYA];
int dp_kampanya[MAKS_KAMPANYA + 1][MAKS_BUTCE + 1];
 
int en_iyi_eslesme(int musteri_index, int temsilci_mask) {
    if (musteri_index >= musteri_sayisi)
        return 0;

    if (dp_yonlendirme[musteri_index][temsilci_mask] != -1)
        return dp_yonlendirme[musteri_index][temsilci_mask];

    int en_iyi_skor = INT_MIN;

    for (int t = 0; t < temsilci_sayisi; t++) {
        if (!(temsilci_mask & (1 << t))) { 
            int yeni_mask = temsilci_mask | (1 << t);
            int skor = uygunluk_matrisi[musteri_index][t] + en_iyi_eslesme(musteri_index + 1, yeni_mask);
            if (skor > en_iyi_skor)
                en_iyi_skor = skor;
        }
    }

    return dp_yonlendirme[musteri_index][temsilci_mask] = en_iyi_skor;
}
 
int en_iyi_kampanya_secimi() {
    for (int i = 0; i <= kampanya_sayisi; i++) {
        for (int b = 0; b <= butce; b++) {
            if (i == 0 || b == 0) {
                dp_kampanya[i][b] = 0;
            } else if (maliyet[i - 1] <= b) {
                dp_kampanya[i][b] = (getiri[i - 1] + dp_kampanya[i - 1][b - maliyet[i - 1]] > dp_kampanya[i - 1][b]) 
                                     ? getiri[i - 1] + dp_kampanya[i - 1][b - maliyet[i - 1]] 
                                     : dp_kampanya[i - 1][b];
            } else {
                dp_kampanya[i][b] = dp_kampanya[i - 1][b];
            }
        }
    }
    return dp_kampanya[kampanya_sayisi][butce];
}

int main() {
    printf("Musteri sayisini girin: ");
    scanf("%d", &musteri_sayisi);
    printf("Temsilci sayisini girin: ");
    scanf("%d", &temsilci_sayisi);

    printf("Musteri-Temsilci uygunluk matrisini girin (%dx%d):\n", musteri_sayisi, temsilci_sayisi);
    for (int i = 0; i < musteri_sayisi; i++) {
        for (int j = 0; j < temsilci_sayisi; j++) {
            scanf("%d", &uygunluk_matrisi[i][j]);
        }
    }

    for (int i = 0; i < MAKS_MUSTERI; i++)
        for (int j = 0; j < (1 << MAKS_TEMSILCI); j++)
            dp_yonlendirme[i][j] = -1;

    printf("En iyi musteri-temsilci eslesme puani: %d\n", en_iyi_eslesme(0, 0));

    printf("Kampanya sayisini girin: ");
    scanf("%d", &kampanya_sayisi);
    printf("Butceyi girin: ");
    scanf("%d", &butce);

    printf("Her kampanyanin maliyetini ve beklenen getirisini girin:\n");
    for (int i = 0; i < kampanya_sayisi; i++) {
        printf("Kampanya %d (Maliyet Getiri): ", i + 1);
        scanf("%d %d", &maliyet[i], &getiri[i]);
    }

    printf("Maksimum yatirim getirisi: %d\n", en_iyi_kampanya_secimi());

    return 0;
}