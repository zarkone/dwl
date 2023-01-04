{
  description = "zarkone-dwl";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.flake-compat = {
    url = github:edolstra/flake-compat;
    flake = false;
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;
        config = { allowUnfree = true; };
      };
    in {
      devShell = pkgs.mkShell {
        name = "zarkone-dwl";
        nativeBuildInputs = with pkgs; [
          wlroots
          wayland-protocols
          wayland
          pkg-config
          libxkbcommon
          libinput
          xorg.libxcb
          xorg.libX11
          xwayland

          pixman

          # wm soft
          foot
          bemenu
          wofi
          waybar
          inotify-tools
          # deck soft
          emacs
          tmux
          fish
          google-chrome-beta

        ];
      };
    });
}
