#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

char message[] = "Hello Serv!";
char buf[sizeof(message)];

int main()
{
	int sock;
	struct sockaddr_in addr;
	
	sock = socket(AF_INET, SOCK_STREAN, 0);
	if(sock < 0)
	{
		perror("socket");
		exit(1);
	}
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = htnol(INADDR_LOOPBACK);
	if(connect(sock,(struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("connect");
		exit(2);
	}
	
	send(sock,message,sizeof(message),0);
	recv(sock, buf, sizeof(message), 0);
	
	printf(buf);
	close(sock);
	
	return 0;
}

