<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [i2cReadWordData](./lgpio.i2creadworddata.md)

## i2cReadWordData() function

This reads a single 16-bit word from the specified register of the device.

<b>Signature:</b>

```typescript
export declare function i2cReadWordData(handle: number, i2cReg: number): number;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The I2C device handle as returned by [i2cOpen()](./lgpio.i2copen.md) |
|  i2cReg | number | 0-0xFF, the register to read |

<b>Returns:</b>

number

0-0xFFFF, the word read from the device
