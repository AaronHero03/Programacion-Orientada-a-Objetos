#include <iostream>
#include <cstring>
using namespace std;

class Buffer {
    char* datos;
    size_t n;
public:
    Buffer(const char* s) {
        n = strlen(s);
        datos = new char[n+1];
        strcpy(datos, s);
    }
    ~Buffer() { delete[] datos; }
    Buffer& operator=(const Buffer& otro) {
        if(this != &otro){
            delete[] datos;
            datos = new char(strlen(otro.datos + 1));
            strcpy(datos, otro.datos);
        }
        return *this;
    }
    void print() const { cout << datos << endl; }
};

int main() {
    Buffer b1("Hola"), b2("Mundo");
    b1 = b2;
    b1.print();  // Mundo

    return 0;
}