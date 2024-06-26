// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Image_isAlphaOnly, 256, 256, true, 0) {
void draw(SkCanvas* canvas) {
    uint8_t pmColors = 0;
    sk_sp<SkImage> image =
            SkImages::RasterFromPixmapCopy({SkImageInfo::MakeA8(1, 1), &pmColors, 1});
    SkDebugf("alphaOnly = %s\n", image->isAlphaOnly() ? "true" : "false");
}
}  // END FIDDLE
