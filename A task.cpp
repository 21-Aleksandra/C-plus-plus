/*******************************************

Aleksandra Dmitruka,ad22069

A30. Dots naturāls skaitlis n. Noskaidrot, vai šī skaitļa pirmais cipars
ir vienāds ar pēdējo ciparu (piemēram, 18961). Skaitļa dalīšana ciparos jāveic skaitliski.

Programma izveidota: 14.09.2022
Mainīta: 21.09.22. Uzlabota ieejas datu korektības nodrošināšana
*******************************************/

#include <iostream>
using namespace std;

int main() {

   int ok; 
   do {
    
    long long int num,first,last; // ļauj ievadīt skaitļus,kuri ir lielāki par 2^31, un iegūt pareizo programas reakciju

    do{
  
    cout << "Enter a natural number:";
    cin >> num;

    if(num<=0) { 
        cout<<"Error! Natural numbers belong to the intveral num>0. Please try again."<<endl;
        
    }
    }while(num<=0); //Nodrošina ieejas datu korektumu


    last=num % 10; 

    first=num; // Izveido skaitļa kopiju, kuru var modificēt, un atļauj izmantot oriģinālo skaitli citās darbībās
    
    while(first>=10){
      first=first/10;}  
    

    if (first==last){
        cout<<"The first("<<first<<")and last("<<last<<")digits of a number("<<num<<")ARE equal"<<endl;
    }

    else{
      cout<<"The first("<<first<<")and last("<<last<<")digits of a number(" <<num<< ")AREN'T equal"<<endl;  
      }
    

    cout << endl << "Enter 0 to exit or 1 to continue" << endl;
    cin >> ok;

   } while (ok == 1); //lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1
}



 /********************************

 * 
 *    Ievads   |       Programmas vēlamā reakcija          |                    Rezultāts C++
 * ------------+-------------------------------------------+----------------------------------------------------------------
 *     6       |       Paziņojums "Digits ARE equal"       |                          +
 *    464      |       Paziņojums "Digits ARE equal"       |                          +
 * 399999999997|      Paziņojums "Digits AREN'T equal"     |                          +
 *     47      |       Paziņojums "Digits AREN'T equal"    |                          +
 *      0      | Kļūda.Nepieder naturalo skaitļu intervālam| izdod paziņojumu "Error! Natural numbers belong to the intveral num<=0."      
 *    -98      | Kļūda.Nepieder naturalo skaitļu intervālam| izdod paziņojumu "Error! Natural numbers belong to the intveral num<=0."  

 *******************************/

// while vietā var izmantot arī for(first=num;first>=10;first=first/10), tomēr tas nav loģisks risinājums  
