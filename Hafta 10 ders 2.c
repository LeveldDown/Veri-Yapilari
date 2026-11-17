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
