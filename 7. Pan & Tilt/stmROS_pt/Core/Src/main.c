/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <uxr/client/transport.h>
#include <rmw_microxrcedds_c/config.h>
#include <rmw_microros/rmw_microros.h>

#include <std_msgs/msg/int32.h>
#include <stdbool.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ENCODER_SAMPLE_TIME 0.05                                  //Encoder gives data once every 50 ms
//Pan PWM Control
#define PAN_TURNING_MAX 10000                                     //Max speed clockwise
#define PAN_TURNING_NO 6200                                       //No turning
#define PAN_TURNING_MIN 0                                         //Max speed counterclockwise
//Tilt PWM Control
#define TILT_TURNING_MAX 10000                                    //Max speed clockwise
#define TILT_TURNING_NO 5000                                      //No Turning
#define TILT_TURNING_MIN 0                                        //Max speed counterclockwise
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define MAX_PEAKS 30
#define SAMPLES_PER_FRAME 3200
#define SAMPLES_PER_HALF_FRAME 1600
#define MIN_PEAK 420
#define MAX_PEAK_LENGTH 100
#define MIN_CONSECUTIVE_PEAKS 6
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c3;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
uint32_t defaultTaskBuffer[ 3000 ];
osStaticThreadDef_t defaultTaskControlBlock;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .cb_mem = &defaultTaskControlBlock,
  .cb_size = sizeof(defaultTaskControlBlock),
  .stack_mem = &defaultTaskBuffer[0],
  .stack_size = sizeof(defaultTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* USER CODE BEGIN PV */
static const uint8_t AS5600_ADDR_PAN = 0x36 << 1;                 //Set the register of AS5600 for I2C communication
static const uint8_t AS5600_ADDR_TILT = 0x36 << 1;                //Set the register of AS5600 for I2C communication

//For debuging puposes
uint8_t flag = 0;
uint8_t flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;
uint8_t flag7 = 0, flag8 = 0;

std_msgs__msg__Int32 msgSubscriber;                               //Data received from the main executor is stored in this variable

uint16_t panTarget = 0;                                           //Variable to store the pan position target
uint16_t tiltTarget = 0;                                          //Variable to store the tilt position target

int32_t panDutyPWM = 0;                                           //Variable to store the pan PWM duty cycle
int32_t tiltDutyPWM = 0;                                          //Variable to store the tilt PWM duty cycle
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_I2C1_Init(void);
static void MX_I2C3_Init(void);
static void MX_TIM2_Init(void);
void StartDefaultTask(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	flag2 = 1;                                                      //Flag2 is changed to 1, for debugging purposes

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_I2C1_Init();
  MX_I2C3_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
  HAL_TIM_Base_Start_IT(&htim3);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 5;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 999;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 4199;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
bool cubemx_transport_open(struct uxrCustomTransport * transport);
bool cubemx_transport_close(struct uxrCustomTransport * transport);
size_t cubemx_transport_write(struct uxrCustomTransport* transport, const uint8_t * buf, size_t len, uint8_t * err);
size_t cubemx_transport_read(struct uxrCustomTransport* transport, uint8_t* buf, size_t len, int timeout, uint8_t* err);

void * microros_allocate(size_t size, void * state);
void microros_deallocate(void * pointer, void * state);
void * microros_reallocate(void * pointer, size_t size, void * state);
void * microros_zero_allocate(size_t number_of_elements, size_t size_of_element, void * state);

void subscription_callback(const void * msgin)
{
  // Cast received message to used type
  const std_msgs__msg__Int32 * msgSubscriber = (const std_msgs__msg__Int32 *)msgin;
}
/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
	  // micro-ROS configuration
	flag4 = 1;

	  rmw_uros_set_custom_transport(
	    true,
	    (void *) &huart2,
	    cubemx_transport_open,
	    cubemx_transport_close,
	    cubemx_transport_write,
	    cubemx_transport_read);

	  rcl_allocator_t freeRTOS_allocator = rcutils_get_zero_initialized_allocator();
	  freeRTOS_allocator.allocate = microros_allocate;
	  freeRTOS_allocator.deallocate = microros_deallocate;
	  freeRTOS_allocator.reallocate = microros_reallocate;
	  freeRTOS_allocator.zero_allocate =  microros_zero_allocate;

	  if (!rcutils_set_default_allocator(&freeRTOS_allocator)) {
	      printf("Error on default allocators (line %d)\n", __LINE__);
	  }

	  // micro-ROS app

	  rcl_publisher_t publisher;
	  std_msgs__msg__Int32 msgPublisher;
	  rclc_support_t support;
	  rcl_allocator_t allocator;
	  rcl_node_t node;

	  rcl_subscription_t subscriber;

	  rclc_executor_t executor;


	  allocator = rcl_get_default_allocator();

	  //create init_options
	  rclc_support_init(&support, 0, NULL, &allocator);

	  // create node
	  rclc_node_init_default(&node, "pt_node", "", &support);

	  // create publisher
	  rclc_publisher_init_default(
	    &publisher,
	    &node,
	    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32), //std_msgs/msg/Int32
	    "pt_publisher");

	  msgPublisher.data = 0;

	  // Create subscriber
	  rclc_subscription_init_default(
	    &subscriber,
	    &node,
	    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
	    "pt_subscriber");

	  msgSubscriber.data = 0;


	  executor = rclc_executor_get_zero_initialized_executor();
	  rclc_executor_init(&executor, &support.context, 1, &allocator);
	  rclc_executor_add_subscription(
	   &executor, &subscriber, &msgSubscriber,
	    &subscription_callback, ON_NEW_DATA);

	  // Spin executor to receive messages
	  rclc_executor_spin_some(&executor,1000*1000*40);
	  //rcl_subscription_fini(&subscriber, &node);
	  //rcl_node_fini(&node);

    //Variables used for this project
	  HAL_StatusTypeDef panStatus;                                  //Check the status of the register for pan's AS5600
	  uint8_t as5600_panData[3] = {0};                              //Store the data from the pan's AS5600 register
	  uint16_t panLowbyte;                                          //Seperating the pan angle, to get the low byte
	  uint16_t panHighbyte;                                         //Seperating the pan angle, to get the high byte
	  uint16_t panRawAngle;                                         //Raw pan angle
	  float panFloatAngle;                                          //Float pan angle in degree
	  uint16_t panDegAngle;                                         //Int pan angle in degree
	  int panFlag = 0;                                              //Debug purpose

	  HAL_StatusTypeDef tiltStatus;                                 //Check the status of the register for tilt's AS5600
	  uint8_t as5600_tiltData[3] = {0};                             //Store the data from the tilt's AS5600 register
	  uint16_t tiltLowbyte;                                         //Seperating the tilt angle, to get the low byte
	  uint16_t tiltHighbyte;                                        //Seperating the tilt angle, to get the high byte
	  uint16_t tiltRawAngle;                                        //Raw tilt angle
	  float tiltFloatAngle;                                         //Float tilt angle in degree
	  uint16_t tiltDegAngle;                                        //Int tilt angle in degree
	  int tiltFlag = 0;                                             //Debug purpose

	  int64_t newPanTarget = 0;                                     //Pan target position
	  int64_t newTiltTarget = 0;                                    //Tilt target position
	  int64_t oldPanTarget = 0;                                     //Previous pan target position
	  int64_t oldTiltTarget = 0;                                    //Previous tilt target position

	  const float panKp = 300;                                      //Kp value for the pan's encoder
	  const float panKd = 120;                                      //Kd value for the pan's encoder
	  const float tiltKp = 100;                                     //Kp value for the tilt's encoder
	  const float tiltKd = 40;                                      //Kd value for the tilt's encoder

	  uint32_t panAndTilt = 0;

	  while(1)
	  {
		  flag5 = 1;                                                  //Debug purpose
		  if(flag == 1)                                               //Flag is changed by the timer interupt
		  	{
		  		flag = 0;
		  		flag6 = 1;

          //Take the combined received angle from the main executor and separate it
		  		tiltTarget = msgSubscriber.data >> 9;                   //Higher byte is assigned for tilt target position
		  		panTarget = msgSubscriber.data & 511;                   //Lower byte is assigned for pan target position

          //Obtain the information from the three consecutive register of the pan encoder
		  		panStatus = HAL_I2C_Mem_Read(&hi2c1, AS5600_ADDR_PAN, 0x0B, 1, as5600_panData, 3, HAL_MAX_DELAY);

		  		panHighbyte = as5600_panData[1];                        //2nd value of the pan data array is the high byte
		  		panLowbyte = as5600_panData[2];                         //3rd value of the pan data array is the low byte
		  		panRawAngle = panHighbyte << 8 | panLowbyte;            //Combine both value to get the raw angle
		  		panFloatAngle = panRawAngle * 0.087890625;              //Convert the angle to be an angle in degree
		  		panDegAngle = (int)panFloatAngle;                       //Round the angle to be an integer value

          //Setting the initial pan position to be at 0 degree
		  		if(panDegAngle < 156)
		  		{
		  		  panDegAngle = 360 -156 + panDegAngle;
		  		}
		  		else
		  		{
		  		  panDegAngle = panDegAngle - 156;
		  		}


          //Obtain the information from the three consecutive register of the tilt encoder
		  		tiltStatus = HAL_I2C_Mem_Read(&hi2c3, AS5600_ADDR_TILT, 0x0B, 1, as5600_tiltData, 3, HAL_MAX_DELAY);

		  		tiltHighbyte = as5600_tiltData[1];                      //2nd value of the tilt data array is the high byte
		  		tiltLowbyte = as5600_tiltData[2];                       //3rd value of the tilt data array is the low byte
		  		tiltRawAngle = tiltHighbyte << 8 | tiltLowbyte;         //Combine both value to get the raw angle
		  		tiltFloatAngle = tiltRawAngle * 0.087890625;            //Convert the angle to be an angle in degree
		  		tiltDegAngle = (int)tiltFloatAngle;                     //Round the angle to be an integer value

          //Setting the initial tilt position to be at 0 degree
		  		if(tiltDegAngle < 104)                
		  		{
		  		  tiltDegAngle = 360 -104 + tiltDegAngle;
		  		}
		  		else
		  		{
		  		  tiltDegAngle = tiltDegAngle - 104;
		  		}

				//Setting Pan Position
				if(panTarget == panDegAngle)                              //If current pan angle is equal to the target, don't turn the motor
				{
				  panFlag = 1;                                            //Debug only

				  TIM2->CCR1 = PAN_TURNING_NO;
				}
				else                                                      //Else statement
				{
				  panFlag = 0;                                            //Debug only

				  newPanTarget = panTarget - panDegAngle;                 //Calculate the differences

          //Set the PWM duty cycle using PID formula
				  panDutyPWM = PAN_TURNING_NO + panKp*newPanTarget + panKd*((newPanTarget - oldPanTarget)/ENCODER_SAMPLE_TIME);
				  oldPanTarget = newPanTarget;

          //To limit the PWM duty cycle
				  if(panDutyPWM < PAN_TURNING_MIN)                        //If calculated PWM duty cycle is smaller than minimum value, use the minimum PWM value
					panDutyPWM = PAN_TURNING_MIN;
				  if(panDutyPWM > PAN_TURNING_MAX)                        //If calculated PWM duty cycle is larger than minimum value, use the maximum PWM value
					panDutyPWM = PAN_TURNING_MAX;

				  TIM2->CCR1 = panDutyPWM;
				}

				//Setting Tilt Position
				if(tiltTarget == tiltDegAngle)                            //If current tilt angle is equal to the target, don't turn the motor
				{
				  tiltFlag = 1;                                           //Debug only

				  TIM2->CCR2 = TILT_TURNING_NO;
				}
				else
				{
				  tiltFlag = 0;                                           //Debug only

				  newTiltTarget = tiltTarget - tiltDegAngle;              //Calculate the differences

          //Set the PWM duty cycle using PID formula
				  tiltDutyPWM = TILT_TURNING_NO + tiltKp*newTiltTarget + tiltKd*((newTiltTarget - oldTiltTarget)/ENCODER_SAMPLE_TIME);
				  oldTiltTarget = newTiltTarget;

          //To limit the PWM duty cycle
				  if(tiltDutyPWM < TILT_TURNING_MIN)                      //If calculated PWM duty cycle is smaller than minimum value, use the minimum PWM value
					tiltDutyPWM = TILT_TURNING_MIN;
				  if(tiltDutyPWM > TILT_TURNING_MAX)                      //If calculated PWM duty cycle is smaller than maximum value, use the maximum PWM value
					tiltDutyPWM = TILT_TURNING_MAX;

				  TIM2->CCR2 = tiltDutyPWM;
				}

				//Send feedback and results to the main executor
				panAndTilt = 0;                                           //Reset the variable
				panAndTilt = (panDegAngle) | ((tiltDegAngle) << 9);       //Combining the current pan and tilt angles
				msgPublisher.data = panAndTilt;                           //Assign the data to be sent, to this object

          //Send the data
			    rcl_ret_t ret = rcl_publish(&publisher, &msgPublisher, NULL);
			    flag7 = 1;
			    if (ret != RCL_RET_OK)
			    {
			    	flag8 = 1;
			      printf("Error publishing (line %d)\n", __LINE__);
			    }


		  	}

				  /*HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
				  //sprintf(MSG, "%d\r\n", 1);
				  //HAL_UART_Transmit(&huart2, MSG, sizeof(MSG), 20);
				  msg.data = 1;
				  rcl_ret_t ret = rcl_publish(&publisher, &msg, NULL);
				  if (ret != RCL_RET_OK)
				  {
				    printf("Error publishing (line %d)\n", __LINE__);
				  }
			  }

		  }*/
	    /*rcl_ret_t ret = rcl_publish(&publisher, &msg, NULL);
	    if (ret != RCL_RET_OK)
	    {
	      printf("Error publishing (line %d)\n", __LINE__);
	    }

	    msg.data++;*/
	  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
  else //if (htim->Instance == TIM3)
  {
	  flag = 1;
	  flag3 = 1;
  }
  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
