#include <iostream>
#include <sstream>
#include "poo_aux.h"
#include "poo_repository.h"
#include "poo_controller.h"
#include "Restaurante.h"

using namespace std;
using namespace poo;

string HELP = R"(
        help
        addIngred       _id _valor
        showIngred
        infoIngred
        addProd         _id _ingre ... _ingre _valor
        showProd
        infoProd
        addCliente      _name ... _name
        showClientes
        infoCliente     _name
        addMesa         _id _qtdCad
)";

class Restaurante : public Controller{
    Repository<Ingrediente> r_ingre;
    Repository<Produto> r_produtos;
    Repository<Cliente> r_clientes;
public:
    Restaurante():
        r_ingre("ingredientes"),
        r_produtos("produtos"),
        r_clientes("clientes")
    {}

    string process(string line){
        auto ui = poo::split(line, ' ');
        auto cmd = ui[0];

        if(cmd == "help")
            return HELP;
        else if(cmd == "addIngred"){
            r_ingre.add(ui[1], Ingrediente(ui[1], Float(ui[2])));
        }
        else if(cmd == "showIngred"){
            return "" + r_ingre.keys();
        }
        else if(cmd == "infoIngred"){
            vector<Ingrediente> aux = r_ingre.values();
            stringstream ss;
            ss << "Ingredientes: \n";
            for(auto ele : aux){
                ss << ele.toStringIngr();
            }
            return ss.str();
        }
        else if(cmd == "addProd"){
            int size = ui.size();
            float valor = Float(ui[size - 1]);
            Produto prod = Produto(ui[1], valor);
            for(int i = 2; i < (size - 1); i++){
                prod.setIngredientes(r_ingre.get(ui[i]));
            }
            r_produtos.add(ui[1], prod);
        }
        else if(cmd == "showProd"){
            return "" + r_produtos.keys();
        }
        else if(cmd == "infoProd"){
            vector<Produto> prodAux = r_produtos.values();
            stringstream ss;
            for(auto ele : prodAux){
                ss << ele.toStringProd();
            }
            return ss.str();
        }
        else if(cmd == "addCliente"){
            int size = ui.size();
            for(int i = 1; i < (size); i++){
                r_clientes.add(ui[i], Cliente(ui[i]));
            }
        }
        else if(cmd == "showClientes"){
            return "" + r_clientes.keys();
        }
        else if(cmd == "infoCliente"){
            return r_clientes.get(ui[1])->toStringCli();

            vector<Cliente> prodCli = r_clientes.values();
            stringstream ss;
            for(auto ele : prodCli){
                ss << ele.toStringCli() << endl;
            }
            return ss.str();
        }
        else if(cmd == "addMesa"){

        }

        else if(cmd == "fim")
            return "";
        else
            return string("") + "comando invalido " + "[" + cmd + "]";
        return "done";
    }
};


int main()
{
    Restaurante c;
    c.commandLine();
    return 0;
}
