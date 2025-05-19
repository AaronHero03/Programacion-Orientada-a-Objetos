#include <iostream>
using namespace std;


class ReproductorAudio{
    public:
    virtual void reproducir(){
        cout << "Reproduciendo audio" << endl;
    }
};

class ReproductorVideo{
    public:
    virtual void reproducir(){
        cout << "Reproduciendo video" << endl;
    }
};

class ReproductorMultimedia: public ReproductorAudio, public ReproductorVideo{
    public:
    void reproducir() override{
        cout << "Reproduciendo multimedia" << endl;
    }
};

int main(){
    ReproductorAudio reproductorAudio;
    ReproductorVideo reproductorVideo;
    ReproductorMultimedia reproductor;

    reproductorAudio.reproducir();
    reproductorVideo.reproducir();
    reproductor.reproducir();

    return 0;
}