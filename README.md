# Practica_2_EDL_Q

• Descripción de tu implementación de las funciones in2pos y evaluar.
• Análisis del trabajo que realizaste.
• Conclusiones.

---

## Funcion in2pos
La funcion es de tipo String, recibe como parametro un String con una expresion infija,
para empezar creamos una variable String vacia llamada Posfija
Creamos una pila de caracteres (char) llamada __pilaops__, la idea de esta pila es que se guarden los operadores,
asi podemos ir eliminandolos despues de usarlos.
En la linea 43 creamos un for para iterar sobre todos los char de __infija__, dentro usaremos 4 estructuras __IF ELSE__.
1. La primer estructura verifica si el token es un numero.
2. La segunda nota si es un parentesis izquierdo, si lo es hacen push del token a pilaops
3. La tercer estructura nota si es un parentesis derecho, de ser asi con un while que itera mientras
__pilaops__ no este vacia y que la cima de la pila no sea un parentesis izquierdo.
4. La cuarta estructura if verifica si es un operador, aqui al usar un while y un metodo extra que se creo en el mismo archivo llamado __Jerarquia__ 

`

    if (valor == '*' || valor == '/')
        return 2;
    if (valor == '+' || valor == '-')
        return 1;
    return 0;


verificamos el orden en que se haran las operaciones.
como ultimo usamos un while que iterara mientras ***pilaops*** no este vacia,
si la cima de la pila tiene un parentesis izquierdo haremos pop de la pila,
si no es un parentesis izquierdo meteremos la cima de la pila en la expresion posfija.

Al final del metodo regresamos el String posfija con la expresion.

## Funcion Evaluar
---
La función evaluar es de tipo float para garantizar la precisión de cualquier resultado de la operación. Recibe la expresión en notación posfija como parámetro.

* Se creo una variable __float__ para el resultado
* Una pila de __char__ llamada pilaops
* Una pila del tipo __float__ llamada __*numeros*__, en esta guardaremos los valores que se usaran en las operaciones.

En la linea 104 usamos un __for__ para iterar sobre toda la expresion.
dentro de este usando la funcion __*isalnum*__, verificamos si el token es un numero. Dentro del __if__ creamos una variable auxiliar donde se guarda el digito, paso siguiente lo introducimos en la pila.

En la linea 115 usaremos un switch para verificar si el *token* es un operador, dentro de este *switch* en un *IF* verificaremos
si la pila de numeros contiene al menos 2 numeros, si no es asi no se realizara una operacion.

Si el *IF* es *true*  se crea una variable auxilar de tipo *float*, en esta guardaremos la cima de la pila,
para luego hacerle pop, siguiendo asi con el siguiente numero, este algoritmo nos permite guardar los 2 valores con los que realizaremos la operacion.

Crearemos un *switch* anidado dentro del antes mencionado donde ahora se verifica que operador usar.
Usando 4 *cases* metemos el resultado en la variable res, lo unico importante de mencionar es que para la division
se verifica si esta es entre 0 pues un mal uso de esta operacion romperia el codigo.

Por ultimo hacemos push al resultado, significa que volvemos a introducir a la pila el resultado para futuras operaciones.

Al final del metodo usamos un __IF__ y __ELSE__ para verificar que la pila numeros solo contenga un numero, 
si esto es cierto la expresion se termino de evaluar y podemos hacer return a la cima de la pila, de otra forma
regresaremos 0;


  
                

# Analisis del trabajo realizado

El desarrollo de ambos metodos se realizo con una estructura LIFO, es decir que se utilizo una ***pila***

___¿Porque una pila?___
Debido a la estructura LIFO es posible realizar el algoritmo, 
si hubieramos elegido una cola de tipo FIFO el algoritmo no hubiera funcionado. la idea de la pila es que podamos guardar los operadores, y gracias al metodo ***top*** podemos ir sacando los operadores cuando se necesiten,esto para la funcion ***in2pos***.

Para la funcion ***Evaluar*** utilizamos 2 pilas, la idea es replicar el algoritmo de  ___in2pos___ para poder guardar los operadores, pero esta vez utilizamos una segunda para poder guardar los operandos, de esta forma podemos controlar que solo al tener 2 o mas valores en la pila de operandos se pueda realizar una operacion, de esta forma creamos un metodo robusto.