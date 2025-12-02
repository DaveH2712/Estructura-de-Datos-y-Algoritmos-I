def cambio(monto, monedas):
    resultado = []
    for m in monedas:
        if monto >= m:
            num = monto // m
            monto -= num * m
            resultado.append((m, num))
    return resultado

monto = int(input("Monto a devolver: "))
monedas = [50, 20, 10, 5, 2, 1]

print("Cambio con Greedy:")
res = cambio(monto, monedas)

for m, n in res:
    print(f"{n} moneda(s) de {m}")
