/*
 * geiger_counter.h
 * geiger tube driver
 */

#ifndef INC_GEIGER_COUNTER_H_
#define INC_GEIGER_COUNTER_H_


extern const uint32_t geiger_counter_period_ms;
//extern osTimerId tim_geiger_counterHandle;


void geiger_counter_init(void);
void tim_geiger_counter_callback_1m(void const * argument);
void geiger_counter_int_callback(void);

extern uint32_t geiger_counter_mkroentgen_last;
extern uint32_t geiger_counter_nanosv_last;

#endif /* INC_GEIGER_COUNTER_H_ */
