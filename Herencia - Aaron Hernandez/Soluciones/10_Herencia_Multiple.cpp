#include <iostream>
using namespace std;

class A { 
    public: void imprimir() { 
        cout << "A" << endl; 
    } 
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.C::imprimir(); // Error
    return 0;
}