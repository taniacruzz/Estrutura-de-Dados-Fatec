# # seleção
# lista = [5, 1, 76, 3, 9, 80, 1, 75]
# for j in range(len(lista)-1, -1, -1):
#     posicao = j
#     maior = lista[j]
#     for i in range(0, j):
#         if lista[i] > maior:
#             maior = lista[i]
#             posicao = i
#     lista[posicao] = lista[j]
#     lista[j] = maior
# print(lista)

# #inserção
# lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
# ordenada = []
# for i in range (0, len(lista)):
#     ordenada.append(lista[i])
#     for j in range(len(ordenada)-2, -1, -1):
#         if lista[i]<ordenada[j]:
#             ordenada[j+1] = ordenada[j]
#             ordenada[j] = lista[i]
#         else: break
# print(ordenada)

#shell
# lista = [5, 100, 1, 76, 300, 3, 9, 80, 1, 75, 200]
lista=[88,	15,	66,	55,	98,	36,	40,	65,	22,	71,	62]

shell = [4, 2, 1]
reserva=0
print(lista)
for i in shell:
    print("passo:", i)
    for j in range (0, len(lista) - i):
        if lista[j] > lista[j+i]:
            reserva = lista[j]
            lista[j] = lista[j+i]
            lista[j+i] = reserva
        print(lista)
print(lista)
