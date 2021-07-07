import { GpioAlert, GpioEdge, GpioFlag } from '../types';

/**
 * This claims a GPIO for alerts on level changes.
 *
 * @remarks
 * The GPIO flags may be used to set the GPIO as active low, open drain, or open source.
 *
 * The edge flags are used to specify alerts for a rising edge, falling edge, or both edges.
 *
 * The alerts will be sent to a previously opened notification channel. If you don't want them
 * sent to a notification channel set `nfyHandle` to -1 or leave it unspecified.
 *
 * The alerts will also be sent to any callback registered for the GPIO by {@link gpioSetAlertsFunc|gpioSetAlertsFunc()}.
 *
 * All GPIO alerts are also sent to a callback registered by {@link gpioSetSamplesFunc|gpioSetSamplesFunc()}.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param flags - Bitmask of the available {@link GpioFlag|GPIO flags}
 * @param edges - Bitmask of the {@link GpioEdge|edge flags} on which an alert should trigger
 * @param gpio - The GPIO number
 * @param nfyHandle - A notification channel handle as returned by {@link notifyOpen|notifyOpen()}
 */
export declare function gpioClaimAlert(handle: number, flags: GpioFlag, edges: GpioEdge, gpio: number, nfyHandle?: number): void;

/**
 * This sets the debounce time for a GPIO.
 *
 * @remarks
 * This only affects alerts.
 *
 * An alert will only be issued if the edge has been stable for at least debounce microseconds.
 *
 * Generally this is used to debounce mechanical switches (e.g. contact bounce).
 *
 * Note that level changes will be timestamped debounce microseconds after the actual level change.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param debounceUs - The debounce time in microseconds
 */
export declare function gpioSetDebounce(handle: number, gpio: number, debounceUs: number): void;

/**
 * This sets the watchdog time for a GPIO.
 *
 * @remarks
 * This only affects alerts.
 *
 * A watchdog alert will be sent if no edge alert has been issued for that GPIO
 * in the previous watchdog microseconds.
 *
 * Note that only one watchdog alert will be sent per stream of edge alerts.
 * The watchdog is reset by the sending of a new edge alert.
 *
 * The level is set to `GpioLevel.WATCHDOG` (2) for a watchdog alert.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param watchdogUs - The watchdog time in microseconds
 */
export declare function gpioSetWatchdog(handle: number, gpio: number, watchdogUs: number): void;

/**
 * This sets up a callback to be called when an alert GPIO changes state.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param callback - The callback function
 */
export declare function gpioSetAlertsFunc(handle: number, gpio: number, callback: (alerts: GpioAlert[]) => void): void;

/**
 * This sets up a callback to be called when any alert GPIO changes state.
 *
 * @remarks
 * Note that no handle or gpio is specified. The callback function
 * will receive alerts for all gpiochips and gpio.
 *
 * @public
 * @param callback - The callback function
 */
export declare function gpioSetSamplesFunc(callback: (alerts: GpioAlert[]) => void): void;

/**
 * This function requests a free notification.
 *
 * @remarks
 * A notification is a method for being notified of GPIO state changes via a pipe.
 *
 * The notification pipes are created in the library working directory (see {@link getWorkDir|getWorkDir()}).
 *
 * Notifications for handle x will be available at the pipe named `.lgd-nfy*`
 * (where `*` is the handle number). E.g. if the function returns 15 then the notifications
 * must be read from `.lgd-nfy15`.
 *
 * The notification gets state changes for each associated GPIO.
 *
 * Each notification occupies 16 bytes in the fifo and has the following structure:
 *
 *  - `timestamp` (`uint64`): The alert time in nanoseconds since the UNIX epoch
 *  - `chip` (`uint8`): The gpiochip device number
 *  - `gpio` (`uint8`): Offset into the gpio device
 *  - `level` (`uint8`): The GPIO level (0=low, 1=high, 2=watchdog)
 *  - `flags` (`uint8`): None currently defined
 *
 * For future proofing it is probably best to ignore any notification with non-zero flags.
 *
 * @public
 * @returns The notification channel handle
 */
export declare function notifyOpen(): number;

/**
 * This function restarts notifications on a paused notification.
 *
 * @public
 * @param handle - The notification handle as returned by {@link notifyOpen|notifyOpen()}
 */
export declare function notifyResume(handle: number): void;

/**
 * This function pauses notifications.
 *
 * @public
 * @param handle - The notification handle as returned by {@link notifyOpen|notifyOpen()}
 */
export declare function notifyPause(handle: number): void;

/**
 * This function stops notifications and frees the handle for reuse.
 *
 * @public
 * @param handle - The notification handle as returned by {@link notifyOpen|notifyOpen()}
 */
export declare function notifyClose(handle: number): void;
