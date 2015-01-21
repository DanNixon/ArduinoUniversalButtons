#ifndef ARDUINO_UNIVERSAL_JOYSTICKS_H
#define ARDUINO_UNIVERSAL_JOYSTICKS_H

#include <Arduino.h>
#include <inttypes.h>
#include <UniversalInput.h>

#include "JoystickConfig.h"
#include "JoystickTypes.h"


using UniversalInput::pin_t;


struct Joystick
{
  joystickid_t id;
  JoystickConfig *config;
  joystickvalue_t (* adcRead) (pin_t pin);
  joystickvalue_t lastValue;
  Joystick *next;
};


class UniversalJoysticks
{
  public:
    UniversalJoysticks();
    ~UniversalJoysticks();

    void poll();

    void setValueChangeCallback(void (* callback)(joystickid_t jid, joystickvalue_t value, joystickvalue_t delta));

    JoystickConfig *getDefaultConfig();
    void setDefaultConfig(JoystickConfig *config);

    JoystickConfig *getConfig(joystickid_t jid);

    void setCustomIO(int32_t (* readADC)(pin_t pin));

    UniversalInput::Result addJoystick(pin_t pin);
    UniversalInput::Result addJoystick(joystickid_t jid, pin_t pin);

    UniversalInput::Result addCustomJoystick(pin_t pin);
    UniversalInput::Result addCustomJoystick(joystickid_t jid, pin_t pin);

    joystickvalue_t getJoystickValue(joystickid_t jid);

    uint16_t joystickCount();

  private:
    JoystickConfig *m_defaultConfig;

    int32_t (* m_readADC)(pin_t pin);
    void (* m_valueChangeCallback)(joystickid_t jid, joystickvalue_t value, joystickvalue_t delta);

    uint16_t m_joystickCount;
    Joystick *m_joystickList;

};

#endif
