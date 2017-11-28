#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Ingrediente{
    //int qtd
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

        ss << idIngr << ", Valor: " << valor << endl;

        return ss.str();
    }

};

class Mesa{
    string idMesa;
    int qtdCad;
public:
    Mesa(string id = "", int qtd){
        idMesa = id;
        qtdCad = qtd;
    }

    int getQtdCad(){
        return qtdCad;
    }
    string getIdMesa(){
        return idMesa;
    }
    string toStringMesa(){
        stringstream ss;
        ss << "Mesa:" << idMesa << " QtdCade: " << qtdCad;
        ss.str();
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

    string toStringProd(){
        stringstream ss;
         ss << "Produto: " << idProd << " R$: " << valor << endl;
         ss << "Ingredientes: " << endl;
         for(auto elemento : ingredientes){
             ss << elemento->getIdIngr() << endl;
         }
         return ss.str();
    }
};

class Cliente{
    string idCliente;
    float saldoDev{0};
public:
    Cliente(string id = ""){
        idCliente = id;
    }

    string getIdCliente(){
        return idCliente;
    }
    float getSaldoDev(){
        return saldoDev;
    }
    void comprar(float valor){
        saldoDev -= valor;
    }
    string toStringCli(){
        stringstream ss;
        ss << idCliente << " Dev: " << saldoDev;
        return ss.str();

    }
};

#endif // RESTAURANTE_H




