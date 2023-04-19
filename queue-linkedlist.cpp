#include <iostream>
using namespace std;
typedef struct node *alamat;
typedef struct node {
    int data;
    alamat next;
} node;

typedef struct {
    alamat front;
    alamat back;
    int count;
} queue;
queue antri;

void init(queue* q) {
    q->front = NULL;
    q->back = NULL;
    q->count = 0;
}

void enqueue(int orang, queue* q) {
    alamat baru = new node;
    baru->data = orang;
    baru->next = NULL;
    if (q->count == 0) {
        q->front = baru;
        q->back = baru;
    } else {
        q->back->next = baru;
        q->back = baru;
    }
    ++(q->count);
}

void dequeue(queue* q, int orang) {
    if (q->count == 0) {
        cout << "Maaf antrian kosong" << endl;
    } else {
        --(q->count);
        alamat lama = q->front;
        orang = lama->data;
        cout << orang << " dipanggil CS" << endl;
        q->front = lama->next;
        delete lama;
    }
}



void view(queue* q) {
    if (q->count == 0) {
        cout << "Maaf antrian kosong" << endl;
    } else {
        alamat temp = q->front;
        cout << "Isi antrian: ";
        for (int i = 0; i < q->count; ++i) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
}

int main() {
    int orang;
    init(&antri);
    enqueue(10, &antri);
    enqueue(12, &antri);
    enqueue(16, &antri);
    view(&antri);
    dequeue(&antri, orang);
    view(&antri);
    dequeue(&antri, orang);
    view(&antri);
    dequeue(&antri, orang);
    view(&antri);
}