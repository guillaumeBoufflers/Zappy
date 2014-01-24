#if defined (WIN32)
    #include <winsock2.h>
typedef int socklen_t;
#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#endif
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
  
  
int main(int ac, char **av)
{
#if defined (WIN32)
  WSADATA WSAData;
  int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
#else
  int erreur = 0;
#endif
  
  SOCKET sock;
  SOCKADDR_IN sin;
  SOCKET csock;
  SOCKADDR_IN csin;
  char buffer[32] = "Bonjour !";
  socklen_t recsize = sizeof(csin);
  int sock_err;
  
  /* Si les sockets Windows fonctionnent */
  if(!erreur)
    {
      sock = socket(AF_INET, SOCK_STREAM, 0);
  
      /* Si la socket est valide */
      if(sock != INVALID_SOCKET)
        {
	  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
  
	  /* Configuration */
	  sin.sin_addr.s_addr    = htonl(INADDR_ANY);   /* Adresse IP automatique */
	  sin.sin_family         = AF_INET;             /* Protocole familial (IP) */
	  sin.sin_port           = htons(atoi(av[1]));         /* Listage du port */
	  sock_err = bind(sock, (SOCKADDR*)&sin, sizeof(sin));
  
	  /* Si la socket fonctionne */
	  if(sock_err != SOCKET_ERROR)
            {
	      /* Démarrage du listage (mode server) */
	      sock_err = listen(sock, 5);
  
	      /* Si la socket fonctionne */
	      if(sock_err != SOCKET_ERROR)
                {
		  /* Attente pendant laquelle le client se connecte */
		  //		  printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);        
  
		  csock = accept(sock, (SOCKADDR*)&csin, &recsize);
		  printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));  
		  char	buff[32768];

		  while (1)
		    {
		      bzero(buff, 32768);
		      read(0, buff, 32767);
		      write(csock, buff, 32767);
		    }
		}
            }
  
	  /* Fermeture de la socket */
	  printf("Fermeture de la socket...\n");
	  closesocket(sock);
	  printf("Fermeture du serveur terminee\n");
        }
  
#if defined (WIN32)
      WSACleanup();
#endif
    }
  
  /* On attend que l'utilisateur tape sur une touche, puis on ferme */
  getchar();
  
  return EXIT_SUCCESS;
}
