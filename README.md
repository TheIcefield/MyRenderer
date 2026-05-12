# MyRenderer

## Build

```bash
# Clone
git clone git@github.com:TheIcefield/MyRenderer.git

# Install dependencies
## Debian / Ubuntu / Mint
sudo apt update
sudo apt install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev

## fedora / RHEL / CentOS
sudo dnf install libXrandr-devel libXinerama-devel ibXcursor-devel libXi-devel

## Arch Linux / Manjaro
sudo pacman -S libxrandr libxinerama libxcursor libxi

# Build
mkdir build
cmake ..
cmake --build .
```
