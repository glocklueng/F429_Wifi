#include "sys.h"
#include "delay.h"
#include "malloc.h"
#include "string.h"
#include "stdio.h"
#include "common.h"
 
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

int main(void)
{
	u16 Send_Timers = 0;
	u8 *Temp_Data = (u8*)"F429 wifi test"; 
	
  HAL_Init();                     // 初始化HAL库
  SystemClock_Config();           // 100MHz   HSI->PLL
  delay_init(100);                // 初始化延时函数
	
  uart_init(115200);              // 初始化USART1        串口调试
	usart3_init(115200);  				  // 初始化USART3        WiFi控制线
  my_mem_init(SRAMIN);            // 初始化内部内存池
  my_mem_init(SRAMCCM);           // 初始化内部CCM内存池
	
	atk_8266_init();                // ATK-ESP8266模块初始化配置函数

	u8 *Send_Data = mymalloc(SRAMIN,50);			  // 申请50字节内存
	while(1)
	{
		sprintf((char*)Send_Data, "%s%d", Temp_Data, Send_Timers++);
		if(atk_8266_wifisend_data(Send_Data) == 0)
		{
			Send_Timers--;
			printf("连接出错，正在重新连接...");	
			atk_8266_init();          //ATK-ESP8266模块初始化配置函数
		}
		delay_ms(1000);
	}
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

