#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Number gpiochipOpen(const CallbackInfo& info);

void gpiochipClose(const CallbackInfo& info);

Object gpioGetChipInfo(const CallbackInfo& info);

void gpioSetUser(const CallbackInfo& info);
