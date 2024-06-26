// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Bitmap_writePixels, 256, 256, false, 3) {
void draw(SkCanvas* canvas) {
    std::vector<int32_t> srcPixels;
    int width = image->width();
    int height = image->height();
    srcPixels.resize(height * width  * 4);
    SkPixmap pixmap(SkImageInfo::MakeN32Premul(width, height), (const void*) &srcPixels.front(),
                    width * 4);
    image->readPixels(nullptr, pixmap, 0, 0);
    canvas->scale(.5f, .5f);
    width /= 4;
    height /= 4;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            SkBitmap bitmap;
            bitmap.allocPixels(SkImageInfo::MakeN32Premul(width, height));
            bitmap.writePixels(pixmap, -y * width, -x * height);
            canvas->drawImage(bitmap.asImage(), x * width, y * height);
        }
    }
}
}  // END FIDDLE
