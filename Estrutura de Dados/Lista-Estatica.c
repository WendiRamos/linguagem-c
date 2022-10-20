#include <stdio.h>
#include <stdlib.h>
#define maxTam 10

typedef struct sLista
{
    char elemento[maxTam];
    int ultimo;
}Lista;

//Inicializar a lista
void inicializarLista(Lista *lista){
    lista -> ultimo = -1;
}

//Verificar se a lista esta cheia
int listaCheia(Lista *lista){
    if(lista -> ultimo == (maxTam -1)){
        return 1;
    }
    return 0;
}

//Verificar se a lista esta vazia
int listaVazia(Lista *lista){
    if(lista -> ultimo == -1){
        return 1;
    }
    return 0;
}

//Inserir elemento no fim da lista
int inserirFim(Lista *lista, char elemento){
    //Verificar se a lista está cheia
    if(listaCheia(lista)){
        printf("ERRO: Lista cheia!\n");
        return 0;
    }
    lista -> elemento[lista -> ultimo + 1] = elemento;
    lista -> ultimo++;
    return 1;
}

//Modificar um elemento existente
int modificarElemento(Lista *lista, int posicao, char elemento){
    if(!listaVazia(lista)){
        //Verifica se a posição é válida
        if (posicao >= 0 && posicao < lista -> ultimo + 1){
            //Substitui o elemento
            lista -> elemento[posicao] = elemento;
            return 1;
        }
    }
    return 0;
}

//Remover um elemento da posição I
int removerElemento(Lista *lista, int posicao){
    int i;
    //Verifica se a lista está vazia
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return 0;
    }
    //Testa se a posição é inválida
    if(posicao < 0 || posicao > lista -> ultimo){
        printf("\nERRO: Posicao Invalida");
        return 0;
    }
    //Move os elementos posteriores ao removido
    for(i = posicao; i < lista -> ultimo; i++){
        lista -> elemento[i] = lista -> elemento[i + 1];
    }
    //Atualiza o indicador de último elemento
    lista -> ultimo --;
    return 1;
}

//Acesso ao elemento da posição I
char acessarElemento(Lista *lista, int posicao){
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return ' ';
    }
    if (posicao < 0 || posicao > lista -> ultimo){
        printf("\n ERRO: Posicao Invalida");
        return ' ';
    }
    return lista -> elemento[posicao];
}

//Pesquisar um elemento na lista
int pesquisarElemento(Lista *lista, char elemento){
    int i;
    if(listaVazia(lista)){
        printf("\nERRO: Lista Vazia");
        return -1;
    }
    //Percorre todos os elementos da lista
    for( i = 0; i <= lista -> ultimo; i++){
        if(lista -> elemento[i] == elemento){
            return i;//Retorna a posição do elemento
        }
    }
    //Se percorreu a lista e não encontrou o elemento
    return -1;
}

//Retornar o tamanho da lista
int tamanhoLista(Lista *lista){
    return lista -> ultimo + 1;
}

int main()
{
   Lista lista;
   inicializarLista(&lista);
    
    return 0;
}