// Transferencias
//Completar codigo de inicialização
// Ajeitar as Operações

// Ordenar vetor de clientes por ordem
// Mudar Status das contas quando encerrar (lembrar que se n fizer, nao colocar o status no "show")




#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int controle = 0;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

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

    void setAtiva(){
        this->ativa = !this->ativa;
    }

    bool getAtiva(){
        return this->ativa;
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

    string getCpf(){
        return this->cpf;
    }

    vector<Conta> getConta(){
        return this->contas;
    }

    void setConta(int _num){
        contas.push_back(Conta(_num));
    }

    int endConta(int _numero){
        for(Conta elemento : contas){
            if(elemento.getNumero() == _numero){
                cout << "Ai" << endl;
                if(elemento.getSaldo() > 0){
                    return -3; // Só pode encerrar com saldo zerado
                }
                if((elemento.getAtiva()) == (false)){
                    return -2;
                }
                elemento.setAtiva();
                return _numero;
            }
        }
        return -1;
    }
};

class Agencia{
    vector<Cliente> clientes;
  public:
    Agencia(){}

    int abrirConta(string _cpf){

        //Pra saber se tem duas contas ativas
        for(Cliente elemento : clientes){
            if(elemento.getConta().size() >= 2){
                int x = 0;
                vector<Conta> contas = elemento.getConta();
                for(Conta elemento2 : contas){
                    if(elemento2.getAtiva() == true){
                        x += 1;
                        if(x == 2){
                            return -2;
                        }
                    }
                }
            }
        }
        for(Cliente& elemento : clientes){
            if(elemento.getCpf() == _cpf){
                elemento.setConta(controle);
                int numeroConta = controle;
                controle += 1;
                return numeroConta;
            }
        }
        return -1;
    }


    bool addCliente(string _cpf){
        for(Cliente elemento : clientes){
            if(elemento.getCpf() == _cpf){
                return false;
            }
        }
        clientes.push_back(Cliente(_cpf));
        abrirConta(_cpf);
        return true;
    }

    string showAllCliente(){
        stringstream ss;
        int x = 1;
        vector<Conta> contas;
        for(Cliente elemento : clientes){
            contas = elemento.getConta();
            vector<int> contasAti;
            for(Conta elemento2 : contas){
                if(elemento2.getAtiva()){
                    contasAti.push_back(elemento2.getNumero());
                }
            }
            ss << x << " - " << elemento.getCpf() << " [ ";
            for(int i = 0; i < (int)contasAti.size(); i++){
                ss << contasAti[i] << " ";
            }
            ss << "]" << endl;
            x += 1;
        }
        return ss.str();
    }

    Cliente * Login(string _cpf){
        for(Cliente& elemento : clientes){
            if(elemento.getCpf() == _cpf){
                return &elemento;
            }
        }
        return nullptr;
    }


    string show(string _cpf){
        stringstream ss;
        float saldoT = 0;
        ss << "Cliente: " << _cpf << endl;
        vector<Conta> contas;
        for(Cliente elemento : clientes){
            if(elemento.getCpf() == _cpf){
                contas = elemento.getConta();
                for(Conta elemento2 : contas){
                    saldoT += elemento2.getSaldo();
                    ss << "Conta: " << elemento2.getNumero() << ", "
                       << "Saldo: " << elemento2.getSaldo() << ", "
                       << "Status: " << elemento2.getAtiva() << endl;
                }
                ss << "Saldo Total: " << saldoT << endl;
                return ss.str();
                }

            }
        return "Error!";
        }
};

void inicializar(Agencia& agencia){
    agencia.addCliente("123");
    agencia.addCliente("321");
    agencia.addCliente("456");
    agencia.abrirConta("123");
}


int main(){

    Agencia agen;
    Cliente * cliente = nullptr;
    string op = "";
    inicializar(agen);
    while(op != "fim"){
        cout << "Digite o comando ou help: ";
        cin >> op;
        if(op == "help"){
            cout << "Comandos:" << endl
                 << "login $cpf" << endl
                 << "logout" << endl
                 << "showAll" << endl
                 << "addCli $cpf" << endl
                 << "abrirConta $cpf" << endl
                 << "endConta $conta" << endl
                 << "show" << endl


                 << "fim" << endl <<endl;
                 ;
        }

        if(op == "login"){
            string _cpf;
            cin >> _cpf;
            cliente = agen.Login(_cpf);
            if(cliente == nullptr)
                cout << "Erro de login" << endl;
            else
                cout << "Sucesso" << endl;
        }
        if(op == "logout"){
            if(cliente != nullptr){
                cliente = nullptr;
                cout << "Logout efetuado" << endl;
            }else{
                cout << "Ninguem logado" << endl;
            }
        }

        if(op == "showAll"){
            cout << agen.showAllCliente() << endl;
        }
        if(op == "addCli"){
            if(agen.addCliente(read<string>())){
                cout << "Cliente Add!" << endl;
            }else
                cout << "Error ao adicionar cliente, CPF duplicado!" << endl;
        }
        if(op == "abrirConta"){
            int x;
            x = agen.abrirConta(read<string>());
            if(x >= 0){
                cout << "Conta " << x << " aberta." << endl;
            }else if(x == -1){
                cout << "CPF não existe!" << endl;
            }else if(x == -2){
                cout << "Limite de contas atingido!" << endl;
            }
        }

        if(op == "endConta"){
            if(cliente == nullptr){
                cout << "Ninguem logado!" << endl;
            }else {
                int x = cliente->endConta(read<int>());
                if(x >= 0){
                    cout << "Conta " << x << " encerrada!" << endl;
                }else if(x == -1){
                    cout << "Conta invalida." << endl;
                }else if(x == -2){
                    cout << "Conta ja esta incerrada." << endl;
                }else if(x == -3){
                    cout << "Saldo positivo." << endl;
                }
            }
        }
        if(op == "show"){
            if(cliente == nullptr){
                cout << "Ninguem logado!" << endl;
            }else {
                cout << agen.show(cliente->getCpf()) << endl;
            }
        }




    }

}
