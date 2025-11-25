memoria = {1: 0, 2: 1}

def fibonacci(n):
    if n in memoria:
        return memoria[n]
    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return memoria[n]

posiciones = [7, 21, 40, 71, 94]

for p in posiciones:
    print("Fibonacci({}) = {}".format(p, fibonacci(p)))
