#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void uppercase(char *s){
    while(*s !='\0'){
        *s=(isalpha(*s) && islower(*s))? toupper(*s):*s;
        s++;
    }
}
int main(){
    int sum_teks=0,j,i,pk,pt,sum_key=0;
    char teks[100],key[100];
    char plainteks[100],newkey[100],newkey_1[100],enc[100],des[100];
    
    printf("Masukkan pesan : ");
    gets(teks);
    printf("Masukkan kunci : ");
    gets(key);
    
    printf("\n|============================|\n");
    //==========================
    //===== plainteks menghilangkan spasi ==============
    pt=strlen(teks);
    pk=strlen(key);
    for(i=0,j=0; i<pt;i++){
        if(teks[i]!=' '){
            plainteks[j]=teks[i];
            sum_teks++;
            j++;
        }
    }

    for(i=0,j=0; i<pk;i++){
        if(key[i]!=' '){
            newkey_1[j]=key[i];
            sum_key++;
            j++;
        }
    }
    // printf("%d ",sum_key);
    printf("\nKey \t  : ");
    for(i=0; i<sum_key;i++){
        printf("%c ",newkey_1[i]);
        // printf("%d ",i);
    }
    //===== key ===========
    for(i=0,j=0;i<sum_teks;i++,j++){
        if(j==sum_key){
            j=0;
        }
        newkey[i]=newkey_1[j];
    }
    newkey[i]='\0';
    
    //=============================
    //menampilkan dalam bentuk carakter besar
    uppercase(plainteks);
    
    printf("\nPlainteks : ");
    for(i=0; i<sum_teks;i++){
        printf("%c ",plainteks[i]);
    }
    
    uppercase(newkey);
    printf("\nKey \t  : ");
    for(i=0; i<sum_teks;i++){
        printf("%c ",newkey[i]);
    }
    //=============================================
    //===== menampilkan hasil ebcripsi dan deskripsi
    printf("\n|============================|\nenkripsi : ");
    for(i=0; i<sum_teks;i++){
        enc[i]=((plainteks[i]+newkey[i])%26)+'A';
        printf("%c",enc[i]);
    }

    printf("\ndeskripsi : ");
    for(i=0; i<sum_teks;i++){
        des[i]=(((enc[i]-newkey[i])+26)%26)+'A';
        printf("%c",des[i]);
    }
    printf("\n|============================|");
}