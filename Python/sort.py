# melhor caso: quando estiver já em ordem
def selecao(lista):
    for j in range(len(lista)-1, -1, -1):
        posicao = j
        maior = lista[j]
        for i in range(0, j):
            if lista[i] > maior:
                maior = lista[i]
                posicao = i
        lista[posicao] = lista[j]
        lista[j] = maior
    return lista

def insercao(lista):
    ordenada = []
    for i in range (0, len(lista)):
        ordenada.append(lista[i])
        for j in range(len(ordenada)-2, -1, -1):
            if lista[i]<ordenada[j]:
                ordenada[j+1] = ordenada[j]
                ordenada[j] = lista[i]
            else: break
    return ordenada

# #shell
# lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
# lista=[88, 15, 66, 55, 98, 36, 40, 65, 22, 71, 62]

def shell (lista, passo):
    reserva=0
    # print(lista)
    for i in passo:
        # print("passo:", i)
        for j in range (0, len(lista) - i):
            if lista[j] > lista[j+i]:
                reserva = lista[j]
                lista[j] = lista[j+i]
                lista[j+i] = reserva
            # print(lista)
    return lista

#merge
# hipotese: tenho uma lista de 3 componentes
import math


lista = [10, 3, 5, 20, 4, 1]

def merge(lista):
    if len(lista) > 1:
        lista3 = []
        lista1 = lista[0: math.ceil(len(lista)/2)]
        lista2 = lista[math.ceil(len(lista)/2): len(lista)]
        if len(lista1) > 1:
            lista1 = merge(lista1)
        if len(lista2) > 1:
            lista2 = merge(lista2)
        while (len(lista1) > 0 or (len(lista2)) > 0):
            if len(lista1)==0:
                for num in lista2: 
                    lista3.append(num)
                lista2=[]
            elif len(lista2)==0:
                for num in lista1: 
                    lista3.append(num)
                lista1 = []
            else:
                if lista1[0] > lista2[0]:
                    lista3.append(lista2.pop(0))
                else:
                    lista3.append(lista1.pop(0))
        return lista3

    return lista

lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
print(f"a lista {lista} ordenada com seleção fica: {selecao(lista)}")
lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
print(f"a lista {lista} ordenada com inserção fica: {insercao(lista)}")
lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
print(f"a lista {lista} ordenada com shell fica: {shell(lista, [4, 2, 1])}")
lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
print(f"a lista {lista} ordenada com merge fica: {merge(lista)}")