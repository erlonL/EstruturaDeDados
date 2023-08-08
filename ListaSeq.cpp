#include <iostream>
#include <chrono>
#include <thread>

class ListaSeq {
    int* dados;
    int tamAtual;
    int tamMax;
public:
    // a) (Construtores)
    ListaSeq(){
        tamMax = 100;
        tamAtual = 0;
        dados = new int[tamMax];
    }
    ListaSeq(int tM){
        tamMax = tM;
        tamAtual = 0;
        dados = new int[tamMax];        
    }
    // Destrutor
    ~ListaSeq(){
        delete[] dados;
    }
    // b)
    bool vazia(){
        if(tamAtual == 0) return true;
        else return false;
    }
    bool cheia(){
        if(tamAtual == tamMax) return true;
        else return false;
    }
    // c)
    int tamanho(){
        return tamAtual;
    }
    // d)
    int get_element(int pos){
        int dado;
        if((pos > tamAtual) || (pos <= 0))
            return -1;
        dado = dados[pos-1];
        return dado;
    }
    bool modify_element(int pos, int dado){
        if((pos > tamAtual) || (pos <= 0)){
            std::cout << "Erro! Digite uma posição válida!" << std::endl;
            return false;
        }else{
            dados[pos-1] = dado;
            return true;
        }
    }
    // e) (insere um elemento até a última posição+1 na lista)
    bool set_element(int pos, int element){
        if(cheia() || (pos > tamAtual+1) || (pos<=0))
            return false;

        for(int i = tamAtual; i >= pos; i--){
            dados[i] = dados[i-1];
        }

        dados[pos-1] = element;
        tamAtual++;
        return true;
    }
    bool append_element(int element){
        if(cheia())
            return false;
        dados[tamAtual] = element;
        tamAtual++;
        return true;
    }
    // f)
    int remove_element(int pos){
        int dado;
        if ((pos > tamAtual) || (pos < 1))
            return -1;
        
        dado = dados[pos-1];
        for(int i = pos - 1; i < tamAtual - 1; i++){
            dados[i] = dados[i+1];
        }
        tamAtual--;
        return dado;
    }
    // g)
    void print_elements(){
        for(int i = 0; i < tamAtual; i++){
            std::cout << dados[i] << " ";
        }
        std::cout << std::endl;
    }
    void print_last_element(){
        std::cout << dados[tamAtual-1];
    }
    int get_max_size(){
        return tamMax;
    }
    void clear(){
        tamAtual = 0;
    }
    int get_size(){
        return tamAtual;
    }
};

int main(){
    ListaSeq lista1(10);
    std::cout << "A lista está vazia?\n>> "<< (lista1.vazia() ? "Sim" : "Não") << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < lista1.get_max_size(); i++){
        lista1.append_element(i+1);
    }

    std::cout << "Lista Padrão: " << std::endl;
    lista1.print_elements();
    std::cout << std::endl;

    lista1.remove_element(lista1.get_size()); // Remove o último elemento


    lista1.set_element(5, 823); // adiciona 823 na posição 5
    std::cout << "Append 823 in pos 5: " << std::endl;
    lista1.print_elements();
    std::cout << std::endl;

    std::cout << "A lista está vazia?\n>> "<< (lista1.vazia() ? "Sim" : "Não") << std::endl;
    std::cout << std::endl;

    lista1.remove_element(5); // remove 823

    std::cout << "Remove 823 element (pos 5) " << std::endl;
    lista1.print_elements();
    std::cout << std::endl;

    lista1.modify_element(5, 0);
    std::cout << "Modify pos 5 element to 0 " << std::endl;
    lista1.print_elements();
    std::cout << std::endl;

    ListaSeq lista2 = ListaSeq(10);

    // Tentando adicionar mais elementos que a lista comporta
    std::cout << "Tentando preencher a Lista com mais elementos do que ela comporta " 
    << "(tMax = " << lista2.get_max_size() << ")" << std::endl;

    for(int i = 0; i < lista2.get_max_size() + 10; i++){
        std::cout << i+1 << ": "; 
        std::cout << (lista2.append_element(i+1) ? std::to_string(lista2.get_element(i+1)) : "Erro! Lista cheia!") << std::endl;
    }


    lista2.print_elements();
    


}
