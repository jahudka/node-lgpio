#include <napi.h>
#include <string>

#include "./chip.h"
#include "./gpio.h"
#include "./tx.h"
#include "./alerts.h"
#include "./utils.h"

using namespace Napi;


Object Init(Env env, Object exports) {
  exports.Set(
    String::New(env, "gpiochipOpen"),
    Function::New(env, gpiochipOpen)
  );

  exports.Set(
    String::New(env, "gpiochipClose"),
    Function::New(env, gpiochipClose)
  );

  exports.Set(
    String::New(env, "gpioGetChipInfo"),
    Function::New(env, gpioGetChipInfo)
  );

  exports.Set(
    String::New(env, "gpioSetUser"),
    Function::New(env, gpioSetUser)
  );

  exports.Set(
    String::New(env, "gpioGetLineInfo"),
    Function::New(env, gpioGetLineInfo)
  );

  exports.Set(
    String::New(env, "gpioGetMode"),
    Function::New(env, gpioGetMode)
  );

  exports.Set(
    String::New(env, "gpioClaimInput"),
    Function::New(env, gpioClaimInput)
  );

  exports.Set(
    String::New(env, "gpioClaimOutput"),
    Function::New(env, gpioClaimOutput)
  );

  exports.Set(
    String::New(env, "gpioFree"),
    Function::New(env, gpioFree)
  );

  exports.Set(
    String::New(env, "gpioRead"),
    Function::New(env, gpioRead)
  );

  exports.Set(
    String::New(env, "gpioWrite"),
    Function::New(env, gpioWrite)
  );

  exports.Set(
    String::New(env, "groupClaimInput"),
    Function::New(env, groupClaimInput)
  );

  exports.Set(
    String::New(env, "groupClaimOutput"),
    Function::New(env, groupClaimOutput)
  );

  exports.Set(
    String::New(env, "groupFree"),
    Function::New(env, groupFree)
  );

  exports.Set(
    String::New(env, "groupRead"),
    Function::New(env, groupRead)
  );

  exports.Set(
    String::New(env, "groupWrite"),
    Function::New(env, groupWrite)
  );

  exports.Set(
    String::New(env, "txPulse"),
    Function::New(env, txPulse)
  );

  exports.Set(
    String::New(env, "txPwm"),
    Function::New(env, txPwm)
  );

  exports.Set(
    String::New(env, "txWave"),
    Function::New(env, txWave)
  );

  exports.Set(
    String::New(env, "txBusy"),
    Function::New(env, txBusy)
  );

  exports.Set(
    String::New(env, "txRoom"),
    Function::New(env, txRoom)
  );

  exports.Set(
    String::New(env, "gpioClaimAlert"),
    Function::New(env, gpioClaimAlert)
  );

  exports.Set(
    String::New(env, "gpioSetDebounce"),
    Function::New(env, gpioSetDebounce)
  );

  exports.Set(
    String::New(env, "gpioSetWatchdog"),
    Function::New(env, gpioSetWatchdog)
  );

  exports.Set(
    String::New(env, "gpioSetAlertsFunc"),
    Function::New(env, gpioSetAlertsFunc)
  );

  exports.Set(
    String::New(env, "gpioSetSamplesFunc"),
    Function::New(env, gpioSetSamplesFunc)
  );

  exports.Set(
    String::New(env, "notifyOpen"),
    Function::New(env, notifyOpen)
  );

  exports.Set(
    String::New(env, "notifyResume"),
    Function::New(env, notifyResume)
  );

  exports.Set(
    String::New(env, "notifyPause"),
    Function::New(env, notifyPause)
  );

  exports.Set(
    String::New(env, "notifyClose"),
    Function::New(env, notifyClose)
  );

  exports.Set(
    String::New(env, "timestamp"),
    Function::New(env, timestamp)
  );

  exports.Set(
    String::New(env, "version"),
    Function::New(env, version)
  );

  exports.Set(
    String::New(env, "getInternal"),
    Function::New(env, getInternal)
  );

  exports.Set(
    String::New(env, "setInternal"),
    Function::New(env, setInternal)
  );

  exports.Set(
    String::New(env, "errorText"),
    Function::New(env, errorText)
  );

  exports.Set(
    String::New(env, "setWorkDir"),
    Function::New(env, setWorkDir)
  );

  exports.Set(
    String::New(env, "getWorkDir"),
    Function::New(env, getWorkDir)
  );

  return exports;
}

NODE_API_MODULE(lgpio, Init)
