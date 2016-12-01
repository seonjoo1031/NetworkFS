본 프로그램은 fuse 기반으로 Network file system을 구현한 것이다.
따라서 프로그램을 실행하기 위해서는 먼저 fuse library가 설치되어 있어야 한다.
fuse library는 https://github.com/libfuse/libfuse 에서 설치할 수 있다.
또한 server와 client는 socket으로 메세지를 주고 받는데 이때 google의 protobuf가 사용된다.
protobuf library는 https://github.com/google/protobuf 에서 설치할 수 있다. 

프로그램을 local에서 실행하기 위해 필요한 파일은 server 소스 코드인 server.cc, client 소스 코드인 fusexmp.cc, protobuf를 구현하기 위한 file.proto 파일이다.
server 소스 코드를 컴파일하기 위해서는 커맨드 입력 창에 g++ server.cc file.pb.cc -o server -lprotobuf 를 입력하고 client 소스 코드를 컴파일하기 위해서는 g++ -W fusexmp.cc file.pb.cc -o nfs -D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26 -lfuse -lprotobuf 를 입력한다.
이때 file.pb.cc 파일은 file.proto 파일을 컴파일하면 생성되는데 생성하기 위해서는 커맨드 입력 창에 protoc -I=%SRC_DIR% --cpp_out=%DST_DIR% %SRC_DIR%/file.proto 을 입력한다.
각각 실행 파일의 이름은 server, nfs 이다.
server 파일을 실행하기 위해서는 ./server [port number] 을 입력하고 nfs 파일을 실행하기 위해서는 ./nfs -f [port number] [mount folder] 을 입력한다.

본 프로그램에서 protobuf library를 사용하기 위해서는 특정 header 파일을 추가해야 하는데 /google/protobuf/io/zero_copy_stream_impl_lite.h, /google/protobuf/text_format.h 가 필요하다.
본 프로그램의 현재 소스 코드에서는
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/io/zero_copy_stream_impl_lite.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/text_format.h>
와 같이 추가된 상태이다.

또한 실제로 server에 올릴 때 경로를 지정하기 위해 server 소스 코드에서 mount directory 경로를
#define MNT_DIR "/home/seonjoo"
와 같이 설정하였다.
이와 같이 설정하면 client의 마운트 폴더에서 서버 디렉토리의 /home/seonjoo 를 바라볼 수 있게 된다.

본 프로그램에서 구현된 callback 함수는 9개로 getattr, access, readdir, mknod, mkdir, unlink, open, read, write이다.


