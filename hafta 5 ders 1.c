/*geçen halttaki şeye küçükten büyüğe
eleman ekleyen fonksiyonu yazdır
    /* arasındaki haltlar bu soru 
       üzerine eklenen kısımlar
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* dugumOlustur(int veri) {

	struct Node* yeni =(struct Node*)malloc(sizeof(struct Node));

	yeni->data= veri;
	yeni->next= NULL;

	return yeni;
}

void listeYazdir(struct Node* bas) {
	struct Node* temp=bas;
	printf("bağlı listedeki elemanlar \n");
	while(temp!=NULL) {
		printf("%d-->", temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void listeSil(struct Node* bas) {
	struct Node* temp=bas;
	while(temp!=NULL) {
		struct Node* sil=temp;
		temp=temp->next;
		free(sil);
	}
}

struct Node* basaEkle(struct Node* bas, int veri) {
	struct Node* yeni=dugumOlustur(veri);
	yeni->next=bas;
	return yeni;
}

struct Node* sonaEkle(struct Node* bas, int veri) {
	struct Node* yeni=dugumOlustur(veri);
	if(bas==NULL)
		return yeni;
	struct Node* temp=bas;
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=yeni;
	return bas;
}
/*
struct Node* sirayaEkle(struct Node* bas, int veri) {
	struct Node* yeni = dugumOlustur(veri);

	if (bas == NULL || veri <= bas->data) {
		yeni->next = bas;
		return yeni;
	}

 struct Node* temp = bas;
    while (temp->next != NULL && temp->next->data < veri) {
        temp = temp->next;
    }

    yeni->next = temp->next;
    temp->next = yeni;

    return bas;
}
*/

	int main() {

		struct Node* head = NULL;

		head=basaEkle(head,10);
		head=sonaEkle(head,20);
		head=basaEkle(head,40);
		
		/*
		head=sirayaEkle(head,10);
		head=sirayaEkle(head,5);
		head=sirayaEkle(head,20);
		head=sirayaEkle(head,15);
        */
		listeYazdir(head);
	}
