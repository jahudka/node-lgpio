<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [i2cReadByte](./lgpio.i2creadbyte.md)

## i2cReadByte() function

This reads a single byte from the device.

<b>Signature:</b>

```typescript
export declare function i2cReadByte(handle: number): number;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The I2C device handle as returned by [i2cOpen()](./lgpio.i2copen.md) |

<b>Returns:</b>

number

0-0xFF, the value read from the device

