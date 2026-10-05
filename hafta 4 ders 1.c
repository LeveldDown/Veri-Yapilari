#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
    
    
};
int main(){
    
    struct Node* head= NULL;
    struct Node* birinci=(struct Node*)malloc(sizeof(struct Node));
    birinci->data=11;
    birinci->next=NULL;
    head=birinci;
    
    struct Node* ikinci=(struct Node*)malloc(sizeof(struct Node));
    ikinci->data=5;
    ikinci->next=NULL;
    birinci->next=ikinci;
    
    struct Node* ucuncu=(struct Node*)malloc(sizeof(struct Node));
    ucuncu->data=28;
    ucuncu->next=NULL;
    ikinci->next=ucuncu;
    
    printf("bağlı listedeki elemanlar : \n");
    
    struct Node* temp=head;
    
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
temp=head;
while(temp!=NULL){
    struct Node* sil=temp;
    temp=temp->next;
    free(sil);
}
}

/*
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* elemanEkle(struct Node* head, int veri) {
    struct Node* yeniDugum = (struct Node*)malloc(sizeof(struct Node));
    yeniDugum->data = veri;
    yeniDugum->next = NULL;

    if (head == NULL) {
        return yeniDugum;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = yeniDugum;
    
    return head;
}

void listeyiYazdir(struct Node* head) {
    printf("bağlı listedeki elemanlar : \n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* listeyiTemizle(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* sil = temp;
        temp = temp->next;
        free(sil);
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;

    head = elemanEkle(head, 11);
    head = elemanEkle(head, 5);
    head = elemanEkle(head, 28);

    listeyiYazdir(head);

    head = listeyiTemizle(head);

    return 0;
}
*/
