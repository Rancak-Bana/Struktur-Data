#include <iostream>
using namespace std;
typedef struct node *alamat; // alamatnya yang dibintang bukan node
struct node{
    int data;
    alamat next;
}; alamat first; // first doang

alamat alokasi(int datanya){
    alamat hasil = new node;
    hasil->data = datanya;
    hasil->next = NULL;
    return hasil;
}

void insertfirst(alamat baru){
    baru->next = first; // baru dulu
    first = baru;
}

void deletefirst(){
    alamat temp = first; 
    first = first->next; // first dipindah ke nextnya dia, kalo mau delete pake temp
    delete temp;
}
// method LAST pasti pakai while p
void insertlast(alamat baru){ 
    alamat p = first; 
    while(p->next != NULL){ // jalan sampai ketemu yang nextnya null
        p = p->next;
    } p->next = baru; // isi node baru
}

void deletelast(){
    alamat p = first;
    while(p->next->next != NULL){ // jalan dulu
        p = p->next;
    }
    alamat temp = p->next; // terus delete
    p->next = NULL;
    delete temp;
}

// method AFTER pasti pakai lama
void insertafter(alamat lama, alamat baru){
    baru->next = lama->next;
    lama->next = baru;
}

void deleteafter(alamat lama){
    alamat temp = lama->next;
    lama->next = lama->next->next;
    delete temp;
}

void cetak(){
    alamat p = first;
    while(p != NULL){
        cout << p->data << endl;
        p = p->next;
    }
}

int main(){
     first = alokasi(10);
     insertfirst(alokasi(30));
     insertfirst(alokasi(70));
     insertfirst(alokasi(50));
     insertafter(first->next->next,alokasi(99));
     deleteafter(first);
     cetak();
}