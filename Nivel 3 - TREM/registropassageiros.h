#ifndef REGISTROPASSAGEIROS_H
#define REGISTROPASSAGEIROS_H
#include <vector>
#include <iostream>
#include <sstream>
#include "passageiro.h"

using namespace std;

class RegistroPassageiros{
    vector<Passageiro> passageiros;

public:
    RegistroPassageiros(){}

    void addPass(Passageiro pass){
        for(auto pessoa : passageiros)
            if(pessoa.getCPF() == pass.getCPF())
                throw string("Passageiro" + pass.getCPF() + " ja está embarcado.");
        passageiros.push_back(pass);
    }

    vector<Passageiro> getAllPass(){
        return passageiros;
    }

    string toString(){
        stringstream ss;
        ss << "Passageiros:" << endl;
        for(Passageiro pass : passageiros){
            ss << pass.toString() << endl;
        }
        return ss.str();
    }
};

#endif // REGISTROPASSAGEIROS_H
