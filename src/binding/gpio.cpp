#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Object gpioGetLineInfo(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  lgLineInfo_t cInfo;
  Object jsInfo = Object::New(env);

  int result = lgGpioGetLineInfo(handle, gpio, &cInfo);
  throwIfError(env, "Failed getting GPIO line info", result);

  jsInfo.Set("flags", cInfo.lFlags);
  jsInfo.Set("name", cInfo.name);
  jsInfo.Set("user", cInfo.user);
  return jsInfo;
}

Number gpioGetMode(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  int result = lgGpioGetMode(handle, gpio);
  throwIfError(env, "Failed getting GPIO mode", result);

  return Number::New(env, result);
}

void gpioClaimInput(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int flags = getOptionalArg<Number, int>(info, 2, 0);

  int result = lgGpioClaimInput(handle, flags, gpio);
  throwIfError(env, "Failed claiming GPIO input", result);
}

void gpioClaimOutput(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  int flags = getOptionalArg<Number, int>(info, 2, 0);
  bool level = getOptionalArg<Boolean, bool>(info, 3, false);

  int result = lgGpioClaimOutput(handle, flags, gpio, level ? 1 : 0);
  throwIfError(env, "Failed claiming GPIO output", result);
}

void gpioFree(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  int result = lgGpioFree(handle, gpio);
  throwIfError(env, "Failed freeing GPIO", result);
}

Boolean gpioRead(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  int result = lgGpioRead(handle, gpio);
  throwIfError(env, "Failed reading GPIO", result);
  return Boolean::New(env, (bool) result);
}

void gpioWrite(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  bool level = (bool) info[2].ToBoolean();

  int result = lgGpioWrite(handle, gpio, level ? 1 : 0);
  throwIfError(env, "Failed writing GPIO", result);
}

void groupClaimInput(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  vector<int> gpios = napiArrayToIntVector(info[1].As<Array>());
  int flags = getOptionalArg<Number, int>(info, 2, 0);

  int result = lgGroupClaimInput(handle, flags, gpios.size(), &gpios[0]);
  throwIfError(env, "Failed claiming GPIO input group", result);
}

void groupClaimOutput(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  vector<int> gpios = napiArrayToIntVector(info[1].As<Array>());
  size_t n = gpios.size();

  vector<int> levels;

  if (info.Length() > 2 && isDefined(info[2])) {
    levels = napiArrayToIntVector(info[2].As<Array>(), true);
  }

  if (levels.size() < n) {
    levels.reserve(n);

    for (size_t i = levels.size(); i < n; ++i) {
      levels.push_back(0);
    }
  }

  int flags = getOptionalArg<Number, int>(info, 3, 0);

  int result = lgGroupClaimOutput(handle, flags, n, &gpios[0], &levels[0]);
  throwIfError(env, "Failed claiming GPIO output group", result);
}

void groupFree(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  int result = lgGroupFree(handle, gpio);
  throwIfError(env, "Failed freeing GPIO group", result);
}

BigInt groupRead(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();

  uint64_t values;
  int result = lgGroupRead(handle, gpio, &values);
  throwIfError(env, "Failed reading GPIO group", result);

  return BigInt::New(env, values);
}

void groupWrite(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int gpio = (int) info[1].As<Number>();
  bool lossless;
  uint64_t values = info[2].As<BigInt>().Uint64Value(&lossless);
  uint64_t mask;

  if (info.Length() > 3) {
    mask = info[3].As<BigInt>().Uint64Value(&lossless);
  } else {
    mask = 0xFFFFFFFFFFFFFFFFULL;
  }

  int result = lgGroupWrite(handle, gpio, values, mask);
  throwIfError(env, "Failed writing GPIO group", result);
}
