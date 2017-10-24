#ifndef USER_H
#define USER_H
#include "Repository.h"
#include "Tweett.h"
#include <iostream>
#include <sstream>

using namespace std;

//class Tweett;

class User{
    string username;
    Repository<User> seguidores;
    Repository<User> seguidos;
    Repository<Tweett> myTweets;
    Repository<Tweett> timeLine;
    int unreadCount;
    int nextTwId;

public:
    User(string _username = ""){
        this->username = _username;
    }

    void seguir(User user){
        seguidos.add(user.getUserName(), user);

    }

//    void twittar(string msg){
//        myTweets.add();

//    }

    vector<Tweett> getUnread(){
        vector<Tweett> aux = timeLine.getValues();
        vector<Tweett> aux2;
        for(int i = ((int)aux.size() - unreadCount); i < ((int)aux.size()); i++){
            aux2.push_back(aux[i]);
        }
        return aux;
    }

    string getUserName(){
        return this->username;
    }

    vector<User> getSeguidores(){
        return this->seguidores.getValues();
    }

    vector<User> getSeguidos(){
        return this->seguidos.getValues();
    }

    vector<Tweett> getMyTweets(){
        return this->myTweets.getValues();
    }

    Repository<Tweett> getTimeLine(){
        return this->timeLine;
    }

    string toStringUser(){
        stringstream ss;
        ss << "Nome: " << getUserName() << endl;

        ss << "Seguidores: { ";
        vector<User> aux = seguidores.getValues();
        for(User elemento : aux){
            ss << elemento.getUserName() << " ";
        }
        ss << "}" << endl;

        ss << "Seguidos: { ";
        vector<User> aux2 = seguidos.getValues();
        for(User elemento: aux2){
            ss << elemento.getUserName() << " ";
        }
        ss << "}" << endl;

        ss << "Meus tweetts { ";
        vector<Tweett> aux3 = myTweets.getValues();
        for(Tweett elemento: aux3){
            ss << "ID: " << elemento.getTwId() << ": " << elemento.getMsg() << endl;
        }
        ss << "}";
    }
};

#endif // USER_H
