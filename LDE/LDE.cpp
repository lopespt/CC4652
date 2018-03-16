/*
 * LDE.cpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 *
 */
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T> class No {
private:
public:
  T valor;
  No<T> *prox;

  No(T valor) {
    this->valor = valor;
    this->prox = NULL;
  }
};

template <typename T> class Lde {
private:
  No<T> *primeiro;
  unsigned int total;

public:
  Lde() : primeiro(NULL), total(0) {
  }

  /*
  bool insere(T valor) {
    No<T> *novo = new No<T>(valor);

    No<T> *ve = primeiro;
    while (ve && ve->prox && ve->prox->valor < valor)
      ve = ve->prox;

    if (ve && ve->valor > valor) {
      primeiro = novo;
      novo->prox = ve;
    } else {
      if (ve) {
        novo->prox = ve->prox;
        ve->prox = novo;
      }
    }
  }
  */

  bool insere(T valor) {
    No<T> *atual = primeiro;
    No<T> *anterior = NULL;

    No<T> *novo = new No<T>(valor);

    if (!novo)
      return false;

    while (atual && atual->valor < valor) {
      anterior = atual;
      atual = atual->prox;
    }

    if (anterior)
      anterior->prox = novo;
    else
      primeiro = novo;

    novo->prox = atual;
    return true;
  }

  ~Lde() {
    No<T> *prox = NULL;
    No<T> *atual = primeiro;
    while (atual) {
      prox = atual->prox;
      delete atual;
      atual = prox;
    }
  }

  void imprime() {
    No<T> *atual = primeiro;
    while (atual) {
      cout << atual->valor << endl;
      atual = atual->prox;
    }
  }

  No<T> *busca(T valor) {
    No<T> *atual = primeiro;
    while (atual && atual->valor < valor) {
      atual = atual->prox;
    }

    if (atual && atual->valor == valor)
      return atual;
    else
      return NULL;
  }

  bool remove(int valor) {
    No<T> *anterior = NULL;
    No<T> *atual = primeiro;
    while (atual && atual->valor < valor) {
      anterior = atual;
      atual = atual->prox;
    }

    if (atual == NULL || atual->valor != valor)
      return false;

    if (anterior)
      anterior->prox = atual->prox;
    else
      primeiro = atual->prox;

    delete atual;

    return true;
  }
};

int main(int argc, const char *argv[]) {

  Lde<int> l;
  l.insere(1);
  l.insere(2);
  l.insere(3);
  l.insere(4);
  l.imprime();
  No<int> *n = l.busca(2);
  if (n)
    cout << "encontrei: " << n->valor << endl;
  else
    cout << "nao encontrei" << endl;

  l.remove(2);
  l.imprime();
  n = l.busca(2);
  if (n)
    cout << "encontrei: " << n->valor << endl;
  else
    cout << "nao encontrei" << endl;

  return 0;
}
