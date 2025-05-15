/*
// buffer_asign_bug.cpp
#include <iostream>
#include <cstring>
using namespace std;

class Buffer {
    char* datos;
public:
    Buffer(const char* s) {
        datos = new char[strlen(s)+1];
        strcpy(datos, s);
    }
    ~Buffer() { delete[] datos; }
    Buffer& operator=(const Buffer& otro) {
        delete[] datos;
        datos = otro.datos;   // BUG: ¿qué problema surge aquí?
        return *this;
    }
};
*/