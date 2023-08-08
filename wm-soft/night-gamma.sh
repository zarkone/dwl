#!/usr/bin/env bash
nohup wl-gammarelay-rs &

busctl --user set-property rs.wl-gammarelay / rs.wl.gammarelay Temperature q 3000
busctl --user set-property rs.wl-gammarelay / rs.wl.gammarelay Brightness d 0.8
