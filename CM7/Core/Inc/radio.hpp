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
#ifndef __RADIO_HPP
#define __RADIO_HPP

#include <cstddef>
#include "resources.hpp"

/* USER CODE END Includes */

class Radio
{
   public:
    Radio();
    
    
    Radio(uint16_t id);


    ~Radio() = default;

   private:
    // Member Functions
    VErrorStatus sendMessage(const BasicMessage& message);


    VErrorStatus messageReceivedCallback();


    VErrorStatus flushBuffer();

    // Member Variables
    uint16_t id_ = 0;
};


#endif /* __RADIO_HPP */
