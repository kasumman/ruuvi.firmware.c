#include "unity.h"

#include "app_sensor.h"
#include "ruuvi_driver_sensor.h"
#include "mock_ruuvi_task_sensor.h"
#include "mock_ruuvi_interface_shtcx.h"

void setUp (void)
{
    m_sensors_init();
}

void tearDown (void)
{
}

void test_app_sensor_init_ok (void)
{
    rd_status_t err_code;

    for (size_t ii = 0; ii < SENSOR_COUNT; ii++)
    {
        rt_sensor_initialize_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
        rt_sensor_load_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
        rt_sensor_configure_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
    }

    err_code = app_sensor_init();
    TEST_ASSERT (RD_SUCCESS == err_code);
}

void test_app_sensor_init_first_time (void)
{
    rd_status_t err_code;

    for (size_t ii = 0; ii < SENSOR_COUNT; ii++)
    {
        rt_sensor_initialize_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
        rt_sensor_load_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_ERROR_NOT_FOUND);
        rt_sensor_configure_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
        rt_sensor_store_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_SUCCESS);
    }

    err_code = app_sensor_init();
    TEST_ASSERT (RD_SUCCESS == err_code);
}

void test_app_sensor_init_not_found (void)
{
    rd_status_t err_code;

    for (size_t ii = 0; ii < SENSOR_COUNT; ii++)
    {
        rt_sensor_initialize_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_ERROR_NOT_FOUND);
    }

    err_code = app_sensor_init();
    TEST_ASSERT (RD_SUCCESS == err_code);
}

void test_app_sensor_init_selftest_fail (void)
{
    rd_status_t err_code;

    for (size_t ii = 0; ii < SENSOR_COUNT; ii++)
    {
        size_t retries = 0;

        do
        {
            rt_sensor_initialize_ExpectWithArrayAndReturn (m_sensors[ii], 1, RD_ERROR_SELFTEST);
        } while (retries++ < APP_SENSOR_SELFTEST_RETRIES);
    }

    err_code = app_sensor_init();
    TEST_ASSERT (RD_ERROR_SELFTEST == err_code);
}