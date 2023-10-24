#include <stdio.h>
#include <stdlib.h>

// criar estrutura de celula
typedef struct Celula {
    int conteudo;
    struct Celula* seg;
} Celula;

// atribuir valor a celula
Celula* criarCelula(int valor) {
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = valor;
    newSeg->seg = NULL;
    return newSeg;
}

// criar lista encadeada com um numero count de células
// os consteudos de cada célula serão valores aleatórios entre 0 e 20
Celula* criarListaEncadeada(int count) {
    if(count == 0){return NULL;}
    Celula* newSeg = malloc(sizeof(Celula));
    newSeg->conteudo = rand() % 10;
    if (count == 1) {newSeg->seg = NULL;}
    if (count > 1){
        newSeg->seg = criarListaEncadeada(count - 1);}
    return newSeg;
}

void imprimirConteudoLista (Celula* lst){
    if(lst->seg != NULL){
        printf("%d, ", lst->conteudo);
        imprimirConteudoLista(lst->seg);
    } else if(lst->seg == NULL){
        printf("%d", lst->conteudo);
    }
}

void imprimirEnderecosLista (Celula* lst, int count){
    printf("endereco da %d celula: %p; endereco para o qual essa celula aponta: %p\n", count, lst, lst->seg);
    if(lst->seg != NULL){
        imprimirEnderecosLista(lst->seg, count+1);
    }
}


// inserir celula no inicio de lista sem cabeça
void inserirCelInicio(Celula** ponteiroLst, Celula* cel){
    cel->seg = *ponteiroLst;
    *ponteiroLst = cel;
}

//inserior celula no inicio de lista com cabeça
void inserirCelInicioCabeca(Celula* ponteiroCabeca, Celula* cel) {
    cel->seg = ponteiroCabeca->seg;
    ponteiroCabeca->seg = cel;
}

// busca valor em celula da lista e retorna o seg da celula anterior
Celula* buscarValor(Celula* lst, int valor){
    if (lst->conteudo == valor){
        return lst;
    }
    if (lst->seg == NULL){
        return NULL;
    }
    if (lst->conteudo != valor){
        return buscarValor(lst->seg, valor);
    }
}

// inserir uma nova célula  em lista encadeada logo após uma celula de valor "valor".
void inserirCel(Celula* lst, int valor){
    Celula* pCel = criarCelula(rand() % 100);
    Celula* pCelAnterior = buscarValor(lst, valor);
    if (pCelAnterior == NULL) { printf ("nao ha celula com o valor %d na lista\n", valor); return;}
    if (pCelAnterior->seg != NULL){
        pCel->seg = pCelAnterior->seg;
        pCelAnterior->seg = pCel;
        return;
    }else {
        pCelAnterior->seg = pCel;
        return;}
}

void deleteCel(Celula** lst) {
    Celula* pReserva = *lst;
    *lst = (*lst)->seg;
    free(pReserva);
}


int main() {
    printf("Criando lista encadeada com 5 celulas: ");
    Celula* lst = criarListaEncadeada(5);
    imprimirConteudoLista(lst);
    printf("\n");
    imprimirEnderecosLista(lst, 1);
    printf("\n");
    
    printf("Criando celula, com conteudo=100, e inserindo-a no inicio da lista sem cabeca anteriormente criada: ");
    Celula* cabeca = criarCelula(100);
    inserirCelInicio(&lst, cabeca);
    imprimirConteudoLista(lst);
    printf("\n");
    imprimirEnderecosLista(lst, 1);
    printf("\n");

    printf("Criando celula, com conteudo=200, e inserindo-a no inicio da lista anteriormente criada. \n");
    printf("Dessa vez, a celula com conteudo=100 sera considerada cabeca: ");
    Celula* celula = criarCelula(200);
    inserirCelInicioCabeca(lst, celula);
    imprimirConteudoLista(lst);
    printf("\n");
    imprimirEnderecosLista(lst, 1);
    printf("\n");

    printf("Buscando valor em lista encadeada. O endereco da celula que possui o valor 7 e: ");
    printf("%p\n\n", buscarValor(lst, 7));

    printf("Inserindo uma celula em lista encadeada logo apos a celula de valor 9: ");
    inserirCel(lst, 9);

    imprimirConteudoLista(lst);
    printf("\n");
    imprimirEnderecosLista(lst, 1);
    printf("\n");

    printf("Se tento inserir celula apos valor que nao existe na lista, tenho o retorno: ");
    inserirCel(lst, 10);
    
    printf("\nDeletanto a primeira celula da lista, tenho: ");
    deleteCel(&lst);

    imprimirConteudoLista(lst);
    printf("\n");
    imprimirEnderecosLista(lst, 1);
    printf("\n");

}
