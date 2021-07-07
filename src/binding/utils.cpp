#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


BigInt timestamp(const CallbackInfo& info) {
  Env env = info.Env();
  return BigInt::New(env, lguTimestamp());
}

Number version(const CallbackInfo& info) {
  Env env = info.Env();
  return Number::New(env, lguVersion());
}

BigInt getInternal(const CallbackInfo& info) {
  Env env = info.Env();

  int cfgId = (int) info[0].As<Number>();
  uint64_t cfgVal;

  int result = lguGetInternal(cfgId, &cfgVal);
  throwIfError(env, "Failed getting internal config value", result);

  return BigInt::New(env, cfgVal);
}

void setInternal(const CallbackInfo& info) {
  Env env = info.Env();

  int cfgId = (int) info[0].As<Number>();
  bool lossless;
  uint64_t cfgVal = info[1].As<BigInt>().Uint64Value(&lossless);

  int result = lguSetInternal(cfgId, cfgVal);
  throwIfError(env, "Failed setting internal config value", result);
}

String errorText(const CallbackInfo& info) {
  Env env = info.Env();

  int errNo = (int) info[0].As<Number>();

  return String::New(env, lguErrorText(errNo));
}

void setWorkDir(const CallbackInfo& info) {
  string dirPath = (string) info[0].As<String>();
  lguSetWorkDir(dirPath.c_str());
}

String getWorkDir(const CallbackInfo& info) {
  Env env = info.Env();
  return String::New(env, lguGetWorkDir());
}
