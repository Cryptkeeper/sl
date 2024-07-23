#ifndef SL_H
#define SL_H

typedef char *slist_t;

/// @brief 'sladd' duplicates a string and appends it to the end of the string
/// list. The list is resized by one element to accommodate the new string. The
/// potentially reallocated list is returned in 'sl'. A new string list is
/// allocated by passing a non-NULL pointer (to a NULL value) to `sl`. The
/// caller is responsible for freeing the list using 'slfree'.
/// @param sl The string list to append to, return in the event of reallocation.
/// @param str The string to duplicate and append, must not be NULL.
/// @return 0 if successful and 'sl' is set to the new string list, otherwise -1
/// is returned, 'errno' is set, and the original list is left unchanged.
int sladd(slist_t **sl, const char *str);

/// @brief 'slfree' frees all strings in the string list and the list itself.
/// @param sl The string list to free, may be NULL.
void slfree(slist_t *sl);

/// @brief 'slpop' removes and returns the last element from the string list.
/// This does not resize the array. The "removed" element is instead set to NULL
/// and its memory can be reclaimed by the next call to 'sladd'. The caller is
/// responsible for freeing the returned string using `free`.
/// @param sl The string list to pop from
/// @return The last element removed from the list. If the list is NULL or
/// empty, NULL is returned.
char *slpop(slist_t *sl);

/// @brief 'slcount' returns the number of elements in the string list. This
/// function is O(n) and should be used sparingly in performance-critical code.
/// @param sl The string list to count elements in.
/// @return The number of elements in the list. If the list is NULL or empty, 0
/// is returned. The return value is always non-negative.
long slcount(const slist_t *sl);

#endif // SL_H
