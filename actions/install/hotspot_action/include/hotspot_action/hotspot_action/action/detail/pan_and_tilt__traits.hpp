// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from hotspot_action:action/PanAndTilt.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__TRAITS_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "hotspot_action/action/detail/pan_and_tilt__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: pan
  {
    out << "pan: ";
    rosidl_generator_traits::value_to_yaml(msg.pan, out);
    out << ", ";
  }

  // member: tilt
  {
    out << "tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PanAndTilt_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pan: ";
    rosidl_generator_traits::value_to_yaml(msg.pan, out);
    out << "\n";
  }

  // member: tilt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PanAndTilt_Goal & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_Goal & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_Goal>()
{
  return "hotspot_action::action::PanAndTilt_Goal";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_Goal>()
{
  return "hotspot_action/action/PanAndTilt_Goal";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: move_finished
  {
    out << "move_finished: ";
    rosidl_generator_traits::value_to_yaml(msg.move_finished, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PanAndTilt_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: move_finished
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "move_finished: ";
    rosidl_generator_traits::value_to_yaml(msg.move_finished, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PanAndTilt_Result & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_Result & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_Result>()
{
  return "hotspot_action::action::PanAndTilt_Result";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_Result>()
{
  return "hotspot_action/action/PanAndTilt_Result";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: pan_feedback
  {
    out << "pan_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.pan_feedback, out);
    out << ", ";
  }

  // member: tilt_feedback
  {
    out << "tilt_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PanAndTilt_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pan_feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pan_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.pan_feedback, out);
    out << "\n";
  }

  // member: tilt_feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tilt_feedback: ";
    rosidl_generator_traits::value_to_yaml(msg.tilt_feedback, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PanAndTilt_Feedback & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_Feedback & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_Feedback>()
{
  return "hotspot_action::action::PanAndTilt_Feedback";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_Feedback>()
{
  return "hotspot_action/action/PanAndTilt_Feedback";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "hotspot_action/action/detail/pan_and_tilt__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_SendGoal_Request & msg,
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
  const PanAndTilt_SendGoal_Request & msg,
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

inline std::string to_yaml(const PanAndTilt_SendGoal_Request & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_SendGoal_Request & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_SendGoal_Request>()
{
  return "hotspot_action::action::PanAndTilt_SendGoal_Request";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_SendGoal_Request>()
{
  return "hotspot_action/action/PanAndTilt_SendGoal_Request";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::PanAndTilt_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::PanAndTilt_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_SendGoal_Request>
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
  const PanAndTilt_SendGoal_Response & msg,
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
  const PanAndTilt_SendGoal_Response & msg,
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

inline std::string to_yaml(const PanAndTilt_SendGoal_Response & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_SendGoal_Response & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_SendGoal_Response>()
{
  return "hotspot_action::action::PanAndTilt_SendGoal_Response";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_SendGoal_Response>()
{
  return "hotspot_action/action/PanAndTilt_SendGoal_Response";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_SendGoal>()
{
  return "hotspot_action::action::PanAndTilt_SendGoal";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_SendGoal>()
{
  return "hotspot_action/action/PanAndTilt_SendGoal";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<hotspot_action::action::PanAndTilt_SendGoal_Request>::value &&
    has_fixed_size<hotspot_action::action::PanAndTilt_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<hotspot_action::action::PanAndTilt_SendGoal_Request>::value &&
    has_bounded_size<hotspot_action::action::PanAndTilt_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<hotspot_action::action::PanAndTilt_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<hotspot_action::action::PanAndTilt_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hotspot_action::action::PanAndTilt_SendGoal_Response>
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
  const PanAndTilt_GetResult_Request & msg,
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
  const PanAndTilt_GetResult_Request & msg,
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

inline std::string to_yaml(const PanAndTilt_GetResult_Request & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_GetResult_Request & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_GetResult_Request>()
{
  return "hotspot_action::action::PanAndTilt_GetResult_Request";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_GetResult_Request>()
{
  return "hotspot_action/action/PanAndTilt_GetResult_Request";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_GetResult_Response & msg,
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
  const PanAndTilt_GetResult_Response & msg,
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

inline std::string to_yaml(const PanAndTilt_GetResult_Response & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_GetResult_Response & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_GetResult_Response>()
{
  return "hotspot_action::action::PanAndTilt_GetResult_Response";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_GetResult_Response>()
{
  return "hotspot_action/action/PanAndTilt_GetResult_Response";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::PanAndTilt_Result>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::PanAndTilt_Result>::value> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_GetResult>()
{
  return "hotspot_action::action::PanAndTilt_GetResult";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_GetResult>()
{
  return "hotspot_action/action/PanAndTilt_GetResult";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<hotspot_action::action::PanAndTilt_GetResult_Request>::value &&
    has_fixed_size<hotspot_action::action::PanAndTilt_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<hotspot_action::action::PanAndTilt_GetResult_Request>::value &&
    has_bounded_size<hotspot_action::action::PanAndTilt_GetResult_Response>::value
  >
{
};

template<>
struct is_service<hotspot_action::action::PanAndTilt_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<hotspot_action::action::PanAndTilt_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<hotspot_action::action::PanAndTilt_GetResult_Response>
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
// #include "hotspot_action/action/detail/pan_and_tilt__traits.hpp"

namespace hotspot_action
{

namespace action
{

inline void to_flow_style_yaml(
  const PanAndTilt_FeedbackMessage & msg,
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
  const PanAndTilt_FeedbackMessage & msg,
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

inline std::string to_yaml(const PanAndTilt_FeedbackMessage & msg, bool use_flow_style = false)
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
  const hotspot_action::action::PanAndTilt_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  hotspot_action::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use hotspot_action::action::to_yaml() instead")]]
inline std::string to_yaml(const hotspot_action::action::PanAndTilt_FeedbackMessage & msg)
{
  return hotspot_action::action::to_yaml(msg);
}

template<>
inline const char * data_type<hotspot_action::action::PanAndTilt_FeedbackMessage>()
{
  return "hotspot_action::action::PanAndTilt_FeedbackMessage";
}

template<>
inline const char * name<hotspot_action::action::PanAndTilt_FeedbackMessage>()
{
  return "hotspot_action/action/PanAndTilt_FeedbackMessage";
}

template<>
struct has_fixed_size<hotspot_action::action::PanAndTilt_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<hotspot_action::action::PanAndTilt_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<hotspot_action::action::PanAndTilt_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<hotspot_action::action::PanAndTilt_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<hotspot_action::action::PanAndTilt_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<hotspot_action::action::PanAndTilt>
  : std::true_type
{
};

template<>
struct is_action_goal<hotspot_action::action::PanAndTilt_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<hotspot_action::action::PanAndTilt_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<hotspot_action::action::PanAndTilt_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__TRAITS_HPP_
