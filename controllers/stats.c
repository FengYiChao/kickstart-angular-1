/*
    stats.c -- Stats controller
 */

#include "esp.h"

static void data() {
    double     prior, result;

    prior = (double) stoi(param("prior"));
    result = (prior * 0.9) + (random() * 0.1);
    setHeader("Content-Type", "text/javascript");
    render("%d", (int) result);
}

static void traffic() {}

ESP_EXPORT int esp_controller_kickstart_stats(HttpRoute *route)
{
    espDefineAction(route, "stats/data", data);
    espDefineAction(route, "stats/traffic", traffic);
    return 0;
}
