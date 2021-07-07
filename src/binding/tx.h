#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Number txPulse(const CallbackInfo& info);

Number txPwm(const CallbackInfo& info);

Number txServo(const CallbackInfo& info);

Number txWave(const CallbackInfo& info);

Boolean txBusy(const CallbackInfo& info);

Number txRoom(const CallbackInfo& info);
