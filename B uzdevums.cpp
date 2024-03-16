/*******************************************

Aleksandra Dmitruka,ad22069

B22. Sastādīt programmu, kura reizina un dala racionālus skaitļus, 
racionālos skaitļus uzdodot kā divu veselu skaitļu pāri (1/3 tiek uzdota kā divi skaitļi 1 un 3). 
Rezultātam jābūt kā nesaīsināmam daļskaitlim. Risinājumā izmantot funkciju, kas reizina divus racionālus skaitļus un funkciju,
kas pārveido racionālu skaitli par nesaīsināmu daļskaitli.

Programma izveidota: 20.10.2022
*******************************************/


void reiz (long long int numone, long long int denone, long long int numtwo, long long int dentwo, long long int* storeone, long long int* storetwo){  //Atkarība no padodamo datu secības reizina vai dala racionālus skaitļus (daļas)                                                                                                                                                    // 
  *storeone=numone*numtwo;                                                                                                                             //ļauj izmantot skaitļus,kuri ir lielāki par 2^31, un iegūt pareizo programas reakciju
  *storetwo=denone*dentwo;
}



void nesadal (long long int a, long long int b, long long int c, long long int d, long long int* reznum, long long int* rezden){ // Aprēķina skaitītāja un saucēja lielāko kopīgo dalītaju,izmantojot Eiklīda algoritmu,un iegūst nesaīsināmo daļskaitli,dalot tos ar LKD
                                                                                                                                 //ļauj ievadīt skaitļus,kuri ir lielāki par 2^31, un iegūt pareizo programas reakciju

    if (a<0){ //Nodrošina ieejas datu korektumu, jo, LKD var apreķināt tikai skaitļu moduļiem t.i. tikai pozitivajiem skaitļiem
        a=-a;
    }
    
    if (b<0){
        b=-b;
    }
     
  
  while(a!=0 && b!=0){ //Izmanto Eiklīda algoritmu, lai atrastu LKD
    if (a>b) {
      a=a%b;
    }
    else{
      b=b%a;
    }
  }
  a=a+b;

  *reznum=c/a;
  *rezden=d/a;   
}



#include <iostream>
using namespace std;

int main() {

   int ok; 
   do {
    
    long long int numone,numtwo,denone,dentwo,a,b,c,d; //ļauj ievadīt skaitļus,kuri ir lielāki par 2^31, un iegūt pareizo programas reakciju. 
                                                       //Papildmainīgaie a,b,c,d ir ievesti, lai izmantotu oriģinālus skaitļus citās darbībās

    do{
  
    cout << "Enter the numerator and denominator of the first the second fraction! Observe the input order and use spaces:";
    cin >>numone>>denone>>numtwo>>dentwo;

    if(denone==0 or dentwo==0 ) { 
        cout<<"Error!The denominator of any fraction cannot be zero."<<endl;
        
    }
    }while(denone==0 || dentwo==0 ); //Nodrošina ieejas datu korektumu

    reiz(numone,denone,numtwo,dentwo,&a,&b); //reizina racionālus skaitļus
    reiz(numone,denone,dentwo,numtwo,&c,&d); //dala racionālus skaitļus

   
    /**** 
    cout<<a<<endl; //Starpvērtību parbaude
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    ****/

    nesadal(a,b,a,b,&a,&b); //saīsina reizinajumu

    nesadal (c,d,c,d,&c,&d); //saīsina dalījumu 


    cout<<"The division of fractions"<<' '<<numone<<"/"<< denone <<' '<<"and"<<' '<<numtwo<<"/"<<dentwo<<' '<<"is equal to"<<' '<<c<<"/"<<d<<endl;
    cout<<"The multiplication of fractions"<<' '<<numone<<"/"<< denone <<' '<<"and"<<' '<<numtwo<<"/"<<dentwo<<' '<< "is equal to"<<' '<< a <<"/"<<b <<endl;
    

    cout << endl << "Enter 0 to exit or 1 to continue" << endl;
    cin >> ok;

   } while (ok == 1); //lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1
}



 /********************************

 * 
 *        Ievads       |                     Programmas vēlamā reakcija                    |                    Rezultāts C++
 * --------------------+-------------------------------------------------------------------+----------------------------------------------------------------
 *       2 3 4 5       |        "Devision is 5/6  | Multiplication is 8/15"                |                          +
 *      -10 3 6 7      |        "Devision is -35/9 | Multiplication is -20/7"              |                          +
 *      21 -6 2 4      |         "Devision is 7/-1 | Multiplication is 7/-4"               |                          +
 *     -3 -7 -4 -5     |        "Devision is 15/28 | Multiplication is 12/35"              |                          +
 *      -4 0 2 7       |              Kļūda.Nedrīkst dalīt ar nulli                        | izdod paziņojumu "Error!The denominator of any fraction cannot be zero."      
 * 2 1234567 3 12345678| "Devision is 8230452\1234567| Multiplication is 1\2540261108571"  |                          +

 *******************************/

