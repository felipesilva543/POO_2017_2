#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int controle = 0;

struct Operacao{
    string descricao;
    float valor;
    float saldoParcial{0};
    Operacao(string descricao = "", float valor = 0){
        this->descricao = descricao;
        this->valor = valor;
    }
};

class Conta{
private:
    int num;
    float saldo{0};
    bool ativa{true};
    vector<Operacao> extrato;
public:
    Conta(int _num = 0){
        this->num = _num;
    }

    float getSaldo(){
        return this->saldo;
    }

    int getNumero(){
        return this->num;
    }

    void setNumero(int _num){
        this->num = _num;
    }

    bool sacar(float valor){
        if((this->saldo < valor) || (valor < 0)){
            return false;
        }
        this->saldo -= valor;
        this->extrato.push_back(Operacao("Saque: -", valor));

        return true;
    }

    bool depositar(float valor){
        if(valor < 1){
            return false;
        }
        this->saldo += valor;
        this->extrato.push_back(Operacao("Deposito: +", valor));
        return true;
    }

    string getExtrato(){
        stringstream ss;
        for (Operacao vetor : extrato){
            ss << vetor.descricao << " " << vetor.valor << endl;
        }
        return ss.str();
    }

    string getExtratoN(int n){
        stringstream ss;
        int tam = (int)(extrato.size()) - n;
        for(; tam < (int)extrato.size(); tam++){
            ss << extrato[tam].descricao << " " << extrato[tam].valor << endl;
        }
        return ss.str();
    }

    bool getAtiva(){
        return this->ativa;
    }

    void setAtiva(){
        this->ativa = !this->ativa;
    }

//    bool tranferencia(Conta _outra, float _valor){
//        this->saldo -= _valor;
//    }


};

class Cliente{
    string cpf;
    vector<Conta> contas;
  public:
    Cliente(string _cpf = ""){
        this->cpf = _cpf;
    }

    bool addConta(string _numero){

    }

//    int endConta(int _numero){
//        for(Conta elemento : contas){
//            if(elemento.getNumero() == _numero){
//                if(elemento.getSaldo() > 0){
//                    return -2;
//                }
//                elemento.setAtiva();
//                return true;
//            }
//        }
//    }

    string getCpf(){
        return this->cpf;
    }

    vector<Conta> getConta(){
        return this->contas;
    }

    void setConta(int _num){
        contas.push_back(Conta(_num));
    }
};

class Agencia{
    vector<Cliente> clientes;
  public:
    Agencia(){}

    bool addCliente(string _cpf){
        for(Cliente elemento : clientes){
            if(elemento.getCpf() == _cpf){
                return false;
            }
        }
        clientes.push_back(Cliente(_cpf));
        return true;
    }

    int abrirConta(string _cpf){
        for(Cliente elemento : clientes){
            if(elemento.getCpf() != _cpf){
                return -1;
            }
        }
        for(Cliente elemento : clientes){
           // int cont;
            if(elemento.getConta().size() > 2){
                return -2;
            }
        }
        for(Cliente& elemento : clientes){
            if(elemento.getCpf() == _cpf){
                elemento.setConta(controle);
                controle += 1;
                return 1;
            }
        }
    }

    void showCliente(){
        for(Cliente elemento : clientes){
            cout << elemento.getCpf() << endl;

        }
    }
};

int main()
{
}
