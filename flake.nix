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
        nativeBuildInputs = with pkgs; [
          wayland-pkgs.wlroots
          wayland-pkgs.new-wayland-protocols
          wayland.dev
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
          direnv nix-direnv
        ];
      };
    });
}
