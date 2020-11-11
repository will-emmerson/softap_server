#include <esp_event.h>
#include <esp_log.h>
#include <esp_netif.h>
#include <limits.h>
#include <network.h>
#include <webserver.h>
#include <wifi.h>

static const char *TAG = "MAIN";

__unused void app_main() {
//    esp_log_level_set("*", ESP_LOG_INFO);
//    network_init();
    esp_netif_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    start_webserver();
    wifi_init();
}
