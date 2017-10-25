#ifndef USER_H
#define USER_H
#include "Repository.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Tweet;

class User{
    string username;
    vector<User*> seguidores;
    vector<User*> seguidos;
    vector<Tweet> myTweets;
    vector<Tweet*> timeLine;
    int unreadCount;
    int nextTwId;

public:
    User(string _username = ""){
        this->username = _username;
    }

    void seguir(User user){
        seguidos.add(user.getUserName());

    }

//    void twittar(string msg){
//        myTweets.add();

//    }

    vector<Tweet> getUnread(){
        vector<Tweet> aux = timeLine.getValues();
        vector<Tweet> aux2;
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

    vector<Tweet> getMyTweets(){
        return this->myTweets.getValues();
    }

    vector<Tweet> getTimeLine(){
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
        vector<Tweet> aux3 = myTweets.getValues();
        for(Tweet elemento: aux3){
            ss << "ID: " << elemento.getTwId() << ": " << elemento.getMsg() << endl;
        }
        ss << "}";
    }
};

#endif // USER_H
