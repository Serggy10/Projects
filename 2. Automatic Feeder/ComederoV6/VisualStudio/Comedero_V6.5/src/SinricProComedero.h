#ifndef _SINRICPROCOMEDERO_H_
#define _SINRICPROCOMEDERO_H_

#include <SinricProDevice.h>
#include <Capabilities/PushNotification.h>
#include <Capabilities/ModeController.h>

class SinricProComedero 
: public SinricProDevice
, public PushNotification<SinricProComedero>
, public ModeController<SinricProComedero> {
  friend class PushNotification<SinricProComedero>;
  friend class ModeController<SinricProComedero>;
public:
  SinricProComedero(const String &deviceId) : SinricProDevice(deviceId, "SinricProComedero") {};
};

#endif
