/* 
 * File:   delay.h
 * Author: Tulajdonos
 *
 * Created on 2014. május 30., 14:39
 */

#ifndef DELAY_H
#define	DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    void __delay_ms(long msec);
    void __delay_us(long usec);

#ifdef	__cplusplus
}
#endif

#endif	/* DELAY_H */

