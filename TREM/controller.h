#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <iostream>
#include <sstream>
#include "trem.h"
#include "split.h"
#include "vagao.h"
#include "passageiro.h"
#include "registropassageiros.h"

using namespace std;

class Controller{
    Trem trem;
    RegistroPassageiros registro;
    int id{0};
public:
    Controller(){}

    string process(string line){
        auto ui = split(line);
        auto cmd = ui[0];

        if(cmd == "help"){
            return  "  # comandos                                 \n"
                    "  iniciarTrem _qtdVagoes                     \n"
                    "  addVagao _capacidade                       \n"
                    "  embarcar _passCpf                          \n"
                    "  desembarque _passCpf                       \n"
                    "  show                                       \n"
                    "  registro                                   \n"

                    "  # default                                  \n"
                    "  fim                                        \n"
                    "  help                                       \n";
        }
        if(cmd == "iniciarTrem"){
            int numVag = Int(ui[1]);
            trem = Trem(numVag);
            string resp = "Trem iniciado com " + ui[1] + " vagões.\n";
            return resp;
        }
        if("addVagao" == cmd){
            int capac = Int(ui[1]);
            Vagao vag = Vagao(id, capac);
            trem.addVagao(vag);
            id++;
            return "Vagao adicionado.\n";
        }
        if(cmd == "embarcar"){
            Passageiro aux = Passageiro(ui[1]);
            vector<Passageiro> passageiro = registro.getAllPass();
                for(auto pass : passageiro)
                    if(pass.getCPF() == aux.getCPF())
                        throw string("CPF já embarcado.");
            trem.embarcarTrem(aux);
            registro.addPass(aux);
            return "Passageiro embarcado com sucesso.";
        }
        if(cmd == "desembarque"){
            Passageiro * pass = trem.desembarcarTrem(ui[1]);
            if(pass == nullptr){
                return "O passageiro não esta no trem. \n";
            }
            return "Passageiro desembarcado";
        }
        if(cmd == "show"){
            return trem.toString();
        }
        if(cmd == "registro"){
            return registro.toString();
        }
        return "";
    }


    void commandLine() {
        string line = "";
        while(line != "fim"){
            cout << "(help): ";
            getline(cin, line);
            if(line == "")
                continue;
            cout << ">> " << line << endl;
            try {
                cout << process(line) << endl;
            } catch(const string& erro) {
                cout << erro << endl;
            }
        }
    }
};

#endif // CONTROLLER_H
