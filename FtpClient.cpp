#include "FtpClient.h"
#include "util.h"
#include <ace/Log_Msg.h>
#include <ace/SOCK_Connector.h>
#include <ace/Reactor.h>
#include <ace/SOCK_Acceptor.h>
#include <ace/Thread_Manager.h>
#include <ace/streams.h>
#include <ace/TP_Reactor.h>
#include <string.h>


#define SERVER_PORT 8080

FtpClient::FtpClient()
{
    ACE_DEBUG((LM_DEBUG, "FtpClient() invoked"));
}

FtpClient::~FtpClient()
{
    ACE_DEBUG((LM_DEBUG, "~FtpClient() invoked!\n"));
}

int FtpClient::FtpLogin(const char *pRemoteAddr, const char *pUser, const char *pPassWord)
{
    ACE_DEBUG((LM_DEBUG, "FtpClient run, and remoteAddr:%s", pRemoteAddr));
    int index = 0;
    char acBuf[256] = {0};
    char aceConmmand[50] = {0};
    ACE_SOCK_Connector connector;
    ACE_INET_Addr serverAddr(SERVER_PORT, pRemoteAddr);
    if (connector.connect(s_Server, serverAddr) == -1)
    {
        ACE_ERROR_RETURN((LM_ERROR, "%p Addr[%s]\n", "open server", pRemoteAddr), -1);
    }
    s_Server.recv(acBuf, 256);
    ACE_DEBUG((LM_DEBUG, "FtpClient::FtpLogin()user[%s]pwd[%s] FIRST[%s]!\n", pUser, pPassWord, acBuf));
    while (++index < 3)
    {
        /* code */
        switch (index)
        {
        case 1:
            ACE_OS::sprintf(aceConmmand, "USER %s\r\n", pUser);
            break;

        case 2:
            ACE_OS::sprintf(aceConmmand, "USER %s\r\n", pPassWord);

        default:
            break;
        }
        s_Server.send_urg(aceConmmand, strlen(aceConmmand));
        ACE_OS::memset(acBuf, 0x00, 256);
        ACE_OS::sleep(1);
        ACE_DEBUG((LM_DEBUG, "FtpClient::FtpLogin() UORP[%s]!\n", acBuf));
    }

    ACE_DEBUG((LM_DEBUG, "FtpClient::FtpLogin() Login Server Success!\n"));
    return 0;
}

void FtpClient::run()
{
    string cmd;
    vector<string> vCmd;
    cout << ">";
    while (cin >> cmd)
    {
        vCmd = split(cmd, " ");
        string realCmd = vCmd.front();        switch (hash_(realCmd.c_str()))
        {
        case "ls"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "cd"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "put"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "mput"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "get"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "mget"_hash:
            /* code */
            cout << "coding" << endl;
            break;
        case "bye"_hash:
        case "quit"_hash:
            /* code */
            cout << "coding" << endl;
            break;

        default:
            ACE_DEBUG((LM_ERROR, "not this command option!\n"));
            break;
        }
        cout << ">";
    }
}

int FtpClient::FtpPutFile(const char *pRemodeFileName,  const char *pLocalFileName, const char * pLocal,const char *pLocalPort)
{
    ACE_DEBUG((LM_DEBUG, "FtpClient::FtpPutFile() invoke!\n"));

    int iLen = 0;
    int acBuf[256] = {0};

    int acCmd[128] = {0};
    FILE *fp = NULL;
    ACE_Handle_Set handle_set;
    return 0;
}

