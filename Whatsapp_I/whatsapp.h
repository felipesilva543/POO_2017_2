#ifndef WHATSAPP
#define WHATSAPP

#include <sstream>
#include <iostream>
#include "whatsapp.h"
#include "poo_aux.h"

using namespace std;
using namespace poo;

class Zap{
    string userId;
    string msg;
public:
    Zap(string _userId = "", string _msg = ""){
        userId = _userId;
        msg = _msg;
    }
    string getUserId(){
        return userId;
    }

    string toStringZap(){
        stringstream ss;
        ss << "[ Zap: " << userId;
        ss << ": " << msg << " ]" << endl;

        return ss.str();
    }
};

class Chat; //declaração que existe
class Registro;

class User{
    map<string, Chat*> lista_chat;
    string userId;
public:
    User(string _userId){
        userId = _userId;
    }

    vector<string> getChats(){
        return poo::map_keys(lista_chat);
    }

    string getOverview(){
        stringstream ss;
        for(auto par : lista_chat){
            ss << "Chat: " << par.first << endl;
            ss << "Qtd. msg não lidas: " << par.second->getUnreadCount(userId) << endl;
        }
        return ss.str();
    }

    void assertChat(string _chatId){
        if(lista_chat.count(_chatId) == 0)
            throw _chatId + " não existe!";
    }

    void invite(string _chatId, User * _user){
        assertChat(_chatId);
        Chat aux = *lista_chat[_chatId];

        //se o usuario ja esta no chat, retorne

        //Abra um registro para esse usuario no chat
        aux.lista_reg[_user->userId] = Registro(_user);
        //Adicione esse chat na lista dos usuarios
        _user->lista_chat[_chatId] = &aux;
//            # se as mensagens de InOut estiverem habilitadas
//                # envie uma mensagem avisando que o novo usuario chegou



    }
    void leave(string _chatId){
        //Teste se voce tem esse chat - OK
        assertChat(_chatId);
        Chat aux = *lista_chat[_chatId];
        //Se retire da lista do chat
        aux.lista_reg.erase(this->userId);
        //Retire o chat da sua lista
        lista_chat.erase(aux.chatId);


        //Se habilitado, mande mensagem avisando que voce saiu
    }


    void sendZap(string _msg, string _chatId){
        //Teste se voce tem esse chat
        assertChat(_chatId);
        //Obtenha o objeto chat
        Chat aux = *lista_chat[_chatId];
        //Delegue para o chat entregar o objeto Zap que voce criou

    }

    string toStringUser(){
        return this->userId;
    }


    friend class Chat;
};

class Registro{
    User * user;
    int underCount{0};
public:
    Registro(User * _user){
        user = _user;
    }
    void underCountPlus(int qtd){
        underCount += qtd;
    }
    int getUnderCount(){
        return this->underCount;
    }
    void setUnderCount(int valor){
        underCount = valor;
    }
};

class Chat{
    string chatId;
    vector<Zap> lista_zap;
    map<string, Registro> lista_reg;
    static bool enableInOutMsgs;
    static const string systemUsername = "system";
public:
    Chat(string _chatId){
        chatId = _chatId;
    }

    vector<string> getUser(){
        vector<string> users;
        for(auto par : lista_reg)
            users.push_back(par.first);
        return users;
    }

    bool addFirstUser(User * _chatCreator){
        if(((int) lista_reg.size()) != 0)
            throw "Erro ao adicionar o primeiro Usuário.\n";

        //Adicione o usuario
        lista_reg[_chatCreator->userId] = Registro(_chatCreator);
        //Se adicione a lista de grupos do usuario
        _chatCreator->lista_chat[this->chatId] = this;

    }

    void assertUser(string _user){
        if(!lista_reg.count(_user))
            throw _user + " não existe!";
    }


    void deliverZap(Zap _zap){

        /**
         *  # se nao for um zap do sistema, teste se o usuario esta no chat
        # adicione o zap na lista do grupo
        # para cada usuario do grupo
            # se ele nao for o emissor
                # incremente o contador de nao lidos
         */

        if(_zap.getUserId() == "system"){
            lista_zap.push_back(_zap);
            for(auto user : lista_reg){
                user.second.underCountPlus(1);
            }
        }else{
            assertUser(_zap.getUserId());
            lista_zap.push_back(_zap);
            for(auto user : lista_reg){
                if(user.first != _zap.getUserId()){
                    user.second.underCountPlus(1);
                }
            }
        }
    }

    /**
     *def getUnreadCount(userId):
    # retorne a quantidade de mensagens nao lidas desse user
     */
    int getUnreadCount(string _userId){
        assertUser(_userId);
        Registro aux = lista_reg[_userId];
        return aux.getUnderCount();
    }

    /**
     *def getUnread(userId):
    # teste se usuario existe no grupo
    # crie lista de retorno
    # veja quantas sao as mensagens nao lidas desse usuario
    # já coletando mensagens do grupo que nao forem emitidas
    # por esse usuario ate atingir a quantidade de nao lidas.
    # zere a quantidade de mensagens nao lidas
    # se nao houver mensagens, retorne que nao ha mensagens
     */

    vector<Zap> getUnread(string _userId){
        assertUser(_userId);
        vector<Zap> retorno;
        int tmhVetZap = (int) lista_zap.size();
        int qtdNLidas = getUnreadCount(_userId);

        if(tmhVetZap == 0){
            retorno.push_back(Zap("System", "Não ha zaps!\n"));
            return retorno;
        }

        while(qtdNLidas != 0){
            Zap zapAux = lista_zap[tmhVetZap - qtdNLidas];
            if(zapAux.getUserId() != _userId){
                retorno.push_back(zapAux);
                qtdNLidas -= 1;
            }
        }

        Registro auxReg = lista_reg[_userId];
        auxReg.setUnderCount(0);

        return retorno;
    }

    bool hasUser(string _userId){
        if(lista_reg.count(_userId))
            return true;
        return false;
    }

    string toStringChat(){
        return this->chatId;
    }

    friend class User;
};



#endif // WHATSAPP

