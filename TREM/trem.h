#ifndef TREM_H
#define TREM_H
#include "registropassageiros.h"
#include "vagao.h"
#include <vector>
#include <iostream>
#include <sstream>


using namespace std;

class Trem{
    int maxVagoes;
    int contarVagoes{0};
    vector<Vagao> vagoes;
public:
    Trem(int _maxVagoes = 0){
        maxVagoes = _maxVagoes;
    }

    void addVagao(Vagao _vagao){
        if(contarVagoes > maxVagoes){
            throw string("Numero máximo de vagões atingido.");
        }
        vagoes.push_back(_vagao);
        contarVagoes++;
    }

    void embarcarTrem(Passageiro pass){
        for(Vagao& vagao : vagoes){
            if(vagao.getLotacao() < vagao.getCapacidade()){
                if(vagao.embarcarVagao(&pass))
                    return;
            }
        }
        throw string("Poltronas indisponiveis.");
    }

    Passageiro * desembarcarTrem(string cpf){
        for(Vagao vagao : vagoes){
            Passageiro * ps = vagao.desembarcarVagao(cpf);
            if(ps){
                return ps;
            }
        }
        return nullptr;
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
