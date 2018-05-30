/*
 * main.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */


#include "Avl.hpp"
#include "No.hpp"
#include <iostream>


int main(int argc, char *argv[])
{
    Avl<int> A;
    int v[]={1,2,3,4,9,6,7,8,70,80,90};

    for(auto i : v){
        A.insere(i);
    }


    A.erd();
    A.red();
    cout << "================== Buscas ================" << endl;
    No<int>* a = A.busca(6);
    if(a)
      cout << a->getValor() << endl;
    else
      cout << "Nao encontrado" << endl;

    a = A.busca(2);
    if(a)
      cout << a->getValor() << endl;
    else
      cout << "Nao encontrado" << endl;

    a = A.busca(12);
    if(a)
      cout << a->getValor() << endl;
    else
      cout << "Nao encontrado" << endl;
    cout << endl;
    for(auto i : v){
      A.remove(A.getRaiz());
    }


    return 0;
}

