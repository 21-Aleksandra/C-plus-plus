/*******************************************

Aleksandra Dmitruka,ad22069

C15. No masīva A(2n) iegūt divus masīvus B(n) un C(n) šādā veidā: 
atrast masīvā A divus pēc vērtības vistuvākos skaitļus - mazāko ielikt masīvā B, bet lielāko - masīvā C. 
Darbu turpināt, līdz visi atlikušie elementi ir izņemti un masīvi B un C aizpildīti.


Programma izveidota: 09.11.2022
*******************************************/


#include <iostream>
using namespace std;
 
 /*******
 void order (double arr[],int dsize);
 order(A,twice); - sakarto masīva A ar garumu twice elementus augošā secībā
 *******/

 void order (double arr[],int dsize){
 for(int i=0;i<dsize;i++){
  for(int m=i+1;m<dsize;m++){
    if(arr[i]>=arr[m])
			{
				double k=arr[i];
				arr[i]=arr[m];
				arr[m]=k;
			}
    }
  } 
}

/******
void BigSmall(double arr[],double B[], double C[],int dsize);
BigSmall(A,B,C,twice) - atrod masīvā A ar garumu twice divus pēc vērtības vistuvākos skaitļus,
mazāko ieliek masīvā B, bet lielāko - masīvā C. 
******/

void BigSmall(double arr[],double B[], double C[],int dsize){
 
  int size=0; //lauj iziet cauri masīvam B un C no sākuma indeksa 0
  

  for(int i=0;i<dsize-1;i+=2){
  
  if (arr[i]>=arr[i+1]){
      
      B[size]=arr[i+1];
      C[size]=arr[i];
      size++;
       
        
     
     }

    else {

      C[size]=arr[i+1];
      B[size]=arr[i];
      size++;
      
    }
    
   }
  }



int main() {

   int ok;
   do {

    int n;
    int twice;
    do{
    cout<<"Enter array lenght n(n>0), which will be multiplied by two (2n):"<<endl;
    cin>>n;

    if(n<=0) { 
        cout<<"Error!The lenght of the array must be at least one(n>0)"<<endl;}

    }while(n<=0);  //Nodrošina ieejas datu korektumu

    twice=n*2; // Iegūst korektu A masīva izmēru

    double *A = new double [twice]; 

    for (int i = 0; i < twice; i++){
            cout<<"Enter array's element"<<endl;
            cin>>A[i]; 
        }

  order(A,twice);
    
  double *B = new double [n]; 
  double *C = new double [n]; 
  
  BigSmall(A,B,C,twice);


    cout<<"A array elements are:"<<endl; //masīva A pārbaude
    for (int i=0;i<twice;i++) {
      cout<<A[i]<<' ';
    }
    cout<<endl;

    cout<<"B array elements are:"<<endl;
    for (int i=0;i<n;i++) {
      cout << B[i]<<' '; }
      
       cout<<endl;
    
    cout<<"C array elements are:"<<endl;
    for (int i=0;i<n;i++) {
      cout << C[i]<<' '; }
      
       cout<<endl;


    delete [] A;
	  delete [] B;
    delete [] C; 

    cout << endl << "Enter 0 to exit or 1 to continue" << endl;
    cin >> ok;

    } while (ok == 1); //lauj atkārtot visu programmu, ja lietotājs beigās ievadīs ciparu 1
}

 /********************************
 *
 *   n |      Ievads(A)     |           B                |                C                     |                    Rezultāts C++
 * ------------------------ +-------------------------------------------------------------------+----------------------------------------------------------------
 *   2 |     2  4  3  5     |        2        4          |          3         5                 |                          +
 *   2 |   2.4  1  7  5.8   |        1       5.8         |         2.4         7                |                          +
 *   3 | 6.1 -7 -1  4  2  -9|       -9   -1   4          |         -7    2     6.1              |                          +
 *   3 |  3  5  5  8  1   9 |        1    4   5          |          3    5     8                |                          +
 *   2 |      1  2  3  4    |        1        3          |          2          4                |                          +
 *  -2 |         -          |            Kļūda.Masīva izmērs nevar būt mazāks par 1             | izdod paziņojumu "Error!The lenght of the array must be at least one(n>0)"
 *******************************/

