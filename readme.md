# NodeJS bindings for `lg`

This package provides NodeJS bindings
for the [`lg`](http://abyz.me.uk/lg/index.html) GPIO library.

## Disclaimer

This is my first time writing native Node bindings for a C library.
Heck, it's my first time writing _any_ C/C++ code! So if things don't
work as expected, or if the bindings leak memory like nobody's business,
please don't be too hard on me. I'll be happy for any issue reports
and / or pull requests.

## Prerequisites

You need to have the `lg` library installed on your system.
Since the library doesn't compile outside Linux, this might complicate
things slightly. This package can be installed anywhere, but the bindings
themselves will only be compiled on Linux to prevent `npm install` from
dying all the time. This should enable you to develop on your local machine
regardless of platform or architecture and run the code on machines which
actually have GPIO for the underlying library to work with.

On a Raspberry Pi the `lg` library is easily downloaded, compiled and installed
in three commands. Refer to the library website for the how-to.

## Installation

```shell
npm install --save lgpio
```

## Docs

The [docs](./docs/lgpio.md) are autogenerated from the (pretty extensive)
JSDocs which are present in the included TypeScript declaration files.
Most of the documentation is copied verbatim from the `lg` library docs,
only altered where it makes sense.

## About

The bindings are mostly 1:1 with the underlying C functions, except the `lg`
prefix is stripped from the function names (you'll usually want to `import * as lg`
anyway). The call signatures are mostly kept identical, except for obvious
differences:
 - All functions which indicate an error by returning a negative integer value
   throw an error instead; this means all functions whose return value _only_
   signifies success or failure return `void` in JS.
 - Passing array length separately from the array itself (as you need to do in C)
   is unnecessary in JS, so the array length / count parameters are omitted where
   applicable.
 - Some parameters can be omitted and fall back to sane defaults (like the initial
   output level of a GPIO, which defaults to low).
