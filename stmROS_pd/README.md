# stmROS_pd
Contains the STM32CubeIDE project for acoustic PD detection developed by MEng Team 4 2023/2024.

# Instructions
The project folders and files are generated by the IDE and the subsequent installation of micro-ROS.
The tutorials followed for installing micro-ros are:
  https://github.com/micro-ROS/micro_ros_stm32cubemx_utils/tree/humble
  https://github.com/lFatality/stm32_micro_ros_setup
  https://www.youtube.com/watch?v=xbWaHARjSmk&t=935s

STM32CubeIDE was used. 
micro-ROS libraries could not be built using these tutorials on wsl - a linux computer was needed.

The configuration of the microcontroller timers, peripherals, ADCs and communication interfaces is saved in the stmROS_pd.ioc file. 
This file generates code to initialize them.

The software developed is in the main.c file (Core->Src->main.c) with the main algorithm being written in the "StartDefaultTask()" function.