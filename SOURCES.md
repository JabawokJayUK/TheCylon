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

**Build photographs — recovered October 2026.** These were previously recorded
here as lost. Twenty-two filenames were referenced by the three 2012 blog posts
and the project page, and only 150×150 WordPress thumbnails survived the loss of
the site database: the full-size originals were absent from the 2024 Amplify
deploy, absent from the Wayback Machine, and the 2012 forum attachment IDs that
carried them return 404 from the forum CDN.

They were then found in Jay's own offline backup — 78 unique full-size camera
originals from the build, 4608 × 3440 (Fujifilm) and 3456 × 2304 / 2592 × 1936
(Canon), dated 2012-02-06 to 2012-04-10. Twenty-one of the twenty-two referenced
filenames are among them.

`IMG_0053-2` is the single exception and remains unrecovered; it is not in the
backup under that name, and may have been a crop or edit made for the blog post
rather than a camera original.

The photographs are published on the project pages at
[jabawoki.com/projects/the-cylon/](https://jabawoki.com/projects/the-cylon/) and
its [gallery](https://jabawoki.com/projects/the-cylon/gallery/), resized to a
1400 px long edge. The originals stay in Jay's backup rather than in this
repository — this repo holds engineering files, not a photo archive.

**The lesson, recorded because it cost a full recovery crawl:** "exhausted every
online source" is not the same as "lost". Ask the author for an offline copy
before writing anything off.

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
