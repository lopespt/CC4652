#ifndef NO_H
#define NO_H


template <typename T>
class PDE;

template <typename T>
class No
{
private:
   No<T> *abaixo; 
   T valor;

public:
    No(T valor): abaixo(nullptr), valor(valor){};
    virtual ~No(){};
    friend class PDE<T>;
};

#endif /* NO_H */
