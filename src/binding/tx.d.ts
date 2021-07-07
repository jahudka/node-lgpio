import { TxKind, TxWavePulse } from '../types';

/**
 * This starts software timed pulses on an output GPIO.
 *
 * @remarks
 * If both `pulseOn` and `pulseOff` are zero pulses will be switched off for that GPIO.
 * The active pulse, if any, will be stopped and any queued pulses will be deleted.
 *
 * Each successful call to this function consumes one PWM queue entry.
 *
 * `pulseCycles` cycles are transmitted (0 or unspecified means infinite).
 * Each cycle consists of `pulseOn` microseconds of GPIO high followed by
 * `pulseOff` microseconds of GPIO low.
 *
 * PWM is characterised by two values, its frequency (number of cycles per second)
 * and its duty cycle (percentage of high time per cycle).
 *
 * The set frequency will be `1000000 / (pulseOn + pulseOff)` Hz.
 *
 * The set duty cycle will be `pulseOn / (pulseOn + pulseOff) * 100` %.
 *
 * E.g. if `pulseOn` is 50 and `pulseOff` is 100 the frequency will be 6666.67 Hz
 * and the duty cycle will be 33.33 %.
 *
 * `pulseOffset` is a microsecond offset from the natural start of the PWM cycle.
 *
 * For instance if the PWM frequency is 10 Hz the natural start of each cycle is at seconds 0,
 * then 0.1, 0.2, 0.3 etc. In this case if the offset is 20000 microseconds the cycle
 * will start at seconds 0.02, 0.12, 0.22, 0.32 etc.
 *
 * Another pulse command may be issued to the GPIO before the last has finished.
 *
 * If the last pulse had infinite cycles then it will be replaced by the new settings
 * at the end of the current cycle. Otherwise it will be replaced by the new settings
 * when all its cycles are compete.
 *
 * Multiple pulse settings may be queued in this way.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param pulseOn - Pulse high time in microseconds
 * @param pulseOff - Pulse low time in microseconds
 * @param pulseOffset - Offset from nominal pulse start position
 * @param pulseCycles - The number of pulses to send, 0 or unspecified for infinite
 * @returns The number of entries left in the PWM queue for the GPIO
 */
export declare function txPulse(handle: number, gpio: number, pulseOn: number, pulseOff: number, pulseOffset?: number, pulseCycles?: number): number;

/**
 * This starts software timed PWM on an output GPIO.
 *
 * @remarks
 * Each successful call to this function consumes one PWM queue entry.
 *
 * PWM is characterised by two values, its frequency (number of cycles per second)
 * and its duty cycle (percentage of high time per cycle).
 *
 * Another PWM command may be issued to the GPIO before the last has finished.
 *
 * If the last pulse had infinite cycles then it will be replaced by the new settings
 * at the end of the current cycle. Otherwise it will be replaced by the new settings
 * when all its cycles are complete.
 *
 * Multiple PWM settings may be queued in this way.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param pwmFrequency - The PWM frequency in Hz (0=off, 0.1-10000)
 * @param pwmDutyCycle - The PWM duty cycle in % (0-100)
 * @param pwmOffset - Offset from nominal pulse start position
 * @param pwmCycles - The number of pulses to send, 0 or unspecified for infinite
 * @returns The number of entries left in the PWM queue for the GPIO
 */
export declare function txPwm(handle: number, gpio: number, pwmFrequency: number, pwmDutyCycle: number, pwmOffset?: number, pwmCycles?: number): number;

/**
 * This starts software timed servo pulses on an output GPIO.
 *
 * @remarks
 * I would only use software timed servo pulses for testing purposes. The timing jitter
 * will cause the servo to fidget. This may cause it to overheat and wear out prematurely.
 *
 * Each successful call to this function consumes one PWM queue entry.
 *
 * Another servo command may be issued to the GPIO before the last has finished.
 *
 * If the last pulse had infinite cycles then it will be replaced by the new settings
 * at the end of the current cycle. Otherwise it will be replaced by the new settings
 * when all its cycles are compete.
 *
 * Multiple servo settings may be queued in this way.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The GPIO number
 * @param pulseWidth - Pulse high time in microseconds (0=off, 500-2500)
 * @param servoFrequency - The number of pulses per second (40-500)
 * @param servoOffset - Offset from nominal pulse start position
 * @param servoCycles - The number of pulses to be sent, 0 or unspecified for infinite
 * @returns The number of entries left in the PWM queue for the GPIO
 */
export declare function txServo(handle: number, gpio: number, pulseWidth: number, servoFrequency: number, servoOffset?: number, servoCycles?: number): number;

/**
 * This starts a wave on an output group of GPIOs.
 *
 * @remarks
 * Each successful call to this function consumes one queue entry.
 *
 * This command starts a wave of pulses.
 *
 * `pulses` is an array of pulses to be transmitted on the group.
 *
 * Each pulse is defined by an object with the following properties:
 *
 *  - `bits` (`bigint`): the levels to set for the selected GPIO
 *  - `mask` (`bigint`): the GPIO to select
 *  - `delay` (`number`): the delay in microseconds before the next pulse
 *
 * Another wave command may be issued to the group before the last has finished transmission.
 * The new wave will start when the previous wave has competed.
 *
 * Multiple waves may be queued in this way.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The group leader GPIO number
 * @param pulses - The pulses
 * @returns The number of entries left in the wave queue for the GPIO group
 */
export declare function txWave(handle: number, gpio: number, pulses: TxWavePulse[]): number;

/**
 * This returns true if transmissions of the specified kind are active on the GPIO or group.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The number of the GPIO or group leader to check
 * @param kind - The transmission type to check
 * @returns True if a transmission is active, false otherwise
 */
export declare function txBusy(handle: number, gpio: number, kind: TxKind): boolean;

/**
 * This returns the number of entries available for queueing transmissions
 * of the specified kind on the GPIO or group.
 *
 * @public
 * @param handle - The GPIO device handle as returned by {@link gpiochipOpen|gpiochipOpen()}
 * @param gpio - The number of the GPIO or group leader to check
 * @param kind - The queue type to check
 * @returns The number of free entries in the queue
 */
export declare function txRoom(handle: number, gpio: number, kind: TxKind): number;
