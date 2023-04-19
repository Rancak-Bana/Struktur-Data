#include <iostream>
// jumlah bangku/antriannya 5
#define maxqueue 5
using namespace std;

typedef struct {
  int front;          // memegang data terdepan untuk dequeue
  int back;           // memegang data terakhir untuk enqueue
  int count;          // menghitung banyak data pada antrian
  int data[maxqueue]; // data/bangku ke berapa
} queue;
queue antri;

// menginisialisasi queue, *q menyimpan alamat &antri
void init(queue *q) {
  q->front = 0;
  q->back = 0;
  q->count = 0;
}

// mengisi bangku dengan kondisi apakah bangku penuh/tidak
void enqueue(int orang, queue *q) {
  if (q->count == maxqueue) {
    cout << "Maaf antrian penuh" << endl;
  } else {
    // q->back karena antrian dibuat selalu ++ maka dipanggil data yang memegang back
    q->data[q->back] = orang;
    // butuh hitungan agar balik lagi ke bangku[0], dengan mod
    q->back = (q->back + 1) % maxqueue;
    // misal antrian penuh dan front ada di bangku[0] dan di-dequeue,
    // maka ketika orang datang akan mengisi bangku[0]/back, caranya 4 + 1 = 5, 5 mod 5 = 0R
    ++(q->count);
  }
}

// dequeue mengeluarkan orang dari bangku dengan kondisi apakah kosong/tidak
void dequeue(queue *q, int orang) {
  if (q->count == 0) {
    cout << "Maaf antrian kosong" << endl;
  } else {
    --(q->count);
    orang = q->data[q->front];
    cout << orang << " dipanggil CS" << endl;
    q->front = (q->front + 1) % maxqueue;
  }
}




void view(queue *q) {
  if (q->count == 0) {
    cout << "Maaf antrian kosong" << endl;
  } else {
    int i = q->front;
    cout << "Isi antrian: ";
    for (int j = 0; j < q->count; ++j) {
      cout << q->data[i] << " ";
      i = (i + 1) % maxqueue;
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