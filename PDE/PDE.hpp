/*
 * PDE.hpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PDE_H
#define PDE_H

#include "No.hpp"

template <typename T> class PDE {
private:
  int n;
  int t;
  No<T> *topo;

public:
  PDE() : n(0), topo(nullptr){
  }

  bool empilha(T valor) {
      No<T>* novo = new No<T>(valor);
      if(novo == nullptr)
          return false;

    novo->abaixo = topo;
    topo = novo;

    return true;
  }

  bool desempilha(T &valor) {
    if (topo == nullptr)
      return false;

    No<T>* prox = topo->abaixo;
    valor = topo->valor;
    delete topo;
    topo=prox;

    return true;
  }

  virtual ~PDE() {
      T a;
      while(desempilha(a));
  };
};

#endif /* PDE_H */
