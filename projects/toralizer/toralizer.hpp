// toralizer.h

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PROXY "127.0.0.1" // constant definition
#define PROXYPORT 9050    // constant definition proxy Port

typedef unsigned char int8;

typedef unsigned short int int16;
typedef unsigned int int32;

struct proxy_request {
  int8 vn;
  int8 cd;
  int16 dstPost;
  int32 dstIp;
  unsigned char userId[8];
};

typedef struct proxy_request Req;
struct proxyResponse {
  int8 vn;
  int8 cd;
  int16 _;
  int32 __;
};

typedef struct proxyRequest Res;
