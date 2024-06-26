// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Canvas_drawTextBlob_2, 256, 120, false, 0) {
void draw(SkCanvas* canvas) {
    SkTextBlobBuilder textBlobBuilder;
    SkFont font = SkFont(fontMgr->matchFamilyStyle(nullptr, {}), 50);
    const SkTextBlobBuilder::RunBuffer& run =
            textBlobBuilder.allocRun(font, 1, 20, 100);
    run.glyphs[0] = 20;
    sk_sp<const SkTextBlob> blob = textBlobBuilder.make();
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    canvas->drawTextBlob(blob.get(), 0, 0, paint);
}
}  // END FIDDLE
