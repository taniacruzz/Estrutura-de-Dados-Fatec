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

Car* createCar() {
    Car* p_car = (Car*)malloc(sizeof(Car));
    p_car->weight = rand() % 1000;
    p_car->baseCar = NULL;
    return p_car;
}

CarPile* createCarPile () {
    CarPile* p_pile = (CarPile*)malloc(sizeof(CarPile));
    p_pile->topCar = NULL;
    return p_pile;
}

void insertCar (CarPile* pPile) {
    Car* p = createCar();
    p->baseCar=pPile->topCar;
    pPile->topCar = p;
}

void deleteCar (CarPile* pPile) {
    Car* p_reserva = pPile->topCar;
    pPile->topCar = pPile->topCar->baseCar;
    free(p_reserva);
}

Car* takeOutCar (CarPile* pPile) {
    Car* p_reserva = pPile->topCar;
    pPile->topCar = pPile->topCar->baseCar;
    return p_reserva;
}

void moveCar(CarPile* p_origin, CarPile* p_destiny)


int main(){
    Car* finalPile = createCarPile();
    Car* startPile = createCarPile();
    Car* middlePile = createCarPile();


}