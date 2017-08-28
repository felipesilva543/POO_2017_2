#include <iostream>
#include <vector>
using namespace std;

class Cliente{
  private:
    float saldo;
  public:
    Cliente(float _saldo = 0){
        saldo = _saldo;
    }

    bool inserirDin(float _valor){
        if (_valor > 0){
            this->saldo += _valor;
            return true;
        }
        return false;
    }

    float getSaldo(){
        return this->saldo;
    }

    float getTroco(){
        float x = this->saldo;
        this->saldo = 0;
        return x;
    }
};

class Produto{
  private:
   // int id;
    string nome;
    int qnt;
    float valor;
  public:
    Produto(string _nome = "", int _qtd = 0, float _valor = 0){
        this->id = _id;
        this->nome = _nome;
        this->qnt = _qtd;
        this->valor = _valor;
    }

};

class JunkFood{
  private:
    int espirais;
    vector<Produto> produtos;
  public:
    JunkFood(int _espirais = 0){
        this->espirais = _espirais;
        produtos.resize(espirais);
    }

    void alterarProd(){

    }

};



int main()
{
    Cliente cliente;

    cout << "Ola Cliente!" << endl
         << "Comandos:" << endl
         << "inserirDin _valor" << endl
         << "saldo" << endl
         << "troco" << endl
         << "fim" << endl << endl

         << "Ola Admin!" << endl
         << "Comandos:" << endl
         << "iniciar _qtd" << endl

         << "fim" << endl;

    string op;
    cout << endl;

    while (op != "fim") {
        cin >> op;
        if(op == "inserirDin"){
            float x;
            cin >> x;
            if(cliente.inserirDin(x)){
                cout << "Suceso!"<< endl;
            }else{
                cout << "Erro!" << endl;
            }
        }
        if (op == "saldo"){
           cout << cliente.getSaldo() << " Reais." << endl;
        }
        if (op == "troco"){
            cout << "Você retirou " << cliente.getTroco() << " Reais." << endl;
        }
    }


    return 0;
}
