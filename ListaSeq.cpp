#include <iostream>
#include <chrono>
#include <thread>

#define TAM_MAX 100
#define QTD_ELM 10

using namespace std;


class ListaSeq {
    int* dados;
    int tamAtual;
    int tamMax;
public:
    // a) (Construtores)
    ListaSeq(){
        tamMax = TAM_MAX;
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
    int get_tam(){
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
    bool modifica(int pos, int dado){
        if((pos > tamAtual) || (pos <= 0)){
            std::cout << "Erro! Digite uma posição válida!" << std::endl;
            return false;
        }else{
            dados[pos-1] = dado;
            return true;
        }
    }
    // e) (insere um elemento até a última posição+1 na lista)
    bool insere(int pos, int element){
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
    int remove(int pos){
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
    void print(){
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
    // a)
    cout << "Inicializando Lista Sequencial... \n" << endl;
    ListaSeq lista1;

    // b)
    cout << (lista1.vazia() ? "Lista está vazia" : "Lista não está vazia") << endl;

    cout << "Preenchendo a lista com " + to_string(QTD_ELM) + " elementos..." << endl;

    int random_list_element;
    for(int i = 0; i < QTD_ELM; i++){
        random_list_element = rand() % 100 + 1;
        lista1.append_element(random_list_element);
    }
    
    // c)
    cout << "Tamanho da lista atual: " << (lista1.get_tam()) << endl;

    // d)
    cout << endl;
    cout << "//Elemento em uma posição aleatória//" << endl;
    int random_int = rand() % QTD_ELM + 1;

    cout << "Elemento na posição " + to_string(random_int) + ": "<< lista1.get_element(random_int) << endl;

    cout << "Lista completa:\n" << endl;
    lista1.print();

    int num, pos;
    cout << "\n//Modifica valor em uma posição válida//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << "Digite um inteiro: ";
    cin >> num;
    cout << (lista1.modifica(pos, num) ? "Valor " + to_string(num) + " modificado na posição " + to_string(pos) + " com sucesso!" : "Erro! Digite uma posição válida!") << endl;

    // e)
    cout << "\n//Insere um elemento em uma posição válida//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << "Digite um inteiro: ";
    cin >> num;
    cout << (lista1.insere(pos, num) ? ("Valor " + to_string(num) + " inserido na posição " + to_string(pos) + " com sucesso!") : "Erro! Digite uma posição válida!") << endl;

    // f)
    cout << "\n//Remove um elemento em uma posição válida//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << (lista1.remove(pos) != -1 ? ("Valor " + to_string(lista1.remove(pos)) + " removido da posição " + to_string(pos) + " com sucesso!") : "Erro! Digite uma posição válida!") << endl;

   // g)
    cout << "\n//Imprime todos os elementos da lista//" << endl;
    lista1.print(); 
    
    return 0;
}
