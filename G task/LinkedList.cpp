/******************************************************************

Aleksandra Dmitruka, ad22069

Izveidot programmu valodā C++, kas strādā ar vērtību virkni, to realizējot kā vienvirziena saistīto sarakstu, izmantojot dinamiskas datu struktūras,
Realizācijā ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās,
gan rezultējošās vērtības. Saistītā saraksta gadījumā jāuzraksta arī nepieciešamās palīgfunkcijas (piemēram, elementu pievienošanai),
kā arī pēc tā izmantošanas korekti jāatbrīvo izdalītā atmiņa.

G15. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus, kuru vērtība  mazāka par tam sekojošā elementa vērtību.

Programma izveidota: 26.03.2023

********************************************************************/

#include<iostream>
#include "FunctionLinked.h"

using namespace std;



int main(){
int kk;
do{
try{
elem *first=NULL, *last=NULL;
int n;
cout << "Enter new element(0 if you want to stop the input) " << endl;
cin >> n;

while (n!=0){ // ievaīšana kamēr nav sastapta nulle
add_linked(first, last, n);
cout << "Enter new element(0 if you want to stop the input) " << endl;
cin >> n;
}

print_linked(first);



remove_linked(first);

print_linked(first);

delete_all_linked(first);


}

catch(const char* err){ //kļūdu apstrāde
    if(err==(string)"Empty"){
        cout<<"Empty list"<<endl;
        return -1;
    }


    if(err==(string)"Only one elem"){
        cout<<"You need to enter at least two elements"<<endl;
        return -2;
    }

}
catch(...){ // Lai nodrošinātu darbības korektumu nezināmas kļūdas dēļ
cout<<"Unknown error"<<endl;
return -5;
}

cout << " Enter 0 to exit or 1 to continue" << endl;
cin >> kk;

}while(kk==1); // ļauj izpildīt programmu atkārtoti. Kļūdaino pabeidz(var atļaut, noņemot return pie catch)
}

 /********************************

 *
 *        Ievads       |                     Programmas vēlamā reakcija                    |                    Rezultāts C++
 * --------------------+-------------------------------------------------------------------+----------------------------------------------------------------
 *        1 2 3 4      |                                4                                  |                          +
 *      6 5 4 3 2 1    |                          6 5 4 3 2 1                              |                          +
 *       2 7 8 7 1     |                              8 7 1                                |                          +
 *           -         |                              Kļūda                                |            Izdod paziņojumu "Empty list"
 *           1         |                              Kļūda                                |   Izdod paziņojumu "You need to enter at least two elements"


 *******************************/




