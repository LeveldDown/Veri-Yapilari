/* Soru 1:
Tek yönlü bağlı liste kullanılarak bir öncelikli kuyruk oluşturulmuştur.
kuyrukta en yüksek önceliğe sahip kaç eleman bulunduğunu
hesaplayan enYuksekOncelikliSay() fonksiyonunu yaziniz. */

/*
#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    int oncelik;
    struct Dugum* sonraki;
};

int enYuksekOncelikSay(struct Dugum* head) {
    if (head == NULL) {
        return 0;
    }
    int enYuksekOncelik = head->oncelik;
    int sayac = 0;
    struct Dugum* gecici = head;
    while (gecici != NULL && gecici->oncelik == enYuksekOncelik) {
        sayac++;
        gecici = gecici->sonraki;
    }

    return sayac;
}
struct Dugum* yeniDugumOlustur(int veri, int oncelik) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->oncelik = oncelik;
    yeni->sonraki = NULL;
    return yeni;
}
int main(){
    
    struct Dugum* head = yeniDugumOlustur(10, 5);
    head->sonraki = yeniDugumOlustur(20, 5);              
    head->sonraki->sonraki = yeniDugumOlustur(30, 3);       
    head->sonraki->sonraki->sonraki = yeniDugumOlustur(40, 1);

    int sonuc = enYuksekOncelikSay(head);
    
    printf("Kuyrukta en yuksek oncelige sahip eleman sayisi: %d\n", sonuc);
    struct Dugum* gecici;
    while (head != NULL) {
        gecici = head;
        head = head->sonraki;
        free(gecici);
    }

    return 0;
}
*/

/* Soru 2:
tek yönlü bağlı liste kullanılarak bir kuyruk oluşturunuz. kuyrukta
bulunan toplam eleman sayısını hesaplayan int elemanSay() fonks. yaz.
*/

#include <stdio.h>
#include <stdlib.h>
struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

int elemanSay(struct Dugum* head) {
    int sayac = 0;
    struct Dugum* gecici = head;

    while (gecici != NULL) {
        sayac++;
        gecici = gecici->sonraki;
    }

    return sayac;
}

struct Dugum* yeniDugumOlustur(int veri) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->veri = veri;
    yeni->sonraki = NULL;
    return yeni;
}

int main() {
    
    struct Dugum* head = yeniDugumOlustur(10);
    head->sonraki = yeniDugumOlustur(20);
    head->sonraki->sonraki = yeniDugumOlustur(30);
    head->sonraki->sonraki->sonraki = yeniDugumOlustur(40);
    
    int toplamEleman = elemanSay(head);
    
    printf("Kuyrukta bulunan toplam eleman sayisi: %d\n", toplamEleman);
    
    struct Dugum* gecici;
    while (head != NULL) {
        gecici = head;
        head = head->sonraki;
        free(gecici);
    }

    return 0;
}
