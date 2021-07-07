<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [gpioSetUser](./lgpio.gpiosetuser.md)

## gpioSetUser() function

This sets the user string to be associated with each claimed GPIO.

<b>Signature:</b>

```typescript
export declare function gpioSetUser(handle: number, user: string): void;
```

## Parameters

|  Parameter | Type | Description |
|  --- | --- | --- |
|  handle | number | The GPIO device handle as returned by [gpiochipOpen()](./lgpio.gpiochipopen.md) |
|  user | string | The user name (up to 32 characters) |

<b>Returns:</b>

void
