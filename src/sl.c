#ifndef SL_IMPL_NO_INCLUDE
#include "sl.h"
#endif

#ifndef SL_OVERRIDE
#include <stdlib.h> /* for free, realloc, NULL */
#include <string.h> /* for strdup */

#define SLX_REALLOC realloc
#define SLX_FREE free
#define SLX_STRDUP strdup
#endif

int sladd(slist_t **sl, const char *str) {
  slist_t *r = NULL;
  const long c = slcount(*sl);
  if ((r = SLX_REALLOC(*sl, (c + 2) * sizeof(char *))) == NULL ||
      (r[c] = SLX_STRDUP(str)) == NULL)
    return -1;
  r[c + 1] = NULL;
  *sl = r;
  return 0;
}

void slfree(slist_t *sl) {
  long i;
  for (i = 0; sl != NULL && sl[i] != NULL; i++)
    SLX_FREE(sl[i]);
  SLX_FREE(sl);
}

char *slpop(slist_t *sl) {
  const long c = slcount(sl);
  char *r = NULL;
  if (c == 0)
    return NULL;
  r = sl[c - 1];
  sl[c - 1] = NULL;
  return r;
}

long slcount(const slist_t *sl) {
  long c = 0;
  for (; sl != NULL && sl[c] != NULL; c++)
    ;
  return c;
}
