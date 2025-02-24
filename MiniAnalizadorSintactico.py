from openpyxl import Workbook

# Definición de la clase Pila para el Ejemplo 1
class Pila:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None

    def top(self):
        if not self.is_empty():
            return self.items[-1]
        return None

    def muestra(self):
        return self.items

    def is_empty(self):
        return len(self.items) == 0

# Definición de la clase Lexico para el Ejemplo 2
class Lexico:
    def __init__(self, entrada):
        self.entrada = entrada
        self.indice = 0

    def sigSimbolo(self):
        if not self.terminado():
            simbolo = self.entrada[self.indice]
            self.indice += 1
            return simbolo
        return None

    def terminado(self):
        return self.indice >= len(self.entrada)

# Función para el Ejemplo 1
def ejemplo1():
    pila = Pila()
    pila.push(2)
    pila.push(3)
    pila.push(4)
    pila.push(5)
    pila_muestra = pila.muestra()
    top1 = pila.top()
    top2 = pila.top()
    pop1 = pila.pop()
    pop2 = pila.pop()

    # Crear una lista de resultados
    resultados = [
        ['Operación', 'Pila'],
        ['push(2)', str(pila_muestra)],
        ['push(3)', str(pila_muestra)],
        ['push(4)', str(pila_muestra)],
        ['push(5)', str(pila_muestra)],
        ['muestra()', str(pila_muestra)],
        ['top()', str(top1)],
        ['top()', str(top2)],
        ['pop()', str(pop1)],
        ['pop()', str(pop2)]
    ]
    return resultados

# Función para el Ejemplo 2
def ejemplo2(entrada):
    lexico = Lexico(entrada)
    simbolos = []
    while not lexico.terminado():
        simbolo = lexico.sigSimbolo()
        simbolos.append(simbolo)

    # Crear una lista de resultados
    resultados = [['Símbolo']]
    for simbolo in simbolos:
        resultados.append([simbolo])
    return resultados

# Crear un archivo Excel
wb = Workbook()

# Hoja para el Ejemplo 1
ws1 = wb.active
ws1.title = "Ejemplo1"
resultados_ejemplo1 = ejemplo1()
for row in resultados_ejemplo1:
    ws1.append(row)

# Hoja para el Ejemplo 2
ws2 = wb.create_sheet("Ejemplo2")
resultados_ejemplo2 = ejemplo2("a+b+c+d+e+f")
for row in resultados_ejemplo2:
    ws2.append(row)

# Guardar el archivo Excel
wb.save("simulacion_gramaticas.xlsx")

print("Archivo Excel generado exitosamente: 'simulacion_gramaticas.xlsx'")
