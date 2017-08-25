//Criação da class que verifica a quantidade de alegria da plateia e o quanto determinado Circence agradou

#include <iostream>
#include <vector>

using namespace std;

class Circense{
public:
    string nome;
    string especialidade;
    int gosto;
    Circense(string nome = "Tanguinha", string especialidade = "palhaco"){
        this->nome = nome;
        this->especialidade = especialidade;
        this->gosto = 0;
    }

};

class Pessoa{
public:
    string nome;
    vector<string> preferencias;
    int idade;
    int alegria;

    Pessoa(string nome = "", int idade = 18, vector<string> preferencias = vector<string>()){
        this->nome = nome;
        this->idade = idade;
        this->alegria = 0;
        this->preferencias = preferencias;
    }

//    void verEspetaculo(vector<Circense> vetor){
//        for (Circense& circense : vetor)
//            for(string pref : preferencias)
//                if(circense.especialidade == pref ){
//                    this->alegria += 1;
//                }

        // MODO INDEXADO
//        for (int i = 0; i < vetor.size(); i++){
//            for(int j = 0; j < preferencias.size(); j++){
//                if(vetor[i].especialidade == preferencias[j]){
//                    this->alegria += 1;
//                    vetor[j].gosto +=1;
//                }
//            }
//        }
//    }

    void addPreferencias(string pref){
        preferencias.push_back(pref);
    }
};

class Circo{
    public:
    vector<Circense> cir;
    vector<Pessoa> pes;

    Circo(vector<Circense> cir, vector<Pessoa> pes){
        this->cir = cir;
        this->pes = pes;
    }

    void espetaculo(){

        for (Circense& circense : this->cir)
            for(Pessoa& pessoa : this->pes)
                for(string pref : pessoa.preferencias)
                    if(circense.especialidade == pref ){
                        pessoa.alegria+=1;
                        circense.gosto+=1;
                }

    }

};

#include <sstream>
int main(){

    vector<Pessoa> plateia = {Pessoa("Bia", 5, {"palhaco", "domador", "magico"}),
                              Pessoa("Ruy", 50, {"contorcionista"}),
                              Pessoa("Ana", 8, vector<string>(10, "palhaco"))};
    vector<Circense> atracoes = {Circense("Tanguinha", "palhaco"),
                                 Circense("Shazam", "magico"),
                                 Circense("Juvenal", "domador"),
                                 Circense("Valentina", "contorcionista")};

//        for(Pessoa &pessoa : plateia)
//            pessoa.verEspetaculo(atracoes);

//        for(Pessoa &pessoa : plateia)
//            cout << pessoa.nome << " " << pessoa.alegria << "\n";

//        cout << endl;

//        for(Circense &cir : atracoes)
//            cout << cir.nome << endl
//                 << cir.especialidade << endl
//                 << cir.gosto << endl;

           Circo *circo = new Circo(atracoes, plateia);

           circo->espetaculo();

           for(int i=0; i<circo->pes.size(); i++){
              cout<< circo->pes[i].nome << " " << circo->pes[i].alegria <<endl;
           }

           cout << endl;

           for(int i = 0; i<circo->cir.size(); i++){
              cout<< circo->cir[i].nome << endl;
              cout<< circo->cir[i].especialidade << endl;
              cout<< circo->cir[i].gosto << endl;
              cout<<endl;
           }

           return 0;
}
