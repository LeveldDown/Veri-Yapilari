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
    }
    return kuyruk[bas];
}
void yazdir(){
    //kuyruk boş mu kontrolü yapılır
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
}
