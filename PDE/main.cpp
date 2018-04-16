/*
 * main.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */

#include "PDE.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  PDE<int> pilha;
  for (int i = 0; i < 1000; i++)
    pilha.empilha(i);

  int a;

  while (pilha.desempilha(a)) {
    cout << a << endl;
  }

  return 0;
}
