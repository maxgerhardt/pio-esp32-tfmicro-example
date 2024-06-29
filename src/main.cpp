#include "sdkconfig.h"
#include <Arduino.h>
extern "C" {
#include <test_functions.h>
}
#include <esp_timer.h>

static const char *TAG = "test_app";
static uint32_t start_c, start_opt, total_c, total_opt;
#if __has_include("esp_idf_version.h")
#include <esp_idf_version.h>
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(5, 0, 0)
#define esp_cpu_get_ccount esp_cpu_get_cycle_count
#endif
#endif

extern "C" void profile_c_start()
{
    /* initiate profiling */
    start_c = esp_cpu_get_ccount();
}

extern "C" uint32_t profile_c_end()
{
    /* record profile number */
    total_c = esp_cpu_get_ccount() - start_c;
    return total_c;
}

extern "C" void profile_opt_start()
{
    /* initiate profiling */
    start_opt = esp_cpu_get_ccount();
}

extern "C" uint32_t profile_opt_end()
{
    /* record profile number */
    total_opt = esp_cpu_get_ccount() - start_opt;
    return total_opt;
}

void setup() {
    Serial.begin(115200);
}
void loop() {
    /* s8 tests */
    ESP_LOGI(TAG, "Running s8 tests...");
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_add_elementwise_s8_test();
    printf("add, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_mul_elementwise_s8_test();
    printf("mul, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_depthwise_conv_s8_test();
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_conv_s8_test();

    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_relu6_s8_test();
    printf("relu, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_avg_pool_s8_test();
    printf("avg_pool, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_max_pool_s8_test();
    printf("max_pool, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_fully_connected_s8_test();
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    esp_nn_softmax_s8_test();
    printf("softmax, c %" PRIu32 " opt %" PRIu32 "\n", total_c, total_opt);
    printf("Free heap: %u bytes \n", ESP.getFreeHeap());
    ESP_LOGI(TAG, "s8 tests done!\n");

    /* u8 tests */
    //ESP_LOGI(TAG, "Running u8 tests...");
    //esp_nn_add_elementwise_u8_test();
    //esp_nn_depthwise_conv_u8_test();
    //esp_nn_conv_u8_test();
    //esp_nn_avg_pool_u8_test();
    //esp_nn_max_pool_u8_test();
    //esp_nn_fully_connected_u8_test();
    //ESP_LOGI(TAG, "u8 tests done!\n");
    Serial.println("Sleeping 10 seconds");
    delay(10000);
}
