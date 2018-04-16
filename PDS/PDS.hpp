/*
 * PDS.hpp
 * Copyright (C) 2018 lopespt <lopespt@UX501VW>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef PDS_H
#define PDS_H

template <typename T> class PDS {
private:
  int n;
  int t;
  T *buffer;

public:
  PDS(int n) : n(n), t(0), buffer(new T[n]) {
  }

  bool pilhaCheia() {
    return t >= n;
  }

  bool empilha(T valor) {
    if (pilhaCheia())
      return false;

    buffer[t] = valor;
    t++;
    return true;
  }

  bool desempilha(T &valor) {
    if (t == 0)
      return false;

    t--;
    valor = buffer[t];
    return true;
  }

  virtual ~PDS() {
    delete[] buffer;
  };
};

#endif /* PDS_H */
