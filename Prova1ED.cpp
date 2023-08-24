#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

using std::stringstream;

using namespace std;


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
        // cout << "Inserido: " << valor << endl;
        return true;
    }
    int pop(){
        if(vazia()){
            throw "Pilha vazia";
        }
        int valor = dados[topo];
        topo--;
        // cout << "Removido: " << valor << endl;
        return valor;
    }
};



int main(void){
    PilhaSeq p;
    
    istringstream frase;
    frase.str("ESTE EXERCICIO E MUITO FACIL");
    
    std::string palavra;
    string contrario;
    
    
    for(string line; getline(frase, line, ' ');){
        for(int i = 0; i < line.size(); i++){
            p.push(line[i]);
            // cout << line[i] << " ";
        }
        for(int i = 0; i < line.size(); i++){
            contrario.push_back(p.pop());
        }
        
        contrario.push_back(' ');
        // cout << endl;
        // cout << line << endl;
    }
    cout << contrario;
}