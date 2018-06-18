# wfn\_tex

Texture and animation library for `wfn_eng`.

### File Specs

#### Texture

`.tex` is a renamed `.png` with no special encoding.

#### Animation

| Name       | Size               | Description                 |
|------------|--------------------|-----------------------------|
| header     | 4 bytes            | Character string, "ANIM".   |
| fgcount    | 4 bytes            | The number of frame guides. |
| texcount   | 4 bytes            | The number of textures.     |
| fgs        | 4 bytes * fgcount  | Frame guides.               |
| texs       | variable           | The set of images.          |
