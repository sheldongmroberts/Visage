/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : radio.cpp
 * @brief          : Radio Class implementation
 ******************************************************************************
*/

#include "radio.hpp"

extern "C"
{
#include "FreeRTOS.h"
#include "message_buffer.h"
#include "portmacro.h"
}

Radio::Radio(uint16_t id)
	: id_(id)
{}

/*
size_t xMessageBufferSend( MessageBufferHandle_t xMessageBuffer,
                           const void *pvTxData,
                           size_t xDataLengthBytes,
                           TickType_t xTicksToWait );
*/

VErrorStatus Radio::sendMessage(const BasicMessage& message)
{
	// memset(MESSAGE_BUFFER, 0, sizeof(MESSAGE_BUFFER));
	// memcpy(MESSAGE_BUFFER, &message.messageBuffer, sizeof(message));
	TickType_t xTickType;
	size_t sendRes = xMessageBufferSend(xMessageBuffer, &message, 256, xTickType);

	return V_NO_ERROR;
}