// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_resetMatrix, 256, 128, false, 0) {
void draw(SkCanvas* canvas) {
    SkPaint paint;
    SkFont font = SkFont(fontMgr->matchFamilyStyle(nullptr, {}));
    canvas->scale(4, 6);
    canvas->drawString("truth", 2, 10, font, paint);
    canvas->resetMatrix();
    canvas->scale(2.8f, 6);
    canvas->drawString("consequences", 2, 20, font, paint);
}
}  // END FIDDLE
