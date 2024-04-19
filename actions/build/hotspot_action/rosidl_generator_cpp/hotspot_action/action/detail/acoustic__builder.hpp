// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hotspot_action:action/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__BUILDER_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hotspot_action/action/detail/acoustic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_Goal_tilt_position
{
public:
  explicit Init_Acoustic_Goal_tilt_position(::hotspot_action::action::Acoustic_Goal & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Acoustic_Goal tilt_position(::hotspot_action::action::Acoustic_Goal::_tilt_position_type arg)
  {
    msg_.tilt_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_Goal msg_;
};

class Init_Acoustic_Goal_pan_position
{
public:
  explicit Init_Acoustic_Goal_pan_position(::hotspot_action::action::Acoustic_Goal & msg)
  : msg_(msg)
  {}
  Init_Acoustic_Goal_tilt_position pan_position(::hotspot_action::action::Acoustic_Goal::_pan_position_type arg)
  {
    msg_.pan_position = std::move(arg);
    return Init_Acoustic_Goal_tilt_position(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_Goal msg_;
};

class Init_Acoustic_Goal_measurement_point
{
public:
  explicit Init_Acoustic_Goal_measurement_point(::hotspot_action::action::Acoustic_Goal & msg)
  : msg_(msg)
  {}
  Init_Acoustic_Goal_pan_position measurement_point(::hotspot_action::action::Acoustic_Goal::_measurement_point_type arg)
  {
    msg_.measurement_point = std::move(arg);
    return Init_Acoustic_Goal_pan_position(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_Goal msg_;
};

class Init_Acoustic_Goal_take_ac_reading
{
public:
  Init_Acoustic_Goal_take_ac_reading()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_Goal_measurement_point take_ac_reading(::hotspot_action::action::Acoustic_Goal::_take_ac_reading_type arg)
  {
    msg_.take_ac_reading = std::move(arg);
    return Init_Acoustic_Goal_measurement_point(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_Goal>()
{
  return hotspot_action::action::builder::Init_Acoustic_Goal_take_ac_reading();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_Result_ac_save_path
{
public:
  Init_Acoustic_Result_ac_save_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::Acoustic_Result ac_save_path(::hotspot_action::action::Acoustic_Result::_ac_save_path_type arg)
  {
    msg_.ac_save_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_Result>()
{
  return hotspot_action::action::builder::Init_Acoustic_Result_ac_save_path();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{


}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_Feedback>()
{
  return ::hotspot_action::action::Acoustic_Feedback(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_SendGoal_Request_goal
{
public:
  explicit Init_Acoustic_SendGoal_Request_goal(::hotspot_action::action::Acoustic_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Acoustic_SendGoal_Request goal(::hotspot_action::action::Acoustic_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_SendGoal_Request msg_;
};

class Init_Acoustic_SendGoal_Request_goal_id
{
public:
  Init_Acoustic_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_SendGoal_Request_goal goal_id(::hotspot_action::action::Acoustic_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Acoustic_SendGoal_Request_goal(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_SendGoal_Request>()
{
  return hotspot_action::action::builder::Init_Acoustic_SendGoal_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_SendGoal_Response_stamp
{
public:
  explicit Init_Acoustic_SendGoal_Response_stamp(::hotspot_action::action::Acoustic_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Acoustic_SendGoal_Response stamp(::hotspot_action::action::Acoustic_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_SendGoal_Response msg_;
};

class Init_Acoustic_SendGoal_Response_accepted
{
public:
  Init_Acoustic_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_SendGoal_Response_stamp accepted(::hotspot_action::action::Acoustic_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Acoustic_SendGoal_Response_stamp(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_SendGoal_Response>()
{
  return hotspot_action::action::builder::Init_Acoustic_SendGoal_Response_accepted();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_GetResult_Request_goal_id
{
public:
  Init_Acoustic_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::Acoustic_GetResult_Request goal_id(::hotspot_action::action::Acoustic_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_GetResult_Request>()
{
  return hotspot_action::action::builder::Init_Acoustic_GetResult_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_GetResult_Response_result
{
public:
  explicit Init_Acoustic_GetResult_Response_result(::hotspot_action::action::Acoustic_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Acoustic_GetResult_Response result(::hotspot_action::action::Acoustic_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_GetResult_Response msg_;
};

class Init_Acoustic_GetResult_Response_status
{
public:
  Init_Acoustic_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_GetResult_Response_result status(::hotspot_action::action::Acoustic_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Acoustic_GetResult_Response_result(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_GetResult_Response>()
{
  return hotspot_action::action::builder::Init_Acoustic_GetResult_Response_status();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_Acoustic_FeedbackMessage_feedback
{
public:
  explicit Init_Acoustic_FeedbackMessage_feedback(::hotspot_action::action::Acoustic_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::Acoustic_FeedbackMessage feedback(::hotspot_action::action::Acoustic_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_FeedbackMessage msg_;
};

class Init_Acoustic_FeedbackMessage_goal_id
{
public:
  Init_Acoustic_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_FeedbackMessage_feedback goal_id(::hotspot_action::action::Acoustic_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Acoustic_FeedbackMessage_feedback(msg_);
  }

private:
  ::hotspot_action::action::Acoustic_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::Acoustic_FeedbackMessage>()
{
  return hotspot_action::action::builder::Init_Acoustic_FeedbackMessage_goal_id();
}

}  // namespace hotspot_action

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__BUILDER_HPP_
