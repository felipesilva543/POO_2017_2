#ifndef TREM_H
#define TREM_H
#include "vagao.h"
#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

class Trem{
    int maxVagoes{0};
    int contarVagoes{0};
    vector<Vagao> vagoes;
public:
    Trem(int _maxVagoes){
        maxVagoes = _maxVagoes;
    }

    bool addVagao(Vagao _vagao){
        if(contarVagoes > maxVagoes){
            return false;
        }
        vagoes.push_back(_vagao);
        contarVagoes++;
        return true;
    }

    bool embarcar(){

    }

    Passageiro desembarcar(){

    }

    //Search

    int getLotacao(){
        int i = 0;
        for(Vagao vag : vagoes){
            i += vag.getLotacao();
        }
        return i;
    }

    int getCapacidade(){
        int i = 0;
        for(Vagao vag : vagoes){
            i += vag.getCapacidade();
        }
        return i;
    }

    string toString(){
        stringstream ss;
        ss << "Max. de vagões: " << maxVagoes << endl;
        for(Vagao vag : vagoes){
            ss << vag.toString() << endl;
        }
        return ss.str();
    }

};

#endif // TREM_H
