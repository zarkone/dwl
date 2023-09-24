#!/usr/bin/env sh

export XDG_SESSION_TYPE=wayland
export XDG_CURRENT_DESKTOP=sway
export WAYLAND_DISPLAY=wayland-0

dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP
systemctl --user restart xdg-desktop-portal
