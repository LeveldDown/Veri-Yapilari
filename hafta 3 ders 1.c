/*
#include <stdio.h>
#include <string.h>

struct Ogrenci{
int numara;
char ad[30]
;
float not;
};

int main(){
    struct Ogrenci ogr1;
    struct Ogrenci ogr2;
    
    ogr1.numara = 101;
    ogr1.not = 85.5;
    //ogr1.ad = "Ayse";
    strcpy(ogr1.ad, ogr2.ad);
    
    printf("Numara: %d\n", ogr1.numara);
    printf("Ad: %s\n", ogr1.ad);
    printf("Not: %.2f\n", ogr1.not);
}
*/

/*Soru:
*Cihaz adında bir yağı tanımlayınız.
*Yapıda ürün adı, marka, fiyat ve stok miktarı bilgileri bulunsun.
*Bir cihazın bilgilerini kullanıcıdan alınız.
*Cihaz bilgilerini ekrana yazdıran cihazYazdir() fonks. yazın.
*Ayrıca fiyatı 5000 TL den büyük olan cihazlara %5 indirim uygulayan ve
indirimli fiyatı ekrana yazdıran indirimliFiyatGoster() fonk. oluştur.
*/

/*
#include <stdio.h>
#include <string.h>

struct Cihaz{
    char urun[50];
    char marka[50];
    float fiyat;
    int stok;
};

void cihazYazdir(struct Cihaz c){
    printf("Cihaz Bilgileri:");
    printf("Urun Adi: %s\n", c.urun);
    printf("Marka: %s\n", c.marka);
    printf("Fiyat: %.2f\n", c.fiyat);
    printf("Stok Adedi: %d\n", c.stok);
}

void indirimliFiyatGoster(struct Cihaz c){
    if (c.fiyat > 5000.0) {
        float indirimliFiyat = c.fiyat - (c.fiyat * 0.05);
        printf("Fiyat 5000 TL'den buyuk oldugu icin %%5 indirim uygulanmistir.\n");
        printf("Indirimli Fiyat: %.2f TL\n", indirimliFiyat);
}
    else {
        printf("Fiyat 5000 TL veya altinda oldugu icin indirim uygulanmamistir.\n");
    }
}

int main(){
    struct Cihaz c1;
    
    printf("Cihaz bilgilerini giriniz:\n");
    
    printf("Urun Adi: ");
    scanf(" %[^\n]s", c1.urun);
    
    printf("Marka: ");
    scanf(" %[^\n]s", c1.marka);
    
    printf("Fiyat (TL): ");
    scanf("%f", &c1.fiyat);
    
    printf("Stok Miktari: ");
    scanf("%d", &c1.stok);


    cihazYazdir(c1);
    
    printf("\n--- Kampanya Bilgisi ---\n");
    indirimliFiyatGoster(c1);
}
*/
