// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: radar_srr_fc_lane.proto

#ifndef PROTOBUF_INCLUDED_radar_5fsrr_5ffc_5flane_2eproto
#define PROTOBUF_INCLUDED_radar_5fsrr_5ffc_5flane_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_radar_5fsrr_5ffc_5flane_2eproto 

namespace protobuf_radar_5fsrr_5ffc_5flane_2eproto {
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
}  // namespace protobuf_radar_5fsrr_5ffc_5flane_2eproto
namespace radar_srr_fc_lane {
namespace proto {
class SrrHeader;
class SrrHeaderDefaultTypeInternal;
extern SrrHeaderDefaultTypeInternal _SrrHeader_default_instance_;
class SrrLane;
class SrrLaneDefaultTypeInternal;
extern SrrLaneDefaultTypeInternal _SrrLane_default_instance_;
class srr_fc_frame_lane;
class srr_fc_frame_laneDefaultTypeInternal;
extern srr_fc_frame_laneDefaultTypeInternal _srr_fc_frame_lane_default_instance_;
}  // namespace proto
}  // namespace radar_srr_fc_lane
namespace google {
namespace protobuf {
template<> ::radar_srr_fc_lane::proto::SrrHeader* Arena::CreateMaybeMessage<::radar_srr_fc_lane::proto::SrrHeader>(Arena*);
template<> ::radar_srr_fc_lane::proto::SrrLane* Arena::CreateMaybeMessage<::radar_srr_fc_lane::proto::SrrLane>(Arena*);
template<> ::radar_srr_fc_lane::proto::srr_fc_frame_lane* Arena::CreateMaybeMessage<::radar_srr_fc_lane::proto::srr_fc_frame_lane>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace radar_srr_fc_lane {
namespace proto {

// ===================================================================

class SrrHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_fc_lane.proto.SrrHeader) */ {
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

  // @@protoc_insertion_point(class_scope:radar_srr_fc_lane.proto.SrrHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  ::google::protobuf::uint32 rolling_counter_;
  ::google::protobuf::uint32 sensor_id_;
  ::google::protobuf::uint32 obj_num_;
  ::google::protobuf::uint32 line_num_;
  ::google::protobuf::uint32 fs_num_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5ffc_5flane_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SrrLane : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_fc_lane.proto.SrrLane) */ {
 public:
  SrrLane();
  virtual ~SrrLane();

  SrrLane(const SrrLane& from);

  inline SrrLane& operator=(const SrrLane& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  SrrLane(SrrLane&& from) noexcept
    : SrrLane() {
    *this = ::std::move(from);
  }

  inline SrrLane& operator=(SrrLane&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const SrrLane& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SrrLane* internal_default_instance() {
    return reinterpret_cast<const SrrLane*>(
               &_SrrLane_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(SrrLane* other);
  friend void swap(SrrLane& a, SrrLane& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline SrrLane* New() const final {
    return CreateMaybeMessage<SrrLane>(NULL);
  }

  SrrLane* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<SrrLane>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const SrrLane& from);
  void MergeFrom(const SrrLane& from);
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
  void InternalSwap(SrrLane* other);
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

  // uint32 line_id = 1;
  void clear_line_id();
  static const int kLineIdFieldNumber = 1;
  ::google::protobuf::uint32 line_id() const;
  void set_line_id(::google::protobuf::uint32 value);

  // uint32 index = 2;
  void clear_index();
  static const int kIndexFieldNumber = 2;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // double C0 = 3;
  void clear_c0();
  static const int kC0FieldNumber = 3;
  double c0() const;
  void set_c0(double value);

  // double C1 = 4;
  void clear_c1();
  static const int kC1FieldNumber = 4;
  double c1() const;
  void set_c1(double value);

  // double C2 = 5;
  void clear_c2();
  static const int kC2FieldNumber = 5;
  double c2() const;
  void set_c2(double value);

  // double C3 = 6;
  void clear_c3();
  static const int kC3FieldNumber = 6;
  double c3() const;
  void set_c3(double value);

  // double start_long = 8;
  void clear_start_long();
  static const int kStartLongFieldNumber = 8;
  double start_long() const;
  void set_start_long(double value);

  // double start_lat = 9;
  void clear_start_lat();
  static const int kStartLatFieldNumber = 9;
  double start_lat() const;
  void set_start_lat(double value);

  // double end_long = 10;
  void clear_end_long();
  static const int kEndLongFieldNumber = 10;
  double end_long() const;
  void set_end_long(double value);

  // double end_lat = 11;
  void clear_end_lat();
  static const int kEndLatFieldNumber = 11;
  double end_lat() const;
  void set_end_lat(double value);

  // uint32 confidence = 7;
  void clear_confidence();
  static const int kConfidenceFieldNumber = 7;
  ::google::protobuf::uint32 confidence() const;
  void set_confidence(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:radar_srr_fc_lane.proto.SrrLane)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 line_id_;
  ::google::protobuf::uint32 index_;
  double c0_;
  double c1_;
  double c2_;
  double c3_;
  double start_long_;
  double start_lat_;
  double end_long_;
  double end_lat_;
  ::google::protobuf::uint32 confidence_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5ffc_5flane_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class srr_fc_frame_lane : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:radar_srr_fc_lane.proto.srr_fc_frame_lane) */ {
 public:
  srr_fc_frame_lane();
  virtual ~srr_fc_frame_lane();

  srr_fc_frame_lane(const srr_fc_frame_lane& from);

  inline srr_fc_frame_lane& operator=(const srr_fc_frame_lane& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  srr_fc_frame_lane(srr_fc_frame_lane&& from) noexcept
    : srr_fc_frame_lane() {
    *this = ::std::move(from);
  }

  inline srr_fc_frame_lane& operator=(srr_fc_frame_lane&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const srr_fc_frame_lane& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const srr_fc_frame_lane* internal_default_instance() {
    return reinterpret_cast<const srr_fc_frame_lane*>(
               &_srr_fc_frame_lane_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(srr_fc_frame_lane* other);
  friend void swap(srr_fc_frame_lane& a, srr_fc_frame_lane& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline srr_fc_frame_lane* New() const final {
    return CreateMaybeMessage<srr_fc_frame_lane>(NULL);
  }

  srr_fc_frame_lane* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<srr_fc_frame_lane>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const srr_fc_frame_lane& from);
  void MergeFrom(const srr_fc_frame_lane& from);
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
  void InternalSwap(srr_fc_frame_lane* other);
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

  // repeated .radar_srr_fc_lane.proto.SrrLane lanes = 3;
  int lanes_size() const;
  void clear_lanes();
  static const int kLanesFieldNumber = 3;
  ::radar_srr_fc_lane::proto::SrrLane* mutable_lanes(int index);
  ::google::protobuf::RepeatedPtrField< ::radar_srr_fc_lane::proto::SrrLane >*
      mutable_lanes();
  const ::radar_srr_fc_lane::proto::SrrLane& lanes(int index) const;
  ::radar_srr_fc_lane::proto::SrrLane* add_lanes();
  const ::google::protobuf::RepeatedPtrField< ::radar_srr_fc_lane::proto::SrrLane >&
      lanes() const;

  // .radar_srr_fc_lane.proto.SrrHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::radar_srr_fc_lane::proto::SrrHeader& _internal_header() const;
  public:
  const ::radar_srr_fc_lane::proto::SrrHeader& header() const;
  ::radar_srr_fc_lane::proto::SrrHeader* release_header();
  ::radar_srr_fc_lane::proto::SrrHeader* mutable_header();
  void set_allocated_header(::radar_srr_fc_lane::proto::SrrHeader* header);

  // uint64 timestamp = 2;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 2;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:radar_srr_fc_lane.proto.srr_fc_frame_lane)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::radar_srr_fc_lane::proto::SrrLane > lanes_;
  ::radar_srr_fc_lane::proto::SrrHeader* header_;
  ::google::protobuf::uint64 timestamp_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_radar_5fsrr_5ffc_5flane_2eproto::TableStruct;
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
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.timestamp)
  return timestamp_;
}
inline void SrrHeader::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.timestamp)
}

// uint32 rolling_counter = 2;
inline void SrrHeader::clear_rolling_counter() {
  rolling_counter_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::rolling_counter() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.rolling_counter)
  return rolling_counter_;
}
inline void SrrHeader::set_rolling_counter(::google::protobuf::uint32 value) {
  
  rolling_counter_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.rolling_counter)
}

// uint32 sensor_id = 3;
inline void SrrHeader::clear_sensor_id() {
  sensor_id_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::sensor_id() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.sensor_id)
  return sensor_id_;
}
inline void SrrHeader::set_sensor_id(::google::protobuf::uint32 value) {
  
  sensor_id_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.sensor_id)
}

// uint32 obj_num = 4;
inline void SrrHeader::clear_obj_num() {
  obj_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::obj_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.obj_num)
  return obj_num_;
}
inline void SrrHeader::set_obj_num(::google::protobuf::uint32 value) {
  
  obj_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.obj_num)
}

// uint32 line_num = 5;
inline void SrrHeader::clear_line_num() {
  line_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::line_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.line_num)
  return line_num_;
}
inline void SrrHeader::set_line_num(::google::protobuf::uint32 value) {
  
  line_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.line_num)
}

// uint32 fs_num = 6;
inline void SrrHeader::clear_fs_num() {
  fs_num_ = 0u;
}
inline ::google::protobuf::uint32 SrrHeader::fs_num() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrHeader.fs_num)
  return fs_num_;
}
inline void SrrHeader::set_fs_num(::google::protobuf::uint32 value) {
  
  fs_num_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrHeader.fs_num)
}

// -------------------------------------------------------------------

// SrrLane

// uint32 line_id = 1;
inline void SrrLane::clear_line_id() {
  line_id_ = 0u;
}
inline ::google::protobuf::uint32 SrrLane::line_id() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.line_id)
  return line_id_;
}
inline void SrrLane::set_line_id(::google::protobuf::uint32 value) {
  
  line_id_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.line_id)
}

// uint32 index = 2;
inline void SrrLane::clear_index() {
  index_ = 0u;
}
inline ::google::protobuf::uint32 SrrLane::index() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.index)
  return index_;
}
inline void SrrLane::set_index(::google::protobuf::uint32 value) {
  
  index_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.index)
}

// double C0 = 3;
inline void SrrLane::clear_c0() {
  c0_ = 0;
}
inline double SrrLane::c0() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.C0)
  return c0_;
}
inline void SrrLane::set_c0(double value) {
  
  c0_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.C0)
}

// double C1 = 4;
inline void SrrLane::clear_c1() {
  c1_ = 0;
}
inline double SrrLane::c1() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.C1)
  return c1_;
}
inline void SrrLane::set_c1(double value) {
  
  c1_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.C1)
}

// double C2 = 5;
inline void SrrLane::clear_c2() {
  c2_ = 0;
}
inline double SrrLane::c2() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.C2)
  return c2_;
}
inline void SrrLane::set_c2(double value) {
  
  c2_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.C2)
}

// double C3 = 6;
inline void SrrLane::clear_c3() {
  c3_ = 0;
}
inline double SrrLane::c3() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.C3)
  return c3_;
}
inline void SrrLane::set_c3(double value) {
  
  c3_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.C3)
}

// uint32 confidence = 7;
inline void SrrLane::clear_confidence() {
  confidence_ = 0u;
}
inline ::google::protobuf::uint32 SrrLane::confidence() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.confidence)
  return confidence_;
}
inline void SrrLane::set_confidence(::google::protobuf::uint32 value) {
  
  confidence_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.confidence)
}

// double start_long = 8;
inline void SrrLane::clear_start_long() {
  start_long_ = 0;
}
inline double SrrLane::start_long() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.start_long)
  return start_long_;
}
inline void SrrLane::set_start_long(double value) {
  
  start_long_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.start_long)
}

// double start_lat = 9;
inline void SrrLane::clear_start_lat() {
  start_lat_ = 0;
}
inline double SrrLane::start_lat() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.start_lat)
  return start_lat_;
}
inline void SrrLane::set_start_lat(double value) {
  
  start_lat_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.start_lat)
}

// double end_long = 10;
inline void SrrLane::clear_end_long() {
  end_long_ = 0;
}
inline double SrrLane::end_long() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.end_long)
  return end_long_;
}
inline void SrrLane::set_end_long(double value) {
  
  end_long_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.end_long)
}

// double end_lat = 11;
inline void SrrLane::clear_end_lat() {
  end_lat_ = 0;
}
inline double SrrLane::end_lat() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.SrrLane.end_lat)
  return end_lat_;
}
inline void SrrLane::set_end_lat(double value) {
  
  end_lat_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.SrrLane.end_lat)
}

// -------------------------------------------------------------------

// srr_fc_frame_lane

// .radar_srr_fc_lane.proto.SrrHeader header = 1;
inline bool srr_fc_frame_lane::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void srr_fc_frame_lane::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
inline const ::radar_srr_fc_lane::proto::SrrHeader& srr_fc_frame_lane::_internal_header() const {
  return *header_;
}
inline const ::radar_srr_fc_lane::proto::SrrHeader& srr_fc_frame_lane::header() const {
  const ::radar_srr_fc_lane::proto::SrrHeader* p = header_;
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.srr_fc_frame_lane.header)
  return p != NULL ? *p : *reinterpret_cast<const ::radar_srr_fc_lane::proto::SrrHeader*>(
      &::radar_srr_fc_lane::proto::_SrrHeader_default_instance_);
}
inline ::radar_srr_fc_lane::proto::SrrHeader* srr_fc_frame_lane::release_header() {
  // @@protoc_insertion_point(field_release:radar_srr_fc_lane.proto.srr_fc_frame_lane.header)
  
  ::radar_srr_fc_lane::proto::SrrHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::radar_srr_fc_lane::proto::SrrHeader* srr_fc_frame_lane::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::radar_srr_fc_lane::proto::SrrHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:radar_srr_fc_lane.proto.srr_fc_frame_lane.header)
  return header_;
}
inline void srr_fc_frame_lane::set_allocated_header(::radar_srr_fc_lane::proto::SrrHeader* header) {
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
  // @@protoc_insertion_point(field_set_allocated:radar_srr_fc_lane.proto.srr_fc_frame_lane.header)
}

// uint64 timestamp = 2;
inline void srr_fc_frame_lane::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 srr_fc_frame_lane::timestamp() const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.srr_fc_frame_lane.timestamp)
  return timestamp_;
}
inline void srr_fc_frame_lane::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:radar_srr_fc_lane.proto.srr_fc_frame_lane.timestamp)
}

// repeated .radar_srr_fc_lane.proto.SrrLane lanes = 3;
inline int srr_fc_frame_lane::lanes_size() const {
  return lanes_.size();
}
inline void srr_fc_frame_lane::clear_lanes() {
  lanes_.Clear();
}
inline ::radar_srr_fc_lane::proto::SrrLane* srr_fc_frame_lane::mutable_lanes(int index) {
  // @@protoc_insertion_point(field_mutable:radar_srr_fc_lane.proto.srr_fc_frame_lane.lanes)
  return lanes_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::radar_srr_fc_lane::proto::SrrLane >*
srr_fc_frame_lane::mutable_lanes() {
  // @@protoc_insertion_point(field_mutable_list:radar_srr_fc_lane.proto.srr_fc_frame_lane.lanes)
  return &lanes_;
}
inline const ::radar_srr_fc_lane::proto::SrrLane& srr_fc_frame_lane::lanes(int index) const {
  // @@protoc_insertion_point(field_get:radar_srr_fc_lane.proto.srr_fc_frame_lane.lanes)
  return lanes_.Get(index);
}
inline ::radar_srr_fc_lane::proto::SrrLane* srr_fc_frame_lane::add_lanes() {
  // @@protoc_insertion_point(field_add:radar_srr_fc_lane.proto.srr_fc_frame_lane.lanes)
  return lanes_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::radar_srr_fc_lane::proto::SrrLane >&
srr_fc_frame_lane::lanes() const {
  // @@protoc_insertion_point(field_list:radar_srr_fc_lane.proto.srr_fc_frame_lane.lanes)
  return lanes_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace radar_srr_fc_lane

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_radar_5fsrr_5ffc_5flane_2eproto
