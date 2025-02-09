#include <iostream>
#include <bitset>
#include <vector>

//Calculadora binaria

bool esBinario(std::string bin) {
    for (char c : bin) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

//binario a entero
int binarioADecimal(std::string binario) {
    return std::bitset<32>(binario).to_ulong(); //sin decimales
}

std::string decimalABinario(int decimal) {
    return std::bitset<32>(decimal).to_string(); //string 32 bites sin decimales
}

std::string limpiarBinario(std::string bin) {
    size_t pos = bin.find('1');
    return (pos != std::string::npos) ? bin.substr(pos) : "0"; //Si todo es cero, devuelve solo un cero
}

int main() {
    int opcionNumeros, opcionOperacion;
    std::vector<int> numeros;
    std::string binario;

    do {
        //menú numeros
        std::cout << "\n======= MENU PRINCIPAL =======\n";
        std::cout << "1. Operar con 2 numeros binarios\n";
        std::cout << "2. Operar con 3 numeros binarios\n";
        std::cout << "3. Operar con 4 numeros binarios\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionNumeros;

        if (opcionNumeros >= 1 && opcionNumeros <= 3) {
            int cantidad = opcionNumeros + 1;
            numeros.clear();

            for (int i = 0; i < cantidad; i++) {
                do {
                    std::cout << "Ingrese el numero binario " << (i + 1) << ": ";
                    std::cin >> binario;
                    if (!esBinario(binario))
                        std::cout << "Error: Ingrese solo numeros binarios (0s y 1s).\n";
                } while (!esBinario(binario));
                numeros.push_back(binarioADecimal(binario));
            }

            //menú operaciones
            do {
                std::cout << "\n=== MENU DE OPERACIONES ===\n";
                std::cout << "1. Suma\n";
                std::cout << "2. Resta\n";
                std::cout << "3. Multiplicacion\n";
                std::cout << "4. Division Entera\n";
                std::cout << "5. AND\n";
                std::cout << "6. OR\n";
                std::cout << "7. XOR\n";
                std::cout << "8. XNOR\n";
                std::cout << "9. Volver al Menu Principal\n";
                std::cout << "Seleccione una operacion: ";
                std::cin >> opcionOperacion;

                int resultado = numeros[0];

                switch (opcionOperacion) {
                    case 1:
                        for (int i = 1; i < cantidad; i++) resultado += numeros[i];
                        std::cout << "Resultado en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 2:
                        for (int i = 1; i < cantidad; i++) resultado -= numeros[i];
                        std::cout << "Resultado en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 3:
                        for (int i = 1; i < cantidad; i++) resultado *= numeros[i];
                        std::cout << "Resultado en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 4:
                        for (int i = 1; i < cantidad; i++) {
                            if (numeros[i] == 0) {
                                std::cout << "Error: División por cero no permitida.\n";
                                resultado = -1;
                                break;
                            }
                            resultado /= numeros[i]; //división sin decimales
                        }
                        if (resultado != -1)
                            std::cout << "Resultado en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 5:
                        for (int i = 1; i < cantidad; i++) resultado &= numeros[i];
                        std::cout << "Resultado AND en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 6:
                        for (int i = 1; i < cantidad; i++) resultado |= numeros[i];
                        std::cout << "Resultado OR en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 7:
                        for (int i = 1; i < cantidad; i++) resultado ^= numeros[i];
                        std::cout << "Resultado XOR en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 8:
                        for (int i = 1; i < cantidad; i++) resultado ^= numeros[i];
                        resultado = ~resultado; //niega el nor
                        std::cout << "Resultado XNOR en binario: " << limpiarBinario(decimalABinario(resultado)) << std::endl;
                        break;
                    case 9:
                        std::cout << "Volviendo al Menú Principal...\n";
                        break;
                    default:
                        std::cout << "Opción no válida. Intente de nuevo.\n";
                }
            } while (opcionOperacion != 9);
        } else if (opcionNumeros == 4) {
            std::cout << "Saliendo del programa...\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcionNumeros != 4);

    return 0;
}