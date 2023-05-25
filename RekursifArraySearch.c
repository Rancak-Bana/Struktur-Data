#include<stdio.h>

int data[15]={78,79,7,8,32,1,2,34,5,6,7,89,32,90,100};
int indketemu,nilai;
int search(int dicari, int jmlIndex){
    if(jmlIndex==0) {return -1;}
    if(data[jmlIndex-1]==dicari){return jmlIndex;}
    return search(dicari,jmlIndex-1);
}

main(){
    printf("masukan nilai yang akan dicari:");
    scanf("%d",&nilai);
    indketemu=search(nilai,14);
    if (indketemu==-1){
        printf("data tidak ditemukan");
    }else{
            printf("ditemukan pada elemen ke %d",indketemu);
    }
}
