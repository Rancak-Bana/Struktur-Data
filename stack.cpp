#include <iostream>
#define maxstack 4
using namespace std;
struct stack{
    int data[maxstack];
    int count;
}; stack a;

void inisialisasi(stack *s){
    s->count = 0;
}

bool isFull(stack *s){
    if(s->count == maxstack){
        return true;
    }else{
        return false;
    }
}

void push(int masuk, stack *s){
    if(isFull(s)){
        cout << "Stack penuh";
    }else{
        s->data[s->count] = masuk;
        ++(s->count);
    }
}

bool isEmpty(stack *s){
    if(s->count == 0){
        return true;
    }else{
        return false;
    }
}

void pop(stack *s, int ambil){
    if(isEmpty(s)){
        cout << "Stack kosong";
    }else{
       --(s->count);
       ambil = s->data[s->count];
cout << "nilai terambil adalah " << ambil << endl;
       s->data[s->count] = 0;
    }
}

void cetak(stack *s){
    for(int i=0; i<maxstack; i++){
        cout << s->data[i] << endl;
    }
}

int main(){
    int ambil;
    inisialisasi(&a);
    push(5, &a);
    push(4, &a);
    push(15, &a);
    pop(&a, ambil);
    pop(&a, ambil);
    pop(&a, ambil);
    cetak(&a);
}