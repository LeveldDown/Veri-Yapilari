#include <stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top==MAX-1;
}

void push(int veri){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=veri;
    printf("%d yığına eklendi\n", veri);
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d yığından çıkarıdı\n", stack[top]);
    top--;
}

void peek(){
    if(isEmpty()){
        printf("Yığın boş\n");
        return;
    }
    printf("en üstteki eleman : %d\n", stack[top]);
}

void Yazdir(){
    if(isEmpty()){
        printf("yığın bos yazdırılacak eleman yok\n");
        return;
    }
    printf("en yukarıdan aşağıya yığın elemanları : \n");
    for(int i=top; i>=0; i--){
        printf("%d\n", stack[i]);
    }
}

int main(){
    push(19);
    push(20);
    push(30);
    Yazdir();
    peek();
    
    pop();
    pop();
    Yazdir();
    push(50);
    push(70);
    push(80);
    push(100);
    Yazdir();
    push(40);
    Yazdir();
}
