// clientTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Winsock2.h>
#include <cstdio>
#pragma comment(lib,"ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
    SOCKET sockClient;//客户端Socket
    SOCKADDR_IN addrServer;//服务端地址
    WSAStartup(MAKEWORD(2,2),&wsaData);
    //新建客户端socket
	//while(1){
		sockClient=socket(AF_INET,SOCK_STREAM,0);
		//定义要连接的服务端地址
		addrServer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//目标IP(127.0.0.1是回送地址)
		addrServer.sin_family=AF_INET;
		addrServer.sin_port=htons(6000);//连接端口6000
		//连接到服务端
		if(connect(sockClient,(SOCKADDR*)&addrServer,sizeof(SOCKADDR)) == -1){
			printf("error!");
		}
		//发送数据
		//char message[20]="123123123";
		//char message[20];
		char buf[6] = {0x01,0x03,0x00,0x02,0x75,0xc5};   
		printf("%d",strlen(buf));
		//scanf("%s",&message);
		send(sockClient,buf,(strlen(buf)+1)*2,0);
		char buff[100]; 

		//memset(buff, 0, sizeof(buff));	
		if(recv(sockClient,buff,strlen(buff),0) > 0){
			printf("收到了：");
			printf("%s",buff);
		}else if(recv(sockClient,buff,strlen(buff),0) == 0){
			printf("服务器端无数据");
		}else{
			printf("error!");
		}
		//关闭socket
		closesocket(sockClient);
	//}
    WSACleanup();
	return 0;
}

