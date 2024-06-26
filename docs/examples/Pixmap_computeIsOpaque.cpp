// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Pixmap_computeIsOpaque, 256, 256, true, 0) {
void draw(SkCanvas* canvas) {
    std::vector<uint32_t> pixels;
    const int height = 2;
    const int width = 2;
    pixels.resize(height * width * 4);
    SkPixmap pixmap(SkImageInfo::Make(width, height, kN32_SkColorType,
            kPremul_SkAlphaType), (const void*) &pixels.front(), width * 4);
    for (int index = 0; index < 2; ++index) {
        pixmap.erase(0x00000000);
        SkDebugf("computeIsOpaque: %s\n", pixmap.computeIsOpaque() ? "true" : "false");
        pixmap.erase(0xFFFFFFFF);
        SkDebugf("computeIsOpaque: %s\n", pixmap.computeIsOpaque() ? "true" : "false");
        pixmap.reset(pixmap.info().makeAlphaType(kOpaque_SkAlphaType),
                     (const void*) &pixels.front(), width * 4);
    }
}
}  // END FIDDLE
