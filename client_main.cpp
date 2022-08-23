#include "FtpClient.cpp"

#include <ace/OS.h>
#include <ace/Log_Msg.h>
#include <iostream>


#define REMOTEADDR "127.0.0.1"
#define USER "root"
#define PASSWORD "dingjia"

using namespace std;

int main()
{
    FtpClient ftpclient;
    // if(ftpclient.FtpLogin(REMOTEADDR,USER,PASSWORD)!=0)
    // {
    //     ACE_DEBUG((LM_DEBUG,"username or password is invalid\n"));
    //     ACE_OS::exit(-1);
    // }

    ftpclient.run();
    return 0;
}