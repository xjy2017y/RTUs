// clientTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Winsock2.h>
#include <cstdio>
#pragma comment(lib,"ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsaData;
    SOCKET sockClient;//�ͻ���Socket
    SOCKADDR_IN addrServer;//����˵�ַ
    WSAStartup(MAKEWORD(2,2),&wsaData);
    //�½��ͻ���socket
	//while(1){
		sockClient=socket(AF_INET,SOCK_STREAM,0);
		//����Ҫ���ӵķ���˵�ַ
		addrServer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//Ŀ��IP(127.0.0.1�ǻ��͵�ַ)
		addrServer.sin_family=AF_INET;
		addrServer.sin_port=htons(6000);//���Ӷ˿�6000
		//���ӵ������
		if(connect(sockClient,(SOCKADDR*)&addrServer,sizeof(SOCKADDR)) == -1){
			printf("error!");
		}
		//��������
		//char message[20]="123123123";
		//char message[20];
		char buf[6] = {0x01,0x03,0x00,0x02,0x75,0xc5};   
		printf("%d",strlen(buf));
		//scanf("%s",&message);
		send(sockClient,buf,(strlen(buf)+1)*2,0);
		char buff[100]; 

		//memset(buff, 0, sizeof(buff));	
		if(recv(sockClient,buff,strlen(buff),0) > 0){
			printf("�յ��ˣ�");
			printf("%s",buff);
		}else if(recv(sockClient,buff,strlen(buff),0) == 0){
			printf("��������������");
		}else{
			printf("error!");
		}
		//�ر�socket
		closesocket(sockClient);
	//}
    WSACleanup();
	return 0;
}

