#include <iostream>
#include <string>

#include "posfija.h"

using namespace std;

int main() {
    string infija = "(3*(4+5)*(7-2))";
    string posfija = in2pos(infija);
    float resultado = evaluar(posfija);
    
    cout << "Expresión en notación infija: " << infija << endl;
    cout << "Expresión en notación posfija: " << posfija << endl;
    cout << "Evaluación: " << to_string(resultado) << endl;
    
    return EXIT_SUCCESS;
}