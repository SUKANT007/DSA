#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
	int server_sock;
	int client_sock;
	int error;
//create the server socket
	server_sock = socket(PF_INET, SOCK_STREAM, 0);
// Need an address to bind the serversocket to
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_family = PF_INET;
	server_address.sin_port = htons(2222);
// bind the server socket to a local address
	error = bind(server_sock,
	             (struct sockaddr *)&server_address,
	             sizeof(server_address));
	if (error == -1)
	{
		perror("bind failed.");
		return 1;
		1
		2 GODFREY MUGANDA
	}
// listen for a connection
	error = listen(server_sock, 10);
	if (error == -1)
	{
		perror("listen failed.");
		return 3;
	}
	cerr << "Now listening for connections..." << endl;
// accept a connection
	struct sockaddr_in client_address;
	socklen_t client_addr_len;
	error = client_sock = accept(server_sock,
	                             (struct sockaddr *) &client_address,
	                             &client_addr_len);
	if (error == -1)
	{
		perror("accept failed.");
		return 0;
	}
	cerr << "Connection request received." << endl;
	write(client_sock, "hello there!", 12);
	close(client_sock);
	close(server_sock);
	return 0;
}