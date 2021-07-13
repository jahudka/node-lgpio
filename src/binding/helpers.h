#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;

bool isDefined(const Value& value);

template<class T, typename R> inline
R getOptionalArg(const CallbackInfo& info, size_t index, R fallback) {
  if (info.Length() > index && isDefined(info[index])) {
    return (R) info[index].As<T>();
  }

  return fallback;
}

Error createError(const Env& env, string msg, int code = 0);

void throwIfError(const Env& env, string msg, int result);

vector<int> napiArrayToIntVector(const Array& arr, bool coerce = false);
