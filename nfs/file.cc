#include <iostream>
#include <fstream>
#include <string>
#include "file.pb.h"
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/io/zero_copy_stream_impl_lite.h>
#include </home/seonjoo/Documents/protobuf-2.6.1/src/google/protobuf/text_format.h>

using namespace std;
using namespace google;

int main(int argc, char* argv[])
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
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

	// 버퍼에서 역직렬화
	protobuf::io::ArrayInputStream is(outputBuf, bufSize);
	File dst_file;
	dst_file.ParseFromZeroCopyStream(&is);

	// Message 객체에서 값 가져오기
	string path = dst_file.path();
	int id = dst_file.id();

	printf("path:%s\n", path.c_str());
	printf("id:%d\n", id);

	// 메모리 해제
	delete [] outputBuf;
	outputBuf = NULL;
	protobuf::ShutdownProtobufLibrary();
	return 0;
}