#include <napi.h>
#include <string>

#include <lgpio.h>

using namespace Napi;
using namespace std;

bool isDefined(const Value& value) {
  return !value.IsUndefined() && !value.IsNull();
}

Error createError(const Env& env, string msg, int code = 0) {
  if (code != 0) {
    return Error::New(env, msg + ": " + lguErrorText(code));
  } else {
    return Error::New(env, msg);
  }
}

void throwIfError(const Env& env, string msg, int result) {
  if (result < 0) {
    throw createError(env, msg, result);
  }
}

vector<int> napiArrayToIntVector(const Array& arr, bool coerce = false) {
  vector<int> result;
  size_t n = arr.Length();
  result.reserve(n);

  for (size_t i = 0; i < n; ++i) {
    result.push_back((int) (coerce ? arr[i].ToNumber() : arr[i].As<Number>()));
  }

  return result;
}
