#!/usr/bin/env sh

export XDG_SESSION_TYPE=wayland
export XDG_CURRENT_DESKTOP=sway
dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP=sway
