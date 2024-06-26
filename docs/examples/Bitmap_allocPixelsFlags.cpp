// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Bitmap_allocPixelsFlags, 256, 128, false, 0) {
void draw(SkCanvas* canvas) {
    SkBitmap bitmap;
    bitmap.allocPixelsFlags(SkImageInfo::MakeN32(44, 16, kPremul_SkAlphaType),
                            SkBitmap::kZeroPixels_AllocFlag);
    SkCanvas offscreen(bitmap);
    SkPaint paint;
    SkFont font = SkFont(fontMgr->matchFamilyStyle(nullptr, {}));
    offscreen.drawString("!@#$%", 0, 12, font, paint);
    canvas->scale(6, 6);
    canvas->drawImage(bitmap.asImage(), 0, 0);
    canvas->drawImage(bitmap.asImage(), 8, 8);
}
}  // END FIDDLE
