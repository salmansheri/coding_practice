// main.c

#include "toralizer.hpp"
#include <sys/socket.h>

/* ./toralize 1.2.3.4 80
 *  ./toralize is argc
 *  1.2.3.4 is argv 1
 *  80 argv 2
 * */
int main(
    int argc,
    char *argv[]) { // Argument counter(int argc) and argument pointer(*args[])
  char *host;
  int port, s;
  struct sockaddr_in sock;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <post>\n", argv[0]);

    return -1;
  }
  host = argv[1];
  port = atoi(argv[2]);
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    perror("socket");
    return -1;
  }
  sock.sin_family = AF_INET;
  sock.sin_port = htons(PROXYPORT);
  sock.sin_addr.s_addr = inet_addr(PROXY);
  if (connect(s, (struct sockaddr *)&sock, sizeof(sock))) {
    perror("Connect");
    return -1;
  }

  printf("Connect to proxy server");
  close(s);
  return 0;
}
