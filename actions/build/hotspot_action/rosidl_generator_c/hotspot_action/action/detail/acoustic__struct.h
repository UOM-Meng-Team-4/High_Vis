// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hotspot_action:action/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__STRUCT_H_
#define HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_Goal
{
  bool take_ac_reading;
  int64_t measurement_point;
  int64_t pan_position;
  int64_t tilt_position;
} hotspot_action__action__Acoustic_Goal;

// Struct for a sequence of hotspot_action__action__Acoustic_Goal.
typedef struct hotspot_action__action__Acoustic_Goal__Sequence
{
  hotspot_action__action__Acoustic_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'ac_save_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_Result
{
  rosidl_runtime_c__String ac_save_path;
} hotspot_action__action__Acoustic_Result;

// Struct for a sequence of hotspot_action__action__Acoustic_Result.
typedef struct hotspot_action__action__Acoustic_Result__Sequence
{
  hotspot_action__action__Acoustic_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} hotspot_action__action__Acoustic_Feedback;

// Struct for a sequence of hotspot_action__action__Acoustic_Feedback.
typedef struct hotspot_action__action__Acoustic_Feedback__Sequence
{
  hotspot_action__action__Acoustic_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "hotspot_action/action/detail/acoustic__struct.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  hotspot_action__action__Acoustic_Goal goal;
} hotspot_action__action__Acoustic_SendGoal_Request;

// Struct for a sequence of hotspot_action__action__Acoustic_SendGoal_Request.
typedef struct hotspot_action__action__Acoustic_SendGoal_Request__Sequence
{
  hotspot_action__action__Acoustic_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} hotspot_action__action__Acoustic_SendGoal_Response;

// Struct for a sequence of hotspot_action__action__Acoustic_SendGoal_Response.
typedef struct hotspot_action__action__Acoustic_SendGoal_Response__Sequence
{
  hotspot_action__action__Acoustic_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} hotspot_action__action__Acoustic_GetResult_Request;

// Struct for a sequence of hotspot_action__action__Acoustic_GetResult_Request.
typedef struct hotspot_action__action__Acoustic_GetResult_Request__Sequence
{
  hotspot_action__action__Acoustic_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "hotspot_action/action/detail/acoustic__struct.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_GetResult_Response
{
  int8_t status;
  hotspot_action__action__Acoustic_Result result;
} hotspot_action__action__Acoustic_GetResult_Response;

// Struct for a sequence of hotspot_action__action__Acoustic_GetResult_Response.
typedef struct hotspot_action__action__Acoustic_GetResult_Response__Sequence
{
  hotspot_action__action__Acoustic_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "hotspot_action/action/detail/acoustic__struct.h"

/// Struct defined in action/Acoustic in the package hotspot_action.
typedef struct hotspot_action__action__Acoustic_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  hotspot_action__action__Acoustic_Feedback feedback;
} hotspot_action__action__Acoustic_FeedbackMessage;

// Struct for a sequence of hotspot_action__action__Acoustic_FeedbackMessage.
typedef struct hotspot_action__action__Acoustic_FeedbackMessage__Sequence
{
  hotspot_action__action__Acoustic_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hotspot_action__action__Acoustic_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HOTSPOT_ACTION__ACTION__DETAIL__ACOUSTIC__STRUCT_H_
