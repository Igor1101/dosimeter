/*
 * geiger_counter.h
 * geiger tube driver
 */

#ifndef INC_GEIGER_COUNTER_H_
#define INC_GEIGER_COUNTER_H_


extern const uint32_t geiger_counter_period_ms;
//extern osTimerId tim_geiger_counterHandle;


void geiger_counter_init(void);

#endif /* INC_GEIGER_COUNTER_H_ */
