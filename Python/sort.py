# seleção
lista = [5, 1, 76, 3, 9, 80, 1, 75]
for j in range(len(lista)-1, -1, -1):
    posicao = j
    maior = lista[j]
    for i in range(0, j):
        if lista[i] > maior:
            maior = lista[i]
            posicao = i
    lista[posicao] = lista[j]
    lista[j] = maior
print(lista)
