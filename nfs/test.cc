#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
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
#include <queue>

#define HI hi

using namespace std;
using namespace google;

typedef enum{
	GETATTR,
	OPEN,
} OPER_TYPE;

int main(){
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	OPER_TYPE oper;

	oper = GETATTR;
	switch(oper){
		case GETATTR: cout << "GETATTR" << endl; break;
		case OPEN: cout << "OPEN" << endl; break;
	}

	ostringstream sample;
	string result;

	sample << "hello "
			<< "world";
	result = sample.str();

	printf("%s\n", result.c_str());


	string token;


	string str[2];

	int i=0;

	std::stringstream split_stream(result);


	while(1)
	{
		if( split_stream >> token )
		{
			str[i] = token;
			cout << str[i] << endl;

			i++;
					}
		else break;
	}

	// struct stat *stbuf;
	// stbuf = (struct stat*) malloc( sizeof(stbuf) );
	// if( lstat("/tmp/test", stbuf) < 0 ){
	// 	perror("lstat");
	// }

	int res = -1;
	char error[1];
	// error = (char*) malloc( sizeof(int) * 8 );
	// printf("%d\n", sizeof(res) );
	sprintf(error, "%d", res);
	if( !strcmp(error, "-1") )
		printf("error = -1\n");
	// free(error);

	queue<int> test;

	test.push(1);

	int a;
	test.pop();

	a = test.front();

	printf("queue : %d\n", a);

	printf("protobuf add test\n");
	File file;
	file.add_d_name("seonjoo");
	file.add_d_name("A");
	file.add_d_name("B");

	for(int i=0; i<file.d_name_size(); i++){
		cout << i << " : " << file.d_name(i) << endl;
	}

	printf("\nsize test\n");
	printf("pre size : %d\n", file.ByteSize());

	file.set_oper(file.ByteSize());
	
	printf("next size : %d\n", file.ByteSize());

	printf("string test\n");
	char *hi="hi";
	string fpath;
	fpath = hi;
	fpath.append("hello");
	cout << fpath << endl;

	printf("\ndefine test\n");
	string path;
	path = HI;
	path.append("thread");

	cout << path << endl;
	

	return 0;
}