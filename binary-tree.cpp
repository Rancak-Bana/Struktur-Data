#include <iostream>
using namespace std;
typedef struct node* alamat;

// struct untuk node binary tree
struct node {
    int data;
    alamat kiri;
    alamat kanan;
};

// fungsi untuk membuat node baru
alamat alokasi(int datanya) {
    alamat hasil = new node;
    hasil->data = datanya;
    hasil->kiri = NULL;
    hasil->kanan = NULL;
    return hasil;
}

// fungsi untuk menambahkan node baru ke binary tree
alamat insert(alamat node, int data) {
    if (node == NULL) {
        return alokasi(data);
    }

    if (data < node->data) {
        node->kiri = insert(node->kiri, data);
    } else if (data > node->data) {
        node->kanan = insert(node->kanan, data);
    }

    return node;
}

// fungsi untuk menampilkan isi binary tree secara inorder
void inorder(alamat node) {
    if (node != NULL) {
        inorder(node->kiri);
        cout << node->data << endl;
        inorder(node->kanan);
    }
}

// fungsi untuk menghapus semua node di dalam binary tree
void clear(alamat node) {
    if (node != NULL) {
        clear(node->kiri);
        clear(node->kanan);
        delete node;
    }
}

// fungsi utama
int main() {
    alamat root = NULL;

    // menambahkan node baru ke binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // menampilkan isi binary tree secara inorder
    cout << "Inorder : " << endl;
    inorder(root);
    cout << endl;

    // menghapus semua node di dalam binary tree
    clear(root);
    root = NULL;
}