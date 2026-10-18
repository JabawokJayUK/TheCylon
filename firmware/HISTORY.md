# Firmware history

Every version that survives is kept here. They are not all good — the point is
the progression, including the dead ends. Dates are file modification times from
the original working folder.

## V1.0 — Feb 2012
`Cylon_V1_0.ino`, `Cylon_V1_0.pde`

Ten LEDs on ten digital pins, bare `digitalWrite()`, no PWM at all. Lights
everything on, then runs a hard-edged scan. Proof that ten LEDs in the housing
would be bright enough.

**Dead end:** the ATmega328P has only 6 hardware PWM pins, so a proper fade
across 10 LEDs is impossible this way.

## V2 — Feb 2012
`Cylon_V2.ino`

Adds the SoftPWM library to fade in and out. Looks far better. Still a single
flat loop with no state handling.

## V3 — Feb 2012
`Cylon_V3.ino`, `Cylon_V3_arduino02x.pde`

The first version actually fitted to the car, and the first with the three-state
structure (instant / pulse / larson) plus an MOT bypass on pin 2. Software PWM
across all ten outputs.

**Dead end — and the important one:** in the car it showed ~300 ms of lag behind
the car's own brake lights. That is the ATmega loading the bootloader before the
sketch runs. 300 ms is a following driver's reaction time, so this design could
not ship. The `_arduino02x` variant is the same sketch back-ported for the
Arduino 0.2x IDE.

## V4 / V4.1 / V4.2 — Mar 2012
`Cylon_V4.ino`, `Cylon_V4_ino.ino`, `Cylon_V4_1.ino`, `Cylon_V4_2.ino`

The 2N7000 MOSFET instant-on circuit arrives, solving the 300 ms problem in
hardware. The LEDs are lit by the +12 V rail the moment power appears; the micro
boots, pulls the gate feed low and takes over PWM.

`Cylon_V4.ino` is an unfinished stub — it still carries the original TODO list
in the header. The working sketches are V4.1 and V4.2.

**Dead end:** the SoftPWM library handled the handover from instant-on to PWM
badly. The transition was, in the author's words, "very ugly".

Also here: `ShiftPWM_Test/` — an attempt to solve PWM with shift registers that
was abandoned in favour of the TLC5940.

## Rob_V1 — Mar 2012
`Cylon_Rob_V1.ino`

A state-machine rewrite contributed by **Rob C**, restructuring the effect
sequencing. Kept for the design idea, which fed into V5.

**Note:** this file does not compile as-is — it contains `DigitalWrite` with a
capital D. Preserved exactly as received rather than silently corrected.

## V5.0 → V5.2 — Apr 2012
`Cylon_5_0.ino`, `CylonSWV1.ino`, `../Cylon_5_2.ino`

The rewrite onto the Texas Instruments TLC5940: 16 hardware PWM channels at
12-bit resolution (4095 levels per channel, against the ATmega's 256). The micro
drives it over serial and offloads all LED timing. Combined with the V4
instant-on circuit this gives sub-10 ms start-up and a clean handover.

V5.1 and V5.2 add transient voltage protection upstream of the regulator — a
hard-limited +12 V rail, which matters in an automotive electrical environment.

`CylonSWV1.ino` is the V5.2 code packaged for release alongside the breadboard
and cable layouts in `hardware/visio/`.

**V5.2 is the production version** and lives at the repository root.

## LED current

The V5.2 header carries the working rule used throughout:

```
39.06 / ohms of resistor = mA of drive
```

The two LED types actually bought and used are recorded in
`hardware/LED-Specs.txt`.
