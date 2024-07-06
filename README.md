# qemu-retro-directx

A build of WineD3D for running directly on windows xp for use  
in qemu-3dfx to take advantage of opengl api host pass through.  

```
mkdir build_xp
cd build_xp
cmake -G "Visual Studio 17 2022" -A Win32 -T v141_xp ..
```