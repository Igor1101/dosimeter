/* geiger_counter.c
 * tube driver code
 */
#include <generic/serial.h>
#include "geiger_counter.h"
#include <generic/display.h>
// for M4011
#define CPM 151
// for SI-22g
// #define CPM
// for 1 mk
// for
// counting number
static volatile uint32_t counter=0;
// time period to measure
const uint32_t geiger_counter_period_ms = 60000;

uint32_t geiger_counter_mkroentgen_last = 0;
uint32_t geiger_counter_nanosv_last = 0;
// interrupt 0 on rising edge

void geiger_counter_int_callback(void)
{
	counter++;
}

/* tim_geiger_counter_callback function
 * this should be started each 1 minute */
void geiger_counter_callback(uint32_t time)
{
	geiger_counter_mkroentgen_last = (counter*100 * time)/CPM / 60;
	geiger_counter_nanosv_last = (counter*1000 * time)/CPM / 60;
	tty_println("Counter=%d counts, %d MkRoentgen %d NanoSv", counter,
			geiger_counter_mkroentgen_last,
			geiger_counter_nanosv_last);
	counter = 0;
}

void geiger_counter_init(void)
{
	tty_println("starting geiger counter");
}
