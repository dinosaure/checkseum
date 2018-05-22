#include "checkseum.h"
#include "adler32.h"

#ifdef ARCH_SISTYFOUR
/* XXX(dinosaure): un-allocated version for 64-bits architecture. */

CAMLprim value
caml_checkseum_adler32_ba(value t, value src, value off, value len)
{
  return (Val_int (adler32(Int32_val (t), _ba_uint8_off (src, off), Int_val (len))));
}

CAMLprim value
caml_checkseum_adler32_st(value t, value src, value off, value len)
{
  return (Val_int (adler32(Int32_val (t), _st_uint8_off (src, off), Int_val (len))));
}

#else
/* XXX(dinosaure): allocated version for 32-bits architecture. */

CAMLprim value
caml_checkseum_adler32_ba(value t, value src, value off, value len)
{
  return (copy_int32(adler32(Int32_val (t), _ba_uint8_off (src, off), Int_val (len))));
}

CAMLprim value
caml_checkseum_adler32_st(value t, value src, value off, value len)
{
  return (copy_int32(adler32(Int32_val (t), _st_uint8_off (src, off), Int_val (len))));
}

#endif