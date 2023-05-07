#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXSTACK 5

/*
    Lengkapilah fungsi dan prosedur yang masih kosong dengan parameter yang tersedia
    1. isEmpty untuk mereturn nilai boolean
    2. pop untuk mengeluarkan stack dan menampilkan pesan
    3. lihat untuk melihat stack paling atas
    4. cetak untuk mencetak stack
*/
typedef struct
{
    char data[MAXSTACK][50];
    int count;
} Stack;
Stack stack;

void push(Stack *stack, char *element)
{
    strcpy(stack->data[stack->count], element);
    stack->count++;
}

bool isEmpty(Stack *stack)
{
    if(stack->count == 0)
    {
        return true;
    }
    return false;
}

char *pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack kosong\n");
    }
    stack->count--;
    printf("Berhasil Mengeluarkan %s\n", stack->data[stack->count]);
    return stack->data[stack->count];
}

void lihat(Stack *stack)
{
    printf("Paling atas: %s\n", stack->data[stack->count - 1]);
}
void cetak(Stack *stack)
{
    printf("\n");
    for (int i = stack->count - 1; i >= 0; i--)
    {
        printf("%s\n", stack->data[i]);
    }
}

int main()
{
    /*
        ==========TIDAK PERLU MERUBAH MAIN==========
        kalian hanya perlu mengisi fungsi dan prosedur yang kosong
    */
    char a[50];
    for (int i = 0; i < 5; i++)
    {
        // Memasukkan Stack
        scanf("%s", &a);
        push(&stack, a);
    }
    // Mencetak stack
    cetak(&stack);
    // Melihat tumpukan paling atas
    lihat(&stack);
    // Mengeluarkan stack
    pop(&stack);
    lihat(&stack);
    return 0;
}
