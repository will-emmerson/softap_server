#include "wifi.h"

#include <esp_event.h>
#include <esp_system.h>
#include <esp_wifi.h>
#include <sdkconfig.h>

static const char *TAG = "WIFI";

void wifi_init() {
    esp_netif_create_default_wifi_ap();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
//    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    wifi_config_t ap_config = {.ap = {.authmode = WIFI_AUTH_OPEN, .max_connection=5,}};
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &ap_config));
    esp_wifi_start();
}
