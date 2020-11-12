#include "webserver.h"

#include <esp_http_server.h>
#include <esp_log.h>

static const char *TAG = "WEBSERVER";

static httpd_handle_t server = NULL;

static void add_close_header(httpd_req_t *req) {
    httpd_resp_set_hdr(req, "Connection", "close");
}

static esp_err_t root_handler(httpd_req_t *req) {
    char *body = "hello";
//    add_close_header(req);
    httpd_resp_send(req, body, strlen(body));
    ESP_LOGI(TAG, "handled root");
    return ESP_OK;
}

static const httpd_uri_t root_uri = {
        .uri       = "/",
        .method    = HTTP_GET,
        .handler   = root_handler,
};

void start_webserver(void) {
    if (server == NULL) {
        ESP_LOGI(TAG, "Starting webserver");
        httpd_config_t config = HTTPD_DEFAULT_CONFIG();
//        config.lru_purge_enable = true;
        if (httpd_start(&server, &config) == ESP_OK) {
            httpd_register_uri_handler(server, &root_uri);
            ESP_LOGD(TAG, "Started webserver");
        }
    }
}

void stop_webserver(void) {
    if (server) {
        ESP_LOGI(TAG, "Stopping webserver");
        ESP_ERROR_CHECK(httpd_stop(server));
        server = NULL;
    }
}
