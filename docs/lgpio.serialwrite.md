<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [serialWrite](./lgpio.serialwrite.md)

## serialWrite() function

This function writes `txBuf` to the serial device.

<b>Signature:</b>

```typescript
export declare function serialWrite(handle: number, txBuf: Uint8Array): void;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The serial device handle as returned by [serialOpen()](./lgpio.serialopen.md) |
|  txBuf | Uint8Array | The array of bytes to write |

<b>Returns:</b>

void
