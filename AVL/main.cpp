/*
 * main.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */


#include "Avl.hpp"
#include <iostream>


int main(int argc, char *argv[])
{
    Avl<float> A;
    float v[]={1,2,3,4,5,5.1,5.2,5.3,7,8,9};

    for(auto i : v){
        A.insere(i);
    }


    A.erd();
    A.red();
    for(auto i : v){
      A.remove(A.getRaiz());
    }
    cout << endl;


    return 0;
}

