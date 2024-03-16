#include <iostream>
#include <cctype>
#include "program.h"
using namespace std;

Carray::Carray()
{

 for(int i=0;i<10;i++)
    {letters[i]='a';}
    //letters[10]='\0';

}

Carray::~Carray()
{

 cout<<"The object was liquidated"<<endl;

}

void Carray::change(int n,char m){

//if (n>=0 and n<9)
letters[n]=k;

}

void Carray::toCapital(){

for(int i=0;i<=9;i++){

    letters[i]=toupper(letters[i]);
}


}


void Carray::toSmall(){

for(int i=0;i<=9;i++){

    letters[i]=tolower(letters[i]);
}


}

void Carray::print(){

cout<<letters<<endl;

}
