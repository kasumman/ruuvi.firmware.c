#include "ruuvi_driver_error.h"
#include "ruuvi_boards.h"
#include "ruuvi_interface_gpio.h"
#include "ruuvi_interface_rtc.h"
#include "ruuvi_interface_yield.h"
#include "task_acceleration.h"
#include "task_adc.h"
#include "task_button.h"
#include "task_environmental.h"
#include "task_led.h"
#include <stddef.h>

static task_button_fp_t button_callback = NULL;
static ruuvi_interface_gpio_interrupt_fp_t interrupt_table[RUUVI_BOARD_GPIO_NUMBER + 1 ] = {0};

// Wrapper to gpio interrupt function
static void on_button(ruuvi_interface_gpio_evt_t event)
{
  if(NULL != button_callback) { button_callback(); }
}

ruuvi_driver_status_t task_button_init(ruuvi_interface_gpio_slope_t slope, task_button_fp_t action)
{
  ruuvi_driver_status_t err_code = RUUVI_DRIVER_SUCCESS;
  button_callback = action;
  err_code |= ruuvi_platform_gpio_interrupt_init(interrupt_table, sizeof(interrupt_table));
  err_code |= ruuvi_platform_gpio_interrupt_enable(RUUVI_BOARD_BUTTON_1, slope, RUUVI_INTERFACE_GPIO_MODE_INPUT_PULLUP, on_button);
  return err_code;
}

ruuvi_driver_status_t task_button_on_press(void)
{
  static uint64_t last_press = 0;
  // returns UINT64_MAX if RTC is not running.
  uint64_t now = ruuvi_platform_rtc_millis();
  ruuvi_driver_status_t err_code = RUUVI_DRIVER_SUCCESS;

  // Debounce button
  if((now - last_press) > RUUVI_BOARD_BUTTON_DEBOUNCE_PERIOD_MS)
  {

    err_code |= task_led_write(RUUVI_BOARD_LED_RED, TASK_LED_ON);
    err_code |= task_acceleration_on_button();
    err_code |= task_environmental_on_button();
    err_code |= task_adc_on_button();
    err_code |= task_led_write(RUUVI_BOARD_LED_RED, TASK_LED_OFF);
    RUUVI_DRIVER_ERROR_CHECK(err_code, ~RUUVI_DRIVER_ERROR_FATAL);
  }

  // store time of press for debouncing if possible
  if(RUUVI_DRIVER_UINT64_INVALID != now) { last_press = now; }
  return err_code;
}