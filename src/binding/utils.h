#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;


BigInt timestamp(const CallbackInfo& info);

Number version(const CallbackInfo& info);

BigInt getInternal(const CallbackInfo& info);

void setInternal(const CallbackInfo& info);

String errorText(const CallbackInfo& info);

void setWorkDir(const CallbackInfo& info);

String getWorkDir(const CallbackInfo& info);
