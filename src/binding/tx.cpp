#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Number txPulse(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int pulseOn = (int) info[2].As<Number>();
  int pulseOff = (int) info[3].As<Number>();
  int pulseOffset = getOptionalArg<Number, int>(info, 4, 0);
  int pulseCycles = getOptionalArg<Number, int>(info, 5, 0);

  int result = lgTxPulse(handle, gpio, pulseOn, pulseOff, pulseOffset, pulseCycles);
  throwIfError(env, "Error starting TX pulse", result);

  return Number::New(env, result);
}

Number txPwm(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  float pwmFrequency = (float) info[2].As<Number>();
  float pwmDutyCycle = (float) info[3].As<Number>();
  int pwmOffset = getOptionalArg<Number, int>(info, 4, 0);
  int pwmCycles = getOptionalArg<Number, int>(info, 5, 0);

  int result = lgTxPwm(handle, gpio, pwmFrequency, pwmDutyCycle, pwmOffset, pwmCycles);
  throwIfError(env, "Error starting TX PWM", result);

  return Number::New(env, result);
}

Number txServo(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int pulseWidth = (int) info[2].As<Number>();
  int servoFrequency = (int) info[3].As<Number>();
  int servoOffset = getOptionalArg<Number, int>(info, 4, 0);
  int servoCycles = getOptionalArg<Number, int>(info, 5, 0);

  int result = lgTxServo(handle, gpio, pulseWidth, servoFrequency, servoOffset, servoCycles);
  throwIfError(env, "Error starting TX servo", result);

  return Number::New(env, result);
}

Number txWave(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  Array jsPulses = info[2].As<Array>();
  vector<lgPulse_t> cPulses;
  int n = jsPulses.Length();
  bool lossless;

  cPulses.reserve(n);

  for (int i = 0; i < n; ++i) {
    lgPulse_t pulse;
    pulse.bits = jsPulses.Get(i).As<Object>().Get("bits").As<BigInt>().Uint64Value(&lossless);
    pulse.mask = jsPulses.Get(i).As<Object>().Get("mask").As<BigInt>().Uint64Value(&lossless);
    pulse.delay = jsPulses.Get(i).As<Object>().Get("delay").As<Number>();
    cPulses.push_back(pulse);
  }

  int result = lgTxWave(handle, gpio, n, &cPulses[0]);
  throwIfError(env, "Error starting TX wave", result);

  return Number::New(env, result);
}

Boolean txBusy(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int kind = (int) info[2].As<Number>();

  int result = lgTxBusy(handle, gpio, kind);
  throwIfError(env, "Error checking if TX is busy", result);

  return Boolean::New(env, result > 0);
}

Number txRoom(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int kind = (int) info[2].As<Number>();

  int result = lgTxRoom(handle, gpio, kind);
  throwIfError(env, "Error checking TX queue room", result);

  return Number::New(env, result);
}
