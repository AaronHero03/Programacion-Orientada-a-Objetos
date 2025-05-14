# Sobrecarga de Operadores en C++

Este recurso de aprendizaje ofrece una guía completa para comprender y aplicar la **sobrecarga de operadores en C++**, abarcando desde lo básico hasta conceptos avanzados. Cada sección incluye definición, sintaxis, casos de uso, errores comunes y ejemplos funcionales.

---

## Niveles de Aprendizaje

### 🟢 Nivel Básico

#### 1. Sobrecarga de Operadores Binarios
- **Definición**: Permite redefinir operadores como +, -, *, etc., para que funcionen con objetos de una clase definida por el usuario.
- **Sintaxis**:
```cpp
Tipo operator+(const Clase& otro);
```
- **Casos de uso**: Sumar objetos como puntos, vectores o unidades.
- **Errores comunes**:
  - No devolver un nuevo objeto.
  - No declarar correctamente los parámetros como `const`.
- **Ejemplo**: [ejemplo1.cpp](../ejemplos/ejemplo1.cpp)

#### 2. Sobrecarga de Operadores de Comparación
- **Definición**: Permite comparar objetos personalizados mediante operadores como ==, !=, <, >.
- **Sintaxis**:
```cpp
bool operator==(const Clase& otro);
```
- **Casos de uso**: Comparar clases como libros, usuarios, etc.
- **Errores comunes**:
  - Comparar punteros en lugar de contenido.
  - No usar const.
- **Ejemplo**: [ejemplo2.cpp](../ejemplos/ejemplo2.cpp)

#### 3. Sobrecarga del Operador de Entrada/Salida
- **Definición**: Permite mostrar o leer objetos directamente con cout y cin.
- **Sintaxis**:
```cpp
friend ostream& operator<<(ostream& os, const Clase& obj);
```
- **Casos de uso**: Imprimir objetos de manera personalizada.
- **Errores comunes**:
  - No usar friend.
  - No retornar ostream&.
- **Ejemplo**: [ejemplo3.cpp](../ejemplos/ejemplo3.cpp)

---

### 🟡 Nivel Intermedio

#### 4. Sobrecarga de Operadores Unarios
- **Definición**: Redefine operadores como ++, --, !, - para que trabajen sobre un solo objeto.
- **Sintaxis**:
```cpp
Clase operator++(int);
```
- **Casos de uso**: Contadores personalizados, iteradores, etc.
- **Errores comunes**:
  - No distinguir entre pre y post incremento.
  - No devolver correctamente la copia.
- **Ejemplo**: [ejemplo4.cpp](../ejemplos/ejemplo4.cpp)

#### 5. Sobrecarga del Operador de Asignación
- **Definición**: Permite copiar el contenido de un objeto a otro, especialmente cuando hay memoria dinámica.
- **Sintaxis**:
```cpp
Clase& operator=(const Clase& otra);
```
- **Casos de uso**: Copia profunda para evitar que múltiples objetos apunten a la misma memoria.
- **Errores comunes**:
  - No verificar autoasignación.
  - No liberar recursos previos.
- **Ejemplo**: [ejemplo5.cpp](../ejemplos/ejemplo5.cpp)

---

### 🔴 Nivel Avanzado

#### 6. Operadores de Conversión de Tipo
- **Definición**: Permite convertir objetos en otros tipos, como de clase a int o double.
- **Sintaxis**:
```cpp
operator tipo() const;
```
- **Casos de uso**:Simplificar comparaciones y operaciones con tipos primitivos.
- **Errores comunes**:
  - Hacer conversiones implícitas peligrosas.
  - No marcar como explicit si se requiere control.
- **Ejemplo**: [ejemplo6.cpp](../ejemplos/ejemplo6.cpp)

---

## Caso real relacionado

En los años 90, el equipo de desarrollo de **Adobe Photoshop** tuvo que rediseñar su sistema de representación de puntos y vectores para mejorar el rendimiento del motor gráfico. La sobrecarga de operadores como `+`, `-` y `*` les permitió hacer que las operaciones matemáticas en objetos como `Pixel`, `Color` y `Vector2D` fueran más naturales, legibles y reutilizables, acelerando el desarrollo y depuración del software.

---

## Cómo usar este recurso

1. Explora el directorio `ejemplos/`.
2. Compila los archivos con `g++ ejemploX.cpp -o ejemploX`
3. Ejecuta cada ejemplo y analiza su salida.

---

## Etiquetas del Repositorio

- `C++`
- `operadores`
- `sobrecarga`
- `educativo`
- `ejemplos`
- `POO`
- `nivel-básico`
- `nivel-avanzado`

---

## Licencia

Este recurso está publicado bajo la Licencia MIT.
