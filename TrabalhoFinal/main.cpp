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
        infoIngred      _id
        addProd         _id _ingre ... _ingre _custoProd
        showProd
        infoProd        _id
        addCliente      _name ... _name
        showClientes
        infoCliente     _name
        addMesa         _id _qtdCad
        showMesas
        infoMesa        _id
        sentar          _cli _mesa
        comprar         _mesa _produto
        pagar           _cliente
)";

class Restaurante : public Controller{
    Repository<Ingrediente> r_ingre;
    Repository<Produto> r_produtos;
    Repository<Cliente> r_clientes;
    Repository<Mesa> r_mesas;
public:
    Restaurante():
        r_ingre("ingredientes"),
        r_produtos("produtos"),
        r_clientes("clientes"),
        r_mesas("mesas")
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
            return r_ingre.get(ui[1])->toStringIngr();
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
            return r_produtos.get(ui[1])->toStringProd();
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
        }
        else if(cmd == "addMesa"){
            r_mesas.add(ui[1],Mesa(ui[1], Int(ui[2])));
        }
        else if(cmd == "showMesas"){
            return "" + r_mesas.keys();
        }
        else if(cmd == "infoMesa"){
            return r_mesas.get(ui[1])->toStringMesa();
        }
        else if(cmd == "sentar"){
            r_clientes.get(ui[1])->sentar(r_mesas.get(ui[2]));
        }
        else if(cmd == "comprar"){
           r_mesas.get(ui[1])->comprar(r_produtos.get(ui[2]));
        }
        else if(cmd == "pagar"){
            r_clientes.get(ui[1])->pagarESair();
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
