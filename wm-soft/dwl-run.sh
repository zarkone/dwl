#!/usr/bin/env bash
export PATH=$WM_HOME/wm-soft:$PATH

# screencast
export XDG_SESSION_TYPE=wayland
export XDG_CURRENT_DESKTOP=sway

$WM_HOME/dwl > ~/.cache/dwltags
