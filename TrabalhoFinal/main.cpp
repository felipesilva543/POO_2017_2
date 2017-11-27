#include <iostream>
#include "poo_aux.h"
#include "poo_repository.h"
#include "poo_controller.h"
#include "Restaurante.h"

using namespace std;
using namespace poo;

string HELP = R"(help
        addIngred    _id _valor
        showIngred
        addProd      _id _ingre ... _ingre _valor
        showProd

)";

class Restaurante : public Controller{
    Repository<Produto> r_produtos;
    Repository<Ingrediente> r_ingre;
public:
    Restaurante():
        r_produtos("produtos"),
        r_ingre("ingredientes")
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
