# Legality

**A sequencing or flashing high-level brake light is not road legal in the UK.**

Rear stop lamps are type-approved items. UNECE Regulation 7 (and the UK
Road Vehicles Lighting Regulations 1989 that sit alongside it) require a stop
lamp to show a steady red light. A lamp that fades, breathes or scans is not a
steady light, and a modified lamp loses the type approval the original unit
carried.

Practically, this means:

- An MOT tester is entitled to fail the car on it.
- An insurer is entitled to treat it as an undeclared modification.
- A police officer is entitled to take an interest.

This repository publishes the design as an engineering project — the
instant-on MOSFET circuit, the fail-on redundancy and the TLC5940 PWM work are
the interesting parts, and they are all directly reusable in legal applications.
The effect sequencing is the part that is not.

## The MOT bypass

Every version from V1 onward carries an MOT bypass, and from V4 it is done in
hardware rather than software. The MOSFET gate feed that the ATmega pulls low to
take over PWM is simply broken by a switch. With the switch open, the MOSFETs
stay closed, the LEDs sit at full brightness on a plain +12 V circuit, and
neither microcontroller touches them.

That is a genuine steady-light mode, not a software approximation of one — it is
the same circuit path the fail-on redundancy uses.

## If you build one

Treat the effects as an off-road feature, keep the bypass switch accessible, and
declare the modification to your insurer. The author's own summary from the
build thread, on whether it would pass an MOT:

> Not sure it would pass an MOT and the "rozzers" might get a little upset at
> the cylon / knight rider effect... That's why it comes with an "MOT Bypass
> switch".

Fitting one is your decision and your liability. Nothing here is legal advice.
