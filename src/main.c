#include "task_manager.h"
#include "led_driver.h"

int main(void)
{
	rcc_clock_setup_pll(&rcc_clock_config
		[RCC_CLOCK_VRANGE1_HSI_PLL_32MHZ]);

	led_config();

	BaseType_t r1 = xTaskCreate(vledTaskHandler, 
		"LED handler", 250, NULL, 1, NULL);
	if (r1 != pdPASS) 
	{
		// Task creation failed
	}
	
	/* Start the scheduler */
	vTaskStartScheduler();

	for (;;);
}
