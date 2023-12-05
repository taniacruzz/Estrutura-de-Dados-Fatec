#include <stdio.h>
#include <stdlib.h>

// criar estrutura de pila
typedef struct CarPile {
    struct Car* topCar;
} CarPile;

typedef struct Car {
    int weight;
    struct Car* baseCar;
} Car;

Car* createCar(int weight) {
    Car* p_car = (Car*)malloc(sizeof(Car));
    p_car->weight = weight;
    p_car->baseCar = NULL;
    return p_car;
}

CarPile* createCarPile () {
    CarPile* p_pile = (CarPile*)malloc(sizeof(CarPile));
    p_pile->topCar = NULL;
    return p_pile;
}

void insertCar (Car* p, CarPile* pPile) {
    p->baseCar=pPile->topCar;
    pPile->topCar = p;
}

void populatePile(CarPile* p_Pile, int nCars, int baseWeight) {
    insertCar(createCar(baseWeight), p_Pile);
    if (nCars>1) {populatePile(p_Pile, nCars-1, baseWeight - 2);}
}

void deleteCar (CarPile* pPile) {
    Car* p_reserva = pPile->topCar;
    pPile->topCar = pPile->topCar->baseCar;
    free(p_reserva);
}

// tira o carro da pilha sem deletá-lo.
Car* takeOutCar (CarPile* pPile) {
    Car* p_reserva = pPile->topCar;
    pPile->topCar = pPile->topCar->baseCar;
    p_reserva->baseCar = NULL;
    return p_reserva;
}

void moveCar(CarPile* p_origin, CarPile* p_destiny) {
    if (p_origin->topCar == NULL) {return;}
    if (p_destiny->topCar != NULL && (p_destiny->topCar)->weight < (p_origin->topCar)->weight) {return;}
    Car* p_removedCar = takeOutCar(p_origin);
    insertCar(p_removedCar, p_destiny);
}


void printPile(Car* p_topCar) {
    if (p_topCar == NULL) {printf(" |______| \n");}
    else if (p_topCar->baseCar != NULL) {
        printf(" |__%d__| \n", p_topCar->weight);
        printPile(p_topCar->baseCar);
    } else {
        printf(" |__%d__| \n", p_topCar->weight);
    }
}

void printGame(Car* pCar_finalPile, Car* pCar_startPile, Car* pCar_middlePile) {
    printf("Configuracao do Ferro Velho\n\n");
    printPile(pCar_startPile);
    printf("----------------------------\n");
    printPile(pCar_middlePile);
    printf("----------------------------\n");
    printPile(pCar_finalPile);
    printf("\n\n");
    
}


int main(){
    CarPile* finalPile = createCarPile();
    CarPile* startPile = createCarPile();
    CarPile* middlePile = createCarPile();

    populatePile(finalPile, 3, 20);
    populatePile(startPile, 1, 19);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);

    moveCar(finalPile, startPile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);
   
    moveCar(finalPile, middlePile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);

    moveCar(startPile, middlePile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);
    
    moveCar(startPile, finalPile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);
    
    moveCar(middlePile, startPile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);
    
    moveCar(middlePile, finalPile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);
    
    moveCar(startPile, finalPile);
    printGame(finalPile->topCar, startPile->topCar, middlePile->topCar);


}