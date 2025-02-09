#include <iostream>
//primer calculadora
int main() {
    int n1, n2, opcion, result;
    std::cout << " Por favor ingrese un numero entero: " ;
    std::cin >> n1;
    std::cout << " Por favor ingrese un numero entero: " ;
    std::cin >> n2;
    do {
        std::cout << "\nMenu Operaciones: \n";
        std::cout << "1. Add \n";
        std::cout << "2. Subtract \n";
        std::cout << "3. Multiply \n";
        std::cout << "4. Divide \n";
        std::cout << "5. Modulo \n";
        std::cout << "6. Exit\n";
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                result = n1+n2;
            std::cout << "\nEl resultado de la suma es: " << result <<
           std::endl;
            break;
            case 2:
                result = n1-n2;
            std::cout << "\nEl resultado de la resta es: " << result <<
           std::endl;
            break;
            case 3:
                result = n1*n2;
            std::cout << "\nEl resultado de la multiplicacion es: " <<
           result << std::endl;
            break;
            case 4:
                result = n1/n2;
            std::cout << "\nEl resultado de la division es: " << result
           << std::endl;
            break;
            case 5:
                result = n1%n2;
            std::cout << "\nEl resultado del modulo es: " << result <<
           std::endl;
            break;
            case 6:
                std::cout << "Saliendo del programa" << std::endl;
            break;
            default:
                std::cout << "\nopcion no valida" << std::endl;
        }
    } while (opcion != 6);
 return 0;
}
