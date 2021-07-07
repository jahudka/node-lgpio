#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Object gpioGetLineInfo(const CallbackInfo& info);

Number gpioGetMode(const CallbackInfo& info);

void gpioClaimInput(const CallbackInfo& info);

void gpioClaimOutput(const CallbackInfo& info);

void gpioFree(const CallbackInfo& info);

Boolean gpioRead(const CallbackInfo& info);

void gpioWrite(const CallbackInfo& info);

void groupClaimInput(const CallbackInfo& info);

void groupClaimOutput(const CallbackInfo& info);

void groupFree(const CallbackInfo& info);

BigInt groupRead(const CallbackInfo& info);

void groupWrite(const CallbackInfo& info);
