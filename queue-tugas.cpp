#include <iostream>
#define maxqueue 9
using namespace std;

typedef struct
{
    int front;
    int rear;
    int count;
    int data[maxqueue];
} queue;
queue antri;

void init(queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

void enqueue(int orang, queue *q)
{
    if (q->count == maxqueue)
    {
        cout << "Maaf kursi penuh" << endl;
    }
    else
    {
        q->data[q->rear] = orang;
        q->rear = (q->rear + 1) % maxqueue;
        ++(q->count);
    }
}

void dequeue(queue *q, int orang)
{
    if (q->count == 0)
    {
        cout << endl
             << "Maaf kursi tidak ada yang mengisi" << endl;
    }
    else
    {
        --(q->count);
        orang = q->data[q->front];
        cout << orang << " dipanggil CS" << endl;
        q->front = (q->front + 1) % maxqueue;
    }
}

void view(queue *q)
{
    if (q->count == 0)
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        int i = q->front;
        cout << "Isi antrian: ";
        for (int j = 0; j < q->count; j++)
        {
            cout << q->data[i] << " ";
            i = (i + 1) % maxqueue;
        }
        cout << endl
             << endl;
    }
}

int main()
{
    int orang;
    init(&antri);
    for (int i = 0; i < 12; i++)
    {
        enqueue(i+1, &antri);
        dequeue(&antri, orang);
    }
}