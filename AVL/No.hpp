#ifndef NO_H
#define NO_H

template <typename T> class Avl;

template <typename T> class No {
private:
  No<T> *esq;
  No<T> *dir;
  No<T> *pai;
  int altura;
  T valor;
  int fatorBalanc(){
    int e = esq ? (esq->altura) : -1;
    int d = dir ? (dir->altura) : -1;
    return d - e;
  }

public:
  No(T valor) : esq(nullptr), dir(nullptr),pai(nullptr), altura(0), valor(valor){};
  virtual ~No(){};

  friend class Avl<T>;
};

#endif /* NO_H */
