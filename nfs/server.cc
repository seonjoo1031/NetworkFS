#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "file.pb.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <dirent.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/io/zero_copy_stream_impl_lite.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/text_format.h>

#define MNT_DIR "/home/seonjoo"

using namespace std;
using namespace google;

int client_sockfd;

typedef enum{
    GETATTR,
    ACCESS,
    READLINK,
    READDIR,
    MKNOD,
    MKDIR,
    SYMLINK,
    UNLINK,
    RMDIR,
    RENAME,
    LINK,
    CHMOD,
    CHOWN,
    TRUNCATE,
    OPEN,
    READ,
    WRITE,
    STATFS,
    RELEASE,
    FSYNC,

} OPER_TYPE;




static int xmp_getattr(File file)
{
    int res;
    struct stat stbuf;
   
    string path;
    path = MNT_DIR;
    path.append(file.path());
    
    cout << "\ngetattr(path=" << path << ")" << endl;
    
    //get stat
    res = lstat(path.c_str(), &stbuf);
    write(client_sockfd, &res, sizeof(int));
    if (res == -1){
        
        perror("lstat");
        // printf("getattr(lstat %s)\n", path.c_str());
        // int errsv = -errno;
        // cout << errsv << endl;
        return -errno;
    }

    //stat to string
    ostringstream temp;
    
    temp << stbuf.st_mode << " "
        << stbuf.st_nlink << " "
        << stbuf.st_uid << " "
        << stbuf.st_gid << " "
        << stbuf.st_size << " "
        << stbuf.st_blksize << " "
        << stbuf.st_blocks << " ";

    File msg_stbuf;
    msg_stbuf.Clear();
    msg_stbuf.set_stbuf(temp.str());
    // cout << str_stbuf.c_str();

    // 미리 생성해야 하는 버퍼의 길이를 알아내어 버퍼할당
    int bufSize = msg_stbuf.ByteSize();
    char* outputBuf = new char[bufSize];

    // 버퍼에 직렬화
    protobuf::io::ArrayOutputStream os(outputBuf, bufSize);
    msg_stbuf.SerializeToZeroCopyStream(&os);

    //send stbuf
    int size;
    size = write(client_sockfd, outputBuf, bufSize);
    // printf("getattr(send statbuf %d)\n", size);

    // cout << "getattr(end " << path << ")" << endl;
    return 0;
}

static int xmp_access(File file)
{
    int res;
    int mask;

    mask = file.mask();

    string path;
    path = MNT_DIR;
    path.append(file.path());

    cout << "\naccess(path=" << path << ", " << mask << ")" << endl;
    
    res = access(path.c_str(), mask);

    write(client_sockfd, &res, sizeof(int));
    if (res == -1){
        // int errsv = -errno;
        // cout << errsv << endl;
        perror("access");
        return -errno;
    }
    cout << "access end" << endl;
    return 0;
}

static int xmp_readdir(File file)
{
    string path;
    path = MNT_DIR;
    path.append(file.path());

    cout << "\nreaddir(path=" << path << ")" << endl;

    DIR *dp;
    struct dirent *de;

    dp = opendir(path.c_str());
    write(client_sockfd, &dp, sizeof(int));
    if (dp == NULL){
        
        perror("opendir");
  
        return -errno;
    }

    File reply;
    reply.Clear();
    int i=1;
    while ((de = readdir(dp)) != NULL) {
        
        reply.add_d_name(de->d_name);

        // cout << "readdir(d_name " << i << " = " << de->d_name << ")" << endl;
        i++;
    }
    

    printf("readdir(size %d)\n", reply.d_name_size());

    // 미리 생성해야 하는 버퍼의 길이를 알아내어 버퍼할당
    int bufSize = reply.ByteSize();
    char* outputBuf = new char[bufSize];

    // 버퍼에 직렬화
    protobuf::io::ArrayOutputStream os(outputBuf, bufSize);
    reply.SerializeToZeroCopyStream(&os);

    //send
    int size;
    size = write(client_sockfd, outputBuf, bufSize);
    // printf("readdir(send %d)\n", size);

    closedir(dp);
    cout << "readdir(end " << path << ")" << endl;

    return 0;

}

static int xmp_open(File file)
{
    
    string path;
    path = MNT_DIR;
    path.append(file.path());

    int flag;
    flag = file.flag();
    cout << "\nopen(path=" << path << ")" << endl;

    int res;
    write(client_sockfd, &res, sizeof(int));
    res = open(path.c_str(), flag);
    if (res == -1){
        // int errsv = -errno;
        // cout << errsv << endl;
        return -errno;
    }

    close(res);
    return 0;
}

static int xmp_read(File file)
{
    
    int size;
    int offset;
    char buf[4096];
    int fd;

    string path;
    path = MNT_DIR;
    path.append(file.path());

    size = file.size();
    offset = file.offset();

    printf("\nread path %s, size %d, offset %d\n", path.c_str(), size, offset);

    fd = open(path.c_str(), O_RDONLY);
    if( fd == -1 ){
        return -errno;
    }

    int read_size;
    if( (read_size = pread(fd, buf, size, offset)) == -1){
        perror("pread");
        return -errno;
    }
    printf("read(read size %d)\n", read_size);

    //send buf size
    write(client_sockfd, &read_size, sizeof(int));

    File reply;
    reply.set_buf(buf);
    printf("read(reply buf %s)\n", reply.buf().c_str());

    // 미리 생성해야 하는 버퍼의 길이를 알아내어 버퍼할당
    int bufSize = reply.ByteSize();
    char* outputBuf = new char[bufSize];

    // 버퍼에 직렬화
    protobuf::io::ArrayOutputStream os(outputBuf, bufSize);
    reply.SerializeToZeroCopyStream(&os);

    //send
    int written_size = write(client_sockfd, outputBuf, bufSize);
    printf("read(written size %d)\n", written_size);

    return read_size;
}

static int xmp_mknod(File file)
{
    int mode = file.mode();

    string path;
    path = MNT_DIR;
    path.append(file.path());

    int rdev = file.rdev();


    int res;

    /* On Linux this could just be 'mknod(path, mode, rdev)' but this
       is more portable */
    if (S_ISREG(mode)) {
        res = open(path.c_str(), O_CREAT | O_EXCL | O_WRONLY, mode);
        if (res >= 0)
            res = close(res);
    } else if (S_ISFIFO(mode))
        res = mkfifo(path.c_str(), mode);
    else
        res = mknod(path.c_str(), mode, rdev);

    write(client_sockfd, &res, sizeof(int));

    if (res == -1)
        return -errno;

    return 0;
}

static int xmp_mkdir(File file)
{
    int mode;
    int res;

    mode = file.mode();

    string path;
    path = MNT_DIR;
    path.append(file.path());

    res = mkdir(path.c_str(), mode);
    if (res == -1)
        return -errno;

    return 0;
}

static int xmp_unlink(File file)
{
    string path;
    path = MNT_DIR;
    path.append(file.path());

    int res;

    res = unlink(path.c_str());
    write(client_sockfd, &res, sizeof(int));
    if (res == -1)
        return -errno;

    return 0;
}

static int xmp_write(File file)
{
   
    int size;
    int offset;
    string buf;
    int fd;

    string path;
    path = MNT_DIR;
    path.append(file.path());

    size = file.size();
    offset = file.offset();
    buf = file.buf();

    // char written_buf[4096];
    // strcpy(written_buf, buf.c_str();

    printf("\nwrite path %s, size %d, offset %d, buf %s\n", path.c_str(), size, offset, buf.c_str());

    fd = open(path.c_str(), O_WRONLY);
    if( fd == -1 ){
        return -errno;
    }

    int written_size;
    if( (written_size = pwrite(fd, buf.c_str(), size, offset)) == -1){
        perror("pwrite");
        return -errno;
    }
    printf("write(buf %s)\n", buf.c_str());
    printf("write(written size %d)\n", written_size);

    //send buf size
    write(client_sockfd, &written_size, sizeof(int));

    close(fd);

    return written_size;
}

void get_oper(OPER_TYPE oper, File file)
{
    switch(oper)
    {
        case GETATTR: xmp_getattr(file); break;
        case ACCESS: xmp_access(file); break;
        // case READLINK: xmp_readlink(file); break;
        case READDIR: xmp_readdir(file); break;
        case MKNOD: xmp_mknod(file); break;
        case MKDIR: xmp_mkdir(file); break;
        // case SYMLINK: xmp_symlink(file); break;
        case UNLINK: xmp_unlink(file); break;
        // case RMDIR: xmp_rmdir(file); break;
        // case RENAME: xmp_rename(file); break;
        // case LINK: xmp_link(file); break;
        // case CHMOD: xmp_chmod(file); break;
        // case CHOWN: xmp_chown(file); break;
        // case TRUNCATE: xmp_truncate(file); break;
        case OPEN: xmp_open(file); break;
        case READ: xmp_read(file); break;
        case WRITE: xmp_write(file); break;
        // case STATFS: xmp_statfs(file); break;
        // case RELEASE: xmp_release(file); break;
        // case FSYNC: xmp_fsync(file); break;
    }
}


int main(int argc, char **argv)
{
    int server_sockfd;
    int state, client_len;

    struct sockaddr_in clientaddr, serveraddr;

    if (argc != 2)
    {
        printf("Usage : ./server [port]\n");
        exit(0);
    }

    state = 0;

    // internet 기반의 소켓 생성 (INET)
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error : ");
        exit(0);
    }
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    //prevent bind error
    // int nSockOpt;
    // nSockOpt = 1;
    // setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &nSockOpt, sizeof(nSockOpt));

    state = bind(server_sockfd , (struct sockaddr *)&serveraddr,
            sizeof(serveraddr));
    if (state == -1)
    {
        perror("bind error : ");
        exit(0);
    }

    state = listen(server_sockfd, 5);
    if (state == -1)
    {
        perror("listen error : ");
        exit(0);
    }

    client_len = sizeof(clientaddr);

    while(1)
    {
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&clientaddr,
                               (socklen_t*)&client_len);
        if (client_sockfd == -1)
        {
            perror("Accept error : ");
            exit(0);
        }
        int i=0;
        while(1)
        {	
        	int size;
        	int bufSize;

            // read(client_sockfd, &bufSize, sizeof(int));
            
            // printf("main(size buf %d)\n", bufSize);

            char buf[1024];

            // size = read(client_sockfd, buf, sizeof(buf));

            if ( (size = read(client_sockfd, buf, sizeof(buf))) <= 0)
            {
            	perror("Read error : ");
                close(client_sockfd);
                break;
            }
            printf("main(read size %d)\n", size);

            // printf("start parsing\n");
        	protobuf::io::ArrayInputStream is(buf, sizeof(buf));
			File file;
			file.ParseFromZeroCopyStream(&is);

            int oper;
            oper = file.oper();

            printf("main(oper %d)\n", oper);
            get_oper((OPER_TYPE)oper, file);
            // printf("main end\n");
			
        }
    }
    close(client_sockfd);
}
