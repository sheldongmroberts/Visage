/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : radio.cpp
 * @brief          : Radio Class implementation
 ******************************************************************************
*/

#include "radio.hpp"
#include <iostream>

extern "C"
{
#include "FreeRTOS.h"
#include "message_buffer.h"
#include "portmacro.h"
#include "task.h"
}

Radio::Radio(uint16_t id)
	: id_(id)
{}

size_t Radio::sendMessage(const BasicMessage& message)
{
    size_t temp = xMessageBufferSpacesAvailable(xMessageBuffer);
    configASSERT(temp == 256);

    if (xMessageBufferIsEmpty(xMessageBuffer) == pdTRUE) {
        return 5;
    } else {
        return 6;
    }

	size_t sendRes = xMessageBufferSend(xMessageBuffer, &message, 256, 0);
    // std::cout << sendRes << std::endl;

	return temp;
}


size_t Radio::messageReceivedCallback()
{
    char buffer[256];
	// return xMessageBufferReceive(xMessageBuffer, &buffer, 256, 0);
	size_t res = xMessageBufferReceive(xMessageBuffer, &buffer, 256, 0);
    // std::cout << res << std::endl;

    return res;
}