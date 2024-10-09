/* USER CODE BEGIN Includes */
/**
 ******************************************************************************
 * @file           : radio.hpp
 * @brief          : Definition of the Radio object.
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
#ifndef RADIO_HPP
#define RADIO_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include "resources.hpp"
#include <string>

class Radio
{
   public:
    Radio();
    
    
    Radio(uint16_t id);


    ~Radio() = default;


    size_t sendMessage(const BasicMessage& message);


    size_t messageReceivedCallback();

    char _radioBuffer[256];

   private:
    // Member Functions
    VErrorStatus flushBuffer();

    // Member Variables
    uint16_t id_ = 0;

};


/* USER CODE END Includes */
#endif /* RADIO_HPP */
