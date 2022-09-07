#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "util.h"
#include <ace/OS.h>

#include "ffcs_ftp_client.cpp"
using namespace std;
int ACE_TMAIN(int argc, ACE_TCHAR* argv[])
{
	std::string ftp_host = "127.0.0.1";
			int ftp_port = 5010;


	std::string ftp_local_dir = "/home/scutech/ftp_server/";
	std::string ftp_remote_dir = "/home/scutech/client/";

	std::string ftp_local_file_tmp = "TaskThread.cpp";
	std::string ftp_local_file = "TaskThread.cpp";
	FTPClient ftp_client;
	do{
		cout<<"ftp>input ip:"<<endl;
		string ip;
		cin>>ip;
		cout<<"ftp>input server port:"<<endl;
		int port;
		cin>>port;

		ftp_client.setAddr(ip, port);
		if(!ftp_client.connect()){
			return 0;
		}
		std::string ftp_user;
		std::string ftp_pwd;
		cout<<"ftp>input your user name:"<<endl;
		cin>>ftp_user;
		cout<<"ftp>input your password:"<<endl;
		cin>>ftp_pwd;
		ftp_client.setUserInfo(ftp_user,ftp_pwd);
	}while(!ftp_client.LogoIn());
	

	do{
		cout<<"ftp>";
		string parameter;
		cin>>parameter;
		vector<string>cmd;
		Stringsplit(parameter, ' ', cmd);
		if(cmd[0] == "cd"){
			ftp_client.ChangeLocalDir(cmd[1]);
		}else if(cmd[0] == "quit"){
			ftp_client.LogoOut();
		}else if(cmd[0] == "put"){
			ftp_client.PutFile(cmd[1]);
		}else if(cmd[0] == "rename"){
			ftp_client.ReName(cmd[1], cmd[2]);
		}else if(cmd[0] == "get"){
			ftp_client.GetFile(cmd[1]);
		}else if(cmd[0] == "syst"){
			ftp_client.GetSysInfo();
		}else if(cmd[0] == "ls"){
			string path = cmd.size()>1?cmd[1]:"";
			string pathlist;
			ftp_client.List(pathlist, cmd[1]);
		}


	}while(true);
	return 0;
}

