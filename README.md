Home security project. Two pieces of Hardware: Hub that handles the overall state of the security. Sensor Node that communicates to the hub of the current state of the sensor.

File Structure:

```
home-security-system/
  README.md

  firmware/
    hub/
      platformio.ini
      src/
        main.cpp
        HubApp.cpp
        HubApp.h
        EspNowHub.cpp
        EspNowHub.h
        LedStatus.cpp
        LedStatus.h
      lib/
        shared-protocol/
          Protocol.h
          Protocol.cpp

    sensor-node/
      platformio.ini
      src/
        main.cpp
        SensorApp.cpp
        SensorApp.h
        EspNowNode.cpp
        EspNowNode.h
        LedStatus.cpp
        LedStatus.h
      lib/
        shared-protocol/
          (can be a git submodule, symlink, or copy – we can tighten this up later)

  backend/
    (if you ever build a spring/next backend or dashboard)

  hardware/
    schematics/
    pcbs/

  docs/
    protocol.md
    pairing-flow.md
```
