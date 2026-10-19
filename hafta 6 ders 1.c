#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* onceki;
    struct Dugum* sonraki;
};

struct Dugum* dugumOlustur(int a) {
    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));

    if (yeni == NULL) {
        printf("bellekten yer ayrılamadı\n");
        exit(1);
    }
    yeni->veri = a;
    yeni->onceki = NULL;
    yeni->sonraki = NULL;

    return yeni;
}

struct Dugum* basaEkle(struct Dugum* head, int a) {
    struct Dugum* yeni = dugumOlustur(a);
    
    yeni->sonraki = head;
    
    if (head != NULL) {
        head->onceki = yeni;
    }
    return yeni;
}

struct Dugum* sonaEkle(struct Dugum* head, int a) {
    struct Dugum* yeni = dugumOlustur(a);
    
    if (head == NULL) {
        return yeni;
    }
    struct Dugum* temp = head;
    
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }
    temp->sonraki = yeni;
    yeni->onceki = temp;
    
    return head;
}

void listeYazdir(struct Dugum* head) {
    struct Dugum* temp = head;
    
    while (temp != NULL) {
        printf("<=> %d ", temp->veri);
        temp = temp->sonraki;
    }
    printf("<=> NULL\n");
}

void listeTerstenYazdir(struct Dugum* head) {
    struct Dugum* temp = head;
    
    if (temp == NULL) {
        printf("liste bos\n");
        return;
    }
    while (temp->sonraki != NULL) {
        temp = temp->sonraki;
    }
    
    printf("NULL");
    while (temp != NULL) {
        printf(" <=> %d", temp->veri);
        temp = temp->onceki;
    }
    printf("\n");
}
void listeyiSerbestBirak(struct Dugum* head){
    struct Dugum* temp=head;
    
    while(temp!=NULL){
        struct Dugum* sil=temp;
        temp=temp->sonraki;
        free(sil);
    }
}

int main() {
    struct Dugum* head = NULL;
    
    head = basaEkle(head, 10);
    head = basaEkle(head, 20);
    head = basaEkle(head, 30);
    head = basaEkle(head, 40);
    
    head = sonaEkle(head, 8);
    head = sonaEkle(head, 4);
    head = sonaEkle(head, 2);
    
    printf("Duz Liste:\n");
    listeYazdir(head);
    
    printf("\nTersten Liste:\n");
    listeTerstenYazdir(head);

    return 0;
}
/*
//tek yönlü dairesel bağlı liste
#include <stdio.h>
#include <stdlib.h>

struct Dugum{
    int veri;
    struct Dugum* sonraki;
};
struct Dugum* dugumOlustur(int a){
    struct Dugum* yeni=malloc(sizeof(struct Dugum));
    
    if(yeni==NULL){
        printf("bellekten yer ayrılamadı");
        exit(1);
    }
    yeni->veri=a;
    yeni->sonraki=NULL;
    
    return yeni;
}
struct Dugum* basaEkle(struct Dugum* head, int a){
    struct Dugum* yeni=dugumOlustur(a);
    
    if(head==NULL){
        yeni->sonraki=yeni;
        
        return yeni;
    }
    struct Dugum* temp=head;
    while(temp->sonraki!=head){
        temp=temp->sonraki;
    }
    yeni->sonraki=head;
    temp->sonraki=yeni;
    
    return yeni;
}
void listeYazdir(struct Dugum* head){
    if(head==NULL){
        printf("liste bos yazdirilacak eleman bulunamadi");
        return;
    }
    struct Dugum* temp=head;
    
    do{
        printf("%d -> ", temp->veri);
        temp=temp->sonraki;
    }
    while(temp!=head);
    
    printf("liste basa döndü\n");
}
int main(){
    struct Dugum* head = NULL;
    
    head = basaEkle(head, 1);
    head = basaEkle(head, 25);
    head = basaEkle(head, 33);
    head = basaEkle(head, 40);
    head = basaEkle(head, 8);
    head = basaEkle(head, 24);
    head = basaEkle(head, 5);
    
    listeYazdir(head);

    return 0;
}
*/
