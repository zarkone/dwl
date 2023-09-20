{
  description = "zarkone-dwl";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/23.11-pre";
  inputs.nixpkgs-wayland  = { url = "github:nix-community/nixpkgs-wayland"; };

  inputs.flake-utils.url = "github:numtide/flake-utils";
  inputs.flake-compat = {
    url = github:edolstra/flake-compat;
    flake = false;
  };

  outputs = { self, nixpkgs, nixpkgs-wayland, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {
        inherit system;
        config = { allowUnfree = true; };
      };
      wayland-pkgs = nixpkgs-wayland.packages.${system};
    in {
      devShell = pkgs.mkShell {
        name = "zarkone-dwl";
        LD_LIBRARY_PATH = "${wayland-pkgs.wlroots}/lib";
        NIXOS_OZONE_WL = "1";
        BROWSER = "firefox";
        nativeBuildInputs = with pkgs; [
          wayland-pkgs.wlroots
          wayland-pkgs.new-wayland-protocols
          wayland-pkgs.wlr-randr
          wayland-pkgs.grim
          wayland.dev
          pkg-config
          libxkbcommon
          libinput
          xorg.libxcb
          xorg.libX11
          xwayland
          ccls
          pixman

          # wm soft
          wayland-pkgs.foot
          bemenu
          wayland-pkgs.wofi
          wayland-pkgs.waybar
          wayland-pkgs.wl-gammarelay-rs
          wayland-pkgs.wl-gammactl
          wayland-pkgs.wev
          inotify-tools
          # slurp
          # deck soft
          # emacs
          # tmux
          # fish
          # google-chrome-beta
          #direnv nix-direnv
        ];
      };
    });
}
