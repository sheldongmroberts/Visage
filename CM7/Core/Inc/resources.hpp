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
#ifndef __RESOURCES_HPP
#define __RESOURCES_HPP

/* USER CODE END Includes */

enum VErrorStatus
{
    V_NO_ERROR = 0,
    V_ERROR = 1
};


struct BasicMessage
{
    char messageBuffer[128];
};

#endif /* __RESOURCES_HPP */
