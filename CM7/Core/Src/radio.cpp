/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : radio.cpp
 * @brief          : Radio Class implementation
 ******************************************************************************
*/

#include "radio.hpp"

Radio::Radio(uint16_t id)
	: id_(id)
{}

VErrorStatus Radio::sendMessage(const BasicMessage& message)
{
	char MESSAGE_BUFFER[256];
	memset(MESSAGE_BUFFER, 0, sizeof(MESSAGE_BUFFER));
	memcpy(MESSAGE_BUFFER, &message.messageBuffer, sizeof(message));

	return V_NO_ERROR;
}