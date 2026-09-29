#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kargo{
    
    int takipNumarasi;
    float agirlik;
    float gonderimUcreti;
    int teslimDurumu;
    
};

void kargoKontrol(struct Kargo *k){
    if(k->agirlik>10.0){
        k->gonderimUcreti += (k->gonderimUcreti * 0.20);
    }
    
    if(k->teslimDurumu == 0){
        printf("Kargo teslimat bekliyor.\n");
    }
    
    printf("Kargo Bilgileri:\n");
    printf("Takip Numarası: %d\n", k->takipNumarasi);
    printf("Ağırlık: %.2f\n", k->agirlik);
    printf("Ücret: %.2f TL\n", k->gonderimUcreti);
    
    printf("Kargo Teslimat Durumu:\n");
    if(k->teslimDurumu == 1){
        printf("Teslimat Gerçekleşti!\n");
    }
    else{
        printf("Teslimat Gerçekleşmedi...\n");
    }
    
}

int main(){
    
    struct Kargo *kptr = (struct Kargo*)malloc(sizeof(struct Kargo));
    
    if(kptr == NULL){
        printf("Bellek Hatası!");
        return 1;
    }
    
    printf("Takip Numarası: ");
    scanf("%d", &kptr->takipNumarasi);
    
    printf("Ağırlık: ");
    scanf("%f", &kptr->agirlik);
    
    printf("Ücret: ");
    scanf("%f", &kptr->gonderimUcreti);
    
    printf("Kargo Teslimat Durumu (1 ise evet 0 ise hayır): ");
    scanf("%d", &kptr->teslimDurumu);
    
    kargoKontrol(kptr);
    
    free(kptr);
    
}