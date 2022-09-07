
#include "util.h"

int main(){
    string str = "USER root\r\n\377\377\177";
    cout<<str<<endl;
    trim(str);
    cout<<str<<endl;

    return 0;
}