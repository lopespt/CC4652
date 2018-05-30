#ifndef AVL_H
#define AVL_H

#include "No.hpp"
#include <queue>

#include <iostream>
using namespace std;

template <typename T> class Avl {
private:
  No<T> *raiz;
  int quantidade;

  void setAltura(No<T>* n{
    if(!n)
      return;
    int m=-1;
    if(n && n->esq){
      m = n->esq->altura;
    }
    if(n && n->dir && n->dir->altura > m){
      m = n->dir->altura;
    }
    n->altura = m+1;
  }

  void setPai(No<T>* n, No<T>* pai){
      if(n){
        n->pai = pai;
        if(pai){
            if(n->valor < pai->valor )
                pai->esq = n;
            else
                pai->dir = n;
        }else{
          raiz = n;
        }
      }
  }

  void leftRotate(No<T>* n){
        No<T>* x = n;
        No<T>* y = n->dir;
        No<T>* b = y->esq;

        y->pai = x;
        setPai(y, x->pai);
        x->dir = b;
        if(b)
            b->pai = x;

        setPai(x, y);
        setAltura(x);
        setAltura(y);
        setAltura(y->pai);
  }


  void rightRotate(No<T>* n){
    No<T>* x = n;
    No<T>* y = n->esq;
    No<T>* b = y->dir;

    y->pai = x;
    setPai(y, x->pai);
    x->esq = b;
    if(b)
      b->pai = x;


    setPai(x, y);
    setAltura(x);
    setAltura(y);
    setAltura(y->pai);
  }


  void balanceie(No<T>* n){
    if( n->fatorBalanc() >= 2 ){
      if(n->dir && n->dir->fatorBalanc() < 0){
        rightRotate(n->dir);
      }
      leftRotate(n);
    }else if(n->fatorBalanc() <= -2){
      if(n->esq && n->esq->fatorBalanc() > 0){
        leftRotate(n->esq);
      }
      rightRotate(n);
    }
  }

  int coluna(No<T>* n){
    int contaPaisEsquerdos=fe(raiz);
    No<T> * at = n->pai;
    No<T> * ant = n;
    while(at){
      if(at->dir == ant)
        contaPaisEsquerdos++;
      else
        contaPaisEsquerdos--;
      ant=at;
      at=at->pai;
    }
    return max(fe(n), contaPaisEsquerdos);
  }

  int nivel(No<T>* n){
    int k=0;
    No<T>* at = n;
    while(at){
      k++;
      at = at->pai;
    }
    return k;
  }


public:

  Avl() : raiz(nullptr), quantidade(0){ 
    
  };

  bool insere(T valor) {
    No<T> *novo = new No<T>(valor);
    if (!novo)
      return false;

    No<T> *ptrAnterior = nullptr;
    No<T> *ptrAtual = raiz;
    while (ptrAtual) {
      ptrAnterior = ptrAtual;
      if (valor < ptrAtual->valor)
        ptrAtual = ptrAtual->esq;
      else
        ptrAtual = ptrAtual->dir;
    }

    if (ptrAnterior) {
      novo->pai = ptrAnterior;
      if (valor < ptrAnterior->valor)
        ptrAnterior->esq = novo;
      else
        ptrAnterior->dir = novo;
    } else
      raiz = novo;

    quantidade++;
    No<T>* a = novo->pai;
    while(a){
      setAltura(a);
      balanceie(a);
      //cout << a->valor << endl;
      a = a->pai;
    }
    return true;
  }

  No<T>* busca(T v){
    No<T>* atual = raiz;
    while(atual){
      if(v < atual->valor){
        atual = atual->esq;
      }else if(v > atual->valor){
        atual = atual->esq;
      }else{
        return atual;
      }
    }
    return nullptr;
  }


  bool remove(No<T>* n){
    if(!n)
      return false;

    int filhos = (n->esq!=NULL) + (n->dir!=NULL);
    if(filhos==0){
      if(n->pai){
        if(n == n->pai->esq)
          n->pai->esq = NULL;
        else
          n->pai->dir = NULL;
      }else{
        raiz = NULL;
      }

      delete n;
    }else if(filhos == 1){
      No<T> *filho = n->esq;
      if(!filho)
        filho = n->dir;
      setPai(filho, n->pai);
      delete n;
    }else{
      No<T>* suc = sucessor(n);
      T valor = suc->valor;
      remove(suc);
      n->valor = valor;
    }

    return true;
  }

  void erd(){
      erd(raiz);
  }
  void erd(No<T>* n){
     if(n){
         erd(n->esq);
         cout << n->valor << "(" << n->altura << ")" << endl;
         erd(n->dir);
     }
  }


  void red(){
      red(raiz);
  }
  void red(No<T>* n){
     if(n){
         cout << n->valor << endl;
         red(n->esq);
         red(n->dir);
     }
  }

  int fe(No<T>* n){
      if(!n){
          return -1;
      }
      return max(fe(n->esq)+1, fe(n->dir)-1);
  }


  No<T>* sucessor(No<T> *n){
      n=n->dir;
      while(n && n->esq){
          n=n->esq;
      }
      cout << "sucessor = " << n->valor << endl;
      return n;
  }


  

  virtual ~Avl(){
    while(raiz){
      remove(raiz);
    }
  }
};

#endif /* AVL_H */
