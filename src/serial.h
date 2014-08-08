

#ifndef SERIAL_H_
#define SERIAL_H_

#define TX_BUFFER_SIZE  36
#define RX_BUFFER_SIZE  36

#define waitforTXempty {while (U1STAbits.UTXBF);}



#endif