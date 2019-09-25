#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
    char abjad;
    int i,j;
    char isi[5][5];
    // for (int abjad ='A';abjad <='Z'; abjad++){
    //     printf("%c ",abjad);
    // }
    abjad ='A';
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){           
            isi[i][j]=abjad;
            printf("%c ",isi[i][j]);
            abjad++;
        }
        printf("\n");
    }
}