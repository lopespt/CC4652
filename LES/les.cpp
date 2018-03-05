#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

#define MAX 100
using namespace std;

template <typename T> class Les {
private:
  T v[MAX];
  int n;

public:
  Les() : n(0) {
  }

  bool insere(T novo) {
    // d� para inserir?
    if (n >= MAX)
      return false;

    // buscar posicao para inserir
    int i = 0;
    while (i < n && v[i] < novo) {
      i++;
    }
    // ou
    // for(i=0; i < n && v[i] < novo; i++);

    for (int j = n; j > i; j--) {
      v[j] = v[j - 1];
    }

    v[i] = novo;
    n++;
    return true;
  }

  int busca(T elemento) {
    for (int i = 0; i < n; i++) {
      if (v[i] == elemento)
        return i;
    }
    return -1;
  }

  int buscaBinaria(T elemento) {
    int i = 0;
    int f = n - 1;
    while (i <= f) {
      int p = (i + f) / 2;
      if (elemento < v[p])
        f = p - 1;
      else if (elemento > v[p])
        i = p + 1;
      else
        return p;
    }

    return -1;
  }

  bool remove(T elemento) {
    int pos = busca(elemento);
    if (pos == -1)
      return false;

    for (int i = pos; i < n - 1; i++)
      v[i] = v[i + 1];

    // for(int i=pos+1; i < n ; i++)
    // v[i-1] = v[i];

    n--;
    return true;
  }

  const T &operator[](int idx) {
    if (idx >= n) {
      throw std::runtime_error("estourou");
      return v[0];
    }
    return v[idx];
  }
};

int main(int argc, char *argv[]) {
  Les<int> l;
  for (int i = 0; i < 100; i += 3)
    l.insere(i);

  cout << l[0] << endl;
  cout << l[3] << endl;
  cout << l[7] << endl;
  cout << l.buscaBinaria(0) << endl;
  cout << l.buscaBinaria(33) << endl;
  cout << l.buscaBinaria(3) << endl;
}
