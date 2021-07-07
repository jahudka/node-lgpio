<!-- Do not edit this file. It is automatically generated by API Documenter. -->

[Home](./index.md) &gt; [lgpio](./lgpio.md) &gt; [notifyOpen](./lgpio.notifyopen.md)

## notifyOpen() function

This function requests a free notification.

<b>Signature:</b>

```typescript
export declare function notifyOpen(): number;
```
<b>Returns:</b>

number

The notification channel handle

## Remarks

A notification is a method for being notified of GPIO state changes via a pipe.

The notification pipes are created in the library working directory (see [getWorkDir()](./lgpio.getworkdir.md)<!-- -->).

Notifications for handle x will be available at the pipe named `.lgd-nfy*` (where `*` is the handle number). E.g. if the function returns 15 then the notifications must be read from `.lgd-nfy15`<!-- -->.

The notification gets state changes for each associated GPIO.

Each notification occupies 16 bytes in the fifo and has the following structure:

- `timestamp` (`uint64`<!-- -->): The alert time in nanoseconds since the UNIX epoch

- `chip` (`uint8`<!-- -->): The gpiochip device number

- `gpio` (`uint8`<!-- -->): Offset into the gpio device

- `level` (`uint8`<!-- -->): The GPIO level (0=low, 1=high, 2=watchdog)

- `flags` (`uint8`<!-- -->): None currently defined

For future proofing it is probably best to ignore any notification with non-zero flags.
