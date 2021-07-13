#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Number serialOpen(const CallbackInfo& info) {
  Env env = info.Env();

  string dev = (string) info[0].As<String>();
  int baud = (int) info[1].As<Number>();
  int flags = getOptionalArg<Number, int>(info, 2, 0);

  int result = lgSerialOpen(dev.c_str(), baud, flags);
  throwIfError(env, "Error opening serial device", result);

  return Number::New(env, result);
}

void serialClose(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgSerialClose(handle);
  throwIfError(env, "Error closing serial device", result);
}

void serialWriteByte(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int byteVal = (int) info[1].As<Number>();

  int result = lgSerialWriteByte(handle, byteVal);
  throwIfError(env, "Error writing to serial device", result);
}

Number serialReadByte(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgSerialReadByte(handle);
  throwIfError(env, "Error reading from serial device", result);

  return Number::New(env, result);
}

void serialWrite(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array buf = info[1].As<Uint8Array>();

  int result = lgSerialWrite(handle, reinterpret_cast<const char*>(buf.Data()), buf.ByteLength());
  throwIfError(env, "Error writing to serial device", result);
}

Number serialRead(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array rxBuf = info[1].As<Uint8Array>();
  int count = rxBuf.ByteLength();

  char* buf = (char *) malloc(sizeof(char) * count);
  int result = lgSerialRead(handle, buf, count);
  throwIfError(env, "Error reading from serial device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}

Number serialDataAvailable(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgSerialDataAvailable(handle);
  throwIfError(env, "Error communicating with serial device", result);

  return Number::New(env, result);
}
