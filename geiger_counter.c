/* geiger_counter.c
 * tube driver code
 */
#include <generic/serial.h>
#include "geiger_counter.h"
// for M4011
#define CPM 151
// for SI-22g
// #define CPM
// for 1 mk
// for
// counting number
static uint32_t counter=0;
// time period to measure
const uint32_t geiger_counter_period_ms = 60000;

// interrupt 0 on rising edge

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);
  /* NOTE: This function Should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Callback could be implemented in the user file
   */
	counter++;
}

/* tim_geiger_counter_callback function
 * this should be started each 1 minute */
void tim_geiger_counter_callback_1m(void const * argument)
{
	pr_debugln("Counter=%d counts, %d MkRoentgen %d NanoSv", counter,
			(counter*100)/CPM,
			(counter*1000)/CPM);
	counter = 0;
}

void geiger_counter_init(void)
{
	pr_debugln("starting geiger counter");
	//osTimerStart(tim_geiger_counterHandle, geiger_counter_period_ms);
}
