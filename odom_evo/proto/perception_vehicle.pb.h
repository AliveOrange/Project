// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: perception_vehicle.proto

#ifndef PROTOBUF_INCLUDED_perception_5fvehicle_2eproto
#define PROTOBUF_INCLUDED_perception_5fvehicle_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_perception_5fvehicle_2eproto 

namespace protobuf_perception_5fvehicle_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_perception_5fvehicle_2eproto
namespace calmcar {
namespace perception {
class DashBoard;
class DashBoardDefaultTypeInternal;
extern DashBoardDefaultTypeInternal _DashBoard_default_instance_;
class Vehicle;
class VehicleDefaultTypeInternal;
extern VehicleDefaultTypeInternal _Vehicle_default_instance_;
}  // namespace perception
}  // namespace calmcar
namespace google {
namespace protobuf {
template<> ::calmcar::perception::DashBoard* Arena::CreateMaybeMessage<::calmcar::perception::DashBoard>(Arena*);
template<> ::calmcar::perception::Vehicle* Arena::CreateMaybeMessage<::calmcar::perception::Vehicle>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace calmcar {
namespace perception {

// ===================================================================

class DashBoard : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:calmcar.perception.DashBoard) */ {
 public:
  DashBoard();
  virtual ~DashBoard();

  DashBoard(const DashBoard& from);

  inline DashBoard& operator=(const DashBoard& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DashBoard(DashBoard&& from) noexcept
    : DashBoard() {
    *this = ::std::move(from);
  }

  inline DashBoard& operator=(DashBoard&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DashBoard& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DashBoard* internal_default_instance() {
    return reinterpret_cast<const DashBoard*>(
               &_DashBoard_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(DashBoard* other);
  friend void swap(DashBoard& a, DashBoard& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DashBoard* New() const final {
    return CreateMaybeMessage<DashBoard>(NULL);
  }

  DashBoard* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DashBoard>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DashBoard& from);
  void MergeFrom(const DashBoard& from);
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
  void InternalSwap(DashBoard* other);
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

  // float speed_mps = 1;
  void clear_speed_mps();
  static const int kSpeedMpsFieldNumber = 1;
  float speed_mps() const;
  void set_speed_mps(float value);

  // float yaw_rate = 2;
  void clear_yaw_rate();
  static const int kYawRateFieldNumber = 2;
  float yaw_rate() const;
  void set_yaw_rate(float value);

  // @@protoc_insertion_point(class_scope:calmcar.perception.DashBoard)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  float speed_mps_;
  float yaw_rate_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_perception_5fvehicle_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Vehicle : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:calmcar.perception.Vehicle) */ {
 public:
  Vehicle();
  virtual ~Vehicle();

  Vehicle(const Vehicle& from);

  inline Vehicle& operator=(const Vehicle& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Vehicle(Vehicle&& from) noexcept
    : Vehicle() {
    *this = ::std::move(from);
  }

  inline Vehicle& operator=(Vehicle&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Vehicle& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Vehicle* internal_default_instance() {
    return reinterpret_cast<const Vehicle*>(
               &_Vehicle_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Vehicle* other);
  friend void swap(Vehicle& a, Vehicle& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Vehicle* New() const final {
    return CreateMaybeMessage<Vehicle>(NULL);
  }

  Vehicle* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Vehicle>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Vehicle& from);
  void MergeFrom(const Vehicle& from);
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
  void InternalSwap(Vehicle* other);
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

  // .calmcar.perception.DashBoard dash_board = 1;
  bool has_dash_board() const;
  void clear_dash_board();
  static const int kDashBoardFieldNumber = 1;
  private:
  const ::calmcar::perception::DashBoard& _internal_dash_board() const;
  public:
  const ::calmcar::perception::DashBoard& dash_board() const;
  ::calmcar::perception::DashBoard* release_dash_board();
  ::calmcar::perception::DashBoard* mutable_dash_board();
  void set_allocated_dash_board(::calmcar::perception::DashBoard* dash_board);

  // @@protoc_insertion_point(class_scope:calmcar.perception.Vehicle)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::calmcar::perception::DashBoard* dash_board_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_perception_5fvehicle_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DashBoard

// float speed_mps = 1;
inline void DashBoard::clear_speed_mps() {
  speed_mps_ = 0;
}
inline float DashBoard::speed_mps() const {
  // @@protoc_insertion_point(field_get:calmcar.perception.DashBoard.speed_mps)
  return speed_mps_;
}
inline void DashBoard::set_speed_mps(float value) {
  
  speed_mps_ = value;
  // @@protoc_insertion_point(field_set:calmcar.perception.DashBoard.speed_mps)
}

// float yaw_rate = 2;
inline void DashBoard::clear_yaw_rate() {
  yaw_rate_ = 0;
}
inline float DashBoard::yaw_rate() const {
  // @@protoc_insertion_point(field_get:calmcar.perception.DashBoard.yaw_rate)
  return yaw_rate_;
}
inline void DashBoard::set_yaw_rate(float value) {
  
  yaw_rate_ = value;
  // @@protoc_insertion_point(field_set:calmcar.perception.DashBoard.yaw_rate)
}

// -------------------------------------------------------------------

// Vehicle

// .calmcar.perception.DashBoard dash_board = 1;
inline bool Vehicle::has_dash_board() const {
  return this != internal_default_instance() && dash_board_ != NULL;
}
inline void Vehicle::clear_dash_board() {
  if (GetArenaNoVirtual() == NULL && dash_board_ != NULL) {
    delete dash_board_;
  }
  dash_board_ = NULL;
}
inline const ::calmcar::perception::DashBoard& Vehicle::_internal_dash_board() const {
  return *dash_board_;
}
inline const ::calmcar::perception::DashBoard& Vehicle::dash_board() const {
  const ::calmcar::perception::DashBoard* p = dash_board_;
  // @@protoc_insertion_point(field_get:calmcar.perception.Vehicle.dash_board)
  return p != NULL ? *p : *reinterpret_cast<const ::calmcar::perception::DashBoard*>(
      &::calmcar::perception::_DashBoard_default_instance_);
}
inline ::calmcar::perception::DashBoard* Vehicle::release_dash_board() {
  // @@protoc_insertion_point(field_release:calmcar.perception.Vehicle.dash_board)
  
  ::calmcar::perception::DashBoard* temp = dash_board_;
  dash_board_ = NULL;
  return temp;
}
inline ::calmcar::perception::DashBoard* Vehicle::mutable_dash_board() {
  
  if (dash_board_ == NULL) {
    auto* p = CreateMaybeMessage<::calmcar::perception::DashBoard>(GetArenaNoVirtual());
    dash_board_ = p;
  }
  // @@protoc_insertion_point(field_mutable:calmcar.perception.Vehicle.dash_board)
  return dash_board_;
}
inline void Vehicle::set_allocated_dash_board(::calmcar::perception::DashBoard* dash_board) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete dash_board_;
  }
  if (dash_board) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      dash_board = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, dash_board, submessage_arena);
    }
    
  } else {
    
  }
  dash_board_ = dash_board;
  // @@protoc_insertion_point(field_set_allocated:calmcar.perception.Vehicle.dash_board)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace perception
}  // namespace calmcar

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_perception_5fvehicle_2eproto