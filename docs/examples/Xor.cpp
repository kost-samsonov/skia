// Copyright 2019 Google LLC.
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.
#include "tools/fiddle/examples.h"
REG_FIDDLE(Xor, 256, 256, false, 0) {
void draw(SkCanvas* canvas) {
    SkPaint paint;
    paint.setBlendMode(SkBlendMode::kXor);
    for (auto color : { SK_ColorRED, SK_ColorBLUE, SK_ColorGREEN } ) {
        SkColor colors[] = { color, SkColorSetA(color, 192), SkColorSetA(color, 128),
                             SkColorSetA(color, 0) };
        paint.setShader(SkGradientShader::MakeRadial({ 64, 64}, 100,
                colors, nullptr, std::size(colors), SkTileMode::kClamp));
        canvas->drawCircle(64, 64, 100, paint);
        canvas->translate(64, 64);
    }
}
}  // END FIDDLE
