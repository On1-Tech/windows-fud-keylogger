#pragma once

constexpr bool ARMED = false;

constexpr short AUTOSTART_VECTORS = 1;
constexpr int AUTOSTART_SLEEP_MS = 1000;

#define FCOM_AUTOSTART "autostart"
#define FCOM_AUTOSTART_SUCCESS "autostart-success"

#define DISPLAY_NAME L"Windows Sheduled Maintenance Service"
#define INSTALL_LOCATION "%appdata%\\Sheduled Maintenance\\"
#define FNAME "update.exe"
#define FULL_FNAME "%appdata%\\Sheduled Maintenance\\update.exe"