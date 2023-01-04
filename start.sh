#!/usr/bin/env bash
sudo mount --bind /nix /home/deck/nix
source .nix-profile/etc/profile.d/nix.sh
nix develop ~/flakes --command fish
