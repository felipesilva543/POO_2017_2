#include <iostream>
#include "split.h"
using namespace std;

int main()
{
    string line = "";
    while(line != "fim"){
        cout << "(help): ";
        getline(cin, line);

        auto ui = split(line);

        for(int i = 0; i < (int) ui.size(); i++){
            int j = Int(ui[i]);
            printf("%d\n", j);
        }
    }


    return 0;
}

