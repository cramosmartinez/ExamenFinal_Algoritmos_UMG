//Carlos Javier Ramos Martinez, Seccion D, Variante A, Ecastillos@miumg.com.gt
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Constantes de conversión
const double QUETZAL_TO_DRAM = 0.20;
const double QUETZAL_TO_DOLLAR = 7.71;
const double QUETZAL_TO_PESO = 0.38;

// Variables globales
double monto = 0.0;
int opcion = 0;
ofstream archivoResultados("ResultadoConversion.txt");

void mostrarMenu() {
    cout << "Menu de Conversion de Moneda" << endl;
    cout << "1. Ingreso de monto en quetzales" << endl;
    cout << "2. Convertidor a Dram Armenio" << endl;
    cout << "3. Convertidor a Dolares Americanos" << endl;
    cout << "4. Convertidor a Pesos Mexicanos" << endl;
    cout << "5. Salir" << endl;
}

double convertirQuetzales(double monto, double tasaConversion) {
    return monto / tasaConversion;
}

double Fnc_convertir_dam(double monto) {
    return convertirQuetzales(monto, QUETZAL_TO_DRAM);
}

double Fnc_convertir_Dol(double monto) {
    return convertirQuetzales(monto, QUETZAL_TO_DOLLAR);
}

double Fnc_pesos_m(double monto) {
    return convertirQuetzales(monto, QUETZAL_TO_PESO);
}

void ingresoMonto() {
    cout << "Ingrese el monto en quetzales: ";
    cin >> monto;
}

void guardarResultado(const string& conversion, double resultado) {
    archivoResultados << "Monto en " << conversion << ": " << resultado << endl;
}

void procesarOpcion() {
    double resultado;
    switch (opcion) {
    case 1:
        ingresoMonto();
        break;
    case 2:
        resultado = Fnc_convertir_dam(monto);
        cout << "Monto en Dram Armenio: " << resultado << endl;
        guardarResultado("Dram Armenio", resultado);
        break;
    case 3:
        resultado = Fnc_convertir_Dol(monto);
        cout << "Monto en Dolares Americanos: " << resultado << endl;
        guardarResultado("Dolares Americanos", resultado);
        break;
    case 4:
        resultado = Fnc_pesos_m(monto);
        cout << "Monto en Pesos Mexicanos: " << resultado << endl;
        guardarResultado("Pesos Mexicanos", resultado);
        break;
    case 5:
        cout << "Saliendo del programa..." << endl;
        break;
    default:
        cout << "Opcion no valida. Intente de nuevo." << endl;
        break;
    }
}

int main() {
    if (!archivoResultados) {
        cerr << "Error al abrir el archivo de resultados." << endl;
        return 1;
    }

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        procesarOpcion();
    } while (opcion != 5);

    archivoResultados.close();
    return 0;
}
