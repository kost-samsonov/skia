// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Pixmap_rowBytes, 256, 256, true, 0) {
void draw(SkCanvas* canvas) {
    SkPixmap badPixmap = {SkImageInfo::MakeA8(4, 4), nullptr, 2};
    SkPixmap okPixmap = {SkImageInfo::MakeA8(4, 4), nullptr, 8};
    for (auto& pixmap : { badPixmap, okPixmap } ) {
        SkDebugf("rowBytes: %zu minRowBytes: %zu\n", pixmap.rowBytes(),
           pixmap.info().minRowBytes());
    }
}
}  // END FIDDLE
