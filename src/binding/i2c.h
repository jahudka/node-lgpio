#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Number i2cOpen(const CallbackInfo& info);

void i2cClose(const CallbackInfo& info);

void i2cWriteQuick(const CallbackInfo& info);

void i2cWriteByte(const CallbackInfo& info);

Number i2cReadByte(const CallbackInfo& info);

void i2cWriteByteData(const CallbackInfo& info);

void i2cWriteWordData(const CallbackInfo& info);

Number i2cReadByteData(const CallbackInfo& info);

Number i2cReadWordData(const CallbackInfo& info);

Number i2cProcessCall(const CallbackInfo& info);

void i2cWriteBlockData(const CallbackInfo& info);

Number i2cReadBlockData(const CallbackInfo& info);

Number i2cBlockProcessCall(const CallbackInfo& info);

Number i2cReadI2CBlockData(const CallbackInfo& info);

void i2cWriteI2CBlockData(const CallbackInfo& info);

Number i2cReadDevice(const CallbackInfo& info);

void i2cWriteDevice(const CallbackInfo& info);

Number i2cSegments(const CallbackInfo& info);

Number i2cZip(const CallbackInfo& info);
