#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Number gpiochipOpen(const CallbackInfo& info) {
  Env env = info.Env();

  int gpioDev = (int) info[0].As<Number>();
  int result = lgGpiochipOpen(gpioDev);

  throwIfError(env, "Error opening GPIO chip", result);
  return Number::New(env, result);
}

void gpiochipClose(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int result = lgGpiochipClose(handle);
  throwIfError(env, "Error closing GPIO chip", result);
}

Object gpioGetChipInfo(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  lgChipInfo_t cInfo;
  Object jsInfo = Object::New(env);

  int result = lgGpioGetChipInfo(handle, &cInfo);
  throwIfError(env, "Failed getting GPIO chip info", result);

  jsInfo.Set("lines", cInfo.lines);
  jsInfo.Set("name", cInfo.name);
  jsInfo.Set("label", cInfo.label);
  return jsInfo;
}

void gpioSetUser(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  string user = (string) info[1].As<String>();

  int result = lgGpioSetUser(handle, user.c_str());
  throwIfError(env, "Failed setting GPIO user", result);
}
