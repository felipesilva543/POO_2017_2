#ifndef VAGAO_H
#define VAGAO_H
#include <vector>
#include <iostream>
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





    bool embarcar(Passageiro* _passageiro){
        for(Passageiro* &pass : cadeiras){
            if(pass == nullptr){
                pass = passageiro;
                return true;
            }
        }
        return false;
    }



};

#endif // VAGAO_H
