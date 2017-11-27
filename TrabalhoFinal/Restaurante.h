#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Ingrediente{
    string idIngr;
    float valor{0};
    Ingrediente(string id = "", float _valor = 0.0){
        idIngr = id;
        valor = _valor;
    }
    string getIdIngr(){
        return idIngr;
    }
    float getValor(){
        return valor;
    }
    void setValor(float newValor){
        valor = newValor;
    }

    string toStringIngr(){
        stringstream ss;

        ss << "Ingrediente: " << idIngr << " Valor: " << valor << endl;

        return ss.str();
    }

};

class Produto{
protected:
    string idProd;
    vector<Ingrediente*> ingredientes;
    float valor{0};

    /*
     * Add custo de produção
     * E valor final fica sendo o custo de produção mais o valor de cada ingrediente
     */

public:
    Produto(string id = "", float _valor = 0.0){
        idProd = id;
        valor = _valor;
    }

    void setIngredientes(Ingrediente *ingre){
        ingredientes.push_back(ingre);
    }

    float getValor(){
        return valor;
    }
    void setValor(float newValor){
        valor = newValor;
    }

    string getIdProd(){
        return idProd;
    }

    string toString(){
        stringstream ss;
         ss << "Produto: " << idProd << " Valor: " << valor << endl;
         ss << "Ingredientes: " << endl;
         for(auto elemento : ingredientes){
             ss << elemento->toStringIngr();
         }
         return ss.str();
    }
};

#endif // RESTAURANTE_H


