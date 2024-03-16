/******************************************************************

Aleksandra Dmitruka, ad22069

Izveidot programmu valodā C++, kas apstrādā teksta failu secīgā režīmā.
Dati no faila jānolasa pa vienai rindiņai. Nedrīkst dublēt visa faila saturu operatīvajā atmiņā.

F15. Dots teksta fails, kurā atrodas sintaktiski pareizs C++ programmas teksts.
Uzrakstīt programmu, kura saskaita, cik dažādu bibliotēku (#include) iekļauts dotajā programmā. Drīkst uzskatīt,
ka programmas tekstā nav komentāru un ka attiecīgie simboli neparādīsies teksta literāļos.

Programma izveidota: 26.02.2023

********************************************************************/

#include<iostream>
#include <fstream>

using namespace std;
int main()
{

int ok;
do
{
int count=0;

/****
Realizācija ar ierobežoto simbolu skaitu

fstream f;
char name [21]; // izmantojam char masīvu, jo .open metode pieprasa const char* filename
cout<<"Enter your file name (max 20 letters):"<<endl;
cin.getline(name, 21);
f.open(name,ios::in);
****/

fstream f;
string line;
string lib ="#include";

do{

string filename;
cout<<"Enter file name with its extension :"<<endl;
getline(cin,filename);
f.open (filename.c_str(), ios::in);


if(!f){
cout<<"There is no such file or its name was entered incorrectly!"<<endl;
}

}while(!f); //Nodrošina ieejas datu korektumu

 // Realizē secīgās nolasīšanas shēmu failam
getline(f, line);
    while(f){


       if(line.find(lib)!= string::npos) count++; // izmanto find(), jo divas bibliotēkas nevar būt vienā rindā

     getline(f, line);
    }
f.close();

cout<<"Library count in the following text document is"<<" "<<count<<endl;

cout << " Enter 0 to exit or 1 to continue" << endl;
cin >> ok;
cin.ignore();//sāk no tukšas plūsmas(ignorē ENTER)


 }while (ok == 1); ////lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1

}


 /********************************

 *
 *        Ievads       |                     Programmas vēlamā reakcija                    |                    Rezultāts C++
 * --------------------+-------------------------------------------------------------------+----------------------------------------------------------------
 *       test1.txt     |                                4                                  |                          +
 *       test2.txt     |                                1                                  |                          +
 *       test3.txt     |                                0                                  |                          +
 *       test4.txt     |                              Kļūda                                |            Izdod paziņojumu "There is no such file"



 *******************************/

