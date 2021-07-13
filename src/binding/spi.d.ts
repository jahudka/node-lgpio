/**
 * This function returns a handle for the SPI device on the channel.
 *
 * @remarks
 * The flags may be used to modify the default behaviour.
 *
 * `spiFlags` consists of the least significant 2 bits.
 *
 * ```
 * 1  0
 * m  m
 * ```
 *
 * `mm` defines the SPI mode.
 *
 * ```
 * Mode POL PHA
 * 0    0   0
 * 1    0   1
 * 2    1   0
 * 3    1   1
 * ```
 *
 * The other bits in flags should be set to zero.
 *
 * @public
 * @param spiDev - The SPI device ID
 * @param spiChan - The SPI device channel
 * @param spiBaud - The SPI speed to set in bits per second
 * @param spiFlags - See remarks
 * @returns The handle for the SPI device
 */
export declare function spiOpen(spiDev: number, spiChan: number, spiBaud: number, spiFlags?: number): number;

/**
 * This closes the SPI device.
 *
 * @public
 * @param handle - The SPI device handle as returned by {@link spiOpen|spiOpen()}
 */
export declare function spiClose(handle: number): void;

/**
 * This function reads `count` bytes of data from the SPI device.
 *
 * @public
 * @param handle - The SPI device handle as returned by {@link spiOpen|spiOpen()}
 * @param rxBuf - The buffer to receive data read from the device
 * @returns The number of bytes read from the device
 */
export declare function spiRead(handle: number, rxBuf: Uint8Array): number;

/**
 * This function writes `txBuf` to the SPI device.
 *
 * @public
 * @param handle - The SPI device handle as returned by {@link spiOpen|spiOpen()}
 * @param txBuf - The data to write
 * @returns The number of bytes written to the device
 */
export declare function spiWrite(handle: number, txBuf: Uint8Array): number;


/**
 * This function transfers data from `txBuf` to the SPI device. Simultaneously
 * `txBuf.length` bytes of data are read from the device and written to `rxBuf`.
 *
 * @remarks
 * `rxBuf.length` should be equal to or greater than `txBuf.length`.
 *
 * @public
 * @param handle - The SPI device handle as returned by {@link spiOpen|spiOpen()}
 * @param txBuf - The data to write to the device
 * @param rxBuf - The buffer to receive data from the device
 * @returns The number of bytes transferred
 */
export declare function spiXfer(handle: number, txBuf: Uint8Array, rxBuf: Uint8Array): number;
