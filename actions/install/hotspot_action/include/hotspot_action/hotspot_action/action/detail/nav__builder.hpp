// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hotspot_action:action/Nav.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__NAV__BUILDER_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__NAV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hotspot_action/action/detail/nav__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_Goal_coordinate_y
{
public:
  explicit Init_Nav_Goal_coordinate_y(::hotspot_action::action::Nav_Goal & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Nav_Goal coordinate_y(::hotspot_action::action::Nav_Goal::_coordinate_y_type arg)
  {
    msg_.coordinate_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_Goal msg_;
};

class Init_Nav_Goal_coordinate_x
{
public:
  Init_Nav_Goal_coordinate_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_Goal_coordinate_y coordinate_x(::hotspot_action::action::Nav_Goal::_coordinate_x_type arg)
  {
    msg_.coordinate_x = std::move(arg);
    return Init_Nav_Goal_coordinate_y(msg_);
  }

private:
  ::hotspot_action::action::Nav_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_Goal>()
{
  return hotspot_action::action::builder::Init_Nav_Goal_coordinate_x();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_Result_mp_reached
{
public:
  Init_Nav_Result_mp_reached()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::Nav_Result mp_reached(::hotspot_action::action::Nav_Result::_mp_reached_type arg)
  {
    msg_.mp_reached = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_Result>()
{
  return hotspot_action::action::builder::Init_Nav_Result_mp_reached();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_Feedback_time_to_mp
{
public:
  Init_Nav_Feedback_time_to_mp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::Nav_Feedback time_to_mp(::hotspot_action::action::Nav_Feedback::_time_to_mp_type arg)
  {
    msg_.time_to_mp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_Feedback>()
{
  return hotspot_action::action::builder::Init_Nav_Feedback_time_to_mp();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_SendGoal_Request_goal
{
public:
  explicit Init_Nav_SendGoal_Request_goal(::hotspot_action::action::Nav_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Nav_SendGoal_Request goal(::hotspot_action::action::Nav_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_SendGoal_Request msg_;
};

class Init_Nav_SendGoal_Request_goal_id
{
public:
  Init_Nav_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_SendGoal_Request_goal goal_id(::hotspot_action::action::Nav_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Nav_SendGoal_Request_goal(msg_);
  }

private:
  ::hotspot_action::action::Nav_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_SendGoal_Request>()
{
  return hotspot_action::action::builder::Init_Nav_SendGoal_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_SendGoal_Response_stamp
{
public:
  explicit Init_Nav_SendGoal_Response_stamp(::hotspot_action::action::Nav_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Nav_SendGoal_Response stamp(::hotspot_action::action::Nav_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_SendGoal_Response msg_;
};

class Init_Nav_SendGoal_Response_accepted
{
public:
  Init_Nav_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_SendGoal_Response_stamp accepted(::hotspot_action::action::Nav_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Nav_SendGoal_Response_stamp(msg_);
  }

private:
  ::hotspot_action::action::Nav_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_SendGoal_Response>()
{
  return hotspot_action::action::builder::Init_Nav_SendGoal_Response_accepted();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_GetResult_Request_goal_id
{
public:
  Init_Nav_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::Nav_GetResult_Request goal_id(::hotspot_action::action::Nav_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_GetResult_Request>()
{
  return hotspot_action::action::builder::Init_Nav_GetResult_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_GetResult_Response_result
{
public:
  explicit Init_Nav_GetResult_Response_result(::hotspot_action::action::Nav_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Nav_GetResult_Response result(::hotspot_action::action::Nav_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_GetResult_Response msg_;
};

class Init_Nav_GetResult_Response_status
{
public:
  Init_Nav_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_GetResult_Response_result status(::hotspot_action::action::Nav_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Nav_GetResult_Response_result(msg_);
  }

private:
  ::hotspot_action::action::Nav_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_GetResult_Response>()
{
  return hotspot_action::action::builder::Init_Nav_GetResult_Response_status();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Nav_FeedbackMessage_feedback
{
public:
  explicit Init_Nav_FeedbackMessage_feedback(::hotspot_action::action::Nav_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Nav_FeedbackMessage feedback(::hotspot_action::action::Nav_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Nav_FeedbackMessage msg_;
};

class Init_Nav_FeedbackMessage_goal_id
{
public:
  Init_Nav_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Nav_FeedbackMessage_feedback goal_id(::hotspot_action::action::Nav_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Nav_FeedbackMessage_feedback(msg_);
  }

private:
  ::hotspot_action::action::Nav_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Nav_FeedbackMessage>()
{
  return hotspot_action::action::builder::Init_Nav_FeedbackMessage_goal_id();
}

}  // namespace hotspot_action

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__NAV__BUILDER_HPP_
