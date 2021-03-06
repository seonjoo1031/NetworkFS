// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: file.proto

#ifndef PROTOBUF_file_2eproto__INCLUDED
#define PROTOBUF_file_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_file_2eproto();
void protobuf_AssignDesc_file_2eproto();
void protobuf_ShutdownFile_file_2eproto();

class File;

// ===================================================================

class File : public ::google::protobuf::Message {
 public:
  File();
  virtual ~File();

  File(const File& from);

  inline File& operator=(const File& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const File& default_instance();

  void Swap(File* other);

  // implements Message ----------------------------------------------

  File* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const File& from);
  void MergeFrom(const File& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 oper = 1;
  inline bool has_oper() const;
  inline void clear_oper();
  static const int kOperFieldNumber = 1;
  inline ::google::protobuf::int32 oper() const;
  inline void set_oper(::google::protobuf::int32 value);

  // optional string path = 2;
  inline bool has_path() const;
  inline void clear_path();
  static const int kPathFieldNumber = 2;
  inline const ::std::string& path() const;
  inline void set_path(const ::std::string& value);
  inline void set_path(const char* value);
  inline void set_path(const char* value, size_t size);
  inline ::std::string* mutable_path();
  inline ::std::string* release_path();
  inline void set_allocated_path(::std::string* path);

  // optional string stbuf = 3;
  inline bool has_stbuf() const;
  inline void clear_stbuf();
  static const int kStbufFieldNumber = 3;
  inline const ::std::string& stbuf() const;
  inline void set_stbuf(const ::std::string& value);
  inline void set_stbuf(const char* value);
  inline void set_stbuf(const char* value, size_t size);
  inline ::std::string* mutable_stbuf();
  inline ::std::string* release_stbuf();
  inline void set_allocated_stbuf(::std::string* stbuf);

  // optional int32 mask = 4;
  inline bool has_mask() const;
  inline void clear_mask();
  static const int kMaskFieldNumber = 4;
  inline ::google::protobuf::int32 mask() const;
  inline void set_mask(::google::protobuf::int32 value);

  // optional int32 mode = 5;
  inline bool has_mode() const;
  inline void clear_mode();
  static const int kModeFieldNumber = 5;
  inline ::google::protobuf::int32 mode() const;
  inline void set_mode(::google::protobuf::int32 value);

  // optional int64 rdev = 6;
  inline bool has_rdev() const;
  inline void clear_rdev();
  static const int kRdevFieldNumber = 6;
  inline ::google::protobuf::int64 rdev() const;
  inline void set_rdev(::google::protobuf::int64 value);

  // optional string from = 7;
  inline bool has_from() const;
  inline void clear_from();
  static const int kFromFieldNumber = 7;
  inline const ::std::string& from() const;
  inline void set_from(const ::std::string& value);
  inline void set_from(const char* value);
  inline void set_from(const char* value, size_t size);
  inline ::std::string* mutable_from();
  inline ::std::string* release_from();
  inline void set_allocated_from(::std::string* from);

  // optional string to = 8;
  inline bool has_to() const;
  inline void clear_to();
  static const int kToFieldNumber = 8;
  inline const ::std::string& to() const;
  inline void set_to(const ::std::string& value);
  inline void set_to(const char* value);
  inline void set_to(const char* value, size_t size);
  inline ::std::string* mutable_to();
  inline ::std::string* release_to();
  inline void set_allocated_to(::std::string* to);

  // optional int32 uid = 9;
  inline bool has_uid() const;
  inline void clear_uid();
  static const int kUidFieldNumber = 9;
  inline ::google::protobuf::int32 uid() const;
  inline void set_uid(::google::protobuf::int32 value);

  // optional int32 gid = 10;
  inline bool has_gid() const;
  inline void clear_gid();
  static const int kGidFieldNumber = 10;
  inline ::google::protobuf::int32 gid() const;
  inline void set_gid(::google::protobuf::int32 value);

  // optional int32 size = 11;
  inline bool has_size() const;
  inline void clear_size();
  static const int kSizeFieldNumber = 11;
  inline ::google::protobuf::int32 size() const;
  inline void set_size(::google::protobuf::int32 value);

  // optional int32 flag = 12;
  inline bool has_flag() const;
  inline void clear_flag();
  static const int kFlagFieldNumber = 12;
  inline ::google::protobuf::int32 flag() const;
  inline void set_flag(::google::protobuf::int32 value);

  // optional int32 offset = 13;
  inline bool has_offset() const;
  inline void clear_offset();
  static const int kOffsetFieldNumber = 13;
  inline ::google::protobuf::int32 offset() const;
  inline void set_offset(::google::protobuf::int32 value);

  // optional int32 statvfs = 14;
  inline bool has_statvfs() const;
  inline void clear_statvfs();
  static const int kStatvfsFieldNumber = 14;
  inline ::google::protobuf::int32 statvfs() const;
  inline void set_statvfs(::google::protobuf::int32 value);

  // repeated bytes d_name = 15;
  inline int d_name_size() const;
  inline void clear_d_name();
  static const int kDNameFieldNumber = 15;
  inline const ::std::string& d_name(int index) const;
  inline ::std::string* mutable_d_name(int index);
  inline void set_d_name(int index, const ::std::string& value);
  inline void set_d_name(int index, const char* value);
  inline void set_d_name(int index, const void* value, size_t size);
  inline ::std::string* add_d_name();
  inline void add_d_name(const ::std::string& value);
  inline void add_d_name(const char* value);
  inline void add_d_name(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& d_name() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_d_name();

  // optional int32 msg_size = 16;
  inline bool has_msg_size() const;
  inline void clear_msg_size();
  static const int kMsgSizeFieldNumber = 16;
  inline ::google::protobuf::int32 msg_size() const;
  inline void set_msg_size(::google::protobuf::int32 value);

  // optional bytes buf = 17;
  inline bool has_buf() const;
  inline void clear_buf();
  static const int kBufFieldNumber = 17;
  inline const ::std::string& buf() const;
  inline void set_buf(const ::std::string& value);
  inline void set_buf(const char* value);
  inline void set_buf(const void* value, size_t size);
  inline ::std::string* mutable_buf();
  inline ::std::string* release_buf();
  inline void set_allocated_buf(::std::string* buf);

  // optional int64 fh = 18;
  inline bool has_fh() const;
  inline void clear_fh();
  static const int kFhFieldNumber = 18;
  inline ::google::protobuf::int64 fh() const;
  inline void set_fh(::google::protobuf::int64 value);

  // optional int32 res = 19;
  inline bool has_res() const;
  inline void clear_res();
  static const int kResFieldNumber = 19;
  inline ::google::protobuf::int32 res() const;
  inline void set_res(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:File)
 private:
  inline void set_has_oper();
  inline void clear_has_oper();
  inline void set_has_path();
  inline void clear_has_path();
  inline void set_has_stbuf();
  inline void clear_has_stbuf();
  inline void set_has_mask();
  inline void clear_has_mask();
  inline void set_has_mode();
  inline void clear_has_mode();
  inline void set_has_rdev();
  inline void clear_has_rdev();
  inline void set_has_from();
  inline void clear_has_from();
  inline void set_has_to();
  inline void clear_has_to();
  inline void set_has_uid();
  inline void clear_has_uid();
  inline void set_has_gid();
  inline void clear_has_gid();
  inline void set_has_size();
  inline void clear_has_size();
  inline void set_has_flag();
  inline void clear_has_flag();
  inline void set_has_offset();
  inline void clear_has_offset();
  inline void set_has_statvfs();
  inline void clear_has_statvfs();
  inline void set_has_msg_size();
  inline void clear_has_msg_size();
  inline void set_has_buf();
  inline void clear_has_buf();
  inline void set_has_fh();
  inline void clear_has_fh();
  inline void set_has_res();
  inline void clear_has_res();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* path_;
  ::google::protobuf::int32 oper_;
  ::google::protobuf::int32 mask_;
  ::std::string* stbuf_;
  ::google::protobuf::int64 rdev_;
  ::std::string* from_;
  ::google::protobuf::int32 mode_;
  ::google::protobuf::int32 uid_;
  ::std::string* to_;
  ::google::protobuf::int32 gid_;
  ::google::protobuf::int32 size_;
  ::google::protobuf::int32 flag_;
  ::google::protobuf::int32 offset_;
  ::google::protobuf::RepeatedPtrField< ::std::string> d_name_;
  ::google::protobuf::int32 statvfs_;
  ::google::protobuf::int32 msg_size_;
  ::std::string* buf_;
  ::google::protobuf::int64 fh_;
  ::google::protobuf::int32 res_;
  friend void  protobuf_AddDesc_file_2eproto();
  friend void protobuf_AssignDesc_file_2eproto();
  friend void protobuf_ShutdownFile_file_2eproto();

  void InitAsDefaultInstance();
  static File* default_instance_;
};
// ===================================================================


// ===================================================================

// File

// optional int32 oper = 1;
inline bool File::has_oper() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void File::set_has_oper() {
  _has_bits_[0] |= 0x00000001u;
}
inline void File::clear_has_oper() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void File::clear_oper() {
  oper_ = 0;
  clear_has_oper();
}
inline ::google::protobuf::int32 File::oper() const {
  // @@protoc_insertion_point(field_get:File.oper)
  return oper_;
}
inline void File::set_oper(::google::protobuf::int32 value) {
  set_has_oper();
  oper_ = value;
  // @@protoc_insertion_point(field_set:File.oper)
}

// optional string path = 2;
inline bool File::has_path() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void File::set_has_path() {
  _has_bits_[0] |= 0x00000002u;
}
inline void File::clear_has_path() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void File::clear_path() {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_->clear();
  }
  clear_has_path();
}
inline const ::std::string& File::path() const {
  // @@protoc_insertion_point(field_get:File.path)
  return *path_;
}
inline void File::set_path(const ::std::string& value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set:File.path)
}
inline void File::set_path(const char* value) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(value);
  // @@protoc_insertion_point(field_set_char:File.path)
}
inline void File::set_path(const char* value, size_t size) {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  path_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.path)
}
inline ::std::string* File::mutable_path() {
  set_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    path_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:File.path)
  return path_;
}
inline ::std::string* File::release_path() {
  clear_has_path();
  if (path_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = path_;
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void File::set_allocated_path(::std::string* path) {
  if (path_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete path_;
  }
  if (path) {
    set_has_path();
    path_ = path;
  } else {
    clear_has_path();
    path_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:File.path)
}

// optional string stbuf = 3;
inline bool File::has_stbuf() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void File::set_has_stbuf() {
  _has_bits_[0] |= 0x00000004u;
}
inline void File::clear_has_stbuf() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void File::clear_stbuf() {
  if (stbuf_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    stbuf_->clear();
  }
  clear_has_stbuf();
}
inline const ::std::string& File::stbuf() const {
  // @@protoc_insertion_point(field_get:File.stbuf)
  return *stbuf_;
}
inline void File::set_stbuf(const ::std::string& value) {
  set_has_stbuf();
  if (stbuf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    stbuf_ = new ::std::string;
  }
  stbuf_->assign(value);
  // @@protoc_insertion_point(field_set:File.stbuf)
}
inline void File::set_stbuf(const char* value) {
  set_has_stbuf();
  if (stbuf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    stbuf_ = new ::std::string;
  }
  stbuf_->assign(value);
  // @@protoc_insertion_point(field_set_char:File.stbuf)
}
inline void File::set_stbuf(const char* value, size_t size) {
  set_has_stbuf();
  if (stbuf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    stbuf_ = new ::std::string;
  }
  stbuf_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.stbuf)
}
inline ::std::string* File::mutable_stbuf() {
  set_has_stbuf();
  if (stbuf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    stbuf_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:File.stbuf)
  return stbuf_;
}
inline ::std::string* File::release_stbuf() {
  clear_has_stbuf();
  if (stbuf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = stbuf_;
    stbuf_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void File::set_allocated_stbuf(::std::string* stbuf) {
  if (stbuf_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete stbuf_;
  }
  if (stbuf) {
    set_has_stbuf();
    stbuf_ = stbuf;
  } else {
    clear_has_stbuf();
    stbuf_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:File.stbuf)
}

// optional int32 mask = 4;
inline bool File::has_mask() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void File::set_has_mask() {
  _has_bits_[0] |= 0x00000008u;
}
inline void File::clear_has_mask() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void File::clear_mask() {
  mask_ = 0;
  clear_has_mask();
}
inline ::google::protobuf::int32 File::mask() const {
  // @@protoc_insertion_point(field_get:File.mask)
  return mask_;
}
inline void File::set_mask(::google::protobuf::int32 value) {
  set_has_mask();
  mask_ = value;
  // @@protoc_insertion_point(field_set:File.mask)
}

// optional int32 mode = 5;
inline bool File::has_mode() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void File::set_has_mode() {
  _has_bits_[0] |= 0x00000010u;
}
inline void File::clear_has_mode() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void File::clear_mode() {
  mode_ = 0;
  clear_has_mode();
}
inline ::google::protobuf::int32 File::mode() const {
  // @@protoc_insertion_point(field_get:File.mode)
  return mode_;
}
inline void File::set_mode(::google::protobuf::int32 value) {
  set_has_mode();
  mode_ = value;
  // @@protoc_insertion_point(field_set:File.mode)
}

// optional int64 rdev = 6;
inline bool File::has_rdev() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void File::set_has_rdev() {
  _has_bits_[0] |= 0x00000020u;
}
inline void File::clear_has_rdev() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void File::clear_rdev() {
  rdev_ = GOOGLE_LONGLONG(0);
  clear_has_rdev();
}
inline ::google::protobuf::int64 File::rdev() const {
  // @@protoc_insertion_point(field_get:File.rdev)
  return rdev_;
}
inline void File::set_rdev(::google::protobuf::int64 value) {
  set_has_rdev();
  rdev_ = value;
  // @@protoc_insertion_point(field_set:File.rdev)
}

// optional string from = 7;
inline bool File::has_from() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void File::set_has_from() {
  _has_bits_[0] |= 0x00000040u;
}
inline void File::clear_has_from() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void File::clear_from() {
  if (from_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    from_->clear();
  }
  clear_has_from();
}
inline const ::std::string& File::from() const {
  // @@protoc_insertion_point(field_get:File.from)
  return *from_;
}
inline void File::set_from(const ::std::string& value) {
  set_has_from();
  if (from_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    from_ = new ::std::string;
  }
  from_->assign(value);
  // @@protoc_insertion_point(field_set:File.from)
}
inline void File::set_from(const char* value) {
  set_has_from();
  if (from_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    from_ = new ::std::string;
  }
  from_->assign(value);
  // @@protoc_insertion_point(field_set_char:File.from)
}
inline void File::set_from(const char* value, size_t size) {
  set_has_from();
  if (from_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    from_ = new ::std::string;
  }
  from_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.from)
}
inline ::std::string* File::mutable_from() {
  set_has_from();
  if (from_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    from_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:File.from)
  return from_;
}
inline ::std::string* File::release_from() {
  clear_has_from();
  if (from_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = from_;
    from_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void File::set_allocated_from(::std::string* from) {
  if (from_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete from_;
  }
  if (from) {
    set_has_from();
    from_ = from;
  } else {
    clear_has_from();
    from_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:File.from)
}

// optional string to = 8;
inline bool File::has_to() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void File::set_has_to() {
  _has_bits_[0] |= 0x00000080u;
}
inline void File::clear_has_to() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void File::clear_to() {
  if (to_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    to_->clear();
  }
  clear_has_to();
}
inline const ::std::string& File::to() const {
  // @@protoc_insertion_point(field_get:File.to)
  return *to_;
}
inline void File::set_to(const ::std::string& value) {
  set_has_to();
  if (to_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    to_ = new ::std::string;
  }
  to_->assign(value);
  // @@protoc_insertion_point(field_set:File.to)
}
inline void File::set_to(const char* value) {
  set_has_to();
  if (to_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    to_ = new ::std::string;
  }
  to_->assign(value);
  // @@protoc_insertion_point(field_set_char:File.to)
}
inline void File::set_to(const char* value, size_t size) {
  set_has_to();
  if (to_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    to_ = new ::std::string;
  }
  to_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.to)
}
inline ::std::string* File::mutable_to() {
  set_has_to();
  if (to_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    to_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:File.to)
  return to_;
}
inline ::std::string* File::release_to() {
  clear_has_to();
  if (to_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = to_;
    to_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void File::set_allocated_to(::std::string* to) {
  if (to_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete to_;
  }
  if (to) {
    set_has_to();
    to_ = to;
  } else {
    clear_has_to();
    to_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:File.to)
}

// optional int32 uid = 9;
inline bool File::has_uid() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void File::set_has_uid() {
  _has_bits_[0] |= 0x00000100u;
}
inline void File::clear_has_uid() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void File::clear_uid() {
  uid_ = 0;
  clear_has_uid();
}
inline ::google::protobuf::int32 File::uid() const {
  // @@protoc_insertion_point(field_get:File.uid)
  return uid_;
}
inline void File::set_uid(::google::protobuf::int32 value) {
  set_has_uid();
  uid_ = value;
  // @@protoc_insertion_point(field_set:File.uid)
}

// optional int32 gid = 10;
inline bool File::has_gid() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void File::set_has_gid() {
  _has_bits_[0] |= 0x00000200u;
}
inline void File::clear_has_gid() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void File::clear_gid() {
  gid_ = 0;
  clear_has_gid();
}
inline ::google::protobuf::int32 File::gid() const {
  // @@protoc_insertion_point(field_get:File.gid)
  return gid_;
}
inline void File::set_gid(::google::protobuf::int32 value) {
  set_has_gid();
  gid_ = value;
  // @@protoc_insertion_point(field_set:File.gid)
}

// optional int32 size = 11;
inline bool File::has_size() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void File::set_has_size() {
  _has_bits_[0] |= 0x00000400u;
}
inline void File::clear_has_size() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void File::clear_size() {
  size_ = 0;
  clear_has_size();
}
inline ::google::protobuf::int32 File::size() const {
  // @@protoc_insertion_point(field_get:File.size)
  return size_;
}
inline void File::set_size(::google::protobuf::int32 value) {
  set_has_size();
  size_ = value;
  // @@protoc_insertion_point(field_set:File.size)
}

// optional int32 flag = 12;
inline bool File::has_flag() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void File::set_has_flag() {
  _has_bits_[0] |= 0x00000800u;
}
inline void File::clear_has_flag() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void File::clear_flag() {
  flag_ = 0;
  clear_has_flag();
}
inline ::google::protobuf::int32 File::flag() const {
  // @@protoc_insertion_point(field_get:File.flag)
  return flag_;
}
inline void File::set_flag(::google::protobuf::int32 value) {
  set_has_flag();
  flag_ = value;
  // @@protoc_insertion_point(field_set:File.flag)
}

// optional int32 offset = 13;
inline bool File::has_offset() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void File::set_has_offset() {
  _has_bits_[0] |= 0x00001000u;
}
inline void File::clear_has_offset() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void File::clear_offset() {
  offset_ = 0;
  clear_has_offset();
}
inline ::google::protobuf::int32 File::offset() const {
  // @@protoc_insertion_point(field_get:File.offset)
  return offset_;
}
inline void File::set_offset(::google::protobuf::int32 value) {
  set_has_offset();
  offset_ = value;
  // @@protoc_insertion_point(field_set:File.offset)
}

// optional int32 statvfs = 14;
inline bool File::has_statvfs() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void File::set_has_statvfs() {
  _has_bits_[0] |= 0x00002000u;
}
inline void File::clear_has_statvfs() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void File::clear_statvfs() {
  statvfs_ = 0;
  clear_has_statvfs();
}
inline ::google::protobuf::int32 File::statvfs() const {
  // @@protoc_insertion_point(field_get:File.statvfs)
  return statvfs_;
}
inline void File::set_statvfs(::google::protobuf::int32 value) {
  set_has_statvfs();
  statvfs_ = value;
  // @@protoc_insertion_point(field_set:File.statvfs)
}

// repeated bytes d_name = 15;
inline int File::d_name_size() const {
  return d_name_.size();
}
inline void File::clear_d_name() {
  d_name_.Clear();
}
inline const ::std::string& File::d_name(int index) const {
  // @@protoc_insertion_point(field_get:File.d_name)
  return d_name_.Get(index);
}
inline ::std::string* File::mutable_d_name(int index) {
  // @@protoc_insertion_point(field_mutable:File.d_name)
  return d_name_.Mutable(index);
}
inline void File::set_d_name(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:File.d_name)
  d_name_.Mutable(index)->assign(value);
}
inline void File::set_d_name(int index, const char* value) {
  d_name_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:File.d_name)
}
inline void File::set_d_name(int index, const void* value, size_t size) {
  d_name_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.d_name)
}
inline ::std::string* File::add_d_name() {
  return d_name_.Add();
}
inline void File::add_d_name(const ::std::string& value) {
  d_name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:File.d_name)
}
inline void File::add_d_name(const char* value) {
  d_name_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:File.d_name)
}
inline void File::add_d_name(const void* value, size_t size) {
  d_name_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:File.d_name)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
File::d_name() const {
  // @@protoc_insertion_point(field_list:File.d_name)
  return d_name_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
File::mutable_d_name() {
  // @@protoc_insertion_point(field_mutable_list:File.d_name)
  return &d_name_;
}

// optional int32 msg_size = 16;
inline bool File::has_msg_size() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void File::set_has_msg_size() {
  _has_bits_[0] |= 0x00008000u;
}
inline void File::clear_has_msg_size() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void File::clear_msg_size() {
  msg_size_ = 0;
  clear_has_msg_size();
}
inline ::google::protobuf::int32 File::msg_size() const {
  // @@protoc_insertion_point(field_get:File.msg_size)
  return msg_size_;
}
inline void File::set_msg_size(::google::protobuf::int32 value) {
  set_has_msg_size();
  msg_size_ = value;
  // @@protoc_insertion_point(field_set:File.msg_size)
}

// optional bytes buf = 17;
inline bool File::has_buf() const {
  return (_has_bits_[0] & 0x00010000u) != 0;
}
inline void File::set_has_buf() {
  _has_bits_[0] |= 0x00010000u;
}
inline void File::clear_has_buf() {
  _has_bits_[0] &= ~0x00010000u;
}
inline void File::clear_buf() {
  if (buf_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buf_->clear();
  }
  clear_has_buf();
}
inline const ::std::string& File::buf() const {
  // @@protoc_insertion_point(field_get:File.buf)
  return *buf_;
}
inline void File::set_buf(const ::std::string& value) {
  set_has_buf();
  if (buf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buf_ = new ::std::string;
  }
  buf_->assign(value);
  // @@protoc_insertion_point(field_set:File.buf)
}
inline void File::set_buf(const char* value) {
  set_has_buf();
  if (buf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buf_ = new ::std::string;
  }
  buf_->assign(value);
  // @@protoc_insertion_point(field_set_char:File.buf)
}
inline void File::set_buf(const void* value, size_t size) {
  set_has_buf();
  if (buf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buf_ = new ::std::string;
  }
  buf_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:File.buf)
}
inline ::std::string* File::mutable_buf() {
  set_has_buf();
  if (buf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    buf_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:File.buf)
  return buf_;
}
inline ::std::string* File::release_buf() {
  clear_has_buf();
  if (buf_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = buf_;
    buf_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void File::set_allocated_buf(::std::string* buf) {
  if (buf_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete buf_;
  }
  if (buf) {
    set_has_buf();
    buf_ = buf;
  } else {
    clear_has_buf();
    buf_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:File.buf)
}

// optional int64 fh = 18;
inline bool File::has_fh() const {
  return (_has_bits_[0] & 0x00020000u) != 0;
}
inline void File::set_has_fh() {
  _has_bits_[0] |= 0x00020000u;
}
inline void File::clear_has_fh() {
  _has_bits_[0] &= ~0x00020000u;
}
inline void File::clear_fh() {
  fh_ = GOOGLE_LONGLONG(0);
  clear_has_fh();
}
inline ::google::protobuf::int64 File::fh() const {
  // @@protoc_insertion_point(field_get:File.fh)
  return fh_;
}
inline void File::set_fh(::google::protobuf::int64 value) {
  set_has_fh();
  fh_ = value;
  // @@protoc_insertion_point(field_set:File.fh)
}

// optional int32 res = 19;
inline bool File::has_res() const {
  return (_has_bits_[0] & 0x00040000u) != 0;
}
inline void File::set_has_res() {
  _has_bits_[0] |= 0x00040000u;
}
inline void File::clear_has_res() {
  _has_bits_[0] &= ~0x00040000u;
}
inline void File::clear_res() {
  res_ = 0;
  clear_has_res();
}
inline ::google::protobuf::int32 File::res() const {
  // @@protoc_insertion_point(field_get:File.res)
  return res_;
}
inline void File::set_res(::google::protobuf::int32 value) {
  set_has_res();
  res_ = value;
  // @@protoc_insertion_point(field_set:File.res)
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_file_2eproto__INCLUDED
