import pickle
import os

archivo_memoria = "memoria_fibo.pkl"

if os.path.exists(archivo_memoria):
    with open(archivo_memoria, "rb") as f:
        memoria = pickle.load(f)
else:
    memoria = {0: 0, 1: 1}


def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]

    memoria[n] = fibonacci_top_down(n - 1) + fibonacci_top_down(n - 2)
    return memoria[n]


n = int(input("Ingresa n para Fibonacci (top-down): "))
print("Resultado:", fibonacci_top_down(n))

with open(archivo_memoria, "wb") as f:
    pickle.dump(memoria, f)

print("Valores almacenados en memoria:", memoria)
