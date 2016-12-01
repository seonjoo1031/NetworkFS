/*
  FUSE: Filesystem in Userspace
  Copyright (C) 2001-2007  Miklos Szeredi <miklos@szeredi.hu>
  Copyright (C) 2011       Sebastian Pipping <sebastian@pipping.org>

  This program can be distributed under the terms of the GNU GPL.
  See the file COPYING.

  gcc -Wall fusexmp.c `pkg-config fuse --cflags --libs` -o fusexmp
*/

#define FUSE_USE_VERSION 26

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef linux
/* For pread()/pwrite()/utimensat() */
#define _XOPEN_SOURCE 700
#endif


#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>

#ifdef HAVE_SETXATTR
#include <sys/xattr.h>
#endif

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "file.pb.h"
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/io/zero_copy_stream_impl_lite.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/text_format.h>  

using namespace std;
using namespace google;

int port;
int client_sockfd;

pthread_mutex_t oper_mutex = PTHREAD_MUTEX_INITIALIZER;


void send_protobuf(int oper, int client_sockfd, File send_param){
    // 미리 생성해야 하는 버퍼의 길이를 알아내어 버퍼할당
    int bufSize = send_param.ByteSize();
    
    // write(client_sockfd, &bufSize, sizeof(int));

    char* outputBuf = new char[bufSize];
    // 버퍼에 직렬화
    protobuf::io::ArrayOutputStream os(outputBuf, bufSize);
    send_param.SerializeToZeroCopyStream(&os);


    int size;
    size = write(client_sockfd, outputBuf, bufSize);
    printf("%d send size %d\n", oper, bufSize);
}

void *nfs_init(struct fuse_conn_info *conn)
{
	//connect
	int client_len;
    struct sockaddr_in clientaddr;
    

    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    clientaddr.sin_port = htons(port);
    
    client_len = sizeof(clientaddr);

    if (connect(client_sockfd, (struct sockaddr *)&clientaddr, client_len) < 0)
    {
        perror("Connect error: ");
        exit(0);
    }

}
static int xmp_getattr(const char *path, struct stat *stbuf)
{
	cout << "\ngetattr(path=" << path << ")" << endl;

	File req;
	req.Clear();
	req.set_oper(0);
	req.set_path(path);

	//send oper, path, stbuf
	send_protobuf(0, client_sockfd, req);
	// printf("getattr(send path to server)\n");

	//recv lstat return
	int res;
	read(client_sockfd, &res, sizeof(int));
	if(res == -1){
		printf("getattr(error %d)\n", res);
		return res-1;
	}

	//recv result from server - read
	char recv_msg[1024];

	int read_size;
	read_size = read(client_sockfd, recv_msg, sizeof(recv_msg));

	// printf("getattr(read from server %d)\n", read_size);

	//parse
	protobuf::io::ArrayInputStream is(recv_msg, sizeof(recv_msg));
	File reply;
	reply.ParseFromZeroCopyStream(&is);
		
	string get_stbuf;
	get_stbuf = reply.stbuf();
	// cout << "before sscanf : " << get_stbuf.c_str() << endl;

	//set stbuf
	int mode;
	int nlink;
	int uid;
	int gid;
	int size;
	int blksize;
	int blocks;

	sscanf( get_stbuf.c_str(), "%d %d %d %d %d %d %d",
		&mode, &nlink, &uid, &gid, &size, &blksize, &blocks);

	// printf( "after sscanf : %d %d %d %d %d %d %d\n", mode, nlink, uid, gid, size, blksize, blocks);

	stbuf->st_mode = (mode_t) mode;
	stbuf->st_nlink = (nlink_t) nlink;
	stbuf->st_uid = (uid_t) uid;
	stbuf->st_gid = (gid_t) gid;
	stbuf->st_size = (size_t) size;
	stbuf->st_blksize = (blksize_t) blksize;
	stbuf->st_blocks = (blkcnt_t) blocks;

	// printf("getattr(end %s)\n", path);

	return 0;

/*	int res;

	res = lstat(path, stbuf);
	if (res == -1)
		return -errno;

	return 0;*/


	
}

static int xmp_access(const char *path, int mask)
{
	cout << "\naccess(path=" << path << ", " << mask << ")" << endl;

	File req;
	
	req.set_oper(1);
	req.set_path(path);
	req.set_mask(mask);

	//send oper, path, stbuf
	send_protobuf(1, client_sockfd, req);
	printf("access(send path to server)\n");

	//recv access return
	int res;
	read(client_sockfd, &res, sizeof(int));
	if(res == -1){
		printf("access(error %d)\n", res);
		return res;
	}

	return 0;
}

static int xmp_readlink(const char *path, char *buf, size_t size)
{
	int res;

	res = readlink(path, buf, size - 1);
	if (res == -1)
		return -errno;

	buf[res] = '\0';
	return 0;
}


static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
	(void) offset;
	(void) fi;

	cout << "\nreaddir(path=" << path << ")" << endl;
	
	File req;
	req.Clear();
	req.set_oper(3);
	req.set_path(path);

	//send oper, path, stbuf
	send_protobuf(3, client_sockfd, req);
	// printf("readdir(send path)\n");

	//recv readdir return
	DIR *dp;
	read(client_sockfd, &dp, sizeof(dp));
	if(dp == NULL){
		printf("dp null");
		exit(0); //?
	}

	//recv result from server - read
	char recv_msg[10000];
	int size;
	
	while(1){
		memset(recv_msg, 0, sizeof(recv_msg));
		size = read(client_sockfd, recv_msg, sizeof(recv_msg));
		if( size < sizeof(recv_msg) ){
			break;
		}
			
	}
	

	//parse
	protobuf::io::ArrayInputStream is(recv_msg, sizeof(recv_msg));
	File reply;
	reply.ParseFromZeroCopyStream(&is);
	// printf("readdir(parse size %d)\n", reply.d_name_size());

	for(int i=0; i<reply.d_name_size(); i++){
		// cout << "readdir(d_name " << i+1 << " = " << reply.d_name(i).c_str() << ")" << endl;
		if (filler(buf, reply.d_name(i).c_str(), NULL, 0)){
			// perror("filler");
			break;
		}
	}
	printf("readdir(end %s)\n", path);
	return 0;

/*	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(path);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		// cout << "readdir(d_name=" << de->d_name << ")" << endl;

		if (filler(buf, de->d_name, NULL, 0))
			break;
	}

	closedir(dp);
	return 0;*/
}

static int xmp_mknod(const char *path, mode_t mode, dev_t rdev)
{
	cout << "\nrmknod(path=" << path << ")" << endl;
	
	File req;
	req.set_oper(4);
	req.set_path(path);
	req.set_mode(mode);
	req.set_rdev(rdev);

	//send oper, path, stbuf
	send_protobuf(4, client_sockfd, req);

	//recv access return
	int res;
	read(client_sockfd, &res, sizeof(int));
	if(res == -1){
		printf("mknod(error %d)\n", res);
		return res;
	}

	return 0;
}

static int xmp_mkdir(const char *path, mode_t mode)
{
	printf("\nmkdir(path=%s)\n", path);

	File req;
	
	req.set_oper(5);
	req.set_path(path);
	req.set_mode(mode);

	//send oper, path, stbuf
	send_protobuf(5, client_sockfd, req);
	printf("mkdir(send to server)\n");

	return 0;
}

static int xmp_unlink(const char *path)
{
	printf("\nunlink(path=%s)\n", path);

	File req;
	
	req.set_oper(7);
	req.set_path(path);

	//send oper, path, stbuf
	send_protobuf(7, client_sockfd, req);
	printf("unlink(send to server)\n");

	int res;
	read(client_sockfd, &res, sizeof(int));

	if(res == -1){
		printf("unlink(error %d)\n", res);
		return res;
	}

	return 0;
}

static int xmp_rmdir(const char *path)
{
	int res;

	res = rmdir(path);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_symlink(const char *from, const char *to)
{
	int res;

	res = symlink(from, to);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_rename(const char *from, const char *to)
{
	int res;

	res = rename(from, to);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_link(const char *from, const char *to)
{
	int res;

	res = link(from, to);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_chmod(const char *path, mode_t mode)
{
	int res;

	res = chmod(path, mode);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_chown(const char *path, uid_t uid, gid_t gid)
{
	int res;

	res = lchown(path, uid, gid);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_truncate(const char *path, off_t size)
{
	int res;

	res = truncate(path, size);
	if (res == -1)
		return -errno;

	return 0;
}

#ifdef HAVE_UTIMENSAT
static int xmp_utimens(const char *path, const struct timespec ts[2])
{
	int res;

	/* don't use utime/utimes since they follow symlinks */
	res = utimensat(0, path, ts, AT_SYMLINK_NOFOLLOW);
	if (res == -1)
		return -errno;

	return 0;
}
#endif

static int xmp_open(const char *path, struct fuse_file_info *fi)
{
	cout << "\nopen(path=" << path << ", " << fi->flags << ")" << endl;

	File req;
	
	req.set_oper(14);
	req.set_path(path);
	req.set_flag(fi->flags);

	//send oper, path, stbuf
	send_protobuf(14, client_sockfd, req);
	printf("open(send to server)\n");

	int res;
	read(client_sockfd, &res, sizeof(int));
	if(res == -1){
		printf("open(error %d)\n", res);
		return res;
	}


/*	int res;

	res = open(path, fi->flags);
	if (res == -1)
		return -errno;

	close(res);*/
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi)
{
	cout << "\nread(path=" << path << ", " << fi->fh << ")" << endl;

	File req;
	(void) fi;
	
	req.set_oper(15);
	req.set_path(path);
	req.set_size(size);
	req.set_offset(offset);

	//send oper, path, stbuf
	send_protobuf(15, client_sockfd, req);
	printf("read(send to server)\n");

	//recv buf size
	int bufSize;
	read(client_sockfd, &bufSize, sizeof(bufSize));

	printf("read(get buf size %d)\n", bufSize);

	//recv result from server - read
	char recv_msg[size];

	int read_size;
	read_size = read(client_sockfd, recv_msg, size);

	printf("getattr(read from server %d)\n", read_size);

	//parse
	protobuf::io::ArrayInputStream is(recv_msg, sizeof(recv_msg));
	File reply;
	reply.ParseFromZeroCopyStream(&is);


	// buf = (char*)reply.buf().c_str();
	strcpy(buf, reply.buf().c_str());

	printf("read(real buf %s)\n", buf);	

	return bufSize;
}

static int xmp_write(const char *path, const char *buf, size_t size,
		     off_t offset, struct fuse_file_info *fi)
{

	printf("write(path %s)\n", path);

	File req;

	req.set_oper(16);
	req.set_path(path);
	req.set_buf(buf);
	req.set_size(size);
	req.set_offset(offset);

	//send oper, path, stbuf
	send_protobuf(16, client_sockfd, req);
	printf("write(send to server)\n");

	(void) fi;
	
	//recv buf size
	int bufSize;
	read(client_sockfd, &bufSize, sizeof(bufSize));
	if(bufSize == -1){
		printf("write(error %d)\n", bufSize);
		return bufSize;
	}

	printf("write(get written size %d)\n", bufSize);

	return bufSize;
/*	int fd;
    int res;

    (void) fi;
    fd = open(path, O_WRONLY);
    if (fd == -1)
        return -errno;

    res = pwrite(fd, buf, size, offset);
    if (res == -1)
        res = -errno;

    close(fd);
    return res;*/
}

static int xmp_statfs(const char *path, struct statvfs *stbuf)
{
	int res;

	res = statvfs(path, stbuf);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_release(const char *path, struct fuse_file_info *fi)
{
	/* Just a stub.	 This method is optional and can safely be left
	   unimplemented */

	(void) path;
	(void) fi;
	return 0;
}

static int xmp_fsync(const char *path, int isdatasync,
		     struct fuse_file_info *fi)
{
	/* Just a stub.	 This method is optional and can safely be left
	   unimplemented */

	(void) path;
	(void) isdatasync;
	(void) fi;
	return 0;
}

#ifdef HAVE_POSIX_FALLOCATE
static int xmp_fallocate(const char *path, int mode,
			off_t offset, off_t length, struct fuse_file_info *fi)
{
	int fd;
	int res;

	(void) fi;

	if (mode)
		return -EOPNOTSUPP;

	fd = open(path, O_WRONLY);
	if (fd == -1)
		return -errno;

	res = -posix_fallocate(fd, offset, length);

	close(fd);
	return res;
}
#endif

#ifdef HAVE_SETXATTR
/* xattr operations are optional and can safely be left unimplemented */
static int xmp_setxattr(const char *path, const char *name, const char *value,
			size_t size, int flags)
{
	int res = lsetxattr(path, name, value, size, flags);
	if (res == -1)
		return -errno;
	return 0;
}

static int xmp_getxattr(const char *path, const char *name, char *value,
			size_t size)
{
	int res = lgetxattr(path, name, value, size);
	if (res == -1)
		return -errno;
	return res;
}

static int xmp_listxattr(const char *path, char *list, size_t size)
{
	int res = llistxattr(path, list, size);
	if (res == -1)
		return -errno;
	return res;
}

static int xmp_removexattr(const char *path, const char *name)
{
	int res = lremovexattr(path, name);
	if (res == -1)
		return -errno;
	return 0;
}
#endif /* HAVE_SETXATTR */

static struct fuse_operations xmp_oper;

void set_oper(){
	xmp_oper.init		= nfs_init;
	xmp_oper.getattr	= xmp_getattr;
	xmp_oper.access		= xmp_access;
	xmp_oper.readlink	= xmp_readlink;
	xmp_oper.readdir	= xmp_readdir;
	xmp_oper.mknod		= xmp_mknod;
	xmp_oper.mkdir		= xmp_mkdir;
	xmp_oper.symlink	= xmp_symlink;
	xmp_oper.unlink		= xmp_unlink;
	xmp_oper.rmdir		= xmp_rmdir;
	xmp_oper.rename		= xmp_rename;
	xmp_oper.link		= xmp_link;
	xmp_oper.chmod		= xmp_chmod;
	xmp_oper.chown		= xmp_chown;
	xmp_oper.truncate	= xmp_truncate;
#ifdef HAVE_UTIMENSAT
	xmp_oper.utimens	= xmp_utimens;
#endif
	xmp_oper.open		= xmp_open;
	xmp_oper.read		= xmp_read;
	xmp_oper.write		= xmp_write;
	xmp_oper.statfs		= xmp_statfs;
	xmp_oper.release	= xmp_release;
	xmp_oper.fsync		= xmp_fsync;
#ifdef HAVE_POSIX_FALLOCATE
	xmp_oper.fallocate	= xmp_fallocate;
#endif
#ifdef HAVE_SETXATTR
	xmp_oper.setxattr	= xmp_setxattr;
	xmp_oper.getxattr	= xmp_getxattr;
	xmp_oper.listxattr	= xmp_listxattr;
	xmp_oper.removexattr	= xmp_removexattr;
#endif
}

int main(int argc, char *argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	umask(0);
	port = atoi(argv[argc-2]);
	argv[argc-2] = argv[argc-1];
	argv[argc-1] = NULL;

	printf("port:%d\n", port);

	set_oper();
    	
	return fuse_main(argc-1, argv, &xmp_oper, NULL);


}
