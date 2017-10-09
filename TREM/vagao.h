#ifndef VAGAO_H
#define VAGAO_H
#include <vector>
#include <iostream>
#include <sstream>

#include "passageiro.h"

using namespace std;

class Vagao{
    string id;
    int capacidade;
    vector<Passageiro*> cadeiras;

public:
    Vagao(string _id = "", int _capacidade):
        passageiros(_capacidade, nullptr)
    {
        capacidade = _capacidade;
        id = _id;
    }

    int getLotacao(){
        int cont = 0;
        for(Passageiro pass : cadeiras){
            if(pass){
                cont++;
            }
        }
        return cont;
    }

    int getCapacidade(){
        return capacidade;
    }

    bool embarcar(Passageiro* _passageiro){
        for(Passageiro* &pass : cadeiras){
            if(pass == nullptr){
                pass = passageiro;
                return true;
            }
        }
        return false;
    }
    Passageiro* desembarcar(string _cpf){
        for(int i = 0; i < capacidade; i++){
            if(cadeiras[i].getCPF() == _cpf){
                Passageiro* j = cadeiras[i];
                cadeiras[i] = nullptr;
                return &j;
            }
        }
        return nullptr;
    }

    string toString(){
        stringstream ss;
        ss << "Id: " << id << endl;
        ss << "Capacidade: " << capacidade << endl;
        for(Passageiro pass : cadeiras){
            ss << "  --> CPF: " << pass.getCPF() << endl;
        }
        return ss.str();
    }


};

#endif // VAGAO_H
