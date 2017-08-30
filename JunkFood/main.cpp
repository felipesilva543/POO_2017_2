#include <iostream>
#include <vector>
using namespace std;


class Espiral{
  private:
    string nome;
    int qtd;
    float valor;
  public:
    Espiral(string _nome = "", int _qtd = 0, float _valor = 0){
        this->nome = _nome;
        this->qtd = _qtd;
        this->valor = _valor;
    }

    void setNome(string _nome){
        this->nome = _nome;
    }
    void setQtd(int _qtd){
        this->qtd = _qtd;
    }
    void setValor(float _valor){
        this->valor = _valor;
    }


};

class JunkFood{
  private:
    vector<Espiral> espirais;
    float saldo{0};
    float lucro{0};
    int qtdEs{0};
  public:
    JunkFood(int _qtd){
        espirais(_qtd);
        this->qtdEs = _qtd;
    }
    /*///////////////////////////////////*/
    bool inserirDin(float _valor){
        if (_valor > 0){
            this->saldo += _valor;
            return true;
        }
        return false;
    }
    /*///////////////////////////////////*/
    float getSaldo(){
        return this->saldo;
    }
    /*///////////////////////////////////*/
    float getTroco(){
        float x = this->saldo;
        this->saldo = 0;
        return x;
    }
    /*///////////////////////////////////*/
    bool alterarProd(int _id, string _nome, int _atd, float _valor){
        espirais.at(_id)

    }
    /*////////////////////////////////////
    void comprar(int _id){

    }
    ////////////////////////////////////
    void statusMaq(){

    }

    */

};

int main()
{
    JunkFood maquina;

    cout << "Comandos:" << endl
         << "inserirDin _valor" << endl
         << "saldo" << endl
         << "troco" << endl


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
            if(maquina.inserirDin(x)){
                cout << "Suceso!"<< endl;
            }else{
                cout << "Erro!" << endl;
            }
        }
        if (op == "saldo"){
           cout << maquina.getSaldo() << " Reais." << endl;
        }
        if (op == "troco"){
            cout << "Você retirou " << maquina.getTroco() << " Reais." << endl;
        }
    }


    return 0;
}
