#ifndef FDE_H
#define FDE_H

#include "No.hpp"

// Fila Dinamica Sequencial Circular

template <typename T> class FDE {
private:
  No<T> *primeiro;
  No<T> *ultimo;
  int tam;

public:
  FDE() : primeiro(nullptr), ultimo(nullptr), tam(0){
  }

  bool enfileira(T valor) {
      No<T>* novo = new No<T>(valor);
      if(!novo)
          return false;

      if(ultimo)
          ultimo->proximo = novo;
      ultimo=novo;
      if(!primeiro)
          primeiro=novo;

      return true;
  }

  bool desenfileira(T &saida) {
        if(!primeiro)
            return false;

        saida = primeiro->valor;
        primeiro = primeiro->proximo;
        return true;
  }

  bool vazia() {
    return primeiro == nullptr;
  }

  virtual ~FDE() {
      T s;
      while(desenfileira(s));
  }
};

#endif /* FDE_H */
