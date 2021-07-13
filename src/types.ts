/**
 * Information about the GPIO chip.
 *
 * @remarks
 * See {@link gpioGetChipInfo|gpioGetChipInfo()}.
 *
 * @public
 */
export type GpioChipInfo = {
  lines: number;
  name: string;
  label: string;
};

/**
 * Information about a GPIO.
 *
 * @remarks
 * See {@link gpioGetLineInfo|gpioGetLineInfo()}.
 *
 * @public
 */
export declare type GpioLineInfo = {
  flags: GpioLineMode;
  name: string;
  user: string;
};

/**
 * Bitmask representing the GPIO line mode.
 *
 * @remarks
 * See {@link GpioLineInfo} and {@link gpioGetLineInfo|gpioGetLineInfo()}.
 *
 * @public
 */
export enum GpioLineMode {
  KERNEL_IN_USE = 1 << 0,
  OUTPUT = 1 << 1,
  ACTIVE_LOW = 1 << 2,
  OPEN_DRAIN = 1 << 3,
  OPEN_SOURCE = 1 << 4,
}

/**
 * Bitmask representing the GPIO mode.
 *
 * @remarks
 * See {@link gpioGetMode|gpioGetMode()}.
 *
 * @public
 */
export enum GpioMode {
  KERNEL_IN_USE = 1 << 0,
  KERNEL_OUTPUT = 1 << 1,
  KERNEL_ACTIVE_LOW = 1 << 2,
  KERNEL_OPEN_DRAIN = 1 << 3,
  KERNEL_OPEN_SOURCE = 1 << 4,
  KERNEL_UNUSED_1 = 1 << 5,
  KERNEL_UNUSED_2 = 1 << 6,
  KERNEL_UNUSED_3 = 1 << 7,
  INPUT = 1 << 8,
  OUTPUT = 1 << 9,
  ALERT = 1 << 10,
  GROUP = 1 << 11,
  UNUSED_1 = 1 << 12,
  UNUSED_2 = 1 << 13,
  UNUSED_3 = 1 << 14,
  UNUSED_4 = 1 << 15,
}

/**
 * Bitmask for configuring GPIO options.
 *
 * @remarks
 * See:
 *  - {@link gpioClaimInput|gpioClaimInput()}
 *  - {@link gpioClaimOutput|gpioClaimOutput()}
 *  - {@link groupClaimInput|groupClaimInput()}
 *  - {@link groupClaimOutput|groupClaimOutput()}
 *  - {@link gpioClaimAlert|gpioClaimAlert()}
 *
 * @public
 */
export enum GpioFlag {
  SET_ACTIVE_LOW = 1 << 2,
  SET_OPEN_DRAIN = 1 << 3,
  SET_OPEN_SOURCE = 1 << 4,
}

/**
 * Bitmask representing the edge on which an alert should trigger.
 *
 * @remarks
 * See {@link gpioClaimAlert|gpioClaimAlert()}.
 *
 * @public
 */
export enum GpioEdge {
  RISING = 0b01,
  FALLING = 0b10,
  BOTH = 0b11,
}

/**
 * An object representing a pulse in a wave sequence.
 *
 * @remarks
 * See {@link txWave|txWave()}.
 *
 * @public
 */
export type TxWavePulse = {
  bits: bigint;
  mask: bigint;
  delay: number;
};

/**
 * Transmission queue kind.
 *
 * @remarks
 * See {@link txBusy|txBusy()} and {@link txRoom|txRoom()}.
 *
 * @public
 */
export enum TxKind {
  PWM = 0,
  WAVE = 1,
}

/**
 * An object representing a GPIO alert.
 *
 * @remarks
 * See {@link gpioSetAlertsFunc|gpioSetAlertsFunc()}
 * and {@link gpioSetSamplesFunc|gpioSetSamplesFunc()}.
 *
 * @public
 */
export type GpioAlert = {
  report: GpioReport;
  nfyHandle: number;
};

/**
 * An object representing the details of a GPIO alert.
 *
 * @remarks
 * See {@link GpioAlert}, {@link gpioSetAlertsFunc|gpioSetAlertsFunc()}
 * and {@link gpioSetSamplesFunc|gpioSetSamplesFunc()}.
 *
 * @public
 */
export type GpioReport = {
  timestamp: bigint;
  chip: number;
  gpio: number;
  level: GpioLevel;
  flags: number;
};

/**
 * The GPIO level at the time an alert was triggered.
 *
 * @remarks
 * See {@link GpioAlert}, {@link GpioReport}, {@link gpioSetAlertsFunc|gpioSetAlertsFunc()}
 * and {@link gpioSetSamplesFunc|gpioSetSamplesFunc()}.
 *
 * @public
 */
export enum GpioLevel {
  LOW = 0,
  HIGH = 1,
  WATCHDOG = 2,
}

/**
 * Internal configuration option IDs.
 *
 * @remarks
 * See {@link getInternal|getInternal()} and {@link setInternal|setInternal()}.
 *
 * @public
 */
export enum CfgId {
  DEBUG_LEVEL = 0,
  MIN_DELAY = 1,
}

/**
 * An I2C message object.
 *
 * @remarks
 * See {@link i2cSegments|i2cSegments()}.
 *
 * @public
 */
export type I2cMsg = {
  addr: number;
  flags: number;
  buf: Uint8Array;
};
