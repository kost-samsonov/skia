// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Bitmap_tryAllocPixels_2, 256, 256, false, 3) {
void draw(SkCanvas* canvas) {
    SkBitmap bitmap;
    if (bitmap.tryAllocPixels(SkImageInfo::Make(64, 64, kGray_8_SkColorType, kOpaque_SkAlphaType))) {
        SkCanvas offscreen(bitmap);
        offscreen.scale(.25f, .5f);
        for (int y : { 0, 64, 128, 192 } ) {
            offscreen.drawImage(source.asImage(), -y, -y);
            canvas->drawImage(bitmap.asImage(), y, y);
        }
    }
}
}  // END FIDDLE
