type bigstring = (char, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Array1.t

module type S =
sig
  type t = Optint.t

  val pp: Format.formatter -> t -> unit
  val equal: t -> t -> bool
  val default: t
  val digest_bytes: Bytes.t -> int -> int -> t -> t
  val digest_bigstring: bigstring -> int -> int -> t -> t
  val crc32c_bigstring: bigstring -> int -> int -> t -> t
end

module Adler32: S
