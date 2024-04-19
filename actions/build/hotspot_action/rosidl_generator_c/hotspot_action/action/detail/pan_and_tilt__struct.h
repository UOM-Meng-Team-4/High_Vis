// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hotspot_action:action/PanAndTilt.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_H_
#define HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_Goal
{
  double pan;
  double tilt;
} hotspot_action__action__PanAndTilt_Goal;

// Struct for a sequence of hotspot_action__action__PanAndTilt_Goal.
typedef struct hotspot_action__action__PanAndTilt_Goal__Sequence
{
  hotspot_action__action__PanAndTilt_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_Result
{
  bool move_finished;
} hotspot_action__action__PanAndTilt_Result;

// Struct for a sequence of hotspot_action__action__PanAndTilt_Result.
typedef struct hotspot_action__action__PanAndTilt_Result__Sequence
{
  hotspot_action__action__PanAndTilt_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_Feedback
{
  double pan_feedback;
  double tilt_feedback;
} hotspot_action__action__PanAndTilt_Feedback;

// Struct for a sequence of hotspot_action__action__PanAndTilt_Feedback.
typedef struct hotspot_action__action__PanAndTilt_Feedback__Sequence
{
  hotspot_action__action__PanAndTilt_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "hotspot_action/action/detail/pan_and_tilt__struct.h"

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  hotspot_action__action__PanAndTilt_Goal goal;
} hotspot_action__action__PanAndTilt_SendGoal_Request;

// Struct for a sequence of hotspot_action__action__PanAndTilt_SendGoal_Request.
typedef struct hotspot_action__action__PanAndTilt_SendGoal_Request__Sequence
{
  hotspot_action__action__PanAndTilt_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} hotspot_action__action__PanAndTilt_SendGoal_Response;

// Struct for a sequence of hotspot_action__action__PanAndTilt_SendGoal_Response.
typedef struct hotspot_action__action__PanAndTilt_SendGoal_Response__Sequence
{
  hotspot_action__action__PanAndTilt_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} hotspot_action__action__PanAndTilt_GetResult_Request;

// Struct for a sequence of hotspot_action__action__PanAndTilt_GetResult_Request.
typedef struct hotspot_action__action__PanAndTilt_GetResult_Request__Sequence
{
  hotspot_action__action__PanAndTilt_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_GetResult_Response
{
  int8_t status;
  hotspot_action__action__PanAndTilt_Result result;
} hotspot_action__action__PanAndTilt_GetResult_Response;

// Struct for a sequence of hotspot_action__action__PanAndTilt_GetResult_Response.
typedef struct hotspot_action__action__PanAndTilt_GetResult_Response__Sequence
{
  hotspot_action__action__PanAndTilt_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"

/// Struct defined in action/PanAndTilt in the package hotspot_action.
typedef struct hotspot_action__action__PanAndTilt_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  hotspot_action__action__PanAndTilt_Feedback feedback;
} hotspot_action__action__PanAndTilt_FeedbackMessage;

// Struct for a sequence of hotspot_action__action__PanAndTilt_FeedbackMessage.
typedef struct hotspot_action__action__PanAndTilt_FeedbackMessage__Sequence
{
  hotspot_action__action__PanAndTilt_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__PanAndTilt_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__PAN_AND_TILT__STRUCT_H_
