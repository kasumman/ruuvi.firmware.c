/**
 * Default configuration for Ruuvi Firmware
 *
 * License: BSD-3
 * Author: Otso Jousimaa <otso@ojousima.net>
 */
#ifndef APPLICATION_MODE_DEFAULT_H
#define APPLICATION_MODE_DEFAULT_H

/*************************************
 * Environmental sensor configuration
 *************************************/
/** @brief sample rate, in Hz. 
 *
 *  Typically environmental conditions change slowly inside tag, use minimum
 *  to conserve power.
 */
#ifndef APPLICATION_ENVIRONMENTAL_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_SAMPLERATE RUUVI_DRIVER_SENSOR_CFG_MIN
#endif

/** @brief Use default resolution as default */
#ifndef APPLICATION_ENVIRONMENTAL_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_RESOLUTION RUUVI_DRIVER_SENSOR_CFG_DEFAULT
#endif

/** @brief Use default scale as default */
#ifndef APPLICATION_ENVIRONMENTAL_SCALE
#define APPLICATION_ENVIRONMENTAL_SCALE      RUUVI_DRIVER_SENSOR_CFG_DEFAULT
#endif

#ifndef APPLICATION_ENVIRONMENTAL_DSPFUNC
#define APPLICATION_ENVIRONMENTAL_DSPFUNC    RUUVI_DRIVER_SENSOR_CFG_DEFAULT
#endif 

/** @brief Parameter to DSP function.
 * The parameter affects how agressively the DSP is applied, higher means
 * stronger effect. For example Oversampling with parameter 8 means 8 samples are averaged for one sample.
 *
 * Valid values are RUUVI_DRIVER_SENSOR_CFG_MAX, RUUVI_DRIVER_SENSOR_CFG_MIN, RUUVI_DRIVER_SENSOR_CFG_DEFAULT.
 * 1, 2, 4, 8, 16
 */
#ifndef APPLICATION_ENVIRONMENTAL_DSPPARAM
#define APPLICATION_ENVIRONMENTAL_DSPPARAM   RUUVI_DRIVER_SENSOR_CFG_DEFAULT
#endif

/**
 * @brief default mode of environmental sensor.
 * Valid values are RUUVI_DRIVER_SENSOR_CFG_SLEEP, RUUVI_DRIVER_SENSOR_CFG_SINGLE and RUUVI_DRIVER_SENSOR_CFG_CONTINUOUS.
 * Sleep enters lowest-power mode possible.
 * Single commands sensor to take a new sample, waits sample to be available and then returns the data from sensor.
 * Continuous keeps the sensor running on the background regardless of how often data is read.
 * Continuous is recommended mode for most applications.
**/
#ifndef APPLICATION_ENVIRONMENTAL_MODE
#define APPLICATION_ENVIRONMENTAL_MODE       RUUVI_DRIVER_SENSOR_CFG_CONTINUOUS
#endif

#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_DSP_FUNC
#define APPLICATION_ENVIRONMENTAL_SHTCX_DSP_FUNC   APPLICATION_ENVIRONMENTAL_DSPFUNC
#endif

#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_DSP_PARAM
#define APPLICATION_ENVIRONMENTAL_SHTCX_DSP_PARAM  APPLICATION_ENVIRONMENTAL_DSPPARAM
#endif 

/** @brief SHTCX uses simulated continous mode, i.e. a new sample is taken on data_get. */
#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_MODE
#define APPLICATION_ENVIRONMENTAL_SHTCX_MODE       APPLICATION_ENVIRONMENTAL_MODE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_SHTCX_RESOLUTION APPLICATION_ENVIRONMENTAL_RESOLUTION
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_SHTCX_SAMPLERATE APPLICATION_ENVIRONMENTAL_SAMPLERATE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_SHTCX_SCALE
#define APPLICATION_ENVIRONMENTAL_SHTCX_SCALE      APPLICATION_ENVIRONMENTAL_SCALE
#endif 


/** @brief DSP configuration of environmental sensor.
 * Valid values for BME280 are: (RUUVI_DRIVER_SENSOR_DSP_)LAST, LOW_PASS, OS
 * Low pass slows step response but lowers noise
 * Oversampling (OS) increases power consumption but lowers noise.
 * @see https://blog.ruuvi.com/humidity-sensor-673c5b7636fc and https://blog.ruuvi.com/dsp-compromises-3f264a6b6344
 */
#ifndef APPLICATION_ENVIRONMENTAL_BME280_DSP_FUNC
#define APPLICATION_ENVIRONMENTAL_BME280_DSP_FUNC   RUUVI_DRIVER_SENSOR_DSP_LOW_PASS
#endif

/** @brief DSP configuration of environmental sensor.
 * Valid values for BME280 are: (RUUVI_DRIVER_SENSOR_) DEFAULT, MIN, MAX, 1, 2, 4, 8, 16
 */
#ifndef APPLICATION_ENVIRONMENTAL_BME280_DSP_PARAM
#define APPLICATION_ENVIRONMENTAL_BME280_DSP_PARAM  16
#endif

#ifndef APPLICATION_ENVIRONMENTAL_BME280_MODE
#define APPLICATION_ENVIRONMENTAL_BME280_MODE       APPLICATION_ENVIRONMENTAL_MODE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_BME280_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_BME280_RESOLUTION APPLICATION_ENVIRONMENTAL_RESOLUTION
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_BME280_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_BME280_SAMPLERATE APPLICATION_ENVIRONMENTAL_SAMPLERATE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_BME280_SCALE
#define APPLICATION_ENVIRONMENTAL_BME280_SCALE      APPLICATION_ENVIRONMENTAL_SCALE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_MCU_DSP_FUNC
#define APPLICATION_ENVIRONMENTAL_MCU_DSP_FUNC   APPLICATION_ENVIRONMENTAL_DSPFUNC
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_MCU_DSP_PARAM
#define APPLICATION_ENVIRONMENTAL_MCU_DSP_PARAM  APPLICATION_ENVIRONMENTAL_DSPPARAM
#endif 

/** @brief MCU uses simulated continous mode, i.e. a new sample is taken on data_get. */
#ifndef APPLICATION_ENVIRONMENTAL_MCU_MODE
#define APPLICATION_ENVIRONMENTAL_MCU_MODE       APPLICATION_ENVIRONMENTAL_MODE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_MCU_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_MCU_RESOLUTION APPLICATION_ENVIRONMENTAL_RESOLUTION
#endif

#ifndef APPLICATION_ENVIRONMENTAL_MCU_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_MCU_SAMPLERATE APPLICATION_ENVIRONMENTAL_SAMPLERATE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_MCU_SCALE
#define APPLICATION_ENVIRONMENTAL_MCU_SCALE      APPLICATION_ENVIRONMENTAL_SCALE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_NTC_DSP_FUNC
#define APPLICATION_ENVIRONMENTAL_NTC_DSP_FUNC   APPLICATION_ENVIRONMENTAL_DSPFUNC
#endif

#ifndef APPLICATION_ENVIRONMENTAL_NTC_DSP_PARAM
#define APPLICATION_ENVIRONMENTAL_NTC_DSP_PARAM  APPLICATION_ENVIRONMENTAL_DSPPARAM
#endif

/** @brief NTC uses simulated continous mode, i.e. a new sample is taken on data_get. */
#ifndef APPLICATION_ENVIRONMENTAL_NTC_MODE
#define APPLICATION_ENVIRONMENTAL_NTC_MODE       APPLICATION_ENVIRONMENTAL_MODE
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_NTC_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_NTC_RESOLUTION APPLICATION_ENVIRONMENTAL_RESOLUTION
#endif 

#ifndef APPLICATION_ENVIRONMENTAL_NTC_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_NTC_SAMPLERATE APPLICATION_ENVIRONMENTAL_SAMPLERATE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_NTC_SCALE
#define APPLICATION_ENVIRONMENTAL_NTC_SCALE      APPLICATION_ENVIRONMENTAL_SCALE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_DSP_FUNC
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_DSP_FUNC   APPLICATION_ENVIRONMENTAL_DSPFUNC
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_DSP_PARAM
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_DSP_PARAM  APPLICATION_ENVIRONMENTAL_DSPPARAM
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_MODE
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_MODE       APPLICATION_ENVIRONMENTAL_MODE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_RESOLUTION
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_RESOLUTION APPLICATION_ENVIRONMENTAL_RESOLUTION
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_SAMPLERATE
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_SAMPLERATE APPLICATION_ENVIRONMENTAL_SAMPLERATE
#endif

#ifndef APPLICATION_ENVIRONMENTAL_LIS2DH12_SCALE
#define APPLICATION_ENVIRONMENTAL_LIS2DH12_SCALE      APPLICATION_ENVIRONMENTAL_SCALE
#endif

/*************************************
 * Timer intervals
 *************************************/
/**
 * @brief interval at which environmental data is logged to tag. 
 * As of 3.26.0 environmental data has 2^14 bytes of space which can fit
 * 1024 environmental samples. 6s interval -> 10 minutes.
 * 60 s interval -> 17 hours
 * 10 minute interval -> week
 */
#ifndef APPLICATION_ENVIRONMENTAL_LOG_INTERVAL_MS
#define APPLICATION_ENVIRONMENTAL_LOG_INTERVAL_MS (5*60*1000)
#endif

#ifndef APPLICATION_ADVERTISEMENT_UPDATE_INTERVAL_MS
#define APPLICATION_ADVERTISEMENT_UPDATE_INTERVAL_MS  APPLICATION_ADVERTISING_INTERVAL_MS
#endif

#ifndef APPLICATION_ADVERTISING_STARTUP_INTERVAL_MS
#define APPLICATION_ADVERTISING_STARTUP_INTERVAL_MS   210
#endif

#ifndef APPLICATION_ADVERTISING_STARTUP_PERIOD_MS
#define APPLICATION_ADVERTISING_STARTUP_PERIOD_MS     10000
#endif

#ifndef APPLICATION_GATT_HEARTBEAT_INTERVAL_MS
#define APPLICATION_GATT_HEARTBEAT_INTERVAL_MS    APPLICATION_ADVERTISEMENT_UPDATE_INTERVAL_MS
#endif


/**
 * @brief Watchdog timer interval.
 *
 * Watchdog gets reset on successful "heartbeat", when data is sent 
 * from tag. Should be long enough to let user establish a GATT connection
 * and longer than advertisement update interval.
 */
#ifndef APPLICATION_WATCHDOG_INTERVAL_MS
#define APPLICATION_WATCHDOG_INTERVAL_MS (12*1000)
#endif

#endif