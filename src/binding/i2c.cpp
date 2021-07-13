#include <napi.h>
#include <string>

#include <lgpio.h>

#include "./helpers.h"

using namespace Napi;
using namespace std;


Number i2cOpen(const CallbackInfo& info) {
  Env env = info.Env();

  int dev = (int) info[0].As<Number>();
  int addr = (int) info[1].As<Number>();
  int flags = getOptionalArg<Number, int>(info, 2, 0);

  int result = lgI2cOpen(dev, addr, flags);
  throwIfError(env, "Error opening I2C device", result);

  return Number::New(env, result);
}

void i2cClose(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgI2cClose(handle);
  throwIfError(env, "Error closing I2C device", result);
}

void i2cWriteQuick(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int bitVal = (int) info[1].As<Number>();

  int result = lgI2cWriteQuick(handle, bitVal);
  throwIfError(env, "Error writing to I2C device", result);
}

void i2cWriteByte(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int byteVal = (int) info[1].As<Number>();

  int result = lgI2cWriteByte(handle, byteVal);
  throwIfError(env, "Error writing to I2C device", result);
}

Number i2cReadByte(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();

  int result = lgI2cReadByte(handle);
  throwIfError(env, "Error reading from I2C device", result);

  return Number::New(env, result);
}

void i2cWriteByteData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  int byteVal = (int) info[2].As<Number>();

  int result = lgI2cWriteByteData(handle, reg, byteVal);
  throwIfError(env, "Error writing to I2C device", result);
}

void i2cWriteWordData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  int wordVal = (int) info[2].As<Number>();

  int result = lgI2cWriteWordData(handle, reg, wordVal);
  throwIfError(env, "Error writing to I2C device", result);
}

Number i2cReadByteData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();

  int result = lgI2cReadByteData(handle, reg);
  throwIfError(env, "Error reading from I2C device", result);

  return Number::New(env, result);
}

Number i2cReadWordData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();

  int result = lgI2cReadWordData(handle, reg);
  throwIfError(env, "Error reading from I2C device", result);

  return Number::New(env, result);
}

Number i2cProcessCall(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  int wordVal = (int) info[2].As<Number>();

  int result = lgI2cProcessCall(handle, reg, wordVal);
  throwIfError(env, "Error communicating with I2C device", result);

  return Number::New(env, result);
}

void i2cWriteBlockData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  Uint8Array buf = info[2].As<Uint8Array>();

  int result = lgI2cWriteBlockData(handle, reg, reinterpret_cast<const char*>(buf.Data()), buf.ByteLength());
  throwIfError(env, "Error writing to I2C device", result);
}

Number i2cReadBlockData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  Uint8Array rxBuf = info[2].As<Uint8Array>();

  if (rxBuf.ByteLength() < 32) {
    throw createError(env, "rxBuf length is too small, minimum is 32");
  }

  char* buf = (char *) malloc(sizeof(char) * 32);
  int result = lgI2cReadBlockData(handle, reg, buf);
  throwIfError(env, "Error reading from I2C device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}

Number i2cBlockProcessCall(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  Uint8Array io = info[2].As<Uint8Array>();
  int count = (int) info[3].As<Number>();

  if (io.ByteLength() < 32) {
    throw createError(env, "io length is too small, minimum is 32");
  }

  char* ioBuf = (char *) malloc(sizeof(char) * 32);

  for (int i = 0; i < count; ++i) {
    ioBuf[i] = (char) io[i];
  }

  int result = lgI2cBlockProcessCall(handle, reg, ioBuf, count);
  throwIfError(env, "Error communicating with I2C device", result);

  for (int i = 0; i < result; ++i) {
    io[i] = (uint8_t) ioBuf[i];
  }

  free(ioBuf);
  return Number::New(env, result);
}

Number i2cReadI2CBlockData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  Uint8Array rxBuf = info[2].As<Uint8Array>();
  int count = rxBuf.ByteLength();

  char* buf = (char *) malloc(sizeof(char) * count);

  int result = lgI2cReadI2CBlockData(handle, reg, buf, count);
  throwIfError(env, "Error reading from I2C device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}

void i2cWriteI2CBlockData(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  int reg = (int) info[1].As<Number>();
  Uint8Array buf = info[2].As<Uint8Array>();

  int result = lgI2cWriteI2CBlockData(handle, reg, reinterpret_cast<const char*>(buf.Data()), buf.ByteLength());
  throwIfError(env, "Error writing to I2C device", result);
}

Number i2cReadDevice(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array rxBuf = info[1].As<Uint8Array>();
  int count = rxBuf.ByteLength();

  char* buf = (char *) malloc(sizeof(char) * count);

  int result = lgI2cReadDevice(handle, buf, count);
  throwIfError(env, "Error reading from I2C device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}

void i2cWriteDevice(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array buf = info[1].As<Uint8Array>();

  int result = lgI2cWriteDevice(handle, reinterpret_cast<const char*>(buf.Data()), buf.ByteLength());
  throwIfError(env, "Error communicating with I2C device", result);
}

Number i2cSegments(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Array jsSegments = info[1].As<Array>();

  vector<lgI2cMsg_t> cSegments;
  int n = jsSegments.Length();

  cSegments.reserve(n);

  for (int i = 0; i < n; ++i) {
    Object jsSegment = jsSegments.Get(i).As<Object>();
    lgI2cMsg_t cSegment;
    cSegment.addr = (uint32_t) jsSegment.Get("addr").As<Number>();
    cSegment.flags = (uint32_t) jsSegment.Get("flags").As<Number>();
    Uint8Array jsBuf = jsSegment.Get("buf").As<Uint8Array>();
    cSegment.len = jsBuf.ByteLength();
    cSegment.buf = jsBuf.Data();
    cSegments.push_back(cSegment);
  }

  int result = lgI2cSegments(handle, &cSegments[0], n);
  throwIfError(env, "Error communicating with I2C device", result);

  return Number::New(env, result);
}

Number i2cZip(const CallbackInfo& info) {
  Env env = info.Env();

  int handle = (int) info[0].As<Number>();
  Uint8Array txBuf = info[1].As<Uint8Array>();
  Uint8Array rxBuf = info[2].As<Uint8Array>();
  int rxBufSize = rxBuf.ByteLength();

  char* buf = (char *) malloc(sizeof(char) * rxBufSize);

  int result = lgI2cZip(handle, reinterpret_cast<const char*>(txBuf.Data()), txBuf.ByteLength(), buf, rxBufSize);
  throwIfError(env, "Error communicating with I2C device", result);

  for (int i = 0; i < result; ++i) {
    rxBuf[i] = (uint8_t) buf[i];
  }

  free(buf);
  return Number::New(env, result);
}
