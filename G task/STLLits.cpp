/******************************************************************

Aleksandra Dmitruka, ad22069

Izveidot programmu valodā C++, kas strādā ar vērtību virkni, izmantojot STL::list konteineru.
Realizācijā ir jāizveido prasītā specifiskā vērtību virknes apstrādes funkcija un jānodemonstrē tā darbībā, cita starpā parādot gan sākotnējās,
gan rezultējošās vērtības.

G15. Uzrakstīt funkciju, kas  izmet no saraksta tos elementus, kuru vērtība  mazāka par tam sekojošā elementa vērtību.

Programma izveidota: 26.03.2023

********************************************************************/

#include <iostream>
#include <list>
using namespace std;



/**
void remove_list(list<int> &aa);
Funkcija remove_list(list<int> &aa) apstradā sarakstu aa un izmet no tā tos elementus, kuru vērtība mazāka par tam sekojošā elementa vērtību. Citādi paziņo, kapēc nav izmaiņu
*/

void remove_list(list<int> &aa){
auto current=aa.begin();
auto next=aa.begin();
++next;
// Paziņo,kapēc nenotika apstrāde
if(current==aa.end()){
    cout<<"Empty"<<endl;
}
if(current!=aa.end() && next==aa.end()){
    cout<<"Only one elem"<<endl;
}
while(next!=aa.end()){ // kamēr eksistē nākošais(arī tas npzīme, ka ir esošas elements)
    if(*current < *next){
        current=aa.erase(current); // tā ka erase atgriež iteratoru,kas norāda uz nakošo elementu, tas arī piešķirts current
        next=current;
        ++next;


    }

    else{
        current=next;
        ++next;
    }
}


}


int main(){

int ok;
do{


list<int> aa;

int n;
cout << "Enter new element(0 if you want to stop the input) " << endl;
cin >> n;

while (n!=0){
aa.push_back(n);
cout << "Enter new element(0 if you want to stop the input) " << endl;
cin >> n;
}

//izdruka sarakstu
for (auto it : aa) {
cout << it << " ";
}
cout<<endl;

remove_list(aa);


for (auto it : aa) {
cout << it << " ";
}

cout<<endl;


cout << " Enter 0 to exit or 1 to continue" << endl;
cin >> ok;

 }while (ok == 1); // ļauj izpildīt programmu atkartoti


}




 /********************************

 *
 *        Ievads       |                     Programmas vēlamā reakcija                    |                    Rezultāts C++
 * --------------------+-------------------------------------------------------------------+----------------------------------------------------------------
 *        1 2 3 4      |                                4                                  |                          +
 *      6 5 4 3 2 1    |                          6 5 4 3 2 1                              |                          +
 *       2 7 8 7 1     |                              8 7 1                                |                          +
 *           -         |                              Kļūda                                |            Izdod paziņojumu "Empty"
 *           1         |                              Kļūda                                |        Izdod paziņojumu "Only one elem"


 *******************************/


