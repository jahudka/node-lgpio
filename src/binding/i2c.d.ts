import { I2cMsg } from '../types';

/**
 * This returns a handle for the device at the address on the I2C bus.
 *
 * @public
 * @param i2cDev - The I2C bus device ID
 * @param i2cAddr - The I2C device address
 * @param i2cFlags - No flags are currently defined; this parameter should be omitted or set to zero
 * @returns The handle for the I2C device
 */
export declare function i2cOpen(i2cDev: number, i2cAddr: number, i2cFlags?: number): number;

/**
 * This closes the I2C device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 */
export declare function i2cClose(handle: number): void;

/**
 * This sends a single bit (in the Rd/Wr bit) to the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param bitVal - 0-1, the value to write
 */
export declare function i2cWriteQuick(handle: number, bitVal: number): void;

/**
 * This sends a single byte to the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param byteVal - 0-0xFF, the value to write
 */
export declare function i2cWriteByte(handle: number, byteVal: number): void;

/**
 * This reads a single byte from the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @returns 0-0xFF, the value read from the device
 */
export declare function i2cReadByte(handle: number): number;

/**
 * This writes a single byte to the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to write
 * @param byteVal - 0-0xFF, the value to write
 */
export declare function i2cWriteByteData(handle: number, i2cReg: number, byteVal: number): void;

/**
 * This writes a single 16-bit word to the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to write
 * @param wordVal - 0-0xFFFF, the value to write
 */
export declare function i2cWriteWordData(handle: number, i2cReg: number, wordVal: number): void;

/**
 * This reads a single byte from the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read
 * @returns 0-0xFF, the byte read from the device
 */
export declare function i2cReadByteData(handle: number, i2cReg: number): number;

/**
 * This reads a single 16-bit word from the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read
 * @returns 0-0xFFFF, the word read from the device
 */
export declare function i2cReadWordData(handle: number, i2cReg: number): number;

/**
 * This writes 16 bits of data to the specified register of the device and reads 16 bits of data in return.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read/write
 * @param wordVal - 0-0xFFFF, the value to write
 * @returns 0-0xFFFF, the word read from the device
 */
export declare function i2cProcessCall(handle: number, i2cReg: number, wordVal: number): number;

/**
 * This writes up to 32 bytes to the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to write
 * @param data - The buffer containing the data to write
 */
export declare function i2cWriteBlockData(handle: number, i2cReg: number, data: Uint8Array): void;

/**
 * This reads up to 32 bytes from the specified register of the device.
 *
 * @remarks
 * The amount of returned data is set by the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read
 * @param rxBuf -  The buffer to receive the data read from the device
 * @returns The number of bytes read from the device
 */
export declare function i2cReadBlockData(handle: number, i2cReg: number, rxBuf: Uint8Array): number;

/**
 * This writes data bytes to the specified register of the device
 * and reads a device specified number of bytes of data in return.
 *
 * @remarks
 * The `ioBuf` parameter should contain data you wish to write to the device
 * and it will be updated by the data the device returns. The return value
 * of the function indicates how many bytes were written back to the IO buffer.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read
 * @param ioBuf - The IO buffer
 * @param count - The number of bytes to write from the IO buffer
 * @returns The number of bytes written back to the IO buffer
 */
export declare function i2cBlockProcessCall(handle: number, i2cReg: number, ioBuf: Uint8Array, count: number): number;

/**
 * This reads `rxBuf.length` bytes from the specified register of the device. The count may be 1-32.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to read
 * @param rxBuf - The buffer to receive the data read from the device
 * @returns The number of bytes read from the device
 */
export declare function i2cReadI2CBlockData(handle: number, i2cReg: number, rxBuf: Uint8Array): number;

/**
 * This writes up to 32 bytes to the specified register of the device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param i2cReg - 0-0xFF, the register to write
 * @param data - The data to write
 */
export declare function i2cWriteI2CBlockData(handle: number, i2cReg: number, data: Uint8Array): void;

/**
 * This reads count bytes from the raw device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param rxBuf - The buffer to receive the data read from the device
 * @returns The number of bytes read from the device
 */
export declare function i2cReadDevice(handle: number, rxBuf: Uint8Array): number;

/**
 * This writes a buffer of bytes to the raw device.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param data - The buffer containing the data to write
 */
export declare function i2cWriteDevice(handle: number, data: Uint8Array): void;

/**
 * This function executes multiple I2C segments in one transaction by calling the `I2C_RDWR` ioctl.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param segs - The I2C segments to write
 * @returns The number of segments executed
 */
export declare function i2cSegments(handle: number, segs: I2cMsg[]): number;

/**
 * This function executes a sequence of I2C operations. The operations to be performed
 * are specified by the contents of txBuf which contains the concatenated command codes
 * and associated data.
 *
 * @remarks
 * The following command codes are supported:
 *
 * <table>
 *  <thead>
 *    <tr>
 *      <th>Name</th>
 *      <th>Cmd & Data</th>
 *      <th>Meaning</th>
 *    </tr>
 *  </thead>
 *  <tbody>
 *    <tr>
 *      <td>End</td>
 *      <td><code>0</code></td>
 *      <td>No more commands</td>
 *    </tr>
 *    <tr>
 *      <td>Escape</td>
 *      <td><code>1</code></td>
 *      <td>Next <code>P</code> is two bytes</td>
 *    </tr>
 *    <tr>
 *      <td>Address</td>
 *      <td><code>2 P</code></td>
 *      <td>Set I2C address to <code>P</code></td>
 *    </tr>
 *    <tr>
 *      <td>Flags</td>
 *      <td><code>3 lsb msb</code></td>
 *      <td>Set I2C flags to <code>lsb + (msb \<\< 8)</code></td>
 *    </tr>
 *    <tr>
 *      <td>Read</td>
 *      <td><code>4 P</code></td>
 *      <td>Read <code>P</code> bytes of data</td>
 *    </tr>
 *    <tr>
 *      <td>Write</td>
 *      <td><code>5 P ...</code></td>
 *      <td>Write <code>P</code> bytes of data</td>
 *    </tr>
 *  </tbody>
 * </table>
 *
 * The address, read, and write commands take a parameter `P`. Normally `P` is one byte (0-0xFF).
 * If the command is preceded by the Escape command then `P` is two bytes (0-0xFFFF, least significant byte first).
 *
 * The address defaults to that associated with the handle. The flags default to 0.
 * The address and flags maintain their previous value until updated.
 *
 * The returned I2C data is stored in consecutive locations of the returned buffer.
 *
 * @public
 * @param handle - The I2C device handle as returned by {@link i2cOpen|i2cOpen()}
 * @param txBuf - The buffer containing the concatenated I2C commands
 * @param rxBuf - The buffer to receive the data read from the device
 * @returns The number of bytes read from the device
 */
export declare function i2cZip(handle: number, txBuf: Uint8Array, rxBuf: Uint8Array): number;
