#include "network.h"

#include <esp_event.h>
#include <esp_log.h>
#include <esp_system.h>
#include <mdns.h>
#include <stdint.h>
#include <esp_wifi.h>

static const char *TAG = "NETWORK";

void network_init() {
    esp_netif_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
}
