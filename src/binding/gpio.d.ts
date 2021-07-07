import { GpioFlag, GpioLineInfo, GpioMode } from '../types';

/**
 * Returns information about a GPIO.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @returns Information about the specified GPIO
 */
export declare function gpioGetLineInfo(handle: number, gpio: number): GpioLineInfo;

/**
 * Returns the GPIO mode.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @returns The GPIO mode
 */
export declare function gpioGetMode(handle: number, gpio: number): GpioMode;

/**
 * This claims a GPIO for input.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param flags - Bitmask of the available {@link GpioFlag|GPIO flags}
 */
export declare function gpioClaimInput(handle: number, gpio: number, flags?: GpioFlag): void;

/**
 * This claims a GPIO for output.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param flags - Bitmask of the available {@link GpioFlag|GPIO flags}
 * @param level - The initial output logical level
 */
export declare function gpioClaimOutput(handle: number, gpio: number, flags?: GpioFlag, level?: boolean): void;

/**
 * This frees a GPIO.
 *
 * @remarks
 * Note that the GPIO state will not be reset by this function, so if the GPIO was
 * e.g. an output and its state was high, it will remain so even after it's freed
 * by calling this function.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 */
export declare function gpioFree(handle: number, gpio: number): void;

/**
 * This returns the level of a GPIO.
 *
 * @remarks
 * This command will work for any claimed GPIO (even if a member of a group).
 * For an output GPIO the value returned will be that last written to the GPIO.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @returns The current logical level of the GPIO
 */
export declare function gpioRead(handle: number, gpio: number): boolean;

/**
 * This sets the level of an output GPIO.
 *
 * @remarks
 * This command will work for any GPIO claimed as an output (even if a member of a group).
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param level - The logical level to set
 */
export declare function gpioWrite(handle: number, gpio: number, level: boolean): void;

/**
 * This claims a group of GPIO for inputs.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpios - An array of one or more GPIO; the first GPIO is called
 *                         the group leader and is used to reference the group as a whole
 * @param flags - Bitmask of the available {@link GpioFlag|GPIO flags}
 */
export declare function groupClaimInput(handle: number, gpios: number[], flags?: GpioFlag): void;

/**
 * This claims a group of GPIO for outputs.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpios - An array of one or more GPIO; the first GPIO is called
 *                         the group leader and is used to reference the group as a whole
 * @param levels - An array of the initial logical levels for the GPIOs
 * @param flags - Bitmask of the available {@link GpioFlag|GPIO flags}
 */
export declare function groupClaimOutput(handle: number, gpios: number[], levels?: boolean[], flags?: GpioFlag): void;

/**
 * This frees all the GPIO associated with a group.
 *
 * @remarks
 * Same as with {@link gpioFree|gpioFree()} the GPIOs state will not be reset by calling this function.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The group leader GPIO number
 */
export declare function groupFree(handle: number, gpio: number): void;

/**
 * This returns the levels read from a group.
 *
 * @remarks
 * This command will work for an output group as well as an input group.
 * For an output group the value returned will be that last written to the group GPIO.
 *
 * Note that this command will also work on an individual GPIO claimed as an input or output
 * as that is treated as a group with one member.
 *
 * The return value is a bitmask of the levels of the individual GPIOs in the group,
 * with the LSB (bit 0) being the group leader, bit 1 being the second GPIO in the group,
 * bit 2 being the third GPIO and so on.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The group leader GPIO number
 * @returns The values of the GPIOs in the group
 */
export declare function groupRead(handle: number, gpio: number): bigint;

/**
 * This sets the levels of an output group.
 *
 * @remarks
 * The levels of the group members will be set from the `levels` bitmask
 * if the corresponding bit in the `mask` bitmask is set. The LSB (bit 0)
 * corresponds to the group leader, bit 1 is the second group member and so on.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The group leader GPIO number
 * @param levels - The levels to set
 * @param mask - Bitmask indicating the members of the group whose level should be updated
 */
export declare function groupWrite(handle: number, gpio: number, levels: bigint, mask?: bigint): void;
