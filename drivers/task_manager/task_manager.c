#include "task_manager.h"
#include "led_driver.h"

TaskHandle_t xledTaskHandle = NULL;


void vledTaskHandler(void *params __attribute((unused)))
{
	while(1)
	{
		gpio_toggle(GREEN_LED_PORT, GREEN_LED_PIN); //Toogle green LED
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}



