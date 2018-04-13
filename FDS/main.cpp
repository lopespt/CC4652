/*
 * FDS.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */

#include "FDS.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  FDS<int> F(10);

  F.enfileira(10);
  F.enfileira(20);
  F.enfileira(30);
  F.enfileira(4);
  F.enfileira(9);
  int saida;
  while (F.desenfileira(saida)) {
    cout << saida << endl;
  }
  F.enfileira(10);
  F.enfileira(20);
  F.enfileira(30);
  F.enfileira(4);
  F.enfileira(9);
  F.enfileira(10);
  F.enfileira(20);
  F.enfileira(30);
  F.enfileira(4);
  F.enfileira(9);
  cout << "segunda vez" << endl;
  while (F.desenfileira(saida)) {
    cout << saida << endl;
  }

  return 0;
}
