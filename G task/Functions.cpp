#include "FunctionLinked.h"
#include <iostream>


using namespace std;




void add_linked(elem* &first, elem* &last, int n){
elem *p=new elem;
p->num=n;
p->next=NULL;
if (first==NULL) { //nodrošina korekto pirma elementa izveidošanu
first=last=p;
}

else {
last->next=p;
last = p;
}

}





void delete_all_linked (elem *&first) {

while(first) {

elem *p = first->next;
delete first;
first=p;

    }
}


void print_linked(elem *first){
elem *p=first;
while(p!=NULL) {
cout<<p->num<<" ";
p=p->next;
}
cout<<endl;
}

/**
bool at_least_two(elem *first){

bool ok=false;

if(first==NULL) throw "Empty";
else if (first!=NULL && first->next==NULL)throw "Only one elem"; // Ja ir tieši 1 elements
else ok=true;

return ok;

}
*/

void remove_linked(elem* &first) {

bool ok=false;

if(first==NULL) throw "Empty";
else if (first!=NULL && first->next==NULL)throw "Only one elem"; // Ja ir tieši 1 elements
else ok=true;




    if (ok){
    elem* current = first;
    elem* p=NULL;
    while (current->next!= NULL) {
        if (current->num < current->next->num) {

            // Nodrošina korekto elementa first maiņu, ja ir dzēsts pirmais elements
            if (!p) {
                first = current->next;
            // Nodrošina saites esamību, ja ir dzēsts elements starp citiem 2 elementiem
            } else {
                p->next = current->next;
            }
            elem* temp = current->next;
            delete current;
            current = temp;

        }

        // Ja nosacījums nav izpildīts, tad virzās uz priekšu

        else {
            p=current;
            current = current->next;
        }
    }
  }
}













