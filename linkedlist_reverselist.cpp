#include <bits/stdc++.h>
using namespace std;

typedef struct Node *address;

// Struktur node untuk linked list
struct Node {
    int number;
    address next;
};

// Fungsi untuk membuat node baru
address createNode(int number) {
    address newNode = (address)malloc(sizeof(struct Node));
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node ke bagian terakhir pada linked list
void addLast(address* head, char number) {
    if (*head == NULL) {
        *head = createNode(number);
    } else {
        address temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = createNode(number);
    }
    
}

// Fungsi untuk menambahkan node ke bagian awal pada linked list
void addFirst(address* head, char number) {
    // answer
    if (*head == NULL) {
        *head = createNode(number);
    } else {
        address temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = createNode(number);
    }
}

// Fungsi untuk menambahkan node ke bagian awal pada linked list
address reverseList(address head) {
    // answer
    if (head == NULL) {
        return head;
    }
    address prev = NULL;
    address curr = head;
    while (curr!= NULL) {
        address next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    
}

// Fungsi untuk mencetak linked list
void printList(address head) {
    // answer
    while (head != NULL) {
        printf("%d", head->number);
        if(head->next != NULL) {
            printf(" ");
        }
        head = head->next;
    }
}

int main() {
    int n;
    int number;
    address head = NULL;

    // Input jumlah data yang akan dimasukkan ke linked list
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        
        // Menambahkan inputan ke linked list
        addLast(&head, number);
    }

    // Mencetak linked list
    address ans = reverseList(head);
    printList(ans);

    return 0;
}

