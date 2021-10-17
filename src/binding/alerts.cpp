#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;

void gpioClaimAlert(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int flags = (int) info[1].As<Number>();
  int edges = (int) info[2].As<Number>();
  int gpio = (int) info[3].As<Number>();
  int nfyHandle = getOptionalArg<Number, int>(info, 4, -1);

  int result = lgGpioClaimAlert(handle, flags, edges, gpio, nfyHandle);
  throwIfError(env, "Failed claiming GPIO alert", result);
}

void gpioSetDebounce(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int debounceUs = (int) info[2].As<Number>();

  int result = lgGpioSetDebounce(handle, gpio, debounceUs);
  throwIfError(env, "Failed setting debounce time", result);
}

void gpioSetWatchdog(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int watchdogUs = (int) info[2].As<Number>();

  int result = lgGpioSetWatchdog(handle, gpio, watchdogUs);
  throwIfError(env, "Failed setting watchdog time", result);
}

void callAlertsFunc(int n, lgGpioAlert_p cAlerts, void *data) {
  if (n < 1) {
    return;
  }

  ThreadSafeFunction * tsfn = (ThreadSafeFunction *)data;

  tsfn->BlockingCall(cAlerts, [&, n](Env env, Function cb, lgGpioAlert_p cAlerts) {
    Array jsAlerts = Array::New(env, n);

    for (int i = 0; i < n; ++i) {
      Object report = Object::New(env);
      report.Set("timestamp", BigInt::New(env, cAlerts[i].report.timestamp));
      report.Set("chip", cAlerts[i].report.chip);
      report.Set("gpio", cAlerts[i].report.gpio);
      report.Set("level", cAlerts[i].report.level);
      report.Set("flags", 0);

      Object alert = Object::New(env);
      alert.Set("report", report);
      alert.Set("nfyHandle", cAlerts[i].nfyHandle);

      jsAlerts.Set(i, alert);
    }

    cb.Call({ jsAlerts });
  });
}

void gpioSetAlertsFunc(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  ThreadSafeFunction cb = ThreadSafeFunction::New(
    env,
    info[2].As<Function>(),
    "GPIO alert callback",
    0,
    1
  );

  int result = lgGpioSetAlertsFunc(handle, gpio, callAlertsFunc, &cb);
  throwIfError(env, "Failed setting alert callback", result);
}

void gpioSetSamplesFunc(const CallbackInfo& info) {
  Env env = info.Env();

  ThreadSafeFunction cb = ThreadSafeFunction::New(
    env,
    info[0].As<Function>(),
    "GPIO samples callback",
    0,
    1
  );

  lgGpioSetSamplesFunc(callAlertsFunc, &cb);
}

Number notifyOpen(const CallbackInfo& info) {
  Env env = info.Env();

  int result = lgNotifyOpen();
  throwIfError(env, "Failed opening notification channel", result);
  return Number::New(env, result);
}

void notifyResume(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgNotifyResume(handle);
  throwIfError(env, "Failed resuming notification channel", result);
}

void notifyPause(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgNotifyPause(handle);
  throwIfError(env, "Failed pausing notification channel", result);
}

void notifyClose(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgNotifyClose(handle);
  throwIfError(env, "Failed closing notification channel", result);
}
