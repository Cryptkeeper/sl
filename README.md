# sl

This is one more single-header C99* string list library. It is intended for:

- LIFO queue usage (last-in-first-out)
- Situations that don't need better performance than `realloc` calls and O(n) counting
- Those who like BSD's [stringlist.h](https://man.freebsd.org/cgi/man.cgi?query=stringlist&apropos=0&sektion=3&manpath=FreeBSD+11-current&format=html) and wish they had a worse, (potentially) more portable version
- Those who haven't already copy/pasted [stb_ds.h](https://github.com/nothings/stb/blob/master/stb_ds.h)
- People who enjoy the risk of NULL terminated data structures

\* *C90 if you don't mind the single-line comments*

## Usage

`sl.h` follows the single-header pattern. To use, include `sl.h` in your project and define `SL_IMPL` exactly once in a C source file of your choice. [More information on using single-header libraries.](https://github.com/nothings/stb/tree/master?tab=readme-ov-file#how-do-i-use-these-libraries)

```c
#define SL_IMPL
#include "sl.h"
```

For specific usage details of the C API, see [sl.h](src/sl.h).

### Customizing

You may override the `realloc`, `free`, and `strdup` calls made internally by defining `SL_OVERRIDE` and then defining each of the following macros:

- `SLX_REALLOC`
- `SLX_FREE`
- `SLX_STRDUP`

Any replacement functions must conform to the same interface as their standard counterparts, including in their error handling.

## Building

1. `git clone https://github.com/Cryptkeeper/sl`
2. `cd sl`
3. `cmake -Bbuild`
4. `cmake --build build`

A static library artifact is available as `build/libsl.a`, and the generated single-header file is available as `build/sl.h`.
