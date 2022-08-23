#ifndef FTPCLIENT_H_
#define FTPCLIENT_H_

#include <ace/SOCK_Stream.h>
#include <iostream>
using namespace std;
class ACE_SOCK_Stream;

class FtpClient
{
private:
    int ReplaceChar(char *pFullString,const char OldChar,const char NewChar);
    ACE_SOCK_Stream s_Server;
public:
    FtpClient();
    ~FtpClient();
    int FtpLogin(const char *pRemoteAddr, const char *pUser, const char *pPassWord);
    int FtpPutFile(const char *pRemodeFileName, const char *pLocalFileName, const char * pLocal, const char *pLocalPort);
    int FtpLogOut(void);
    int FtpGetFile(const char *pRemoteFileName);
    int FtpMGetFile();
    int FtpLs();
    int FtpCd(const char *pRemoteFileName);
    void run();

};

#endif