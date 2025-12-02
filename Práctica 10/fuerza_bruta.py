import itertools
import time

digitos = "0123456789"

def fuerza_bruta(pass_objetiva):
    n = len(pass_objetiva)
    inicio = time.time()

    for comb in itertools.product(digitos, repeat=n):
        intento = "".join(comb)
        if intento == pass_objetiva:
            fin = time.time()
            return intento, fin - inicio

    return None, None

contraseñas = ["1234", "12345678", "1234567890"]

for c in contraseñas:
    encontrado, t = fuerza_bruta(c)
    print("Buscando contraseña de longitud", len(c))
    print("Encontrado:", encontrado)
    print("Tiempo:", round(t, 4), "seg\n")
