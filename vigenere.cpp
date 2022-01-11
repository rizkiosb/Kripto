#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Vig {
   public:
      string k;
   Vig(string k) {
      for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            this->k += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            this->k += k[i] + 'A' - 'a';
      }
   }
   string encryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c + k[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
   string decryption(string t) {
      string output;
      for (int i = 0, j = 0; i < t.length(); ++i) {
         char c = t[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         output += (c - k[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % k.length();
      }
      return output;
   }
};
int main() {
   string key;
   int pilih;
   char pilihan;
   cout << "\nMasukkan Kata Kunci: ";
   getline(cin, key);
   Vig v(key);// key

   do{
   cout << "Pilih salah satu dengan masukkan angka:\n";
   cout << "1.Enkripsi \n";
   cout << "2.Dekripsi \n";
   cout << "3.Tutup Program \n";

   cout << "Pilih : ";
   cin>> pilih;
      
      if(pilih==1){
         ifstream file("plainteks.txt");
         string text( (istreambuf_iterator<char>(file) ),(istreambuf_iterator<char>() ) );
         ofstream enc("enkripsi.txt");
         string plainteks ="";//plaintext
         for(int i = 0; i < text.size(); i++){
            plainteks+=text[i];
         }
         string encrypt = v.encryption(plainteks);
         enc<<encrypt;
         enc.close();
         cout << "Isi Pesan : "<<plainteks<< endl;
         cout << "Kunci Pesan : "<<key<< endl;
         cout << "Pesan enkripsi berhasil disimpan"<< endl;

         cout << "Apakah anda ingin memilih pilihan lain y/t: ";
         cin >> pilihan;
         if(pilihan=='t'){
            break;
         }

      }
      else if(pilih==2){
         ifstream file("enkripsi.txt");
         string text( (istreambuf_iterator<char>(file) ),(istreambuf_iterator<char>() ) );//ambil kalimat enkripsi dari file
         ofstream dec("dekripsi.txt");
         string enkripsi ="";
         for(int i = 0; i < text.size(); i++){
            enkripsi+=text[i];//baca enkripsi dari file
         }
         string decrypt = v.decryption(enkripsi);
         dec<<decrypt;
         dec.close();
         cout << "Pesan berhasil di dekripsi: "<< endl;
         cout << "Kunci Pesan : "<<key<< endl;
         cout << "Apakah anda ingin memilih pilihan lain y/t: ";
         cin >> pilihan;
         if(pilihan=='t'){
            break;
         }

      }
      else if(pilih==3){
         cout<<"\n====TERIMA KASIH TERLAH MENCOBA PROGRAM====";
         break;
      }
      else{
         cout<<"Pilihan tidak terdaftar, Coba lagi !!";
      }
   }while(pilih>=3 ||pilih<=1);
   
}