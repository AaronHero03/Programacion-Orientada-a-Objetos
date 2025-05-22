#include <iostream>
#include <string>

using namespace std;

class Usuario{
    public:
    string nombre;
    Usuario(const string nombre) : nombre(nombre) {}
    
    virtual void login(){
        cout << "Usuario " << nombre << " ha iniciado sesión." << endl;
    }
};

class Moderador: public Usuario{
    public:
    Moderador(const string nombre): Usuario(nombre) {}
    
    void login() override{
        cout << "Moderador " << nombre << " ha iniciado sesión." << endl;
    }

    void moderar(){
        cout << nombre << " esta moderando " << nombre  << endl;
    }
};

class Admin: public Moderador{
    public:
    Admin(const string nombre): Moderador(nombre) {}
    
    void banear(){
        cout << nombre << " te ha baneado"<< endl;
    }

    void login() override{
        cout << "Admin " << nombre << " ha iniciado sesión." << endl;
    }
};

int main(){

    Usuario usuario("Juan");
    Moderador moderador("Pedro");
    Admin admin("Maria");

    usuario.login();
    moderador.login();
    moderador.moderar();

    admin.login();
    admin.moderar();
    admin.banear();
    
    return 0;
}