/**
 * This function opens a serial device at a specified baud rate and with specified flags.
 *
 * @remarks
 * The baud rate must be one of 50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400,
 * 4800, 9600, 19200, 38400, 57600, 115200, or 230400.
 *
 * @public
 * @param serDev - The serial device to open
 * @param serBaud - The baud rate in bits per second, see remarks
 * @param serFlags - No flags are currently defined; this parameter should be omitted or set to zero
 * @returns The handle for the serial device
 */
export declare function serialOpen(serDev: string, serBaud: number, serFlags?: number): number;

/**
 * This function closes the serial device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 */
export declare function serialClose(handle: number): void;

/**
 * This function writes a byte to the serial device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 * @param byteVal - 0-0xFF, the value to write
 */
export declare function serialWriteByte(handle: number, byteVal: number): void;

/**
 * This function reads a byte from the serial device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 * @returns 0-0xFF, the value read from the device
 */
export declare function serialReadByte(handle: number): number;

/**
 * This function writes `txBuf` to the serial device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 * @param txBuf - The array of bytes to write
 */
export declare function serialWrite(handle: number, txBuf: Uint8Array): void;

/**
 * This function reads up to `rxBuf.length` bytes from the serial device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 * @param rxBuf - The buffer to receive the data read from the device
 * @returns The number of bytes read from the device
 */
export declare function serialRead(handle: number, rxBuf: Uint8Array): number;

/**
 * This function returns the count of bytes available to be read from the device.
 *
 * @public
 * @param handle - The serial device handle as returned by {@link serialOpen|serialOpen()}
 * @returns The number of bytes available to read
 */
export declare function serialDataAvailable(handle: number): number;
