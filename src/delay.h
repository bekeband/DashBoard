/* 
 * File:   delay.h
 * Author: Tulajdonos
 *
 * Created on 2014. május 30., 14:39
 */

#ifndef DELAY_H
#define	DELAY_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

    void __delay_ms(uint16_t msec);
    void __delay_us(uint16_t usec);

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

