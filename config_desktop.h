/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 * combined_network    Combined interface data         NULL
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv4_multiple       IPV4 address                    NULL
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * netspeed_rx_multiple receive network speed          NULL
 * netspeed_tx_multiple transfer network speed         NULL
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
    /* function format          argument */
    /*{ seperator, "\x07", NULL }, */
    { ipv4, "\x08  %s ", "eno1" },
    /* { seperator, "\x09", NULL }, */
    { netspeed_rx, "\x0A  %s", "eno1" },
    { netspeed_tx, "  %s ", "eno1" },
    /* { seperator, "\x0F", NULL }, */
    { vol_perc, "\x10 蓼 %s%% ", "/dev/mixer" },
    /* { seperator, "\x11", NULL }, */
    { disk_perc, "\x12 / %s%%", "/" },
    { disk_perc, "  %s%% ", "/home" },
    /* { seperator, "\x13", NULL }, */
    { ram_perc, "\x14  %s%% ", NULL },
    /* { seperator, "\x15", NULL }, */
    { cpu_perc, "\x16  %s%% ", NULL },
    /* { seperator, "\x17 ", NULL }, */
    { load_avg, "\x18  %s ", NULL },
    /*{ seperator, "\x19", NULL }, */
    { temp, "\x1A  %s糖 ", "/sys/class/thermal/thermal_zone0/temp" },
    /* { seperator, "\x1B", NULL }, */
    { run_command, "\x1C  %s ", "pacman -Qu | wc -l" },
    /* { seperator, "\x1D", NULL }, */
    { run_command, "\x1E  %s ", "notmuch count tag:unread and tag:inbox" },
    /* { seperator, "\x1F", NULL },*/
    { datetime, "\x06 﨟 %s", "%d-%m-%Y %T" },
};
