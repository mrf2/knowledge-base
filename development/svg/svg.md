# SVG Structure

## The 7 Reasons Something "Disappears" in SVG
When something doesn't show, **it is always one of these:**
 * 1. Offscreen coordinates
 * 2. `fill=none` AND no `stroke`
 * 3. White `text` on white `background`
 * 4. Zero opacity
 * 5. Parent `group <g>` is `hidden`
 * 6. Overlapped by later **shapes**
 * 7. `transform` pushes it outside `view`

