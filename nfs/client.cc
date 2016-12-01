#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <iostream>
#include <fstream>
#include "file.pb.h"
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/io/zero_copy_stream_impl_lite.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/text_format.h>

using namespace std;
using namespace google;

int main(int argc, char **argv)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    int client_len;
    int client_sockfd;


    struct sockaddr_in clientaddr;

    if (argc != 2)
    {
        printf("Usage : ./client [port]\n");
        exit(0);
    }


    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientaddr.sin_port = htons(atoi(argv[1]));

    client_len = sizeof(clientaddr);

    if (connect(client_sockfd, (struct sockaddr *)&clientaddr, client_len) < 0)
    {
        perror("Connect error: ");
        exit(0);
    }
    while(1)
    {
        // Message 객체에 값 세팅
        File file;
        file.set_path("/home/seonjoo/Documents");
        file.set_id(10);

        // 미리 생성해야 하는 버퍼의 길이를 알아내어 버퍼할당
        int bufSize = file.ByteSize();
        char* outputBuf = new char[bufSize];

        // 버퍼에 직렬화
        protobuf::io::ArrayOutputStream os(outputBuf, bufSize);
        file.SerializeToZeroCopyStream(&os);


        write(client_sockfd, outputBuf, bufSize);

        sleep(5);

        

        // {
        //   // Create a message and serialize it.
        //   File foo;
        //   foo.set_path("Hello World!");
        //   foo.set_id(1);

        //   int bufSize = foo.ByteSize();
        //   char* outputBuf = new char[bufSize];

        //   foo.SerializeToString(&outputBuf);
        //   write(client_sockfd, outputBuf, bufSize);
        // }

       
        return 0;
    }

    close(client_sockfd);
    exit(0);
}