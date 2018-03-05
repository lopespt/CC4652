#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T> class Les {
private:
  T* v;
  int n;
  int capacidade;
public:
  Les(int capacidade=10) : v(new T[capacidade]), n(0), capacidade(capacidade) {
  }
  
  int size()const{
		return n;
	}
  
  void realoca(int novoTam){
		if (novoTam < n)
			return;
			
		T *novo = new T[novoTam];
		copy(v, v+n, novo);
		delete []v;
		v = novo;
  }

  bool insere(T novo) {
    // dá para inserir?
    if (n >= capacidade)
      realoca(n*2);

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

  const T &operator[](int idx) const {
    if (idx >= n) {
      throw std::runtime_error("estourou");
      return v[0];
    }
    return v[idx];
  }
  
  void operator=(const Les<T>& outra){
		this->n=0;
		for(int i=0;i<outra.n; i++)
		    this->insere(outra.v[i]);
  }
  
  ~Les{
		delete []v;
	}
  
};





template <typename T>
ostream& operator <<(ostream& out, const Les<T>& outra){
		for(int i=0;i< outra.size(); i++)
		    out << outra[i] << endl;
}








int main(int argc, char *argv[]) {
  Les<int> l;
  Les<int> a;
  for (int i = 0; i < 100; i += 3)
    l.insere(i);

  cout << l[0] << endl;
  cout << l[3] << endl;
  cout << l[7] << endl;
  cout << l.buscaBinaria(0) << endl;
  cout << l.buscaBinaria(33) << endl;
  cout << l.buscaBinaria(3) << endl;
  a = l;
  cout << a;
  
  system("pause");
}
