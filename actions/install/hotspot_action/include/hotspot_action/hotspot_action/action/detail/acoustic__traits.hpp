// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hotspot_action:action/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__TRAITS_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hotspot_action/action/detail/acoustic__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: take_ac_reading
  {
    out << "take_ac_reading: ";
    rosidl_generator_traits::value_to_yaml(msg.take_ac_reading, out);
    out << ", ";
  }

  // member: measurement_point
  {
    out << "measurement_point: ";
    rosidl_generator_traits::value_to_yaml(msg.measurement_point, out);
    out << ", ";
  }

  // member: pan_position
  {
    out << "pan_position: ";
    rosidl_generator_traits::value_to_yaml(msg.pan_position, out);
    out << ", ";
  }

  // member: tilt_position
  {
    out << "tilt_position: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: take_ac_reading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "take_ac_reading: ";
    rosidl_generator_traits::value_to_yaml(msg.take_ac_reading, out);
    out << "\n";
  }

  // member: measurement_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "measurement_point: ";
    rosidl_generator_traits::value_to_yaml(msg.measurement_point, out);
    out << "\n";
  }

  // member: pan_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pan_position: ";
    rosidl_generator_traits::value_to_yaml(msg.pan_position, out);
    out << "\n";
  }

  // member: tilt_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_position: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_Goal & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_Goal>()
{
  return "hotspot_action::action::Acoustic_Goal";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_Goal>()
{
  return "hotspot_action/action/Acoustic_Goal";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hotspot_action::action::Acoustic_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: ac_save_path
  {
    out << "ac_save_path: ";
    rosidl_generator_traits::value_to_yaml(msg.ac_save_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ac_save_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ac_save_path: ";
    rosidl_generator_traits::value_to_yaml(msg.ac_save_path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_Result & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_Result>()
{
  return "hotspot_action::action::Acoustic_Result";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_Result>()
{
  return "hotspot_action/action/Acoustic_Result";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<hotspot_action::action::Acoustic_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_Feedback & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_Feedback & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_Feedback>()
{
  return "hotspot_action::action::Acoustic_Feedback";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_Feedback>()
{
  return "hotspot_action/action/Acoustic_Feedback";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hotspot_action::action::Acoustic_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "hotspot_action/action/detail/acoustic__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_SendGoal_Request & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_SendGoal_Request>()
{
  return "hotspot_action::action::Acoustic_SendGoal_Request";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_SendGoal_Request>()
{
  return "hotspot_action/action/Acoustic_SendGoal_Request";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::Acoustic_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::Acoustic_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::Acoustic_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_SendGoal_Response & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_SendGoal_Response>()
{
  return "hotspot_action::action::Acoustic_SendGoal_Response";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_SendGoal_Response>()
{
  return "hotspot_action/action/Acoustic_SendGoal_Response";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<hotspot_action::action::Acoustic_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hotspot_action::action::Acoustic_SendGoal>()
{
  return "hotspot_action::action::Acoustic_SendGoal";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_SendGoal>()
{
  return "hotspot_action/action/Acoustic_SendGoal";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<hotspot_action::action::Acoustic_SendGoal_Request>::value &&
    has_fixed_size<hotspot_action::action::Acoustic_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<hotspot_action::action::Acoustic_SendGoal_Request>::value &&
    has_bounded_size<hotspot_action::action::Acoustic_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<hotspot_action::action::Acoustic_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<hotspot_action::action::Acoustic_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hotspot_action::action::Acoustic_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_GetResult_Request & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_GetResult_Request>()
{
  return "hotspot_action::action::Acoustic_GetResult_Request";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_GetResult_Request>()
{
  return "hotspot_action/action/Acoustic_GetResult_Request";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::Acoustic_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "hotspot_action/action/detail/acoustic__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_GetResult_Response & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_GetResult_Response>()
{
  return "hotspot_action::action::Acoustic_GetResult_Response";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_GetResult_Response>()
{
  return "hotspot_action/action/Acoustic_GetResult_Response";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::Acoustic_Result>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::Acoustic_Result>::value> {};

template<>
struct is_message<hotspot_action::action::Acoustic_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hotspot_action::action::Acoustic_GetResult>()
{
  return "hotspot_action::action::Acoustic_GetResult";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_GetResult>()
{
  return "hotspot_action/action/Acoustic_GetResult";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<hotspot_action::action::Acoustic_GetResult_Request>::value &&
    has_fixed_size<hotspot_action::action::Acoustic_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<hotspot_action::action::Acoustic_GetResult_Request>::value &&
    has_bounded_size<hotspot_action::action::Acoustic_GetResult_Response>::value
  >
{
};

template<>
struct is_service<hotspot_action::action::Acoustic_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<hotspot_action::action::Acoustic_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hotspot_action::action::Acoustic_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "hotspot_action/action/detail/acoustic__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const Acoustic_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustic_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Acoustic_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace hotspot_action

namespace rosidl_generator_traits
{

[[deprecated("use hotspot_action::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const hotspot_action::action::Acoustic_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::Acoustic_FeedbackMessage & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::Acoustic_FeedbackMessage>()
{
  return "hotspot_action::action::Acoustic_FeedbackMessage";
}

template<>
inline const char * name<hotspot_action::action::Acoustic_FeedbackMessage>()
{
  return "hotspot_action/action/Acoustic_FeedbackMessage";
}

template<>
struct has_fixed_size<hotspot_action::action::Acoustic_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::Acoustic_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::Acoustic_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::Acoustic_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::Acoustic_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<hotspot_action::action::Acoustic>
  : std::true_type
{
};

template<>
struct is_action_goal<hotspot_action::action::Acoustic_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<hotspot_action::action::Acoustic_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<hotspot_action::action::Acoustic_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__TRAITS_HPP_
