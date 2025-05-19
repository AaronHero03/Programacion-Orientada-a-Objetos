#include <iostream>

using namespace std;

class Persona{
    protected:
    string nombre;
    int edad;
    
    Persona(const string& nom, int ed) : nombre(nom), edad(ed) { }
};

class Empleado:protected Persona{
    public:

    Empleado(const string& nom, int ed) : Persona(nom, ed) { }

    void mostrarDatos(){
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main(){
    Empleado empleado("Aaron", 20);
    empleado.mostrarDatos();
    return 0;
}
