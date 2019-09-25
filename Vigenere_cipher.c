#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int sum_teks=0,j,i,pk,pt,sum_key=0,n,t;
char teks[100],key[100],isi_file[100],c;
char plainteks[100],newkey[100],newkey_1[100],enc[100],des[100];
FILE *f; 

void uppercase(char *s){
    while(*s !='\0'){
        *s=(isalpha(*s) && islower(*s))? toupper(*s):*s;
        s++;
    }
}
void delete_spasi_teks(int pt){
    for(i=0,j=0; i<pt;i++){
        if(teks[i]!=' '&&teks[i]!='.'&&teks[i]!=','){
            plainteks[j]=teks[i];
            sum_teks++;
            j++;
        }
    }
}
void delete_spasi_enc(int pt){
    for(i=0,j=0; i<pt;i++){
        if(teks[i]!=' '&&teks[i]!='.'&&teks[i]!=','){
            enc[j]=teks[i];
            sum_teks++;
            j++;
        }
    }
}
void delete_spasi_key(int pk){
    for(i=0,j=0; i<pk;i++){
        if(key[i]!=' '&&key[i]!='.'&&key[i]!=','){
            newkey_1[j]=key[i];
            sum_key++;
            j++;
        }
    }
}
void cetak_key(){
    printf("\nKey \t  : ");
    for(i=0; i<sum_key;i++){
        printf("%c ",newkey_1[i]);
    }
}
void ubah_key(){
    for(i=0,j=0;i<sum_teks;i++,j++){
        if(j==sum_key){
            j=0;
        }
        newkey[i]=newkey_1[j];
    }
    newkey[i]='\0';
}
void encrip(){
    for(i=0; i<sum_teks;i++){
        enc[i]=((plainteks[i]+newkey[i])%26)+'A';
        printf("%c",enc[i]);
        

    }
}
void deskripsi(){
    printf("\nDeskripsi : ");
    for(i=0; i<sum_teks;i++){
        des[i]=(((enc[i]-newkey[i])+26)%26)+'A';
        printf("%c",des[i]);
    }
}
int main(){
    do{
        printf("1. deskripsi ke enkripsi \n");
        printf("2. enkripsi ke deskripsi \n");
        printf("3. file \n");
        printf("0 keluar \n");
        printf("==========================\n");
        printf("Masukkan pilihan : ");
        scanf("%d",&n);
        switch (n){
            case 1 : 
                printf("==========================\n");
                printf("Masukkan pesan deskripsi : ");
                gets(teks);
                gets(teks);
                printf("Masukkan kunci : ");
                gets(key);
                printf("\n|============================|\n");
                //==========================
                //===== plainteks menghilangkan spasi ==============
                pt=strlen(teks);
                pk=strlen(key);
                delete_spasi_teks(pt);
                delete_spasi_key(pk);
                // printf("%d ",sum_key);
                cetak_key();
                //===== key ===========
                ubah_key();
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
                f= fopen("encription.txt","w");
                if(!f){
                    printf("EROR : File tidak dapat terbuat!!!");
                    exit(EXIT_FAILURE);
                }
                //=============================================
                //===== menampilkan hasil encripsi
                printf("\n|============================|\nenkripsi  : ");
                encrip();
                fputs(enc,f);
                fclose(f);
                printf("\n|============================|");
            break;
            case 2 :
                printf("==========================\n");
                printf("Masukkan pesan enkripsi : ");
                gets(teks);
                gets(teks);
                printf("Masukkan kunci : ");
                gets(key); 
                printf("\n|============================|\n");
                //==========================
                //===== plainteks menghilangkan spasi ==============
                pt=strlen(teks);
                pk=strlen(key);
                delete_spasi_enc(pt);
                delete_spasi_key(pk);
                cetak_key();
                //===== key ===========
                ubah_key();
                //=============================
                //menampilkan dalam bentuk carakter besar
                uppercase(enc);
                printf("\nEnkripsi : ");
                for(i=0; i<sum_teks;i++){
                    printf("%c ",enc[i]);
                }
                uppercase(newkey);
                printf("\nKey \t  : ");
                for(i=0; i<sum_teks;i++){
                    printf("%c ",newkey[i]);
                }
                f= fopen("description.txt","w");
                if(!f){
                    printf("EROR : File tidak dapat terbuat!!!");
                    exit(EXIT_FAILURE);
                }
                //=============================================
                //===== menampilkan hasil descripsi
                deskripsi();
                fputs(des,f);
                fclose(f);
                printf("\n|============================|");
                break;
            case 3:
                do{
                    printf("1. file deskripsi ke enkripsi \n");
                    printf("2. file enkripsi ke deskripsi \n");
                    printf("0 keluar \n");
                    printf("==========================\n");
                    printf("Masukkan pilihan : ");
                    scanf("%d",&t);
                    if(t==1){
                        printf("==========================\n");
                        printf("Masukkan nama file : ");
                        gets(isi_file);
                        gets(isi_file);
                        f=fopen(isi_file,"r");
                        if(!f){
                            printf("EROR : File tidak ditemukan!!!");
                            exit(EXIT_FAILURE);
                        }
                        i=0;
                        while((c=getc(f)) !=-1){
                            teks[i] = c;
                            i++;
                        }
                        printf("Masukkan kunci : ");
                        gets(key);
                        pt=strlen(teks);
                        pk=strlen(key);
                        delete_spasi_teks(pt);
                        delete_spasi_key(pk);
                        // printf("%d ",sum_key);
                        cetak_key();
                        //===== key ===========
                        ubah_key();
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
                        f= fopen("encription.txt","w");
                        if(!f){
                            printf("EROR : File tidak dapat terbuat!!!");
                            exit(EXIT_FAILURE);
                        }
                        //=============================================
                        //===== menampilkan hasil encripsi
                        printf("\n|============================|\nenkripsi  : ");
                        encrip();
                        fputs(enc,f);
                        fclose(f);
                        printf("\n|============================|");
                    }else if(t==2){
                        printf("==========================\n");
                        printf("Masukkan nama file : ");
                        gets(isi_file);
                        gets(isi_file);
                        f=fopen(isi_file,"r");
                        if(!f){
                            printf("EROR : File tidak ditemukan!!!");
                            exit(EXIT_FAILURE);
                        }
                        i=0;
                        while((c=getc(f)) !=-1){
                            teks[i] = c;
                            i++;
                        }
                        printf("Masukkan kunci : ");
                        gets(key);
                        printf("\n|============================|\n");
                        //==========================
                        //===== plainteks menghilangkan spasi ==============
                        pt=strlen(teks);
                        pk=strlen(key);
                        delete_spasi_enc(pt);
                        delete_spasi_key(pk);
                        cetak_key();
                        //===== key ===========
                        ubah_key();
                        //=============================
                        //menampilkan dalam bentuk carakter besar
                        uppercase(enc);
                        printf("\nEnkripsi : ");
                        for(i=0; i<sum_teks;i++){
                            printf("%c ",enc[i]);
                        }
                        uppercase(newkey);
                        printf("\nKey \t  : ");
                        for(i=0; i<sum_teks;i++){
                            printf("%c ",newkey[i]);
                        }
                        f= fopen("description.txt","w");
                        if(!f){
                            printf("EROR : File tidak dapat terbuat!!!");
                            exit(EXIT_FAILURE);
                        }
                        //=============================================
                        //===== menampilkan hasil descripsi
                        deskripsi();
                        fputs(des,f);
                        fclose(f);
                        printf("\n|============================|");
                    }else if(t==0){
                        printf("|========== TERIMAKASIH SAMPAI JUMPA ==========|");

                        exit(EXIT_FAILURE);
                    }
                }while(t<0||t>2);
            break;
            case 0 :
            printf("|========== TERIMAKASIH SAMPAI JUMPA ==========|");
            break;
        }
    }while(n<0||n>3);
}