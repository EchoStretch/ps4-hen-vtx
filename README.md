# PS4HEN v2.1.5

## Features
- Current Supports 5.05 - 12.02
- Homebrew Enabler
- [Plugins System](https://github.com/illusion0001/ps4-hen-plugins)
  - Load PRX into `ScePartyDaemon` (Starts klog server on port 3232, based on [klogsrv](https://github.com/ps5-payload-dev/klogsrv))
    - [Source](https://github.com/illusion0001/ps4-hen-plugins/tree/main/plugin_server)
  - Load PRX into retail apps (on startup in CRT `_init_env`) (Shows only notification for now)
    - [Source](https://github.com/illusion0001/ps4-hen-plugins/tree/main/plugin_loader)
- Jailbreak
- Sandbox Escape
- Debug Settings
- External HDD Support
- VR Support
- Remote Package Install
- Rest Mode Support
- External HDD Format Support
- Bypass Firmware Checks
- Debug Trophies Support
- sys_dynlib_dlsym Patch
- UART Enabler
- Never Disable Screenshot
- Remote Play Enabler
- Disable ASLR

## Usage

On your computer, clone the repository:

```sh
git clone --recursive https://github.com/EchoStretch/ps4-hen-vtx.git
```

Compile the payloads:

```sh
./build.sh 900
```

For other firmwares, e.g. FW 12.02, `./build.sh 1202`.

## Contributors
Massive credits to the following:
- [qwertyoruiopz](https://twitter.com/qwertyoruiopz)
- [Specter](https://twitter.com/SpecterDev) 
- [flat_z](https://twitter.com/flat_z)
- [idc](https://twitter.com/3226_2143)
- [Joonie](https://github.com/Joonie86/)
- [Vortex](https://github.com/xvortex)
- [zecoxao](https://twitter.com/notnotzecoxao)
- [SiSTRo](https://github.com/SiSTR0)
- [SocraticBliss](https://twitter.com/SocraticBliss)
- [ChendoChap](https://github.com/ChendoChap)
- [Biorn1950](https://github.com/Biorn1950)
- [Al-Azif](https://github.com/Al-Azif)
- Anonymous

## Helped With Porting
Massive Thanks to the following:
- [BestPig](https://twitter.com/BestPig)
- [LM](https://twitter.com/LightningMods)
- [Al-Azif](https://twitter.com/_AlAzif)
- [zecoxao](https://twitter.com/notnotzecoxao)
- [illusion0001](https://twitter.com/illusion0002)
