// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: camera_me_failsafe.proto

#ifndef PROTOBUF_INCLUDED_camera_5fme_5ffailsafe_2eproto
#define PROTOBUF_INCLUDED_camera_5fme_5ffailsafe_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_camera_5fme_5ffailsafe_2eproto 

namespace protobuf_camera_5fme_5ffailsafe_2eproto {
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
}  // namespace protobuf_camera_5fme_5ffailsafe_2eproto
namespace camera_me_failsafe {
namespace proto {
class MeFailSafe;
class MeFailSafeDefaultTypeInternal;
extern MeFailSafeDefaultTypeInternal _MeFailSafe_default_instance_;
class MeHeader;
class MeHeaderDefaultTypeInternal;
extern MeHeaderDefaultTypeInternal _MeHeader_default_instance_;
class me_frame_fs;
class me_frame_fsDefaultTypeInternal;
extern me_frame_fsDefaultTypeInternal _me_frame_fs_default_instance_;
}  // namespace proto
}  // namespace camera_me_failsafe
namespace google {
namespace protobuf {
template<> ::camera_me_failsafe::proto::MeFailSafe* Arena::CreateMaybeMessage<::camera_me_failsafe::proto::MeFailSafe>(Arena*);
template<> ::camera_me_failsafe::proto::MeHeader* Arena::CreateMaybeMessage<::camera_me_failsafe::proto::MeHeader>(Arena*);
template<> ::camera_me_failsafe::proto::me_frame_fs* Arena::CreateMaybeMessage<::camera_me_failsafe::proto::me_frame_fs>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace camera_me_failsafe {
namespace proto {

// ===================================================================

class MeHeader : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:camera_me_failsafe.proto.MeHeader) */ {
 public:
  MeHeader();
  virtual ~MeHeader();

  MeHeader(const MeHeader& from);

  inline MeHeader& operator=(const MeHeader& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MeHeader(MeHeader&& from) noexcept
    : MeHeader() {
    *this = ::std::move(from);
  }

  inline MeHeader& operator=(MeHeader&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MeHeader& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MeHeader* internal_default_instance() {
    return reinterpret_cast<const MeHeader*>(
               &_MeHeader_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(MeHeader* other);
  friend void swap(MeHeader& a, MeHeader& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MeHeader* New() const final {
    return CreateMaybeMessage<MeHeader>(NULL);
  }

  MeHeader* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MeHeader>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MeHeader& from);
  void MergeFrom(const MeHeader& from);
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
  void InternalSwap(MeHeader* other);
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

  // uint32 hazard_num = 6;
  void clear_hazard_num();
  static const int kHazardNumFieldNumber = 6;
  ::google::protobuf::uint32 hazard_num() const;
  void set_hazard_num(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:camera_me_failsafe.proto.MeHeader)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint64 timestamp_;
  ::google::protobuf::uint32 rolling_counter_;
  ::google::protobuf::uint32 sensor_id_;
  ::google::protobuf::uint32 obj_num_;
  ::google::protobuf::uint32 line_num_;
  ::google::protobuf::uint32 hazard_num_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_camera_5fme_5ffailsafe_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class MeFailSafe : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:camera_me_failsafe.proto.MeFailSafe) */ {
 public:
  MeFailSafe();
  virtual ~MeFailSafe();

  MeFailSafe(const MeFailSafe& from);

  inline MeFailSafe& operator=(const MeFailSafe& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MeFailSafe(MeFailSafe&& from) noexcept
    : MeFailSafe() {
    *this = ::std::move(from);
  }

  inline MeFailSafe& operator=(MeFailSafe&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MeFailSafe& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const MeFailSafe* internal_default_instance() {
    return reinterpret_cast<const MeFailSafe*>(
               &_MeFailSafe_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(MeFailSafe* other);
  friend void swap(MeFailSafe& a, MeFailSafe& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MeFailSafe* New() const final {
    return CreateMaybeMessage<MeFailSafe>(NULL);
  }

  MeFailSafe* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<MeFailSafe>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const MeFailSafe& from);
  void MergeFrom(const MeFailSafe& from);
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
  void InternalSwap(MeFailSafe* other);
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

  // uint32 frame_id = 1;
  void clear_frame_id();
  static const int kFrameIdFieldNumber = 1;
  ::google::protobuf::uint32 frame_id() const;
  void set_frame_id(::google::protobuf::uint32 value);

  // uint32 free_sight = 2;
  void clear_free_sight();
  static const int kFreeSightFieldNumber = 2;
  ::google::protobuf::uint32 free_sight() const;
  void set_free_sight(::google::protobuf::uint32 value);

  // uint32 rain = 3;
  void clear_rain();
  static const int kRainFieldNumber = 3;
  ::google::protobuf::uint32 rain() const;
  void set_rain(::google::protobuf::uint32 value);

  // uint32 fog = 4;
  void clear_fog();
  static const int kFogFieldNumber = 4;
  ::google::protobuf::uint32 fog() const;
  void set_fog(::google::protobuf::uint32 value);

  // uint32 sun_ray = 5;
  void clear_sun_ray();
  static const int kSunRayFieldNumber = 5;
  ::google::protobuf::uint32 sun_ray() const;
  void set_sun_ray(::google::protobuf::uint32 value);

  // uint32 low_sun = 6;
  void clear_low_sun();
  static const int kLowSunFieldNumber = 6;
  ::google::protobuf::uint32 low_sun() const;
  void set_low_sun(::google::protobuf::uint32 value);

  // uint32 blur_image = 7;
  void clear_blur_image();
  static const int kBlurImageFieldNumber = 7;
  ::google::protobuf::uint32 blur_image() const;
  void set_blur_image(::google::protobuf::uint32 value);

  // uint32 partial_blockage = 8;
  void clear_partial_blockage();
  static const int kPartialBlockageFieldNumber = 8;
  ::google::protobuf::uint32 partial_blockage() const;
  void set_partial_blockage(::google::protobuf::uint32 value);

  // uint32 full_blockage = 9;
  void clear_full_blockage();
  static const int kFullBlockageFieldNumber = 9;
  ::google::protobuf::uint32 full_blockage() const;
  void set_full_blockage(::google::protobuf::uint32 value);

  // uint32 frozen_windshield = 10;
  void clear_frozen_windshield();
  static const int kFrozenWindshieldFieldNumber = 10;
  ::google::protobuf::uint32 frozen_windshield() const;
  void set_frozen_windshield(::google::protobuf::uint32 value);

  // uint32 out_of_calib = 11;
  void clear_out_of_calib();
  static const int kOutOfCalibFieldNumber = 11;
  ::google::protobuf::uint32 out_of_calib() const;
  void set_out_of_calib(::google::protobuf::uint32 value);

  // uint32 out_of_focus = 12;
  void clear_out_of_focus();
  static const int kOutOfFocusFieldNumber = 12;
  ::google::protobuf::uint32 out_of_focus() const;
  void set_out_of_focus(::google::protobuf::uint32 value);

  // uint32 tsr_out_of_calib = 13;
  void clear_tsr_out_of_calib();
  static const int kTsrOutOfCalibFieldNumber = 13;
  ::google::protobuf::uint32 tsr_out_of_calib() const;
  void set_tsr_out_of_calib(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:camera_me_failsafe.proto.MeFailSafe)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 frame_id_;
  ::google::protobuf::uint32 free_sight_;
  ::google::protobuf::uint32 rain_;
  ::google::protobuf::uint32 fog_;
  ::google::protobuf::uint32 sun_ray_;
  ::google::protobuf::uint32 low_sun_;
  ::google::protobuf::uint32 blur_image_;
  ::google::protobuf::uint32 partial_blockage_;
  ::google::protobuf::uint32 full_blockage_;
  ::google::protobuf::uint32 frozen_windshield_;
  ::google::protobuf::uint32 out_of_calib_;
  ::google::protobuf::uint32 out_of_focus_;
  ::google::protobuf::uint32 tsr_out_of_calib_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_camera_5fme_5ffailsafe_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class me_frame_fs : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:camera_me_failsafe.proto.me_frame_fs) */ {
 public:
  me_frame_fs();
  virtual ~me_frame_fs();

  me_frame_fs(const me_frame_fs& from);

  inline me_frame_fs& operator=(const me_frame_fs& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  me_frame_fs(me_frame_fs&& from) noexcept
    : me_frame_fs() {
    *this = ::std::move(from);
  }

  inline me_frame_fs& operator=(me_frame_fs&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const me_frame_fs& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const me_frame_fs* internal_default_instance() {
    return reinterpret_cast<const me_frame_fs*>(
               &_me_frame_fs_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(me_frame_fs* other);
  friend void swap(me_frame_fs& a, me_frame_fs& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline me_frame_fs* New() const final {
    return CreateMaybeMessage<me_frame_fs>(NULL);
  }

  me_frame_fs* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<me_frame_fs>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const me_frame_fs& from);
  void MergeFrom(const me_frame_fs& from);
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
  void InternalSwap(me_frame_fs* other);
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

  // .camera_me_failsafe.proto.MeHeader header = 1;
  bool has_header() const;
  void clear_header();
  static const int kHeaderFieldNumber = 1;
  private:
  const ::camera_me_failsafe::proto::MeHeader& _internal_header() const;
  public:
  const ::camera_me_failsafe::proto::MeHeader& header() const;
  ::camera_me_failsafe::proto::MeHeader* release_header();
  ::camera_me_failsafe::proto::MeHeader* mutable_header();
  void set_allocated_header(::camera_me_failsafe::proto::MeHeader* header);

  // .camera_me_failsafe.proto.MeFailSafe fail_safe = 3;
  bool has_fail_safe() const;
  void clear_fail_safe();
  static const int kFailSafeFieldNumber = 3;
  private:
  const ::camera_me_failsafe::proto::MeFailSafe& _internal_fail_safe() const;
  public:
  const ::camera_me_failsafe::proto::MeFailSafe& fail_safe() const;
  ::camera_me_failsafe::proto::MeFailSafe* release_fail_safe();
  ::camera_me_failsafe::proto::MeFailSafe* mutable_fail_safe();
  void set_allocated_fail_safe(::camera_me_failsafe::proto::MeFailSafe* fail_safe);

  // uint64 timestamp = 2;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 2;
  ::google::protobuf::uint64 timestamp() const;
  void set_timestamp(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:camera_me_failsafe.proto.me_frame_fs)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::camera_me_failsafe::proto::MeHeader* header_;
  ::camera_me_failsafe::proto::MeFailSafe* fail_safe_;
  ::google::protobuf::uint64 timestamp_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_camera_5fme_5ffailsafe_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MeHeader

// uint64 timestamp = 1;
inline void MeHeader::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 MeHeader::timestamp() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.timestamp)
  return timestamp_;
}
inline void MeHeader::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.timestamp)
}

// uint32 rolling_counter = 2;
inline void MeHeader::clear_rolling_counter() {
  rolling_counter_ = 0u;
}
inline ::google::protobuf::uint32 MeHeader::rolling_counter() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.rolling_counter)
  return rolling_counter_;
}
inline void MeHeader::set_rolling_counter(::google::protobuf::uint32 value) {
  
  rolling_counter_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.rolling_counter)
}

// uint32 sensor_id = 3;
inline void MeHeader::clear_sensor_id() {
  sensor_id_ = 0u;
}
inline ::google::protobuf::uint32 MeHeader::sensor_id() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.sensor_id)
  return sensor_id_;
}
inline void MeHeader::set_sensor_id(::google::protobuf::uint32 value) {
  
  sensor_id_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.sensor_id)
}

// uint32 obj_num = 4;
inline void MeHeader::clear_obj_num() {
  obj_num_ = 0u;
}
inline ::google::protobuf::uint32 MeHeader::obj_num() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.obj_num)
  return obj_num_;
}
inline void MeHeader::set_obj_num(::google::protobuf::uint32 value) {
  
  obj_num_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.obj_num)
}

// uint32 line_num = 5;
inline void MeHeader::clear_line_num() {
  line_num_ = 0u;
}
inline ::google::protobuf::uint32 MeHeader::line_num() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.line_num)
  return line_num_;
}
inline void MeHeader::set_line_num(::google::protobuf::uint32 value) {
  
  line_num_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.line_num)
}

// uint32 hazard_num = 6;
inline void MeHeader::clear_hazard_num() {
  hazard_num_ = 0u;
}
inline ::google::protobuf::uint32 MeHeader::hazard_num() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeHeader.hazard_num)
  return hazard_num_;
}
inline void MeHeader::set_hazard_num(::google::protobuf::uint32 value) {
  
  hazard_num_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeHeader.hazard_num)
}

// -------------------------------------------------------------------

// MeFailSafe

// uint32 frame_id = 1;
inline void MeFailSafe::clear_frame_id() {
  frame_id_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::frame_id() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.frame_id)
  return frame_id_;
}
inline void MeFailSafe::set_frame_id(::google::protobuf::uint32 value) {
  
  frame_id_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.frame_id)
}

// uint32 free_sight = 2;
inline void MeFailSafe::clear_free_sight() {
  free_sight_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::free_sight() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.free_sight)
  return free_sight_;
}
inline void MeFailSafe::set_free_sight(::google::protobuf::uint32 value) {
  
  free_sight_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.free_sight)
}

// uint32 rain = 3;
inline void MeFailSafe::clear_rain() {
  rain_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::rain() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.rain)
  return rain_;
}
inline void MeFailSafe::set_rain(::google::protobuf::uint32 value) {
  
  rain_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.rain)
}

// uint32 fog = 4;
inline void MeFailSafe::clear_fog() {
  fog_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::fog() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.fog)
  return fog_;
}
inline void MeFailSafe::set_fog(::google::protobuf::uint32 value) {
  
  fog_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.fog)
}

// uint32 sun_ray = 5;
inline void MeFailSafe::clear_sun_ray() {
  sun_ray_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::sun_ray() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.sun_ray)
  return sun_ray_;
}
inline void MeFailSafe::set_sun_ray(::google::protobuf::uint32 value) {
  
  sun_ray_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.sun_ray)
}

// uint32 low_sun = 6;
inline void MeFailSafe::clear_low_sun() {
  low_sun_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::low_sun() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.low_sun)
  return low_sun_;
}
inline void MeFailSafe::set_low_sun(::google::protobuf::uint32 value) {
  
  low_sun_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.low_sun)
}

// uint32 blur_image = 7;
inline void MeFailSafe::clear_blur_image() {
  blur_image_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::blur_image() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.blur_image)
  return blur_image_;
}
inline void MeFailSafe::set_blur_image(::google::protobuf::uint32 value) {
  
  blur_image_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.blur_image)
}

// uint32 partial_blockage = 8;
inline void MeFailSafe::clear_partial_blockage() {
  partial_blockage_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::partial_blockage() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.partial_blockage)
  return partial_blockage_;
}
inline void MeFailSafe::set_partial_blockage(::google::protobuf::uint32 value) {
  
  partial_blockage_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.partial_blockage)
}

// uint32 full_blockage = 9;
inline void MeFailSafe::clear_full_blockage() {
  full_blockage_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::full_blockage() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.full_blockage)
  return full_blockage_;
}
inline void MeFailSafe::set_full_blockage(::google::protobuf::uint32 value) {
  
  full_blockage_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.full_blockage)
}

// uint32 frozen_windshield = 10;
inline void MeFailSafe::clear_frozen_windshield() {
  frozen_windshield_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::frozen_windshield() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.frozen_windshield)
  return frozen_windshield_;
}
inline void MeFailSafe::set_frozen_windshield(::google::protobuf::uint32 value) {
  
  frozen_windshield_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.frozen_windshield)
}

// uint32 out_of_calib = 11;
inline void MeFailSafe::clear_out_of_calib() {
  out_of_calib_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::out_of_calib() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.out_of_calib)
  return out_of_calib_;
}
inline void MeFailSafe::set_out_of_calib(::google::protobuf::uint32 value) {
  
  out_of_calib_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.out_of_calib)
}

// uint32 out_of_focus = 12;
inline void MeFailSafe::clear_out_of_focus() {
  out_of_focus_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::out_of_focus() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.out_of_focus)
  return out_of_focus_;
}
inline void MeFailSafe::set_out_of_focus(::google::protobuf::uint32 value) {
  
  out_of_focus_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.out_of_focus)
}

// uint32 tsr_out_of_calib = 13;
inline void MeFailSafe::clear_tsr_out_of_calib() {
  tsr_out_of_calib_ = 0u;
}
inline ::google::protobuf::uint32 MeFailSafe::tsr_out_of_calib() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.MeFailSafe.tsr_out_of_calib)
  return tsr_out_of_calib_;
}
inline void MeFailSafe::set_tsr_out_of_calib(::google::protobuf::uint32 value) {
  
  tsr_out_of_calib_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.MeFailSafe.tsr_out_of_calib)
}

// -------------------------------------------------------------------

// me_frame_fs

// .camera_me_failsafe.proto.MeHeader header = 1;
inline bool me_frame_fs::has_header() const {
  return this != internal_default_instance() && header_ != NULL;
}
inline void me_frame_fs::clear_header() {
  if (GetArenaNoVirtual() == NULL && header_ != NULL) {
    delete header_;
  }
  header_ = NULL;
}
inline const ::camera_me_failsafe::proto::MeHeader& me_frame_fs::_internal_header() const {
  return *header_;
}
inline const ::camera_me_failsafe::proto::MeHeader& me_frame_fs::header() const {
  const ::camera_me_failsafe::proto::MeHeader* p = header_;
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.me_frame_fs.header)
  return p != NULL ? *p : *reinterpret_cast<const ::camera_me_failsafe::proto::MeHeader*>(
      &::camera_me_failsafe::proto::_MeHeader_default_instance_);
}
inline ::camera_me_failsafe::proto::MeHeader* me_frame_fs::release_header() {
  // @@protoc_insertion_point(field_release:camera_me_failsafe.proto.me_frame_fs.header)
  
  ::camera_me_failsafe::proto::MeHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline ::camera_me_failsafe::proto::MeHeader* me_frame_fs::mutable_header() {
  
  if (header_ == NULL) {
    auto* p = CreateMaybeMessage<::camera_me_failsafe::proto::MeHeader>(GetArenaNoVirtual());
    header_ = p;
  }
  // @@protoc_insertion_point(field_mutable:camera_me_failsafe.proto.me_frame_fs.header)
  return header_;
}
inline void me_frame_fs::set_allocated_header(::camera_me_failsafe::proto::MeHeader* header) {
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
  // @@protoc_insertion_point(field_set_allocated:camera_me_failsafe.proto.me_frame_fs.header)
}

// uint64 timestamp = 2;
inline void me_frame_fs::clear_timestamp() {
  timestamp_ = GOOGLE_ULONGLONG(0);
}
inline ::google::protobuf::uint64 me_frame_fs::timestamp() const {
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.me_frame_fs.timestamp)
  return timestamp_;
}
inline void me_frame_fs::set_timestamp(::google::protobuf::uint64 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:camera_me_failsafe.proto.me_frame_fs.timestamp)
}

// .camera_me_failsafe.proto.MeFailSafe fail_safe = 3;
inline bool me_frame_fs::has_fail_safe() const {
  return this != internal_default_instance() && fail_safe_ != NULL;
}
inline void me_frame_fs::clear_fail_safe() {
  if (GetArenaNoVirtual() == NULL && fail_safe_ != NULL) {
    delete fail_safe_;
  }
  fail_safe_ = NULL;
}
inline const ::camera_me_failsafe::proto::MeFailSafe& me_frame_fs::_internal_fail_safe() const {
  return *fail_safe_;
}
inline const ::camera_me_failsafe::proto::MeFailSafe& me_frame_fs::fail_safe() const {
  const ::camera_me_failsafe::proto::MeFailSafe* p = fail_safe_;
  // @@protoc_insertion_point(field_get:camera_me_failsafe.proto.me_frame_fs.fail_safe)
  return p != NULL ? *p : *reinterpret_cast<const ::camera_me_failsafe::proto::MeFailSafe*>(
      &::camera_me_failsafe::proto::_MeFailSafe_default_instance_);
}
inline ::camera_me_failsafe::proto::MeFailSafe* me_frame_fs::release_fail_safe() {
  // @@protoc_insertion_point(field_release:camera_me_failsafe.proto.me_frame_fs.fail_safe)
  
  ::camera_me_failsafe::proto::MeFailSafe* temp = fail_safe_;
  fail_safe_ = NULL;
  return temp;
}
inline ::camera_me_failsafe::proto::MeFailSafe* me_frame_fs::mutable_fail_safe() {
  
  if (fail_safe_ == NULL) {
    auto* p = CreateMaybeMessage<::camera_me_failsafe::proto::MeFailSafe>(GetArenaNoVirtual());
    fail_safe_ = p;
  }
  // @@protoc_insertion_point(field_mutable:camera_me_failsafe.proto.me_frame_fs.fail_safe)
  return fail_safe_;
}
inline void me_frame_fs::set_allocated_fail_safe(::camera_me_failsafe::proto::MeFailSafe* fail_safe) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete fail_safe_;
  }
  if (fail_safe) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      fail_safe = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, fail_safe, submessage_arena);
    }
    
  } else {
    
  }
  fail_safe_ = fail_safe;
  // @@protoc_insertion_point(field_set_allocated:camera_me_failsafe.proto.me_frame_fs.fail_safe)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace camera_me_failsafe

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_camera_5fme_5ffailsafe_2eproto
