#include <iostream>
#include <vector>
using namespace std; //optimizar codigo y no usar std:: en cada parte

float calcularPromedio(const vector<float>& notas) {
    float suma = 0;
    for (float nota : notas) {
        suma += nota;
    }
    return suma / notas.size();
}

int main() {

    vector<float> notas(6); // Almacenamiento de notas
    float promedio;

    cout << "\nPromediar Notas\n";

    for (int i = 0; i < 6; i++) {
        do {
            cout << "Ingrese su nota " << (i + 1) << " (0 - 5): ";
            cin >> notas[i];

            if (notas[i] < 0 || notas[i] > 5) {
                cout << "Nota invalida. Debe estar entre 0 y 5.\n";
            }
        } while (notas[i] < 0 || notas[i] > 5);
    }

    promedio = calcularPromedio(notas);

    cout << "\nResultado \n";
    cout << "Promedio: " << promedio << "\n";

    if (promedio >= 2.9) {
        cout << "Has aprobado.\n";
    } else {
        cout << "Has reprobado.\n";
    }

    return 0;
}

