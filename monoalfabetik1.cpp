// CPP program for encoding the string
// using classical cipher

#include<bits/stdc++.h>
#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// Function generates the encoded text
string encoder(string key)
{
	string encoded = "";
	// This array represents the
	// 26 letters of alphabets
	bool arr[26] = {0};

	// This loop inserts the keyword
	// at the start of the encoded string
	for (int i=0; i<key.size(); i++)
	{
		if(key[i] >= 'A' && key[i] <= 'Z')
		{
			// To check whether the character is inserted
			// earlier in the encoded string or not
			if (arr[key[i]-65] == 0)
			{
				encoded += key[i];
				arr[key[i]-65] = 1;
			}
		}
		else if (key[i] >= 'a' && key[i] <= 'z')
		{
			if (arr[key[i]-97] == 0)
			{
				encoded += key[i] - 32;
				arr[key[i]-97] = 1;
			}
		}
	}

	// This loop inserts the remaining
	// characters in the encoded string.
	for (int i=0; i<26; i++)
	{
		if(arr[i] == 0)
		{
			arr[i]=1;
			encoded += char(i + 65);
		}
	}
	return encoded;
}

// Function that generates encodes(cipher) the message
string cipheredIt(string msg, string encoded)
{
	string cipher="";

	// This loop ciphered the message.
	// Spaces, special characters and numbers remain same.
	for (int i=0; i<msg.size(); i++)
	{
		if (msg[i] >='a' && msg[i] <='z')
		{
			int pos = msg[i] - 97;
			cipher += encoded[pos];
		}
		else if (msg[i] >='A' && msg[i] <='Z')
		{
			int pos = msg[i] - 65;
			cipher += encoded[pos];
		}
		else
		{
			cipher += msg[i];
		}
	}
	return cipher;
}
string decipheredIt(string msg, string encoded)
{
    // Hold the position of every character (A-Z)
    // from encoded string
    map <char,int> enc;
    for(int i=0; i<encoded.size(); i++)
    {
        enc[encoded[i]]=i;
    }
 
    string decipher="";
 
    // This loop deciphered the message.
    // Spaces, special characters and numbers remain same.
    for (int i=0; i<msg.size(); i++)
    {
        if (msg[i] >='a' && msg[i] <='z')
        {
            int pos = enc[msg[i]-32];
            decipher += plaintext[pos];
        }
        else if(msg[i] >='A' && msg[i] <='Z')
        {
            int pos = enc[msg[i]];
            decipher += plaintext[pos];
        }
        else
        {
            decipher += msg[i];
        }
    }
    return decipher;
}
// Driver code
int main()
{
	// Hold the Keyword
	string key;
    char pilihan;
    int pilih;
	//key = "Computer";
    cout << "Keyword : ";
    getline(cin,key);
	// Function call to generate encoded text
	string encoded = encoder(key);

	do{
        cout << "Pilih salah satu dengan masukkan angka:\n";
        cout << "1.Enkripsi \n";
        cout << "2.Dekripsi \n";
        cout << "3.Tutup Program \n";

        cout << "Pilih : ";
        cin>> pilih;
      
        if(pilih==1){
            ifstream file("plainteks.txt");
            string text((istreambuf_iterator<char>(file)),(istreambuf_iterator<char>()));
            ofstream encry("enkripsi.txt");
            string pesan =" ";//plaintext
            for(int i = 0; i < text.size(); i++){
                pesan+=text[i];
            }
            string message = "";
            cout << "Message before Ciphering : " << pesan << endl;

            // // Function call to print ciphered text
            cout << "Ciphered Text : " << cipheredIt(pesan,encoded) << endl;
            encry << cipheredIt(pesan,encoded);
            cout << "Pesan enkripsi berhasil disimpan"<< endl;

            cout << "Apakah anda ingin memilih pilihan lain y/t: ";
            cin >> pilihan;
            if(pilihan=='t'){
                break;
            }
        }
        else if(pilih==2){
            ifstream filedata("enkripsi.txt");
            string text((istreambuf_iterator<char>(filedata)),(istreambuf_iterator<char>()));
            ofstream decry("dekripsi.txt");
            string enkripsi =" ";//plaintext
            for(int i = 0; i < text.size(); i++){
                enkripsi+=text[i];
            }
        // Function call to print deciphered text
            cout << "Deciphered Text : " << decipheredIt(enkripsi,encoded) << endl;
            decry << decipheredIt(enkripsi, encoded);
            cout << "Pesan dekripsi berhasil disimpan"<< endl;

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
    return 0;

}
