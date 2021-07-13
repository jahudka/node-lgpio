<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [serialReadByte](./lgpio.serialreadbyte.md)

## serialReadByte() function

This function reads a byte from the serial device.

<b>Signature:</b>

```typescript
export declare function serialReadByte(handle: number): number;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The serial device handle as returned by [serialOpen()](./lgpio.serialopen.md) |

<b>Returns:</b>

number

0-0xFF, the value read from the device
