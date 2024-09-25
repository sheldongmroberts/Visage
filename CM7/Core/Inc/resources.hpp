/* USER CODE BEGIN Includes */
/**
 ******************************************************************************
 * @file           : resources.hpp
 * @brief          : Include file!
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef RESOURCES_HPP
#define RESOURCES_HPP


// char MESSAGE_BUFFER[256];
// char* MESSAGE_BUFFER;

enum VErrorStatus
{
    V_NO_ERROR = 0,
    V_ERROR = 1
};

#pragma pack(push, 1)
struct BasicMessage
{
    char messageBuffer[128];
};
#pragma pack(pop)


/* USER CODE END Includes */

#endif /* RESOURCES_HPP */
