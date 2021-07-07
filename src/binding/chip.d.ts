import { GpioChipInfo } from '../types';

/**
 * This returns a handle to a gpiochip device.
 *
 * @public
 * @param gpioDev - The GPIO device number.
 * @returns The GPIO device handle.
 */
export declare function gpiochipOpen(gpioDev: number): number;

/**
 * This closes an opened gpiochip device.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 */
export declare function gpiochipClose(handle: number): void;

/**
 * This returns information about a gpiochip.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @returns The GPIO chip info
 */
export declare function gpioGetChipInfo(handle: number): GpioChipInfo;

/**
 * This sets the user string to be associated with each claimed GPIO.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param user - The user name (up to 32 characters)
 */
export declare function gpioSetUser(handle: number, user: string): void;
