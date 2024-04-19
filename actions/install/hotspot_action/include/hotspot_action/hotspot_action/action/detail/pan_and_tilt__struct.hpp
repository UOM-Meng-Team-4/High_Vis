// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from hotspot_action:action/PanAndTilt.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_Goal __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_Goal __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_Goal_
{
  using Type = PanAndTilt_Goal_<ContainerAllocator>;

  explicit PanAndTilt_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan = 0.0;
      this->tilt = 0.0;
    }
  }

  explicit PanAndTilt_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan = 0.0;
      this->tilt = 0.0;
    }
  }

  // field types and members
  using _pan_type =
    double;
  _pan_type pan;
  using _tilt_type =
    double;
  _tilt_type tilt;

  // setters for named parameter idiom
  Type & set__pan(
    const double & _arg)
  {
    this->pan = _arg;
    return *this;
  }
  Type & set__tilt(
    const double & _arg)
  {
    this->tilt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Goal
    std::shared_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Goal
    std::shared_ptr<hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_Goal_ & other) const
  {
    if (this->pan != other.pan) {
      return false;
    }
    if (this->tilt != other.tilt) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_Goal_

// alias to use template instance with default allocator
using PanAndTilt_Goal =
  hotspot_action::action::PanAndTilt_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action


#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_Result __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_Result __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_Result_
{
  using Type = PanAndTilt_Result_<ContainerAllocator>;

  explicit PanAndTilt_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_finished = false;
    }
  }

  explicit PanAndTilt_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->move_finished = false;
    }
  }

  // field types and members
  using _move_finished_type =
    bool;
  _move_finished_type move_finished;

  // setters for named parameter idiom
  Type & set__move_finished(
    const bool & _arg)
  {
    this->move_finished = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Result
    std::shared_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Result
    std::shared_ptr<hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_Result_ & other) const
  {
    if (this->move_finished != other.move_finished) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_Result_

// alias to use template instance with default allocator
using PanAndTilt_Result =
  hotspot_action::action::PanAndTilt_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action


#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_Feedback __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_Feedback_
{
  using Type = PanAndTilt_Feedback_<ContainerAllocator>;

  explicit PanAndTilt_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan_feedback = 0.0;
      this->tilt_feedback = 0.0;
    }
  }

  explicit PanAndTilt_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pan_feedback = 0.0;
      this->tilt_feedback = 0.0;
    }
  }

  // field types and members
  using _pan_feedback_type =
    double;
  _pan_feedback_type pan_feedback;
  using _tilt_feedback_type =
    double;
  _tilt_feedback_type tilt_feedback;

  // setters for named parameter idiom
  Type & set__pan_feedback(
    const double & _arg)
  {
    this->pan_feedback = _arg;
    return *this;
  }
  Type & set__tilt_feedback(
    const double & _arg)
  {
    this->tilt_feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Feedback
    std::shared_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_Feedback
    std::shared_ptr<hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_Feedback_ & other) const
  {
    if (this->pan_feedback != other.pan_feedback) {
      return false;
    }
    if (this->tilt_feedback != other.tilt_feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_Feedback_

// alias to use template instance with default allocator
using PanAndTilt_Feedback =
  hotspot_action::action::PanAndTilt_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "hotspot_action/action/detail/pan_and_tilt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Request __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_SendGoal_Request_
{
  using Type = PanAndTilt_SendGoal_Request_<ContainerAllocator>;

  explicit PanAndTilt_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PanAndTilt_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const hotspot_action::action::PanAndTilt_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Request
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Request
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_SendGoal_Request_

// alias to use template instance with default allocator
using PanAndTilt_SendGoal_Request =
  hotspot_action::action::PanAndTilt_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Response __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_SendGoal_Response_
{
  using Type = PanAndTilt_SendGoal_Response_<ContainerAllocator>;

  explicit PanAndTilt_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PanAndTilt_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Response
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_SendGoal_Response
    std::shared_ptr<hotspot_action::action::PanAndTilt_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_SendGoal_Response_

// alias to use template instance with default allocator
using PanAndTilt_SendGoal_Response =
  hotspot_action::action::PanAndTilt_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action

namespace hotspot_action
{

namespace action
{

struct PanAndTilt_SendGoal
{
  using Request = hotspot_action::action::PanAndTilt_SendGoal_Request;
  using Response = hotspot_action::action::PanAndTilt_SendGoal_Response;
};

}  // namespace action

}  // namespace hotspot_action


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Request __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_GetResult_Request_
{
  using Type = PanAndTilt_GetResult_Request_<ContainerAllocator>;

  explicit PanAndTilt_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PanAndTilt_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Request
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Request
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_GetResult_Request_

// alias to use template instance with default allocator
using PanAndTilt_GetResult_Request =
  hotspot_action::action::PanAndTilt_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action


// Include directives for member types
// Member 'result'
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Response __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_GetResult_Response_
{
  using Type = PanAndTilt_GetResult_Response_<ContainerAllocator>;

  explicit PanAndTilt_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PanAndTilt_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    hotspot_action::action::PanAndTilt_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const hotspot_action::action::PanAndTilt_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Response
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_GetResult_Response
    std::shared_ptr<hotspot_action::action::PanAndTilt_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_GetResult_Response_

// alias to use template instance with default allocator
using PanAndTilt_GetResult_Response =
  hotspot_action::action::PanAndTilt_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action

namespace hotspot_action
{

namespace action
{

struct PanAndTilt_GetResult
{
  using Request = hotspot_action::action::PanAndTilt_GetResult_Request;
  using Response = hotspot_action::action::PanAndTilt_GetResult_Response;
};

}  // namespace action

}  // namespace hotspot_action


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__hotspot_action__action__PanAndTilt_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__hotspot_action__action__PanAndTilt_FeedbackMessage __declspec(deprecated)
#endif

namespace hotspot_action
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PanAndTilt_FeedbackMessage_
{
  using Type = PanAndTilt_FeedbackMessage_<ContainerAllocator>;

  explicit PanAndTilt_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PanAndTilt_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const hotspot_action::action::PanAndTilt_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_FeedbackMessage
    std::shared_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__hotspot_action__action__PanAndTilt_FeedbackMessage
    std::shared_ptr<hotspot_action::action::PanAndTilt_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PanAndTilt_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PanAndTilt_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PanAndTilt_FeedbackMessage_

// alias to use template instance with default allocator
using PanAndTilt_FeedbackMessage =
  hotspot_action::action::PanAndTilt_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace hotspot_action

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace hotspot_action
{

namespace action
{

struct PanAndTilt
{
  /// The goal message defined in the action definition.
  using Goal = hotspot_action::action::PanAndTilt_Goal;
  /// The result message defined in the action definition.
  using Result = hotspot_action::action::PanAndTilt_Result;
  /// The feedback message defined in the action definition.
  using Feedback = hotspot_action::action::PanAndTilt_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = hotspot_action::action::PanAndTilt_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = hotspot_action::action::PanAndTilt_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = hotspot_action::action::PanAndTilt_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PanAndTilt PanAndTilt;

}  // namespace action

}  // namespace hotspot_action

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_HPP_
