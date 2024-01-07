[![GPL](https://img.shields.io/badge/license-GPL--3.0-red.svg)](https://github.com/xtreme8000/BetterSpades/blob/standalone/LICENSE)
[![Discord](https://img.shields.io/badge/discord-join-ff00ff.svg)](https://discord.gg/tZuPt568Dp)

## ![](docs/icon_small.png) PixSpades

* Fork of the game *BetterSpades* (A replicate of classic Voxlap) - See fork differences below
* Runs on very old systems back to OpenGL 1.1 (OpenGL ES support too)
* Shares similar if not even better performance to Voxlap
* Can run on *"embedded"* systems like a [Steam Link](https://store.steampowered.com/app/353380/Steam_Link/)

### Differences in this fork
* Bug fixes not in BetterSpades
* Toggleable client spoofing
* Customizable macros (/medkit, /deaf, /kill, /ratio, /accuracy, /streak, /cancel, /y and two customizable macros)
* Toggleable Auto GG
* Toggleable chat and macro sounds
* Improved scoreboard with weapon names beside players ([RIF] = Rifle, [SMG] = Sub Machine Gun, [SHO] = Shotgun)
* Toggleable team names
* Improved user interface
* Show the name of the item you're holding when you're sprinting to prevent confusion (Toggleable - Only shows tools, not guns)
* Small improvements to the game such as longer chat history, bigger fonts sizes for things that were too small etc.
* Improved the player name indicator when in spectator mode
* Show the '[Player]'s [Body Part]' text even when you're looking at an enemy
* Popup messages are smaller and lower on the screen and don't last as long
* Bullet spread and recoil are the same as OpenSpades
* When in spectator mode players don't fade into fog
* **And more!**

#### Why should I use this instead of ...?

* Free of any Jagex code, they can't shut it down
* Open for future expansion
* Easy to use
* No hidden bugs
* Custom features not in BetterSpades, Voxlap or OpenSpades

### Quick usage guide

You can either:
* Use the client temporarily by extracting the downloaded zip into a new directory
* Extract all contents to your current Ace of Spades installation directory (normally found at `C:/Ace of Spades/`), effectively replacing the old voxlap version

## System requirements

| Type    | min. requirement                                     |
| ------- | ---------------------------------------------------- |
| OS      | Windows 98 or Linux                                  |
| CPU     | 1 GHz single core processor                          |
| GPU     | 64MB VRAM, Mobile Intel 945GM or equivalent          |
| RAM     | 256MB                                                |
| Display | 800x600px                                            |
| Others  | Keyboard and mouse<br />Dial up network connection   |


## Build requirements

This project uses the following libraries and files:

| Name         | License         | Usage                  | GitHub                                             |
| ------------ | --------------- | ---------------------- | :------------------------------------------------: |
| GLFW3        | *ZLib*          | OpenGL context         | [Link](https://github.com/glfw/glfw)               |
| OpenAL soft  | *LGPL-2.1*      | 3D sound environment   | [Link](https://github.com/kcat/openal-soft)        |
| inih         | *BSD-3.Clause*  | .INI file parser       | [Link](https://github.com/benhoyt/inih)            |
| stb_truetype | *Public domain* | TrueType font renderer | [Link](https://github.com/nothings/stb)            |
| dr_wav       | *Public domain* | wav support            | [Link](https://github.com/mackron/dr_libs/)        |
| http         | *Public domain* | http client library    | [Link](https://github.com/mattiasgustavsson/libs)  |
| LodePNG      | *MIT*           | png support            | [Link](https://github.com/lvandeve/lodepng)        |
| libdeflate   | *MIT*           | decompression of maps  | [Link](https://github.com/ebiggers/libdeflate)     |
| enet         | *MIT*           | networking library     | [Link](https://github.com/lsalzman/enet)           |
| parson       | *MIT*           | JSON parser            | [Link](https://github.com/kgabis/parson)           |
| log.c        | *MIT*           | logger                 | [Link](https://github.com/xtreme8000/log.c)        |
| GLEW         | *MIT*           | OpenGL extensions      | [Link](https://github.com/nigels-com/glew)         |
| hashtable    | *MIT*           | hashtable              | [Link](https://github.com/goldsborough/hashtable/) |
| libvxl       | *MIT*           | access VXL format      | [Link](https://github.com/xtreme8000/libvxl/)      |
| microui      | *MIT*           | user interface         | [Link](https://github.com/rxi/microui)             |

You will need to compile the following by yourself, or get hold of precompiled binaries:

* GLFW3
* GLEW
* OpenAL soft *(only needed on Windows)*
* libdeflate
* enet

Follow the instructions on their project page, then place produced static libraries in `deps/`.

All other requirements of the above list (like single file libs) will be downloaded by CMake automatically and **don't** need to be taken care of. Because state of copyright of 0.75 assets is unknown, CMake will also download additional assets from [*here*](http://aos.party/bsresources.zip) which are not part of this repository.

#### Windows

There are GitHub releases for Windows users if you're too lazy to compile PixSpades, with new releases for major commits. Download the release and start the executable. Refer to https://github.com/JimPix1/PixSpades/releases

This project uses CMake to generate all Makefiles automatically. It's best to use MinGW-w64 for GCC on Windows. You can generate the required files by opening `cmd.exe` in the `build/` directory and typing:
```
cmake -G "MinGW Makefiles" ..
mingw32-make
```

If everything went well, the client should be in the `build/BetterSpades/` subfolder.

When starting `client.exe`, you will be greeted by a server list. Select a server on it to start playing!
You can also start the client the same way as you did with the voxlap version by opening cmd and putting an `aos://` link in as the first argument:

```
client.exe -aos://16777343:32887 //Connects to a local server
```

#### Linux

Compilation now works the same on Linux. Just change the build system to `Unix Makefiles` or leaving it as default will work too (`cmake ..`).

You can build each library yourself, or install them with your distro's package manager:
```
sudo apt install libgl1-mesa libgl1-mesa-dev libopenal1 libopenal-dev libglfw-dev libenet-dev libglew-dev
```
(this does not include [libdeflate](https://github.com/ebiggers/libdeflate) which is a requirement too, see [_Wiki/Building_](https://github.com/xtreme8000/BetterSpades/wiki/Building) for more details)

Start the client e.g. with the following inside the `build/bin/` directory:
```
./client
```
Or connect directly to localhost:
```
./client -aos://16777343:32887
```


#### macOS

The same instructions for Linux work on macOS aside from some minor differences. First, use Homebrew or MacPorts to grab dependencies:
```
brew install glfw enet
```
The development headers for OpenAL and OpenGL don't have to be installed since they come with macOS by default. [libdeflate](https://github.com/ebiggers/libdeflate) should be installed and placed manually in a way similar to Linux. See [_Wiki/Building_](https://github.com/xtreme8000/BetterSpades/wiki/Building) for more details.

## Bug reports
Bug reports should generally go to the original [BetterSpades repository](https://github.com/xtreme8000/BetterSpades/issues) unless the bug applies specifically to PixSpades.

## Licensing
Please see the file named LICENSE.

## Gallery

| <img src="/docs/pic01.png" width="250px"><br />*quite old*   | <img src="/docs/pic02.png" width="250px"><br />hiesville                 | <img src="/docs/pic03.png" width="250px">                             |
| :-:                                                          | :-:                                                                      | :-:                                                                   |
| <img src="/docs/pic04.png" width="250px"><br />*grenade fun* | <img src="/docs/pic05.png" width="250px"><br />*falling block animation* | <img src="/docs/pic06.png" width="250px"><br />*sniping on normandie* |
