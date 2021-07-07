<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [txPwm](./lgpio.txpwm.md)

## txPwm() function

This starts software timed PWM on an output GPIO.

<b>Signature:</b>

```typescript
export declare function txPwm(handle: number, gpio: number, pwmFrequency: number, pwmDutyCycle: number, pwmOffset?: number, pwmCycles?: number): number;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The GPIO device handle as returned by [gpiochipOpen()](./lgpio.gpiochipopen.md) |
|  gpio | number | The GPIO number |
|  pwmFrequency | number | The PWM frequency in Hz (0=off, 0.1-10000) |
|  pwmDutyCycle | number | The PWM duty cycle in % (0-100) |
|  pwmOffset | number | Offset from nominal pulse start position |
|  pwmCycles | number | The number of pulses to send, 0 or unspecified for infinite |

<b>Returns:</b>

number

The number of entries left in the PWM queue for the GPIO

## Remarks

Each successful call to this function consumes one PWM queue entry.

PWM is characterised by two values, its frequency (number of cycles per second) and its duty cycle (percentage of high time per cycle).

Another PWM command may be issued to the GPIO before the last has finished.

If the last pulse had infinite cycles then it will be replaced by the new settings at the end of the current cycle. Otherwise it will be replaced by the new settings when all its cycles are complete.

Multiple PWM settings may be queued in this way.
