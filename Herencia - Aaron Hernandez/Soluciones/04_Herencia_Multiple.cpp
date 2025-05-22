#include <iostream>
using namespace std;


class ReproductorAudio{
    public:
    string formatoAudio;
    ReproductorAudio(const string formatoAudio) : formatoAudio(formatoAudio) {}
    virtual void reproducir(){
        cout << "Reproduciendo audio en formato " << formatoAudio <<  endl;
    }
};

class ReproductorVideo{
    public:
    string formatoVideo;
    ReproductorVideo(const string formatoVideo) : formatoVideo(formatoVideo) {}
    
    virtual void reproducir(){
        cout << "Reproduciendo video en formato " << formatoVideo << endl;
    }
};

class ReproductorMultimedia: public ReproductorAudio, public ReproductorVideo{
    public:
    ReproductorMultimedia(const string formatoVideo, const string formatoAudio) : ReproductorAudio(formatoAudio), ReproductorVideo(formatoVideo) {}
    void reproducir() override{
        cout << "Reproduciendo multimedia en formatos " << formatoVideo << " y " << formatoAudio << endl;
    }
};

int main(){
    ReproductorAudio reproductorAudio("mp3");
    ReproductorVideo reproductorVideo("mp4");
    ReproductorMultimedia reproductor("avi", "wav");

    reproductorAudio.reproducir();
    reproductorVideo.reproducir();
    reproductor.reproducir();

    return 0;
}