#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Number spiOpen(const CallbackInfo& info) {
  Env env = info.Env();

  int dev = (int) info[0].As<Number>();
  int chan = (int) info[1].As<Number>();
  int baud = (int) info[2].As<Number>();
  int flags = getOptionalArg<Number, int>(info, 3, 0);

  int result = lgSpiOpen(dev, chan, baud, flags);
  throwIfError(env, "Error opening SPI device", result);

  return Number::New(env, result);
}

void spiClose(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgSpiClose(handle);
  throwIfError(env, "Error closing SPI device", result);
}

Number spiRead(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array rxBuf = info[1].As<Uint8Array>();
  int count = rxBuf.ByteLength();

  char* buf = (char *) malloc(sizeof(char) * count);
  int result = lgSpiRead(handle, buf, count);
  throwIfError(env, "Error reading from SPI device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}

Number spiWrite(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array buf = info[1].As<Uint8Array>();

  int result = lgSpiWrite(handle, reinterpret_cast<const char*>(buf.Data()), buf.ByteLength());
  throwIfError(env, "Error writing to SPI device", result);

  return Number::New(env, result);
}

Number spiXfer(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array txBuf = info[1].As<Uint8Array>();
  Uint8Array rxBuf = info[2].As<Uint8Array>();
  int count = txBuf.ByteLength();

  if (count > (int) rxBuf.ByteLength()) {
    throw createError(env, "rxBuf length is smaller than txBuf length");
  }

  char* buf = (char *) malloc(sizeof(char) * count);
  int result = lgSpiXfer(handle, reinterpret_cast<const char*>(txBuf.Data()), buf, count);
  throwIfError(env, "Error communicating with SPI device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}
