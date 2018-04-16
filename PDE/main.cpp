/*
 * main.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */

#include "PDE.hpp"
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

  PDE<float> pilha;
  for (int i = 0; i < 1000; i++)
    pilha.empilha(sqrt(i));

  float a;

  while (pilha.desempilha(a)) {
    cout << a << endl;
  }

  return 0;
}
