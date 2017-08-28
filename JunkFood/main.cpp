#include <iostream>

using namespace std;

class JunkFood{
    float saldo;
    JunkFood(float _saldo = 0){
        saldo = _saldo;
    }

    float setSaldo( float valor){
        saldo += valor;
    }

    void getSaldo(){
        return this->getSaldo();
    }
};


int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
