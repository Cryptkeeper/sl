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

int sladd(slist_t *sl, const char *str) {
  if (sl->len + 1 >= sl->cap) {
    const long newcap = sl->cap == 0 ? 4 : (long)((double)sl->cap * 1.5);
    char **r;
    if ((r = SLX_REALLOC(sl->strings, (newcap + 1) * sizeof(char *))) == NULL)
      return -1;
    sl->strings = r;
    sl->cap = newcap;
  }
  if ((sl->strings[sl->len] = SLX_STRDUP(str)) == NULL)
    return -1;
  sl->strings[++sl->len] = NULL;
  return 0;
}

void slfree(slist_t *sl) {
  if (sl == NULL)
    return;
  long i;
  for (i = 0; sl->strings != NULL && sl->strings[i] != NULL; i++)
    SLX_FREE(sl->strings[i]);
  SLX_FREE(sl->strings);
  sl->strings = NULL;
  sl->len = sl->cap = 0;
}

char *slpop(slist_t *sl) {
  if (sl == NULL || sl->len == 0)
    return NULL;
  sl->len--;
  char *const str = sl->strings[sl->len];
  sl->strings[sl->len] = NULL;
  return str;
}

long slcount(const slist_t *sl) {
  return sl != NULL ? sl->len : 0;
}
