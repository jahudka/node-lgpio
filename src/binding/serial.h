#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


Number serialOpen(const CallbackInfo& info);

void serialClose(const CallbackInfo& info);

void serialWriteByte(const CallbackInfo& info);

Number serialReadByte(const CallbackInfo& info);

void serialWrite(const CallbackInfo& info);

Number serialRead(const CallbackInfo& info);

Number serialDataAvailable(const CallbackInfo& info);
