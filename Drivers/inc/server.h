/*
 * server.h
 *
 *  Created on: Jan 2, 2023
 *      Author: moham
 */

#ifndef SERVER_H_
#define SERVER_H_

#define MAX_SUB 10


void GetState();
void subscribe(void (*callback_ptr)(void));
void unsubscribe(void (*callback_ptr)(void));
void notify();

#endif /* SERVER_H_ */
