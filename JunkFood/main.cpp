#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class T>
T read(){
    T t;
    cin >> t;
    return t;
}

class Espiral{
  public:
    string nome;
    int qtd;
    float valor;

    Espiral(string _nome = "", int _qtd = 0, float _valor = 0.0){
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

    string getNome(){
        return this->nome;
    }
    int getQtd(){
        return this->qtd;
    }
    float getValor(){
        return this->valor;
    }


};

class JunkFood{
  public:
    vector<Espiral> espirais;
    float saldo{0.0};
    float lucro{0.0};

    JunkFood(int _qtd = 0):
        espirais(_qtd)
    {}

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
    bool alterarProd(int _id, string _nome, int _qtd, float _valor){
        if((_id < (int) espirais.size()) && (_nome != "") && (_qtd > 0) && (_valor > 0.0)){
            espirais[_id].setNome(_nome);
            espirais[_id].setQtd(_qtd);
            espirais[_id].setValor(_valor);
            return true;
        }
        return false;

    }
    /*///////////////////////////////////*/
    int comprar(int _id){
        if((_id > (int) espirais.size()) || (espirais[_id].getQtd() <= 0)){
            return -1;
        }
        if((this->saldo) < (espirais[_id].getValor())){
            return -2;
        }
        this->saldo -= espirais[_id].getValor();
        this->lucro += espirais[_id].getValor();
        espirais[_id].setQtd((espirais[_id].getQtd() - 1));

        return 1;

    }
    /*//////////////////////////////////*/
    string statusMaq(){

        stringstream ss;
        ss << "Saldo: " << this->saldo << endl
           << "Lucro: " << this->lucro << endl;
        int aux = 0;
        for(auto sel : espirais){
            ss << "ind: " << aux << " "
               << "nome: " << sel.nome << " "
               << "qtd: " << sel.qtd << " "
               << "valor: " << sel.valor << endl;
            aux += 1;
        }
        return ss.str();
    }


};

void inicializar(JunkFood& maquina){
    maquina.inserirDin(10);
    maquina.alterarProd(0, "Toddy", 2, 2.5);
    maquina.alterarProd(1, "Pastel", 2, 3);
}


int main()
{
    JunkFood maquina;
    string op;

    while (op != "fim") {

        cout << "Digite o Comando ou help: ";
        cin >> op;

        if(op == "help"){
            cout << "\nComandos:" << endl
                 << "iniciar $qtd" << endl
                 << "inserirDin $valor" << endl
                 << "saldo" << endl
                 << "troco" << endl
                 << "comprar $id" << endl
                 << "alterarProd $id $nome $qtd $valor" << endl
                 << "statusMaq" << endl
                 << "fim" << endl;
        }

        if(op == "iniciar"){
            maquina = JunkFood(read<int>());
            inicializar(maquina);
            cout << "Maquina criada!" << endl;
        }

        if(op == "inserirDin"){
            float x;
            cin >> x;
            if(maquina.inserirDin(x)){
                cout << "Suceso!"<< endl;
            }else{
                cout << "Erro!" << endl;
            }
        }

        if(op == "saldo"){
           cout << maquina.getSaldo() << " Reais." << endl;
        }

        if(op == "troco"){
            cout << "Você retirou " << maquina.getTroco() << " Reais." << endl;
        }

        if(op == "comprar"){
            int x = read<int>();
            if((maquina.comprar(x)) == 1){
                cout << "Comprado!" << endl;
            }else if((maquina.comprar(x)) == -1){
                cout << "ERRO: Produto não existe!" << endl;
            }else if((maquina.comprar(x)) == -2){
                cout << "ERRO: Saldo Insuficiente!" << endl;
            }
        }

        if(op == "alterarProd"){
            int id = read<int>();
            string nome = read<string>();
            int qtd = read<int>();
            float valor = read<float>();

            cout << (maquina.alterarProd(id, nome, qtd, valor)? "Produto Alterado!\n" : "Erro ao alterar produto!\n");
        }

        if(op == "statusMaq"){
            cout << "Status:\n" << maquina.statusMaq();
        }

    }


    return 0;
}
