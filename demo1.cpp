#include "util.h"
#include <string>
#include <iostream>
#include "FtpClient.cpp"
using namespace std;
void simple_switch(char const* str)  
{  

    switch(hash_(str)){  
    case "first"_hash:  
        cout << "1st one" << endl;  
        break;  
    case "second"_hash:  
        cout << "2nd one" << endl;  
        break;  
    case "third"_hash:  
        cout << "3rd one" << endl;  
        break;  
    default:  
        cout << "Default..." << endl;  
    }  
}  

int main(){
    
    const string l = "ls";
    simple_switch("first");
    FtpClient f;
    // switch (l)    // {
    // case "ls"/* constant-expression */:
    //     /* code */
    //     cout<<"succeed"<<endl;
    //     break;
    
    // default:
    //     break;
    // }

    return 0;
}