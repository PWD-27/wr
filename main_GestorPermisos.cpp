#include <iostream>
#include <bitset>

//constantes para de estado
const int ESTADO_ON = 0b100;        // Bit 2 (Encendido)
const int ESTADO_ECO = 0b010;       // Bit 1 (Ahorro de Energía)
const int ESTADO_SECURITY = 0b001;  // Bit 0 (Modo de Seguridad)

//estado actual
void mostrarEstados(int estado) {
    std::cout << "Estado actual (en binario): " << std::bitset<3>(estado) << "\n";
    std::cout << "Estado actual (en decimal): " << estado << "\n";

    std::cout << "Estados activos: ";
    if (estado & ESTADO_ON) std::cout << "ON ";
    if (estado & ESTADO_ECO) std::cout << "ECO ";
    if (estado & ESTADO_SECURITY) std::cout << "SECURITY ";
    if (estado == 0) std::cout << "Ninguno";
    std::cout << "\n";
}

int main() {
    int estado = 0b000; //inicialmente todos los estados estan desactivados
    int opcion;

    //estados
    std::cout << " Representacion de estados del dispositivo \n";
    std::cout << "Bit 2 -> Encendido (ON)\n";
    std::cout << "Bit 1 -> Ahorro de Energía (ECO)\n";
    std::cout << "Bit 0 -> Modo de Seguridad (SECURITY)\n\n";

    do {
        std::cout << "\n Menu de Estados del Dispositivo \n";
        std::cout << "1. Activar Encendido (ON)\n";
        std::cout << "2. Desactivar Encendido (ON)\n";
        std::cout << "3. Activar Modo ECO\n";
        std::cout << "4. Desactivar Modo ECO\n";
        std::cout << "5. Activar Modo Seguridad\n";
        std::cout << "6. Desactivar Modo Seguridad\n";
        std::cout << "7. Ver estado actual del dispositivo\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opcion: ";

        std::cin >> opcion;

        //validar respuesta
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Entrada no valida. Ingrese un numero entre 1 y 8.\n";
            continue;
        }

        switch (opcion) {
            case 1: // Activar ON
                estado |= ESTADO_ON;
                std::cout << "Dispositivo ENCENDIDO.\n";
                break;
            case 2:
                estado &= ~ESTADO_ON;
                std::cout << "Dispositivo APAGADO.\n";
                break;
            case 3:
                estado |= ESTADO_ECO;
                std::cout << "Modo Ahorro de Energía ACTIVADO.\n";
                break;
            case 4:
                estado &= ~ESTADO_ECO;
                std::cout << "Modo Ahorro de Energía DESACTIVADO.\n";
                break;
            case 5:
                estado |= ESTADO_SECURITY;
                std::cout << "Modo Seguridad ACTIVADO.\n";
                break;
            case 6:
                estado &= ~ESTADO_SECURITY;
                std::cout << "Modo Seguridad DESACTIVADO.\n";
                break;
            case 7:
                mostrarEstados(estado);
                break;
            case 8: // Salir
                std::cout << "Saliendo del sistema de gestión de estados.\n";
                break;
            default:
                std::cout << "Opcion no válida. Vuelvalo a intentar.\n";
                break;
        }
    } while (opcion != 8);

    return 0;
}