#include <iostream>

using std::cout;

class FilaSeq{
    int inicio;
    int fim;
    int nElementos;
    int tamMax;
    int* dados;
public:
    FilaSeq(){
        inicio = 0;
        fim = -1;
        nElementos = 0;

        tamMax = 6;
        dados = new int[tamMax];
    }
    bool vazia(){ return nElementos == 0; }
    bool cheia(){ return nElementos == tamMax; }
    int tamanho(){ return nElementos; }
    int primeiro(){
        if(vazia()){
            cout << "Erro: fila vazia\n";
            return -1;
        }
        return dados[inicio];
    }
    bool insere(int dado){
        if(cheia()){
            cout << "Erro: fila cheia\n";
            return false;
        }
        fim = (fim + 1) % tamMax; // Circularidade
        dados[fim] = dado;

        nElementos++;
        return true;
    }
    int remove(){
        if(vazia()){
            cout << "Erro: fila vazia\n";
            return -1;
        }
        int dado = dados[inicio];
        inicio = (inicio + 1) % tamMax; // Circularidade

        nElementos--;
        return dado;
    }
    void imprime(){
        cout << "Fila: ";
        for(int i = 0; i < nElementos; i++){
            cout << dados[(inicio + i) % tamMax] << " ";
        }
        cout << "\n";
    }
    ~FilaSeq(){
        delete[] dados;
    }
};

int main(void){
    FilaSeq fila;
    fila.insere(1);
    fila.insere(2);
    fila.insere(3);
    fila.insere(4);
    fila.insere(5);
    fila.insere(6);
    fila.imprime();
    fila.remove();
    fila.imprime();
    return 0;
}