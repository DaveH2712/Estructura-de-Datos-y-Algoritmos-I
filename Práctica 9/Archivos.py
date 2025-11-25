-Variables_y_cadenas.py
nombre = "Heber"
edad = 22
PI = 3.1416

print("Mi nombre es {}".format(nombre))
print("Tengo {} años".format(edad))

cadena = "Hola\nMundo"
print(cadena)

cadena2 = "UNAM"
cadena3 = "FI"
print("Concatenación con format: {} {}".format(cadena2, cadena3))

a = 10
b = 4

-Operadores.py
print("Suma:", a + b)
print("Resta:", a - b)
print("Multiplicación:", a * b)
print("División:", a / b)

print("a > b:", a > b)
print("a == 10:", a == 10)
print("a != b:", a != b)

print("a > 5 and b < 10:", a > 5 and b < 10)
print("not(a > b):", not(a > b))

-Listas_tuplas_diccionarios.py
lista = [1, 2, 3, 4]
print("Lista:", lista)
print("Primer elemento:", lista[0])
lista.append(99)
print("Lista modificada:", lista)

tupla = (10, 20, 30)
print("\nTupla:", tupla)

dic = {"nombre": "Heber", "edad": 22}
print("\nDiccionario:", dic)
print("Nombre:", dic["nombre"])
dic["edad"] = 23
print("Edad modificada:", dic["edad"])

-Funciones.py
def suma(a, b):
    return a + b

def datos_completos(nombre, edad):
    return "Nombre: {}, Edad: {}".format(nombre, edad)

x = suma(5, 7)
print("Resultado de la suma:", x)

info = datos_completos("Heber", 22)
print(info)

-Estructuras_control.py
x = 10

if x > 5:
    print("x es mayor a 5")
else:
    print("x no es mayor a 5")

for i in range(3):
    print("Iteración", i)

contador = 0
while contador < 3:
    print("Contador:", contador)
    contador += 1

-Biblioteca_numpy_matplotlib.py
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(0, 10, 100)
y = np.sin(x)

plt.plot(x, y)
plt.title("Gráfica seno(x)")
plt.xlabel("x")
plt.ylabel("sin(x)")
plt.show()

-Lectura_datos.py
print("Hola, ¿cómo te llamas?")
nombre = input()
print("Buen día {}".format(nombre))

print("\n---Calculadora---")
print("1- Sumar")
print("2- Restar")
print("3- Multiplicar")
print("4- Dividir")
print("5- Salir")

op = int(input("Opción: "))

if op == 1:
    a = float(input("Valor 1: "))
    b = float(input("Valor 2: "))
    print("Resultado:", a + b)

elif op == 2:
    a = float(input("Valor 1: "))
    b = float(input("Valor 2: "))
    print("Resultado:", a - b)

elif op == 3:
    a = float(input("Valor 1: "))
    b = float(input("Valor 2: "))
    print("Resultado:", a * b)

elif op == 4:
    a = float(input("Valor 1: "))
    b = float(input("Valor 2: "))
    print("Resultado:", a / b)

else:
    print("Saliendo...")
