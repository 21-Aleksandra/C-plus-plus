/**

Aleksandra Dmitruka,ad22069

D12. Izveidot klasi "Burtu masīvs" - Carray, kurā glabājas masīvs ar burtiem (char) garumā 10.
Klasei izveidot šādas metodes:
(1) konstruktors, kas aizpilda masīvu ar simboliem 'a' (lietot vienu papildus elementu ar indeksu 10, kurā ierakstīt simbolu virknes beigu simbolu '\0'),
(2) destruktors, kurš paziņo par objekta likvidēšanu,
(3) metode "Mainīt" - change ar maināmā elementa indeksu (0..9) un jauno vērtību, kas izmaina maināmā masīva elementa vērtību,
(4) metode "Lielie" - toCapital, kas pārveido visus burtus par lielajiem,
(5) metode "Mazie" - toSmall, kas pārveido visus burtus par mazajiem,
(6) metode "Drukāt" - print, kas izdrukā masīvā glabāto vārdu.

Programma izveidota: 27.11.2022

**/

#include <iostream>
#include "Program.h"
#include <cctype>
using namespace std;


int main(){

    int a,b;

    Carray word; //konstruktors
    word.print();

    /**

    do{
    cout<<"Enter array index and prefered symbol"
    cin>>a>>b;
    if(a>9){
    cout<<"Error!Try again"<<endl;
    }
    }while(a>9)

    **/




    word.change(a,b);
    word.print;
    word.toCapital;
    word.print;
    word.toSmall;
    word.print;

    Carray word;






}
