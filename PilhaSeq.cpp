#include <iostream>

using std::cout, std::endl;


class PilhaSeq{
    int* dados;
    int topo;
    int tamMax;
public:
    PilhaSeq(){
        tamMax = 10;
        dados = new int[tamMax];
        topo = -1;
    }
    // gets, sets, etc
    bool vazia(){
        return topo == -1;
    }
    bool cheia(){
        return topo == tamMax - 1;
    }
    int tamanho(){
        return topo + 1;
    }
    int top(){
        if(vazia()){
            throw "Pilha vazia";
        }
        return dados[topo];
    }
    bool push(int valor){
        if(cheia()){
            return false;
        }
        topo++;
        dados[topo] = valor;
        cout << "Inserido: " << valor << endl;
        return true;
    }
    int pop(){
        if(vazia()){
            throw "Pilha vazia";
        }
        int valor = dados[topo];
        topo--;
        cout << "Removido: " << valor << endl;
        return valor;
    }
};



int main(void){
    PilhaSeq p;
    p.push(1);
    p.push(2);
    p.push(3);

    p.pop();
    p.push(4);
    p.pop();
}