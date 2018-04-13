
#ifndef NO_H
#define NO_H


template <typename T>
class FDE;

template <typename T>
class No
{
private:
    T valor;
    No<T>* proximo;

public:
    No(T valor) : valor(valor), proximo(nullptr){};
    virtual ~No(){};

    friend class FDE<T>;
};

#endif /* NO_H */
