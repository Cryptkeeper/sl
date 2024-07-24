#undef NDEBUG
#include <assert.h>
#include <string.h>

#include "sl.h"

int main(void) {
  slist_t *sl = NULL;
  assert(slcount(sl) == 0);
  assert(sladd(&sl, "foo") == 0);
  assert(slcount(sl) == 1);
  assert(sladd(&sl, "bar") == 0);
  assert(slcount(sl) == 2);
  assert(strcmp(slpop(sl), "bar") == 0);
  assert(slcount(sl) == 1);
  assert(strcmp(slpop(sl), "foo") == 0);
  assert(slcount(sl) == 0);
  slfree(sl);
  return 0;
}
