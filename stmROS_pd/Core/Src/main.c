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
ADC_HandleTypeDef hadc1;

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
uint16_t AD_RES = 0;
uint16_t data[SAMPLES_PER_FRAME] = {0};
uint16_t dataPeak[MAX_PEAKS] = {0};
uint16_t timePeak[MAX_PEAKS] = {0};
uint16_t sampleCounter = 0;
uint16_t peakCounter = 0;
uint16_t peakCounterEnd = 0;
uint16_t findPeakCounter = 0;
uint16_t consPeakCounter = 0;
uint16_t findPeakFlag = 0;
uint8_t flagNewSample = 0;
uint8_t flagOddSample = 0;
uint8_t flagNewData = 0;
uint8_t flagNewPeak = 0;
uint8_t flagPD = 0;
uint8_t countPD = 0;
uint16_t peakDiff = 0;
uint16_t timeOffset = 0;
uint16_t timeOffsetOld = 0;
uint16_t minPeak = 0;
uint16_t maxPeakFrame = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM3_Init(void);
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
  MX_ADC1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim3);
  HAL_ADC_Start_IT(&hadc1);
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

}
//Callback to be executed after each ADC conversion has finished
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    AD_RES = HAL_ADC_GetValue(&hadc1); // Read & Update The ADC Result
    flagNewSample = 1;
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); // Toggle Interrupt Rate Indicator Pin
}
  /* USER CODE END 3 */


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
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_7;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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
  htim3.Init.Prescaler = 2;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 345;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
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
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_8, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA8 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
	  std_msgs__msg__Int32 msg;
	  rclc_support_t support;
	  rcl_allocator_t allocator;
	  rcl_node_t node;

	  allocator = rcl_get_default_allocator();

	  //create init_options
	  rclc_support_init(&support, 0, NULL, &allocator);

	  // create node
	  rclc_node_init_default(&node, "cubemx_node", "", &support);

	  // create publisher
	  rclc_publisher_init_default(
	    &publisher,
	    &node,
	    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
	    "cubemx_publisher");

	  msg.data = 0;

	  while(1)
	  {
		  //-----------------------------------------------------
		  //----------SAMPLING-----------------------------------
		  //-----------------------------------------------------
		  if(flagNewSample == 1)
		  {
			  data[sampleCounter] = AD_RES; //save the newly aquired data sample in the data buffer
			  sampleCounter ++;
			  flagNewData = 1;
			  flagNewSample = 0;
		  }

		  //-----------------------------------------------------
		  //----------FINDING-PEAKS------------------------------
		  //-----------------------------------------------------
		  if(flagNewData == 1) //enter if a new data was saved in the buffer
		  {
			  flagNewData = 0;
			  if(findPeakFlag == 0) //if a peak finding has not been started
			  {
				  if(data[sampleCounter-1] >= MIN_PEAK && data[sampleCounter-1] >= minPeak) //if the new data is big enough to be considered part of a peak
				  {
					  findPeakFlag = 1; //start peak finding
					  dataPeak[peakCounter] = data[sampleCounter-1]; //save the amplitude of the data as the peaks amplitude
					  timePeak[peakCounter] = sampleCounter - 1 + timeOffset; //save timing of data as the peak's timing (by saving the position in the data buffer)
																			  //timeOffset comes from the end of frame, where there might be peaks left in the peak 
																			  //buffer from the previous mains cycle
				  }
				  //else do nothing
			  }
			  else //if a peak finding has already been started
			  {
				  if(data[sampleCounter-1] >= dataPeak[peakCounter]) //if the new data is larger than the previous biggest in the peak
				  {
					  dataPeak[peakCounter] = data[sampleCounter-1]; //change the new data to be the current peak
					  timePeak[peakCounter] = sampleCounter -1 + timeOffset; //change the timing
				  }
				  else
				  {
					  findPeakCounter ++; //increment the counter that determines when the peak finishes
				  }
			  }

		  }

		  if(findPeakCounter == MAX_PEAK_LENGTH) //if the peak is finished
		  {
			  peakCounter ++; //increment the counter of peaks in the buffer
			  findPeakFlag = 0;
			  findPeakCounter = 0;
			  if(peakCounter == MAX_PEAKS) 	// if the peak buffer is full which is irregular -> delete all peaks
			  {							   	// and skip to the end of frame to start looking for peaks from the beginning
				  peakCounter = 0;
				  for(int i = 0; i < MAX_PEAKS; i ++)
				  {
					  dataPeak[i] = 0;
					  timePeak[i] = 0;
				  }
				  sampleCounter = SAMPLES_PER_FRAME;
			  }

			  else //if the peak buffer is not full
			  {
				  flagNewPeak = 1; //signify there is a new peak
			  }
		  }



		  //-----------------------------------------------------
		  //----------FINDING-PD---------------------------------
		  //-----------------------------------------------------
		  if(flagNewPeak == 1 && peakCounter > 1) //if there is a newly finished peak and there is more than one peak in the buffer
		  {
			  flagNewPeak = 0;
			  for(int i = 0; i < peakCounter; i++) // loop to try and find peaks before spaced by half a mains cycle or full cycle
			  {
				  peakDiff = timePeak[peakCounter-1] - timePeak[peakCounter-1-i];
				  if(peakDiff > 760)
				  {
					  if(peakDiff <= 840)
					  {
						  if(consPeakCounter < MIN_CONSECUTIVE_PEAKS)
						  {
							  consPeakCounter ++;
						  }
						  else
						  {
							  flagPD = 1; //possible pd detected
						  }
						  break;
					  }
					  else if(peakDiff > 1520)
					  {
						  if(peakDiff <= 1680)
						  {
							  if(consPeakCounter < MIN_CONSECUTIVE_PEAKS)
							  {
								  consPeakCounter ++;
							  }
							  else
							  {
								  flagPD = 1; //possible pd detected
							  }
							  break;
						  }
						  else
						  {
							  if(consPeakCounter != 0)
							  {
								  consPeakCounter --;
							  }
							  else
							  {
								  flagPD = 0; //pd not detected
							  }
							  break;
						  }
					  }
					  else
					  {
						  //760 >= peakDiff > 420
						  //continue with the loop
					  }
				  }
				  else
				  {
					  //peakDiff <= 380
					  //continue with the loop
				  }
			  }
		  }


		  //-----------------------------------------------------
		  //----------END-OF-FRAME-------------------------------
		  //-----------------------------------------------------
		  if(sampleCounter == SAMPLES_PER_FRAME) //end of frame
		  {
			  if(findPeakFlag == 1)
			  {
				  peakCounter ++;
			  }


			  peakCounterEnd = peakCounter;
			  for(int i = 0; i < peakCounterEnd; i++) //remove all peaks from buffer except for the ones in the second half of the frame
			  {
				  if(timePeak[i] <= SAMPLES_PER_HALF_FRAME + timeOffset)
				  {
					  peakCounter--;
				  }
				  else
				  {
					  break;
				  }
			  }

			  if(peakCounter != 0) //shift all remaining (if any) peaks in the buffer and set the timeOffset for next frame
			  {
				  timeOffsetOld = timeOffset;
				  timeOffset = timeOffset + SAMPLES_PER_FRAME - timePeak[peakCounterEnd - peakCounter];
				  for(int i = 0; i < peakCounterEnd; i ++)
				  {
					  if(i>=peakCounter)
					  {
						  dataPeak[i] = 0;
						  timePeak[i] = 0;
					  }
					  else
					  {
						  dataPeak[i] = dataPeak[peakCounterEnd - peakCounter + i];
						  timePeak[i] = timePeak[peakCounterEnd - peakCounter + i] + timeOffset - SAMPLES_PER_FRAME - timeOffsetOld;
					  }
				  }
			  }
			  else
			  {
				  for(int i = 0; i < peakCounterEnd; i ++)
				  {
					  dataPeak[i] = 0;
					  timePeak[i] = 0;
				  }
				  timeOffset = 0;
				  timeOffsetOld = timeOffset;
			  }

			  maxPeakFrame = 0;
			  for(int i = 0; i < peakCounter; i++) //set the minimum value a data can be considered as a peak to be at 70% of the biggest peak in the previous cycle
			  {
				  if(maxPeakFrame < dataPeak[i])
				  {
					  maxPeakFrame = dataPeak[i];
				  }
			  }
			  minPeak = 0.7 * maxPeakFrame;


			  if(findPeakFlag == 1)
			  {
				  peakCounter --;
			  }

			  sampleCounter = 0;

			  if(consPeakCounter != 0)
			  {
				  consPeakCounter --;
			  }
			  else
			  {
				  flagPD = 0;
			  }
		  }


		  //-----------------------------------------------------
		  //-------------REPORTING-------------------------------
		  //-----------------------------------------------------
		  if(sampleCounter == 1) //determine if PD has to be reported or not
		  {
			  if(flagPD == 1)
			  {
				  if(countPD != 10)
				  {
					  countPD ++;
				  }
				  else
				  {

				  }

			  }
			  else
			  {
				  if(countPD !=0)
				  {
					  countPD --;
				  }
				  else
				  {

				  }

			  }


			  if(countPD > 5) //if pd is to be reported
			  {
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); //set LED for debugging 
				  if (maxPeakFrame >= 1500)
				  {
					  msg.data = 22 + (maxPeakFrame-1500)/250; //send the max peak after transforming to dB
				  }
				  else
				  {
					  msg.data = maxPeakFrame/69;
				  }
				  rcl_ret_t ret = rcl_publish(&publisher, &msg, NULL); //bublish to the topic via micro-ROS
				  if (ret != RCL_RET_OK)
				  {
				    printf("Error publishing (line %d)\n", __LINE__);
				  }


			  }
			  else //if no consistent PD is detected to be reported
			  {
				  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); //reset LED for debugging 
				  msg.data = 1;
				  rcl_ret_t ret = rcl_publish(&publisher, &msg, NULL); //send "1" via micro-ROS signifying no PD
				  if (ret != RCL_RET_OK)
				  {
				    printf("Error publishing (line %d)\n", __LINE__);
				  }
			  }

		  }
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
