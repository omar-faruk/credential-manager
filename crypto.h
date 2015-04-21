#include <bits/stdc++.h>
#ifndef CRYPTO_H
#define CRYPTO_H
#endif // CRYPTO_H
using namespace std;

string encrypt(string data,int key){

    string encryptedData;
    for(int i=0;i<int(data.size());i++){
        encryptedData+=data[i]^key;
    }
    return encryptedData;
}
string decrypt(string data,int key){

    string decryptedData;
    for(int i=0;i<int(data.size());i++){
        decryptedData+=data[i]^key;
    }
    return decryptedData;
}

bool entryNotFound(string site,string user,int key ){

    string esite,euser,epass;
    fstream din("data//db.o",std::ios_base::in);

    while(din>>esite>>euser>>epass){
        if(decrypt(esite,key)==site && decrypt(euser,key)==user){
            return false;
            break;
        }
    }
    return true;
}
