/*
 * SPI.h
 *
 *  Created on: Dec 8, 2022
 *      Author: Esraa Ossama
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

void SPI1_INIT(void);
void SPI1_Write(unsigned char data);
unsigned char SPI1_Read();
void SPI1_CS_ENABLE(void);
void SPI1_CS_DISABLE(void);
unsigned char SPI_TransmitRecieve(unsigned Data);

#endif /* INC_SPI_H_ */

