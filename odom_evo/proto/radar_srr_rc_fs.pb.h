// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: radar_srr_rc_fs.proto

#ifndef PROTOBUF_INCLUDED_radar_5fsrr_5frc_5ffs_2eproto
#define PROTOBUF_INCLUDED_radar_5fsrr_5frc_5ffs_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_radar_5fsrr_5frc_5ffs_2eproto 

namespace protobuf_radar_5fsrr_5frc_5ffs_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_radar_5fsrr_5frc_5ffs_2eproto
namespace radar_srr_rc_fs {
namespace proto {
class SrrFreeSpace;
class SrrFreeSpaceDefaultTypeInternal;
extern SrrFreeSpaceDefaultTypeInternal _SrrFreeSpace_default_instance_;
class SrrHeader;
class SrrHeaderDefaultTypeInternal;
extern SrrHeaderDefaultTypeInternal _SrrHeader_default_instance_;
class srr_rc_frame_fs;
class srr_rc_frame_fsDefaultTypeInternal;
extern srr_rc_frame_fsDefaultTypeInternal _srr_rc_frame_fs_default_instance_;
}  // namespace proto
}  // namespace radar_srr_rc_fs
namespace google {
namespace protobuf {
template<> ::radar_srr_rc_fs::proto::SrrFreeSpace* Arena::CreateMaybeMessage<::radar_srr_rc_fs::proto::SrrFreeSpace>(Arena*);
template<> ::radar_srr_rc_fs::proto::SrrHeader* Arena::CreateMaybeMessage<::radar_srr_rc_fs::proto::SrrHeader>(Arena*);
template<> ::radar_srr_rc_fs::proto::srr_rc_frame_fs* Arena::CreateMaybeMessage<::radar_srr_rc_fs::proto::srr_rc_frame_fs>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace radar_srr_rc_fs {
namespace proto {

// ===================================================================

class SrrHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_rc_fs.proto.SrrHeader) */ {
 public:
  SrrHeader();
  virtual ~SrrHeader();

  SrrHeader(const SrrHeader& from);

  inline SrrHeader& operator=(const SrrHeader& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SrrHeader(SrrHeader&& from) noexcept
    : SrrHeader() {
    *this = ::std::move(from);
  }

  inline SrrHeader& operator=(SrrHeader&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SrrHeader& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SrrHeader* internal_default_instance() {
    return reinterpret_cast<const SrrHeader*>(
               &_SrrHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(SrrHeader* other);
  friend void swap(SrrHeader& a, SrrHeader& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SrrHeader* New() const final {
    return CreateMaybeMessage<SrrHeader>(NULL);
  }

  SrrHeader* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SrrHeader>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SrrHeader& from);
  void MergeFrom(const SrrHeader& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SrrHeader* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint64 timestamp = 1;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // uint32 rolling_counter = 2;
  void clear_rolling_counter();
  static const int kRollingCounterFieldNumber = 2;
  ::google::protobuf::uint32 rolling_counter() const;
  void set_rolling_counter(::google::protobuf::uint32 value);

  // uint32 sensor_id = 3;
  void clear_sensor_id();
  static const int kSensorIdFieldNumber = 3;
  ::google::protobuf::uint32 sensor_id() const;
  void set_sensor_id(::google::protobuf::uint32 value);

  // uint32 obj_num = 4;
  void clear_obj_num();
  static const int kObjNumFieldNumber = 4;
  ::google::protobuf::uint32 obj_num() const;
  void set_obj_num(::google::protobuf::uint32 value);

  // uint32 line_num = 5;
  void clear_line_num();
  static const int kLineNumFieldNumber = 5;
  ::google::protobuf::uint32 line_num() const;
  void set_line_num(::google::protobuf::uint32 value);

  // uint32 fs_num = 6;
  void clear_fs_num();
  static const int kFsNumFieldNumber = 6;
  ::google::protobuf::uint32 fs_num() const;
  void set_fs_num(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:radar_srr_rc_fs.proto.SrrHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  ::google::protobuf::uint32 rolling_counter_;
  ::google::protobuf::uint32 sensor_id_;
  ::google::protobuf::uint32 obj_num_;
  ::google::protobuf::uint32 line_num_;
  ::google::protobuf::uint32 fs_num_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5frc_5ffs_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SrrFreeSpace : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_rc_fs.proto.SrrFreeSpace) */ {
 public:
  SrrFreeSpace();
  virtual ~SrrFreeSpace();

  SrrFreeSpace(const SrrFreeSpace& from);

  inline SrrFreeSpace& operator=(const SrrFreeSpace& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SrrFreeSpace(SrrFreeSpace&& from) noexcept
    : SrrFreeSpace() {
    *this = ::std::move(from);
  }

  inline SrrFreeSpace& operator=(SrrFreeSpace&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SrrFreeSpace& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SrrFreeSpace* internal_default_instance() {
    return reinterpret_cast<const SrrFreeSpace*>(
               &_SrrFreeSpace_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SrrFreeSpace* other);
  friend void swap(SrrFreeSpace& a, SrrFreeSpace& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SrrFreeSpace* New() const final {
    return CreateMaybeMessage<SrrFreeSpace>(NULL);
  }

  SrrFreeSpace* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SrrFreeSpace>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SrrFreeSpace& from);
  void MergeFrom(const SrrFreeSpace& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SrrFreeSpace* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 freespace_id = 1;
  void clear_freespace_id();
  static const int kFreespaceIdFieldNumber = 1;
  ::google::protobuf::uint32 freespace_id() const;
  void set_freespace_id(::google::protobuf::uint32 value);

  // uint32 motion_status = 2;
  void clear_motion_status();
  static const int kMotionStatusFieldNumber = 2;
  ::google::protobuf::uint32 motion_status() const;
  void set_motion_status(::google::protobuf::uint32 value);

  // double distance = 3;
  void clear_distance();
  static const int kDistanceFieldNumber = 3;
  double distance() const;
  void set_distance(double value);

  // double confidence = 4;
  void clear_confidence();
  static const int kConfidenceFieldNumber = 4;
  double confidence() const;
  void set_confidence(double value);

  // @@protoc_insertion_point(class_scope:radar_srr_rc_fs.proto.SrrFreeSpace)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 freespace_id_;
  ::google::protobuf::uint32 motion_status_;
  double distance_;
  double confidence_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5frc_5ffs_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class srr_rc_frame_fs : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_rc_fs.proto.srr_rc_frame_fs) */ {
 public:
  srr_rc_frame_fs();
  virtual ~srr_rc_frame_fs();

  srr_rc_frame_fs(const srr_rc_frame_fs& from);

  inline srr_rc_frame_fs& operator=(const srr_rc_frame_fs& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  srr_rc_frame_fs(srr_rc_frame_fs&& from) noexcept
    : srr_rc_frame_fs() {
    *this = ::std::move(from);
  }

  inline srr_rc_frame_fs& operator=(srr_rc_frame_fs&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const srr_rc_frame_fs& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const srr_rc_frame_fs* internal_default_instance() {
    return reinterpret_cast<const srr_rc_frame_fs*>(
               &_srr_rc_frame_fs_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(srr_rc_frame_fs* other);
  friend void swap(srr_rc_frame_fs& a, srr_rc_frame_fs& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline srr_rc_frame_fs* New() const final {
    return CreateMaybeMessage<srr_rc_frame_fs>(NULL);
  }

  srr_rc_frame_fs* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<srr_rc_frame_fs>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const srr_rc_frame_fs& from);
  void MergeFrom(const srr_rc_frame_fs& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(srr_rc_frame_fs* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .radar_srr_rc_fs.proto.SrrFreeSpace fs = 3;
  int fs_size() const;
  void clear_fs();
  static const int kFsFieldNumber = 3;
  ::radar_srr_rc_fs::proto::SrrFreeSpace* mutable_fs(int index);
  ::google::protobuf::RepeatedPtrField< ::radar_srr_rc_fs::proto::SrrFreeSpace >*
      mutable_fs();
  const ::radar_srr_rc_fs::proto::SrrFreeSpace& fs(int index) const;
  ::radar_srr_rc_fs::proto::SrrFreeSpace* add_fs();
  const ::google::protobuf::RepeatedPtrField< ::radar_srr_rc_fs::proto::SrrFreeSpace >&
      fs() const;

  // .radar_srr_rc_fs.proto.SrrHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::radar_srr_rc_fs::proto::SrrHeader& _internal_header() const;
  public:
  const ::radar_srr_rc_fs::proto::SrrHeader& header() const;
  ::radar_srr_rc_fs::proto::SrrHeader* release_header();
  ::radar_srr_rc_fs::proto::SrrHeader* mutable_header();
  void set_allocated_header(::radar_srr_rc_fs::proto::SrrHeader* header);

  // uint64 timestamp = 2;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 2;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:radar_srr_rc_fs.proto.srr_rc_frame_fs)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::radar_srr_rc_fs::proto::SrrFreeSpace > fs_;
  ::radar_srr_rc_fs::proto::SrrHeader* header_;
  ::google::protobuf::uint64 timestamp_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5frc_5ffs_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SrrHeader

// uint64 timestamp = 1;
inline void SrrHeader::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 SrrHeader::timestamp() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.timestamp)
  return timestamp_;
}
inline void SrrHeader::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.timestamp)
}

// uint32 rolling_counter = 2;
inline void SrrHeader::clear_rolling_counter() {
  rolling_counter_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::rolling_counter() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.rolling_counter)
  return rolling_counter_;
}
inline void SrrHeader::set_rolling_counter(::google::protobuf::uint32 value) {
  
  rolling_counter_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.rolling_counter)
}

// uint32 sensor_id = 3;
inline void SrrHeader::clear_sensor_id() {
  sensor_id_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::sensor_id() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.sensor_id)
  return sensor_id_;
}
inline void SrrHeader::set_sensor_id(::google::protobuf::uint32 value) {
  
  sensor_id_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.sensor_id)
}

// uint32 obj_num = 4;
inline void SrrHeader::clear_obj_num() {
  obj_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::obj_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.obj_num)
  return obj_num_;
}
inline void SrrHeader::set_obj_num(::google::protobuf::uint32 value) {
  
  obj_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.obj_num)
}

// uint32 line_num = 5;
inline void SrrHeader::clear_line_num() {
  line_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::line_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.line_num)
  return line_num_;
}
inline void SrrHeader::set_line_num(::google::protobuf::uint32 value) {
  
  line_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.line_num)
}

// uint32 fs_num = 6;
inline void SrrHeader::clear_fs_num() {
  fs_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::fs_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrHeader.fs_num)
  return fs_num_;
}
inline void SrrHeader::set_fs_num(::google::protobuf::uint32 value) {
  
  fs_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrHeader.fs_num)
}

// -------------------------------------------------------------------

// SrrFreeSpace

// uint32 freespace_id = 1;
inline void SrrFreeSpace::clear_freespace_id() {
  freespace_id_ = 0u;
}
inline ::google::protobuf::uint32 SrrFreeSpace::freespace_id() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrFreeSpace.freespace_id)
  return freespace_id_;
}
inline void SrrFreeSpace::set_freespace_id(::google::protobuf::uint32 value) {
  
  freespace_id_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrFreeSpace.freespace_id)
}

// uint32 motion_status = 2;
inline void SrrFreeSpace::clear_motion_status() {
  motion_status_ = 0u;
}
inline ::google::protobuf::uint32 SrrFreeSpace::motion_status() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrFreeSpace.motion_status)
  return motion_status_;
}
inline void SrrFreeSpace::set_motion_status(::google::protobuf::uint32 value) {
  
  motion_status_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrFreeSpace.motion_status)
}

// double distance = 3;
inline void SrrFreeSpace::clear_distance() {
  distance_ = 0;
}
inline double SrrFreeSpace::distance() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrFreeSpace.distance)
  return distance_;
}
inline void SrrFreeSpace::set_distance(double value) {
  
  distance_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrFreeSpace.distance)
}

// double confidence = 4;
inline void SrrFreeSpace::clear_confidence() {
  confidence_ = 0;
}
inline double SrrFreeSpace::confidence() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.SrrFreeSpace.confidence)
  return confidence_;
}
inline void SrrFreeSpace::set_confidence(double value) {
  
  confidence_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.SrrFreeSpace.confidence)
}

// -------------------------------------------------------------------

// srr_rc_frame_fs

// .radar_srr_rc_fs.proto.SrrHeader header = 1;
inline bool srr_rc_frame_fs::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void srr_rc_frame_fs::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
inline const ::radar_srr_rc_fs::proto::SrrHeader& srr_rc_frame_fs::_internal_header() const {
  return *header_;
}
inline const ::radar_srr_rc_fs::proto::SrrHeader& srr_rc_frame_fs::header() const {
  const ::radar_srr_rc_fs::proto::SrrHeader* p = header_;
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.srr_rc_frame_fs.header)
  return p != NULL ? *p : *reinterpret_cast<const ::radar_srr_rc_fs::proto::SrrHeader*>(
      &::radar_srr_rc_fs::proto::_SrrHeader_default_instance_);
}
inline ::radar_srr_rc_fs::proto::SrrHeader* srr_rc_frame_fs::release_header() {
  // @@protoc_insertion_point(field_release:radar_srr_rc_fs.proto.srr_rc_frame_fs.header)
  
  ::radar_srr_rc_fs::proto::SrrHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::radar_srr_rc_fs::proto::SrrHeader* srr_rc_frame_fs::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::radar_srr_rc_fs::proto::SrrHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:radar_srr_rc_fs.proto.srr_rc_frame_fs.header)
  return header_;
}
inline void srr_rc_frame_fs::set_allocated_header(::radar_srr_rc_fs::proto::SrrHeader* header) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete header_;
  }
  if (header) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      header = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, header, submessage_arena);
    }
    
  } else {
    
  }
  header_ = header;
  // @@protoc_insertion_point(field_set_allocated:radar_srr_rc_fs.proto.srr_rc_frame_fs.header)
}

// uint64 timestamp = 2;
inline void srr_rc_frame_fs::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 srr_rc_frame_fs::timestamp() const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.srr_rc_frame_fs.timestamp)
  return timestamp_;
}
inline void srr_rc_frame_fs::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_rc_fs.proto.srr_rc_frame_fs.timestamp)
}

// repeated .radar_srr_rc_fs.proto.SrrFreeSpace fs = 3;
inline int srr_rc_frame_fs::fs_size() const {
  return fs_.size();
}
inline void srr_rc_frame_fs::clear_fs() {
  fs_.Clear();
}
inline ::radar_srr_rc_fs::proto::SrrFreeSpace* srr_rc_frame_fs::mutable_fs(int index) {
  // @@protoc_insertion_point(field_mutable:radar_srr_rc_fs.proto.srr_rc_frame_fs.fs)
  return fs_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::radar_srr_rc_fs::proto::SrrFreeSpace >*
srr_rc_frame_fs::mutable_fs() {
  // @@protoc_insertion_point(field_mutable_list:radar_srr_rc_fs.proto.srr_rc_frame_fs.fs)
  return &fs_;
}
inline const ::radar_srr_rc_fs::proto::SrrFreeSpace& srr_rc_frame_fs::fs(int index) const {
  // @@protoc_insertion_point(field_get:radar_srr_rc_fs.proto.srr_rc_frame_fs.fs)
  return fs_.Get(index);
}
inline ::radar_srr_rc_fs::proto::SrrFreeSpace* srr_rc_frame_fs::add_fs() {
  // @@protoc_insertion_point(field_add:radar_srr_rc_fs.proto.srr_rc_frame_fs.fs)
  return fs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::radar_srr_rc_fs::proto::SrrFreeSpace >&
srr_rc_frame_fs::fs() const {
  // @@protoc_insertion_point(field_list:radar_srr_rc_fs.proto.srr_rc_frame_fs.fs)
  return fs_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace radar_srr_rc_fs

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_radar_5fsrr_5frc_5ffs_2eproto
