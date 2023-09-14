#include <iostream>

using std::cout, std::endl;

class No{
    int valor;
    No* prox;
public:
    No(){
        prox = nullptr;
    }
    int getValor(){
        return valor;
    }
    void setValor(int dado){
        valor = dado;
    }
    No* getProx(){
        return prox;
    }
    void setProx(No* p){
        prox = p;
    }
};

class PilhaEnc{
    No* topo;
    int tam;
public:
    PilhaEnc(){
        topo = nullptr;
        tam = 0;
    }
    bool vazia(){
        return topo == nullptr;
    }
    int tamanho(){
        return tam;
    }
    int top(int print = 0){
        if(vazia()){
            throw "Pilha vazia";
        }
        if(print)
            cout << "Topo: " << topo->getValor() << endl;
        return topo->getValor();
    }
    bool push(int valor){

        No* novo = new No();

        novo->setValor(valor);
        novo->setProx(topo);

        topo = novo;
        tam++;
        cout << "Inserido: " << valor << endl;
        return true;
    }
    int pop(){
        if(vazia()){
            throw "Pilha vazia";
        }
        int valor = topo->getValor();
        No* aux = topo;
        topo = topo->getProx(); // = nullptr
        delete aux;
        tam--;
        cout << "Removido: " << valor << endl;
        return valor;
    }
    void print(){
        No* aux = topo;
        int count = 0;
        while(aux != nullptr){
            cout << aux->getValor() << endl;
            aux = aux->getProx();
        }
        cout << endl;
    }
};

int main(void){
    PilhaEnc p;
    int v[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < sizeof(v)/sizeof(int); i++){
        p.push(v[i]);
    }
    for(int i = 0; i < sizeof(v)/sizeof(int); i++){
        v[i] = p.pop();
    }
    for(int i = 0; i < sizeof(v)/sizeof(int); i++){
        cout << v[i] << " ";
    }

    return 0;
}