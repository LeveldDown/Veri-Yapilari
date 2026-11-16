/*
#include <stdio.h>
#include <stdbool.h>
#define BOYUT 5

int kuyruk[BOYUT];
int bas=0;
int son=-1;
int elemanSayisi=0;

bool kuyrukBosMu(){
    return (elemanSayisi=0);
}

bool kuyrukDoluMu(){
    return(elemanSayisi==BOYUT);
}

void ekle(int veri){
    if(kuyrukDoluMu()){
        printf("kuyruk dolu\n");
    }
    son++;
    kuyruk[son]=veri;
    printf("%d kuyruğa eklendi\n", veri);
}
int cikar(){
    if(kuyrukBosMu()){
        printf("kuyruk bos\n");
    }
    int cikan=kuyruk[bas];
    bas++;
    elemanSayisi--;
    printf("%d kuyruktan çıkarıldı\n", cikan);
    return cikan;
}
int ilkEleman(){
    if(kuyrukBosMu()){
        printf("kuyruk bos\n");
        return -1;
    }
    return kuyruk[bas];
}
void yazdir(){
    //kuyruk boş mu kontrolü yapılır
    if(kuyrukBosMu()){
        printf("kuyruk boş\n");
        return;
    }
    
    printf("kuyruktaki elemanlar :\n");
    for(int i=bas;i<=son;i++){
        printf("%d ", kuyruk[i]);
    }
    printf("\n");
}
int main(){
    ekle(10);
    ekle(20);
    ekle(30);
    
    yazdir();
    
    printf("ilk eleman = %d\n", ilkEleman());
    
    cikar();
    yazdir();
    
    ekle(40);
    ekle(50);
    //ekle(60);
    
    yazdir();
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int veri;
    int oncelik;
    struct Node* next;
};
struct Node* bas = NULL;

bool kuyrukBosMu(){
    return (bas==NULL);
}
//önceliğe göre doğru yere ekleme yapan fonksiyon
void ekle(int veri, int oncelik){
    struct Node* yeni = malloc(sizeof(struct Node));
    yeni->veri = veri;
    yeni->oncelik = oncelik;
    yeni->next = NULL;
    
    //Kuyruk boşsa veya yeni düğümün önceliği baştakinden büyükse başa ekle
    if(bas == NULL || oncelik > bas->oncelik){
        yeni->next = bas;
        bas = yeni;
    }
    else{
        //ortaya veya sona ekleme yapılır
        struct Node* temp = bas;
        
        while(temp->next != NULL && temp->next->oncelik >= oncelik){
            temp = temp->next;
        }
        
        yeni->next = temp->next;
        temp->next = yeni;
    }
    
    printf("%d (oncelik: %d) kuyruga eklendi.\n", veri, oncelik);
}

//en yüksek öncelikli elemanı çıkarır
int cikar(){
    
    if(kuyrukBosMu()){
        printf("Kuyruk bos\n");
        return -1;
    }
    
    struct Node* silinecek = bas;
    int veri = silinecek->veri;
    bas = bas->next;
    
    free(silinecek);
    
    printf("%d kuyruktan cikarildi.\n", veri);
    return veri;
}

//kuyruk elemanlarnı yazdırır
void kuyrukYazdir(){
    
    if(kuyrukBosMu()){
        printf("Kuyruk bos\n");
        return;
    }
    printf("Kuyruk (veri | oncelik): ");
    struct Node* temp = bas;
    while (temp!= NULL){
        printf("[%d | %d] ", temp->veri, temp->oncelik);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    ekle(50, 2);
    ekle(10, 5);
    ekle(40, 3);
    ekle(90, 1);
    kuyrukYazdir();
    cikar();
    kuyrukYazdir();
    
    ekle(77, 4);
    kuyrukYazdir();
}
