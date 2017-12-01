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

class Produto{
protected:
    string idProd;
    vector<Ingrediente*> ingredientes;
    float valor{0};

public:
    Produto(string id = "", float _valor = 0.0){
        idProd = id;
        valor = _valor;
    }

    void setIngredientes(Ingrediente *ingre){
        ingredientes.push_back(ingre);
        valor += ingre->getValor();
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

class Cliente;
class Mesa{
    string idMesa;
    int clientesNaMesa{0};
    int qtdCad{0};
    float valorAPagar{0};
    vector<Cliente*> cli_mesa;
public:
    Mesa(string id = "", int _qtdCad = 0){
        idMesa = id;
        qtdCad = _qtdCad;
    }

    int getClieNaMesa(){
        return clientesNaMesa;
    }

    string getIdMesa(){
        return idMesa;
    }

    void comprar(Produto * produto);

    bool addCli(Cliente * cli){
        if(((int)cli_mesa.size()) == qtdCad)
            return false;
        cli_mesa.push_back(cli);
        clientesNaMesa++;
        return true;

    }

    void setValorAPagar(float valor){
        valorAPagar -= valor;
        clientesNaMesa -= 1;
    }

    string toStringMesa();

    friend class Cliente;
};



class Cliente{
    string idCliente;
    Mesa * mesa{nullptr};
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

    void sentar(Mesa * _mesa){
        if(_mesa->addCli(this)){
            mesa = _mesa;
        }else{
            throw string("\nVagas indisponíveis para essa mesa!\n");
        }
    }

    void pagarESair(){
        for(int i = 0; i < (int) mesa->cli_mesa.size(); i++){
            if(mesa->cli_mesa[i]->getIdCliente() == this->getIdCliente()){
                mesa->setValorAPagar(saldoDev);
                saldoDev = 0;
                mesa->cli_mesa.erase(mesa->cli_mesa.begin() + i);
                mesa = nullptr;
                return;
            }
        }
    }

    string getMesaCli(){
        return mesa->getIdMesa();
    }

    string toStringCli(){
        stringstream ss;
        ss << "Cliente: " << idCliente << " Dev: R$ " << saldoDev;
        ss << "\nMesa: ";
        if(mesa != nullptr)
            ss << mesa->getIdMesa();
        return ss.str();

    }
    friend class Mesa;
};

void Mesa::comprar(Produto *produto){
    valorAPagar += produto->getValor();
    for(Cliente * ele : cli_mesa){
        ele->saldoDev += (produto->getValor() / clientesNaMesa);
    }
}

string Mesa::toStringMesa(){
    stringstream ss;
    ss << "Mesa:" << idMesa << " QtdCade: " << qtdCad;
    ss << "\nClientes na Mesa: " << endl;

    ss << "[ ";
    for(Cliente* elemento : cli_mesa){
        ss << elemento->getIdCliente() << " ";
    }
    ss << "]";
    ss << "\nValor total: R$ " << valorAPagar;
    return ss.str();
}



#endif // RESTAURANTE_H





