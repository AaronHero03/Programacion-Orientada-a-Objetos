#include <iostream>

using namespace std;

class Complejo{
    public:
        double re, im;

        Complejo(double r, double i): re(r), im(i){}
        Complejo operator+(const Complejo& otro){
            return  Complejo(otro.re + re, otro.im + im); 
        }
};

int main() {
    Complejo a(1.0, 2.0);
    Complejo b(3.0, -1.0);
    Complejo res = a + b;
    cout << "(" << res.re << ", " << res.im << ")" << endl;
    return 0;
}