def insertion_sort(lista):
    for i in range(1, len(lista)):
        actual = lista[i]
        j = i - 1

        while j >= 0 and lista[j] > actual:
            lista[j + 1] = lista[j]
            j -= 1

        lista[j + 1] = actual

    return lista


n = int(input("Tamaño de la lista: "))
lista = []

print("Valores:")
for _ in range(n):
    lista.append(int(input()))

print("Lista original:", lista)
ordenada = insertion_sort(lista)
print("Lista ordenada:", ordenada)
