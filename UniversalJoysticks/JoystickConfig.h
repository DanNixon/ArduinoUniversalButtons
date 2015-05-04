#ifndef ARDUINO_UNIVERSAL_JOYSTICKS_CONFIG_H
#define ARDUINO_UNIVERSAL_JOYSTICKS_CONFIG_H

#include <inttypes.h>
#include <UniversalInput.h>

#include "JoystickTypes.h"


using UniversalInput::result_t;


/**
 * Used to define the polarity of a joystick.
 *
 * When POLARITY_NEGATIVE is set the high and low values
 * of the mapped to range will be swapped.
 */
enum joystickpolaity_t
{
  POLARITY_POSITIVE,
  POLARITY_NEGATIVE
};


/**
 * Holds configuration data for a joystick and does
 * conversion from raw ADC value to joystick position.
 */
class JoystickConfig
{
  public:
    JoystickConfig();

    JoystickConfig(joystickvalue_t toLow, joystickvalue_t toHigh,
                   joystickraw_t fromLow, joystickraw_t fromCentre, joystickraw_t fromHigh,
                   joystickraw_t deadBandLow, joystickraw_t deadBandCentre, joystickraw_t deadBandHigh,
                   joystickpolaity_t polarity, bool hasCentrePoint,
                   joystickvalue_t deltaThreshold);

    joystickvalue_t convertRaw(joystickraw_t value);
    bool withinTolRange(joystickraw_t testValue, joystickraw_t pointValue, joystickraw_t tolerance);

    result_t setToRangeLow(joystickvalue_t value);
    joystickvalue_t getToRangeLow() { return m_toRangeLow; }

    result_t setToRangeHigh(joystickvalue_t value);
    joystickvalue_t getToRangeHigh() { return m_toRangeHigh; }

    result_t setFromLow(joystickraw_t value);
    joystickraw_t getFromLow() { return m_fromLow; }

    result_t setFromCentre(joystickraw_t value);
    joystickraw_t getFromCentre() { return m_fromCentre; }

    result_t setFromHigh(joystickraw_t value);
    joystickraw_t getFromHigh() { return m_fromHigh; }

    result_t setDeadBandLow(joystickraw_t value);
    joystickraw_t getDeadBandLow() { return m_deadBandLow; }

    result_t setDeadBandCentre(joystickraw_t value);
    joystickraw_t getDeadBandCentre() { return m_deadBandCentre; }

    result_t setDeadBandHigh(joystickraw_t value);
    joystickraw_t getDeadBandHigh() { return m_deadBandHigh; }

    result_t setPolarity(joystickpolaity_t polarity);
    joystickpolaity_t getPolarity() { return m_polarity; }

    result_t setHasCentrePoint(bool hasCentrePoint);
    bool getHasCentrePoint() { return m_hasCentrePoint; }

    result_t setDeltaThreshold(joystickvalue_t threshold);
    joystickvalue_t getDeltaThreshold() { return m_deltaThreshold; }


  private:
    joystickvalue_t m_toRangeHigh;
    joystickvalue_t m_toRangeLow;

    joystickraw_t m_fromHigh;
    joystickraw_t m_fromCentre;
    joystickraw_t m_fromLow;

    joystickraw_t m_deadBandHigh;
    joystickraw_t m_deadBandCentre;
    joystickraw_t m_deadBandLow;

    joystickpolaity_t m_polarity;
    bool m_hasCentrePoint;

    joystickvalue_t m_deltaThreshold;

};

#endif