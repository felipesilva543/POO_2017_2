#ifndef TWEET_H
#define TWEET_H
#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"

using namespace std;



class Tweet{
    string idTw;
    string userName;
    string msg;
    vector<string> likes;
public:
    Tweet(int _idTw, string _userName, string _msg){
        this->idTw = _idTw;
        this->userName = _userName;
        this->msg = _msg;
    }

    void addLike(string _username){
        likes.push_back(_username);
    }

    string getTwId(){
        return this->idTw;
    }

    string getUserName(){
        return this->userName;
    }

    string getMsg(){
        return this->msg;
    }

    string toString(){
        stringstream ss;
        ss << "Id: " << this->idTw << endl;
        ss << "User Name: " << this->userName << endl;
        ss << "Msg: " << this->msg << endl;
        ss << "{ ";
        for(auto elemento : this->likes){
            ss << elemento.getUserName() << " ";
        }
        ss << "}";

        return ss.str();
    }
};

#endif // TWEET_H
