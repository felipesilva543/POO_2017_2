#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <iostream>
#include <sstream>
using namespace std;

class Passageiro{
    string cpf;
public:
    Passageiro(string _cpf){
        cpf = _cpf;
    }
    string getCPF(){
        return cpf;
    }

    string toString(){
        stringstream ss;
        ss << "CPF: " << cpf << endl;
        return ss.str();
    }
};

#endif // PASSAGEIRO_H
