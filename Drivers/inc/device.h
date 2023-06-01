/*
 * device.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

#define Set_Temperature 30
void TC72_Init();
void Read_Register(unsigned char Reg_Address,signed char *Data);
void Write_Register(unsigned char Reg_Address,unsigned char Data);
double get_temperature() ;

#endif /* INC_DEVICE_H_ */
