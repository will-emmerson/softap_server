#include "wifi.h"

#include <esp_event.h>
#include <esp_system.h>
#include <esp_wifi.h>
#include <sdkconfig.h>

static const char *TAG = "WIFI";

//static void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
//    if (event_id == WIFI_EVENT_AP_START) {
//        set_bit(WIFI_AP_STARTED);
//        start_webserver();
//    } else if (event_id == WIFI_EVENT_AP_STOP) {
//        clear_bit(WIFI_AP_STARTED);
//        stop_webserver();
//    } else if (event_id == WIFI_EVENT_STA_START) {
//        esp_wifi_connect();
//    } else if (event_id == WIFI_EVENT_STA_CONNECTED) {
//        wifi_ap_record_t ap_info;
//        ESP_ERROR_CHECK(esp_wifi_sta_get_ap_info(&ap_info));
//
//        const int8_t rssi = ap_info.rssi;
//        char *ssid = (char *) ap_info.ssid;
//        char bssid_string[18] = "";
//        mac_string(ap_info.bssid, bssid_string);
//
//        cJSON *data = cJSON_CreateObject();
//        cJSON_AddNumberToObject(data, "rssi", rssi);
//        cJSON_AddStringToObject(data, "ssid", ssid);
//        cJSON_AddStringToObject(data, "bssid", bssid_string);
//        send_device_event(EVENT_WIFI_CONNECT, data);
//        ESP_LOGI(TAG, "wifi connected, rssi=%d, ssid=%s, bssid=%s", rssi, ssid, bssid_string);
//    } else if (event_id == WIFI_EVENT_STA_DISCONNECTED) {
//        ESP_LOGD(TAG, "wifi disconnected, trying to reconnect");
//        esp_wifi_connect();
//    }
//}


void wifi_init() {
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
//    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_APSTA));
    esp_netif_create_default_wifi_ap();
    wifi_config_t ap_config = {.ap = {.authmode = WIFI_AUTH_OPEN, .max_connection=5,}};
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_AP, &ap_config));
    esp_wifi_connect();
}


//void wifi_sta_init(const char *wifi_ssid, const char *wifi_password) {
//    esp_netif_create_default_wifi_sta();
//    wifi_config_t sta_config = {};
//    strcpy((char *) sta_config.sta.ssid, wifi_ssid);
//    strcpy((char *) sta_config.sta.password, wifi_password);
//    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &sta_config));
//}
