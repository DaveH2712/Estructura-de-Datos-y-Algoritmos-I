def quicksort(lista):
    if len(lista) <= 1:
        return lista

    pivote = lista[len(lista) // 2]
    menores = [x for x in lista if x < pivote]
    iguales = [x for x in lista if x == pivote]
    mayores = [x for x in lista if x > pivote]

    return quicksort(menores) + iguales + quicksort(mayores)


n = int(input("Tamaño de la lista: "))
lista = []

print("Ingresa los elementos:")
for _ in range(n):
    lista.append(int(input()))

print("Lista original:", lista)
ordenada = quicksort(lista)
print("Lista ordenada:", ordenada)
