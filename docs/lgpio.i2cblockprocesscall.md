<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [i2cBlockProcessCall](./lgpio.i2cblockprocesscall.md)

## i2cBlockProcessCall() function

This writes data bytes to the specified register of the device and reads a device specified number of bytes of data in return.

<b>Signature:</b>

```typescript
export declare function i2cBlockProcessCall(handle: number, i2cReg: number, ioBuf: Uint8Array, count: number): number;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The I2C device handle as returned by [i2cOpen()](./lgpio.i2copen.md) |
|  i2cReg | number | 0-0xFF, the register to read |
|  ioBuf | Uint8Array | The IO buffer |
|  count | number | The number of bytes to write from the IO buffer |

<b>Returns:</b>

number

The number of bytes written back to the IO buffer

## Remarks

The `ioBuf` parameter should contain data you wish to write to the device and it will be updated by the data the device returns. The return value of the function indicates how many bytes were written back to the IO buffer.

