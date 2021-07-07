#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


void gpioClaimAlert(const CallbackInfo& info);

void gpioSetDebounce(const CallbackInfo& info);

void gpioSetWatchdog(const CallbackInfo& info);

void gpioSetAlertsFunc(const CallbackInfo& info);

void gpioSetSamplesFunc(const CallbackInfo& info);

Number notifyOpen(const CallbackInfo& info);

void notifyResume(const CallbackInfo& info);

void notifyPause(const CallbackInfo& info);

void notifyClose(const CallbackInfo& info);
