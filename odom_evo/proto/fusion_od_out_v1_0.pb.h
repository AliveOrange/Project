// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: fusion_od_out_v1_0.proto

#ifndef PROTOBUF_INCLUDED_fusion_5fod_5fout_5fv1_5f0_2eproto
#define PROTOBUF_INCLUDED_fusion_5fod_5fout_5fv1_5f0_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto 

namespace protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto {
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
}  // namespace protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto
namespace fusion_od_out {
namespace proto {
class ObjFrame;
class ObjFrameDefaultTypeInternal;
extern ObjFrameDefaultTypeInternal _ObjFrame_default_instance_;
class ObjectHeader;
class ObjectHeaderDefaultTypeInternal;
extern ObjectHeaderDefaultTypeInternal _ObjectHeader_default_instance_;
class ObjectInfo;
class ObjectInfoDefaultTypeInternal;
extern ObjectInfoDefaultTypeInternal _ObjectInfo_default_instance_;
}  // namespace proto
}  // namespace fusion_od_out
namespace google {
namespace protobuf {
template<> ::fusion_od_out::proto::ObjFrame* Arena::CreateMaybeMessage<::fusion_od_out::proto::ObjFrame>(Arena*);
template<> ::fusion_od_out::proto::ObjectHeader* Arena::CreateMaybeMessage<::fusion_od_out::proto::ObjectHeader>(Arena*);
template<> ::fusion_od_out::proto::ObjectInfo* Arena::CreateMaybeMessage<::fusion_od_out::proto::ObjectInfo>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace fusion_od_out {
namespace proto {

// ===================================================================

class ObjectHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fusion_od_out.proto.ObjectHeader) */ {
 public:
  ObjectHeader();
  virtual ~ObjectHeader();

  ObjectHeader(const ObjectHeader& from);

  inline ObjectHeader& operator=(const ObjectHeader& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ObjectHeader(ObjectHeader&& from) noexcept
    : ObjectHeader() {
    *this = ::std::move(from);
  }

  inline ObjectHeader& operator=(ObjectHeader&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ObjectHeader& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ObjectHeader* internal_default_instance() {
    return reinterpret_cast<const ObjectHeader*>(
               &_ObjectHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ObjectHeader* other);
  friend void swap(ObjectHeader& a, ObjectHeader& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ObjectHeader* New() const final {
    return CreateMaybeMessage<ObjectHeader>(NULL);
  }

  ObjectHeader* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ObjectHeader>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ObjectHeader& from);
  void MergeFrom(const ObjectHeader& from);
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
  void InternalSwap(ObjectHeader* other);
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

  // @@protoc_insertion_point(class_scope:fusion_od_out.proto.ObjectHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  ::google::protobuf::uint32 rolling_counter_;
  ::google::protobuf::uint32 sensor_id_;
  ::google::protobuf::uint32 obj_num_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ObjectInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fusion_od_out.proto.ObjectInfo) */ {
 public:
  ObjectInfo();
  virtual ~ObjectInfo();

  ObjectInfo(const ObjectInfo& from);

  inline ObjectInfo& operator=(const ObjectInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ObjectInfo(ObjectInfo&& from) noexcept
    : ObjectInfo() {
    *this = ::std::move(from);
  }

  inline ObjectInfo& operator=(ObjectInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ObjectInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ObjectInfo* internal_default_instance() {
    return reinterpret_cast<const ObjectInfo*>(
               &_ObjectInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ObjectInfo* other);
  friend void swap(ObjectInfo& a, ObjectInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ObjectInfo* New() const final {
    return CreateMaybeMessage<ObjectInfo>(NULL);
  }

  ObjectInfo* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ObjectInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ObjectInfo& from);
  void MergeFrom(const ObjectInfo& from);
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
  void InternalSwap(ObjectInfo* other);
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

  // uint32 obj_id = 1;
  void clear_obj_id();
  static const int kObjIdFieldNumber = 1;
  ::google::protobuf::uint32 obj_id() const;
  void set_obj_id(::google::protobuf::uint32 value);

  // uint32 class_type = 2;
  void clear_class_type();
  static const int kClassTypeFieldNumber = 2;
  ::google::protobuf::uint32 class_type() const;
  void set_class_type(::google::protobuf::uint32 value);

  // double confidence = 3;
  void clear_confidence();
  static const int kConfidenceFieldNumber = 3;
  double confidence() const;
  void set_confidence(double value);

  // uint32 life_time = 4;
  void clear_life_time();
  static const int kLifeTimeFieldNumber = 4;
  ::google::protobuf::uint32 life_time() const;
  void set_life_time(::google::protobuf::uint32 value);

  // uint32 motion_status = 5;
  void clear_motion_status();
  static const int kMotionStatusFieldNumber = 5;
  ::google::protobuf::uint32 motion_status() const;
  void set_motion_status(::google::protobuf::uint32 value);

  // double height = 6;
  void clear_height();
  static const int kHeightFieldNumber = 6;
  double height() const;
  void set_height(double value);

  // double width = 7;
  void clear_width();
  static const int kWidthFieldNumber = 7;
  double width() const;
  void set_width(double value);

  // double length = 8;
  void clear_length();
  static const int kLengthFieldNumber = 8;
  double length() const;
  void set_length(double value);

  // double dist_long = 9;
  void clear_dist_long();
  static const int kDistLongFieldNumber = 9;
  double dist_long() const;
  void set_dist_long(double value);

  // double dist_lat = 10;
  void clear_dist_lat();
  static const int kDistLatFieldNumber = 10;
  double dist_lat() const;
  void set_dist_lat(double value);

  // double vrel_long = 11;
  void clear_vrel_long();
  static const int kVrelLongFieldNumber = 11;
  double vrel_long() const;
  void set_vrel_long(double value);

  // double vrel_lat = 12;
  void clear_vrel_lat();
  static const int kVrelLatFieldNumber = 12;
  double vrel_lat() const;
  void set_vrel_lat(double value);

  // double arel_long = 13;
  void clear_arel_long();
  static const int kArelLongFieldNumber = 13;
  double arel_long() const;
  void set_arel_long(double value);

  // double arel_lat = 14;
  void clear_arel_lat();
  static const int kArelLatFieldNumber = 14;
  double arel_lat() const;
  void set_arel_lat(double value);

  // double yaw_angle = 15;
  void clear_yaw_angle();
  static const int kYawAngleFieldNumber = 15;
  double yaw_angle() const;
  void set_yaw_angle(double value);

  // double orientation_angle = 16;
  void clear_orientation_angle();
  static const int kOrientationAngleFieldNumber = 16;
  double orientation_angle() const;
  void set_orientation_angle(double value);

  // double dist_long_rms = 18;
  void clear_dist_long_rms();
  static const int kDistLongRmsFieldNumber = 18;
  double dist_long_rms() const;
  void set_dist_long_rms(double value);

  // double dist_lat_rms = 19;
  void clear_dist_lat_rms();
  static const int kDistLatRmsFieldNumber = 19;
  double dist_lat_rms() const;
  void set_dist_lat_rms(double value);

  // double vrel_long_rms = 20;
  void clear_vrel_long_rms();
  static const int kVrelLongRmsFieldNumber = 20;
  double vrel_long_rms() const;
  void set_vrel_long_rms(double value);

  // double vrel_lat_rms = 21;
  void clear_vrel_lat_rms();
  static const int kVrelLatRmsFieldNumber = 21;
  double vrel_lat_rms() const;
  void set_vrel_lat_rms(double value);

  // double arel_long_rms = 22;
  void clear_arel_long_rms();
  static const int kArelLongRmsFieldNumber = 22;
  double arel_long_rms() const;
  void set_arel_long_rms(double value);

  // double arel_lat_rms = 23;
  void clear_arel_lat_rms();
  static const int kArelLatRmsFieldNumber = 23;
  double arel_lat_rms() const;
  void set_arel_lat_rms(double value);

  // double orientation_rms = 24;
  void clear_orientation_rms();
  static const int kOrientationRmsFieldNumber = 24;
  double orientation_rms() const;
  void set_orientation_rms(double value);

  // uint32 meas_state = 17;
  void clear_meas_state();
  static const int kMeasStateFieldNumber = 17;
  ::google::protobuf::uint32 meas_state() const;
  void set_meas_state(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:fusion_od_out.proto.ObjectInfo)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 obj_id_;
  ::google::protobuf::uint32 class_type_;
  double confidence_;
  ::google::protobuf::uint32 life_time_;
  ::google::protobuf::uint32 motion_status_;
  double height_;
  double width_;
  double length_;
  double dist_long_;
  double dist_lat_;
  double vrel_long_;
  double vrel_lat_;
  double arel_long_;
  double arel_lat_;
  double yaw_angle_;
  double orientation_angle_;
  double dist_long_rms_;
  double dist_lat_rms_;
  double vrel_long_rms_;
  double vrel_lat_rms_;
  double arel_long_rms_;
  double arel_lat_rms_;
  double orientation_rms_;
  ::google::protobuf::uint32 meas_state_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ObjFrame : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fusion_od_out.proto.ObjFrame) */ {
 public:
  ObjFrame();
  virtual ~ObjFrame();

  ObjFrame(const ObjFrame& from);

  inline ObjFrame& operator=(const ObjFrame& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ObjFrame(ObjFrame&& from) noexcept
    : ObjFrame() {
    *this = ::std::move(from);
  }

  inline ObjFrame& operator=(ObjFrame&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ObjFrame& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ObjFrame* internal_default_instance() {
    return reinterpret_cast<const ObjFrame*>(
               &_ObjFrame_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(ObjFrame* other);
  friend void swap(ObjFrame& a, ObjFrame& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ObjFrame* New() const final {
    return CreateMaybeMessage<ObjFrame>(NULL);
  }

  ObjFrame* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ObjFrame>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ObjFrame& from);
  void MergeFrom(const ObjFrame& from);
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
  void InternalSwap(ObjFrame* other);
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

  // repeated .fusion_od_out.proto.ObjectInfo objects = 3;
  int objects_size() const;
  void clear_objects();
  static const int kObjectsFieldNumber = 3;
  ::fusion_od_out::proto::ObjectInfo* mutable_objects(int index);
  ::google::protobuf::RepeatedPtrField< ::fusion_od_out::proto::ObjectInfo >*
      mutable_objects();
  const ::fusion_od_out::proto::ObjectInfo& objects(int index) const;
  ::fusion_od_out::proto::ObjectInfo* add_objects();
  const ::google::protobuf::RepeatedPtrField< ::fusion_od_out::proto::ObjectInfo >&
      objects() const;

  // .fusion_od_out.proto.ObjectHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::fusion_od_out::proto::ObjectHeader& _internal_header() const;
  public:
  const ::fusion_od_out::proto::ObjectHeader& header() const;
  ::fusion_od_out::proto::ObjectHeader* release_header();
  ::fusion_od_out::proto::ObjectHeader* mutable_header();
  void set_allocated_header(::fusion_od_out::proto::ObjectHeader* header);

  // uint64 timestamp = 2;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 2;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:fusion_od_out.proto.ObjFrame)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::fusion_od_out::proto::ObjectInfo > objects_;
  ::fusion_od_out::proto::ObjectHeader* header_;
  ::google::protobuf::uint64 timestamp_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_fusion_5fod_5fout_5fv1_5f0_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ObjectHeader

// uint64 timestamp = 1;
inline void ObjectHeader::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 ObjectHeader::timestamp() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectHeader.timestamp)
  return timestamp_;
}
inline void ObjectHeader::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectHeader.timestamp)
}

// uint32 rolling_counter = 2;
inline void ObjectHeader::clear_rolling_counter() {
  rolling_counter_ = 0u;
}
inline ::google::protobuf::uint32 ObjectHeader::rolling_counter() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectHeader.rolling_counter)
  return rolling_counter_;
}
inline void ObjectHeader::set_rolling_counter(::google::protobuf::uint32 value) {
  
  rolling_counter_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectHeader.rolling_counter)
}

// uint32 sensor_id = 3;
inline void ObjectHeader::clear_sensor_id() {
  sensor_id_ = 0u;
}
inline ::google::protobuf::uint32 ObjectHeader::sensor_id() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectHeader.sensor_id)
  return sensor_id_;
}
inline void ObjectHeader::set_sensor_id(::google::protobuf::uint32 value) {
  
  sensor_id_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectHeader.sensor_id)
}

// uint32 obj_num = 4;
inline void ObjectHeader::clear_obj_num() {
  obj_num_ = 0u;
}
inline ::google::protobuf::uint32 ObjectHeader::obj_num() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectHeader.obj_num)
  return obj_num_;
}
inline void ObjectHeader::set_obj_num(::google::protobuf::uint32 value) {
  
  obj_num_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectHeader.obj_num)
}

// -------------------------------------------------------------------

// ObjectInfo

// uint32 obj_id = 1;
inline void ObjectInfo::clear_obj_id() {
  obj_id_ = 0u;
}
inline ::google::protobuf::uint32 ObjectInfo::obj_id() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.obj_id)
  return obj_id_;
}
inline void ObjectInfo::set_obj_id(::google::protobuf::uint32 value) {
  
  obj_id_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.obj_id)
}

// uint32 class_type = 2;
inline void ObjectInfo::clear_class_type() {
  class_type_ = 0u;
}
inline ::google::protobuf::uint32 ObjectInfo::class_type() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.class_type)
  return class_type_;
}
inline void ObjectInfo::set_class_type(::google::protobuf::uint32 value) {
  
  class_type_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.class_type)
}

// double confidence = 3;
inline void ObjectInfo::clear_confidence() {
  confidence_ = 0;
}
inline double ObjectInfo::confidence() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.confidence)
  return confidence_;
}
inline void ObjectInfo::set_confidence(double value) {
  
  confidence_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.confidence)
}

// uint32 life_time = 4;
inline void ObjectInfo::clear_life_time() {
  life_time_ = 0u;
}
inline ::google::protobuf::uint32 ObjectInfo::life_time() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.life_time)
  return life_time_;
}
inline void ObjectInfo::set_life_time(::google::protobuf::uint32 value) {
  
  life_time_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.life_time)
}

// uint32 motion_status = 5;
inline void ObjectInfo::clear_motion_status() {
  motion_status_ = 0u;
}
inline ::google::protobuf::uint32 ObjectInfo::motion_status() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.motion_status)
  return motion_status_;
}
inline void ObjectInfo::set_motion_status(::google::protobuf::uint32 value) {
  
  motion_status_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.motion_status)
}

// double height = 6;
inline void ObjectInfo::clear_height() {
  height_ = 0;
}
inline double ObjectInfo::height() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.height)
  return height_;
}
inline void ObjectInfo::set_height(double value) {
  
  height_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.height)
}

// double width = 7;
inline void ObjectInfo::clear_width() {
  width_ = 0;
}
inline double ObjectInfo::width() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.width)
  return width_;
}
inline void ObjectInfo::set_width(double value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.width)
}

// double length = 8;
inline void ObjectInfo::clear_length() {
  length_ = 0;
}
inline double ObjectInfo::length() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.length)
  return length_;
}
inline void ObjectInfo::set_length(double value) {
  
  length_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.length)
}

// double dist_long = 9;
inline void ObjectInfo::clear_dist_long() {
  dist_long_ = 0;
}
inline double ObjectInfo::dist_long() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.dist_long)
  return dist_long_;
}
inline void ObjectInfo::set_dist_long(double value) {
  
  dist_long_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.dist_long)
}

// double dist_lat = 10;
inline void ObjectInfo::clear_dist_lat() {
  dist_lat_ = 0;
}
inline double ObjectInfo::dist_lat() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.dist_lat)
  return dist_lat_;
}
inline void ObjectInfo::set_dist_lat(double value) {
  
  dist_lat_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.dist_lat)
}

// double vrel_long = 11;
inline void ObjectInfo::clear_vrel_long() {
  vrel_long_ = 0;
}
inline double ObjectInfo::vrel_long() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.vrel_long)
  return vrel_long_;
}
inline void ObjectInfo::set_vrel_long(double value) {
  
  vrel_long_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.vrel_long)
}

// double vrel_lat = 12;
inline void ObjectInfo::clear_vrel_lat() {
  vrel_lat_ = 0;
}
inline double ObjectInfo::vrel_lat() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.vrel_lat)
  return vrel_lat_;
}
inline void ObjectInfo::set_vrel_lat(double value) {
  
  vrel_lat_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.vrel_lat)
}

// double arel_long = 13;
inline void ObjectInfo::clear_arel_long() {
  arel_long_ = 0;
}
inline double ObjectInfo::arel_long() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.arel_long)
  return arel_long_;
}
inline void ObjectInfo::set_arel_long(double value) {
  
  arel_long_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.arel_long)
}

// double arel_lat = 14;
inline void ObjectInfo::clear_arel_lat() {
  arel_lat_ = 0;
}
inline double ObjectInfo::arel_lat() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.arel_lat)
  return arel_lat_;
}
inline void ObjectInfo::set_arel_lat(double value) {
  
  arel_lat_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.arel_lat)
}

// double yaw_angle = 15;
inline void ObjectInfo::clear_yaw_angle() {
  yaw_angle_ = 0;
}
inline double ObjectInfo::yaw_angle() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.yaw_angle)
  return yaw_angle_;
}
inline void ObjectInfo::set_yaw_angle(double value) {
  
  yaw_angle_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.yaw_angle)
}

// double orientation_angle = 16;
inline void ObjectInfo::clear_orientation_angle() {
  orientation_angle_ = 0;
}
inline double ObjectInfo::orientation_angle() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.orientation_angle)
  return orientation_angle_;
}
inline void ObjectInfo::set_orientation_angle(double value) {
  
  orientation_angle_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.orientation_angle)
}

// uint32 meas_state = 17;
inline void ObjectInfo::clear_meas_state() {
  meas_state_ = 0u;
}
inline ::google::protobuf::uint32 ObjectInfo::meas_state() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.meas_state)
  return meas_state_;
}
inline void ObjectInfo::set_meas_state(::google::protobuf::uint32 value) {
  
  meas_state_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.meas_state)
}

// double dist_long_rms = 18;
inline void ObjectInfo::clear_dist_long_rms() {
  dist_long_rms_ = 0;
}
inline double ObjectInfo::dist_long_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.dist_long_rms)
  return dist_long_rms_;
}
inline void ObjectInfo::set_dist_long_rms(double value) {
  
  dist_long_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.dist_long_rms)
}

// double dist_lat_rms = 19;
inline void ObjectInfo::clear_dist_lat_rms() {
  dist_lat_rms_ = 0;
}
inline double ObjectInfo::dist_lat_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.dist_lat_rms)
  return dist_lat_rms_;
}
inline void ObjectInfo::set_dist_lat_rms(double value) {
  
  dist_lat_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.dist_lat_rms)
}

// double vrel_long_rms = 20;
inline void ObjectInfo::clear_vrel_long_rms() {
  vrel_long_rms_ = 0;
}
inline double ObjectInfo::vrel_long_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.vrel_long_rms)
  return vrel_long_rms_;
}
inline void ObjectInfo::set_vrel_long_rms(double value) {
  
  vrel_long_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.vrel_long_rms)
}

// double vrel_lat_rms = 21;
inline void ObjectInfo::clear_vrel_lat_rms() {
  vrel_lat_rms_ = 0;
}
inline double ObjectInfo::vrel_lat_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.vrel_lat_rms)
  return vrel_lat_rms_;
}
inline void ObjectInfo::set_vrel_lat_rms(double value) {
  
  vrel_lat_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.vrel_lat_rms)
}

// double arel_long_rms = 22;
inline void ObjectInfo::clear_arel_long_rms() {
  arel_long_rms_ = 0;
}
inline double ObjectInfo::arel_long_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.arel_long_rms)
  return arel_long_rms_;
}
inline void ObjectInfo::set_arel_long_rms(double value) {
  
  arel_long_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.arel_long_rms)
}

// double arel_lat_rms = 23;
inline void ObjectInfo::clear_arel_lat_rms() {
  arel_lat_rms_ = 0;
}
inline double ObjectInfo::arel_lat_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.arel_lat_rms)
  return arel_lat_rms_;
}
inline void ObjectInfo::set_arel_lat_rms(double value) {
  
  arel_lat_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.arel_lat_rms)
}

// double orientation_rms = 24;
inline void ObjectInfo::clear_orientation_rms() {
  orientation_rms_ = 0;
}
inline double ObjectInfo::orientation_rms() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjectInfo.orientation_rms)
  return orientation_rms_;
}
inline void ObjectInfo::set_orientation_rms(double value) {
  
  orientation_rms_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjectInfo.orientation_rms)
}

// -------------------------------------------------------------------

// ObjFrame

// .fusion_od_out.proto.ObjectHeader header = 1;
inline bool ObjFrame::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void ObjFrame::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
inline const ::fusion_od_out::proto::ObjectHeader& ObjFrame::_internal_header() const {
  return *header_;
}
inline const ::fusion_od_out::proto::ObjectHeader& ObjFrame::header() const {
  const ::fusion_od_out::proto::ObjectHeader* p = header_;
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjFrame.header)
  return p != NULL ? *p : *reinterpret_cast<const ::fusion_od_out::proto::ObjectHeader*>(
      &::fusion_od_out::proto::_ObjectHeader_default_instance_);
}
inline ::fusion_od_out::proto::ObjectHeader* ObjFrame::release_header() {
  // @@protoc_insertion_point(field_release:fusion_od_out.proto.ObjFrame.header)
  
  ::fusion_od_out::proto::ObjectHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::fusion_od_out::proto::ObjectHeader* ObjFrame::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::fusion_od_out::proto::ObjectHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:fusion_od_out.proto.ObjFrame.header)
  return header_;
}
inline void ObjFrame::set_allocated_header(::fusion_od_out::proto::ObjectHeader* header) {
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
  // @@protoc_insertion_point(field_set_allocated:fusion_od_out.proto.ObjFrame.header)
}

// uint64 timestamp = 2;
inline void ObjFrame::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 ObjFrame::timestamp() const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjFrame.timestamp)
  return timestamp_;
}
inline void ObjFrame::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:fusion_od_out.proto.ObjFrame.timestamp)
}

// repeated .fusion_od_out.proto.ObjectInfo objects = 3;
inline int ObjFrame::objects_size() const {
  return objects_.size();
}
inline void ObjFrame::clear_objects() {
  objects_.Clear();
}
inline ::fusion_od_out::proto::ObjectInfo* ObjFrame::mutable_objects(int index) {
  // @@protoc_insertion_point(field_mutable:fusion_od_out.proto.ObjFrame.objects)
  return objects_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::fusion_od_out::proto::ObjectInfo >*
ObjFrame::mutable_objects() {
  // @@protoc_insertion_point(field_mutable_list:fusion_od_out.proto.ObjFrame.objects)
  return &objects_;
}
inline const ::fusion_od_out::proto::ObjectInfo& ObjFrame::objects(int index) const {
  // @@protoc_insertion_point(field_get:fusion_od_out.proto.ObjFrame.objects)
  return objects_.Get(index);
}
inline ::fusion_od_out::proto::ObjectInfo* ObjFrame::add_objects() {
  // @@protoc_insertion_point(field_add:fusion_od_out.proto.ObjFrame.objects)
  return objects_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::fusion_od_out::proto::ObjectInfo >&
ObjFrame::objects() const {
  // @@protoc_insertion_point(field_list:fusion_od_out.proto.ObjFrame.objects)
  return objects_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace fusion_od_out

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_fusion_5fod_5fout_5fv1_5f0_2eproto