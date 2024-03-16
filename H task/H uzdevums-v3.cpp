/******************************************************************

Aleksandra Dmitruka, ad22069


Izveidot programmu valodā C++.  Ar faila komponenti tiek saprasts fiksēta garuma ieraksts. Sīkākās prasības sk. Laboratorijas darbu noteikumos.

H13. Doti divi bināri faili f1 un f2, kuru komponentes ir ieraksti ar struktūru: atslēga (int), vārds (nepārsniedz 30 simbolus). Failu komponentes sakārtotas atslēgu pieaugšanas secībā.
Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3  tā, lai arī f3 komponentes būtu atslēgu pieaugšanas secībā (failos  nedrīkst parādīties divas komponentes ar vienādu atslēgu vērtību).
Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.

Programma izveidota: 23.04.2023
Mainīta: 25.04.2023 // Uzlabota datu korektumu kontrole ar map

********************************************************************/

#include<iostream>
#include <fstream>
#include<cstring>
#include <string>
#include <map>
using namespace std;

const int WORDLENGTH = 30;

class Component{
int key;
char word[WORDLENGTH+1];

public:

void fillFromMapPair(const pair<int,string>& pair) {
key = pair.first;
string str = pair.second;
strcpy(word, str.c_str());}

void write(ofstream &fout){
fout.write((char*)this, sizeof(Component));
}


void print(){
cout <<key<<' '<<word<< endl;
}

void printfile(ifstream &fin){
fin.read((char*)this, sizeof(Component));
while(fin){
    print();
    fin.read((char*)this, sizeof(Component));
}

}



int getKey(){
return key;
}


void mergeFiles(const char* file1, const char* file2, const char* outfile) {
    Component c1, c2;
    bool ok;
    ifstream f1(file1, ios::binary);
    ifstream f2(file2, ios::binary);
    ofstream fout(outfile, ios::binary);
    f1.read(reinterpret_cast<char*>(&c1), sizeof(Component));
    f2.read(reinterpret_cast<char*>(&c2), sizeof(Component));


    while (!f1.eof() && !f2.eof()) {

        if (c1.getKey() < c2.getKey()) {
            fout.write(reinterpret_cast<const char*>(&c1), sizeof(Component));
            f1.read(reinterpret_cast<char*>(&c1), sizeof(Component));
        }
        else if (c1.getKey() > c2.getKey()) {
            fout.write(reinterpret_cast<const char*>(&c2), sizeof(Component));
            f2.read(reinterpret_cast<char*>(&c2), sizeof(Component));
        } else{
            fout.write(reinterpret_cast<const char*>(&c1), sizeof(Component));
            f1.read(reinterpret_cast<char*>(&c1), sizeof(Component));
            f2.read(reinterpret_cast<char*>(&c2), sizeof(Component));


        }

    }




    while (!f1.eof()) {




        fout.write(reinterpret_cast<const char*>(&c1), sizeof(Component));
        f1.read(reinterpret_cast<char*>(&c1), sizeof(Component));}

    while (!f2.eof()) {


        fout.write(reinterpret_cast<const char*>(&c2), sizeof(Component));
        f2.read(reinterpret_cast<char*>(&c2), sizeof(Component));}

    f1.close();
    f2.close();
    fout.close();
}



};



int main(){
int kk;

do{
map<int, string> file1;
map<int, string> file2;

int yes;
int key;
string word;

cout<<"F1 INPUT"<<endl;

 do{


 cout<<"Key:";
 cin>>key;
 cin.ignore();
  do{
    cout << "Enter the word(max 30 letters): ";
    getline(cin,word);
    if((word.size())>30){
        cout<<"The word is too huge, try again!"<<endl;
    }
    }while(word.size()>30);


 file1.insert(pair<int,string> (key,word));


 cout<<"Want to enter another pair: yes(1) or no (0)" <<endl;
 cin>>yes;

 }while(yes==1);


ofstream outfile("f1.bin", ios::binary);
    if (!outfile.is_open()) {
        cout << "Error opening  file" <<endl;
        return -1;
    }

    map<int, string>::iterator it;
    Component c;

    for (it = file1.begin(); it != file1.end(); ++it) {

        c.fillFromMapPair(*it);

        c.write(outfile);
    }

    outfile.close();



 ifstream f2;
 f2.open("f1.bin", ios::binary);
 if(!f2){cout <<"Nav faila"<< endl; return -1;}
 cout<<"Faila f1 saturs"<<endl;
 c.printfile(f2);
 cout<<endl;
 f2.close();



 int yes2;

cout<<"F2 INPUT"<<endl;



 do{


 cout<<"Key:";
 cin>>key;
 cin.ignore();
  do{
    cout << "Enter the word(max 30 letters): ";
    getline(cin,word);
    if((word.size())>30){
        cout<<"The word is too huge, try again!"<<endl;
    }
    }while(word.size()>30);


 file2.insert(pair<int,string> (key,word));


 cout<<"Want to enter another pair: yes(1) or no (0)" <<endl;
 cin>>yes2;

 }while(yes2==1);



ofstream outfile2("f2.bin", ios::binary);
    if (!outfile2.is_open()) {
        cout << "Error opening  file" <<endl;
        return -1;
    }


    Component c2;

    for (it = file2.begin(); it != file2.end(); ++it) {

        c2.fillFromMapPair(*it);

        c2.write(outfile2);
    }

    outfile2.close();



 ifstream f3;
 f3.open("f2.bin", ios::binary);
 if(!f3){cout <<"Nav faila"<< endl; return -1;}
 cout<<"Faila f2 saturs"<<endl;
 c2.printfile(f3);
 cout<<endl;
 f3.close();



 Component comp3;
 comp3.mergeFiles("f1.bin","f2.bin","f3.bin");

 ifstream f5;
 f5.open("f3.bin", ios::binary);
 if(!f5){cout <<"Nav faila"<< endl; return -4;}
 cout<<"Faila f3 saturs:"<<endl;
 comp3.printfile(f5);
 f5.close();



cout << " Enter 0 to exit or 1 to continue" << endl;
cin >> kk;
cin.ignore();
}while(kk==1); // ļauj izpildīt programmu atkārtoti






}


 /********************************

 *
 *    Ievads failā f1  |  Ievads failā f2   |          Programmas vēlamā reakcija          |                    Rezultāts C++
 * --------------------+--------------------+----------------------------------------------+------------------------------------------------------
 *       9 lapsa       |     8 gulbis       |                 8 gulbis                     |
 *                     |                    |                 9 lapsa                      |                          +
 * --------------------|--------------------|----------------------------------------------|------------------------------------------------------
 *       10 zakis      |     10 kakis       |                 10 zakis                     |                          +
 * --------------------|--------------------|----------------------------------------------|------------------------------------------------------
 *       3 suns        |     1 lacis        |                  1 lacis                     |
 *       4 vilks       |     2 varna        |                  2 varna                     |
 *                     |     4 zilonis      |                  3 suns                      |                          +
 *                     |     5 zvirbulis    |                  4 vilks                     |
                       |                    |                  5 zvirbulis                 |
 *---------------------|--------------------|----------------------------------------------|-------------------------------------------------------
 *                     |                    |                                              |
 *       1 oooooooooo  |    --------        |                                              |                          +
 *       oooooooooooo  |                    |             kļūdas paziņojums                |
 *       ooooooooo     |                    |       "The word is too huge, try again!"     |
 *---------------------|--------------------|----------------------------------------------|-------------------------------------------------------




 *******************************/




