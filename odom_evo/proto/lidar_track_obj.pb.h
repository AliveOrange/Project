// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lidar_track_obj.proto

#ifndef PROTOBUF_INCLUDED_lidar_5ftrack_5fobj_2eproto
#define PROTOBUF_INCLUDED_lidar_5ftrack_5fobj_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_lidar_5ftrack_5fobj_2eproto 

namespace protobuf_lidar_5ftrack_5fobj_2eproto {
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
}  // namespace protobuf_lidar_5ftrack_5fobj_2eproto
namespace lidar_obj_track {
namespace proto {
class HEADER;
class HEADERDefaultTypeInternal;
extern HEADERDefaultTypeInternal _HEADER_default_instance_;
class lidar_obj_track;
class lidar_obj_trackDefaultTypeInternal;
extern lidar_obj_trackDefaultTypeInternal _lidar_obj_track_default_instance_;
class obj_info;
class obj_infoDefaultTypeInternal;
extern obj_infoDefaultTypeInternal _obj_info_default_instance_;
}  // namespace proto
}  // namespace lidar_obj_track
namespace google {
namespace protobuf {
template<> ::lidar_obj_track::proto::HEADER* Arena::CreateMaybeMessage<::lidar_obj_track::proto::HEADER>(Arena*);
template<> ::lidar_obj_track::proto::lidar_obj_track* Arena::CreateMaybeMessage<::lidar_obj_track::proto::lidar_obj_track>(Arena*);
template<> ::lidar_obj_track::proto::obj_info* Arena::CreateMaybeMessage<::lidar_obj_track::proto::obj_info>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace lidar_obj_track {
namespace proto {

// ===================================================================

class HEADER : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lidar_obj_track.proto.HEADER) */ {
 public:
  HEADER();
  virtual ~HEADER();

  HEADER(const HEADER& from);

  inline HEADER& operator=(const HEADER& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  HEADER(HEADER&& from) noexcept
    : HEADER() {
    *this = ::std::move(from);
  }

  inline HEADER& operator=(HEADER&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const HEADER& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const HEADER* internal_default_instance() {
    return reinterpret_cast<const HEADER*>(
               &_HEADER_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(HEADER* other);
  friend void swap(HEADER& a, HEADER& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline HEADER* New() const final {
    return CreateMaybeMessage<HEADER>(NULL);
  }

  HEADER* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<HEADER>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const HEADER& from);
  void MergeFrom(const HEADER& from);
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
  void InternalSwap(HEADER* other);
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

  // uint32 num_of_obj = 3;
  void clear_num_of_obj();
  static const int kNumOfObjFieldNumber = 3;
  ::google::protobuf::uint32 num_of_obj() const;
  void set_num_of_obj(::google::protobuf::uint32 value);

  // uint32 id_liar = 4;
  void clear_id_liar();
  static const int kIdLiarFieldNumber = 4;
  ::google::protobuf::uint32 id_liar() const;
  void set_id_liar(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:lidar_obj_track.proto.HEADER)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  ::google::protobuf::uint32 rolling_counter_;
  ::google::protobuf::uint32 num_of_obj_;
  ::google::protobuf::uint32 id_liar_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_lidar_5ftrack_5fobj_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class obj_info : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lidar_obj_track.proto.obj_info) */ {
 public:
  obj_info();
  virtual ~obj_info();

  obj_info(const obj_info& from);

  inline obj_info& operator=(const obj_info& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  obj_info(obj_info&& from) noexcept
    : obj_info() {
    *this = ::std::move(from);
  }

  inline obj_info& operator=(obj_info&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const obj_info& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const obj_info* internal_default_instance() {
    return reinterpret_cast<const obj_info*>(
               &_obj_info_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(obj_info* other);
  friend void swap(obj_info& a, obj_info& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline obj_info* New() const final {
    return CreateMaybeMessage<obj_info>(NULL);
  }

  obj_info* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<obj_info>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const obj_info& from);
  void MergeFrom(const obj_info& from);
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
  void InternalSwap(obj_info* other);
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

  // double width = 6;
  void clear_width();
  static const int kWidthFieldNumber = 6;
  double width() const;
  void set_width(double value);

  // double height = 7;
  void clear_height();
  static const int kHeightFieldNumber = 7;
  double height() const;
  void set_height(double value);

  // double length = 8;
  void clear_length();
  static const int kLengthFieldNumber = 8;
  double length() const;
  void set_length(double value);

  // double loc_x = 9;
  void clear_loc_x();
  static const int kLocXFieldNumber = 9;
  double loc_x() const;
  void set_loc_x(double value);

  // double loc_y = 10;
  void clear_loc_y();
  static const int kLocYFieldNumber = 10;
  double loc_y() const;
  void set_loc_y(double value);

  // double loc_z = 11;
  void clear_loc_z();
  static const int kLocZFieldNumber = 11;
  double loc_z() const;
  void set_loc_z(double value);

  // double orientation_angle = 12;
  void clear_orientation_angle();
  static const int kOrientationAngleFieldNumber = 12;
  double orientation_angle() const;
  void set_orientation_angle(double value);

  // double vx_vehicle = 14;
  void clear_vx_vehicle();
  static const int kVxVehicleFieldNumber = 14;
  double vx_vehicle() const;
  void set_vx_vehicle(double value);

  // double vy_vehicle = 15;
  void clear_vy_vehicle();
  static const int kVyVehicleFieldNumber = 15;
  double vy_vehicle() const;
  void set_vy_vehicle(double value);

  // double loc_x_rms = 16;
  void clear_loc_x_rms();
  static const int kLocXRmsFieldNumber = 16;
  double loc_x_rms() const;
  void set_loc_x_rms(double value);

  // double loc_y_rms = 17;
  void clear_loc_y_rms();
  static const int kLocYRmsFieldNumber = 17;
  double loc_y_rms() const;
  void set_loc_y_rms(double value);

  // uint32 meas_state = 13;
  void clear_meas_state();
  static const int kMeasStateFieldNumber = 13;
  ::google::protobuf::uint32 meas_state() const;
  void set_meas_state(::google::protobuf::uint32 value);

  // bool stable_vrel_flag = 21;
  void clear_stable_vrel_flag();
  static const int kStableVrelFlagFieldNumber = 21;
  bool stable_vrel_flag() const;
  void set_stable_vrel_flag(bool value);

  // double vx_rms = 18;
  void clear_vx_rms();
  static const int kVxRmsFieldNumber = 18;
  double vx_rms() const;
  void set_vx_rms(double value);

  // double vy_rms = 19;
  void clear_vy_rms();
  static const int kVyRmsFieldNumber = 19;
  double vy_rms() const;
  void set_vy_rms(double value);

  // double orientation_rms = 20;
  void clear_orientation_rms();
  static const int kOrientationRmsFieldNumber = 20;
  double orientation_rms() const;
  void set_orientation_rms(double value);

  // @@protoc_insertion_point(class_scope:lidar_obj_track.proto.obj_info)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 obj_id_;
  ::google::protobuf::uint32 class_type_;
  double confidence_;
  ::google::protobuf::uint32 life_time_;
  ::google::protobuf::uint32 motion_status_;
  double width_;
  double height_;
  double length_;
  double loc_x_;
  double loc_y_;
  double loc_z_;
  double orientation_angle_;
  double vx_vehicle_;
  double vy_vehicle_;
  double loc_x_rms_;
  double loc_y_rms_;
  ::google::protobuf::uint32 meas_state_;
  bool stable_vrel_flag_;
  double vx_rms_;
  double vy_rms_;
  double orientation_rms_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_lidar_5ftrack_5fobj_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class lidar_obj_track : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:lidar_obj_track.proto.lidar_obj_track) */ {
 public:
  lidar_obj_track();
  virtual ~lidar_obj_track();

  lidar_obj_track(const lidar_obj_track& from);

  inline lidar_obj_track& operator=(const lidar_obj_track& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  lidar_obj_track(lidar_obj_track&& from) noexcept
    : lidar_obj_track() {
    *this = ::std::move(from);
  }

  inline lidar_obj_track& operator=(lidar_obj_track&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const lidar_obj_track& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const lidar_obj_track* internal_default_instance() {
    return reinterpret_cast<const lidar_obj_track*>(
               &_lidar_obj_track_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(lidar_obj_track* other);
  friend void swap(lidar_obj_track& a, lidar_obj_track& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline lidar_obj_track* New() const final {
    return CreateMaybeMessage<lidar_obj_track>(NULL);
  }

  lidar_obj_track* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<lidar_obj_track>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const lidar_obj_track& from);
  void MergeFrom(const lidar_obj_track& from);
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
  void InternalSwap(lidar_obj_track* other);
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

  // repeated .lidar_obj_track.proto.obj_info obj = 2;
  int obj_size() const;
  void clear_obj();
  static const int kObjFieldNumber = 2;
  ::lidar_obj_track::proto::obj_info* mutable_obj(int index);
  ::google::protobuf::RepeatedPtrField< ::lidar_obj_track::proto::obj_info >*
      mutable_obj();
  const ::lidar_obj_track::proto::obj_info& obj(int index) const;
  ::lidar_obj_track::proto::obj_info* add_obj();
  const ::google::protobuf::RepeatedPtrField< ::lidar_obj_track::proto::obj_info >&
      obj() const;

  // .lidar_obj_track.proto.HEADER header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::lidar_obj_track::proto::HEADER& _internal_header() const;
  public:
  const ::lidar_obj_track::proto::HEADER& header() const;
  ::lidar_obj_track::proto::HEADER* release_header();
  ::lidar_obj_track::proto::HEADER* mutable_header();
  void set_allocated_header(::lidar_obj_track::proto::HEADER* header);

  // @@protoc_insertion_point(class_scope:lidar_obj_track.proto.lidar_obj_track)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::lidar_obj_track::proto::obj_info > obj_;
  ::lidar_obj_track::proto::HEADER* header_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_lidar_5ftrack_5fobj_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// HEADER

// uint64 timestamp = 1;
inline void HEADER::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 HEADER::timestamp() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.HEADER.timestamp)
  return timestamp_;
}
inline void HEADER::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.HEADER.timestamp)
}

// uint32 rolling_counter = 2;
inline void HEADER::clear_rolling_counter() {
  rolling_counter_ = 0u;
}
inline ::google::protobuf::uint32 HEADER::rolling_counter() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.HEADER.rolling_counter)
  return rolling_counter_;
}
inline void HEADER::set_rolling_counter(::google::protobuf::uint32 value) {
  
  rolling_counter_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.HEADER.rolling_counter)
}

// uint32 num_of_obj = 3;
inline void HEADER::clear_num_of_obj() {
  num_of_obj_ = 0u;
}
inline ::google::protobuf::uint32 HEADER::num_of_obj() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.HEADER.num_of_obj)
  return num_of_obj_;
}
inline void HEADER::set_num_of_obj(::google::protobuf::uint32 value) {
  
  num_of_obj_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.HEADER.num_of_obj)
}

// uint32 id_liar = 4;
inline void HEADER::clear_id_liar() {
  id_liar_ = 0u;
}
inline ::google::protobuf::uint32 HEADER::id_liar() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.HEADER.id_liar)
  return id_liar_;
}
inline void HEADER::set_id_liar(::google::protobuf::uint32 value) {
  
  id_liar_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.HEADER.id_liar)
}

// -------------------------------------------------------------------

// obj_info

// uint32 obj_id = 1;
inline void obj_info::clear_obj_id() {
  obj_id_ = 0u;
}
inline ::google::protobuf::uint32 obj_info::obj_id() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.obj_id)
  return obj_id_;
}
inline void obj_info::set_obj_id(::google::protobuf::uint32 value) {
  
  obj_id_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.obj_id)
}

// uint32 class_type = 2;
inline void obj_info::clear_class_type() {
  class_type_ = 0u;
}
inline ::google::protobuf::uint32 obj_info::class_type() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.class_type)
  return class_type_;
}
inline void obj_info::set_class_type(::google::protobuf::uint32 value) {
  
  class_type_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.class_type)
}

// double confidence = 3;
inline void obj_info::clear_confidence() {
  confidence_ = 0;
}
inline double obj_info::confidence() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.confidence)
  return confidence_;
}
inline void obj_info::set_confidence(double value) {
  
  confidence_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.confidence)
}

// uint32 life_time = 4;
inline void obj_info::clear_life_time() {
  life_time_ = 0u;
}
inline ::google::protobuf::uint32 obj_info::life_time() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.life_time)
  return life_time_;
}
inline void obj_info::set_life_time(::google::protobuf::uint32 value) {
  
  life_time_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.life_time)
}

// uint32 motion_status = 5;
inline void obj_info::clear_motion_status() {
  motion_status_ = 0u;
}
inline ::google::protobuf::uint32 obj_info::motion_status() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.motion_status)
  return motion_status_;
}
inline void obj_info::set_motion_status(::google::protobuf::uint32 value) {
  
  motion_status_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.motion_status)
}

// double width = 6;
inline void obj_info::clear_width() {
  width_ = 0;
}
inline double obj_info::width() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.width)
  return width_;
}
inline void obj_info::set_width(double value) {
  
  width_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.width)
}

// double height = 7;
inline void obj_info::clear_height() {
  height_ = 0;
}
inline double obj_info::height() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.height)
  return height_;
}
inline void obj_info::set_height(double value) {
  
  height_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.height)
}

// double length = 8;
inline void obj_info::clear_length() {
  length_ = 0;
}
inline double obj_info::length() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.length)
  return length_;
}
inline void obj_info::set_length(double value) {
  
  length_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.length)
}

// double loc_x = 9;
inline void obj_info::clear_loc_x() {
  loc_x_ = 0;
}
inline double obj_info::loc_x() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.loc_x)
  return loc_x_;
}
inline void obj_info::set_loc_x(double value) {
  
  loc_x_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.loc_x)
}

// double loc_y = 10;
inline void obj_info::clear_loc_y() {
  loc_y_ = 0;
}
inline double obj_info::loc_y() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.loc_y)
  return loc_y_;
}
inline void obj_info::set_loc_y(double value) {
  
  loc_y_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.loc_y)
}

// double loc_z = 11;
inline void obj_info::clear_loc_z() {
  loc_z_ = 0;
}
inline double obj_info::loc_z() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.loc_z)
  return loc_z_;
}
inline void obj_info::set_loc_z(double value) {
  
  loc_z_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.loc_z)
}

// double orientation_angle = 12;
inline void obj_info::clear_orientation_angle() {
  orientation_angle_ = 0;
}
inline double obj_info::orientation_angle() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.orientation_angle)
  return orientation_angle_;
}
inline void obj_info::set_orientation_angle(double value) {
  
  orientation_angle_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.orientation_angle)
}

// uint32 meas_state = 13;
inline void obj_info::clear_meas_state() {
  meas_state_ = 0u;
}
inline ::google::protobuf::uint32 obj_info::meas_state() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.meas_state)
  return meas_state_;
}
inline void obj_info::set_meas_state(::google::protobuf::uint32 value) {
  
  meas_state_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.meas_state)
}

// double vx_vehicle = 14;
inline void obj_info::clear_vx_vehicle() {
  vx_vehicle_ = 0;
}
inline double obj_info::vx_vehicle() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.vx_vehicle)
  return vx_vehicle_;
}
inline void obj_info::set_vx_vehicle(double value) {
  
  vx_vehicle_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.vx_vehicle)
}

// double vy_vehicle = 15;
inline void obj_info::clear_vy_vehicle() {
  vy_vehicle_ = 0;
}
inline double obj_info::vy_vehicle() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.vy_vehicle)
  return vy_vehicle_;
}
inline void obj_info::set_vy_vehicle(double value) {
  
  vy_vehicle_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.vy_vehicle)
}

// double loc_x_rms = 16;
inline void obj_info::clear_loc_x_rms() {
  loc_x_rms_ = 0;
}
inline double obj_info::loc_x_rms() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.loc_x_rms)
  return loc_x_rms_;
}
inline void obj_info::set_loc_x_rms(double value) {
  
  loc_x_rms_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.loc_x_rms)
}

// double loc_y_rms = 17;
inline void obj_info::clear_loc_y_rms() {
  loc_y_rms_ = 0;
}
inline double obj_info::loc_y_rms() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.loc_y_rms)
  return loc_y_rms_;
}
inline void obj_info::set_loc_y_rms(double value) {
  
  loc_y_rms_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.loc_y_rms)
}

// double vx_rms = 18;
inline void obj_info::clear_vx_rms() {
  vx_rms_ = 0;
}
inline double obj_info::vx_rms() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.vx_rms)
  return vx_rms_;
}
inline void obj_info::set_vx_rms(double value) {
  
  vx_rms_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.vx_rms)
}

// double vy_rms = 19;
inline void obj_info::clear_vy_rms() {
  vy_rms_ = 0;
}
inline double obj_info::vy_rms() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.vy_rms)
  return vy_rms_;
}
inline void obj_info::set_vy_rms(double value) {
  
  vy_rms_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.vy_rms)
}

// double orientation_rms = 20;
inline void obj_info::clear_orientation_rms() {
  orientation_rms_ = 0;
}
inline double obj_info::orientation_rms() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.orientation_rms)
  return orientation_rms_;
}
inline void obj_info::set_orientation_rms(double value) {
  
  orientation_rms_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.orientation_rms)
}

// bool stable_vrel_flag = 21;
inline void obj_info::clear_stable_vrel_flag() {
  stable_vrel_flag_ = false;
}
inline bool obj_info::stable_vrel_flag() const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.obj_info.stable_vrel_flag)
  return stable_vrel_flag_;
}
inline void obj_info::set_stable_vrel_flag(bool value) {
  
  stable_vrel_flag_ = value;
  // @@protoc_insertion_point(field_set:lidar_obj_track.proto.obj_info.stable_vrel_flag)
}

// -------------------------------------------------------------------

// lidar_obj_track

// .lidar_obj_track.proto.HEADER header = 1;
inline bool lidar_obj_track::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void lidar_obj_track::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
inline const ::lidar_obj_track::proto::HEADER& lidar_obj_track::_internal_header() const {
  return *header_;
}
inline const ::lidar_obj_track::proto::HEADER& lidar_obj_track::header() const {
  const ::lidar_obj_track::proto::HEADER* p = header_;
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.lidar_obj_track.header)
  return p != NULL ? *p : *reinterpret_cast<const ::lidar_obj_track::proto::HEADER*>(
      &::lidar_obj_track::proto::_HEADER_default_instance_);
}
inline ::lidar_obj_track::proto::HEADER* lidar_obj_track::release_header() {
  // @@protoc_insertion_point(field_release:lidar_obj_track.proto.lidar_obj_track.header)
  
  ::lidar_obj_track::proto::HEADER* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::lidar_obj_track::proto::HEADER* lidar_obj_track::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::lidar_obj_track::proto::HEADER>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:lidar_obj_track.proto.lidar_obj_track.header)
  return header_;
}
inline void lidar_obj_track::set_allocated_header(::lidar_obj_track::proto::HEADER* header) {
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
  // @@protoc_insertion_point(field_set_allocated:lidar_obj_track.proto.lidar_obj_track.header)
}

// repeated .lidar_obj_track.proto.obj_info obj = 2;
inline int lidar_obj_track::obj_size() const {
  return obj_.size();
}
inline void lidar_obj_track::clear_obj() {
  obj_.Clear();
}
inline ::lidar_obj_track::proto::obj_info* lidar_obj_track::mutable_obj(int index) {
  // @@protoc_insertion_point(field_mutable:lidar_obj_track.proto.lidar_obj_track.obj)
  return obj_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::lidar_obj_track::proto::obj_info >*
lidar_obj_track::mutable_obj() {
  // @@protoc_insertion_point(field_mutable_list:lidar_obj_track.proto.lidar_obj_track.obj)
  return &obj_;
}
inline const ::lidar_obj_track::proto::obj_info& lidar_obj_track::obj(int index) const {
  // @@protoc_insertion_point(field_get:lidar_obj_track.proto.lidar_obj_track.obj)
  return obj_.Get(index);
}
inline ::lidar_obj_track::proto::obj_info* lidar_obj_track::add_obj() {
  // @@protoc_insertion_point(field_add:lidar_obj_track.proto.lidar_obj_track.obj)
  return obj_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::lidar_obj_track::proto::obj_info >&
lidar_obj_track::obj() const {
  // @@protoc_insertion_point(field_list:lidar_obj_track.proto.lidar_obj_track.obj)
  return obj_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace lidar_obj_track

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_lidar_5ftrack_5fobj_2eproto
