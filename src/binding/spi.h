#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Number spiOpen(const CallbackInfo& info);

void spiClose(const CallbackInfo& info);

Number spiRead(const CallbackInfo& info);

Number spiWrite(const CallbackInfo& info);

Number spiXfer(const CallbackInfo& info);
