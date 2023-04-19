#include <iostream>
using namespace std;
typedef struct node *alamat;
struct node{
    alamat prev;
    int data;
    alamat next;
}; alamat first,last; // first dan last

alamat alokasi(int datanya){
    alamat hasil = new node;
    hasil->data = datanya;
    hasil->next = hasil->prev = NULL;
    return hasil;
}

void insertfirst(alamat baru){
    if(first == NULL){
        first = last = baru;
    }else{
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertlast(alamat baru){
    if(first == NULL){
        first = last = baru;
    }else{
        last->next = baru;
        baru->prev = last;
        last = baru;
    }
}

void insertafter(alamat lama, alamat baru){ // lama didapat dari first->next
    baru->next = lama->next;  // ilustrasi: node kanannya->prev
    baru->prev = lama;
    lama->next->prev = baru;
    lama->next = baru;
}

void deletefirst(){
    first = first->next;
    delete first->prev;   
    first->prev = NULL;
}

void deletelast(){
    last = last->prev;
    delete last->next;
    last->next = NULL;
}

void deleteafter(alamat lama){
    lama->next = lama->next->next;
    delete lama->next->prev;
    lama->next->prev = lama;
}
// method tersebut melakukan bypass/nyempil=mengubah prev dan next dari node sebelumnya dan setelahnya

void cetak(){
    alamat p = first;
    while(p != NULL){
        cout << p->data << endl;
        p = p->next;
    }
}

int main(){
    insertlast(alokasi(20));
    insertlast(alokasi(10));
    insertlast(alokasi(30));
    deleteafter(first);
    cetak();
}