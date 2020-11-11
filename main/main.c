#include <esp_event.h>
#include <esp_log.h>
#include <esp_netif.h>
#include <limits.h>
#include <webserver.h>
#include <wifi.h>
#include <nvs_flash.h>

static const char *TAG = "MAIN";

__unused void app_main() {
//    esp_log_level_set("*", ESP_LOG_INFO);
//    network_init();

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    start_webserver();
    ESP_ERROR_CHECK(nvs_flash_init());
    wifi_init();
}
