#!/usr/bin/env bash
# announce a running sway session to systemd

systemctl --user import-environment XDG_SESSION_TYPE XDG_CURRENT_DESKTOP
dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP=sway
