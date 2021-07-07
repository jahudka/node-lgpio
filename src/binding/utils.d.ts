import { CfgId } from '../types';

/**
 * Returns the current timestamp.
 *
 * @remarks
 * The timestamp is the number of nanoseconds since the epoch (start of 1970).
 *
 * @public
 * @returns The number of nanoseconds since the UNIX epoch
 */
export declare function timestamp(): bigint;

/**
 * Returns the lgpiolibrary version number.
 *
 * @public
 * @returns The version number
 */
export declare function version(): number;

/**
 * Get an internal configuration value.
 *
 * @public
 * @param cfgId - The configuration item ID
 * @returns The configuration value
 */
export declare function getInternal(cfgId: CfgId): bigint;

/**
 * Set an internal configuration value.
 *
 * @public
 * @param cfgId - The configuration item ID
 * @param value - The configuration value
 */
export declare function setInternal(cfgId: CfgId, value: bigint): void;

/**
 * Returns the error text for an error code.
 *
 * @public
 * @param error - The error code
 * @returns The error message
 */
export declare function errorText(error: number): string;

/**
 * Sets the library working directory.
 *
 * @remarks
 * This function has no effect if the working directory has already been set.
 *
 * @public
 * @param dirPath - The working directory path
 */
export declare function setWorkDir(dirPath: string): void;

/**
 * Returns the library working directory.
 *
 * @public
 * @returns The library working directory
 */
export declare function getWorkDir(): string;
