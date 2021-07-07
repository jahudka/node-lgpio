#include <napi.h>
#include <string>

using namespace Napi;
using namespace std;

bool isDefined(const Value& value);

template<class T, typename R>
R getOptionalArg(const CallbackInfo& info, int index, R fallback);

Error createError(const Env& env, string msg, int code = 0);

void throwIfError(const Env& env, string msg, int result);

vector<int> napiArrayToIntVector(const Array& arr, bool coerce = false);
