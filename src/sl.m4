// sl.h - single-header string list library
// https://github.com/Cryptkeeper/sl
// MIT licensed
// define SL_IMPL before including this file in a source file
#ifndef SL_SINGLEFILE_H
#define SL_SINGLEFILE_H
#define SL_IMPL_NO_INCLUDE
#line 1 "sl.h"
include(`src/sl.h')
#endif // SL_SINGLEFILE_H
#ifdef SL_IMPL
#ifndef SL_IMPL_ONCE
#define SL_IMPL_ONCE
#line 1 "sl.c"
include(`src/sl.c')
#endif // SL_IMPL_ONCE
#endif // SL_IMPL
