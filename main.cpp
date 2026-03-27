#include <iostream>
#include "funciones.h"
using namespace std;

int main(){
    int op;

    cout<<"Ingrese numero de problema (1,3,5,7,9,11,13,15,17): ";
    cin>>op;

    switch(op){
    case 1: problema1(); break;
    case 3: problema3(); break;
    case 5: problema5(); break;
    case 7: problema7(); break;
    case 9: problema9(); break;
    case 11: problema11(); break;
    case 13: problema13(); break;
    case 15: problema15(); break;
    case 17: problema17(); break;
    default: cout<<"Opcion no valida"<<endl;
    }

    return 0;
}