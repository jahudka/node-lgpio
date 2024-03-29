<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [gpioClaimOutput](./lgpio.gpioclaimoutput.md)

## gpioClaimOutput() function

This claims a GPIO for output.

<b>Signature:</b>

```typescript
export declare function gpioClaimOutput(handle: number, gpio: number, flags?: GpioFlag, level?: boolean): void;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The GPIO device handle as returned by [gpiochipOpen()](./lgpio.gpiochipopen.md) |
|  gpio | number | The GPIO number |
|  flags | [GpioFlag](./lgpio.gpioflag.md) | <i>(Optional)</i> Bitmask of the available [GPIO flags](./lgpio.gpioflag.md) |
|  level | boolean | <i>(Optional)</i> The initial output logical level |

<b>Returns:</b>

void

