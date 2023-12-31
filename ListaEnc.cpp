#include <iostream>
#include <chrono>
#include <thread>

#define QTD_ELM 10

using namespace std;


class No{
    int conteudo;
    No* prox;
public:
    No(){
        prox = nullptr;
    }
    // Métodos get e set
    void set_conteudo(int c){
        conteudo = c;
    }
    void set_prox(No* p){
        prox = p;
    }
    int get_conteudo(){
        return conteudo;
    }
    No* get_prox(){
        return prox;
    }
};

class ListaEnc{
    No* cabeca;
    int tam;
public:
    ListaEnc(){
        cabeca = nullptr;
        tam = 0;
    }
    bool vazia(){ if(tam == 0) return true; else return false; }
    bool cheia(){
        return false; // Lista encadeada nunca estará cheia 
                      //(na prática, pode estar cheia por falta de 
                      // memória, mas não é o caso aqui pois não estamos usando alocação dinâmica)
    }
    int get_tam(){ return tam; }

    int get_elemento(int pos){
        No* aux = cabeca;
        int cont = 1;
        if(vazia()) return -1; // Consulta falhou
        
        if ((pos < 1) || (pos > tam)) return -1; // Posição inválida

        while(cont < pos){
            aux = aux->get_prox();
            cont++;
        }
        return aux->get_conteudo();
    }
    int get_posicao(int dado){
        int cont = 1;
        No* aux;

        if(vazia()) return 0;
        aux = cabeca;
        while(aux != NULL){
            if(aux->get_conteudo() == dado)
                return cont;
            aux = aux->get_prox();
            cont++;
        }
        return -1;
    }
    // Métodos de inserção
    bool insereInicio(int dado){
        No* novo = new No();

        novo->set_conteudo(dado);
        novo->set_prox(cabeca);
        cabeca = novo;

        tam++;
        return true;
        
    }
    bool insereMeio(int pos, int dado){
        int cont = 1;
        No* novoNo = new No();
        novoNo->set_conteudo(dado);

        // Localiza aonde será inserido o novo nó
        No* aux = cabeca;
        while ((cont < pos-1) && (aux != NULL)){
            aux = aux->get_prox();
            cont++;
        }
        if(aux == NULL) return false; // Posição inválida

        // Insere o novo nó
        novoNo->set_prox(aux->get_prox());
        aux->set_prox(novoNo);
        tam++;
        return true;
    }
    bool insereFim(int dado){
        No* novoNo = new No();
        novoNo->set_conteudo(dado);

        // Localiza o último nó
        No* aux = cabeca;
        while(aux->get_prox() != NULL){
            aux = aux->get_prox();
        }

        // Determina que o novo nó seja o último da lista 
        // e o penúltimo apontar para ele, além de 
        // incrementar o tamanho da lista
        novoNo->set_prox(NULL);
        aux->set_prox(novoNo);
        tam++;
        return true;
    }
    bool insere(int pos, int dado){
        if((vazia()) && (pos != 1)) return false; // Lista vazia e posição inválida
        if(pos == 1){
            // cout << "InsereInicio " << dado << endl;
            return insereInicio(dado);
        }
        else if(pos == tam+1){
            // cout << "insereFim " << dado << endl;
            return insereFim(dado);
        }
        else{
            // cout << "Inserindo o valor " << dado << " na posição " << pos << endl;
            return insereMeio(pos, dado);
        }
    }
    bool modifica(int pos, int dado){
        No* aux = cabeca;
        int cont = 1;

        while ((cont < pos) && (aux != NULL)){
            aux = aux->get_prox();
            cont++;
        }
        if(aux == NULL) return false;

        aux->set_conteudo(dado);
        return true;
    }
    int removeInicio(){
        No* aux = cabeca;
        int dado = aux->get_conteudo();

        // Retira o 1o elemento da lista
        cabeca = aux->get_prox();
        tam--;

        aux = NULL;
        return dado;
    }
    int removeNaLista(int pos){
        No* atual = NULL; No* antecessor = NULL;
        int dado = -1; int cont = 1;

        atual = cabeca;
        while((cont < pos/*+1 ??*/) && (atual != NULL)){
            antecessor = atual;
            atual = atual->get_prox();
            cont++;
        }
        if(atual == NULL)
            return -1;

        dado = atual->get_conteudo();
        antecessor->set_prox(atual->get_prox());
        tam--;

        atual = NULL;
        return dado;
    }
    int remove(int pos){
        if(vazia()) return -1; // Lista vazia

        if(pos == 1){
            return removeInicio();
        }
        else{
            return removeNaLista(pos);
        }
    }
    void print(){
        int cont = 1;
        No* aux = cabeca;
        while((cont < tam - 1) && (aux != NULL)){
            cout << aux->get_conteudo() << " ";
            aux = aux->get_prox();
        }
    }
};

int main(void){
    // a)
    cout << "Inicializando Lista Encadeada... " << endl;
    ListaEnc lista;
    int dado;

    // b)
    cout << (lista.vazia() ? "Está vazia" : "Não está vazia") << endl;

    cout << endl;
    cout << "Preenchendo a lista com " + to_string(QTD_ELM) + " elementos..." << endl;

    int random_list_element;
    for(int i = 1; i < QTD_ELM+1 ; i++){
        random_list_element = rand() % 100 + 1;
        lista.insere(i, random_list_element);
    }

    // c)
    cout << "Tamanho da lista atual: " << (lista.get_tam()) << endl;

    // d)
    cout << endl;
    lista.print();
    cout << endl;

    int num, pos;
    cout << "\n//Modifica valor em uma posição//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << "Digite um inteiro: ";
    cin >> num;
    cout << (lista.modifica(pos, num) ? ("Valor na posição " + to_string(pos) + " modificado para " + to_string(num) + " com sucesso!") : "Erro!") << endl;

    cout << endl;
    lista.print();
    cout << endl;

    // e)
    cout << "\n//Insere um elemento//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << "Digite um inteiro: ";
    cin >> num;
    cout << (lista.insere(pos, num) ? ("Valor " + to_string(num) + " na posição " + to_string(pos) + " inserido com sucesso!") : "Erro!") << endl;

    cout << endl;
    lista.print();
    cout << endl;

    // f)
    cout << "\n//Remove um elemento//" << endl;
    cout << "Digite a posição: ";
    cin >> pos;
    cout << (lista.remove(pos) != -1 ? ("Valor na posição " + to_string(pos) + " removido com sucesso!") : "Erro!") << endl;
    

    // g)
    cout << "\n//Todos os elementos da lista//" << endl;
    lista.print();
    
    


    return 0;
}