#ifndef __CONFIG_H
#define __CONFIG_H

// Enable semihosting to receive debug logs during development
// NOTE: Semihosting has to be disabled when the RS41 radiosonde is not connected to the STM32 programmer dongle, otherwise the firmware will not run.
//#define SEMIHOSTING_ENABLE
//#define LOGGING_ENABLE

/**
 * Global configuration
 */

#define CALLSIGN "SA7BSS" // Set the tracker amateur radio call sign here
#define LEDS_ENABLE false // Disabling LEDs will save power - Red LED: Lit during initialization and transmit. - Green LED: Blinking fast when no GPS fix. Blinking slowly with GPS fix.
#define LEDS_DISABLE_ALTITUDE_METERS 500 // Disable LEDs above the specified altitude (in meters) to save power. Set to zero to disable this behavior.
#define ALLOW_POWER_OFF false // Allow powering off the sonde by pressing the button for over a second (when the sonde is not transmitting)

// Define the I²C bus clock speed in Hz.
// The default of 100000 (= 100 kHz) should be used with the Si5351 clock generator to allow fast frequency changes, a must for Horus V2 to work. Slow clock speed 10000 (= 10 kHz)
#define I2C_BUS_CLOCK_SPEED 100000
#define RADIO_SI5351_ENABLE true // Enable use of an externally connected I²C Si5351 clock generator chip for HF radio transmissions
#define LOCATOR_PAIR_COUNT_FULL 6 // // Number of character pairs to include in locator, max. 6 (12 characters WWL)
#define RADIO_POST_TRANSMIT_DELAY_MS 2000 // Delay after transmission for modes that do not use time synchronization. Zero delay allows continuous transmit mode for Horus V1 and V2.
#define RADIO_TIME_SYNC_THRESHOLD_MS 1000 // Threshold for time-synchronized modes regarding how far from scheduled transmission time the transmission is still allowed
#define GPS_REQUIRE_3D_FIX true // Enable this setting to require 3D fix (altitude required, enable for airborne use), otherwise 2D fix is enough
#define GPS_NMEA_OUTPUT_VIA_SERIAL_PORT_ENABLE false // Enable NMEA output from GPS via external serial port. This disables use of I²C bus (Si5351 and sensors) because the pins are shared.

// Continuous transmit mode can be enabled for Horus V2. This disables all other transmission modes.
// The continuous mode transmits Horus 4FSK preamble between transmissions to allow Horus receivers to keep frequency synchronization at all times, which improves reception.
#define RADIO_SI4032_TX_HORUS_V2_CONTINUOUS false

// Built-in Si4032 and ext Si5351 radio chip transmission configuration
#define RADIO_SI4032_TX_POWER 7 // Si4032 transmit power: 0..7 // 0 = -1dBm, 1 = 2dBm, 2 = 5dBm, 3 = 8dBm, 4 = 11dBm, 5 = 14dBm, 6 = 17dBm, 7 = 20dBm
#define RADIO_SI5351_TX_POWER 3 // Si5351 transmit power: 0..3 // Si5351 drive strength: 0 = 2mA, 1 = 4mA, 2 = 6mA, 3 = 8mA

// Which modes to transmit using the built-in Si4032 transmitter chip
#define RADIO_SI4032_TX_CW false
#define RADIO_SI4032_TX_CW_COUNT 1
#define RADIO_SI4032_TX_PIP false
#define RADIO_SI4032_TX_PIP_COUNT 3
#define RADIO_SI4032_TX_APRS false
#define RADIO_SI4032_TX_APRS_COUNT 2
#define RADIO_SI4032_TX_HORUS_V2 false
#define RADIO_SI4032_TX_HORUS_V2_COUNT 2
// Which modes to transmit using an externally connected Si5351 chip on the I²C bus
#define RADIO_SI5351_TX_CW false
#define RADIO_SI5351_TX_CW_COUNT 1
#define RADIO_SI5351_TX_PIP false
#define RADIO_SI5351_TX_PIP_COUNT 3
#define RADIO_SI5351_TX_HORUS_V2 true
#define RADIO_SI5351_TX_HORUS_V2_COUNT 2
#define RADIO_SI5351_TX_JT9 false
#define RADIO_SI5351_TX_JT9_COUNT 1
#define RADIO_SI5351_TX_JT65 false
#define RADIO_SI5351_TX_JT65_COUNT 1
#define RADIO_SI5351_TX_JT4 false
#define RADIO_SI5351_TX_JT4_COUNT 1
#define RADIO_SI5351_TX_WSPR true
#define RADIO_SI5351_TX_WSPR_COUNT 1
#define RADIO_SI5351_TX_FSQ false
#define RADIO_SI5351_TX_FSQ_COUNT 1
#define RADIO_SI5351_TX_FT8 true
#define RADIO_SI5351_TX_FT8_COUNT 1

// Transmit frequencies for the Si4032 transmitter modes
#define RADIO_SI4032_TX_FREQUENCY_CW         434200000
#define RADIO_SI4032_TX_FREQUENCY_PIP        434200000
#define RADIO_SI4032_TX_FREQUENCY_APRS_1200  432500000
#define RADIO_SI4032_TX_FREQUENCY_HORUS_V2   434201000  // Use a frequency offset to place FSK tones slightly above the defined frequency for SSB reception
// Transmit frequencies for the Si5351 transmitter modes
#define RADIO_SI5351_TX_FREQUENCY_CW         14085000UL
#define RADIO_SI5351_TX_FREQUENCY_PIP        14085000UL
#define RADIO_SI5351_TX_FREQUENCY_HORUS_V2   14085000UL
#define RADIO_SI5351_TX_FREQUENCY_JT9        14085000UL    // Was: 14078700UL
#define RADIO_SI5351_TX_FREQUENCY_JT65       14085000UL    // Was: 14078300UL
#define RADIO_SI5351_TX_FREQUENCY_JT4        14085000UL    // Was: 14078500UL
#define RADIO_SI5351_TX_FREQUENCY_WSPR       14096260UL    // Was: 14097200UL
#define RADIO_SI5351_TX_FREQUENCY_FSQ        14085000UL    // Was: 7105350UL     // Base freq is 1350 Hz higher than dial freq in USB
#define RADIO_SI5351_TX_FREQUENCY_FT8        14085000UL    // Was: 14075000UL

/**
 * APRS mode settings
 * APRS SSID:
 * '0' = (-0) Your primary station usually fixed and message capable
 * '1' = (-1) generic additional station, digi, mobile, wx, etc
 * '2' = (-2) generic additional station, digi, mobile, wx, etc
 * '3' = (-3) generic additional station, digi, mobile, wx, etc
 * '4' = (-4) generic additional station, digi, mobile, wx, etc
 * '5' = (-5) Other networks (Dstar, Iphones, Androids, Blackberry's etc)
 * '6' = (-6) Special activity, Satellite ops, camping or 6 meters, etc
 * '7' = (-7) walkie talkies, HT's or other human portable
 * '8' = (-8) boats, sailboats, RV's or second main mobile
 * '9' = (-9) Primary Mobile (usually message capable)
 * 'A' = (-10) internet, Igates, echolink, winlink, AVRS, APRN, etc
 * 'B' = (-11) balloons, aircraft, spacecraft, etc
 * 'C' = (-12) APRStt, DTMF, RFID, devices, one-way trackers*, etc
 * 'D' = (-13) Weather stations
 * 'E' = (-14) Truckers or generally full time drivers
 * 'F' = (-15) generic additional station, digi, mobile, wx, etc
 */
// APRS Settings
#define APRS_CALLSIGN CALLSIGN
#define APRS_SSID 'B'          // See APRS symbol table documentation in: http://www.aprs.org/symbols/symbolsX.txt
#define APRS_SYMBOL_TABLE '/'  // '/' denotes primary and '\\' denotes alternate APRS symbol table
#define APRS_SYMBOL 'O'
#define APRS_COMMENT "RS41ng"
#define APRS_RELAYS "WIDE1-1,WIDE2-1"
#define APRS_DESTINATION "APZ41N"
#define APRS_DESTINATION_SSID '0'
#define APRS_WEATHER_REPORT_ENABLE false  // Generate an APRS weather report instead of a position report. This will override the APRS symbol with the weather station symbol.
#define APRS_TIME_SYNC_SECONDS 0          // Schedule transmission every N seconds, counting from beginning of an hour (based on GPS time). Set to zero to disable time sync.
#define APRS_TIME_SYNC_OFFSET_SECONDS 0   // Delay transmission for an N second offset after the scheduled time.

// Horus V2 4FSK mode settings
#define HORUS_FREQUENCY_OFFSET_SI4032 0  //Common Horus 4FSK mode settings
#define HORUS_V2_PAYLOAD_ID 34           // Use Horus payload ID 256 for Horus V2 tests (4FSKTEST-V2)
#define HORUS_V2_BAUD_RATE_SI4032 100
#define HORUS_V2_BAUD_RATE_SI5351 100
#define HORUS_V2_PREAMBLE_LENGTH 16
#define HORUS_V2_IDLE_PREAMBLE_LENGTH 32
#define HORUS_V2_TONE_SPACING_HZ_SI5351 270
#define HORUS_V2_TIME_SYNC_SECONDS 0         // Schedule transmission every N seconds, counting from beginning of an hour (based on GPS time). Set to zero to disable time sync.
#define HORUS_V2_TIME_SYNC_OFFSET_SECONDS 0  // Delay transmission for an N second offset after the scheduled time.

// CW settings
#define CW_SPEED_WPM 20                 // CW speed in WPM, range 5 - 40
#define CW_TIME_SYNC_SECONDS 0          // Schedule transmission every N seconds, counting from beginning of an hour (based on GPS time). Set to zero to disable time sync.
#define CW_TIME_SYNC_OFFSET_SECONDS 0   // Delay transmission for an N second offset after the scheduled time.

// Pip settings (short beep generated using CW to indicate presence of the transmitter)
#define PIP_SPEED_WPM 18                // Pip speed is defined as CW WPM, range 5 - 40
#define PIP_TIME_SYNC_SECONDS 0         // Schedule transmission every N seconds, counting from beginning of an hour (based on GPS time). Set to zero to disable time sync.
#define PIP_TIME_SYNC_OFFSET_SECONDS 0  // Delay transmission for an N second offset after the scheduled time.

// WSPR settings
#define WSPR_CALLSIGN CALLSIGN
#define WSPR_LOCATOR_FIXED_ENABLED false
#define WSPR_LOCATOR_FIXED "AA00"
#define WSPR_DBM 10
#define WSPR_TIME_SYNC_SECONDS 120
#define WSPR_TIME_SYNC_OFFSET_SECONDS 19

// FSQ settings
#define FSQ_CALLSIGN_FROM CALLSIGN
#define FSQ_SUBMODE RADIO_DATA_MODE_FSQ_3
#define FSQ_TIME_SYNC_SECONDS 0
#define FSQ_TIME_SYNC_OFFSET_SECONDS 0

// FT/JT mode settings
#define FT8_TIME_SYNC_SECONDS 30       // Schedule transmission every 15 seconds, counting from beginning of an hour (based on GPS time). Set to zero to disable time sync.
#define FT8_TIME_SYNC_OFFSET_SECONDS 3 // Delay transmission for 1 second after the scheduled time.

#define JT9_TIME_SYNC_SECONDS 60
#define JT9_TIME_SYNC_OFFSET_SECONDS 1

#define JT4_TIME_SYNC_SECONDS 60
#define JT4_TIME_SYNC_OFFSET_SECONDS 1

#define JT65_TIME_SYNC_SECONDS 60
#define JT65_TIME_SYNC_OFFSET_SECONDS 1

#include "config_internal.h"

#endif
