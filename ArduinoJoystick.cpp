/*! \file */

#include "ArduinoJoystick.h"

#include "Arduino.h"

/*!
 * \brief Creates a new joystick on an Arduino ADC.
 * \param id ID of the joystick
 * \param adc ADC pin joystick is attached to
 */
ArduinoJoystick::ArduinoJoystick(inputid_t id, inputpin_t adc)
    : IJoystick(id)
    , m_adcPin(adc)
{
  setPoints(0, 512, 1024);
}

/*!
 * \copydoc IJoystick::getPhysicalValue
 */
inputanalog_t ArduinoJoystick::getPhysicalValue() const
{
  return analogRead(m_adcPin);
}
