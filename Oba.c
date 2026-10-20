#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
};

struct Dugum* dugumOlustur(int veri) {
    struct Dugum* yeniDugum = (struct Dugum*)malloc(sizeof(struct Dugum));
    if (yeniDugum == NULL) {
        printf("Bellek tahsis hatasi!\n");
        exit(1);
    }
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    return yeniDugum;
}

struct Dugum* sonaEkleDairesel(struct Dugum* bas, int veri) {
    struct Dugum* yeniDugum = dugumOlustur(veri);
    if (bas == NULL) {
        bas = yeniDugum;
        yeniDugum->sonraki = bas;
    } else {
        struct Dugum* gecici = bas;
        while (gecici->sonraki != bas) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
        yeniDugum->sonraki = bas;
    }
    return bas;
}

struct Dugum* sonaEkleDogrusal(struct Dugum* bas, int veri) {
    struct Dugum* yeniDugum = dugumOlustur(veri);
    if (bas == NULL) {
        bas = yeniDugum;
    } else {
        struct Dugum* gecici = bas;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeniDugum;
    }
    return bas;
}

void listeYazdir(struct Dugum* bas) {
    if (bas == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Dugum* gecici = bas;
    int dairesel = 0;
    
    while (gecici != NULL) {
        if (gecici->sonraki == bas) {
            dairesel = 1;
            break;
        }
        gecici = gecici->sonraki;
    }
    
    gecici = bas;
    if (dairesel) {
        do {
            printf("%d -> ", gecici->veri);
            gecici = gecici->sonraki;
        } while (gecici != bas);
        printf("(basa dondu)\n");
    } else {
        while (gecici != NULL) {
            printf("%d -> ", gecici->veri);
            gecici = gecici->sonraki;
        }
        printf("NULL\n");
    }
}

struct Dugum* listeleriBirlestir(struct Dugum* daireselBas, struct Dugum* dogrusalBas) {
    if (daireselBas == NULL || dogrusalBas == NULL) return daireselBas;
    
    struct Dugum* daireselSon = daireselBas;
    while (daireselSon->sonraki != daireselBas) {
        daireselSon = daireselSon->sonraki;
    }
    
    struct Dugum* dogrusalSon = dogrusalBas;
    while (dogrusalSon->sonraki != NULL) {
        dogrusalSon = dogrusalSon->sonraki;
    }
    
    daireselSon->sonraki = dogrusalBas;
    dogrusalSon->sonraki = daireselBas;
    
    return daireselBas;
}

struct Dugum* bellekSerbestBirak(struct Dugum* daireselBas) {
    if (daireselBas == NULL) return NULL;
    
    struct Dugum* gecici = daireselBas;
    while (gecici->sonraki != daireselBas) {
        gecici = gecici->sonraki;
    }
    gecici->sonraki = NULL;
    
    struct Dugum* simdiki = daireselBas;
    while (simdiki != NULL) {
        struct Dugum* sonraki = simdiki->sonraki;
        free(simdiki);
        simdiki = sonraki;
    }
    return NULL;
}

int main() {
    struct Dugum* daireselBas = NULL;
    struct Dugum* dogrusalBas = NULL;
    
    daireselBas = sonaEkleDairesel(daireselBas, 10);
    daireselBas = sonaEkleDairesel(daireselBas, 20);
    daireselBas = sonaEkleDairesel(daireselBas, 30);
    daireselBas = sonaEkleDairesel(daireselBas, 40);
    daireselBas = sonaEkleDairesel(daireselBas, 50);
    
    dogrusalBas = sonaEkleDogrusal(dogrusalBas, 60);
    dogrusalBas = sonaEkleDogrusal(dogrusalBas, 70);
    dogrusalBas = sonaEkleDogrusal(dogrusalBas, 80);
    dogrusalBas = sonaEkleDogrusal(dogrusalBas, 90);
    
    printf("Dairesel liste:\n");
    listeYazdir(daireselBas);
    
    printf("\nDogrusal liste:\n");
    listeYazdir(dogrusalBas);
    
    daireselBas = listeleriBirlestir(daireselBas, dogrusalBas);
    
    printf("\nBirlestirilmis dairesel liste:\n");
    listeYazdir(daireselBas);
    
    daireselBas = bellekSerbestBirak(daireselBas);
    
    return 0;
}
