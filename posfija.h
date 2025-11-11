#ifndef POSFIJA_H
#define POSFIJA_H

#include <string>
#include "nodo.h"
#include "pila_dinamica.h"

/**
 * Convierte la expresión en <code>infija<\code> a notación posfija.
 * @param infija la expresión en notación infija.
 * @return un <code>string<code> la expresión en notación posfija.
 *
 **/

// con esto sabemos la jerarquia de las operaciones
int jerarquia(char valor)
{
    if (valor == '*' || valor == '/')
        return 2;
    if (valor == '+' || valor == '-')
        return 1;
    return 0;
}
// usamos esta funcion para saber si la pila tiene al menos 2 elementos
// cuando la pila tiene 2 o mas elementos se puede hacer una operacion
bool pila_tam_2(Pila<float> &pila)
{

    int tam = 0;
    tam = pila.getNumElementos();
    if (tam >= 2)
        return true;
    return false;
}

std::string in2pos(const std::string infija)
{
    // creamos una variable vacia String para guardar la expresion posfija
    std::string posfija = "";
    // creamos una pila para las operaciones
    Pila<char> pilaops;
    // iteramos sobre toda la expresion
    for (char token : infija)
    {
        // funcion que nota si el token es un espacio
        if (std::isdigit(token))
            posfija += token;
        // si encontramos un parentesis metemos el token en la pila
        else if (token == '(')
            pilaops.push(token);
        // si es parentesis derecho
        else if (token == ')')
        {
            // mientras la pila no este vacia y el tope de la pila no sea '('
            while (!pilaops.esVacia() && pilaops.top() != '(')
            {
                posfija += pilaops.top();
                pilaops.pop();
            }
            // si la pila no esta vacia y el tope es '('
            if (!pilaops.esVacia() && pilaops.top() == '(')
                pilaops.pop();
        }

        // si es un operador
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            // miestras la pila no este vacia y la cima no sea '(' y la jerarquia de la cima sea mayor que la del token
            while (!pilaops.esVacia() && pilaops.top() != '(' && jerarquia(pilaops.top()) >= jerarquia(token))
            {
                posfija += pilaops.top();
                pilaops.pop();
            }

            pilaops.push(token);
        }
    }
    // miestras la pila no este vacia
    while (!pilaops.esVacia())
    {
        // verifica que la cima sea '('
        if (pilaops.top() == '(')
        {
            pilaops.pop();
            continue;
        }
        posfija += pilaops.top();
        pilaops.pop();
    }

    return posfija;
}

/**
 * Evalúa la expresión en notación <code>posfja<\code>.
 * @param posfija la expresión que se quiere evaluar.
 * @return el resultado de la evaluación de la expresión.
 */
float evaluar(std::string posfija)
{
    float res;                 // aqui guardamos el resultado
    Pila<char> pilaops;        // creamos una pila para los operadores
    Pila<float> numeros;       // cree esta pila para los valores para operar
    for (char token : posfija) // iteramos toda la palabra
    {

        // Comparacion para saber si el token es un numero.
        if (std::isalnum(token))
        {
            int digito_int = token - '0'; // algoritmo que pasa de char a int
            numeros.push(digito_int);     // lo metemos en la pila
        }
        bool valor;

        switch (token)
        {
        case '*':
        case '/':
        case '+':
        case '-':
        {
            // verificamos si podemos realizar una operacion
            if (pila_tam_2(numeros))
            {
                // sacamos el primer valor para la operacion
                float op1 = numeros.top();
                numeros.pop();             // lo sacamos de la pila
                float op2 = numeros.top(); // el siguiente valor para la operacion
                numeros.pop();             // lo sacamos de la pila

                float resultado; // variable para el resultado

                // switch para ver que operacion se realiza
                switch (token)
                {
                case '*':
                    res = op2 * op1;
                    break;
                case '/':
                    if (op1 == 0)
                    {
                        std::cout << "Error: Division por cero." << std::endl;
                        res = 0;
                    }
                    res = op2 / op1;
                    break;
                case '+':
                    res = op2 + op1;
                    break;
                case '-':
                    res = op2 - op1;
                    break;
                default:
                    break;
                }

                // apilamos el resultado
                numeros.push(res);
            }

            break;
        }
        default:
            break;
        }
    }
    // si en la pila solo queda un numero, significa que ya esta el resultado
    if (numeros.getNumElementos() == 1)
    {
        return res = numeros.top();
    }
    else
    {
        return 0.0f;
    }
}

#endif // POSFIJA_H