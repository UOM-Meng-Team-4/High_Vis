// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from hotspot_action:action/PanAndTilt.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__BUILDER_HPP_
#define HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "hotspot_action/action/detail/pan_and_tilt__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_Goal_tilt
{
public:
  explicit Init_PanAndTilt_Goal_tilt(::hotspot_action::action::PanAndTilt_Goal & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_Goal tilt(::hotspot_action::action::PanAndTilt_Goal::_tilt_type arg)
  {
    msg_.tilt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_Goal msg_;
};

class Init_PanAndTilt_Goal_pan
{
public:
  Init_PanAndTilt_Goal_pan()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_Goal_tilt pan(::hotspot_action::action::PanAndTilt_Goal::_pan_type arg)
  {
    msg_.pan = std::move(arg);
    return Init_PanAndTilt_Goal_tilt(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_Goal>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_Goal_pan();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_Result_move_finished
{
public:
  Init_PanAndTilt_Result_move_finished()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::PanAndTilt_Result move_finished(::hotspot_action::action::PanAndTilt_Result::_move_finished_type arg)
  {
    msg_.move_finished = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_Result>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_Result_move_finished();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_Feedback_tilt_feedback
{
public:
  explicit Init_PanAndTilt_Feedback_tilt_feedback(::hotspot_action::action::PanAndTilt_Feedback & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_Feedback tilt_feedback(::hotspot_action::action::PanAndTilt_Feedback::_tilt_feedback_type arg)
  {
    msg_.tilt_feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_Feedback msg_;
};

class Init_PanAndTilt_Feedback_pan_feedback
{
public:
  Init_PanAndTilt_Feedback_pan_feedback()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_Feedback_tilt_feedback pan_feedback(::hotspot_action::action::PanAndTilt_Feedback::_pan_feedback_type arg)
  {
    msg_.pan_feedback = std::move(arg);
    return Init_PanAndTilt_Feedback_tilt_feedback(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_Feedback>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_Feedback_pan_feedback();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_SendGoal_Request_goal
{
public:
  explicit Init_PanAndTilt_SendGoal_Request_goal(::hotspot_action::action::PanAndTilt_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_SendGoal_Request goal(::hotspot_action::action::PanAndTilt_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_SendGoal_Request msg_;
};

class Init_PanAndTilt_SendGoal_Request_goal_id
{
public:
  Init_PanAndTilt_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_SendGoal_Request_goal goal_id(::hotspot_action::action::PanAndTilt_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PanAndTilt_SendGoal_Request_goal(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_SendGoal_Request>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_SendGoal_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_SendGoal_Response_stamp
{
public:
  explicit Init_PanAndTilt_SendGoal_Response_stamp(::hotspot_action::action::PanAndTilt_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_SendGoal_Response stamp(::hotspot_action::action::PanAndTilt_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_SendGoal_Response msg_;
};

class Init_PanAndTilt_SendGoal_Response_accepted
{
public:
  Init_PanAndTilt_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_SendGoal_Response_stamp accepted(::hotspot_action::action::PanAndTilt_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_PanAndTilt_SendGoal_Response_stamp(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_SendGoal_Response>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_SendGoal_Response_accepted();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_GetResult_Request_goal_id
{
public:
  Init_PanAndTilt_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::hotspot_action::action::PanAndTilt_GetResult_Request goal_id(::hotspot_action::action::PanAndTilt_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_GetResult_Request>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_GetResult_Request_goal_id();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_GetResult_Response_result
{
public:
  explicit Init_PanAndTilt_GetResult_Response_result(::hotspot_action::action::PanAndTilt_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_GetResult_Response result(::hotspot_action::action::PanAndTilt_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_GetResult_Response msg_;
};

class Init_PanAndTilt_GetResult_Response_status
{
public:
  Init_PanAndTilt_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_GetResult_Response_result status(::hotspot_action::action::PanAndTilt_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PanAndTilt_GetResult_Response_result(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_GetResult_Response>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_GetResult_Response_status();
}

}  // namespace hotspot_action


namespace hotspot_action
{

namespace action
{

namespace builder
{

class Init_PanAndTilt_FeedbackMessage_feedback
{
public:
  explicit Init_PanAndTilt_FeedbackMessage_feedback(::hotspot_action::action::PanAndTilt_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::hotspot_action::action::PanAndTilt_FeedbackMessage feedback(::hotspot_action::action::PanAndTilt_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_FeedbackMessage msg_;
};

class Init_PanAndTilt_FeedbackMessage_goal_id
{
public:
  Init_PanAndTilt_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PanAndTilt_FeedbackMessage_feedback goal_id(::hotspot_action::action::PanAndTilt_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_PanAndTilt_FeedbackMessage_feedback(msg_);
  }

private:
  ::hotspot_action::action::PanAndTilt_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::hotspot_action::action::PanAndTilt_FeedbackMessage>()
{
  return hotspot_action::action::builder::Init_PanAndTilt_FeedbackMessage_goal_id();
}

}  // namespace hotspot_action

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__BUILDER_HPP_
