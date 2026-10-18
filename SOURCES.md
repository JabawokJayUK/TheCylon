# Sources

Where everything in this repository came from, and what could not be recovered.

## Firmware and hardware files

Jay's own working folder, `Project Cylon`, preserved offline since 2012–2014.
62 files, modification times 2012-02-06 to 2014-04-08. Copied in unmodified
except for renaming (spaces → hyphens) and the directory reorganisation
described in the README. No source file has been edited — including
`Cylon_Rob_V1.ino`, which does not compile.

This folder is the only surviving copy of the five downloads that were offered
on jabawoki.com in 2012. The site's download handler (`/downloads/?did=N`) died
with the WordPress install, so the links in the original posts are all dead:

| Original link | Recovered as |
|---|---|
| `?did=4` V3 schematic | `hardware/designspark/Technical Schematic V3 SoftPWM.sch` |
| `?did=5` V3 code | `firmware/development/Cylon_V3.ino` |
| `?did=6` V5.2 schematic | `hardware/designspark/Technical Schematic V5.2.sch` + PDF |
| `?did=7` V5.2 code | `Cylon_5_2.ino` |
| breadboard layouts | `hardware/visio/`, `hardware/fritzing/` |

## Photographs

`docs/images/oem-light-bar-opened.jpg` — Alfa Owner forum attachment 155783,
posted by Jay in the build thread, recovered from the live forum CDN. Shows the
factory 159 high-level brake light opened up with the filament bar visible.

`docs/images/breadboard-v3-*.png` and `cylon-breadboard.png` — renders exported
from the original BlackBoard breadboard designs in the working folder.

`docs/images/schematic-v2*.jpg`, `schematic-v3-softpwm.jpg` — renders from the
working folder.

**Not recovered:** the build photographs. Twenty-six images were referenced by
the three 2012 blog posts and the project page — `DSCF1078`, `DSCF1081`,
`DSCF1085`, `DSCF1094`, `DSCF1097`, `DSCF1099`, `DSCF1287`, `DSCF1295`,
`DSCF1311`, `IMG_0053-2`, `IMG_0084`, `IMG_0087`, `IMG_0088`, `IMG_0096`,
`IMG_6473`–`IMG_6482`. Only 150×150 thumbnails survive in the WordPress media
export; the full-size originals are absent from the 2024 Amplify deploy, absent
from the Wayback Machine (no snapshots exist for those URLs), and the ten 2012
forum attachment IDs that carried them return 404 from the forum CDN. They
appear to be genuinely lost unless an offline copy turns up.

## Written material

`README.md` and `docs/LEGALITY.md` are written from two primary sources, both
Jay's own words:

- The project page and three build posts on jabawoki.com (2012-02-07,
  2012-02-29, 2012-04-06), preserved in the site archive.
- The Alfa Owner build thread, *Cylon Brake Light Project*, thread 325425,
  04-03-2012 to 2012-10-23. 37 posts, 16 of them Jay's, recovered complete from
  Wayback snapshots of both pages. The live forum is behind a proof-of-work
  challenge; the archived copies were used instead.

`firmware/HISTORY.md` is written from reading the source files themselves,
cross-checked against Jay's version-by-version account on the project page.

## Verification

`docs/MANIFEST.txt` lists sha256, size and path for every file in this
repository, generated at import time.
