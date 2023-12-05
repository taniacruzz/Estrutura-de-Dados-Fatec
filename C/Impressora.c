#include <stdio.h>
#include <stdlib.h>

typedef struct Doc {
    int content;
    struct Doc* nextDoc;
    struct Doc* lastDoc;
} Doc;


// aqui quando eu for imprimir tudo, eu terei problema, creio que a questão principal é que não devo usar 
// a função create sequence; tenho que pensar na possiblidade de imprimir tudo e criar tudo.
// Doc* createSequenceToPrint (int count, Doc** p_pFim) {
//     if(count == 0) {return NULL;}
//     Doc* pDoc = malloc(sizeof(Doc));
//     pDoc->content = rand() % 10;
//     if (count == 1) {
//         pDoc->nextDoc = NULL;
//         *p_pFim = pDoc;
//         }
//     if (count > 1) {
//         pDoc->nextDoc = createSequenceToPrint(count - 1, p_pFim);}
//     return pDoc;
// }



void checkSequence (Doc* pDoc) {
    if(pDoc == NULL) {printf("Nao ha documento para impressao\n");}
    else if(pDoc->nextDoc != NULL) {
        printf("%d\n", pDoc->content);
        checkSequence(pDoc->nextDoc);
    } else {
        printf("%d\n--------------\n", pDoc->content);
    }
}

void toPrint (Doc** p_pFirst, Doc** p_pLast) {
    Doc* pReserva = *p_pFirst;
    *p_pFirst=(pReserva->nextDoc);
    free(pReserva);
    if (p_pFirst == NULL) {*p_pLast = NULL;}
}

// void addDocToPrint (Doc* pFirstDoc) {
//     if ((pFirstDoc->nextDoc)==NULL){
//         Doc* p = malloc(sizeof(Doc));
//         p->content = rand()%10;
//         p->nextDoc = NULL;
//         pFirstDoc->nextDoc=p;
//     }
//     else(addDocToPrint(pFirstDoc->nextDoc));
// }
void addDocToPrint (Doc** p_pLast, Doc** p_pFirst) {
        Doc* p = malloc(sizeof(Doc));
        p->content = rand()%10;
        p->nextDoc = NULL;
        if (*p_pFirst == NULL) {
            *p_pFirst = p;
            *p_pLast = p;
        }
        else {

        (*p_pLast)->nextDoc = p;
        *p_pLast = p;
       
        }
    
}

int main() {
    
    Doc* pLast = NULL;
    Doc* pFirst = NULL;
    // Doc* pFirstDoc = createSequenceToPrint(7, &pFim);

    printf("Criando sequencia para impressao com 7 documentos: \n");
    for (int i = 0; i < 7; i++) {
        addDocToPrint(&pLast, &pFirst);
    }
    checkSequence(pFirst);
    printf("\n");
   
    printf("Imprimindo primeiro documento da sequencia: \n");
    toPrint(&pFirst, &pLast);
    checkSequence(pFirst);
    printf("\n");
   
    printf("Imprimindo todos os documentos: \n");
    while (pFirst != NULL) {
        toPrint(&pFirst, &pLast);
    }
    checkSequence(pFirst);
    printf("\n");
    
     printf("Criando sequencia para impressao com 10 documentos:\n");
     for (int i = 0; i < 10; i++) {
        addDocToPrint(&pLast, &pFirst);
    }
    checkSequence(pFirst);
    printf("\n");
}

