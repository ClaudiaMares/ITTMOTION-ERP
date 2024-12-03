#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Estructuras para los datos
struct Empleado {
    int id;
    string nombre;
    string posicion;
    string departamento;
    string correo;
};

struct Cliente {
    int id;
    string nombre;
    string correo;
    string telefono;
};

struct Venta {
    int id;
    string cliente;
    string producto;
    int cantidad;
    double precioTotal;
    string fecha;
};

struct Produccion {
    int id;
    string producto;
    int unidadesProducidas;
    string fecha;
};

struct Compra {
    int id;
    string proveedor;
    string producto;
    int cantidad;
    double costoTotal;
    string fecha;
};

struct Riesgo {
    int id;
    string tipo;
    string descripcion;
    string nivelRiesgo;
    string fecha;
};

struct Rendimiento {
    int id;
    string periodo;
    string indicador;
    double valor;
};

struct CadenaSuministro {
    int id;
    string proveedor;
    string producto;
    string estado;
};

// Funciones para manejar archivos
void guardarEnArchivo(const string& registro, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << registro << "\n";
        file.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }
}

void listarArchivo(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo " << filename << endl;
    }
}

// Funciones de registro
void agregarEmpleado() {
    Empleado empleado;
    cout << "Ingrese ID (número entero): ";
    while (!(cin >> empleado.id)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Ingrese Nombre: ";
    getline(cin, empleado.nombre);
    cout << "Ingrese Posición: ";
    getline(cin, empleado.posicion);
    cout << "Ingrese Departamento: ";
    getline(cin, empleado.departamento);
    cout << "Ingrese Correo: ";
    getline(cin, empleado.correo);

    string registro = to_string(empleado.id) + "," + empleado.nombre + "," + empleado.posicion + "," + empleado.departamento + "," + empleado.correo;
    guardarEnArchivo(registro, "empleados.txt");
    cout << "Empleado agregado exitosamente." << endl;
}

void registrarCliente() {
    Cliente cliente;
    cout << "Ingrese ID (número entero): ";
    while (!(cin >> cliente.id)) {
        cout << "Entrada inválida. Por favor, ingrese un número entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Ingrese Nombre: ";
    getline(cin, cliente.nombre);
    cout << "Ingrese Correo: ";
    getline(cin, cliente.correo);
    cout << "Ingrese Teléfono: ";
    getline(cin, cliente.telefono);

    string registro = to_string(cliente.id) + "," + cliente.nombre + "," + cliente.correo + "," + cliente.telefono;
    guardarEnArchivo(registro, "clientes.txt");
    cout << "Cliente registrado exitosamente." << endl;
}

void registrarCompra() {
    Compra compra;
    cout << "Ingrese ID: ";
    cin >> compra.id;
    cin.ignore();
    cout << "Ingrese Proveedor: ";
    getline(cin, compra.proveedor);
    cout << "Ingrese Producto: ";
    getline(cin, compra.producto);
    cout << "Ingrese Cantidad: ";
    cin >> compra.cantidad;
    cout << "Ingrese Costo Total: ";
    cin >> compra.costoTotal;
    cin.ignore();
    cout << "Ingrese Fecha (YYYY-MM-DD): ";
    getline(cin, compra.fecha);

    string registro = to_string(compra.id) + "," + compra.proveedor + "," + compra.producto + "," + to_string(compra.cantidad) + "," + to_string(compra.costoTotal) + "," + compra.fecha;
    guardarEnArchivo(registro, "compras.txt");
    cout << "Compra registrada exitosamente." << endl;
}

void registrarRiesgo() {
    Riesgo riesgo;
    cout << "Ingrese ID: ";
    cin >> riesgo.id;
    cin.ignore();
    cout << "Ingrese Tipo de Riesgo: ";
    getline(cin, riesgo.tipo);
    cout << "Ingrese Descripción: ";
    getline(cin, riesgo.descripcion);
    cout << "Ingrese Nivel de Riesgo (Bajo, Medio, Alto): ";
    getline(cin, riesgo.nivelRiesgo);
    cout << "Ingrese Fecha (YYYY-MM-DD): ";
    getline(cin, riesgo.fecha);

    string registro = to_string(riesgo.id) + "," + riesgo.tipo + "," + riesgo.descripcion + "," + riesgo.nivelRiesgo + "," + riesgo.fecha;
    guardarEnArchivo(registro, "riesgos.txt");
    cout << "Riesgo registrado exitosamente." << endl;
}

void registrarRendimiento() {
    Rendimiento rendimiento;
    cout << "Ingrese ID: ";
    cin >> rendimiento.id;
    cin.ignore();
    cout << "Ingrese Periodo: ";
    getline(cin, rendimiento.periodo);
    cout << "Ingrese Indicador: ";
    getline(cin, rendimiento.indicador);
    cout << "Ingrese Valor: ";
    cin >> rendimiento.valor;

    string registro = to_string(rendimiento.id) + "," + rendimiento.periodo + "," + rendimiento.indicador + "," + to_string(rendimiento.valor);
    guardarEnArchivo(registro, "rendimiento.txt");
    cout << "Rendimiento registrado exitosamente." << endl;
}

void registrarSuministro() {
    CadenaSuministro suministro;
    cout << "Ingrese ID: ";
    cin >> suministro.id;
    cin.ignore();
    cout << "Ingrese Proveedor: ";
    getline(cin, suministro.proveedor);
    cout << "Ingrese Producto: ";
    getline(cin, suministro.producto);
    cout << "Ingrese Estado: ";
    getline(cin, suministro.estado);

    string registro = to_string(suministro.id) + "," + suministro.proveedor + "," + suministro.producto + "," + suministro.estado;
    guardarEnArchivo(registro, "suministros.txt");
    cout << "Suministro registrado exitosamente." << endl;
}

// Menú principal
int main() {
    int opcion;
    do {
        cout << "\nERP ITT Motion Technologies\n";
        cout << "1. Agregar Empleado\n";
        cout << "2. Listar Empleados\n";
        cout << "3. Registrar Cliente\n";
        cout << "4. Listar Clientes\n";
        cout << "5. Registrar Compra\n";
        cout << "6. Listar Compras\n";
        cout << "7. Registrar Riesgo\n";
        cout << "8. Listar Riesgos\n";
        cout << "9. Registrar Rendimiento\n";
        cout << "10. Listar Rendimiento\n";
        cout << "11. Registrar Suministro\n";
        cout << "12. Listar Suministros\n";
        cout << "13. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                listarArchivo("empleados.txt");
                break;
            case 3:
                registrarCliente();
                break;
            case 4:
                listarArchivo("clientes.txt");
                break;
            case 5:
                registrarCompra();
                break;
            case 6:
                listarArchivo("compras.txt");
                break;
            case 7:
                registrarRiesgo();
                break;
            case 8:
                listarArchivo("riesgos.txt");
                break;
            case 9:
                registrarRendimiento();
                break;
            case 10:
                listarArchivo("rendimiento.txt");
                break;
            case 11:
                registrarSuministro();
                break;
            case 12:
                listarArchivo("suministros.txt");
                break;
            case 13:
                cout << "Saliendo del ERP. ¡Hasta pronto!" << endl;
                break;
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 13);

    return 0;
}


